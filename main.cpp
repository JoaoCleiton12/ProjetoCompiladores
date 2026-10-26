#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <cctype>
#include <FlexLexer.h>
#include <cstdio>
#include "tabela_simbolos.h"

using namespace std;

extern FILE* yyin;
extern int yyparse();

unordered_map<string, Simbolo> tabela_simbolos;

int main(int argc, char* argv[]) {
    string caminho_entrada = "input/teste2.txt";

    if (argc >= 2) {
        caminho_entrada = argv[1];
    }

    FILE* arquivo = fopen(caminho_entrada.c_str(), "r");
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo: " << caminho_entrada << endl;
        return 1;
    }

    yyin = arquivo;

    cout << "=====================================================" << endl;
    cout << "             INICIANDO ANÁLISE SINTÁTICA             " << endl;
    cout << "=====================================================" << endl;

    int status = yyparse();
    fclose(arquivo);

    cout << "\n=====================================================" << endl;
    cout << "            TABELA DE SÍNTESE (SÍMBOLOS)             " << endl;
    cout << "=====================================================" << endl;

    if (tabela_simbolos.empty()) {
        cout << "Nenhum símbolo estrutural foi registrado." << endl;
    } else {
        for (const auto& par : tabela_simbolos) {
            const Simbolo& sim = par.second;
            cout << "Categoria: " << sim.categoria 
                 << " | Nome: " << sim.nome 
                 << " | Linha: " << sim.linha_declaracao << endl;
        }
    }
    cout << "=====================================================" << endl;

    return (status == 0) ? 0 : 1;
}