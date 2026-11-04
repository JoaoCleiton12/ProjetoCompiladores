#include "classes_datatypes.h"

#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include "relatorio_erros.h"
#include "tabela_simbolos.h"
#include "enum_genset.h"

using namespace std;

static vector<DeclaracaoClasse> lista_classes;
static vector<DeclaracaoDataType> lista_datatypes;
static DeclaracaoClasse* classe_atual = nullptr;
static DeclaracaoDataType* datatype_atual = nullptr;

static string seguro(const char* s) { return s ? string(s) : string(); }

static bool tipo_nativo(const string& tipo) {
    static const unordered_set<string> nativos = {
        "number", "string", "boolean", "date", "time", "datetime",
        "int" // aceito por compatibilidade com o exemplo Address da especificação
    };
    return nativos.count(tipo) != 0;
}

static bool nome_datatype_declarado(const string& nome) {
    for (const auto& d : lista_datatypes)
        if (d.nome == nome) return true;
    return false;
}

static bool nome_classe_declarado(const string& nome) {
    for (const auto& c : lista_classes)
        if (c.nome == nome) return true;
    return false;
}

static bool nome_ja_declarado(const string& nome) {
    return nome_classe_declarado(nome) || nome_datatype_declarado(nome);
}

static void verificar_atributo_duplicado(const vector<AtributoOntologia>& attrs,
                                         const string& nome, int linha, int coluna,
                                         const string& contexto) {
    for (const auto& a : attrs) {
        if (a.nome == nome) {
            registrar_erro(linha, coluna, contexto,
                "Atributo '" + nome + "' declarado mais de uma vez.",
                "Renomeie ou remova a declaração duplicada dentro do mesmo bloco.");
            return;
        }
    }
}

void classe_iniciar(const char* estereotipo, const char* nome, int linha, int coluna) {
    classe_atual = nullptr;
    string n = seguro(nome);
    if (n.empty()) return;

    bool duplicado = nome_ja_declarado(n) || tabela_simbolos.find(n) != tabela_simbolos.end();
    if (duplicado) {
        registrar_erro(linha, coluna, "Classe",
            "O identificador '" + n + "' já foi declarado.",
            "Utilize um identificador ainda não declarado.");
    }

    lista_classes.push_back({n, seguro(estereotipo), linha, coluna, {}, {}, 0, false});
    classe_atual = &lista_classes.back();
    if (!duplicado) inserir_simbolo(n, "Classe", linha);
}

void classe_adicionar_especializacao(const char* nome, int linha, int coluna) {
    if (!classe_atual) return;
    string n = seguro(nome);
    if (n.empty()) return;
    for (const auto& existente : classe_atual->especializacoes) {
        if (existente == n) {
            registrar_erro(linha, coluna, "Classe",
                "Especialização '" + n + "' repetida na declaração da classe '" +
                classe_atual->nome + "'.",
                "Liste cada classe especializada uma única vez.");
            return;
        }
    }
    classe_atual->especializacoes.push_back(n);
}

void classe_adicionar_atributo(const char* nome, const char* tipo, const char* meta,
                               int linha, int coluna) {
    if (!classe_atual) return;
    string n = seguro(nome), t = seguro(tipo), m = seguro(meta);
    verificar_atributo_duplicado(classe_atual->atributos, n, linha, coluna, "Classe");
    classe_atual->atributos.push_back({n, t, linha, m});
}

void classe_adicionar_relacao_interna(int) {
    if (classe_atual) classe_atual->relacoes_internas++;
}

void classe_finalizar(bool com_erro, int) {
    if (classe_atual) classe_atual->com_erro = com_erro;
    classe_atual = nullptr;
}

void datatype_iniciar(const char* nome, int linha, int coluna) {
    datatype_atual = nullptr;
    string n = seguro(nome);
    if (n.empty()) return;

    bool duplicado = nome_ja_declarado(n) || tabela_simbolos.find(n) != tabela_simbolos.end();
    if (duplicado) {
        registrar_erro(linha, coluna, "DataType",
            "O identificador '" + n + "' já foi declarado.",
            "Utilize um nome de tipo ainda não utilizado.");
    }

    lista_datatypes.push_back({n, linha, coluna, {}, false});
    datatype_atual = &lista_datatypes.back();
    if (!duplicado) inserir_simbolo(n, "Tipo de Dado", linha);
}

