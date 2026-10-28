%{
#include <iostream>
#include <string>
#include "tabela_simbolos.h"

using namespace std;

int yylex();
extern int yylineno;
void yyerror(const char *s);
%}

%union {
    char* str;
    int num;
}

%token PACKAGE RELATION
%token <str> ESTEREOTIPO_RELACAO CLASSE ID_ATRIBUTO DADOS_CRIADOS RELACOES INSTANCIA NUMERO
%token ESTEREOTIPO_CLASSE PALAVRA_RESERVADA DADOS_NATIVOS META_ATRIBUTOS
%token ERRO_DATATYPE SIMBOLO_ESPECIAL INVALIDO_CLASSE INVALIDO

%%

programa:
    declaracoes_pacotes corpo_programa
    | corpo_programa
    ;

declaracoes_pacotes:
    declaracoes_pacotes declaracao_pacote
    | declaracao_pacote
    ;

declaracao_pacote:
    PACKAGE CLASSE { inserir_simbolo($2, "Pacote", yylineno); }
    | PACKAGE ID_ATRIBUTO { inserir_simbolo($2, "Pacote", yylineno); }
    ;

corpo_programa:
    corpo_programa elemento
    | /* vazio */
    ;

elemento:
    declaracao_relacao_externa
    | declaracao_relacao_interna
    | token_invalido // "Aspirador de pó" para ignorar o código dos colegas com segurança
    | error { yyerrok; } // Recuperação de erro limpa (sem yyclearin destrutivo)
    ;

// Esta regra agora cobre todos os formatos numéricos, como [1], [*], [1..*] e [0..5]
cardinalidade:
    SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL
    | SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL
    | SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL
    | SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL
    | SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL
    ;

// Regra atualizada para capturar o nome da relação no meio (ex: -- tem_Massa --)
declaracao_relacao_externa:
    SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO RELATION CLASSE cardinalidade SIMBOLO_ESPECIAL RELACOES SIMBOLO_ESPECIAL cardinalidade CLASSE {
        inserir_simbolo($7, "Relação Externa", yylineno);
    }
    ;

declaracao_relacao_interna:
    SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO cardinalidade SIMBOLO_ESPECIAL cardinalidade CLASSE {
        string identificador = string("Interna_") + $2 + "_para_" + $6 + "_L" + to_string(yylineno);
        inserir_simbolo(identificador, "Relação Interna", yylineno);
    }
    ;

// Mapeamento de tudo que não nos interessa para ser ignorado silenciosamente
token_invalido:
    PACKAGE | RELATION | CLASSE | ID_ATRIBUTO | DADOS_CRIADOS | RELACOES
    | INSTANCIA | NUMERO | ESTEREOTIPO_CLASSE | PALAVRA_RESERVADA | DADOS_NATIVOS
    | META_ATRIBUTOS | ERRO_DATATYPE | SIMBOLO_ESPECIAL | INVALIDO_CLASSE
    | INVALIDO | ESTEREOTIPO_RELACAO
    ;

%%

void yyerror(const char *s) {
    // Silenciado para não poluir o terminal
}