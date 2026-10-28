#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

struct Simbolo {
    string nome;
    string categoria;
    int linha_declaracao;
};

extern unordered_map<string, Simbolo> tabela_simbolos;
extern ofstream arquivo_saida; // Declara que o arquivo de saída existe no main.cpp

inline void inserir_simbolo(string nome, string categoria, int linha) {
    if (tabela_simbolos.find(nome) == tabela_simbolos.end()) {
        tabela_simbolos[nome] = {nome, categoria, linha};
    } else {
        // Agora os avisos também vão para o arquivo de texto em vez do terminal
        arquivo_saida << "[Aviso Semântico] Linha " << linha 
                      << ": O símbolo '" << nome << "' já foi declarado!" << endl;
    }
}

#endif