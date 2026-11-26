#include "padroes_subkind_relator.h"

#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "classes_datatypes.h"
#include "enum_genset.h"
#include "pacotes_relacoes.h"
#include "relatorio_erros.h"

using namespace std;

/* ===================================================================== */
/*  Estrutura de resultado (mesmo formato do módulo Mode / RoleMixin)    */
/* ===================================================================== */

struct OcorrenciaPadraoSR {
    string padrao;             // "Subkind" ou "Relator"
    string nome;               // classe central (kind ou relator)
    int linha;
    string identificado_por;   // assinatura/sobrecarga que identificou o padrão
    vector<string> elementos;  // partes válidas encontradas
    vector<string> faltas;     // restrições violadas ou componentes ausentes
    vector<string> coercoes;   // correções aplicadas por coerção
};

static vector<OcorrenciaPadraoSR> ocorrencias_sr;

/* ===================================================================== */
/*  Utilitários de consulta de classes, cardinalidades e hierarquia      */
/* ===================================================================== */

static const DeclaracaoClasse* buscar_classe(const string& nome) {
    for (const DeclaracaoClasse& c : classes_declaradas())
        if (c.nome == nome) return &c;
    return nullptr;
}

static string tipo_da_classe(const string& nome) {
    const DeclaracaoClasse* c = buscar_classe(nome);
    return c ? c->estereotipo : string();
}

static bool contem(const vector<string>& lista, const string& valor) {
    return find(lista.begin(), lista.end(), valor) != lista.end();
}

static string juntar_lista(const vector<string>& itens) {
    string r;
    for (size_t i = 0; i < itens.size(); i++) {
        if (i > 0) r += ", ";
        r += itens[i];
    }
    return r;
}

static string card_minimo(const string& card) {
    if (card.empty() || card == "*") return "0";
    size_t p = card.find("..");
    return p == string::npos ? card : card.substr(0, p);
}

static string card_maximo(const string& card) {
    if (card.empty()) return "*";
    size_t p = card.find("..");
    return p == string::npos ? card : card.substr(p + 2);
}

// Obtém todas as classes-mãe (declaradas via 'specializes' ou inferidas via 'genset')
static vector<string> obter_superclasses(const DeclaracaoClasse& cls,
                                         bool* inferida_via_genset = nullptr) {
    vector<string> maes = cls.especializacoes;
    if (inferida_via_genset) *inferida_via_genset = false;

    for (const DeclGenset& g : gensets_declarados()) {
        if (!g.tem_geral) continue;
        for (const Referencia& esp : g.especificas) {
            if (esp.nome == cls.nome && !contem(maes, g.geral.nome)) {
                maes.push_back(g.geral.nome);
                if (inferida_via_genset) *inferida_via_genset = true;
            }
        }
    }
    return maes;
}

// Verifica recursivamente se a classe possui algum ancestral com estereótipo 'kind'
static bool possui_ancestral_kind(const string& nome_classe,
                                  unordered_set<string>& visitados,
                                  string& kind_raiz) {
    if (visitados.count(nome_classe)) return false;
    visitados.insert(nome_classe);

    const DeclaracaoClasse* cls = buscar_classe(nome_classe);
    if (!cls) return false;

    if (cls->estereotipo == "kind") {
        kind_raiz = cls->nome;
        return true;
    }

    for (const string& mae : obter_superclasses(*cls)) {
        if (possui_ancestral_kind(mae, visitados, kind_raiz)) return true;
    }
    return false;
}

/* ===================================================================== */
/*  1. SUBKIND PATTERN — Sobrecarga de Funções (Overloading)             */
/*                                                                       */
/*      kind ClassName                                                   */
/*      subkind SubclassName1 specializes ClassName                      */
/*      subkind SubclassName2 specializes ClassName                      */
/*      disjoint [complete] genset Kind_Subkind_Genset_Name {            */
/*          general ClassName                                            */
/*          specifics SubclassName1, SubclassName2                       */
/*      }                                                                */
/* ===================================================================== */

