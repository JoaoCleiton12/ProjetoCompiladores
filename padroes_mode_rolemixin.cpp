#include "padroes_mode_rolemixin.h"

#include <algorithm>
#include <map>
#include <set>
#include <vector>

#include "classes_datatypes.h"
#include "enum_genset.h"
#include "relatorio_erros.h"

using namespace std;

/* ===================================================================== */
/*  Dados coletados durante a análise sintática                         */
/* ===================================================================== */

struct RelacaoInterna {
    string dona;          // classe em cujo bloco a relação foi declarada
    string estereotipo;   // characterization, externalDependence...
    string card_origem;   // lado da classe dona
    string card_destino;  // lado da classe alvo
    string destino;       // classe alvo
    int linha;
    int coluna;
};

static vector<RelacaoInterna> relacoes;

void padroes_registrar_relacao_interna(const string& dona, const string& estereotipo,
                                       const string& card_origem, const string& card_destino,
                                       const string& destino, int linha, int coluna) {
    RelacaoInterna r = {dona, estereotipo, card_origem, card_destino, destino, linha, coluna};
    relacoes.push_back(r);
}

/* ===================================================================== */
/*  Resultado da análise: ocorrências de padrões                         */
/* ===================================================================== */

struct OcorrenciaPadrao {
    string padrao;             // "Mode" ou "RoleMixin"
    string nome;               // classe central do padrão (o mode / o roleMixin)
    int linha;
    string identificado_por;   // qual construção e quais tipos identificaram o padrão
    vector<string> elementos;  // partes do padrão encontradas
    vector<string> faltas;     // o que impede o padrão de estar completo
    vector<string> coercoes;   // correções aplicadas por coerção
};

static vector<OcorrenciaPadrao> ocorrencias_padroes;

/* ===================================================================== */
/*  Tabela de símbolos: tipo (estereótipo) de cada classe                */
/* ===================================================================== */

/* Procura a classe pelo nome e devolve o seu tipo (estereótipo).
   Devolve "" se a classe não foi declarada. */
static string tipo_da_classe(const string& nome) {
    for (const DeclaracaoClasse& c : classes_declaradas())
        if (c.nome == nome) return c.estereotipo;
    return "";
}

