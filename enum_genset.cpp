#include "enum_genset.h"
#include "relatorio_erros.h"
#include "tabela_simbolos.h"

#include <algorithm>
#include <cctype>
#include <map>
#include <set>
#include <sstream>

using namespace std;

/* ===================================================================== */
/*  Estado                                                               */
/* ===================================================================== */

static string pacote_atual = "(sem pacote)";

static vector<DeclEnum>   lista_enums;
static vector<DeclGenset> lista_gensets;

static bool     enum_aberto = false;
static DeclEnum enum_corrente;

static bool       genset_aberto = false;
static DeclGenset genset_corrente;

void definir_pacote_atual(const string& nome) { pacote_atual = nome; }

const vector<DeclEnum>& enums_declarados() { return lista_enums; }
const vector<DeclGenset>& gensets_declarados() { return lista_gensets; }

bool em_enum() { return enum_aberto; }
bool em_genset() { return genset_aberto; }

string contexto_enum_genset() {
    if (enum_aberto)
        return enum_corrente.nome.empty() ? "Enum" : "Enum '" + enum_corrente.nome + "'";
    if (genset_aberto)
        return genset_corrente.nome.empty() ? "Genset" : "Genset '" + genset_corrente.nome + "'";
    return "";
}

/* ===================================================================== */
/*  Utilitários                                                          */
/* ===================================================================== */

string capitalizar(const string& s) {
    string r = s;
    if (!r.empty()) r[0] = (char)toupper((unsigned char)r[0]);
    return r;
}

string descapitalizar(const string& s) {
    string r = s;
    if (!r.empty()) r[0] = (char)tolower((unsigned char)r[0]);
    return r;
}

string remover_digitos(const string& s) {
    string r;
    for (char c : s)
        if (!isdigit((unsigned char)c)) r += c;
    return r;
}

string sanitizar_identificador(const string& s) {
    string r;
    for (char c : s) {
        if (isalnum((unsigned char)c) || c == '_') r += c;
        else if (!r.empty() && r.back() != '_') r += '_';
    }
    while (!r.empty() && r.back() == '_') r.pop_back();
    return r;
}

string descrever_modificadores(int mods) {
    string disj = (mods & MOD_DISJOINT) ? "disjoint" : (mods & MOD_OVERLAPPING) ? "overlapping" : "";
    string comp = (mods & MOD_COMPLETE) ? "complete" : (mods & MOD_INCOMPLETE) ? "incomplete" : "";
    if (disj.empty() && comp.empty()) return "(nenhuma)";
    if (disj.empty()) return comp;
    if (comp.empty()) return disj;
    return disj + " " + comp;
}

string motivo_lexema_invalido(const string& s) {
    if (s.find('-') != string::npos) return "contém hífen '-' (não permitido em nomes)";
    if (!s.empty() && (s.front() == '_' || s.back() == '_'))
        return "começa ou termina com sublinhado (o sublinhado deve ser subcadeia própria do nome)";
    if (s.find("__") != string::npos) return "contém sublinhados consecutivos";
    for (char c : s)
        if (!isalnum((unsigned char)c) && c != '_')
            return string("contém o caractere inválido '") + c + "'";
    bool tem_digito_meio = false;
    for (size_t i = 0; i + 1 < s.size(); i++)
        if (isdigit((unsigned char)s[i]) && !isdigit((unsigned char)s[i + 1])) tem_digito_meio = true;
    if (tem_digito_meio) return "contém números fora do final do nome";
    return "não segue as convenções de nomes da linguagem";
}

static string minusculo(const string& s) {
    string r = s;
    for (char& c : r) c = (char)tolower((unsigned char)c);
    return r;
}

static string juntar(const vector<Referencia>& refs, const string& sep = ", ") {
    string r;
    for (size_t i = 0; i < refs.size(); i++) {
        if (i) r += sep;
        r += refs[i].nome;
    }
    return r;
}

