%{
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include "tabela_simbolos.h"
#include "relatorio_erros.h"   /* [Tópicos 4/5] relatório de erros com sugestões */
#include "enum_genset.h"       /* [Tópicos 4/5] enum e genset                    */

using namespace std;

int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(const char *s);

/* [Tópicos 4/5] Marca que o último item de uma lista foi um símbolo usado
   indevidamente como separador (ex.: ';'), para não acusar também "falta vírgula". */
static bool separador_invalido_pendente = false;
static bool consumir_separador_invalido() {
    bool havia = separador_invalido_pendente;
    separador_invalido_pendente = false;
    return havia;
}
static bool eh_simbolo_solto(const char* s) {
    for (const char* p = s; *p; p++)
        if (isalnum((unsigned char)*p)) return false;
    return true;
}
%}

/* [Tópicos 4/5] Posição (linha/coluna) de cada símbolo: @1, @2, ... */
%locations
/* [Tópicos 4/5] Mensagens de erro sintático próprias (yyreport_syntax_error),
   com a lista exata de tokens esperados (LAC). Reduções padrão apenas em estados
   consistentes, para que a recuperação "{ error" pare no '}' ou no início da
   próxima declaração. */
%define parse.error custom
%define parse.lac full
%define lr.default-reduction consistent

%union {
    char* str;
    int num;
}

%token PACKAGE RELATION
%token <str> ESTEREOTIPO_RELACAO CLASSE ID_ATRIBUTO DADOS_CRIADOS RELACOES INSTANCIA NUMERO
%token ESTEREOTIPO_CLASSE PALAVRA_RESERVADA DADOS_NATIVOS META_ATRIBUTOS
%token ERRO_DATATYPE SIMBOLO_ESPECIAL INVALIDO_CLASSE
%token <str> INVALIDO

/* [Tópicos 4/5] Palavras reservadas e delimitadores de enum / genset */
%token ENUM GENSET DISJOINT OVERLAPPING COMPLETE INCOMPLETE
%token GENERAL SPECIFICS CATEGORIZER WHERE SPECIALIZES
%token ABRE_CHAVE FECHA_CHAVE VIRGULA

/* [Tópicos 4/5] Como o "aspirador" (token_invalido) aceita quase qualquer token
   depois de uma declaração, as formas incompletas de enum/genset (produções de
   erro) ficariam ambíguas. Estas precedências resolvem explicitamente a favor de
   continuar a declaração (shift), sem afetar os conflitos das outras regras. */
%precedence REDUZ_INCOMPLETO
%precedence FECHA_CHAVE SPECIALIZES VIRGULA CLASSE RELACOES INSTANCIA INVALIDO

%type <str> nome_enum literal_enum ref_classe nome_genset
%type <num> modificadores_genset modificador_genset

%%

programa:
    declaracoes_pacotes
    | declaracoes_pacotes corpo_programa
    | corpo_programa
    ;

declaracoes_pacotes:
    declaracoes_pacotes declaracao_pacote
    | declaracao_pacote
    ;

declaracao_pacote:
    PACKAGE CLASSE { inserir_simbolo($2, "Pacote", yylineno); definir_pacote_atual($2); }
    | PACKAGE ID_ATRIBUTO { inserir_simbolo($2, "Pacote", yylineno); definir_pacote_atual($2); }
    ;

/* [Tópicos 4/5] lista não-vazia (equivalente à versão anterior com produção vazia):
   assim o token 'error' pode ser empilhado logo após os pacotes e a recuperação
   de erros funciona desde o primeiro elemento do arquivo. */
corpo_programa:
    corpo_programa elemento
    | elemento
    ;

elemento:
    declaracao_relacao_externa
    | declaracao_relacao_interna
    | declaracao_enum            /* Tópico 4 */
    | declaracao_genset          /* Tópico 5 */
    | token_invalido // "Aspirador de pó" para ignorar o código dos colegas com segurança
    | error {
        enum_genset_recuperar_erro();   /* [Tópicos 4/5] fecha enum/genset interrompido */
        yyerrok;
    } // Recuperação de erro limpa (sem yyclearin destrutivo)
    ;

