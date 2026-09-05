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
classe {segmento}(_{segmento})*
invalido [^ \t\n]+

%%
{brancos}   ;
{classe}    {cout << YYText() << " é um nome de classe válido!\n";}
{invalido}  {cout << YYText() << " é um nome de classe inválido!\n";}
%%

int main() {
    yyFlexLexer lexer;
    lexer.yylex();
}