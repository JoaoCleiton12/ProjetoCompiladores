%{
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstring>
#include "parser.tab.hpp"

using namespace std; 

/* [Tópicos 4/5] Rastreamento de linha e coluna de cada token (yylloc),
   usado pelo parser para indicar a posição exata dos erros. */
static int linha_atual = 1;
static int coluna_atual = 1;
#define YY_USER_ACTION                                              \
    yylloc.first_line = linha_atual;                                \
    yylloc.first_column = coluna_atual;                             \
    for (int i_ = 0; i_ < (int)yyleng; i_++) {                      \
        if (yytext[i_] == '\n') { linha_atual++; coluna_atual = 1; } \
        else if ((yytext[i_] & 0xC0) != 0x80) coluna_atual++;       \
    }                                                               \
    yylloc.last_line = linha_atual;                                 \
    yylloc.last_column = coluna_atual - 1;

%}

%option noyywrap
%option yylineno

delim [ \t\n]
brancos {delim}+
letra_maiuscula [A-Z]
letra_minuscula [a-z]
letras [a-zA-Z]
digitos [0-9]
numero {digitos}+
alfanumerico [a-zA-Z0-9]
segmento {letra_maiuscula}{letras}*
novo_tipo_dado {letras}+"DataType"
tipo_dado_incorreto  [a-zA-Z]*[dD][aA][tT][aA][tT][yY][pP][eE]
classe {letra_maiuscula}{letras}*(_{letras}+)*
relacao {letra_minuscula}{letras}*(_{letras}+)*
classe_invalida_minuscula [a-z]+({segmento})+
instancia {letras}+(_{letras}+)*{digitos}+
simbolo_especial "{"|"}"|"("|")"|"["|"]"|".."|"<>--"|"--<>"|"*"|"@"|":"|"--"|","|"<>"
id_atributo {letra_minuscula}{alfanumerico}*
invalido [^ \t\n{},()\[\]@:*\.]+

%%
{brancos}   ;

    /* [Tópicos 4/5] comentários de linha e de bloco são ignorados */
"//"[^\n]*                              ;
"/*"([^*]|"*"+[^*/])*"*"+"/"            ;

    /* Regras analise sintatica */
"package" return PACKAGE;
"relation" return RELATION;
    /* estereotipos de classe*/
"event" return ESTEREOTIPO_CLASSE;
"situation" return ESTEREOTIPO_CLASSE;
"process" return ESTEREOTIPO_CLASSE;
"category" return ESTEREOTIPO_CLASSE;
"mixin" return ESTEREOTIPO_CLASSE;
"phaseMixin" return ESTEREOTIPO_CLASSE;
"roleMixin" return ESTEREOTIPO_CLASSE;
"historicalRoleMixin" return ESTEREOTIPO_CLASSE;
"kind" return ESTEREOTIPO_CLASSE;
"collective" return ESTEREOTIPO_CLASSE;
"quantity" return ESTEREOTIPO_CLASSE;
"quality" return ESTEREOTIPO_CLASSE;
"mode" return ESTEREOTIPO_CLASSE;
"intrisicMode" return ESTEREOTIPO_CLASSE;
"extrinsicMode" return ESTEREOTIPO_CLASSE;
"subKind" return ESTEREOTIPO_CLASSE;
"phase" return ESTEREOTIPO_CLASSE;
"role" return ESTEREOTIPO_CLASSE;
"historicalRole" return ESTEREOTIPO_CLASSE;
"relator" return ESTEREOTIPO_CLASSE;

    /* esteriotipos de relacoes */
"material" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"derivation" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"comparative" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"mediation" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"characterization" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"subCollectionOf" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"subQualityOf" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"subQualityof" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"instantiation" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"externalDependence" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"componentOf" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"componentof" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"memberOf" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"memberof" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"termination" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"participational" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"participation" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"historicalDependence" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"creation" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"manifestation" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"bringsAbout" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"triggers" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"composition" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"aggregation" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"inherence" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"value" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"formal" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
"constitution" {yylval.str = strdup(yytext); return ESTEREOTIPO_RELACAO;}
    /* palavras reservadas */
    /* [Tópicos 4/5] palavras reservadas de enum e genset com token próprio */
"enum" return ENUM;
"genset" return GENSET;
"disjoint" return DISJOINT;
"overlapping" return OVERLAPPING;
"complete" return COMPLETE;
"incomplete" return INCOMPLETE;
"general" return GENERAL;
"specifics" return SPECIFICS;
"categorizer" return CATEGORIZER;
"where" return WHERE;
"specializes" return SPECIALIZES;
"package" return PALAVRA_RESERVADA;
"import" return PALAVRA_RESERVADA;
"functional-complexes" return PALAVRA_RESERVADA;
"relation" return PALAVRA_RESERVADA;
"datatype" return PALAVRA_RESERVADA;
    /* dados nativos */
"number" return DADOS_NATIVOS;
"string" return DADOS_NATIVOS;
"boolean" return DADOS_NATIVOS;
"date" return DADOS_NATIVOS;
"time" return DADOS_NATIVOS;
"datetime" return DADOS_NATIVOS;
    /* Meta-atributos */
"ordered" return META_ATRIBUTOS;
"const" return META_ATRIBUTOS;
"derived" return META_ATRIBUTOS;
"subsets" return META_ATRIBUTOS;
"redefines" return META_ATRIBUTOS;

    /* caputa de texto */
{novo_tipo_dado} {yylval.str = strdup(yytext); return DADOS_CRIADOS;}

{id_atributo}/[ \t]*":" {yylval.str = strdup(yytext); return ID_ATRIBUTO;}

{relacao} {yylval.str = strdup(yytext); return RELACOES;}

{instancia} {yylval.str = strdup(yytext); return INSTANCIA;}

{tipo_dado_incorreto} return ERRO_DATATYPE;

{classe} {yylval.str = strdup(yytext); return CLASSE;}

    /* [Tópicos 4/5] delimitadores usados em enum/genset com token próprio */
"{" return ABRE_CHAVE;
"}" return FECHA_CHAVE;
"," return VIRGULA;

{simbolo_especial} return SIMBOLO_ESPECIAL;

{classe_invalida_minuscula} return INVALIDO_CLASSE;

{numero} {yylval.str = strdup(yytext); return NUMERO;}

{invalido} {yylval.str = strdup(yytext); return INVALIDO;}

    /* [Tópicos 4/5] qualquer caractere restante (ex.: '.' isolado) vira token inválido,
       em vez de ser ecoado silenciosamente pelo Flex */
. {yylval.str = strdup(yytext); return INVALIDO;}

%%