/* Um nome já está em uso por outro enum ou genset? */
static bool nome_usado(const string& nome, string& categoria, int& linha) {
    for (const DeclEnum& e : lista_enums)
        if (e.nome == nome) { categoria = "enum"; linha = e.linha; return true; }
    for (const DeclGenset& g : lista_gensets)
        if (g.nome == nome) { categoria = "genset"; linha = g.linha; return true; }
    return false;
}

/* ===================================================================== */
/*  Tópico 4 — Classes enumeradas                                        */
/* ===================================================================== */

void enum_iniciar(const string& nome, int linha, int coluna) {
    if (enum_aberto) enum_finalizar(true, enum_corrente.linha);
    enum_corrente = DeclEnum();
    enum_corrente.nome = nome;
    enum_corrente.pacote = pacote_atual;
    enum_corrente.linha = linha;
    enum_corrente.coluna = coluna;
    enum_corrente.com_erro = false;
    enum_aberto = true;
}

void enum_adicionar_especializacao(const string& nome, int linha, int coluna) {
    if (!enum_aberto) return;
    if (nome == enum_corrente.nome && !nome.empty()) {
        registrar_erro(linha, coluna, "Enum '" + enum_corrente.nome + "'",
                       "O enum '" + nome + "' especializa a si mesmo.",
                       "Remova '" + nome + "' da cláusula specializes ou indique outro tipo pai.");
        return;
    }
    enum_corrente.especializa.push_back({nome, linha, coluna});
}

void enum_adicionar_literal(const string& nome, int linha, int coluna) {
    if (!enum_aberto || nome.empty()) return;
    for (const Referencia& r : enum_corrente.literais) {
        if (r.nome == nome) {
            registrar_erro(linha, coluna, contexto_enum_genset(),
                           "Literal '" + nome + "' repetido (já declarado na linha " +
                               to_string(r.linha) + ").",
                           "Cada literal (instância) de um enum deve ser único; remova a repetição.");
            return;
        }
    }
    if (!enum_corrente.nome.empty() && nome == enum_corrente.nome) {
        registrar_aviso(linha, coluna, contexto_enum_genset(),
                        "O literal '" + nome + "' tem o mesmo nome do próprio enum.",
                        "Use um nome que identifique o indivíduo, ex.: '" + nome + "1'.");
    }
    enum_corrente.literais.push_back({nome, linha, coluna});
}

void enum_finalizar(bool com_erro_sintatico, int linha_fim) {
    if (!enum_aberto) return;
    enum_aberto = false;
    DeclEnum e = enum_corrente;
    e.com_erro = com_erro_sintatico;
    e.linha_fim = max(linha_fim, e.linha);
    string ctx = e.nome.empty() ? "Enum" : "Enum '" + e.nome + "'";

    if (!e.nome.empty()) {
        string categoria;
        int linha_ant;
        if (nome_usado(e.nome, categoria, linha_ant)) {
            registrar_erro(e.linha, e.coluna, ctx,
                           "Nome '" + e.nome + "' já foi usado por outro " + categoria +
                               " (linha " + to_string(linha_ant) + ").",
                           "Renomeie um dos construtos; nomes de enums e gensets devem ser únicos.");
        } else if (tabela_simbolos.count(e.nome)) {
            registrar_erro(e.linha, e.coluna, ctx,
                           "Nome '" + e.nome + "' já foi declarado como " +
                               tabela_simbolos[e.nome].categoria + " (linha " +
                               to_string(tabela_simbolos[e.nome].linha_declaracao) + ").",
                           "Escolha outro nome para o enum.");
        } else {
            inserir_simbolo(e.nome, "Enum", e.linha);
        }
    }

    if (!com_erro_sintatico && e.literais.empty()) {
        registrar_aviso(e.linha, e.coluna, ctx,
                        "Enum declarado sem nenhum literal.",
                        "Classes enumeradas têm um conjunto finito e pré-definido de instâncias: "
                        "enum " + (e.nome.empty() ? string("Nome") : e.nome) + " { Literal1, Literal2 }.");
    } else if (!com_erro_sintatico && e.literais.size() == 1) {
        registrar_aviso(e.linha, e.coluna, ctx,
                        "Enum com apenas um literal ('" + e.literais[0].nome + "').",
                        "Verifique se faltam literais; um enum costuma enumerar duas ou mais instâncias.");
    }

    lista_enums.push_back(e);
}