// Sobrecarga 1 (Completa): Classe-mãe + Subkinds + Genset
static void avaliar_subkind_pattern(const DeclaracaoClasse& mae,
                                    const vector<const DeclaracaoClasse*>& filhas,
                                    const DeclGenset& g,
                                    const vector<string>& subkinds_fora_genset) {
    OcorrenciaPadraoSR oc;
    oc.padrao = "Subkind";
    oc.nome = mae.nome;
    oc.linha = mae.linha;
    oc.identificado_por = "sobrecarga completa: '" + mae.nome + "' + " +
                          to_string(filhas.size()) + " subkind(s) + genset '" + g.nome + "'";
    string ctx = "Padrão Subkind '" + mae.nome + "'";

    // Valida a classe-mãe: aceita 'kind' direta ou 'subkind' que descenda de uma 'kind'
    if (mae.estereotipo == "kind") {
        oc.elementos.push_back("classe-mãe: kind " + mae.nome);
    } else if (mae.estereotipo == "subkind") {
        unordered_set<string> vis;
        string kind_raiz;
        if (possui_ancestral_kind(mae.nome, vis, kind_raiz)) {
            oc.elementos.push_back("classe-mãe: subkind " + mae.nome + " (herda de kind " + kind_raiz + ")");
        } else {
            registrar_erro(mae.linha, mae.coluna, ctx,
                "O subkind '" + mae.nome + "' não possui ancestral do tipo 'kind'.",
                "Vincule '" + mae.nome + "' (ou sua superclasse) a uma classe 'kind'.");
            oc.faltas.push_back("A classe-mãe '" + mae.nome + "' não possui ancestral 'kind'.");
        }
    } else {
        oc.faltas.push_back("'" + mae.nome + "' foi declarada como '" + mae.estereotipo +
                            "', mas subkinds exigem classe-mãe do tipo 'kind'.");
    }

    oc.elementos.push_back("genset: " + g.nome + " (linha " + to_string(g.linha) + ")");

    if (g.com_erro)
        oc.faltas.push_back("O genset '" + g.nome + "' possui erro sintático.");

    // Restrição do genset: 'disjoint' é obrigatório para subkinds ('complete' é opcional)
    if (g.modificadores & MOD_OVERLAPPING) {
        oc.faltas.push_back("O genset '" + g.nome + "' usa 'overlapping', mas subkinds são rígidos e exigem 'disjoint'.");
    } else if (!(g.modificadores & MOD_DISJOINT)) {
        registrar_coercao(g.linha, g.coluna, ctx,
            "O genset '" + g.nome + "' agrupa subkinds sem a restrição obrigatória 'disjoint'.",
            "Restrição 'disjoint' assumida por coerção para o genset.");
        oc.coercoes.push_back("genset '" + g.nome + "': 'disjoint' assumido (linha " +
                              to_string(g.linha) + ")");
    }

    if (g.especificas.size() < 2) {
        oc.faltas.push_back("O genset '" + g.nome + "' possui apenas " +
                            to_string(g.especificas.size()) + " subclasse(s); recomenda-se 2 ou mais.");
    }

    for (const Referencia& esp : g.especificas) {
        const DeclaracaoClasse* sub = buscar_classe(esp.nome);
        if (!sub) {
            oc.faltas.push_back("A subclasse '" + esp.nome + "' listada no genset não foi declarada.");
            continue;
        }
        if (sub->estereotipo != "subkind") {
            oc.faltas.push_back("'" + esp.nome + "' tem estereótipo '" + sub->estereotipo +
                                "', mas o genset de Subkind Pattern exige 'subkind'.");
            continue;
        }

        // Coerção: subkind listado em specifics do genset sem declarar 'specializes'
        if (!contem(sub->especializacoes, mae.nome)) {
            registrar_coercao(esp.linha, esp.coluna, ctx,
                "O subkind '" + esp.nome + "' está no genset de '" + mae.nome +
                "', mas omitiu 'specializes " + mae.nome + "'.",
                "Especialização '" + esp.nome + " specializes " + mae.nome + "' inserida a partir do genset.");
            oc.coercoes.push_back("'" + esp.nome + " specializes " + mae.nome +
                                  "' inserido (linha " + to_string(esp.linha) + ")");
        }

        oc.elementos.push_back("subkind: " + esp.nome + " specializes " + mae.nome);
    }

    for (const string& fora : subkinds_fora_genset) {
        oc.faltas.push_back("O subkind '" + fora + "' especializa '" + mae.nome +
                            "', mas ficou fora das specifics do genset '" + g.nome + "'.");
    }

    ocorrencias_sr.push_back(oc);
}

