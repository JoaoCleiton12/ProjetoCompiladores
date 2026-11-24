#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "tabela_simbolos.h"
#include "pacotes_relacoes.h"
#include "relatorio_erros.h"
#include "enum_genset.h"
#include "classes_datatypes.h"

using namespace std;

extern FILE* yyin;
extern int yyparse();

int main(int argc, char* argv[]) {
    string caminho_entrada = "input/teste1.txt";
    string caminho_saida = "output/saida.txt";

    if (argc >= 2) {
        caminho_entrada = argv[1];
    }

    FILE* arquivo = fopen(caminho_entrada.c_str(), "r");
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo: " << caminho_entrada << endl;
        return 1;
    }

    ofstream arquivo_saida(caminho_saida);
    if (!arquivo_saida.is_open()) {
        cerr << "Erro ao criar o arquivo de saída: " << caminho_saida << endl;
        fclose(arquivo);
        return 1;
    }

    yyin = arquivo;

    arquivo_saida << "=====================================================" << endl;
    arquivo_saida << "             INICIANDO ANÁLISE SINTÁTICA             " << endl;
    arquivo_saida << "=====================================================" << endl;

    int status = yyparse();
    fclose(arquivo);

    // Verificações semânticas pós-análise de cada módulo
    verificar_referencias_pacotes_relacoes();
    verificar_referencias_enum_genset();
    verificar_referencias_classes_datatypes();

    // Impressão centralizada da Tabela de Símbolos e Síntese Geral
    imprimir_tabela_simbolos(arquivo_saida);
    imprimir_tabela_sintese(arquivo_saida);

    // Sínteses específicas de cada módulo e relatório de erros
    imprimir_sintese_pacotes_relacoes(arquivo_saida);
    imprimir_sintese_enum_genset(arquivo_saida);
    imprimir_sintese_classes_datatypes(arquivo_saida);
    imprimir_relatorio_erros(arquivo_saida);

    arquivo_saida.close();

    cout << "Analise concluída! Resultados salvos e ordenados em: " << caminho_saida << endl;
    cout << "Relatório de erros: " << total_erros() << " erro(s), "
         << total_avisos() << " aviso(s)." << endl;

    return (status == 0) ? 0 : 1;
}