/* ===================================================================== */
/*  Tópico 5 — Generalization sets                                       */
/* ===================================================================== */

void genset_iniciar(const string& nome, int modificadores, int linha, int coluna) {
    if (genset_aberto) genset_finalizar(true, genset_corrente.linha);
    genset_corrente = DeclGenset();
    genset_corrente.nome = nome;
    genset_corrente.pacote = pacote_atual;
    genset_corrente.linha = linha;
    genset_corrente.coluna = coluna;
    genset_corrente.modificadores = modificadores;
    genset_corrente.forma_curta = false;
    genset_corrente.tem_geral = false;
    genset_corrente.tem_categorizador = false;
    genset_corrente.com_erro = false;
    genset_aberto = true;
}

void genset_definir_forma(bool forma_curta) {
    if (genset_aberto) genset_corrente.forma_curta = forma_curta;
}

void genset_definir_geral(const string& nome, int linha, int coluna) {
    if (!genset_aberto || nome.empty()) return;
    genset_corrente.tem_geral = true;
    genset_corrente.geral = {nome, linha, coluna};
}

void genset_definir_categorizador(const string& nome, int linha, int coluna) {
    if (!genset_aberto || nome.empty()) return;
    genset_corrente.tem_categorizador = true;
    genset_corrente.categorizador = {nome, linha, coluna};
}

void genset_adicionar_especifica(const string& nome, int linha, int coluna) {
    if (!genset_aberto || nome.empty()) return;
    for (const Referencia& r : genset_corrente.especificas) {
        if (r.nome == nome) {
            registrar_erro(linha, coluna, contexto_enum_genset(),
                           "Classe específica '" + nome + "' listada mais de uma vez.",
                           "Remova a repetição de '" + nome + "' da lista de classes filhas.");
            return;
        }
    }
    genset_corrente.especificas.push_back({nome, linha, coluna});
}

