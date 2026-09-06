%{
#include <iostream>
using namespace std;
enum { CLASSE = 1 };   
%}

%option noyywrap
%option c++

delim [ \t\n]
brancos {delim}+
letra_maiuscula [A-Z]
letras [a-zA-Z]
segmento {letra_maiuscula}{letras}*

    /* Regra para identificação de nomes de classes */
classe {segmento}(_{segmento})*
invalido [^ \t\n]+

estereotipoOne "event"|"situation"|"process"|"category"|"mixin"|"phaseMixin"
estereotipoTwo "roleMixin"|"historicalRoleMixin"|"kind"|"collective"|"quantity"
estereotipoThree "quality"|"mode"|"intrisicMode"|"extrinsicMode"|"subKind"
estereotipoFour "phase"|"role"|"historicalRole"
estereotipoFinal {estereotipoOne}|{estereotipoTwo}|{estereotipoThree}|{estereotipoFour}


%%
{brancos}   ;

    /* palavras reservadas */
"genset" {cout << YYText() << " é uma palavra reservada!\n";}
"disjoint" {cout << YYText() << " é uma palavra reservada!\n";}
"general" {cout << YYText() << " é uma palavra reservada!\n";}
"complete" {cout << YYText() << " é uma palavra reservada!\n";}
"specifics" {cout << YYText() << " é uma palavra reservada!\n";}
"where" {cout << YYText() << " é uma palavra reservada!\n";}
"package" {cout << YYText() << " é uma palavra reservada!\n";}
"import" {cout << YYText() << " é uma palavra reservada!\n";}
"functional-complexes" {cout << YYText() << " é uma palavra reservada!\n";}

    /* Nome das classes */
{classe}    {cout << YYText() << " é um nome de classe válido!\n";}

{estereotipoFinal}  {cout << YYText() << " é um estereótipo válido!\n";}

    /*Precisa definir uma saída */
{invalido}  {cout << YYText() << " é um nome de classe inválido!\n";}

%%


int main() {
    yyFlexLexer lexer;
    lexer.yylex();
}