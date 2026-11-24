#include "tabela_simbolos.h"
#include "relatorio_erros.h"

#include <algorithm>
#include <vector>

using namespace std;

// Encapsulada no módulo: nenhum outro arquivo acessa diretamente
static unordered_map<string, Simbolo> tabela_simbolos;

bool inserir_simbolo(const string& nome, const string& categoria, int linha, int coluna) {
    auto it = tabela_simbolos.find(nome);
    if (it == tabela_simbolos.end()) {
        tabela_simbolos[nome] = {nome, categoria, linha};
        return true;
    }

    registrar_aviso(linha, coluna, categoria,
        "O símbolo '" + nome + "' já foi declarado (linha " +
            to_string(it->second.linha_declaracao) + ").",
        "Utilize um identificador único para cada elemento.");
    return false;
}

bool simbolo_existe(const string& nome) {
    return tabela_simbolos.find(nome) != tabela_simbolos.end();
}

const Simbolo* buscar_simbolo(const string& nome) {
    auto it = tabela_simbolos.find(nome);
    if (it == tabela_simbolos.end()) return nullptr;
    return &it->second;
}

const unordered_map<string, Simbolo>& obter_tabela_simbolos() {
    return tabela_simbolos;
}

void imprimir_tabela_simbolos(ostream& out) {
    vector<Simbolo> lista_ordenada;
    lista_ordenada.reserve(tabela_simbolos.size());
    for (const auto& par : tabela_simbolos) {
        lista_ordenada.push_back(par.second);
    }

    // Ordena primeiro por Categoria (ordem alfabética) e depois por Linha
    sort(lista_ordenada.begin(), lista_ordenada.end(), [](const Simbolo& a, const Simbolo& b) {
        if (a.categoria == b.categoria) {
            return a.linha_declaracao < b.linha_declaracao;
        }
        return a.categoria < b.categoria;
    });

    out << "\n=====================================================" << endl;
    out << "                 TABELA DE SÍMBOLOS                  " << endl;
    out << "=====================================================" << endl;

    if (lista_ordenada.empty()) {
        out << "Nenhum símbolo estrutural foi registrado." << endl;
        return;
    }

    for (const auto& sim : lista_ordenada) {
        out << "Linha: " << sim.linha_declaracao
            << " | Categoria: " << sim.categoria
            << " | Nome: " << sim.nome << endl;
    }
}

void imprimir_tabela_sintese(ostream& out) {
    int cont_pacotes = 0;
    int cont_relacoes_ext = 0;
    int cont_relacoes_int = 0;
    int cont_classes = 0;
    int cont_datatypes = 0;
    int cont_enums = 0;
    int cont_gensets = 0;

    for (const auto& par : tabela_simbolos) {
        const string& cat = par.second.categoria;
        if (cat == "Pacote") cont_pacotes++;
        else if (cat == "Relação Externa") cont_relacoes_ext++;
        else if (cat == "Relação Interna") cont_relacoes_int++;
        else if (cat == "Classe") cont_classes++;
        else if (cat == "Tipo de Dado") cont_datatypes++;
        else if (cat == "Enum") cont_enums++;
        else if (cat == "Genset") cont_gensets++;
    }

    out << "\n=====================================================" << endl;
    out << "                 TABELA DE SÍNTESE                   " << endl;
    out << "=====================================================" << endl;
    out << "Total de Pacotes...........: " << cont_pacotes << endl;
    out << "Total de Relações Externas.: " << cont_relacoes_ext << endl;
    out << "Total de Relações Internas.: " << cont_relacoes_int << endl;
    out << "Total de Classes...........: " << cont_classes << endl;
    out << "Total de DataTypes.........: " << cont_datatypes << endl;
    out << "Total de Enums.............: " << cont_enums << endl;
    out << "Total de Gensets...........: " << cont_gensets << endl;
    out << "=====================================================" << endl;
}