void genset_finalizar(bool com_erro_sintatico, int linha_fim) {
    if (!genset_aberto) return;
    genset_aberto = false;
    DeclGenset g = genset_corrente;
    g.com_erro = com_erro_sintatico;
    g.linha_fim = max(linha_fim, g.linha);
    string ctx = g.nome.empty() ? "Genset" : "Genset '" + g.nome + "'";

    /* Nome único */
    if (!g.nome.empty()) {
        string categoria;
        int linha_ant;
        if (nome_usado(g.nome, categoria, linha_ant)) {
            registrar_erro(g.linha, g.coluna, ctx,
                           "Nome '" + g.nome + "' já foi usado por outro " + categoria +
                               " (linha " + to_string(linha_ant) + ").",
                           "Cada conjunto de generalização deve ter nome único, de preferência "
                               "expressando o aspecto da classificação (ex.: 'Tipos_De_" +
                               (g.tem_geral ? g.geral.nome : string("Classe")) + "').");
        } else if (tabela_simbolos.count(g.nome)) {
            registrar_erro(g.linha, g.coluna, ctx,
                           "Nome '" + g.nome + "' já foi declarado como " +
                               tabela_simbolos[g.nome].categoria + " (linha " +
                               to_string(tabela_simbolos[g.nome].linha_declaracao) + ").",
                           "Use um nome próprio para o genset, diferente das classes que ele agrupa.");
        } else {
            inserir_simbolo(g.nome, "Genset", g.linha);
        }

        /* Nome que imita as palavras de restrição (ex.: genset disjoint_complete { ... }) */
        string n = minusculo(g.nome);
        bool parece_restricao = n.find("disjoint") != string::npos || n.find("complete") != string::npos ||
                                n.find("overlapping") != string::npos;
        if (parece_restricao && g.modificadores == 0) {
            registrar_aviso(g.linha, g.coluna, ctx,
                            "O nome '" + g.nome + "' parece conter restrições, mas o genset não declara "
                            "nenhuma (ele será tratado como overlapping incomplete).",
                            "Restrições são palavras reservadas que antecedem 'genset': "
                            "disjoint complete genset NomeDoGenset { ... }.");
        }
    }

    if (!com_erro_sintatico) {
        /* Classe geral também listada como específica → herança cíclica */
        if (g.tem_geral) {
            for (const Referencia& r : g.especificas) {
                if (r.nome == g.geral.nome) {
                    registrar_erro(r.linha, r.coluna, ctx,
                                   "A classe '" + r.nome + "' aparece como geral e como específica "
                                   "(uma classe não pode especializar a si mesma).",
                                   "Remova '" + r.nome + "' da lista de classes específicas.");
                }
            }
            if (g.tem_categorizador && g.categorizador.nome == g.geral.nome) {
                registrar_erro(g.categorizador.linha, g.categorizador.coluna, ctx,
                               "O categorizador '" + g.categorizador.nome + "' é a própria classe geral.",
                               "O categorizador deve ser um tipo de alta ordem (ex.: type "
                               "PersonTypeByAge) cujas instâncias são as classes específicas.");
            }
        }
        if (g.tem_categorizador) {
            for (const Referencia& r : g.especificas)
                if (r.nome == g.categorizador.nome)
                    registrar_erro(r.linha, r.coluna, ctx,
                                   "O categorizador '" + r.nome + "' também aparece como classe específica.",
                                   "Remova '" + r.nome + "' de specifics ou escolha outro categorizador.");
        }
        if (g.especificas.size() == 1) {
            registrar_aviso(g.especificas[0].linha, g.especificas[0].coluna, ctx,
                            "Generalização com apenas uma classe específica ('" + g.especificas[0].nome + "').",
                            "Um generalization set agrupa as subclasses de um mesmo aspecto; se houver só "
                            "uma, prefira 'kind/subkind/... " + g.especificas[0].nome + " specializes " +
                                (g.tem_geral ? g.geral.nome : string("ClasseMae")) + "'.");
        }
    }

    lista_gensets.push_back(g);
}

void enum_genset_recuperar_erro() {
    if (enum_aberto) enum_finalizar(true, enum_corrente.linha);
    if (genset_aberto) genset_finalizar(true, genset_corrente.linha);
}

/* ===================================================================== */
/*  Verificações pós-análise                                             */
/* ===================================================================== */

static bool eh_categoria_classe(const string& categoria) {
    return categoria.rfind("Classe", 0) == 0;   // começa com "Classe"
}

void verificar_referencias_enum_genset() {
    /* Duas gensets diferentes com a mesma classe geral e as mesmas específicas */
    for (size_t i = 0; i < lista_gensets.size(); i++) {
        for (size_t j = i + 1; j < lista_gensets.size(); j++) {
            const DeclGenset& a = lista_gensets[i];
            const DeclGenset& b = lista_gensets[j];
            if (!a.tem_geral || !b.tem_geral || a.geral.nome != b.geral.nome) continue;
            set<string> sa, sb;
            for (auto& r : a.especificas) sa.insert(r.nome);
            for (auto& r : b.especificas) sb.insert(r.nome);
            if (!sa.empty() && sa == sb)
                registrar_aviso(b.linha, b.coluna, "Genset '" + b.nome + "'",
                                "Mesma classe geral e mesmas específicas do genset '" + a.nome +
                                    "' (linha " + to_string(a.linha) + ").",
                                "Gensets duplicados são redundantes; mantenha apenas um.");
        }
    }

    /* Referências a classes: só é possível verificar se a declaração de classes
       registrar os símbolos na tabela com categoria iniciada por "Classe". */
    bool ha_classes = false;
    for (const auto& par : tabela_simbolos)
        if (eh_categoria_classe(par.second.categoria)) { ha_classes = true; break; }

    auto verificar = [&](const DeclGenset& g, const Referencia& r, const string& papel) {
        string ctx = "Genset '" + g.nome + "'";
        auto it = tabela_simbolos.find(r.nome);
        if (it != tabela_simbolos.end() && it->second.categoria == "Enum") {
            registrar_erro(r.linha, r.coluna, ctx,
                           "'" + r.nome + "' é um enum e não pode ser " + papel + " de uma generalização.",
                           "Gensets relacionam classes (kind, subkind, role, phase...); "
                           "use uma classe declarada.");
            return;
        }
        if (!ha_classes) return;
        if (it == tabela_simbolos.end() || !eh_categoria_classe(it->second.categoria)) {
            registrar_erro(r.linha, r.coluna, ctx,
                           "Classe " + papel + " '" + r.nome + "' não foi declarada.",
                           "Declare a classe antes do genset (ex.: 'kind " + r.nome +
                               "') ou corrija o nome.");
        } else if (it->second.linha_declaracao > g.linha) {
            registrar_aviso(r.linha, r.coluna, ctx,
                            "Classe " + papel + " '" + r.nome + "' só é declarada depois (linha " +
                                to_string(it->second.linha_declaracao) + ").",
                            "Declare as classes antes do genset que as agrupa.");
        }
    };

    for (const DeclGenset& g : lista_gensets) {
        if (g.tem_geral) verificar(g, g.geral, "geral");
        if (g.tem_categorizador) verificar(g, g.categorizador, "categorizadora");
        for (const Referencia& r : g.especificas) verificar(g, r, "específica");
    }
}

