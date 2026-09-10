%{
#include <iostream>
#include <fstream>
using namespace std;
enum { CLASSE = 1, ESTEREOTIPO, INVALIDO, PALAVRA_RESERVADA };   
%}

%option noyywrap
%option c++
%option yylineno

delim [ \t\n]
brancos {delim}+
letra_maiuscula [A-Z]
letras [a-zA-Z]
segmento {letra_maiuscula}{letras}*
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
"genset" return PALAVRA_RESERVADA;
"disjoint" return PALAVRA_RESERVADA;
"general" return PALAVRA_RESERVADA;
"complete" return PALAVRA_RESERVADA;
"specifics" return PALAVRA_RESERVADA;
"where" return PALAVRA_RESERVADA;
"package" return PALAVRA_RESERVADA;
"import" return PALAVRA_RESERVADA;
"functional-complexes" return PALAVRA_RESERVADA;

    /* Nome das classes */
{classe} return CLASSE;

    /* Estereótipos */

{estereotipoFinal}  return ESTEREOTIPO;

    /*Precisa definir uma saída */
{invalido}  return INVALIDO;

%%



int main() {

    ifstream entrada("input/teste1.txt");
    ofstream saida("output/saida.txt");

    if (!entrada.is_open() || !saida.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << "output/saida.txt" << endl;
        return 1;
    }


    //Lê diretamente do arquivo de entrada
    yyFlexLexer lexer(&entrada, &saida);
    

    int token;
    int total_palavras_reservadas = 0;
    int total_estereotipos = 0;
    int total_classes = 0;

    //rececbe o token do lexer e verifica se é diferente de 0, 
    //apenas vai ser 0 quando o arquivo acabar.
    saida << "=====================================================" << endl;
    saida << "                TABELA DE SINTESE                    " << endl;
    saida << "=====================================================" << endl;

    while ((token = lexer.yylex()) != 0) {
        
        if (token == PALAVRA_RESERVADA) {
            total_palavras_reservadas++;
        }
        if (token == ESTEREOTIPO) {
            total_estereotipos++;
        }
        if (token == CLASSE) {
            total_classes++;
        }
    }
    saida << "CATEGORIA                 | QUANTIDADE               " << endl;
    saida << "Palavras Reservadas       | " << total_palavras_reservadas << endl;
    saida << "Estereótipos              | " << total_estereotipos << endl;
    saida << "Classes                   | " << total_classes << endl;

    entrada.close();
    saida.close();
    return 0;
}