// Sobrecarga 2 (Incompleta): Classe-mãe + Subkinds, mas sem Genset
static void avaliar_subkind_pattern(const DeclaracaoClasse& mae,
                                    const vector<const DeclaracaoClasse*>& filhas) {
    OcorrenciaPadraoSR oc;
    oc.padrao = "Subkind";
    oc.nome = mae.nome;
    oc.linha = mae.linha;
    oc.identificado_por = "sobrecarga parcial: especialização de subkind(s) para '" + mae.nome + "' (sem genset)";

    if (mae.estereotipo == "kind") {
        oc.elementos.push_back("classe-mãe: kind " + mae.nome);
    } else {
        unordered_set<string> vis;
        string kind_raiz;
        if (mae.estereotipo == "subkind" && possui_ancestral_kind(mae.nome, vis, kind_raiz)) {
            oc.elementos.push_back("classe-mãe: subkind " + mae.nome + " (herda de kind " + kind_raiz + ")");
        } else {
            oc.faltas.push_back("'" + mae.nome + "' (" + mae.estereotipo +
                                ") não é 'kind': não existem subkinds sem classes-mãe do tipo 'kind'.");
        }
    }

    vector<string> nomes_filhas;
    for (const auto* f : filhas) {
        oc.elementos.push_back("subkind: " + f->nome + " specializes " + mae.nome);
        nomes_filhas.push_back(f->nome);
    }

    oc.faltas.push_back("Ausência de 'disjoint genset' agrupando " + mae.nome +
                        " e [" + juntar_lista(nomes_filhas) + "].");

    ocorrencias_sr.push_back(oc);
}

// Sobrecarga 3 (Isolada/Incompleta): Subkind órfão sem nenhuma classe-mãe
static void avaliar_subkind_pattern(const DeclaracaoClasse& subkind_orfao) {
    OcorrenciaPadraoSR oc;
    oc.padrao = "Subkind";
    oc.nome = subkind_orfao.nome;
    oc.linha = subkind_orfao.linha;
    oc.identificado_por = "sobrecarga por estereótipo: 'subkind " + subkind_orfao.nome + "' isolado";

    registrar_erro(subkind_orfao.linha, subkind_orfao.coluna, "Padrão Subkind '" + subkind_orfao.nome + "'",
        "Não existem subkinds sem classes-mãe do tipo 'kind'.",
        "Declare 'subkind " + subkind_orfao.nome + " specializes <ClasseKind>'.");

    oc.elementos.push_back("subkind: " + subkind_orfao.nome);
    oc.faltas.push_back("Não possui classe-mãe do tipo 'kind' (falta 'specializes <Kind>').");
    oc.faltas.push_back("Não participa de nenhum 'disjoint genset'.");

    ocorrencias_sr.push_back(oc);
}

