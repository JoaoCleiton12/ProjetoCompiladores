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
    | error { yyclearin; yyerrok; }
    ;

cardinalidade:
    SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL
    | SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL
    ;

declaracao_relacao_externa:
    SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO RELATION CLASSE cardinalidade cardinalidade CLASSE {
        inserir_simbolo($4, "Relação Externa", yylineno);
    }
    ;

declaracao_relacao_interna:
    SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO cardinalidade SIMBOLO_ESPECIAL cardinalidade CLASSE {
        string identificador = string("Interna_") + $2 + "_para_" + $6;
        inserir_simbolo(identificador, "Relação Interna", yylineno);
    }
    ;

%%

void yyerror(const char *s) {
    //cerr << "[Erro Sintático] Linha " << yylineno << ": " << s << endl;
}