// Esta regra agora cobre todos os formatos numéricos, como [1], [*], [1..*] e [0..5]
cardinalidade:
    SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL
    | SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL
    | SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL
    | SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL
    | SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL
    ;

// Regra atualizada para capturar o nome da relação no meio (ex: -- tem_Massa --)
declaracao_relacao_externa:
    SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO RELATION CLASSE cardinalidade SIMBOLO_ESPECIAL RELACOES SIMBOLO_ESPECIAL cardinalidade CLASSE {
        inserir_simbolo($7, "Relação Externa", yylineno);
    }
    ;

declaracao_relacao_interna:
    SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO cardinalidade SIMBOLO_ESPECIAL cardinalidade CLASSE {
        string identificador = string("Interna_") + $2 + "_para_" + $6 + "_L" + to_string(yylineno);
        inserir_simbolo(identificador, "Relação Interna", yylineno);
    }
    ;

// Mapeamento de tudo que não nos interessa para ser ignorado silenciosamente
token_invalido:
    PACKAGE | RELATION | CLASSE | ID_ATRIBUTO | DADOS_CRIADOS | RELACOES
    | INSTANCIA | NUMERO | ESTEREOTIPO_CLASSE | PALAVRA_RESERVADA | DADOS_NATIVOS
    | META_ATRIBUTOS | ERRO_DATATYPE | SIMBOLO_ESPECIAL | INVALIDO_CLASSE
    | INVALIDO | ESTEREOTIPO_RELACAO
    /* [Tópicos 4/5] tokens que antes eram PALAVRA_RESERVADA / SIMBOLO_ESPECIAL e
       também aparecem em classes/datatypes (ex.: specializes, { } ,). enum, genset e
       as restrições NÃO entram aqui, pois iniciam as declarações dos tópicos 4 e 5. */
    | SPECIALIZES | ABRE_CHAVE | FECHA_CHAVE | VIRGULA
    | GENERAL | SPECIFICS | CATEGORIZER | WHERE
    ;

/* ======================================================================== */
/*  TÓPICO 4 — DECLARAÇÃO DE CLASSES ENUMERADAS                              */
/*                                                                          */
/*    enum EyeColor { Blue, Green, Brown, Black }                           */
/*    enum Tipo_De_Vacina { Covid01, FebreAmarela02 }                       */
/*    enum Cor specializes Tipo { Azul, Verde }        (forma do Tonto)     */
/* ======================================================================== */

declaracao_enum:
    ENUM nome_enum { enum_iniciar($2, @1.first_line, @1.first_column); }
    especializacao_enum_opt corpo_enum
    ;

nome_enum:
    CLASSE   { $$ = $1; }
    | RELACOES {
        registrar_erro(@1.first_line, @1.first_column, "Enum",
            string("Nome de enum '") + $1 + "' inicia com letra minúscula.",
            "Classes enumeradas seguem a convenção de nomes de classe (inicial maiúscula): '" +
            capitalizar($1) + "'.");
        $$ = $1;
    }
    | INSTANCIA {
        registrar_erro(@1.first_line, @1.first_column, "Enum",
            string("Nome de enum '") + $1 + "' contém números.",
            "Nomes terminados em número são reservados a instâncias; use '" +
            remover_digitos($1) + "'.");
        $$ = $1;
    }
    | DADOS_CRIADOS {
        registrar_erro(@1.first_line, @1.first_column, "Enum",
            string("Nome de enum '") + $1 + "' usa o sufixo 'DataType'.",
            "O sufixo DataType é exclusivo de novos tipos de dados (datatype). Para um enum, use um "
            "nome de classe, ex.: '" + string($1).substr(0, strlen($1) - 8) + "'.");
        $$ = $1;
    }
    | INVALIDO {
        registrar_erro(@1.first_line, @1.first_column, "Enum",
            string("Nome de enum '") + $1 + "' " + motivo_lexema_invalido($1) + ".",
            "Use apenas letras e sublinhado, com inicial maiúscula: '" +
            capitalizar(sanitizar_identificador($1)) + "'.");
        $$ = $1;
    }
    | /* vazio */ {
        registrar_erro(@$.first_line, @$.first_column, "Enum",
            "Declaração de enum sem nome.",
            "Informe o nome logo após 'enum': enum NomeDoEnum { Literal1, Literal2 }.");
        $$ = strdup("");
    }
    ;