static void analisar_padroes_subkind() {
    unordered_map<string, vector<const DeclaracaoClasse*>> subkinds_por_mae;
    vector<string> ordem_maes;

    for (const DeclaracaoClasse& c : classes_declaradas()) {
        if (c.estereotipo != "subkind") continue;

        vector<string> maes = obter_superclasses(c);
        if (maes.empty()) {
            // Sobrecarga 3: subkind órfão
            avaliar_subkind_pattern(c);
            continue;
        }

        for (const string& m : maes) {
            if (!subkinds_por_mae.count(m)) ordem_maes.push_back(m);
            subkinds_por_mae[m].push_back(&c);
        }
    }

    for (const string& nome_mae : ordem_maes) {
        const DeclaracaoClasse* mae = buscar_classe(nome_mae);
        const vector<const DeclaracaoClasse*>& filhas = subkinds_por_mae[nome_mae];

        if (!mae) {
            OcorrenciaPadraoSR oc;
            oc.padrao = "Subkind";
            oc.nome = nome_mae;
            oc.linha = filhas[0]->linha;
            oc.identificado_por = "sobrecarga parcial: subkinds referenciam classe-mãe não declarada '" + nome_mae + "'";
            for (const auto* f : filhas)
                oc.elementos.push_back("subkind: " + f->nome + " specializes " + nome_mae);
            oc.faltas.push_back("A classe-mãe 'kind " + nome_mae + "' não foi declarada no arquivo.");
            ocorrencias_sr.push_back(oc);
            continue;
        }

        // Busca gensets cuja classe 'general' seja nome_mae e que contenham subkinds
        vector<const DeclGenset*> gensets_subkind;
        for (const DeclGenset& g : gensets_declarados()) {
            if (!g.tem_geral || g.geral.nome != nome_mae) continue;
            bool tem_subkind = false;
            for (const Referencia& esp : g.especificas) {
                if (tipo_da_classe(esp.nome) == "subkind") { tem_subkind = true; break; }
            }
            if (tem_subkind) gensets_subkind.push_back(&g);
        }

        if (gensets_subkind.empty()) {
            // Sobrecarga 2: tem kind + subkinds, mas não tem genset
            avaliar_subkind_pattern(*mae, filhas);
        } else {
            // Sobrecarga 1: tem kind + subkinds + genset
            for (const DeclGenset* g : gensets_subkind) {
                vector<string> fora;
                for (const auto* f : filhas) {
                    bool coberta = false;
                    for (const Referencia& esp : g->especificas) {
                        if (esp.nome == f->nome) { coberta = true; break; }
                    }
                    if (!coberta) fora.push_back(f->nome);
                }
                avaliar_subkind_pattern(*mae, filhas, *g, fora);
            }
        }
    }
}

/* ===================================================================== */
/*  4. RELATOR PATTERN — Sobrecarga de Funções (Overloading)             */
/*                                                                       */
/*      kind ClassName1                                                  */
/*      kind ClassName2                                                  */
/*      role Role_Name1 specializes ClassName1                           */
/*      role Role_Name2 specializes ClassName2                           */
/*      relator Relator_Name {                                           */
/*          @mediation [1..*] [1..*] Role_Name1                          */
/*          @mediation [1..*] [1..*] Role_Name2                          */
/*      }                                                                */
/*      @material relation Role_Name1 [1..*] relationName [1..*] Role_Name2 */
/* ===================================================================== */

static int valor_min_card(const string& card) {
    string min_s = card_minimo(card);
    if (min_s.empty() || min_s == "*") return 0;
    for (char ch : min_s)
        if (!isdigit((unsigned char)ch)) return 0;
    return stoi(min_s);
}