/* ===================================================================== */
/*  Tabela de síntese                                                    */
/* ===================================================================== */

/* largura visível de uma string UTF-8 */
static size_t largura(const string& s) {
    size_t n = 0;
    for (unsigned char c : s)
        if ((c & 0xC0) != 0x80) n++;
    return n;
}

/* Status de um construto: quantos erros do relatório caem nas suas linhas. */
static string status_construto(int inicio, int fim, bool com_erro_sintatico) {
    int n = 0;
    for (const Ocorrencia& o : ocorrencias())
        if (o.severidade == Severidade::ERRO && o.linha >= inicio && o.linha <= fim) n++;
    if (n == 0 && com_erro_sintatico) n = 1;
    return n == 0 ? "ok" : to_string(n) + " erro(s)";
}

static void imprimir_tabela(ostream& out, const vector<string>& cab, const vector<vector<string>>& linhas) {
    vector<size_t> w(cab.size());
    for (size_t i = 0; i < cab.size(); i++) w[i] = largura(cab[i]);
    for (const auto& l : linhas)
        for (size_t i = 0; i < l.size(); i++) w[i] = max(w[i], largura(l[i]));

    auto separador = [&]() {
        out << "+";
        for (size_t x : w) out << string(x + 2, '-') << "+";
        out << "\n";
    };
    auto linha = [&](const vector<string>& l) {
        out << "|";
        for (size_t i = 0; i < l.size(); i++)
            out << " " << l[i] << string(w[i] - largura(l[i]), ' ') << " |";
        out << "\n";
    };

    separador();
    linha(cab);
    separador();
    for (const auto& l : linhas) linha(l);
    separador();
}