especializacao_enum_opt:
    /* vazio */
    | SPECIALIZES lista_especializacao_enum
    | SPECIALIZES {
        registrar_erro(@1.first_line, @1.first_column, contexto_enum_genset(),
            "'specializes' sem o tipo especializado.",
            "Informe o tipo pai: enum Nome specializes TipoPai { ... }, ou remova 'specializes'.");
    }
    ;

lista_especializacao_enum:
    ref_classe { enum_adicionar_especializacao($1, @1.first_line, @1.first_column); }
    | lista_especializacao_enum VIRGULA ref_classe {
        enum_adicionar_especializacao($3, @3.first_line, @3.first_column);
    }
    ;

corpo_enum:
    ABRE_CHAVE literais_enum_opt FECHA_CHAVE { enum_finalizar(false, @3.first_line); }
    /* recuperação: descarta até '}' ... */
    | ABRE_CHAVE error FECHA_CHAVE           { enum_finalizar(true, @3.first_line); yyerrok; }
    /* ... ou até o início da próxima declaração (enum não fechado) */
    | ABRE_CHAVE error %prec REDUZ_INCOMPLETO { enum_finalizar(true, @2.last_line); yyerrok; }
    ;

literais_enum_opt:
    /* vazio */
    | lista_literais_enum
    | lista_literais_enum VIRGULA {
        registrar_erro(@2.first_line, @2.first_column, contexto_enum_genset(),
            "Vírgula sobrando após o último literal.",
            "Remova a vírgula antes de '}'.");
    }
    ;

lista_literais_enum:
    literal_enum { enum_adicionar_literal($1, @1.first_line, @1.first_column); }
    | lista_literais_enum VIRGULA literal_enum {
        consumir_separador_invalido();
        enum_adicionar_literal($3, @3.first_line, @3.first_column);
    }
    | lista_literais_enum literal_enum {
        if (!consumir_separador_invalido() && *$2)
            registrar_erro(@2.first_line, @2.first_column, contexto_enum_genset(),
                string("Falta vírgula antes do literal '") + $2 + "'.",
                "Separe os literais do enum por vírgula: Literal1, Literal2.");
        if (*$2 == '\0') separador_invalido_pendente = true;
        enum_adicionar_literal($2, @2.first_line, @2.first_column);
    }
    ;

/* Literais (instâncias) de um enum: aceita-se tanto a forma de nome de classe
   (Blue, Green — exemplo do enunciado) quanto a convenção léxica de instâncias
   (Planeta1, Covid01). */
literal_enum:
    CLASSE      { $$ = $1; }
    | INSTANCIA { $$ = $1; }
    | RELACOES {
        registrar_erro(@1.first_line, @1.first_column, contexto_enum_genset(),
            string("Literal '") + $1 + "' inicia com letra minúscula.",
            "Literais de enum iniciam com maiúscula (ex.: '" + capitalizar($1) +
            "') ou seguem a convenção de instância terminando em número (ex.: '" +
            capitalizar($1) + "01').");
        $$ = $1;
    }
    | NUMERO {
        registrar_erro(@1.first_line, @1.first_column, contexto_enum_genset(),
            string("Literal '") + $1 + "' é apenas um número.",
            string("Um literal precisa de um nome iniciado por letra, ex.: 'Valor") + $1 + "'.");
        $$ = $1;
    }
    | DADOS_CRIADOS {
        registrar_erro(@1.first_line, @1.first_column, contexto_enum_genset(),
            string("Literal '") + $1 + "' usa o sufixo 'DataType'.",
            "Literais são instâncias, não tipos; remova o sufixo DataType.");
        $$ = $1;
    }
    | INVALIDO {
        if (eh_simbolo_solto($1)) {
            registrar_erro(@1.first_line, @1.first_column, contexto_enum_genset(),
                string("Símbolo '") + $1 + "' não é um separador válido entre literais.",
                "Use vírgula para separar os literais: Literal1, Literal2.");
            $$ = strdup("");
        } else {
            registrar_erro(@1.first_line, @1.first_column, contexto_enum_genset(),
                string("Literal '") + $1 + "' " + motivo_lexema_invalido($1) + ".",
                "Use apenas letras, sublinhado e números finais; sugestão: '" +
                capitalizar(sanitizar_identificador($1)) + "'.");
            $$ = $1;
        }
    }
    ;

