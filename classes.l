%{
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
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
digitos [0-9]
alfanumerico [a-zA-Z0-9]
segmento {letra_maiuscula}{letras}*
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
    /* Tipos de dados criados pelo usuário */
{novo_tipo_dado} return DADOS_CRIADOS;
    /* Nome das classes */
{classe} return CLASSE;
    /* Símbolos especiais */
{simbolo_especial} return SIMBOLO_ESPECIAL;
    /* Tipos de dados incorretos */
{tipo_dado_incorreto} return INVALIDO;
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
    int total_instancias = 0;
    int total_dados_nativos = 0;
    int total_meta_atributos = 0;

    //tabela hash para controlar os nomes de classe únicos
    unordered_set<string> nomes_classes_unicos;

    unordered_map<int, vector<string>> tokens_agrupados;

    //rececbe o token do lexer e verifica se é diferente de 0, 
    //apenas vai ser 0 quando o arquivo acabar.
    
    while ((token = lexer.yylex()) != 0) {
        
        if (token == PALAVRA_RESERVADA) {
            total_palavras_reservadas++;
            tokens_agrupados[PALAVRA_RESERVADA].push_back(lexer.YYText());
        }
        else if (token == ESTEREOTIPO_CLASSE) {
            total_estereotipos++;
            tokens_agrupados[ESTEREOTIPO_CLASSE].push_back(lexer.YYText());
        }
        else if (token == CLASSE) {

            string nome_classe = lexer.YYText();

            if (nomes_classes_unicos.find(nome_classe) == nomes_classes_unicos.end()) {
                nomes_classes_unicos.insert(nome_classe);
                total_classes++;
                tokens_agrupados[CLASSE].push_back(nome_classe);
            }
        }
        else if (token == SIMBOLO_ESPECIAL) {
            total_simbolos++;
            tokens_agrupados[SIMBOLO_ESPECIAL].push_back(lexer.YYText());
        }
        else if (token == DADOS_CRIADOS) {
            total_dados_criados++;
            tokens_agrupados[DADOS_CRIADOS].push_back(lexer.YYText());
        }
        else if (token == DADOS_NATIVOS) {
            total_dados_nativos++;
            tokens_agrupados[DADOS_NATIVOS].push_back(lexer.YYText());
        }
        else if (token == META_ATRIBUTOS) {
            total_meta_atributos++;
            tokens_agrupados[META_ATRIBUTOS].push_back(lexer.YYText());
        }
        else if (token == INVALIDO) {
            total_invalidos++;
            tokens_agrupados[INVALIDO].push_back(lexer.YYText());
        }
    }

    saida << "=====================================================" << endl;
    saida << "                 VISAO ANALITICA                     " << endl;
    saida << "=====================================================" << endl;

    vector<pair<int, string>> ordem_exibicao = {
        {ESTEREOTIPO_CLASSE, "Estereótipo de Classe"},
        {PALAVRA_RESERVADA,   "Palavra Reservada"},
        {CLASSE,              "Classe"},
        {DADOS_CRIADOS,       "Novo Tipo de Dado"},
        {DADOS_NATIVOS,       "Dado Nativo"},
        {META_ATRIBUTOS,      "Meta-atributo"},
        {SIMBOLO_ESPECIAL,    "Símbolo Especial"},
        {INVALIDO,            "Token Inválido"}
    };

    for(size_t i = 0; i < ordem_exibicao.size(); ++i) {
        int id_token = ordem_exibicao[i].first;
        string rotulo = ordem_exibicao[i].second;

        if(tokens_agrupados.count(id_token)) {
            const vector<string>& tokens = tokens_agrupados[id_token];

            for(size_t j = 0; j < tokens.size(); ++j) {
                saida << rotulo << " : " << tokens[j] << endl;
            }
        }
    }

   

    saida << "=====================================================" << endl;
    saida << "                TABELA DE SINTESE                    " << endl;
    saida << "=====================================================" << endl;
    saida << "CATEGORIA                 | QUANTIDADE               " << endl;
    saida << "Palavras Reservadas       | " << total_palavras_reservadas << endl;
    saida << "Estereótipos de classe    | " << total_estereotipos << endl;
    saida << "Classes                   | " << total_classes << endl;
    saida << "Inválidos                 | " << total_invalidos << endl;
    saida << "Símbolos Especiais        | " << total_simbolos << endl;
    saida << "Dados Nativos             | " << total_dados_nativos << endl;
    saida << "Dados Criados             | " << total_dados_criados << endl;
    saida << "Meta-atributos            | " << total_meta_atributos << endl;
    saida << "=====================================================" << endl;


    entrada.close();
    saida.close();
    return 0;
}