static void verificar_polos_relator(const DeclaracaoClasse& relator,
                                    const vector<const DeclRelacao*>& mediacoes,
                                    OcorrenciaPadraoSR& oc) {
    string ctx = "Padrão Relator '" + relator.nome + "'";

    for (const DeclRelacao* med : mediacoes) {
        const DeclaracaoClasse* alvo = buscar_classe(med->destino);
        if (!alvo) {
            oc.faltas.push_back("Polo mediado '" + med->destino + "' (@mediation, linha " +
                                to_string(med->linha) + ") não foi declarado como classe.");
            continue;
        }

        // Regra UFO: minCard >= 1 e immutable na ponta do Substantial Universal
        if (!med->card_destino.empty() && valor_min_card(med->card_destino) == 0) {
            string max_c = card_maximo(med->card_destino);
            string nova = (max_c == "1") ? "1" : "1.." + max_c;
            registrar_coercao(med->linha, med->coluna, ctx,
                "Cardinalidade de '" + med->destino + "' em @mediation é [" + med->card_destino +
                "] (mínimo 0), mas mediações exigem dependência existencial (minCard >= 1).",
                "Cardinalidade convertida de [" + med->card_destino + "] para [" + nova + "].");
            oc.coercoes.push_back("cardinalidade de '" + med->destino + "': [" +
                                  med->card_destino + "] -> [" + nova + "] (linha " +
                                  to_string(med->linha) + ")");
        }

        if (alvo->estereotipo == "role" || alvo->estereotipo == "historicalRole") {
            unordered_set<string> vis;
            string kind_mae;
            if (possui_ancestral_kind(alvo->nome, vis, kind_mae)) {
                oc.elementos.push_back("mediação (@mediation): " + alvo->nome +
                                       " (role -> kind " + kind_mae + ")");
            } else {
                registrar_erro(alvo->linha, alvo->coluna, ctx,
                    "Não existem roles sem classes-mãe do tipo 'kind': '" + alvo->nome +
                    "' não especializa nenhuma 'kind'.",
                    "Declare 'role " + alvo->nome + " specializes <ClasseKind>'.");
                oc.faltas.push_back("O role '" + alvo->nome + "' não possui classe-mãe do tipo 'kind'.");
            }
        } else if (alvo->estereotipo == "roleMixin") {
            // Mixin anti-rígido (Substantial Universal): válido se especializado por roles com raiz kind
            unordered_set<string> kinds_distintas;
            for (const DeclaracaoClasse& c : classes_declaradas()) {
                if ((c.estereotipo == "role" || c.estereotipo == "historicalRole") &&
                    contem(c.especializacoes, alvo->nome)) {
                    unordered_set<string> vis;
                    string kind_mae;
                    if (possui_ancestral_kind(c.nome, vis, kind_mae)) {
                        kinds_distintas.insert(kind_mae);
                    }
                }
            }
            if (!kinds_distintas.empty()) {
                oc.elementos.push_back("mediação (@mediation): " + alvo->nome + " (roleMixin)");
            } else {
                registrar_coercao(med->linha, med->coluna, ctx,
                    "O roleMixin '" + alvo->nome + "' mediado por '" + relator.nome +
                    "' não possui roles especializados vinculados a classes 'kind'.",
                    "RoleMixin '" + alvo->nome + "' assumido como papel contextual na mediação.");
                oc.coercoes.push_back("polo '" + alvo->nome +
                                      "' (roleMixin sem roles vinculados) coagido na mediação (linha " +
                                      to_string(med->linha) + ")");
                oc.elementos.push_back("mediação (@mediation): " + alvo->nome + " (roleMixin coagido)");
            }
        } else if (alvo->estereotipo == "kind" || alvo->estereotipo == "subkind" ||
                   alvo->estereotipo == "collective" || alvo->estereotipo == "quantity" ||
                   alvo->estereotipo == "phase" || alvo->estereotipo == "category") {
            // Substantial Universal válido na UFO geral, coagido para 'role' conforme o template TONTO
            registrar_coercao(med->linha, med->coluna, ctx,
                "Mediação '@mediation' de '" + relator.nome + "' aponta diretamente para '" +
                alvo->estereotipo + " " + alvo->nome + "' em vez de um 'role'.",
                "Classe '" + alvo->nome + "' coagida para papel contextual ('role') na mediação.");
            oc.coercoes.push_back("polo '" + alvo->nome + "' (" + alvo->estereotipo +
                                  ") coagido para 'role' (linha " + to_string(med->linha) + ")");
            oc.elementos.push_back("mediação (@mediation): " + alvo->nome +
                                   " (" + alvo->estereotipo + " coagido para role)");
        } else {
            // Moment Universals (mode, relator) ou não-endurants (enum, datatype) são proibidos pela UFO
            registrar_erro(med->linha, med->coluna, ctx,
                "Polo '" + alvo->nome + "' possui estereótipo '" + alvo->estereotipo +
                "', que não é um Substantial Universal válido para '@mediation'.",
                "Relators devem mediar classes 'role' (especializando 'kind').");
            oc.faltas.push_back("Polo '" + alvo->nome + "' tem estereótipo '" + alvo->estereotipo +
                                "', incompatível com '@mediation'.");
        }
    }
}