/* ======================================================================== */
/*  TÓPICO 5 — GENERALIZAÇÕES (GENERALIZATION SETS)                         */
/*                                                                          */
/*  Forma curta:                                                            */
/*    disjoint complete genset PersonAgeGroup where Child, Adult            */
/*        specializes Person                                                */
/*  Forma em bloco:                                                         */
/*    genset PersonAgeGroup {                                               */
/*        general Person                                                    */
/*        categorizer PersonTypeByAge        (opcional)                     */
/*        specifics Child, Adult                                            */
/*    }                                                                     */
/*  Restrições (opcionais, nesta ordem):                                    */
/*    [disjoint | overlapping] [complete | incomplete]                      */
/* ======================================================================== */

declaracao_genset:
    modificadores_genset GENSET nome_genset {
        genset_iniciar($3, $1, @2.first_line, @2.first_column);
    }
    resto_genset
    ;

modificadores_genset:
    /* vazio */ { $$ = 0; }
    | modificadores_genset modificador_genset {
        int antes = $1, novo = $2;
        int l = @2.first_line, c = @2.first_column;
        const int DISJ = MOD_DISJOINT | MOD_OVERLAPPING;
        const int COMP = MOD_COMPLETE | MOD_INCOMPLETE;
        string nome_novo = descrever_modificadores(novo);
        if (antes & novo) {
            registrar_erro(l, c, "Genset", "Restrição '" + nome_novo + "' repetida.",
                "Declare cada restrição uma única vez.");
        } else if ((novo & DISJ) && (antes & DISJ)) {
            registrar_erro(l, c, "Genset",
                "Restrições 'disjoint' e 'overlapping' usadas juntas.",
                "São mutuamente exclusivas: use 'disjoint' (subclasses sem instâncias em comum) "
                "OU 'overlapping' (subclasses podem compartilhar instâncias).");
        } else if ((novo & COMP) && (antes & COMP)) {
            registrar_erro(l, c, "Genset",
                "Restrições 'complete' e 'incomplete' usadas juntas.",
                "São mutuamente exclusivas: use 'complete' (toda instância da classe geral está em "
                "alguma específica) OU 'incomplete'.");
        } else if ((novo & DISJ) && (antes & COMP)) {
            registrar_erro(l, c, "Genset",
                "Ordem das restrições invertida: '" + descrever_modificadores(antes) + "' antes de '" +
                nome_novo + "'.",
                "A restrição de disjunção vem antes da de completude: '" +
                descrever_modificadores(antes | novo) + " genset ...'.");
        }
        $$ = antes | novo;
    }
    ;

modificador_genset:
    DISJOINT      { $$ = MOD_DISJOINT; }
    | OVERLAPPING { $$ = MOD_OVERLAPPING; }
    | COMPLETE    { $$ = MOD_COMPLETE; }
    | INCOMPLETE  { $$ = MOD_INCOMPLETE; }
    ;

nome_genset:
    CLASSE { $$ = $1; }
    | RELACOES {
        registrar_aviso(@1.first_line, @1.first_column, "Genset",
            string("Nome de genset '") + $1 + "' inicia com letra minúscula.",
            "Por consistência com os nomes de classe, prefira '" + capitalizar($1) + "'.");
        $$ = $1;
    }
    | INSTANCIA {
        registrar_aviso(@1.first_line, @1.first_column, "Genset",
            string("Nome de genset '") + $1 + "' termina com número (convenção de instâncias).",
            "Prefira um nome que descreva o aspecto da classificação, ex.: '" +
            remover_digitos($1) + "'.");
        $$ = $1;
    }
    | INVALIDO {
        registrar_erro(@1.first_line, @1.first_column, "Genset",
            string("Nome de genset '") + $1 + "' " + motivo_lexema_invalido($1) + ".",
            "Use letras e sublinhado: '" + capitalizar(sanitizar_identificador($1)) + "'.");
        $$ = $1;
    }
    | /* vazio */ {
        registrar_erro(@$.first_line, @$.first_column, "Genset",
            "Generalization set sem nome.",
            "Informe o nome logo após 'genset': genset NomeDoGenset { ... }.");
        $$ = strdup("");
    }
    ;

