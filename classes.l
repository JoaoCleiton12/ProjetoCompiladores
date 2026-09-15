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