// Sobrecarga 1 (Completa): Relator + Sum(minCard) >= 2 + Relação Material (Variant 2)
static void avaliar_relator_pattern(const DeclaracaoClasse& relator,
                                    const vector<const DeclRelacao*>& mediacoes,
                                    const vector<const DeclRelacao*>& materiais) {
    OcorrenciaPadraoSR oc;
    oc.padrao = "Relator";
    oc.nome = relator.nome;
    oc.linha = relator.linha;
    oc.identificado_por = "sobrecarga completa: relator '" + relator.nome + "' + " +
                          to_string(mediacoes.size()) + " @mediation + @material";

    oc.elementos.push_back("relator: " + relator.nome);
    verificar_polos_relator(relator, mediacoes, oc);

    for (const DeclRelacao* mat : materiais) {
        oc.elementos.push_back("relação material (@material): " + mat->nome +
                               " (" + mat->origem + " -> " + mat->destino + ")");
    }

    ocorrencias_sr.push_back(oc);
}

// Sobrecarga 2 (Incompleta): Relator + Sum(minCard) >= 2, sem Relação Material (apenas Variant 1)
static void avaliar_relator_pattern(const DeclaracaoClasse& relator,
                                    const vector<const DeclRelacao*>& mediacoes) {
    OcorrenciaPadraoSR oc;
    oc.padrao = "Relator";
    oc.nome = relator.nome;
    oc.linha = relator.linha;
    oc.identificado_por = "sobrecarga parcial: relator '" + relator.nome + "' com " +
                          to_string(mediacoes.size()) + " @mediation (sem @material)";

    oc.elementos.push_back("relator: " + relator.nome);
    verificar_polos_relator(relator, mediacoes, oc);

    string p1 = mediacoes.size() >= 1 ? mediacoes[0]->destino : "Role1";
    string p2 = mediacoes.size() >= 2 ? mediacoes[1]->destino : p1;
    string msg = "Relators sempre exigem uma relação externa '@material' entre os polos mediados.";
    string sug = "Declare: @material relation " + p1 + " [1..*] nomeRelacao [1..*] " + p2;

    registrar_erro(relator.linha, relator.coluna, "Padrão Relator '" + relator.nome + "'", msg, sug);
    oc.faltas.push_back(msg + " (" + sug + ")");

    ocorrencias_sr.push_back(oc);
}

// Sobrecarga 3 (Mínima/Incompleta): Relator com Sum(minCard) < 2
static void avaliar_relator_pattern(const DeclaracaoClasse& relator,
                                    int soma_min_card,
                                    const vector<const DeclRelacao*>& mediacoes) {
    OcorrenciaPadraoSR oc;
    oc.padrao = "Relator";
    oc.nome = relator.nome;
    oc.linha = relator.linha;
    oc.identificado_por = "sobrecarga por estereótipo: 'relator " + relator.nome +
                          "' com Sum(minCard) = " + to_string(soma_min_card);

    oc.elementos.push_back("relator: " + relator.nome);
    verificar_polos_relator(relator, mediacoes, oc);

    string msg = "Relators exigem pelo menos duas mediações (Sum(minCard) >= 2) e uma relação '@material'.";
    registrar_erro(relator.linha, relator.coluna, "Padrão Relator '" + relator.nome + "'", msg,
        "Adicione pelo menos duas relações '@mediation' em '" + relator.nome +
        "' e uma '@material relation' externa.");
    oc.faltas.push_back(msg + " Mediações encontradas: " + to_string(mediacoes.size()) +
                        " (Sum(minCard) = " + to_string(soma_min_card) + ").");

    ocorrencias_sr.push_back(oc);
}