void imprimir_sintese_enum_genset(ostream& out) {
    /* ---------------- Enums ---------------- */
    out << "\n=====================================================\n";
    out << "     SÍNTESE: CLASSES ENUMERADAS (enum) — Tópico 4   \n";
    out << "=====================================================\n";
    out << "Total de enums declarados: " << lista_enums.size() << "\n";
    if (!lista_enums.empty()) {
        size_t total_literais = 0;
        vector<vector<string>> linhas;
        for (size_t i = 0; i < lista_enums.size(); i++) {
            const DeclEnum& e = lista_enums[i];
            total_literais += e.literais.size();
            linhas.push_back({to_string(i + 1),
                              e.nome.empty() ? "(sem nome)" : e.nome,
                              e.pacote,
                              to_string(e.linha),
                              e.especializa.empty() ? "-" : juntar(e.especializa),
                              to_string(e.literais.size()),
                              e.literais.empty() ? "-" : juntar(e.literais),
                              status_construto(e.linha, e.linha_fim, e.com_erro)});
        }
        out << "Total de literais (instâncias): " << total_literais << "\n";
        imprimir_tabela(out, {"#", "Enum", "Pacote", "Linha", "Especializa", "Qtd", "Literais", "Status"},
                        linhas);
    }

    /* ---------------- Gensets ---------------- */
    out << "\n=====================================================\n";
    out << "   SÍNTESE: GENERALIZAÇÕES (genset) — Tópico 5       \n";
    out << "=====================================================\n";
    int curtas = 0, longas = 0;
    for (const DeclGenset& g : lista_gensets) (g.forma_curta ? curtas : longas)++;
    out << "Total de generalization sets: " << lista_gensets.size()
        << "  (forma curta 'where': " << curtas << ", forma em bloco '{ }': " << longas << ")\n";

    if (!lista_gensets.empty()) {
        vector<vector<string>> linhas;
        for (size_t i = 0; i < lista_gensets.size(); i++) {
            const DeclGenset& g = lista_gensets[i];
            linhas.push_back({to_string(i + 1),
                              g.nome.empty() ? "(sem nome)" : g.nome,
                              g.pacote,
                              to_string(g.linha),
                              g.forma_curta ? "curta" : "bloco",
                              descrever_modificadores(g.modificadores),
                              g.tem_geral ? g.geral.nome : "-",
                              g.tem_categorizador ? g.categorizador.nome : "-",
                              g.especificas.empty() ? "-" : juntar(g.especificas),
                              status_construto(g.linha, g.linha_fim, g.com_erro)});
        }
        imprimir_tabela(out, {"#", "Genset", "Pacote", "Linha", "Forma", "Restrições", "Geral",
                              "Categorizador", "Específicas", "Status"},
                        linhas);

        /* Contagem por restrição */
        map<string, int> por_restricao;
        for (const DeclGenset& g : lista_gensets) por_restricao[descrever_modificadores(g.modificadores)]++;
        out << "Gensets por restrição:";
        for (const auto& p : por_restricao) out << "  " << p.first << " = " << p.second << ";";
        out << "\n";

        /* Taxonomia: classe geral -> específicas */
        map<string, vector<string>> taxonomia;
        for (const DeclGenset& g : lista_gensets)
            if (g.tem_geral)
                for (const Referencia& r : g.especificas) {
                    vector<string>& filhas = taxonomia[g.geral.nome];
                    if (find(filhas.begin(), filhas.end(), r.nome) == filhas.end()) filhas.push_back(r.nome);
                }
        if (!taxonomia.empty()) {
            out << "\nTaxonomia derivada dos gensets (classe-mãe -> classes filhas):\n";
            for (const auto& p : taxonomia) {
                out << "  " << p.first << " -> ";
                for (size_t i = 0; i < p.second.size(); i++) out << (i ? ", " : "") << p.second[i];
                out << "\n";
            }
        }
    }

    /* ---------------- Por pacote ---------------- */
    map<string, pair<vector<string>, vector<string>>> por_pacote;
    for (const DeclEnum& e : lista_enums)
        por_pacote[e.pacote].first.push_back(e.nome.empty() ? "(sem nome)" : e.nome);
    for (const DeclGenset& g : lista_gensets)
        por_pacote[g.pacote].second.push_back(g.nome.empty() ? "(sem nome)" : g.nome);
    if (!por_pacote.empty()) {
        out << "\nEnums e gensets por pacote:\n";
        for (const auto& p : por_pacote) {
            out << "  Pacote " << p.first << ": " << p.second.first.size() << " enum(s)";
            if (!p.second.first.empty()) {
                out << " [";
                for (size_t i = 0; i < p.second.first.size(); i++)
                    out << (i ? ", " : "") << p.second.first[i];
                out << "]";
            }
            out << "; " << p.second.second.size() << " genset(s)";
            if (!p.second.second.empty()) {
                out << " [";
                for (size_t i = 0; i < p.second.second.size(); i++)
                    out << (i ? ", " : "") << p.second.second[i];
                out << "]";
            }
            out << "\n";
        }
    }
    out << "=====================================================\n";
}
