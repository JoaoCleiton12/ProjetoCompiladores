#ifndef RELATORIO_ERROS_H
#define RELATORIO_ERROS_H

/*
 * Relatório de erros da ontologia (infraestrutura compartilhada).
 *
 * Qualquer regra da gramática (parser.y) ou verificação semântica pode
 * registrar um problema aqui. Ao fim da análise, main.cpp imprime o relatório
 * ordenado por linha, com a sugestão de tratamento de cada problema.
 *
 *   registrar_erro(linha, coluna, "Enum", "mensagem", "sugestão");
 *   registrar_aviso(linha, coluna, "Genset", "mensagem", "sugestão");
 */

#include <ostream>
#include <string>
#include <vector>

enum class Severidade { ERRO, AVISO };

struct Ocorrencia {
    Severidade severidade;
    int linha;
    int coluna;
    std::string construto;   // ex.: "Enum", "Genset", "Sintaxe"
    std::string mensagem;
    std::string sugestao;
};

void registrar_erro(int linha, int coluna, const std::string& construto,
                    const std::string& mensagem, const std::string& sugestao);
void registrar_aviso(int linha, int coluna, const std::string& construto,
                     const std::string& mensagem, const std::string& sugestao);

int total_erros();
int total_avisos();
const std::vector<Ocorrencia>& ocorrencias();

void imprimir_relatorio_erros(std::ostream& out);

#endif