static void analisar_padroes_relator() {
    const vector<DeclRelacao>& todas_relacoes = relacoes_declaradas();
    set<string> materiais_associadas;

    // Verifica se alguma @mediation foi usada fora de um relator
    for (const DeclRelacao& r : todas_relacoes) {
        if (r.interna && r.estereotipo == "mediation" && !r.origem.empty()) {
            const DeclaracaoClasse* dona = buscar_classe(r.origem);
            if (dona && dona->estereotipo != "relator") {
                registrar_erro(r.linha, r.coluna, "Padrão Relator",
                    "Relação '@mediation' declarada dentro de '" + r.origem +
                    "' (" + dona->estereotipo + ").",
                    "Relações '@mediation' pertencem exclusivamente a classes 'relator'.");
            }
        }
    }

    for (const DeclaracaoClasse& c : classes_declaradas()) {
        if (c.estereotipo != "relator") continue;

        vector<const DeclRelacao*> mediacoes;
        unordered_set<string> polos_diretos;
        unordered_set<string> kinds_ancestrais;
        int soma_min_card = 0;

        for (const DeclRelacao& r : todas_relacoes) {
            if (r.interna && r.origem == c.nome && r.estereotipo == "mediation") {
                mediacoes.push_back(&r);
                polos_diretos.insert(r.destino);

                int min_efetivo = max(1, valor_min_card(r.card_destino));
                soma_min_card += min_efetivo;

                unordered_set<string> vis;
                string kind_raiz;
                if (possui_ancestral_kind(r.destino, vis, kind_raiz)) {
                    kinds_ancestrais.insert(kind_raiz);
                }
            }
        }

        // Regra UFO: Sum(minCard) >= 2 (cobre >= 2 mediações ou 1 mediação com card >= 2)
        if (soma_min_card < 2) {
            avaliar_relator_pattern(c, soma_min_card, mediacoes);
            continue;
        }

        // Busca relações externas que ligam os polos mediados por este relator
        vector<const DeclRelacao*> materiais;
        for (const DeclRelacao& r : todas_relacoes) {
            if (r.interna) continue;

            bool liga_polos = polos_diretos.count(r.origem) && polos_diretos.count(r.destino);
            bool liga_kinds = (r.origem != r.destino) &&
                              kinds_ancestrais.count(r.origem) &&
                              kinds_ancestrais.count(r.destino);

            if (r.estereotipo == "material" && liga_polos) {
                materiais.push_back(&r);
                materiais_associadas.insert(r.nome + "#" + to_string(r.linha));
            } else if (r.estereotipo == "material" && liga_kinds) {
                // Coerção: @material ligou as kinds base em vez dos roles mediados
                registrar_coercao(r.linha, r.coluna, "Padrão Relator '" + c.nome + "'",
                    "Relação '@material " + r.nome + "' conecta as classes-base (" + r.origem +
                    " -> " + r.destino + ") em vez dos roles mediados por '" + c.nome + "'.",
                    "Relação material associada por coerção aos roles mediados de '" + c.nome + "'.");
                materiais.push_back(&r);
                materiais_associadas.insert(r.nome + "#" + to_string(r.linha));
            } else if (r.estereotipo != "material" && liga_polos) {
                // Coerção: relação externa entre os polos declarada com outro estereótipo
                registrar_coercao(r.linha, r.coluna, "Padrão Relator '" + c.nome + "'",
                    "Relação externa '" + r.nome + "' entre polos mediados por '" + c.nome +
                    "' usa '@" + r.estereotipo + "' em vez de '@material'.",
                    "Estereótipo coagido para '@material' para compor o Relator Pattern.");
                materiais.push_back(&r);
                materiais_associadas.insert(r.nome + "#" + to_string(r.linha));
            }
        }

        if (!materiais.empty()) {
            // Sobrecarga 1: completa (Variant 2)
            avaliar_relator_pattern(c, mediacoes, materiais);
        } else {
            // Sobrecarga 2: incompleta — falta @material (apenas Variant 1)
            avaliar_relator_pattern(c, mediacoes);
        }
    }

    // Sobrecarga adicional: relação '@material' sem nenhum 'relator' derivando-a
    for (const DeclRelacao& r : todas_relacoes) {
        if (r.interna || r.estereotipo != "material") continue;
        string chave = r.nome + "#" + to_string(r.linha);
        if (materiais_associadas.count(chave)) continue;

        OcorrenciaPadraoSR oc;
        oc.padrao = "Relator";
        oc.nome = r.nome;
        oc.linha = r.linha;
        oc.identificado_por = "sobrecarga por relação '@material " + r.nome + "' sem relator mediador";
        oc.elementos.push_back("relação material: " + r.nome + " (" + r.origem + " -> " + r.destino + ")");
        oc.faltas.push_back("Ausência de classe 'relator' com '@mediation' para '" +
                            r.origem + "' e '" + r.destino + "'.");
        ocorrencias_sr.push_back(oc);
    }

    // Verificação global: qualquer 'role' isolado no arquivo que não possua mãe 'kind'
    for (const DeclaracaoClasse& c : classes_declaradas()) {
        if (c.estereotipo != "role" && c.estereotipo != "historicalRole") continue;
        unordered_set<string> vis;
        string kind_mae;
        if (!possui_ancestral_kind(c.nome, vis, kind_mae)) {
            registrar_erro(c.linha, c.coluna, "Padrão Relator / Role",
                "Não existem roles sem classes-mãe do tipo 'kind': '" + c.nome +
                "' não possui ancestral 'kind'.",
                "Declare 'role " + c.nome + " specializes <ClasseKind>'.");
        }
    }
}

