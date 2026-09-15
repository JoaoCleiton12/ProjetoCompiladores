%{
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

enum { ESTEREOTIPO_CLASSE = 1, ESTEREOTIPO_RELACAO, PALAVRA_RESERVADA, 
SIMBOLO_ESPECIAL, CLASSE, RELACOES, INSTANCIA, DADOS_NATIVOS, DADOS_CRIADOS, META_ATRIBUTOS, INVALIDO,
INVALIDO_CLASSE, ID_ATRIBUTO, ERRO_DATATYPE, NUMERO};  

struct ErroLexico {
    int linha;
    string lexema;
    string descricao;
};
%}

%option noyywrap
%option c++
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
novo_tipo_dado {letras}*"DataType"
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
"material" return ESTEREOTIPO_RELACAO;  
"derivation" return ESTEREOTIPO_RELACAO;
"comparative" return ESTEREOTIPO_RELACAO;
"mediation" return ESTEREOTIPO_RELACAO;
"characterization" return ESTEREOTIPO_RELACAO;
"subCollectionOf" return ESTEREOTIPO_RELACAO;
"subQualityOf" return ESTEREOTIPO_RELACAO;
"subQualityof" return ESTEREOTIPO_RELACAO;
"instantiation" return ESTEREOTIPO_RELACAO;
"externalDependence" return ESTEREOTIPO_RELACAO;
"componentOf" return ESTEREOTIPO_RELACAO;
"componentof" return ESTEREOTIPO_RELACAO;
"memberOf" return ESTEREOTIPO_RELACAO;
"memberof" return ESTEREOTIPO_RELACAO;
"termination" return ESTEREOTIPO_RELACAO;
"participational" return ESTEREOTIPO_RELACAO;
"participation" return ESTEREOTIPO_RELACAO;
"historicalDependence" return ESTEREOTIPO_RELACAO;
"creation" return ESTEREOTIPO_RELACAO;
"manifestation" return ESTEREOTIPO_RELACAO;
"bringsAbout" return ESTEREOTIPO_RELACAO;
"triggers" return ESTEREOTIPO_RELACAO;
"composition" return ESTEREOTIPO_RELACAO;
"aggregation" return ESTEREOTIPO_RELACAO;
"inherence" return ESTEREOTIPO_RELACAO;
"value" return ESTEREOTIPO_RELACAO;
"formal" return ESTEREOTIPO_RELACAO;
"constitution" return ESTEREOTIPO_RELACAO;
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

{novo_tipo_dado} return DADOS_CRIADOS;

{id_atributo}/[ \t]*":" return ID_ATRIBUTO;

{relacao} return RELACOES;

{instancia} return INSTANCIA;

{tipo_dado_incorreto} return ERRO_DATATYPE;

{classe} return CLASSE;
    
{simbolo_especial} return SIMBOLO_ESPECIAL;

{classe_invalida_minuscula} return INVALIDO_CLASSE;

{numero} return NUMERO;
    
{invalido}  return INVALIDO;

%%