resto_genset:
    /* forma em bloco */
    ABRE_CHAVE corpo_genset FECHA_CHAVE { genset_definir_forma(false); genset_finalizar(false, @3.first_line); }
    | ABRE_CHAVE error FECHA_CHAVE      { genset_definir_forma(false); genset_finalizar(true, @3.first_line); yyerrok; }
    | ABRE_CHAVE error %prec REDUZ_INCOMPLETO { genset_definir_forma(false); genset_finalizar(true, @2.last_line); yyerrok; }
    /* forma curta */
    | WHERE lista_especificas SPECIALIZES ref_classe {
        genset_definir_forma(true);
        genset_definir_geral($4, @4.first_line, @4.first_column);
        genset_finalizar(false, @4.first_line);
    }
    | WHERE lista_especificas virgula_sobrando SPECIALIZES ref_classe {
        genset_definir_forma(true);
        genset_definir_geral($5, @5.first_line, @5.first_column);
        genset_finalizar(false, @5.first_line);
    }
    | WHERE lista_especificas virgula_sobrando %prec REDUZ_INCOMPLETO {
        registrar_erro(@3.last_line, @3.last_column, contexto_enum_genset(),
            "Falta 'specializes <ClasseGeral>' ao final da forma curta.",
            "Forma curta completa: genset Nome where Filha1, Filha2 specializes ClasseMae.");
        genset_definir_forma(true);
        genset_finalizar(false, @3.last_line);
    }
    | WHERE lista_especificas SPECIALIZES %prec REDUZ_INCOMPLETO {
        registrar_erro(@3.first_line, @3.first_column, contexto_enum_genset(),
            "Falta a classe geral após 'specializes'.",
            "Complete com a classe-mãe: ... where Filha1, Filha2 specializes ClasseMae.");
        genset_definir_forma(true);
        genset_finalizar(false, @3.first_line);
    }
    | WHERE lista_especificas %prec REDUZ_INCOMPLETO {
        registrar_erro(@2.last_line, @2.last_column, contexto_enum_genset(),
            "Falta 'specializes <ClasseGeral>' ao final da forma curta.",
            "Forma curta completa: genset Nome where Filha1, Filha2 specializes ClasseMae.");
        genset_definir_forma(true);
        genset_finalizar(false, @2.last_line);
    }
    ;

corpo_genset:
    clausula_general clausula_categorizer_opt clausula_specifics
    | clausula_specifics clausula_general {
        registrar_erro(@2.first_line, @2.first_column, contexto_enum_genset(),
            "Ordem invertida: 'specifics' declarado antes de 'general'.",
            "Declare primeiro a classe-mãe e depois as filhas: { general Mae specifics Filha1, Filha2 }.");
    }
    | clausula_general clausula_categorizer_opt {
        registrar_erro(@1.first_line, @1.first_column, contexto_enum_genset(),
            "Generalization set sem a cláusula 'specifics'.",
            "Liste as classes filhas: specifics Filha1, Filha2.");
    }
    | clausula_specifics {
        registrar_erro(@1.first_line, @1.first_column, contexto_enum_genset(),
            "Generalization set sem a cláusula 'general'.",
            "Informe a classe-mãe antes das filhas: general ClasseMae.");
    }
    | /* vazio */ {
        registrar_erro(@$.first_line, @$.first_column, contexto_enum_genset(),
            "Generalization set com corpo vazio.",
            "Preencha o bloco: { general ClasseMae specifics Filha1, Filha2 }.");
    }
    ;

clausula_general:
    GENERAL ref_classe { genset_definir_geral($2, @2.first_line, @2.first_column); }
    | GENERAL {
        registrar_erro(@1.first_line, @1.first_column, contexto_enum_genset(),
            "'general' sem a classe geral.",
            "Informe a classe-mãe: general ClasseMae.");
    }
    ;

