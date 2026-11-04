/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PACKAGE = 258,                 /* PACKAGE  */
    RELATION = 259,                /* RELATION  */
    DATATYPE = 260,                /* DATATYPE  */
    DOIS_PONTOS = 261,             /* DOIS_PONTOS  */
    BARRA = 262,                   /* BARRA  */
    ESTEREOTIPO_RELACAO = 263,     /* ESTEREOTIPO_RELACAO  */
    ESTEREOTIPO_CLASSE = 264,      /* ESTEREOTIPO_CLASSE  */
    CLASSE = 265,                  /* CLASSE  */
    ID_ATRIBUTO = 266,             /* ID_ATRIBUTO  */
    DADOS_CRIADOS = 267,           /* DADOS_CRIADOS  */
    RELACOES = 268,                /* RELACOES  */
    INSTANCIA = 269,               /* INSTANCIA  */
    NUMERO = 270,                  /* NUMERO  */
    DADOS_NATIVOS = 271,           /* DADOS_NATIVOS  */
    META_ATRIBUTOS = 272,          /* META_ATRIBUTOS  */
    PALAVRA_RESERVADA = 273,       /* PALAVRA_RESERVADA  */
    ERRO_DATATYPE = 274,           /* ERRO_DATATYPE  */
    SIMBOLO_ESPECIAL = 275,        /* SIMBOLO_ESPECIAL  */
    INVALIDO_CLASSE = 276,         /* INVALIDO_CLASSE  */
    INVALIDO = 277,                /* INVALIDO  */
    ENUM = 278,                    /* ENUM  */
    GENSET = 279,                  /* GENSET  */
    DISJOINT = 280,                /* DISJOINT  */
    OVERLAPPING = 281,             /* OVERLAPPING  */
    COMPLETE = 282,                /* COMPLETE  */
    INCOMPLETE = 283,              /* INCOMPLETE  */
    GENERAL = 284,                 /* GENERAL  */
    SPECIFICS = 285,               /* SPECIFICS  */
    CATEGORIZER = 286,             /* CATEGORIZER  */
    WHERE = 287,                   /* WHERE  */
    SPECIALIZES = 288,             /* SPECIALIZES  */
    ABRE_CHAVE = 289,              /* ABRE_CHAVE  */
    FECHA_CHAVE = 290,             /* FECHA_CHAVE  */
    VIRGULA = 291,                 /* VIRGULA  */
    REDUZ_INCOMPLETO = 292         /* REDUZ_INCOMPLETO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "parser.y"

    char* str;
    int num;

#line 106 "parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
