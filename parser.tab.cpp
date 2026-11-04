/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include "tabela_simbolos.h"
#include "relatorio_erros.h"   /* [Tópicos 4/5] relatório de erros com sugestões */
#include "enum_genset.h"       /* [Tópicos 4/5] enum e genset                    */
#include "classes_datatypes.h" /* [Tópicos 2/3] classes e tipos de dados          */

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

#line 104 "parser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PACKAGE = 3,                    /* PACKAGE  */
  YYSYMBOL_RELATION = 4,                   /* RELATION  */
  YYSYMBOL_DATATYPE = 5,                   /* DATATYPE  */
  YYSYMBOL_DOIS_PONTOS = 6,                /* DOIS_PONTOS  */
  YYSYMBOL_BARRA = 7,                      /* BARRA  */
  YYSYMBOL_ESTEREOTIPO_RELACAO = 8,        /* ESTEREOTIPO_RELACAO  */
  YYSYMBOL_ESTEREOTIPO_CLASSE = 9,         /* ESTEREOTIPO_CLASSE  */
  YYSYMBOL_CLASSE = 10,                    /* CLASSE  */
  YYSYMBOL_ID_ATRIBUTO = 11,               /* ID_ATRIBUTO  */
  YYSYMBOL_DADOS_CRIADOS = 12,             /* DADOS_CRIADOS  */
  YYSYMBOL_RELACOES = 13,                  /* RELACOES  */
  YYSYMBOL_INSTANCIA = 14,                 /* INSTANCIA  */
  YYSYMBOL_NUMERO = 15,                    /* NUMERO  */
  YYSYMBOL_DADOS_NATIVOS = 16,             /* DADOS_NATIVOS  */
  YYSYMBOL_META_ATRIBUTOS = 17,            /* META_ATRIBUTOS  */
  YYSYMBOL_PALAVRA_RESERVADA = 18,         /* PALAVRA_RESERVADA  */
  YYSYMBOL_ERRO_DATATYPE = 19,             /* ERRO_DATATYPE  */
  YYSYMBOL_SIMBOLO_ESPECIAL = 20,          /* SIMBOLO_ESPECIAL  */
  YYSYMBOL_INVALIDO_CLASSE = 21,           /* INVALIDO_CLASSE  */
  YYSYMBOL_INVALIDO = 22,                  /* INVALIDO  */
  YYSYMBOL_ABRE_COLCHETE = 23,             /* ABRE_COLCHETE  */
  YYSYMBOL_FECHA_COLCHETE = 24,            /* FECHA_COLCHETE  */
  YYSYMBOL_PONTOS = 25,                    /* PONTOS  */
  YYSYMBOL_ASTERISCO = 26,                 /* ASTERISCO  */
  YYSYMBOL_ENUM = 27,                      /* ENUM  */
  YYSYMBOL_GENSET = 28,                    /* GENSET  */
  YYSYMBOL_DISJOINT = 29,                  /* DISJOINT  */
  YYSYMBOL_OVERLAPPING = 30,               /* OVERLAPPING  */
  YYSYMBOL_COMPLETE = 31,                  /* COMPLETE  */
  YYSYMBOL_INCOMPLETE = 32,                /* INCOMPLETE  */
  YYSYMBOL_GENERAL = 33,                   /* GENERAL  */
  YYSYMBOL_SPECIFICS = 34,                 /* SPECIFICS  */
  YYSYMBOL_CATEGORIZER = 35,               /* CATEGORIZER  */
  YYSYMBOL_WHERE = 36,                     /* WHERE  */
  YYSYMBOL_SPECIALIZES = 37,               /* SPECIALIZES  */
  YYSYMBOL_ABRE_CHAVE = 38,                /* ABRE_CHAVE  */
  YYSYMBOL_FECHA_CHAVE = 39,               /* FECHA_CHAVE  */
  YYSYMBOL_VIRGULA = 40,                   /* VIRGULA  */
  YYSYMBOL_REDUZ_INCOMPLETO = 41,          /* REDUZ_INCOMPLETO  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_programa = 43,                  /* programa  */
  YYSYMBOL_declaracoes_pacotes = 44,       /* declaracoes_pacotes  */
  YYSYMBOL_declaracao_pacote = 45,         /* declaracao_pacote  */
  YYSYMBOL_corpo_programa = 46,            /* corpo_programa  */
  YYSYMBOL_elemento = 47,                  /* elemento  */
  YYSYMBOL_cardinalidade = 48,             /* cardinalidade  */
  YYSYMBOL_limite_card = 49,               /* limite_card  */
  YYSYMBOL_declaracao_relacao_externa = 50, /* declaracao_relacao_externa  */
  YYSYMBOL_declaracao_relacao_interna = 51, /* declaracao_relacao_interna  */
  YYSYMBOL_token_invalido = 52,            /* token_invalido  */
  YYSYMBOL_declaracao_classe = 53,         /* declaracao_classe  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_nome_classe_decl = 55,          /* nome_classe_decl  */
  YYSYMBOL_especializacao_classe_opt = 56, /* especializacao_classe_opt  */
  YYSYMBOL_lista_especializacoes_classe = 57, /* lista_especializacoes_classe  */
  YYSYMBOL_corpo_classe_opt = 58,          /* corpo_classe_opt  */
  YYSYMBOL_membros_classe_opt = 59,        /* membros_classe_opt  */
  YYSYMBOL_membros_classe = 60,            /* membros_classe  */
  YYSYMBOL_membro_classe = 61,             /* membro_classe  */
  YYSYMBOL_atributo_classe = 62,           /* atributo_classe  */
  YYSYMBOL_nome_atributo = 63,             /* nome_atributo  */
  YYSYMBOL_tipo_atributo = 64,             /* tipo_atributo  */
  YYSYMBOL_meta_atributo_prefix_opt = 65,  /* meta_atributo_prefix_opt  */
  YYSYMBOL_meta_atributo_opt = 66,         /* meta_atributo_opt  */
  YYSYMBOL_cardinalidade_opt = 67,         /* cardinalidade_opt  */
  YYSYMBOL_declaracao_datatype = 68,       /* declaracao_datatype  */
  YYSYMBOL_69_2 = 69,                      /* $@2  */
  YYSYMBOL_corpo_datatype = 70,            /* corpo_datatype  */
  YYSYMBOL_nome_datatype = 71,             /* nome_datatype  */
  YYSYMBOL_membros_datatype_opt = 72,      /* membros_datatype_opt  */
  YYSYMBOL_membros_datatype = 73,          /* membros_datatype  */
  YYSYMBOL_atributo_datatype = 74,         /* atributo_datatype  */
  YYSYMBOL_relacao_interna = 75,           /* relacao_interna  */
  YYSYMBOL_declaracao_enum = 76,           /* declaracao_enum  */
  YYSYMBOL_77_3 = 77,                      /* $@3  */
  YYSYMBOL_nome_enum = 78,                 /* nome_enum  */
  YYSYMBOL_especializacao_enum_opt = 79,   /* especializacao_enum_opt  */
  YYSYMBOL_lista_especializacao_enum = 80, /* lista_especializacao_enum  */
  YYSYMBOL_corpo_enum = 81,                /* corpo_enum  */
  YYSYMBOL_literais_enum_opt = 82,         /* literais_enum_opt  */
  YYSYMBOL_lista_literais_enum = 83,       /* lista_literais_enum  */
  YYSYMBOL_literal_enum = 84,              /* literal_enum  */
  YYSYMBOL_declaracao_genset = 85,         /* declaracao_genset  */
  YYSYMBOL_86_4 = 86,                      /* $@4  */
  YYSYMBOL_modificadores_genset = 87,      /* modificadores_genset  */
  YYSYMBOL_modificador_genset = 88,        /* modificador_genset  */
  YYSYMBOL_nome_genset = 89,               /* nome_genset  */
  YYSYMBOL_resto_genset = 90,              /* resto_genset  */
  YYSYMBOL_corpo_genset = 91,              /* corpo_genset  */
  YYSYMBOL_clausula_general = 92,          /* clausula_general  */
  YYSYMBOL_clausula_categorizer_opt = 93,  /* clausula_categorizer_opt  */
  YYSYMBOL_clausula_specifics = 94,        /* clausula_specifics  */
  YYSYMBOL_lista_especificas = 95,         /* lista_especificas  */
  YYSYMBOL_virgula_sobrando = 96,          /* virgula_sobrando  */
  YYSYMBOL_ref_classe = 97                 /* ref_classe  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1008

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    77,    78,    82,    83,    87,    88,    95,
      96,   100,   101,   102,   103,   104,   105,   106,   107,   115,
     116,   130,   131,   136,   142,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   148,   148,   148,   148,   148,   149,
     149,   149,   149,   150,   150,   150,   150,   150,   150,   154,
     154,   154,   154,   155,   155,   155,   155,   167,   167,   174,
     175,   181,   187,   196,   197,   198,   206,   207,   214,   215,
     218,   222,   229,   230,   234,   235,   239,   240,   244,   251,
     252,   256,   257,   258,   259,   268,   269,   273,   274,   278,
     279,   290,   290,   297,   300,   304,   310,   311,   312,   321,
     322,   326,   327,   331,   338,   354,   354,   359,   360,   367,
     374,   381,   388,   397,   398,   399,   407,   408,   414,   416,
     418,   422,   423,   424,   432,   433,   437,   451,   452,   453,
     461,   467,   473,   506,   506,   513,   514,   545,   546,   547,
     548,   552,   553,   559,   566,   572,   582,   583,   584,   586,
     591,   596,   603,   610,   620,   621,   626,   631,   636,   644,
     645,   653,   654,   658,   659,   660,   668,   669,   673,   684,
     694,   695,   702,   709
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "PACKAGE", "RELATION",
  "DATATYPE", "DOIS_PONTOS", "BARRA", "ESTEREOTIPO_RELACAO",
  "ESTEREOTIPO_CLASSE", "CLASSE", "ID_ATRIBUTO", "DADOS_CRIADOS",
  "RELACOES", "INSTANCIA", "NUMERO", "DADOS_NATIVOS", "META_ATRIBUTOS",
  "PALAVRA_RESERVADA", "ERRO_DATATYPE", "SIMBOLO_ESPECIAL",
  "INVALIDO_CLASSE", "INVALIDO", "ABRE_COLCHETE", "FECHA_COLCHETE",
  "PONTOS", "ASTERISCO", "ENUM", "GENSET", "DISJOINT", "OVERLAPPING",
  "COMPLETE", "INCOMPLETE", "GENERAL", "SPECIFICS", "CATEGORIZER", "WHERE",
  "SPECIALIZES", "ABRE_CHAVE", "FECHA_CHAVE", "VIRGULA",
  "REDUZ_INCOMPLETO", "$accept", "programa", "declaracoes_pacotes",
  "declaracao_pacote", "corpo_programa", "elemento", "cardinalidade",
  "limite_card", "declaracao_relacao_externa",
  "declaracao_relacao_interna", "token_invalido", "declaracao_classe",
  "$@1", "nome_classe_decl", "especializacao_classe_opt",
  "lista_especializacoes_classe", "corpo_classe_opt", "membros_classe_opt",
  "membros_classe", "membro_classe", "atributo_classe", "nome_atributo",
  "tipo_atributo", "meta_atributo_prefix_opt", "meta_atributo_opt",
  "cardinalidade_opt", "declaracao_datatype", "$@2", "corpo_datatype",
  "nome_datatype", "membros_datatype_opt", "membros_datatype",
  "atributo_datatype", "relacao_interna", "declaracao_enum", "$@3",
  "nome_enum", "especializacao_enum_opt", "lista_especializacao_enum",
  "corpo_enum", "literais_enum_opt", "lista_literais_enum", "literal_enum",
  "declaracao_genset", "$@4", "modificadores_genset", "modificador_genset",
  "nome_genset", "resto_genset", "corpo_genset", "clausula_general",
  "clausula_categorizer_opt", "clausula_specifics", "lista_especificas",
  "virgula_sobrando", "ref_classe", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-97)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-170)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     848,   -97,     5,   -97,   111,   -97,   -97,   -97,   152,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   193,
     -97,   -97,   -97,   -97,   -97,   -97,   902,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,     3,   234,   -97,   275,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   976,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
      49,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   316,
     -97,   -97,   954,   -97,   -97,   -97,   -97,   -97,    22,   357,
      44,    76,    65,    72,   -97,   -97,   -97,   -97,   -97,    45,
     -97,   398,   439,    70,   -97,   -97,   913,    70,   960,    59,
     865,   480,   -97,   -97,    95,    67,    38,   -97,   -97,   521,
      68,   -97,   134,   -97,    76,   185,   -97,   -97,   -97,   -97,
     890,   -97,    51,   -97,   971,    66,   -97,   -97,   880,   -97,
     -97,   226,   562,   260,   310,   320,    69,   -97,   -97,   952,
     -97,   387,   417,   -97,   971,   603,   -97,   -97,   -97,   -97,
     -97,   -97,   443,   896,   -97,   644,   -97,   685,   919,   933,
     484,   917,   -32,   -97,   -97,   -97,   -97,   964,   -97,   -97,
     -97,    70,   -97,   -97,   558,   585,   -97,   -97,   -97,   -97,
     947,   -97,   726,   767,   808,   -97,   -97,   -97,   909,   -97,
     971,    16,   -97,   -97,    57,   880,    70,   -97,   -97,   -97,
     971,   -97,   -97,   -97,   629,   -97,   882,   677,   -97,   689,
     887,   -97,   -97,   -97
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,     0,    26,     0,    28,    29,    44,     0,    30,
      31,    32,    33,    34,    35,    38,    39,    37,    40,     0,
      42,    43,    45,    46,    47,    48,     0,    53,    54,    55,
      56,    49,    50,    51,    52,     0,     0,     6,     0,    10,
      11,    12,    17,    15,    16,    24,    13,    14,     0,     7,
       8,    96,    97,    98,    91,    59,    60,    61,    62,    57,
       0,   107,   110,   108,   109,   111,   105,     1,     5,     0,
      25,     9,     0,   137,   138,   139,   140,   136,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   133,     0,
      92,     0,     0,     0,    21,    22,     0,     0,     0,     0,
       0,     0,    79,    80,     0,     0,     0,   101,    66,     0,
       0,    58,     0,    19,     0,     0,   170,   171,   172,   173,
       0,   116,     0,   106,     0,     0,   134,    94,     0,    93,
     102,     0,     0,     0,     0,     0,     0,    74,    76,     0,
      77,     0,     0,   104,     0,     0,   127,   131,   129,   128,
     130,   132,     0,     0,   124,     0,   166,     0,     0,     0,
       0,     0,     0,    82,    83,    81,    84,     0,    67,    70,
      86,     0,    69,    75,     0,     0,    20,   117,   119,   118,
       0,   126,     0,     0,     0,   168,   147,   159,     0,   146,
       0,     0,   155,    90,     0,     0,     0,   125,   149,   167,
       0,   164,   162,   154,     0,   103,     0,     0,   150,     0,
       0,    23,    88,    78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   -97,   -97,   733,   774,     9,   -93,   736,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   755,
     -97,   758,   709,   -97,   703,   711,   -97,   -97,   -97,   -97,
     -97,   -97,   821,   -53,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -82,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     772,   -97,   753,   786,   762,   -96
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    35,    36,    37,    38,    39,    82,    96,    40,    41,
      42,    43,    79,    59,    92,   109,   111,   135,   136,   137,
     138,   104,   167,   139,   205,   194,    44,    78,    90,    54,
     105,   106,   107,    45,    46,    83,    66,    99,   120,   123,
     152,   153,   154,    47,   100,    48,    77,    88,   126,   160,
     161,   191,   162,   155,   184,   156
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     112,   158,   121,    67,   115,   -25,   -25,  -157,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,    49,    50,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   101,    71,   177,   102,
     159,   103,   145,    80,    93,  -156,   102,   140,   103,   185,
      89,   146,   187,   147,   148,   149,   150,   157,   -87,   132,
     -87,   181,    81,   151,   193,   133,   133,  -100,    71,   -85,
     -85,   -85,   -85,   140,   -99,    97,   198,   199,   134,   134,
    -121,    94,   185,    81,   202,   204,   -87,   122,   197,   158,
     159,   128,    95,   207,   208,  -158,   129,   -72,   -73,    98,
    -113,   -27,   -27,   193,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,    51,   -27,    52,   -27,   -27,   -27,   -27,   -27,   -27,
      53,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -36,   -36,   141,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,    55,   -36,   -36,    56,    57,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,    58,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -41,   -41,   143,   -41,   -41,   -41,   -41,
     -41,    60,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,    -2,     1,   168,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,  -135,  -135,  -135,  -135,  -135,    27,    28,    29,
      30,    31,    32,    33,    34,    -4,     1,   170,    70,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,  -135,  -135,  -135,  -135,  -135,    27,    28,
      29,    30,    31,    32,    33,    34,    -3,     1,   171,    70,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,  -135,  -135,  -135,  -135,  -135,    27,
      28,    29,    30,    31,    32,    33,    34,   -63,   -63,   172,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,    91,   -63,   -63,   -63,   -65,   -65,
     175,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   108,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -68,
     -68,   176,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   110,   -68,   -68,
     -95,   -95,   179,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   127,
     -95,   -64,   -64,   189,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   131,   -71,   -71,   195,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   169,   -71,  -120,  -120,   196,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,   178,  -120,  -153,  -153,   209,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,   116,  -153,  -153,   117,   118,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,   119,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,   182,  -153,  -153,   183,  -148,  -148,   211,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,   186,  -148,  -152,  -152,   212,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,   116,  -152,  -152,   117,
     118,  -152,  -152,  -152,  -152,  -152,  -152,  -152,   119,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -169,  -169,    68,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,   116,  -169,  -169,
     117,   118,  -169,  -169,  -169,  -169,  -169,  -169,  -169,   119,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -151,  -151,
      69,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,   200,  -151,  -151,  -151,     1,
     142,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,  -135,  -135,  -135,  -135,
    -135,    27,    28,    29,    30,    31,    32,    33,    34,   -89,
     163,   173,   164,   -89,   -87,   -89,   165,   174,   -87,   166,
     -87,   124,   -89,   125,   206,    81,   146,   -87,   147,   148,
     149,   150,    61,   213,    62,    63,    64,   210,   151,   116,
     -89,   -89,   117,   118,    65,   204,   -87,   130,  -114,   116,
     144,   119,   117,   118,   192,  -122,   180,   113,   114,  -112,
    -112,   119,  -163,   116,   203,   188,   117,   118,  -163,   183,
     201,  -161,   190,  -160,  -160,   119,  -161,   146,  -160,   147,
     148,   149,   150,   102,    84,   103,  -165,    85,    86,   151,
     116,     0,  -165,   117,   118,   -89,    87,   -89,     0,     0,
       0,   116,   119,     0,   117,   118,  -123,    81,     0,     0,
    -145,     0,  -145,   119,     0,     0,     0,     0,  -115,     0,
       0,     0,   -89,   -89,    72,    73,    74,    75,    76
};

static const yytype_int16 yycheck[] =
{
      93,    33,    98,     0,    97,     0,     1,    39,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     1,    38,   144,    11,
      34,    13,     1,     4,    10,    39,    11,   110,    13,   155,
      38,    10,   158,    12,    13,    14,    15,     1,    11,     1,
      13,   153,    23,    22,   167,     7,     7,    39,    69,    11,
      11,    13,    13,   136,    39,    20,   182,   183,    20,    20,
      39,    15,   188,    23,   190,    38,    39,    38,   180,    33,
      34,     6,    26,   196,   200,    39,    39,    39,    39,    37,
      38,     0,     1,   206,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,     1,    20,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     1,    10,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     1,    10,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,     1,    17,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     1,     8,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,     1,    39,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,     1,
      13,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
       1,    24,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,     1,    39,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,     1,    39,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,     1,     6,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     1,    20,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     1,    17,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,     1,    10,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     1,    39,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,     1,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,     1,
      36,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     1,
     114,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     7,
      10,   136,    12,    11,     7,    13,    16,   139,    11,    19,
      13,    36,    20,    38,   195,    23,    10,    20,    12,    13,
      14,    15,    10,   210,    12,    13,    14,   206,    22,    10,
      38,    39,    13,    14,    22,    38,    39,   106,    38,    10,
      40,    22,    13,    14,   162,    39,    40,    24,    25,    37,
      38,    22,    33,    10,   191,   159,    13,    14,    39,    40,
     188,    34,    35,    34,    35,    22,    39,    10,    39,    12,
      13,    14,    15,    11,    10,    13,    33,    13,    14,    22,
      10,    -1,    39,    13,    14,    11,    22,    13,    -1,    -1,
      -1,    10,    22,    -1,    13,    14,    39,    23,    -1,    -1,
      36,    -1,    38,    22,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    38,    39,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    33,    34,    35,
      36,    37,    38,    39,    40,    43,    44,    45,    46,    47,
      50,    51,    52,    53,    68,    75,    76,    85,    87,    10,
      11,    10,    12,    19,    71,    10,    13,    14,    22,    55,
       8,    10,    12,    13,    14,    22,    78,     0,    45,    46,
       3,    47,    28,    29,    30,    31,    32,    88,    69,    54,
       4,    23,    48,    77,    10,    13,    14,    22,    89,    38,
      70,    37,    56,    10,    15,    26,    49,    20,    37,    79,
      86,     1,    11,    13,    63,    72,    73,    74,    10,    57,
      38,    58,    48,    24,    25,    48,    10,    13,    14,    22,
      80,    97,    38,    81,    36,    38,    90,    39,     6,    39,
      74,    40,     1,     7,    20,    59,    60,    61,    62,    65,
      75,    20,    49,    10,    40,     1,    10,    12,    13,    14,
      15,    22,    82,    83,    84,    95,    97,     1,    33,    34,
      91,    92,    94,    10,    12,    16,    19,    64,    10,    39,
      17,     8,    39,    61,    63,    13,    24,    97,    39,    39,
      40,    84,    37,    40,    96,    97,    39,    97,    95,    39,
      35,    93,    92,    48,    67,     6,    20,    84,    97,    97,
      37,    96,    97,    94,    38,    66,    64,    48,    97,    17,
      67,    10,    39,    66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    44,    45,    45,    46,
      46,    47,    47,    47,    47,    47,    47,    47,    47,    48,
      48,    49,    49,    50,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    54,    53,    55,
      55,    55,    55,    56,    56,    56,    57,    57,    58,    58,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    63,
      63,    64,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    69,    68,    70,    70,    70,    71,    71,    71,    72,
      72,    73,    73,    74,    75,    77,    76,    78,    78,    78,
      78,    78,    78,    79,    79,    79,    80,    80,    81,    81,
      81,    82,    82,    82,    83,    83,    83,    84,    84,    84,
      84,    84,    84,    86,    85,    87,    87,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    92,
      92,    93,    93,    94,    94,    94,    95,    95,    95,    96,
      97,    97,    97,    97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     1,     1,    10,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     1,
       1,     1,     1,     0,     2,     1,     1,     3,     0,     3,
       3,     2,     0,     1,     1,     2,     1,     1,     6,     1,
       1,     1,     1,     1,     1,     0,     2,     0,     3,     0,
       1,     0,     4,     3,     3,     2,     1,     1,     1,     0,
       1,     1,     2,     5,     6,     0,     5,     1,     1,     1,
       1,     1,     0,     0,     2,     1,     1,     3,     3,     3,
       2,     0,     1,     2,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     0,     5,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     3,     2,     4,
       5,     3,     3,     2,     3,     2,     2,     1,     0,     2,
       1,     0,     2,     2,     3,     1,     1,     3,     2,     1,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          YYNOMEM;                                                      \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




/* The kind of the lookahead of this context.  */
static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;

