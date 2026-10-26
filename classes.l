%{
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include "parser.tab.hpp"

using namespace std; 

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
classe {segmento}(_{segmento})*
relacao {letra_minuscula}{letras}*(_{letras}+)*
classe_invalida_minuscula [a-z]+({segmento})+
instancia {letras}+(_{letras}+)*{digitos}+
simbolo_especial "{"|"}"|"("|")"|"["|"]"|".."|"<>--"|"--<>"|"*"|"@"|":"|"--"|","|"<>"
id_atributo {letra_minuscula}{alfanumerico}*
invalido [^ \t\n{},()\[\]@:*\.]+

%%
{brancos}   ;

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
"genset" return PALAVRA_RESERVADA;
"disjoint" return PALAVRA_RESERVADA;
"general" return PALAVRA_RESERVADA;
"complete" return PALAVRA_RESERVADA;
"specifics" return PALAVRA_RESERVADA;
"where" return PALAVRA_RESERVADA;
"package" return PALAVRA_RESERVADA;
"import" return PALAVRA_RESERVADA;
"functional-complexes" return PALAVRA_RESERVADA;
"relation" return PALAVRA_RESERVADA;
"specializes" return PALAVRA_RESERVADA;
"datatype" return PALAVRA_RESERVADA;
"enum" return PALAVRA_RESERVADA;
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

{simbolo_especial} return SIMBOLO_ESPECIAL;

{classe_invalida_minuscula} return INVALIDO_CLASSE;

{numero} {yylval.str = strdup(yytext); return NUMERO;}

{invalido} return INVALIDO;

%%