void datatype_adicionar_atributo(const char* nome, const char* tipo, const char* meta,
                                 int linha, int coluna) {
    if (!datatype_atual) return;
    string n = seguro(nome), t = seguro(tipo), m = seguro(meta);
    verificar_atributo_duplicado(datatype_atual->atributos, n, linha, coluna, "DataType");
    datatype_atual->atributos.push_back({n, t, linha, m});
}

void datatype_finalizar(bool com_erro, int) {
    if (datatype_atual) datatype_atual->com_erro = com_erro;
    datatype_atual = nullptr;
}

void verificar_referencias_classes_datatypes() {
    auto verificar = [](const vector<AtributoOntologia>& attrs, const string& dono,
                        const string& contexto) {
        for (const auto& a : attrs) {
            if (tipo_nativo(a.tipo)) continue;
            bool tipo_encontrado = nome_datatype_declarado(a.tipo) || nome_classe_declarado(a.tipo);
            if (!tipo_encontrado) {
                for (const auto& e : enums_declarados())
                    if (e.nome == a.tipo) { tipo_encontrado = true; break; }
            }
            if (!tipo_encontrado) {
                registrar_erro(a.linha, 1, contexto,
                    "O atributo '" + a.nome + "' de '" + dono +
                    "' utiliza o tipo '" + a.tipo + "', que não foi declarado como datatype.",
                    "Declare 'datatype " + a.tipo + " { ... }' ou utilize um dos tipos nativos: "
                    "number, string, boolean, date, time ou datetime (também é aceito int por compatibilidade com o exemplo). ");
            }
        }
    };

    for (const auto& c : lista_classes) {
        verificar(c.atributos, c.nome, "Classe");
        for (const auto& especializacao : c.especializacoes) {
            if (!nome_classe_declarado(especializacao)) {
                registrar_aviso(c.linha, c.coluna, "Classe",
                    "A classe '" + c.nome + "' especializa '" + especializacao +
                    "', mas essa classe não foi declarada no arquivo.",
                    "Declare a classe especializada ou confira a grafia do nome.");
            }
        }
    }
    for (const auto& d : lista_datatypes)
        verificar(d.atributos, d.nome, "DataType");
}

void imprimir_sintese_classes_datatypes(ostream& out) {
    size_t total_atributos_classes = 0, total_atributos_datatypes = 0, total_relacoes = 0;
    out << "\n=====================================================\n";
    out << "       SÍNTESE DE CLASSES E TIPOS DE DADOS\n";
    out << "=====================================================\n";

    out << "Classes declaradas: " << lista_classes.size() << "\n";
    for (const auto& c : lista_classes) {
        total_atributos_classes += c.atributos.size();
        total_relacoes += c.relacoes_internas;
        out << "  " << c.estereotipo << " " << c.nome
            << " | atributos: " << c.atributos.size()
            << " | relações internas: " << c.relacoes_internas
            << (c.com_erro ? " | bloco com erro" : "") << "\n";
        for (const auto& a : c.atributos)
            out << "      - " << a.nome << ": " << a.tipo
                << (a.meta_atributo.empty() ? "" : " {" + a.meta_atributo + "}") << "\n";
    }

    out << "Tipos de dados declarados: " << lista_datatypes.size() << "\n";
    for (const auto& d : lista_datatypes) {
        total_atributos_datatypes += d.atributos.size();
        out << "  datatype " << d.nome << " | atributos: " << d.atributos.size()
            << (d.com_erro ? " | bloco com erro" : "") << "\n";
        for (const auto& a : d.atributos)
            out << "      - " << a.nome << ": " << a.tipo
                << (a.meta_atributo.empty() ? "" : " {" + a.meta_atributo + "}") << "\n";
    }

    out << "Total de atributos em classes....: " << total_atributos_classes << "\n";
    out << "Total de atributos em datatypes..: " << total_atributos_datatypes << "\n";
    out << "Total de relações internas.......: " << total_relacoes << "\n";
    out << "=====================================================\n";
}

const vector<DeclaracaoClasse>& classes_declaradas() { return lista_classes; }
const vector<DeclaracaoDataType>& datatypes_declarados() { return lista_datatypes; }