static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx)
{
  return yyctx->yytoken;
}

/* The location of the lookahead of this context.  */
static YYLTYPE *
yypcontext_location (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;

static YYLTYPE *
yypcontext_location (const yypcontext_t *yyctx)
{
  return yyctx->yylloc;
}

/* User defined function to report a syntax error.  */
static int
yyreport_syntax_error (const yypcontext_t *yyctx);

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      YY_LAC_ESTABLISH;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 7: /* declaracao_pacote: PACKAGE CLASSE  */
#line 87 "parser.y"
                   { inserir_simbolo((yyvsp[0].str), "Pacote", yylineno); definir_pacote_atual((yyvsp[0].str)); }
#line 1945 "parser.tab.cpp"
    break;

  case 8: /* declaracao_pacote: PACKAGE ID_ATRIBUTO  */
#line 88 "parser.y"
                          { inserir_simbolo((yyvsp[0].str), "Pacote", yylineno); definir_pacote_atual((yyvsp[0].str)); }
#line 1951 "parser.tab.cpp"
    break;

  case 18: /* elemento: error  */
#line 107 "parser.y"
            {
        enum_genset_recuperar_erro();   /* [Tópicos 4/5] fecha enum/genset interrompido */
        yyerrok;
    }
#line 1960 "parser.tab.cpp"
    break;

  case 20: /* cardinalidade: ABRE_COLCHETE limite_card PONTOS limite_card FECHA_COLCHETE  */
#line 116 "parser.y"
                                                                  {
        string lo = (yyvsp[-3].str), hi = (yyvsp[-1].str);
        if (lo == "*" && hi != "*")
            registrar_erro((yylsp[-4]).first_line, (yylsp[-4]).first_column, "Cardinalidade",
                "Limite inferior '*' com limite superior numérico.",
                "Use [*] ou [n..*].");
        else if (lo != "*" && hi != "*" && stol(lo) > stol(hi))
            registrar_erro((yylsp[-4]).first_line, (yylsp[-4]).first_column, "Cardinalidade",
                "Limite inferior (" + lo + ") maior que o superior (" + hi + ").",
                "Inverta os limites: [" + hi + ".." + lo + "].");
    }
#line 1976 "parser.tab.cpp"
    break;

  case 21: /* limite_card: NUMERO  */
#line 130 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 1982 "parser.tab.cpp"
    break;

  case 22: /* limite_card: ASTERISCO  */
#line 131 "parser.y"
                { (yyval.str) = strdup("*"); }
#line 1988 "parser.tab.cpp"
    break;

  case 23: /* declaracao_relacao_externa: SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO RELATION CLASSE cardinalidade SIMBOLO_ESPECIAL RELACOES SIMBOLO_ESPECIAL cardinalidade CLASSE  */
#line 136 "parser.y"
                                                                                                                                       {
        inserir_simbolo((yyvsp[-3].str), "Relação Externa", yylineno);
    }
#line 1996 "parser.tab.cpp"
    break;

  case 57: /* $@1: %empty  */
#line 167 "parser.y"
                                        {
        classe_iniciar((yyvsp[-1].str), (yyvsp[0].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2004 "parser.tab.cpp"
    break;

  case 59: /* nome_classe_decl: CLASSE  */
#line 174 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2010 "parser.tab.cpp"
    break;

  case 60: /* nome_classe_decl: RELACOES  */
#line 175 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Classe",
            string("Nome de classe '") + (yyvsp[0].str) + "' inicia com letra minúscula.",
            "Nomes de classe iniciam com maiúscula: '" + capitalizar((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2021 "parser.tab.cpp"
    break;

  case 61: /* nome_classe_decl: INSTANCIA  */
#line 181 "parser.y"
                {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Classe",
            string("Nome de classe '") + (yyvsp[0].str) + "' contém números.",
            "Remova os números do nome da classe: '" + remover_digitos((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2032 "parser.tab.cpp"
    break;

  case 62: /* nome_classe_decl: INVALIDO  */
#line 187 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Classe",
            string("Nome de classe '") + (yyvsp[0].str) + "' " + motivo_lexema_invalido((yyvsp[0].str)) + ".",
            "Use letras e sublinhado, com inicial maiúscula.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2043 "parser.tab.cpp"
    break;

  case 65: /* especializacao_classe_opt: SPECIALIZES  */
#line 198 "parser.y"
                  {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Classe",
            "'specializes' sem classe especializada.",
            "Informe a classe-mãe: phase Child specializes Person.");
    }
#line 2053 "parser.tab.cpp"
    break;

  case 66: /* lista_especializacoes_classe: CLASSE  */
#line 206 "parser.y"
           { classe_adicionar_especializacao((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2059 "parser.tab.cpp"
    break;

  case 67: /* lista_especializacoes_classe: lista_especializacoes_classe VIRGULA CLASSE  */
#line 207 "parser.y"
                                                  {
        classe_adicionar_especializacao((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2067 "parser.tab.cpp"
    break;

  case 68: /* corpo_classe_opt: %empty  */
#line 214 "parser.y"
           { classe_finalizar(false, (yyloc).last_line); }
#line 2073 "parser.tab.cpp"
    break;

  case 69: /* corpo_classe_opt: ABRE_CHAVE membros_classe_opt FECHA_CHAVE  */
#line 215 "parser.y"
                                                {
        classe_finalizar(false, (yylsp[0]).last_line);
    }
#line 2081 "parser.tab.cpp"
    break;

  case 70: /* corpo_classe_opt: ABRE_CHAVE error FECHA_CHAVE  */
#line 218 "parser.y"
                                   {
        classe_finalizar(true, (yylsp[0]).last_line);
        yyerrok;
    }
#line 2090 "parser.tab.cpp"
    break;

  case 71: /* corpo_classe_opt: ABRE_CHAVE error  */
#line 222 "parser.y"
                                              {
        classe_finalizar(true, (yylsp[0]).last_line);
        yyerrok;
    }
#line 2099 "parser.tab.cpp"
    break;

  case 78: /* atributo_classe: meta_atributo_prefix_opt nome_atributo DOIS_PONTOS tipo_atributo cardinalidade_opt meta_atributo_opt  */
#line 244 "parser.y"
                                                                                                         {
        string meta = ((yyvsp[-5].str) && *(yyvsp[-5].str)) ? string((yyvsp[-5].str)) : string((yyvsp[0].str) ? (yyvsp[0].str) : "");
        classe_adicionar_atributo((yyvsp[-4].str), (yyvsp[-2].str), meta.c_str(), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2108 "parser.tab.cpp"
    break;

  case 79: /* nome_atributo: ID_ATRIBUTO  */
#line 251 "parser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 2114 "parser.tab.cpp"
    break;

  case 80: /* nome_atributo: RELACOES  */
#line 252 "parser.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 2120 "parser.tab.cpp"
    break;

  case 81: /* tipo_atributo: DADOS_NATIVOS  */
#line 256 "parser.y"
                  { (yyval.str) = (yyvsp[0].str); }
#line 2126 "parser.tab.cpp"
    break;

  case 82: /* tipo_atributo: CLASSE  */
#line 257 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 2132 "parser.tab.cpp"
    break;

  case 83: /* tipo_atributo: DADOS_CRIADOS  */
#line 258 "parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2138 "parser.tab.cpp"
    break;

  case 84: /* tipo_atributo: ERRO_DATATYPE  */
#line 259 "parser.y"
                    {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "DataType",
            string("Tipo de dado '") + (yyvsp[0].str) + "' utiliza capitalização incorreta do sufixo DataType.",
            "Utilize o sufixo exato 'DataType' ou declare o tipo com a palavra-chave datatype.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2149 "parser.tab.cpp"
    break;

  case 85: /* meta_atributo_prefix_opt: %empty  */
#line 268 "parser.y"
           { (yyval.str) = strdup(""); }
#line 2155 "parser.tab.cpp"
    break;

  case 86: /* meta_atributo_prefix_opt: BARRA META_ATRIBUTOS  */
#line 269 "parser.y"
                           { (yyval.str) = (yyvsp[0].str); }
#line 2161 "parser.tab.cpp"
    break;

  case 87: /* meta_atributo_opt: %empty  */
#line 273 "parser.y"
           { (yyval.str) = strdup(""); }
#line 2167 "parser.tab.cpp"
    break;

  case 88: /* meta_atributo_opt: ABRE_CHAVE META_ATRIBUTOS FECHA_CHAVE  */
#line 274 "parser.y"
                                            { (yyval.str) = (yyvsp[-1].str); }
#line 2173 "parser.tab.cpp"
    break;

  case 91: /* $@2: %empty  */
#line 290 "parser.y"
                           {
        datatype_iniciar((yyvsp[0].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2181 "parser.tab.cpp"
    break;

  case 93: /* corpo_datatype: ABRE_CHAVE membros_datatype_opt FECHA_CHAVE  */
#line 297 "parser.y"
                                                {
        datatype_finalizar(false, (yylsp[0]).last_line);
    }
#line 2189 "parser.tab.cpp"
    break;

  case 94: /* corpo_datatype: ABRE_CHAVE error FECHA_CHAVE  */
#line 300 "parser.y"
                                   {
        datatype_finalizar(true, (yylsp[0]).last_line);
        yyerrok;
    }
#line 2198 "parser.tab.cpp"
    break;

  case 95: /* corpo_datatype: ABRE_CHAVE error  */
#line 304 "parser.y"
                                              {
        datatype_finalizar(true, (yylsp[0]).last_line);
        yyerrok;
    }
#line 2207 "parser.tab.cpp"
    break;

  case 96: /* nome_datatype: CLASSE  */
#line 310 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2213 "parser.tab.cpp"
    break;

  case 97: /* nome_datatype: DADOS_CRIADOS  */
#line 311 "parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2219 "parser.tab.cpp"
    break;

  case 98: /* nome_datatype: ERRO_DATATYPE  */
#line 312 "parser.y"
                    {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "DataType",
            string("Nome de tipo de dado '") + (yyvsp[0].str) + "' utiliza capitalização incorreta do sufixo.",
            "Quando utilizar o sufixo, escreva exatamente 'DataType' (D e T maiúsculos).");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2230 "parser.tab.cpp"
    break;

  case 103: /* atributo_datatype: nome_atributo DOIS_PONTOS tipo_atributo cardinalidade_opt meta_atributo_opt  */
#line 331 "parser.y"
                                                                                {
        datatype_adicionar_atributo((yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[0].str), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2238 "parser.tab.cpp"
    break;

  case 104: /* relacao_interna: SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO cardinalidade SIMBOLO_ESPECIAL cardinalidade CLASSE  */
#line 338 "parser.y"
                                                                                             {
        string identificador = string("Interna_") + (yyvsp[-4].str) + "_para_" + (yyvsp[0].str) + "_L" + to_string((yylsp[-5]).first_line);
        inserir_simbolo(identificador, "Relação Interna", (yylsp[-5]).first_line);
        classe_adicionar_relacao_interna((yylsp[-5]).first_line);
    }
#line 2248 "parser.tab.cpp"
    break;

  case 105: /* $@3: %empty  */
#line 354 "parser.y"
                   { enum_iniciar((yyvsp[0].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2254 "parser.tab.cpp"
    break;

  case 107: /* nome_enum: CLASSE  */
#line 359 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 2260 "parser.tab.cpp"
    break;

  case 108: /* nome_enum: RELACOES  */
#line 360 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Enum",
            string("Nome de enum '") + (yyvsp[0].str) + "' inicia com letra minúscula.",
            "Classes enumeradas seguem a convenção de nomes de classe (inicial maiúscula): '" +
            capitalizar((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2272 "parser.tab.cpp"
    break;

  case 109: /* nome_enum: INSTANCIA  */
#line 367 "parser.y"
                {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Enum",
            string("Nome de enum '") + (yyvsp[0].str) + "' contém números.",
            "Nomes terminados em número são reservados a instâncias; use '" +
            remover_digitos((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2284 "parser.tab.cpp"
    break;

  case 110: /* nome_enum: DADOS_CRIADOS  */
#line 374 "parser.y"
                    {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Enum",
            string("Nome de enum '") + (yyvsp[0].str) + "' usa o sufixo 'DataType'.",
            "O sufixo DataType é exclusivo de novos tipos de dados (datatype). Para um enum, use um "
            "nome de classe, ex.: '" + string((yyvsp[0].str)).substr(0, strlen((yyvsp[0].str)) - 8) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2296 "parser.tab.cpp"
    break;

  case 111: /* nome_enum: INVALIDO  */
#line 381 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Enum",
            string("Nome de enum '") + (yyvsp[0].str) + "' " + motivo_lexema_invalido((yyvsp[0].str)) + ".",
            "Use apenas letras e sublinhado, com inicial maiúscula: '" +
            capitalizar(sanitizar_identificador((yyvsp[0].str))) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2308 "parser.tab.cpp"
    break;

  case 112: /* nome_enum: %empty  */
#line 388 "parser.y"
             {
        registrar_erro((yyloc).first_line, (yyloc).first_column, "Enum",
            "Declaração de enum sem nome.",
            "Informe o nome logo após 'enum': enum NomeDoEnum { Literal1, Literal2 }.");
        (yyval.str) = strdup("");
    }
#line 2319 "parser.tab.cpp"
    break;

  case 115: /* especializacao_enum_opt: SPECIALIZES  */
#line 399 "parser.y"
                  {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "'specializes' sem o tipo especializado.",
            "Informe o tipo pai: enum Nome specializes TipoPai { ... }, ou remova 'specializes'.");
    }
#line 2329 "parser.tab.cpp"
    break;

  case 116: /* lista_especializacao_enum: ref_classe  */
#line 407 "parser.y"
               { enum_adicionar_especializacao((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2335 "parser.tab.cpp"
    break;

  case 117: /* lista_especializacao_enum: lista_especializacao_enum VIRGULA ref_classe  */
#line 408 "parser.y"
                                                   {
        enum_adicionar_especializacao((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2343 "parser.tab.cpp"
    break;

  case 118: /* corpo_enum: ABRE_CHAVE literais_enum_opt FECHA_CHAVE  */
#line 414 "parser.y"
                                             { enum_finalizar(false, (yylsp[0]).first_line); }
#line 2349 "parser.tab.cpp"
    break;

  case 119: /* corpo_enum: ABRE_CHAVE error FECHA_CHAVE  */
#line 416 "parser.y"
                                             { enum_finalizar(true, (yylsp[0]).first_line); yyerrok; }
#line 2355 "parser.tab.cpp"
    break;

  case 120: /* corpo_enum: ABRE_CHAVE error  */
#line 418 "parser.y"
                                              { enum_finalizar(true, (yylsp[0]).last_line); yyerrok; }
#line 2361 "parser.tab.cpp"
    break;

  case 123: /* literais_enum_opt: lista_literais_enum VIRGULA  */
#line 424 "parser.y"
                                  {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Vírgula sobrando após o último literal.",
            "Remova a vírgula antes de '}'.");
    }
#line 2371 "parser.tab.cpp"
    break;

  case 124: /* lista_literais_enum: literal_enum  */
#line 432 "parser.y"
                 { enum_adicionar_literal((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2377 "parser.tab.cpp"
    break;

  case 125: /* lista_literais_enum: lista_literais_enum VIRGULA literal_enum  */
#line 433 "parser.y"
                                               {
        consumir_separador_invalido();
        enum_adicionar_literal((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2386 "parser.tab.cpp"
    break;

  case 126: /* lista_literais_enum: lista_literais_enum literal_enum  */
#line 437 "parser.y"
                                       {
        if (!consumir_separador_invalido() && *(yyvsp[0].str))
            registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
                string("Falta vírgula antes do literal '") + (yyvsp[0].str) + "'.",
                "Separe os literais do enum por vírgula: Literal1, Literal2.");
        if (*(yyvsp[0].str) == '\0') separador_invalido_pendente = true;
        enum_adicionar_literal((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2399 "parser.tab.cpp"
    break;

  case 127: /* literal_enum: CLASSE  */
#line 451 "parser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 2405 "parser.tab.cpp"
    break;

  case 128: /* literal_enum: INSTANCIA  */
#line 452 "parser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 2411 "parser.tab.cpp"
    break;

  case 129: /* literal_enum: RELACOES  */
#line 453 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            string("Literal '") + (yyvsp[0].str) + "' inicia com letra minúscula.",
            "Literais de enum iniciam com maiúscula (ex.: '" + capitalizar((yyvsp[0].str)) +
            "') ou seguem a convenção de instância terminando em número (ex.: '" +
            capitalizar((yyvsp[0].str)) + "01').");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2424 "parser.tab.cpp"
    break;

  case 130: /* literal_enum: NUMERO  */
#line 461 "parser.y"
             {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            string("Literal '") + (yyvsp[0].str) + "' é apenas um número.",
            string("Um literal precisa de um nome iniciado por letra, ex.: 'Valor") + (yyvsp[0].str) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2435 "parser.tab.cpp"
    break;

  case 131: /* literal_enum: DADOS_CRIADOS  */
#line 467 "parser.y"
                    {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            string("Literal '") + (yyvsp[0].str) + "' usa o sufixo 'DataType'.",
            "Literais são instâncias, não tipos; remova o sufixo DataType.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2446 "parser.tab.cpp"
    break;

  case 132: /* literal_enum: INVALIDO  */
#line 473 "parser.y"
               {
        if (eh_simbolo_solto((yyvsp[0].str))) {
            registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
                string("Símbolo '") + (yyvsp[0].str) + "' não é um separador válido entre literais.",
                "Use vírgula para separar os literais: Literal1, Literal2.");
            (yyval.str) = strdup("");
        } else {
            registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
                string("Literal '") + (yyvsp[0].str) + "' " + motivo_lexema_invalido((yyvsp[0].str)) + ".",
                "Use apenas letras, sublinhado e números finais; sugestão: '" +
                capitalizar(sanitizar_identificador((yyvsp[0].str))) + "'.");
            (yyval.str) = (yyvsp[0].str);
        }
    }
#line 2465 "parser.tab.cpp"
    break;

  case 133: /* $@4: %empty  */
#line 506 "parser.y"
                                            {
        genset_iniciar((yyvsp[0].str), (yyvsp[-2].num), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2473 "parser.tab.cpp"
    break;

  case 135: /* modificadores_genset: %empty  */
#line 513 "parser.y"
           { (yyval.num) = 0; }
#line 2479 "parser.tab.cpp"
    break;

  case 136: /* modificadores_genset: modificadores_genset modificador_genset  */
#line 514 "parser.y"
                                              {
        int antes = (yyvsp[-1].num), novo = (yyvsp[0].num);
        int l = (yylsp[0]).first_line, c = (yylsp[0]).first_column;
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
        (yyval.num) = antes | novo;
    }
#line 2512 "parser.tab.cpp"
    break;

  case 137: /* modificador_genset: DISJOINT  */
#line 545 "parser.y"
                  { (yyval.num) = MOD_DISJOINT; }
#line 2518 "parser.tab.cpp"
    break;

  case 138: /* modificador_genset: OVERLAPPING  */
#line 546 "parser.y"
                  { (yyval.num) = MOD_OVERLAPPING; }
#line 2524 "parser.tab.cpp"
    break;

  case 139: /* modificador_genset: COMPLETE  */
#line 547 "parser.y"
                  { (yyval.num) = MOD_COMPLETE; }
#line 2530 "parser.tab.cpp"
    break;

  case 140: /* modificador_genset: INCOMPLETE  */
#line 548 "parser.y"
                  { (yyval.num) = MOD_INCOMPLETE; }
#line 2536 "parser.tab.cpp"
    break;

  case 141: /* nome_genset: CLASSE  */
#line 552 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2542 "parser.tab.cpp"
    break;

  case 142: /* nome_genset: RELACOES  */
#line 553 "parser.y"
               {
        registrar_aviso((yylsp[0]).first_line, (yylsp[0]).first_column, "Genset",
            string("Nome de genset '") + (yyvsp[0].str) + "' inicia com letra minúscula.",
            "Por consistência com os nomes de classe, prefira '" + capitalizar((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2553 "parser.tab.cpp"
    break;

  case 143: /* nome_genset: INSTANCIA  */
#line 559 "parser.y"
                {
        registrar_aviso((yylsp[0]).first_line, (yylsp[0]).first_column, "Genset",
            string("Nome de genset '") + (yyvsp[0].str) + "' termina com número (convenção de instâncias).",
            "Prefira um nome que descreva o aspecto da classificação, ex.: '" +
            remover_digitos((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2565 "parser.tab.cpp"
    break;

  case 144: /* nome_genset: INVALIDO  */
#line 566 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Genset",
            string("Nome de genset '") + (yyvsp[0].str) + "' " + motivo_lexema_invalido((yyvsp[0].str)) + ".",
            "Use letras e sublinhado: '" + capitalizar(sanitizar_identificador((yyvsp[0].str))) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2576 "parser.tab.cpp"
    break;

  case 145: /* nome_genset: %empty  */
#line 572 "parser.y"
             {
        registrar_erro((yyloc).first_line, (yyloc).first_column, "Genset",
            "Generalization set sem nome.",
            "Informe o nome logo após 'genset': genset NomeDoGenset { ... }.");
        (yyval.str) = strdup("");
    }
#line 2587 "parser.tab.cpp"
    break;

  case 146: /* resto_genset: ABRE_CHAVE corpo_genset FECHA_CHAVE  */
#line 582 "parser.y"
                                        { genset_definir_forma(false); genset_finalizar(false, (yylsp[0]).first_line); }
#line 2593 "parser.tab.cpp"
    break;

  case 147: /* resto_genset: ABRE_CHAVE error FECHA_CHAVE  */
#line 583 "parser.y"
                                        { genset_definir_forma(false); genset_finalizar(true, (yylsp[0]).first_line); yyerrok; }
#line 2599 "parser.tab.cpp"
    break;

  case 148: /* resto_genset: ABRE_CHAVE error  */
#line 584 "parser.y"
                                              { genset_definir_forma(false); genset_finalizar(true, (yylsp[0]).last_line); yyerrok; }
#line 2605 "parser.tab.cpp"
    break;

  case 149: /* resto_genset: WHERE lista_especificas SPECIALIZES ref_classe  */
#line 586 "parser.y"
                                                     {
        genset_definir_forma(true);
        genset_definir_geral((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
        genset_finalizar(false, (yylsp[0]).first_line);
    }
#line 2615 "parser.tab.cpp"
    break;

  case 150: /* resto_genset: WHERE lista_especificas virgula_sobrando SPECIALIZES ref_classe  */
#line 591 "parser.y"
                                                                      {
        genset_definir_forma(true);
        genset_definir_geral((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
        genset_finalizar(false, (yylsp[0]).first_line);
    }
#line 2625 "parser.tab.cpp"
    break;

  case 151: /* resto_genset: WHERE lista_especificas virgula_sobrando  */
#line 596 "parser.y"
                                                                      {
        registrar_erro((yylsp[0]).last_line, (yylsp[0]).last_column, contexto_enum_genset(),
            "Falta 'specializes <ClasseGeral>' ao final da forma curta.",
            "Forma curta completa: genset Nome where Filha1, Filha2 specializes ClasseMae.");
        genset_definir_forma(true);
        genset_finalizar(false, (yylsp[0]).last_line);
    }
#line 2637 "parser.tab.cpp"
    break;

  case 152: /* resto_genset: WHERE lista_especificas SPECIALIZES  */
#line 603 "parser.y"
                                                                 {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Falta a classe geral após 'specializes'.",
            "Complete com a classe-mãe: ... where Filha1, Filha2 specializes ClasseMae.");
        genset_definir_forma(true);
        genset_finalizar(false, (yylsp[0]).first_line);
    }
#line 2649 "parser.tab.cpp"
    break;

  case 153: /* resto_genset: WHERE lista_especificas  */
#line 610 "parser.y"
                                                     {
        registrar_erro((yylsp[0]).last_line, (yylsp[0]).last_column, contexto_enum_genset(),
            "Falta 'specializes <ClasseGeral>' ao final da forma curta.",
            "Forma curta completa: genset Nome where Filha1, Filha2 specializes ClasseMae.");
        genset_definir_forma(true);
        genset_finalizar(false, (yylsp[0]).last_line);
    }
#line 2661 "parser.tab.cpp"
    break;

  case 155: /* corpo_genset: clausula_specifics clausula_general  */
#line 621 "parser.y"
                                          {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Ordem invertida: 'specifics' declarado antes de 'general'.",
            "Declare primeiro a classe-mãe e depois as filhas: { general Mae specifics Filha1, Filha2 }.");
    }
#line 2671 "parser.tab.cpp"
    break;

  case 156: /* corpo_genset: clausula_general clausula_categorizer_opt  */
#line 626 "parser.y"
                                                {
        registrar_erro((yylsp[-1]).first_line, (yylsp[-1]).first_column, contexto_enum_genset(),
            "Generalization set sem a cláusula 'specifics'.",
            "Liste as classes filhas: specifics Filha1, Filha2.");
    }
#line 2681 "parser.tab.cpp"
    break;

  case 157: /* corpo_genset: clausula_specifics  */
#line 631 "parser.y"
                         {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Generalization set sem a cláusula 'general'.",
            "Informe a classe-mãe antes das filhas: general ClasseMae.");
    }
#line 2691 "parser.tab.cpp"
    break;

  case 158: /* corpo_genset: %empty  */
#line 636 "parser.y"
             {
        registrar_erro((yyloc).first_line, (yyloc).first_column, contexto_enum_genset(),
            "Generalization set com corpo vazio.",
            "Preencha o bloco: { general ClasseMae specifics Filha1, Filha2 }.");
    }
#line 2701 "parser.tab.cpp"
    break;

  case 159: /* clausula_general: GENERAL ref_classe  */
#line 644 "parser.y"
                       { genset_definir_geral((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2707 "parser.tab.cpp"
    break;

  case 160: /* clausula_general: GENERAL  */
#line 645 "parser.y"
              {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "'general' sem a classe geral.",
            "Informe a classe-mãe: general ClasseMae.");
    }
#line 2717 "parser.tab.cpp"
    break;

  case 162: /* clausula_categorizer_opt: CATEGORIZER ref_classe  */
#line 654 "parser.y"
                             { genset_definir_categorizador((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2723 "parser.tab.cpp"
    break;

  case 165: /* clausula_specifics: SPECIFICS  */
#line 660 "parser.y"
                {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "'specifics' sem nenhuma classe específica.",
            "Liste as classes filhas separadas por vírgula: specifics Filha1, Filha2.");
    }
#line 2733 "parser.tab.cpp"
    break;

  case 166: /* lista_especificas: ref_classe  */
#line 668 "parser.y"
               { genset_adicionar_especifica((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2739 "parser.tab.cpp"
    break;

  case 167: /* lista_especificas: lista_especificas VIRGULA ref_classe  */
#line 669 "parser.y"
                                           {
        consumir_separador_invalido();
        genset_adicionar_especifica((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2748 "parser.tab.cpp"
    break;

  case 168: /* lista_especificas: lista_especificas ref_classe  */
#line 673 "parser.y"
                                   {
        if (!consumir_separador_invalido() && *(yyvsp[0].str))
            registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
                string("Falta vírgula antes de '") + (yyvsp[0].str) + "'.",
                "Separe as classes específicas por vírgula: Filha1, Filha2.");
        if (*(yyvsp[0].str) == '\0') separador_invalido_pendente = true;
        genset_adicionar_especifica((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2761 "parser.tab.cpp"
    break;

  case 169: /* virgula_sobrando: VIRGULA  */
#line 684 "parser.y"
                                   {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Vírgula sobrando após a última classe específica.",
            "Remova a vírgula final da lista.");
    }
#line 2771 "parser.tab.cpp"
    break;

  case 170: /* ref_classe: CLASSE  */
#line 694 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2777 "parser.tab.cpp"
    break;

  case 171: /* ref_classe: RELACOES  */
#line 695 "parser.y"
               {
        string ctx = contexto_enum_genset();
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, ctx.empty() ? "Genset" : ctx,
            string("'") + (yyvsp[0].str) + "' não é um nome de classe válido (inicia com minúscula).",
            "Nomes de classe iniciam com letra maiúscula: '" + capitalizar((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2789 "parser.tab.cpp"
    break;

  case 172: /* ref_classe: INSTANCIA  */
#line 702 "parser.y"
                {
        string ctx = contexto_enum_genset();
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, ctx.empty() ? "Genset" : ctx,
            string("'") + (yyvsp[0].str) + "' não é um nome de classe válido (contém números).",
            "Nomes de classe não têm números; se for uma classe, use '" + remover_digitos((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2801 "parser.tab.cpp"
    break;

  case 173: /* ref_classe: INVALIDO  */
#line 709 "parser.y"
               {
        string ctx = contexto_enum_genset();
        if (eh_simbolo_solto((yyvsp[0].str))) {
            registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, ctx.empty() ? "Genset" : ctx,
                string("Símbolo '") + (yyvsp[0].str) + "' não é um separador válido entre classes.",
                "Use vírgula para separar as classes: Filha1, Filha2.");
            (yyval.str) = strdup("");
        } else {
            registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, ctx.empty() ? "Genset" : ctx,
                string("'") + (yyvsp[0].str) + "' não é um nome de classe válido: " + motivo_lexema_invalido((yyvsp[0].str)) + ".",
                "Use letras e sublinhado, com inicial maiúscula: '" +
                capitalizar(sanitizar_identificador((yyvsp[0].str))) + "'.");
            (yyval.str) = (yyvsp[0].str);
        }
    }
#line 2821 "parser.tab.cpp"
    break;


#line 2825 "parser.tab.cpp"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken, &yylloc};
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        if (yyreport_syntax_error (&yyctx) == 2)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);

  return yyresult;
}

#line 726 "parser.y"


/* ======================================================================== */
/*  Relatório de erros sintáticos                                           */
/* ======================================================================== */

/* Descrição legível de cada token, usada nas mensagens de erro. */
static string descrever_token(yysymbol_kind_t t) {
    switch (t) {
        case YYSYMBOL_YYEOF:               return "fim do arquivo";
        case YYSYMBOL_PACKAGE:             return "'package'";
        case YYSYMBOL_DATATYPE:            return "'datatype'";
        case YYSYMBOL_DOIS_PONTOS:         return "':'";
        case YYSYMBOL_BARRA:               return "'/'";
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
        case YYSYMBOL_ABRE_COLCHETE:  return "'['";
        case YYSYMBOL_FECHA_COLCHETE: return "']'";
        case YYSYMBOL_PONTOS:         return "'..'";
        case YYSYMBOL_ASTERISCO:      return "'*'";
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
        inesperado == YYSYMBOL_PACKAGE || inesperado == YYSYMBOL_DATATYPE || inesperado == YYSYMBOL_ESTEREOTIPO_CLASSE;

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