clausula_categorizer_opt:
    /* vazio */
    | CATEGORIZER ref_classe { genset_definir_categorizador($2, @2.first_line, @2.first_column); }
    ;

clausula_specifics:
    SPECIFICS lista_especificas
    | SPECIFICS lista_especificas virgula_sobrando
    | SPECIFICS {
        registrar_erro(@1.first_line, @1.first_column, contexto_enum_genset(),
            "'specifics' sem nenhuma classe específica.",
            "Liste as classes filhas separadas por vírgula: specifics Filha1, Filha2.");
    }
    ;

lista_especificas:
    ref_classe { genset_adicionar_especifica($1, @1.first_line, @1.first_column); }
    | lista_especificas VIRGULA ref_classe {
        consumir_separador_invalido();
        genset_adicionar_especifica($3, @3.first_line, @3.first_column);
    }
    | lista_especificas ref_classe {
        if (!consumir_separador_invalido() && *$2)
            registrar_erro(@2.first_line, @2.first_column, contexto_enum_genset(),
                string("Falta vírgula antes de '") + $2 + "'.",
                "Separe as classes específicas por vírgula: Filha1, Filha2.");
        if (*$2 == '\0') separador_invalido_pendente = true;
        genset_adicionar_especifica($2, @2.first_line, @2.first_column);
    }
    ;

virgula_sobrando:
    VIRGULA %prec REDUZ_INCOMPLETO {
        registrar_erro(@1.first_line, @1.first_column, contexto_enum_genset(),
            "Vírgula sobrando após a última classe específica.",
            "Remova a vírgula final da lista.");
    }
    ;

/* Referência a uma classe já declarada (classe geral, específica,
   categorizador ou tipo especializado por um enum). */
ref_classe:
    CLASSE { $$ = $1; }
    | RELACOES {
        string ctx = contexto_enum_genset();
        registrar_erro(@1.first_line, @1.first_column, ctx.empty() ? "Genset" : ctx,
            string("'") + $1 + "' não é um nome de classe válido (inicia com minúscula).",
            "Nomes de classe iniciam com letra maiúscula: '" + capitalizar($1) + "'.");
        $$ = $1;
    }
    | INSTANCIA {
        string ctx = contexto_enum_genset();
        registrar_erro(@1.first_line, @1.first_column, ctx.empty() ? "Genset" : ctx,
            string("'") + $1 + "' não é um nome de classe válido (contém números).",
            "Nomes de classe não têm números; se for uma classe, use '" + remover_digitos($1) + "'.");
        $$ = $1;
    }
    | INVALIDO {
        string ctx = contexto_enum_genset();
        if (eh_simbolo_solto($1)) {
            registrar_erro(@1.first_line, @1.first_column, ctx.empty() ? "Genset" : ctx,
                string("Símbolo '") + $1 + "' não é um separador válido entre classes.",
                "Use vírgula para separar as classes: Filha1, Filha2.");
            $$ = strdup("");
        } else {
            registrar_erro(@1.first_line, @1.first_column, ctx.empty() ? "Genset" : ctx,
                string("'") + $1 + "' não é um nome de classe válido: " + motivo_lexema_invalido($1) + ".",
                "Use letras e sublinhado, com inicial maiúscula: '" +
                capitalizar(sanitizar_identificador($1)) + "'.");
            $$ = $1;
        }
    }
    ;

%%

/* ======================================================================== */
/*  Relatório de erros sintáticos                                           */
/* ======================================================================== */

