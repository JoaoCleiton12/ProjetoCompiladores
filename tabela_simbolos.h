#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H

#include <ostream>
#include <string>
#include <unordered_map>

struct Simbolo {
    std::string nome;
    std::string categoria;
    int linha_declaracao;
};

// Inserção e consultas encapsuladas
bool inserir_simbolo(const std::string& nome, const std::string& categoria, int linha, int coluna = 0);
bool simbolo_existe(const std::string& nome);
const Simbolo* buscar_simbolo(const std::string& nome);
const std::unordered_map<std::string, Simbolo>& obter_tabela_simbolos();

// Impressão da Tabela de Símbolos e da Tabela de Síntese Geral
void imprimir_tabela_simbolos(std::ostream& out);
void imprimir_tabela_sintese(std::ostream& out);

#endif