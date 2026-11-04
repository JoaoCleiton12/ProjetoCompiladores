#ifndef CLASSES_DATATYPES_H
#define CLASSES_DATATYPES_H

#include <ostream>
#include <string>
#include <vector>

struct AtributoOntologia {
    std::string nome;
    std::string tipo;
    int linha;
    std::string meta_atributo;
};

struct DeclaracaoClasse {
    std::string nome;
    std::string estereotipo;
    int linha;
    int coluna;
    std::vector<std::string> especializacoes;
    std::vector<AtributoOntologia> atributos;
    int relacoes_internas;
    bool com_erro;
};

struct DeclaracaoDataType {
    std::string nome;
    int linha;
    int coluna;
    std::vector<AtributoOntologia> atributos;
    bool com_erro;
};

void classe_iniciar(const char* estereotipo, const char* nome, int linha, int coluna);
void classe_adicionar_especializacao(const char* nome, int linha, int coluna);
void classe_adicionar_atributo(const char* nome, const char* tipo, const char* meta,
                               int linha, int coluna);
void classe_adicionar_relacao_interna(int linha);
void classe_finalizar(bool com_erro, int linha_fim);

void datatype_iniciar(const char* nome, int linha, int coluna);
void datatype_adicionar_atributo(const char* nome, const char* tipo, const char* meta,
                                 int linha, int coluna);
void datatype_finalizar(bool com_erro, int linha_fim);

void verificar_referencias_classes_datatypes();
void imprimir_sintese_classes_datatypes(std::ostream& out);

const std::vector<DeclaracaoClasse>& classes_declaradas();
const std::vector<DeclaracaoDataType>& datatypes_declarados();

#endif
