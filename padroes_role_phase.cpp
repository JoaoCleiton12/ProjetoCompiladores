#include "padroes_role_phase.h"

#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "classes_datatypes.h"
#include "enum_genset.h"
#include "relatorio_erros.h"

using namespace std;

/* ===================================================================== */
/*  Estrutura de resultado (mesmo formato dos módulos Subkind/Relator e  */
/*  Mode/RoleMixin)                                                      */
/* ===================================================================== */

struct OcorrenciaPadraoRP {
    string padrao;             // "Role", "Phase" ou "Role/Phase" (genset ambíguo)
    string nome;               // classe central (o sortal especializado)
    int linha;
    string identificado_por;   // assinatura/sobrecarga que identificou o padrão
    vector<string> elementos;  // partes válidas encontradas
    vector<string> faltas;     // restrições violadas ou componentes ausentes
    vector<string> coercoes;   // correções aplicadas por coerção
};

static vector<OcorrenciaPadraoRP> ocorrencias_rp;

/* ===================================================================== */
/*  Tabela de símbolos: tipo (estereótipo) de cada classe                */
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

/* Sortais da UFO (slide "UFO - Endurant Universals"): kind, collective,
   subkind (rígidos) e phase, role (anti-rígidos). */
static bool eh_sortal(const string& tipo) {
    return tipo == "kind" || tipo == "collective" || tipo == "subkind" ||
           tipo == "phase" || tipo == "role";
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

static vector<string> nomes_das_classes(const vector<const DeclaracaoClasse*>& classes) {
    vector<string> nomes;
    for (const DeclaracaoClasse* c : classes) nomes.push_back(c->nome);
    return nomes;
}

/* Classe-mãe usada para agrupar uma phase/role fora de genset: a primeira
   classe especializada que é sortal; se nenhuma for, a primeira declarada. */
static string classe_mae_principal(const DeclaracaoClasse& c) {
    for (const string& mae : c.especializacoes)
        if (eh_sortal(tipo_da_classe(mae))) return mae;
    return c.especializacoes.empty() ? string() : c.especializacoes[0];
}

/* Verificação de tipo da classe geral: phases e roles só especializam sortais. */
static void verificar_sortal(const string& nome, const string& filhas, int linha, int coluna,
                             OcorrenciaPadraoRP& oc, const string& ctx, bool registrar) {
    string tipo = tipo_da_classe(nome);
    if (tipo.empty()) {
        oc.faltas.push_back("A classe geral '" + nome + "' não foi declarada.");
        return;
    }
    if (!eh_sortal(tipo)) {
        if (registrar)
            registrar_erro(linha, coluna, ctx,
                "'" + nome + "' foi declarada como '" + tipo + "', mas " + filhas +
                " só especializam sortais.",
                "Faça as " + filhas + " especializarem um sortal (kind, collective, subkind, "
                "phase ou role), do qual herdam a identidade.");
        oc.faltas.push_back("'" + nome + "' foi declarada como '" + tipo + "', mas " + filhas +
                            " só especializam sortais (kind, collective, subkind, phase ou role).");
        return;
    }
    oc.elementos.push_back("sortal (geral): " + tipo + " " + nome);
}

/* Coerção comum: a classe está nas specifics do genset, mas não declara
   'specializes <geral>' -> a especialização é inserida a partir do genset. */
static void inserir_especializacao(const DeclaracaoClasse& filha, const Referencia& esp,
                                   const string& geral, OcorrenciaPadraoRP& oc, const string& ctx) {
    if (geral.empty() || contem(filha.especializacoes, geral)) return;
    registrar_coercao(esp.linha, esp.coluna, ctx,
        "A " + filha.estereotipo + " '" + filha.nome + "' está no genset de '" + geral +
        "', mas não declara 'specializes " + geral + "'.",
        "Especialização '" + filha.nome + " specializes " + geral + "' inserida a partir do genset.");
    oc.coercoes.push_back("'" + filha.nome + " specializes " + geral + "' inserido (linha " +
                          to_string(esp.linha) + ")");
}

/* ===================================================================== */
/*  SOBRECARGA DO GENSET: o significado é decidido pelos tipos das       */
/*  classes específicas                                                  */
/* ===================================================================== */

enum class SignificadoGenset { PHASE, ROLE, MISTO, OUTRO };

static SignificadoGenset significado_genset(const DeclGenset& g) {
    int phases = 0, roles = 0, subkinds = 0, outros = 0;
    for (const Referencia& esp : g.especificas) {
        string tipo = tipo_da_classe(esp.nome);
        if (tipo == "phase") phases++;
        else if (tipo == "role") roles++;
        else if (tipo == "subkind") subkinds++;
        else if (!tipo.empty()) outros++;
    }
    /* general roleMixin -> padrão RoleMixin; specifics subkind -> padrão Subkind
       (ambos analisados nos outros módulos) */
    if (g.tem_geral && tipo_da_classe(g.geral.nome) == "roleMixin") return SignificadoGenset::OUTRO;
    if (subkinds > 0) return SignificadoGenset::OUTRO;

    if (phases > 0 && roles == 0 && outros == 0) return SignificadoGenset::PHASE;
    if (roles > 0 && phases == 0 && outros == 0) return SignificadoGenset::ROLE;
    if (phases > 0 || roles > 0) return SignificadoGenset::MISTO;
    return SignificadoGenset::OUTRO;
}

/* Linha da ocorrência: a da classe geral (como no Subkind) ou, se ela não foi
   declarada, a do genset. */
static int linha_do_padrao(const string& geral, int linha_alternativa) {
    const DeclaracaoClasse* c = buscar_classe(geral);
    return c ? c->linha : linha_alternativa;
}

/* ===================================================================== */
/*  3. PHASE PATTERN — Sobrecarga de Funções (Overloading)               */
/*                                                                       */
/*      kind ClassName                                                   */
/*      phase Phase_Name1 specializes ClassName                          */
/*      phase Phase_Name2 specializes ClassName                          */
/*      phase Phase_NameN specializes ClassName                          */
/*      disjoint complete genset Class_Phase_Genset_Name {               */
/*          general ClassName                                            */
/*          specifics Phase_Name1, Phase_Name2, Phase_NameN              */
/*      }                                                                */
/*  "disjoint" é obrigatório para phases; "complete" é opcional.         */
/* ===================================================================== */

// Sobrecarga 1 (Completa): Sortal + Phases + Genset
static void avaliar_phase_pattern(const DeclGenset& g, const vector<string>& phases_fora_genset) {
    string geral = g.tem_geral ? g.geral.nome : "";
    OcorrenciaPadraoRP oc;
    oc.padrao = "Phase";
    oc.nome = geral.empty() ? "(sem classe geral)" : geral;
    oc.linha = linha_do_padrao(geral, g.linha);
    oc.identificado_por = "sobrecarga completa: genset '" + g.nome + "' com " +
                          to_string(g.especificas.size()) + " specifics do tipo phase";
    string ctx = "Padrão Phase '" + oc.nome + "'";

    if (geral.empty())
        oc.faltas.push_back("O genset '" + g.nome + "' não declara 'general' (o sortal particionado).");
    else
        verificar_sortal(geral, "phases", g.geral.linha, g.geral.coluna, oc, ctx, true);

    oc.elementos.push_back("genset: " + g.nome + " (linha " + to_string(g.linha) + ")");

    if (g.com_erro)
        oc.faltas.push_back("O genset '" + g.nome + "' possui erro sintático.");

    // Restrição do genset: 'disjoint' é obrigatório para phases ('complete' é opcional)
    if (g.modificadores & MOD_OVERLAPPING) {
        oc.faltas.push_back("O genset '" + g.nome + "' usa 'overlapping', mas phases são mutuamente "
                            "exclusivas e exigem 'disjoint'.");
    } else if (!(g.modificadores & MOD_DISJOINT)) {
        registrar_coercao(g.linha, g.coluna, ctx,
            "O genset '" + g.nome + "' agrupa phases sem a restrição obrigatória 'disjoint'.",
            "Restrição 'disjoint' assumida por coerção para o genset.");
        oc.coercoes.push_back("genset '" + g.nome + "': 'disjoint' assumido (linha " +
                              to_string(g.linha) + ")");
    }

    // Partição: duas ou mais phases complementares
    if (g.especificas.size() < 2)
        oc.faltas.push_back("O genset '" + g.nome + "' possui apenas " +
                            to_string(g.especificas.size()) +
                            " phase(s); a partição exige 2 ou mais phases complementares.");

    for (const Referencia& esp : g.especificas) {
        const DeclaracaoClasse* phase = buscar_classe(esp.nome);
        if (!phase) {
            oc.faltas.push_back("A phase '" + esp.nome + "' listada no genset não foi declarada.");
            continue;
        }
        inserir_especializacao(*phase, esp, geral, oc, ctx);
        oc.elementos.push_back("phase: " + esp.nome + (geral.empty() ? "" : " specializes " + geral));
    }

    for (const string& fora : phases_fora_genset)
        oc.faltas.push_back("A phase '" + fora + "' especializa '" + geral +
                            "', mas ficou fora das specifics do genset '" + g.nome + "'.");

    ocorrencias_rp.push_back(oc);
}

// Sobrecarga 2 (Incompleta): Sortal + Phases, mas sem Genset
static void avaliar_phase_pattern(const string& nome_mae, const vector<const DeclaracaoClasse*>& phases) {
    OcorrenciaPadraoRP oc;
    oc.padrao = "Phase";
    oc.nome = nome_mae;
    oc.linha = linha_do_padrao(nome_mae, phases[0]->linha);
    oc.identificado_por = "sobrecarga parcial: " + to_string(phases.size()) +
                          " phase(s) especializando '" + nome_mae + "' (sem genset)";
    string ctx = "Padrão Phase '" + nome_mae + "'";

    verificar_sortal(nome_mae, "phases", phases[0]->linha, phases[0]->coluna, oc, ctx, true);

    vector<string> nomes = nomes_das_classes(phases);
    for (const string& n : nomes)
        oc.elementos.push_back("phase: " + n + " specializes " + nome_mae);

    if (phases.size() >= 2)
        oc.faltas.push_back("Ausência de 'disjoint genset' particionando '" + nome_mae + "' em [" +
                            juntar_lista(nomes) + "] (ex.: disjoint complete genset " + nome_mae +
                            "_Phases { general " + nome_mae + " specifics " + juntar_lista(nomes) + " }).");
    else
        oc.faltas.push_back("'" + nomes[0] + "' é a única phase de '" + nome_mae +
                            "': a partição exige 2 ou mais phases complementares em um 'disjoint genset'.");

    ocorrencias_rp.push_back(oc);
}

// Sobrecarga 3 (Isolada/Incompleta): Phase sem nenhum sortal e fora de genset
static void avaliar_phase_pattern(const DeclaracaoClasse& phase_orfa) {
    OcorrenciaPadraoRP oc;
    oc.padrao = "Phase";
    oc.nome = phase_orfa.nome;
    oc.linha = phase_orfa.linha;
    oc.identificado_por = "sobrecarga por estereótipo: 'phase " + phase_orfa.nome + "' isolada";

    registrar_erro(phase_orfa.linha, phase_orfa.coluna, "Padrão Phase '" + phase_orfa.nome + "'",
        "Não existem phases sem um sortal: '" + phase_orfa.nome +
        "' não especializa nenhuma classe nem pertence a um genset.",
        "Declare 'phase " + phase_orfa.nome + " specializes <Sortal>' e agrupe-a com as phases "
        "complementares em um 'disjoint genset'.");

    oc.elementos.push_back("phase: " + phase_orfa.nome);
    oc.faltas.push_back("Não especializa nenhum sortal (falta 'specializes <Sortal>').");
    oc.faltas.push_back("Não participa de nenhum 'disjoint genset'.");

    ocorrencias_rp.push_back(oc);
}

static void analisar_padroes_phase() {
    // Gensets cujo significado (pelos tipos das specifics) é Phase pattern
    map<string, vector<const DeclGenset*>> gensets_por_geral;
    vector<string> ordem_gerais;
    set<string> phases_em_genset;
    for (const DeclGenset& g : gensets_declarados()) {
        if (significado_genset(g) != SignificadoGenset::PHASE) continue;
        string geral = g.tem_geral ? g.geral.nome : "";
        if (!gensets_por_geral.count(geral)) ordem_gerais.push_back(geral);
        gensets_por_geral[geral].push_back(&g);
        for (const Referencia& esp : g.especificas) phases_em_genset.insert(esp.nome);
    }

    // Phases fora de qualquer genset de phases, agrupadas pela classe-mãe
    map<string, vector<const DeclaracaoClasse*>> fora_por_mae;
    vector<string> ordem_maes;
    for (const DeclaracaoClasse& c : classes_declaradas()) {
        if (c.estereotipo != "phase" || phases_em_genset.count(c.nome)) continue;
        string mae = classe_mae_principal(c);
        if (mae.empty()) {
            // Sobrecarga 3: phase isolada
            avaliar_phase_pattern(c);
            continue;
        }
        if (!fora_por_mae.count(mae)) ordem_maes.push_back(mae);
        fora_por_mae[mae].push_back(&c);
    }

    // Sobrecarga 1: sortal + phases + genset (as phases do sortal fora da partição são faltas)
    for (const string& geral : ordem_gerais) {
        const vector<const DeclGenset*>& gs = gensets_por_geral[geral];
        vector<string> fora;
        if (!geral.empty() && fora_por_mae.count(geral)) fora = nomes_das_classes(fora_por_mae[geral]);
        for (size_t i = 0; i < gs.size(); i++)
            avaliar_phase_pattern(*gs[i], i == 0 ? fora : vector<string>());
    }

    // Sobrecarga 2: sortal + phases, sem genset
    for (const string& mae : ordem_maes) {
        if (gensets_por_geral.count(mae)) continue;   // já relatadas como fora da partição
        avaliar_phase_pattern(mae, fora_por_mae[mae]);
    }
}

/* ===================================================================== */
/*  2. ROLE PATTERN — Sobrecarga de Funções (Overloading)                */
/*                                                                       */
/*      kind ClassName                                                   */
/*      role Role_Name1 specializes ClassName                            */
/*      role Role_Name2 specializes ClassName                            */
/*      complete genset Class_Role_Genset_Name {                         */
/*          general ClassName                                            */
/*          specifics Role_Name1, Role_Name2                             */
/*      }                                                                */
/*  "complete" é opcional; "disjoint" não se aplica a roles.             */
/*  (A dependência relacional da role, via @mediation, é verificada no   */
/*  padrão Relator.)                                                     */
/* ===================================================================== */

// Sobrecarga 1 (Completa): Sortal + Roles + Genset
static void avaliar_role_pattern(const DeclGenset& g, const vector<string>& roles_fora_genset) {
    string geral = g.tem_geral ? g.geral.nome : "";
    OcorrenciaPadraoRP oc;
    oc.padrao = "Role";
    oc.nome = geral.empty() ? "(sem classe geral)" : geral;
    oc.linha = linha_do_padrao(geral, g.linha);
    oc.identificado_por = "sobrecarga completa: genset '" + g.nome + "' com " +
                          to_string(g.especificas.size()) + " specifics do tipo role";
    string ctx = "Padrão Role '" + oc.nome + "'";

    if (geral.empty())
        oc.faltas.push_back("O genset '" + g.nome + "' não declara 'general' (o sortal especializado).");
    else
        // classe geral não-sortal: o erro já é registrado pelo Relator ("role sem ancestral kind")
        verificar_sortal(geral, "roles", g.geral.linha, g.geral.coluna, oc, ctx, false);

    oc.elementos.push_back("genset: " + g.nome + " (linha " + to_string(g.linha) + ")");

    if (g.com_erro)
        oc.faltas.push_back("O genset '" + g.nome + "' possui erro sintático.");

    // Restrição do genset: 'disjoint' não se aplica a roles ('complete' é opcional)
    if (g.modificadores & MOD_DISJOINT) {
        int corrigido = g.modificadores & ~MOD_DISJOINT;
        string forma = (corrigido ? descrever_modificadores(corrigido) + " " : string()) + "genset " + g.nome;
        registrar_coercao(g.linha, g.coluna, ctx,
            "O genset '" + g.nome + "' agrupa roles com a restrição 'disjoint', que não se aplica a "
            "roles (a mesma instância pode desempenhar vários papéis).",
            "Restrição 'disjoint' removida por coerção; o genset é tratado como '" + forma + "'.");
        oc.coercoes.push_back("genset '" + g.nome + "': 'disjoint' removido (linha " +
                              to_string(g.linha) + ")");
    }

    for (const Referencia& esp : g.especificas) {
        const DeclaracaoClasse* role = buscar_classe(esp.nome);
        if (!role) {
            oc.faltas.push_back("A role '" + esp.nome + "' listada no genset não foi declarada.");
            continue;
        }
        inserir_especializacao(*role, esp, geral, oc, ctx);
        oc.elementos.push_back("role: " + esp.nome + (geral.empty() ? "" : " specializes " + geral));
    }

    for (const string& fora : roles_fora_genset)
        oc.faltas.push_back("A role '" + fora + "' especializa '" + geral +
                            "', mas ficou fora das specifics do genset '" + g.nome + "'.");

    ocorrencias_rp.push_back(oc);
}

// Sobrecarga 2 (Incompleta): Sortal + Roles, mas sem Genset
static void avaliar_role_pattern(const string& nome_mae, const vector<const DeclaracaoClasse*>& roles) {
    OcorrenciaPadraoRP oc;
    oc.padrao = "Role";
    oc.nome = nome_mae;
    oc.linha = linha_do_padrao(nome_mae, roles[0]->linha);
    oc.identificado_por = "sobrecarga parcial: " + to_string(roles.size()) +
                          " role(s) especializando '" + nome_mae + "' (sem genset)";
    string ctx = "Padrão Role '" + nome_mae + "'";

    verificar_sortal(nome_mae, "roles", roles[0]->linha, roles[0]->coluna, oc, ctx, false);

    vector<string> nomes = nomes_das_classes(roles);
    for (const string& n : nomes)
        oc.elementos.push_back("role: " + n + " specializes " + nome_mae);

    oc.faltas.push_back("Ausência de genset com 'general " + nome_mae + "' agrupando [" +
                        juntar_lista(nomes) + "] (ex.: genset " + nome_mae + "_Roles { general " +
                        nome_mae + " specifics " + juntar_lista(nomes) +
                        " }; 'complete' é opcional e 'disjoint' não se aplica a roles).");

    ocorrencias_rp.push_back(oc);
}

// Sobrecarga 3 (Isolada/Incompleta): Role sem nenhum sortal e fora de genset
static void avaliar_role_pattern(const DeclaracaoClasse& role_orfa) {
    OcorrenciaPadraoRP oc;
    oc.padrao = "Role";
    oc.nome = role_orfa.nome;
    oc.linha = role_orfa.linha;
    oc.identificado_por = "sobrecarga por estereótipo: 'role " + role_orfa.nome + "' isolada";

    // o erro "role sem ancestral kind" já é registrado pela verificação global do Relator
    oc.elementos.push_back("role: " + role_orfa.nome);
    oc.faltas.push_back("Não especializa nenhum sortal (falta 'specializes <Sortal>').");
    oc.faltas.push_back("Não participa de nenhum genset.");

    ocorrencias_rp.push_back(oc);
}

static void analisar_padroes_role() {
    // Roles nas specifics de um genset de roleMixin pertencem ao padrão RoleMixin
    set<string> roles_em_rolemixin;
    for (const DeclGenset& g : gensets_declarados())
        if (g.tem_geral && tipo_da_classe(g.geral.nome) == "roleMixin")
            for (const Referencia& esp : g.especificas) roles_em_rolemixin.insert(esp.nome);

    // Gensets cujo significado (pelos tipos das specifics) é Role pattern
    map<string, vector<const DeclGenset*>> gensets_por_geral;
    vector<string> ordem_gerais;
    set<string> roles_em_genset;
    for (const DeclGenset& g : gensets_declarados()) {
        if (significado_genset(g) != SignificadoGenset::ROLE) continue;
        string geral = g.tem_geral ? g.geral.nome : "";
        if (!gensets_por_geral.count(geral)) ordem_gerais.push_back(geral);
        gensets_por_geral[geral].push_back(&g);
        for (const Referencia& esp : g.especificas) roles_em_genset.insert(esp.nome);
    }

    // Roles fora de qualquer genset, agrupadas pela classe-mãe
    map<string, vector<const DeclaracaoClasse*>> fora_por_mae;
    vector<string> ordem_maes;
    for (const DeclaracaoClasse& c : classes_declaradas()) {
        if (c.estereotipo != "role" || roles_em_genset.count(c.nome) ||
            roles_em_rolemixin.count(c.nome))
            continue;
        string mae = classe_mae_principal(c);
        if (mae.empty()) {
            // Sobrecarga 3: role isolada
            avaliar_role_pattern(c);
            continue;
        }
        if (!fora_por_mae.count(mae)) ordem_maes.push_back(mae);
        fora_por_mae[mae].push_back(&c);
    }

    // Sobrecarga 1: sortal + roles + genset
    for (const string& geral : ordem_gerais) {
        const vector<const DeclGenset*>& gs = gensets_por_geral[geral];
        vector<string> fora;
        if (!geral.empty() && fora_por_mae.count(geral)) fora = nomes_das_classes(fora_por_mae[geral]);
        for (size_t i = 0; i < gs.size(); i++)
            avaliar_role_pattern(*gs[i], i == 0 ? fora : vector<string>());
    }

    // Sobrecarga 2: sortal + roles, sem genset
    for (const string& mae : ordem_maes) {
        if (gensets_por_geral.count(mae)) continue;   // já relatadas como fora do genset
        avaliar_role_pattern(mae, fora_por_mae[mae]);
    }
}

/* ===================================================================== */
/*  Genset ambíguo: phases e roles misturadas (sobrecarga não resolvida) */
/*                                                                       */
/*  Como na verificação de tipos do slide:                               */
/*      if (E1.type == E2.type) ... else SemanticError();                */
/*  As phases e roles desse genset são avaliadas como fora de genset.    */
/* ===================================================================== */

static void analisar_gensets_mistos() {
    for (const DeclGenset& g : gensets_declarados()) {
        if (significado_genset(g) != SignificadoGenset::MISTO) continue;

        vector<string> tipos;
        for (const Referencia& esp : g.especificas) {
            string tipo = tipo_da_classe(esp.nome);
            if (!tipo.empty()) tipos.push_back(esp.nome + ": " + tipo);
        }

        OcorrenciaPadraoRP oc;
        oc.padrao = "Role/Phase";
        oc.nome = g.tem_geral ? g.geral.nome : g.nome;
        oc.linha = linha_do_padrao(oc.nome, g.linha);
        oc.identificado_por = "sobrecarga ambígua: genset '" + g.nome +
                              "' com specifics de tipos diferentes";
        string ctx = "Padrão Role/Phase '" + oc.nome + "'";

        registrar_erro(g.linha, g.coluna, ctx,
            "O genset '" + g.nome + "' mistura classes de tipos incompatíveis (" +
            juntar_lista(tipos) + ").",
            "Separe em um genset só de phases ('disjoint' obrigatório) e outro só de roles "
            "(sem 'disjoint').");

        oc.elementos.push_back("genset: " + g.nome + " (linha " + to_string(g.linha) + ")");
        oc.faltas.push_back("Specifics de tipos incompatíveis (" + juntar_lista(tipos) +
                            "): o genset não pode ser interpretado como Phase nem como Role pattern.");
        ocorrencias_rp.push_back(oc);
    }
}

/* ===================================================================== */
/*  Ponto de entrada e impressão                                         */
/* ===================================================================== */

void analisar_padroes_role_phase() {
    ocorrencias_rp.clear();
    analisar_padroes_role();
    analisar_padroes_phase();
    analisar_gensets_mistos();
    stable_sort(ocorrencias_rp.begin(), ocorrencias_rp.end(),
                [](const OcorrenciaPadraoRP& a, const OcorrenciaPadraoRP& b) {
                    return a.linha < b.linha;
                });
}

static void imprimir_ocorrencia_rp(ostream& out, const OcorrenciaPadraoRP& oc) {
    out << "  [" << oc.padrao << "] " << oc.nome << " (linha " << oc.linha << ")\n";
    out << "      identificado por: " << oc.identificado_por << "\n";
    for (const string& e : oc.elementos) out << "      + " << e << "\n";
    for (const string& f : oc.faltas)    out << "      - FALTA: " << f << "\n";
    for (const string& c : oc.coercoes)  out << "      * COERÇÃO: " << c << "\n";
}

void imprimir_padroes_role_phase(ostream& out) {
    int completos = 0, incompletos = 0;
    for (const OcorrenciaPadraoRP& oc : ocorrencias_rp)
        (oc.faltas.empty() ? completos : incompletos)++;

    out << "\n=====================================================\n";
    out << "  ANÁLISE SEMÂNTICA: PADRÕES ROLE E PHASE\n";
    out << "=====================================================\n";

    out << "(1) PADRÕES COMPLETOS: " << completos << "\n";
    for (const OcorrenciaPadraoRP& oc : ocorrencias_rp)
        if (oc.faltas.empty()) imprimir_ocorrencia_rp(out, oc);
    if (completos == 0) out << "  (nenhum)\n";

    out << "\n(2) PADRÕES INCOMPLETOS (identificados por sobrecarga): " << incompletos << "\n";
    for (const OcorrenciaPadraoRP& oc : ocorrencias_rp)
        if (!oc.faltas.empty()) imprimir_ocorrencia_rp(out, oc);
    if (incompletos == 0) out << "  (nenhum)\n";

    out << "=====================================================\n";
}
