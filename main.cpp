#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm> // Biblioteca necessária para o sort()
#include "tabela_simbolos.h"

using namespace std;

extern FILE* yyin;
extern int yyparse();

unordered_map<string, Simbolo> tabela_simbolos;
ofstream arquivo_saida; 

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

    arquivo_saida.open(caminho_saida);
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

    // --- ORDENAÇÃO DOS DADOS ---
    // Copia os dados da Hash Table para um Vector para poder ordenar
    vector<Simbolo> lista_ordenada;
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

    // Variáveis para a Tabela de Síntese
    int cont_pacotes = 0;
    int cont_relacoes_ext = 0;
    int cont_relacoes_int = 0;

    // 1. IMPRESSÃO DA TABELA DE SÍMBOLOS
    arquivo_saida << "\n=====================================================" << endl;
    arquivo_saida << "                 TABELA DE SÍMBOLOS                  " << endl;
    arquivo_saida << "=====================================================" << endl;

    if (lista_ordenada.empty()) {
        arquivo_saida << "Nenhum símbolo estrutural foi registrado." << endl;
    } else {
        // Agora iteramos sobre a lista ordenada em vez da Hash Table embaralhada
        for (const auto& sim : lista_ordenada) {
            
            arquivo_saida << "Linha: " << sim.linha_declaracao 
                          << " | Categoria: " << sim.categoria 
                          << " | Nome: " << sim.nome << endl;

            // Incrementa os contadores
            if (sim.categoria == "Pacote") cont_pacotes++;
            else if (sim.categoria == "Relação Externa") cont_relacoes_ext++;
            else if (sim.categoria == "Relação Interna") cont_relacoes_int++;
        }
    }

    // 2. IMPRESSÃO DA TABELA DE SÍNTESE
    arquivo_saida << "\n=====================================================" << endl;
    arquivo_saida << "                 TABELA DE SÍNTESE                   " << endl;
    arquivo_saida << "=====================================================" << endl;
    arquivo_saida << "Total de Pacotes...........: " << cont_pacotes << endl;
    arquivo_saida << "Total de Relações Externas.: " << cont_relacoes_ext << endl;
    arquivo_saida << "Total de Relações Internas.: " << cont_relacoes_int << endl;
    arquivo_saida << "=====================================================" << endl;

    arquivo_saida.close();
    
    cout << "Analise concluída! Resultados salvos e ordenados em: " << caminho_saida << endl;
    
    return (status == 0) ? 0 : 1;
}