%{
#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;
enum { ESTEREOTIPO_CLASSE = 1, ESTEREOTIPO_RELACAO, PALAVRA_RESERVADA, 
SIMBOLO_ESPECIAL, CLASSE, RELACOES, INSTANCIA, DADOS_NATIVOS, DADOS_CRIADOS, META_ATRIBUTOS, INVALIDO };   
%}

%option noyywrap
%option c++
%option yylineno

delim [ \t\n]
brancos {delim}+
letra_maiuscula [A-Z]
letras [a-zA-Z]
segmento {letra_maiuscula}{letras}*
    /*precisamos melhorar essa regra, pois quando definimos um tipo de dado novo
    como address: Address, o lexer não reconhece address como um tipo de dado válido, 
    e sim como uma classe, então precisamos criar uma regra para reconhecer tipos de dados que são definidos pelo usuário.
    */
novo_tipo_dado {letras}*"DataType"
/* Captura qualquer palavra que termine com "datatype" (independente de maiúsculas/minúsculas), 
   EXCETO a que casa com o DataType correto acima */
tipo_dado_incorreto  [a-zA-Z]*[dD][aA][tT][aA][tT][yY][pP][eE]
classe {segmento}(_{segmento})*
simbolo_especial "{"|"}"|"("|")"|"["|"]"|".."|"<>--"|"--<>"|"*"|"@"|":"
invalido [^ \t\n]+

%%
{brancos}   ;
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
"number" return DADOS_NATIVOS;
"string" return DADOS_NATIVOS;
"boolean" return DADOS_NATIVOS;
"date" return DADOS_NATIVOS;
"time" return DADOS_NATIVOS;
"datetime" return DADOS_NATIVOS;

{novo_tipo_dado} return DADOS_CRIADOS;

{tipo_dado_incorreto} return INVALIDO;

{simbolo_especial} return SIMBOLO_ESPECIAL;
    /* Nome das classes */
{classe} return CLASSE;
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
    int total_invalidos = 0;
    int total_simbolos = 0;
    int total_dados_criados = 0;

    //tabela hash para controlar os nomes de classe únicos
    unordered_set<string> nomes_classes_unicos;

    //rececbe o token do lexer e verifica se é diferente de 0, 
    //apenas vai ser 0 quando o arquivo acabar.
    saida << "=====================================================" << endl;
    saida << "                 VISAO ANALITICA                     " << endl;
    saida << "=====================================================" << endl;

    while ((token = lexer.yylex()) != 0) {
        
        if (token == PALAVRA_RESERVADA) {
            total_palavras_reservadas++;
        }
        if (token == ESTEREOTIPO_CLASSE) {
            total_estereotipos++;
        }
        if (token == CLASSE) {

            string nome_classe = lexer.YYText();
            if (nomes_classes_unicos.find(nome_classe) == nomes_classes_unicos.end()) {
                nomes_classes_unicos.insert(nome_classe);
                total_classes++;
                saida << "Classe: " << nome_classe << endl;
            }
        }
        if (token == INVALIDO) {
            total_invalidos++;
        }
        if (token == SIMBOLO_ESPECIAL) {
            total_simbolos++;
            //saida << "Símbolo Especial: " << lexer.YYText() << endl;
        }
        if (token == DADOS_CRIADOS) {
            total_dados_criados++;
            //saida << "Novo Tipo de Dado: " << lexer.YYText() << endl;
        }
    }

        //rececbe o token do lexer e verifica se é diferente de 0, 
    //apenas vai ser 0 quando o arquivo acabar.
    saida << "=====================================================" << endl;
    saida << "                TABELA DE SINTESE                    " << endl;
    saida << "=====================================================" << endl;
    saida << "CATEGORIA                 | QUANTIDADE               " << endl;
    saida << "Palavras Reservadas       | " << total_palavras_reservadas << endl;
    saida << "Estereótipos de classe    | " << total_estereotipos << endl;
    saida << "Classes                   | " << total_classes << endl;
    saida << "Inválidos                 | " << total_invalidos << endl;
    saida << "Símbolos Especiais        | " << total_simbolos << endl;


    entrada.close();
    saida.close();
    return 0;
}