/* ===================================================================== */
/*  Ponto de entrada e impressão                                         */
/* ===================================================================== */

void analisar_padroes_subkind_relator() {
    ocorrencias_sr.clear();
    analisar_padroes_subkind();
    analisar_padroes_relator();
    stable_sort(ocorrencias_sr.begin(), ocorrencias_sr.end(),
                [](const OcorrenciaPadraoSR& a, const OcorrenciaPadraoSR& b) {
                    return a.linha < b.linha;
                });
}

static void imprimir_ocorrencia_sr(ostream& out, const OcorrenciaPadraoSR& oc) {
    out << "  [" << oc.padrao << "] " << oc.nome << " (linha " << oc.linha << ")\n";
    out << "      identificado por: " << oc.identificado_por << "\n";
    for (const string& e : oc.elementos) out << "      + " << e << "\n";
    for (const string& f : oc.faltas)    out << "      - FALTA: " << f << "\n";
    for (const string& c : oc.coercoes)  out << "      * COERÇÃO: " << c << "\n";
}

void imprimir_padroes_subkind_relator(ostream& out) {
    int completos = 0, incompletos = 0;
    for (const OcorrenciaPadraoSR& oc : ocorrencias_sr)
        (oc.faltas.empty() ? completos : incompletos)++;

    out << "\n=====================================================\n";
    out << "  ANÁLISE SEMÂNTICA: PADRÕES SUBKIND E RELATOR\n";
    out << "=====================================================\n";

    out << "(1) PADRÕES COMPLETOS: " << completos << "\n";
    for (const OcorrenciaPadraoSR& oc : ocorrencias_sr)
        if (oc.faltas.empty()) imprimir_ocorrencia_sr(out, oc);
    if (completos == 0) out << "  (nenhum)\n";

    out << "\n(2) PADRÕES INCOMPLETOS (identificados por sobrecarga): " << incompletos << "\n";
    for (const OcorrenciaPadraoSR& oc : ocorrencias_sr)
        if (!oc.faltas.empty()) imprimir_ocorrencia_sr(out, oc);
    if (incompletos == 0) out << "  (nenhum)\n";

    out << "=====================================================\n";
}