/* Descrição legível de cada token, usada nas mensagens de erro. */
static string descrever_token(yysymbol_kind_t t) {
    switch (t) {
        case YYSYMBOL_YYEOF:               return "fim do arquivo";
        case YYSYMBOL_PACKAGE:             return "'package'";
        case YYSYMBOL_RELATION:            return "'relation'";
        case YYSYMBOL_ESTEREOTIPO_RELACAO: return "estereótipo de relação";
        case YYSYMBOL_CLASSE:              return "nome de classe";
        case YYSYMBOL_ID_ATRIBUTO:         return "nome de atributo";
        case YYSYMBOL_DADOS_CRIADOS:       return "novo tipo de dado";
        case YYSYMBOL_RELACOES:            return "nome de relação";
        case YYSYMBOL_INSTANCIA:           return "nome de instância";
        case YYSYMBOL_NUMERO:              return "número";
        case YYSYMBOL_ESTEREOTIPO_CLASSE:  return "estereótipo de classe";
        case YYSYMBOL_PALAVRA_RESERVADA:   return "palavra reservada";
        case YYSYMBOL_DADOS_NATIVOS:       return "tipo nativo";
        case YYSYMBOL_META_ATRIBUTOS:      return "meta-atributo";
        case YYSYMBOL_SIMBOLO_ESPECIAL:    return "símbolo especial";
        case YYSYMBOL_INVALIDO:            return "lexema inválido";
        case YYSYMBOL_ENUM:                return "'enum'";
        case YYSYMBOL_GENSET:              return "'genset'";
        case YYSYMBOL_DISJOINT:            return "'disjoint'";
        case YYSYMBOL_OVERLAPPING:         return "'overlapping'";
        case YYSYMBOL_COMPLETE:            return "'complete'";
        case YYSYMBOL_INCOMPLETE:          return "'incomplete'";
        case YYSYMBOL_GENERAL:             return "'general'";
        case YYSYMBOL_SPECIFICS:           return "'specifics'";
        case YYSYMBOL_CATEGORIZER:         return "'categorizer'";
        case YYSYMBOL_WHERE:               return "'where'";
        case YYSYMBOL_SPECIALIZES:         return "'specializes'";
        case YYSYMBOL_ABRE_CHAVE:          return "'{'";
        case YYSYMBOL_FECHA_CHAVE:         return "'}'";
        case YYSYMBOL_VIRGULA:             return "','";
        default:                           return yysymbol_name(t);
    }
}