int main() {

    ifstream entrada("input/teste2.txt");
    ofstream saida("output/saida.txt");

    if (!entrada.is_open() || !saida.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << "output/saida.txt" << endl;
        return 1;
    }

    //Lê diretamente do arquivo de entrada
    yyFlexLexer lexer(&entrada, &saida);
    
    int token;

    int total_estereotipos_classe = 0;
    int total_estereotipos_relacao = 0;
    int total_palavras_reservadas = 0;
    int total_simbolos = 0;
    int total_classes = 0;
    int total_relacoes = 0;
    int total_instancias = 0;
    int total_dados_nativos = 0;
    int total_dados_criados = 0;
    int total_meta_atributos = 0;
    int total_numero = 0;
    int total_invalidos_classe = 0;
    int total_id_atributos = 0;
    int total_invalidos = 0;

    //tabela hash para controlar os nomes de classe únicos
    unordered_set<string> nomes_classes_unicos;


    /* Agrupa os tokens encontrados por categoria (chave = código do token no enum).
       Para cada categoria, guarda uma lista de pares (lexema, número da linha),
       usada depois para imprimir o relatório organizado por tipo de token.
    */
    unordered_map<int, vector<pair<string, int>>> tokens_agrupados;

    vector<ErroLexico> lista_erros;

    //rececbe o token do lexer e verifica se é diferente de 0, 
    //apenas vai ser 0 quando o arquivo acabar.
    while ((token = lexer.yylex()) != 0) {
        
        string lexema = lexer.YYText();
        int linha = lexer.lineno();

        if (token == ESTEREOTIPO_CLASSE) {
            total_estereotipos_classe++;
            tokens_agrupados[ESTEREOTIPO_CLASSE].push_back({lexema, linha});
        }
        else if (token == ESTEREOTIPO_RELACAO) {
            total_estereotipos_relacao++;
            tokens_agrupados[ESTEREOTIPO_RELACAO].push_back({lexema, linha});
        }
        else if (token == PALAVRA_RESERVADA) {
            total_palavras_reservadas++;
            tokens_agrupados[PALAVRA_RESERVADA].push_back({lexema, linha});
        }
        else if (token == SIMBOLO_ESPECIAL) {
            total_simbolos++;
            tokens_agrupados[SIMBOLO_ESPECIAL].push_back({lexema, linha});;
        }
        else if (token == CLASSE) {

            string nome_classe = lexer.YYText();

            if (nomes_classes_unicos.find(lexema) == nomes_classes_unicos.end()) {
                nomes_classes_unicos.insert(lexema);
                total_classes++;
            }
            tokens_agrupados[CLASSE].push_back({lexema, linha});
        }
        else if (token == RELACOES) {
            total_relacoes++;
            tokens_agrupados[RELACOES].push_back({lexema, linha});
        }
        else if (token == INSTANCIA) {
            total_instancias++;
            tokens_agrupados[INSTANCIA].push_back({lexema, linha});
        }
        else if (token == DADOS_CRIADOS) {
            total_dados_criados++;
            tokens_agrupados[DADOS_CRIADOS].push_back({lexema, linha});
        }
        else if (token == DADOS_NATIVOS) {
            total_dados_nativos++;
            tokens_agrupados[DADOS_NATIVOS].push_back({lexema, linha});
        }
        else if (token == META_ATRIBUTOS) {
            total_meta_atributos++;
            tokens_agrupados[META_ATRIBUTOS].push_back({lexema, linha});
        }
        else if (token == ID_ATRIBUTO) {
            total_id_atributos++;
            tokens_agrupados[ID_ATRIBUTO].push_back({lexema, linha});
        }
        else if (token == ERRO_DATATYPE) {
            total_invalidos++;
            tokens_agrupados[INVALIDO].push_back({lexema, linha});

            string base = lexema;
            size_t pos = lexema.size() >= 8 ? lexema.size() - 8 : string::npos;
            string sugerido = (pos != string::npos ? lexema.substr(0, pos) : lexema) + "DataType";

            lista_erros.push_back({
                linha, lexema,
                "Tipo de dado criado com sufixo inválido: a especificação exige exatamente 'DataType' ao final."
            });
        }
        else if(token == NUMERO) {
            total_numero++;
            tokens_agrupados[NUMERO].push_back({lexema, linha});
        }  
        else if (token == INVALIDO_CLASSE) {
            total_invalidos++;
            tokens_agrupados[INVALIDO].push_back({lexema, linha});

            string sugestao = lexema;
            if (!sugestao.empty()) sugestao[0] = toupper(sugestao[0]);

            lista_erros.push_back({
                linha, lexema,
                "Nome de classe inválido (deve começar com letra maiúscula). Sugestão: renomear para '" + sugestao + "'."
            });
        }
        else if (token == INVALIDO) {
            total_invalidos++;
            tokens_agrupados[INVALIDO].push_back({lexema, linha});

            lista_erros.push_back({
                linha, lexema,
                "Token não reconhecido pela gramática da linguagem Tonto. Verifique símbolos não suportados ou identificadores mal formados."
            });
        }
    }

    saida << "=====================================================" << endl;
    saida << "                 VISAO ANALITICA                     " << endl;
    saida << "=====================================================" << endl;

    vector<pair<int, string>> ordem_exibicao = {
        {ESTEREOTIPO_CLASSE, "Estereótipo de Classe"},
        {ESTEREOTIPO_RELACAO, "Estereótipo de Relação"},
        {PALAVRA_RESERVADA,   "Palavra Reservada"},
        {SIMBOLO_ESPECIAL,    "Símbolo Especial"},
        {CLASSE,              "Classe"},
        {RELACOES,            "Nome de Relação"},
        {INSTANCIA,           "Instancias"},
        {DADOS_NATIVOS,       "Dado Nativo"},
        {DADOS_CRIADOS,       "Novo Tipo de Dado"},
        {ID_ATRIBUTO,         "Identificador de Atributo"},
        {META_ATRIBUTOS,      "Meta-atributo"},
        {NUMERO,              "Numeros"},
        {INVALIDO,            "Token Inválido"}
    };

    // Itera sobre a ordem de exibição e imprime os tokens agrupados
    for(size_t i = 0; i < ordem_exibicao.size(); ++i) {
        int id_token = ordem_exibicao[i].first;
        string rotulo = ordem_exibicao[i].second;

        // verifica se a chave existe no mapa
        if(tokens_agrupados.count(id_token)) {
            //pega a referencia da lista de string daquela categoria
            const vector<pair<string, int>>& tokens = tokens_agrupados[id_token];

            //percorre a lista de token de cada categoria e imprime no arquivo de saída
            for(size_t j = 0; j < tokens.size(); ++j) {
                string lexema = tokens[j].first;
                int num_linha = tokens[j].second;
                saida << rotulo << ": " << lexema << " [Linha: " << num_linha << "]" << endl;
            }
            saida << endl;
        }
    }
    saida << "=====================================================" << endl;
    saida << endl;
    saida << endl;

    saida << "=====================================================" << endl;
    saida << "                TABELA DE SINTESE                    " << endl;
    saida << "=====================================================" << endl;
    saida << "CATEGORIA                 | QUANTIDADE               " << endl;
    
    saida << "Estereótipos de classe    | " << total_estereotipos_classe << endl;
    saida << "Estereótipos de relação   | " << total_estereotipos_relacao << endl;
    saida << "Palavras Reservadas       | " << total_palavras_reservadas << endl;
    saida << "Símbolos Especiais        | " << total_simbolos << endl;
    saida << "Classes                   | " << total_classes << endl;
    saida << "Relações                  | " << total_relacoes << endl;
    saida << "Instancias                | " << total_instancias << endl;
    saida << "Dados Nativos             | " << total_dados_nativos << endl;
    saida << "Dados Criados             | " << total_dados_criados << endl;
    saida << "Identificador de atributo | " << total_id_atributos << endl;
    saida << "Meta-atributos            | " << total_meta_atributos << endl;
    saida << "Números                   | " << total_numero << endl;
    saida << "Inválidos                 | " << total_invalidos << endl;
    saida << "=====================================================" << endl;
    saida << endl;
    saida << endl;

    saida << "=====================================================" << endl;
    saida << "              TRATAMENTO DE ERROS                    " << endl;
    saida << "=====================================================" << endl;
    if(lista_erros.empty()) {
        saida << "Nenhum erro léxico encontrado." << endl;
    } else {
        for(size_t i = 0; i < lista_erros.size(); ++i) {
            saida << "Linha: " << lista_erros[i].linha << "] Erro no token '"
                  << lista_erros[i].lexema << "'" << endl;
            saida << "  -> Descrição: " << lista_erros[i].descricao << endl;
            saida << "-----------------------------------------------------" << endl;
        }
    }
    saida << "=====================================================" << endl;

    entrada.close();
    saida.close();
    return 0;
}