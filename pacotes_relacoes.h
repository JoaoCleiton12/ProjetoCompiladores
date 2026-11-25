#ifndef PACOTES_RELACOES_H
#define PACOTES_RELACOES_H

#include <ostream>
#include <string>
#include <vector>

struct DeclPacote {
    std::string nome;
    int linha;
    int coluna;
};

struct DeclRelacao {
    std::string nome;
    std::string estereotipo;
    std::string pacote;
    std::string origem;   // classe de origem (vazia em relações internas)
    std::string destino;  // classe de destino
    std::string card_origem;   // cardinalidade da origem (vazia em relações internas)
    std::string card_destino;  // cardinalidade do destino
    bool interna;
    int linha;
    int coluna;
};

// Controle de pacote (Tópico 1)
void definir_pacote_atual(const std::string& nome);
std::string obter_pacote_atual();
void registrar_pacote(const std::string& nome, int linha, int coluna);

// Registro de relações (Tópico 6)
void registrar_relacao_externa(const std::string& estereotipo,
                               const std::string& origem,
                               const std::string& card_origem,
                               const std::string& nome,
                               const std::string& card_destino,
                               const std::string& destino,
                               int linha, int coluna);

void registrar_relacao_interna(const std::string& estereotipo,
                               const std::string& card_origem,
                               const std::string& card_destino,
                               const std::string& destino,
                               int linha, int coluna);

// Verificações semânticas pós-análise e síntese
void verificar_referencias_pacotes_relacoes();
void imprimir_sintese_pacotes_relacoes(std::ostream& out);

const std::vector<DeclPacote>& pacotes_declarados();
const std::vector<DeclRelacao>& relacoes_declaradas();

#endif