static int yyreport_syntax_error(const yypcontext_t* ctx) {
    static int ultima_linha_reportada = -1;
    const YYLTYPE* loc = yypcontext_location(ctx);
    int linha = loc->first_line, coluna = loc->first_column;

    /* um erro sintático por linha evita cascatas durante a recuperação */
    if (linha == ultima_linha_reportada) return 0;
    ultima_linha_reportada = linha;

    yysymbol_kind_t inesperado = yypcontext_token(ctx);
    enum { MAX_ESPERADOS = 16 };
    yysymbol_kind_t esperados[MAX_ESPERADOS];
    int n = yypcontext_expected_tokens(ctx, esperados, MAX_ESPERADOS);
    bool em_construto = em_enum() || em_genset();

    string msg = "Token inesperado: " + descrever_token(inesperado);
    string desc = descrever_token(inesperado);
    bool desc_ja_eh_lexema = !desc.empty() && desc[0] == '\'';   /* palavras reservadas e '{' '}' ',' */
    if (inesperado != YYSYMBOL_YYEOF && !desc_ja_eh_lexema && yytext && *yytext)
        msg += " '" + string(yytext) + "'";
    msg += ".";

    /* Tokens aceitos apenas por produções de erro (para dar mensagens específicas)
       não são mostrados como "esperados". */
    vector<yysymbol_kind_t> mostrar;
    bool espera_genset = false, espera_enum = false, espera_fecha = false, espera_virgula = false;
    for (int i = 0; i < n; i++) {
        yysymbol_kind_t t = esperados[i];
        if (t == YYSYMBOL_GENSET) espera_genset = true;
        if (t == YYSYMBOL_ENUM) espera_enum = true;
        if (t == YYSYMBOL_FECHA_CHAVE) espera_fecha = true;
        if (t == YYSYMBOL_VIRGULA) espera_virgula = true;
        if (t == YYSYMBOL_INVALIDO) continue;
        if (em_construto && (t == YYSYMBOL_RELACOES || t == YYSYMBOL_INSTANCIA ||
                             t == YYSYMBOL_DADOS_CRIADOS || t == YYSYMBOL_NUMERO))
            continue;
        mostrar.push_back(t);
    }
    string lista;
    for (size_t i = 0; i < mostrar.size(); i++)
        lista += (i ? (i + 1 == mostrar.size() ? " ou " : ", ") : "") + descrever_token(mostrar[i]);
    if (!lista.empty()) msg += " Esperado: " + lista + ".";

    /* o token inesperado inicia uma nova declaração? (indica bloco não fechado) */
    bool inicia_declaracao =
        inesperado == YYSYMBOL_YYEOF || inesperado == YYSYMBOL_ENUM || inesperado == YYSYMBOL_GENSET ||
        inesperado == YYSYMBOL_DISJOINT || inesperado == YYSYMBOL_OVERLAPPING ||
        inesperado == YYSYMBOL_COMPLETE || inesperado == YYSYMBOL_INCOMPLETE ||
        inesperado == YYSYMBOL_PACKAGE || inesperado == YYSYMBOL_ESTEREOTIPO_CLASSE;

    /* o token inesperado é uma palavra reservada/estereótipo (não pode ser nome)? */
    bool eh_reservada = desc_ja_eh_lexema || inesperado == YYSYMBOL_ESTEREOTIPO_CLASSE ||
        inesperado == YYSYMBOL_ESTEREOTIPO_RELACAO || inesperado == YYSYMBOL_PALAVRA_RESERVADA ||
        inesperado == YYSYMBOL_DADOS_NATIVOS || inesperado == YYSYMBOL_META_ATRIBUTOS;
    bool espera_nome = false;
    for (yysymbol_kind_t t : mostrar) if (t == YYSYMBOL_CLASSE) espera_nome = true;

    string contexto = contexto_enum_genset();
    string sugestao;
    if (em_construto && espera_nome && !espera_virgula && eh_reservada &&
        inesperado != YYSYMBOL_FECHA_CHAVE && inesperado != YYSYMBOL_ABRE_CHAVE) {
        /* logo após uma vírgula: tentou-se usar palavra reservada como nome */
        sugestao = string("'") + (yytext ? yytext : "") + "' é palavra reservada da linguagem e não pode "
                   "ser usada como nome; renomeie-o (ex.: '" + capitalizar(yytext ? yytext : "") + "_') "
                   "ou, se faltou fechar o bloco, acrescente '}'.";
    } else if (em_construto && espera_fecha && inicia_declaracao) {
        sugestao = "O bloco de " + contexto + " não foi fechado: acrescente '}' " +
                   string(inesperado == YYSYMBOL_YYEOF ? "antes do fim do arquivo."
                                                       : "antes de iniciar a próxima declaração.");
    } else if (em_enum()) {
        if (espera_fecha || espera_virgula)
            sugestao = "Literais de enum são separados por vírgula e o bloco é fechado com '}': "
                       "enum Nome { Literal1, Literal2 }.";
        else
            sugestao = "Estrutura esperada: enum Nome { Literal1, Literal2, ... }.";
    } else if (em_genset()) {
        sugestao = "Estrutura esperada: [disjoint|overlapping] [complete|incomplete] genset Nome "
                   "{ general ClasseMae [categorizer Tipo] specifics Filha1, Filha2 }  ou  "
                   "genset Nome where Filha1, Filha2 specializes ClasseMae.";
    } else if (espera_genset && !espera_enum) {
        sugestao = "As restrições disjoint/overlapping/complete/incomplete só podem anteceder a "
                   "palavra reservada 'genset'.";
    } else if (inesperado == YYSYMBOL_INVALIDO) {
        sugestao = "Lexema fora das convenções da linguagem; corrija-o ou remova-o.";
    } else if (inesperado == YYSYMBOL_WHERE) {
        sugestao = "'where' só é usado na forma curta do genset (genset Nome where Filha1, Filha2 "
                   "specializes Mae); restrições como disjoint/complete vêm ANTES de 'genset'.";
    } else if (!lista.empty()) {
        sugestao = "Declaração não reconhecida nesta posição; verifique se a construção está "
                   "completa e na ordem correta.";
    }

    registrar_erro(linha, coluna, contexto.empty() ? "Sintaxe" : contexto, msg, sugestao);
    return 0;
}

void yyerror(const char *s) {
    registrar_erro(yylineno, 0, "Sintaxe", s, "");
}