static const DeclaracaoClasse* buscar_classe(const string& nome) {
    for (const DeclaracaoClasse& c : classes_declaradas())
        if (c.nome == nome) return &c;
    return nullptr;
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

/* Cardinalidades: "1", "*", "1..*", "0..1" ... */
static string card_minimo(const string& card) {
    if (card == "*") return "0";
    size_t p = card.find("..");
    return p == string::npos ? card : card.substr(0, p);
}

static string card_maximo(const string& card) {
    size_t p = card.find("..");
    return p == string::npos ? card : card.substr(p + 2);
}

static bool card_exatamente_um(const string& card) {
    return card == "1" || card == "1..1";
}

/* ===================================================================== */
/*  5. MODE PATTERN                                                      */
/*                                                                       */
/*      kind ClassName1                                                  */
/*      kind ClassName2                                                  */
/*      mode Mode_Name1 {                                                */
/*          @characterization [1..*] -- [1] ClassName1                   */
/*          @externalDependence [1..*] -- [1] ClassName2                 */
/*      }                                                                */
/*                                                                       */
/*  - @characterization: o mode inere em exatamente UM portador ([1]);   */
/*  - @externalDependence: classe da qual o mode depende externamente    */
/*    (cardinalidade mínima >= 1).                                       */
/* ===================================================================== */

static void analisar_mode(const string& nome_mode, int linha, const string& tipo,
                          const string& identificado_por) {
    OcorrenciaPadrao oc;
    oc.padrao = "Mode";
    oc.nome = nome_mode;
    oc.linha = linha;
    oc.identificado_por = identificado_por;
    string ctx = "Padrão Mode '" + nome_mode + "'";

    /* Verificação de tipo da classe central: esperado 'mode'. */
    if (tipo != "mode")
        oc.faltas.push_back("'" + nome_mode + "' foi declarada como '" + tipo +
                            "', mas o padrão exige o estereótipo 'mode' (" + tipo +
                            " não pode ser convertido em mode).");

    vector<RelacaoInterna> caracterizacoes, dependencias;
    for (const RelacaoInterna& r : relacoes) {
        if (r.dona != nome_mode) continue;
        if (r.estereotipo == "characterization") caracterizacoes.push_back(r);
        if (r.estereotipo == "externalDependence") dependencias.push_back(r);
    }

    /* @characterization: liga o mode ao seu portador */
    if (caracterizacoes.empty())
        oc.faltas.push_back("Nenhuma @characterization ligando o mode ao seu portador.");
    if (caracterizacoes.size() > 1)
        oc.faltas.push_back("Mais de uma @characterization: um mode inere em um único portador.");

    for (const RelacaoInterna& r : caracterizacoes) {
        string tipo_alvo = tipo_da_classe(r.destino);
        if (tipo_alvo.empty()) {
            oc.faltas.push_back("O portador '" + r.destino + "' (@characterization, linha " +
                                to_string(r.linha) + ") não foi declarado como classe.");
            continue;
        }
        oc.elementos.push_back("portador (@characterization): " + r.destino + " (" + tipo_alvo + ")");

        /* COERÇÃO: o portador deve ter cardinalidade exatamente [1] */
        if (!card_exatamente_um(r.card_destino)) {
            registrar_coercao(r.linha, r.coluna, ctx,
                "Cardinalidade do portador '" + r.destino + "' em @characterization é [" +
                r.card_destino + "], mas um mode inere em exatamente um portador.",
                "Cardinalidade convertida de [" + r.card_destino + "] para [1].");
            oc.coercoes.push_back("cardinalidade do portador '" + r.destino + "': [" +
                                  r.card_destino + "] -> [1] (linha " + to_string(r.linha) + ")");
        }
    }

    /* @externalDependence: de quem o mode depende externamente */
    if (dependencias.empty())
        oc.faltas.push_back("Nenhuma @externalDependence (o modelo do padrão Mode inclui a "
                            "dependência externa).");

    for (const RelacaoInterna& r : dependencias) {
        string tipo_alvo = tipo_da_classe(r.destino);
        if (tipo_alvo.empty()) {
            oc.faltas.push_back("A classe '" + r.destino + "' (@externalDependence, linha " +
                                to_string(r.linha) + ") não foi declarada.");
            continue;
        }
        oc.elementos.push_back("dependência externa (@externalDependence): " + r.destino +
                               " (" + tipo_alvo + ")");

        /* COERÇÃO: a cardinalidade mínima da dependência externa deve ser >= 1 */
        if (card_minimo(r.card_destino) == "0") {
            string maximo = card_maximo(r.card_destino);
            if (maximo == "0") maximo = "1";
            string nova = (maximo == "1") ? "1" : "1.." + maximo;
            registrar_coercao(r.linha, r.coluna, ctx,
                "Cardinalidade de '" + r.destino + "' em @externalDependence é [" +
                r.card_destino + "] (mínimo 0), mas a dependência externa exige mínimo 1.",
                "Cardinalidade convertida de [" + r.card_destino + "] para [" + nova + "].");
            oc.coercoes.push_back("cardinalidade de '" + r.destino + "': [" + r.card_destino +
                                  "] -> [" + nova + "] (linha " + to_string(r.linha) + ")");
        }
    }

    ocorrencias_padroes.push_back(oc);
}

static void analisar_padroes_mode() {
    set<string> ja_analisadas;

    /* Identificação pelo tipo da classe: toda classe 'mode' é um padrão Mode. */
    for (const DeclaracaoClasse& c : classes_declaradas()) {
        if (c.estereotipo != "mode" || ja_analisadas.count(c.nome)) continue;
        ja_analisadas.insert(c.nome);
        analisar_mode(c.nome, c.linha, c.estereotipo, "estereótipo 'mode' da classe '" + c.nome + "'");
    }

    /* Identificação por SOBRECARGA: @characterization e @externalDependence são
       relações do padrão Mode. Se aparecem em uma classe de outro tipo, o
       analisador as reconhece como uma tentativa (incompleta) do padrão.
       (Uma 'quality' também usa @characterization, então não entra aqui.) */
    for (const RelacaoInterna& r : relacoes) {
        if (r.dona.empty() || ja_analisadas.count(r.dona)) continue;
        bool relacao_de_mode = r.estereotipo == "externalDependence" ||
                               r.estereotipo == "characterization";
        if (!relacao_de_mode) continue;
        string tipo = tipo_da_classe(r.dona);
        if (tipo == "mode" || tipo == "quality") continue;
        ja_analisadas.insert(r.dona);
        const DeclaracaoClasse* c = buscar_classe(r.dona);
        analisar_mode(r.dona, c ? c->linha : r.linha, tipo,
                      "relação @" + r.estereotipo + " (própria de mode) na classe '" + r.dona +
                      "', declarada como '" + tipo + "'");
    }
}

/* ===================================================================== */
/*  6. ROLEMIXIN PATTERN                                                 */
/*                                                                       */
/*      kind ClassName1                                                  */
/*      kind ClassName2                                                  */
/*      roleMixin RoleMixin_Name                                         */
/*      role Role_Name1 specializes ClassName1, RoleMixin_Name           */
/*      role Role_Name2 specializes ClassName2, RoleMixin_Name           */
/*      disjoint complete genset RoleMixin_Genset_Name {                 */
/*          general RoleMixin_Name                                       */
/*          specifics Role_Name1, Role_Name2                             */
/*      }                                                                */
/*                                                                       */
/*  - o roleMixin é particionado {disjoint, complete} em 2 ou mais roles;*/
/*  - cada role especializa um sortal (ex.: um kind) e o roleMixin.      */
/* ===================================================================== */

static void analisar_genset_rolemixin(const DeclaracaoClasse& rm, const DeclGenset& g,
                                      const vector<string>& roles_fora_do_genset) {
    OcorrenciaPadrao oc;
    oc.padrao = "RoleMixin";
    oc.nome = rm.nome;
    oc.linha = rm.linha;
    oc.identificado_por = "genset '" + g.nome + "' com 'general " + rm.nome +
                          "', classe do tipo roleMixin";
    string ctx = "Padrão RoleMixin '" + rm.nome + "'";

    oc.elementos.push_back("roleMixin: " + rm.nome);
    oc.elementos.push_back("genset: " + g.nome + " (linha " + to_string(g.linha) + ")");

    if (g.com_erro)
        oc.faltas.push_back("O genset '" + g.nome + "' tem erro de sintaxe (ver relatório de erros).");

    /* Restrições do genset: o padrão exige {disjoint, complete}. */
    if (g.modificadores & MOD_OVERLAPPING)
        oc.faltas.push_back("O genset '" + g.nome + "' é 'overlapping', mas o padrão exige 'disjoint'.");
    else if (!(g.modificadores & MOD_DISJOINT)) {
        /* COERÇÃO: restrição omitida -> assume a exigida pelo padrão */
        registrar_coercao(g.linha, g.coluna, ctx,
            "O genset '" + g.nome + "' não declara 'disjoint', exigido pelo padrão RoleMixin.",
            "Restrição 'disjoint' assumida para o genset.");
        oc.coercoes.push_back("genset '" + g.nome + "': 'disjoint' assumido (linha " +
                              to_string(g.linha) + ")");
    }

    if (g.modificadores & MOD_INCOMPLETE)
        oc.faltas.push_back("O genset '" + g.nome + "' é 'incomplete', mas o padrão exige 'complete'.");
    else if (!(g.modificadores & MOD_COMPLETE)) {
        registrar_coercao(g.linha, g.coluna, ctx,
            "O genset '" + g.nome + "' não declara 'complete', exigido pelo padrão RoleMixin.",
            "Restrição 'complete' assumida para o genset.");
        oc.coercoes.push_back("genset '" + g.nome + "': 'complete' assumido (linha " +
                              to_string(g.linha) + ")");
    }

    /* Partição em 2 ou mais roles */
    if (g.especificas.size() < 2)
        oc.faltas.push_back("O genset tem " + to_string(g.especificas.size()) +
                            " classe(s) específica(s); o padrão exige pelo menos 2 roles.");

    for (const Referencia& esp : g.especificas) {
        const DeclaracaoClasse* role = buscar_classe(esp.nome);

        /* Verificação de tipo: cada específica deve ser do tipo 'role' */
        if (!role) {
            oc.faltas.push_back("A classe específica '" + esp.nome + "' não foi declarada.");
            continue;
        }
        if (role->estereotipo != "role") {
            oc.faltas.push_back("'" + esp.nome + "' foi declarada como '" + role->estereotipo +
                                "', mas as specifics de um roleMixin devem ser do tipo 'role'.");
            continue;
        }

        /* COERÇÃO: o role está no genset do roleMixin, mas não declara
           'specializes <roleMixin>' -> a especialização é inserida. */
        if (!contem(role->especializacoes, rm.nome)) {
            registrar_coercao(esp.linha, esp.coluna, ctx,
                "O role '" + esp.nome + "' está nas specifics do genset de '" + rm.nome +
                "', mas não declara 'specializes " + rm.nome + "'.",
                "Especialização '" + esp.nome + " specializes " + rm.nome +
                "' inserida a partir do genset.");
            oc.coercoes.push_back("'" + esp.nome + " specializes " + rm.nome +
                                  "' inserido (linha " + to_string(esp.linha) + ")");
        }

        /* Cada role deve especializar um sortal (o tipo que "joga" o papel). */
        string sortal, nao_declarado;
        for (const string& pai : role->especializacoes) {
            if (pai == rm.nome) continue;
            string tipo_pai = tipo_da_classe(pai);
            if (eh_sortal(tipo_pai)) { sortal = pai + " (" + tipo_pai + ")"; break; }
            if (tipo_pai.empty() && nao_declarado.empty()) nao_declarado = pai;
        }
        if (!sortal.empty())
            oc.elementos.push_back("role: " + esp.nome + " specializes " + sortal);
        else if (!nao_declarado.empty())
            oc.faltas.push_back("O role '" + esp.nome + "' especializa '" + nao_declarado +
                                "', que não foi declarado neste arquivo (não é possível "
                                "confirmar que é um sortal).");
        else
            oc.faltas.push_back("O role '" + esp.nome + "' não especializa nenhum sortal "
                                "(kind, collective, subkind, phase ou role).");
    }

    /* Roles que especializam o roleMixin mas ficaram fora da partição */
    for (const string& r : roles_fora_do_genset)
        oc.faltas.push_back("O role '" + r + "' especializa '" + rm.nome +
                            "', mas não está nas specifics de nenhum genset do roleMixin.");

    ocorrencias_padroes.push_back(oc);
}

static void analisar_padroes_rolemixin() {
    for (const DeclaracaoClasse& rm : classes_declaradas()) {
        if (rm.estereotipo != "roleMixin") continue;

        /* SOBRECARGA: o mesmo construto 'genset' significa padrões diferentes
           conforme o tipo da classe geral. Com general do tipo roleMixin, ele
           é uma ocorrência do padrão RoleMixin. */
        vector<const DeclGenset*> gensets_do_rm;
        for (const DeclGenset& g : gensets_declarados())
            if (g.tem_geral && g.geral.nome == rm.nome) gensets_do_rm.push_back(&g);

        /* Roles que declaram 'specializes <roleMixin>' */
        vector<string> roles_do_rm;
        for (const DeclaracaoClasse& c : classes_declaradas())
            if (contem(c.especializacoes, rm.nome)) roles_do_rm.push_back(c.nome);

        /* ... e quais deles não aparecem em nenhum genset do roleMixin */
        vector<string> fora;
        for (const string& r : roles_do_rm) {
            bool coberto = false;
            for (const DeclGenset* g : gensets_do_rm)
                for (const Referencia& e : g->especificas)
                    if (e.nome == r) coberto = true;
            if (!coberto) fora.push_back(r);
        }

        if (gensets_do_rm.empty()) {
            OcorrenciaPadrao oc;
            oc.padrao = "RoleMixin";
            oc.nome = rm.nome;
            oc.linha = rm.linha;
            oc.identificado_por = "estereótipo 'roleMixin' da classe '" + rm.nome + "'";
            oc.elementos.push_back("roleMixin: " + rm.nome);
            for (const string& r : roles_do_rm)
                oc.elementos.push_back("role que especializa o roleMixin: " + r);
            oc.faltas.push_back("Nenhum genset com 'general " + rm.nome +
                                "' particionando o roleMixin em roles.");
            ocorrencias_padroes.push_back(oc);
            continue;
        }

        for (size_t i = 0; i < gensets_do_rm.size(); i++)
            analisar_genset_rolemixin(rm, *gensets_do_rm[i],
                                      i == 0 ? fora : vector<string>());
    }
}

/* ===================================================================== */
/*  Ponto de entrada e impressão                                         */
/* ===================================================================== */

void analisar_padroes_mode_rolemixin() {
    ocorrencias_padroes.clear();
    analisar_padroes_mode();
    analisar_padroes_rolemixin();
    stable_sort(ocorrencias_padroes.begin(), ocorrencias_padroes.end(),
                [](const OcorrenciaPadrao& a, const OcorrenciaPadrao& b) {
                    return a.linha < b.linha;
                });
}

static void imprimir_ocorrencia(ostream& out, const OcorrenciaPadrao& oc) {
    out << "  [" << oc.padrao << "] " << oc.nome << " (linha " << oc.linha << ")\n";
    out << "      identificado por: " << oc.identificado_por << "\n";
    for (const string& e : oc.elementos) out << "      + " << e << "\n";
    for (const string& f : oc.faltas)    out << "      - FALTA: " << f << "\n";
    for (const string& c : oc.coercoes)  out << "      * COERÇÃO: " << c << "\n";
}

void imprimir_padroes_mode_rolemixin(ostream& out) {
    int completos = 0, incompletos = 0;
    for (const OcorrenciaPadrao& oc : ocorrencias_padroes)
        (oc.faltas.empty() ? completos : incompletos)++;

    out << "\n=====================================================\n";
    out << "  ANÁLISE SEMÂNTICA: PADRÕES MODE E ROLEMIXIN\n";
    out << "=====================================================\n";

    out << "(1) PADRÕES COMPLETOS: " << completos << "\n";
    for (const OcorrenciaPadrao& oc : ocorrencias_padroes)
        if (oc.faltas.empty()) imprimir_ocorrencia(out, oc);
    if (completos == 0) out << "  (nenhum)\n";

    out << "\n(2) PADRÕES INCOMPLETOS (identificados por sobrecarga): " << incompletos << "\n";
    for (const OcorrenciaPadrao& oc : ocorrencias_padroes)
        if (!oc.faltas.empty()) imprimir_ocorrencia(out, oc);
    if (incompletos == 0) out << "  (nenhum)\n";

    out << "=====================================================\n";
}
