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

#line 103 "parser.tab.cpp"

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
  YYSYMBOL_ESTEREOTIPO_RELACAO = 5,        /* ESTEREOTIPO_RELACAO  */
  YYSYMBOL_CLASSE = 6,                     /* CLASSE  */
  YYSYMBOL_ID_ATRIBUTO = 7,                /* ID_ATRIBUTO  */
  YYSYMBOL_DADOS_CRIADOS = 8,              /* DADOS_CRIADOS  */
  YYSYMBOL_RELACOES = 9,                   /* RELACOES  */
  YYSYMBOL_INSTANCIA = 10,                 /* INSTANCIA  */
  YYSYMBOL_NUMERO = 11,                    /* NUMERO  */
  YYSYMBOL_ESTEREOTIPO_CLASSE = 12,        /* ESTEREOTIPO_CLASSE  */
  YYSYMBOL_PALAVRA_RESERVADA = 13,         /* PALAVRA_RESERVADA  */
  YYSYMBOL_DADOS_NATIVOS = 14,             /* DADOS_NATIVOS  */
  YYSYMBOL_META_ATRIBUTOS = 15,            /* META_ATRIBUTOS  */
  YYSYMBOL_ERRO_DATATYPE = 16,             /* ERRO_DATATYPE  */
  YYSYMBOL_SIMBOLO_ESPECIAL = 17,          /* SIMBOLO_ESPECIAL  */
  YYSYMBOL_INVALIDO_CLASSE = 18,           /* INVALIDO_CLASSE  */
  YYSYMBOL_INVALIDO = 19,                  /* INVALIDO  */
  YYSYMBOL_ENUM = 20,                      /* ENUM  */
  YYSYMBOL_GENSET = 21,                    /* GENSET  */
  YYSYMBOL_DISJOINT = 22,                  /* DISJOINT  */
  YYSYMBOL_OVERLAPPING = 23,               /* OVERLAPPING  */
  YYSYMBOL_COMPLETE = 24,                  /* COMPLETE  */
  YYSYMBOL_INCOMPLETE = 25,                /* INCOMPLETE  */
  YYSYMBOL_GENERAL = 26,                   /* GENERAL  */
  YYSYMBOL_SPECIFICS = 27,                 /* SPECIFICS  */
  YYSYMBOL_CATEGORIZER = 28,               /* CATEGORIZER  */
  YYSYMBOL_WHERE = 29,                     /* WHERE  */
  YYSYMBOL_SPECIALIZES = 30,               /* SPECIALIZES  */
  YYSYMBOL_ABRE_CHAVE = 31,                /* ABRE_CHAVE  */
  YYSYMBOL_FECHA_CHAVE = 32,               /* FECHA_CHAVE  */
  YYSYMBOL_VIRGULA = 33,                   /* VIRGULA  */
  YYSYMBOL_REDUZ_INCOMPLETO = 34,          /* REDUZ_INCOMPLETO  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_programa = 36,                  /* programa  */
  YYSYMBOL_declaracoes_pacotes = 37,       /* declaracoes_pacotes  */
  YYSYMBOL_declaracao_pacote = 38,         /* declaracao_pacote  */
  YYSYMBOL_corpo_programa = 39,            /* corpo_programa  */
  YYSYMBOL_elemento = 40,                  /* elemento  */
  YYSYMBOL_cardinalidade = 41,             /* cardinalidade  */
  YYSYMBOL_declaracao_relacao_externa = 42, /* declaracao_relacao_externa  */
  YYSYMBOL_declaracao_relacao_interna = 43, /* declaracao_relacao_interna  */
  YYSYMBOL_token_invalido = 44,            /* token_invalido  */
  YYSYMBOL_declaracao_enum = 45,           /* declaracao_enum  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_nome_enum = 47,                 /* nome_enum  */
  YYSYMBOL_especializacao_enum_opt = 48,   /* especializacao_enum_opt  */
  YYSYMBOL_lista_especializacao_enum = 49, /* lista_especializacao_enum  */
  YYSYMBOL_corpo_enum = 50,                /* corpo_enum  */
  YYSYMBOL_literais_enum_opt = 51,         /* literais_enum_opt  */
  YYSYMBOL_lista_literais_enum = 52,       /* lista_literais_enum  */
  YYSYMBOL_literal_enum = 53,              /* literal_enum  */
  YYSYMBOL_declaracao_genset = 54,         /* declaracao_genset  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_modificadores_genset = 56,      /* modificadores_genset  */
  YYSYMBOL_modificador_genset = 57,        /* modificador_genset  */
  YYSYMBOL_nome_genset = 58,               /* nome_genset  */
  YYSYMBOL_resto_genset = 59,              /* resto_genset  */
  YYSYMBOL_corpo_genset = 60,              /* corpo_genset  */
  YYSYMBOL_clausula_general = 61,          /* clausula_general  */
  YYSYMBOL_clausula_categorizer_opt = 62,  /* clausula_categorizer_opt  */
  YYSYMBOL_clausula_specifics = 63,        /* clausula_specifics  */
  YYSYMBOL_lista_especificas = 64,         /* lista_especificas  */
  YYSYMBOL_virgula_sobrando = 65,          /* virgula_sobrando  */
  YYSYMBOL_ref_classe = 66                 /* ref_classe  */
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
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   547

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    73,    74,    78,    79,    83,    84,    91,
      92,    96,    97,    98,    99,   100,   101,   109,   110,   111,
     112,   113,   118,   124,   132,   132,   132,   132,   132,   132,
     133,   133,   133,   133,   133,   134,   134,   134,   134,   135,
     135,   139,   139,   139,   139,   140,   140,   140,   140,   152,
     152,   157,   158,   165,   172,   179,   186,   194,   196,   197,
     205,   206,   212,   214,   216,   219,   221,   222,   230,   231,
     235,   249,   250,   251,   259,   265,   271,   304,   304,   311,
     312,   343,   344,   345,   346,   350,   351,   357,   364,   370,
     380,   381,   382,   384,   389,   394,   401,   408,   418,   419,
     424,   429,   434,   442,   443,   450,   452,   456,   457,   458,
     466,   467,   471,   482,   492,   493,   500,   507
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
  "ESTEREOTIPO_RELACAO", "CLASSE", "ID_ATRIBUTO", "DADOS_CRIADOS",
  "RELACOES", "INSTANCIA", "NUMERO", "ESTEREOTIPO_CLASSE",
  "PALAVRA_RESERVADA", "DADOS_NATIVOS", "META_ATRIBUTOS", "ERRO_DATATYPE",
  "SIMBOLO_ESPECIAL", "INVALIDO_CLASSE", "INVALIDO", "ENUM", "GENSET",
  "DISJOINT", "OVERLAPPING", "COMPLETE", "INCOMPLETE", "GENERAL",
  "SPECIFICS", "CATEGORIZER", "WHERE", "SPECIALIZES", "ABRE_CHAVE",
  "FECHA_CHAVE", "VIRGULA", "REDUZ_INCOMPLETO", "$accept", "programa",
  "declaracoes_pacotes", "declaracao_pacote", "corpo_programa", "elemento",
  "cardinalidade", "declaracao_relacao_externa",
  "declaracao_relacao_interna", "token_invalido", "declaracao_enum", "$@1",
  "nome_enum", "especializacao_enum_opt", "lista_especializacao_enum",
  "corpo_enum", "literais_enum_opt", "lista_literais_enum", "literal_enum",
  "declaracao_genset", "$@2", "modificadores_genset", "modificador_genset",
  "nome_genset", "resto_genset", "corpo_genset", "clausula_general",
  "clausula_categorizer_opt", "clausula_specifics", "lista_especificas",
  "virgula_sobrando", "ref_classe", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-81)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-114)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     441,   -81,    68,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   102,   -81,   -81,    19,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,    35,   136,
     -81,   170,   -81,   -81,   -81,   -81,   -81,   -81,   461,   -81,
     -81,     2,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     204,   -81,   -81,   510,   -81,   -81,   -81,   -81,   -81,    38,
      -3,    39,   466,   -81,   -81,   -81,   -81,   -81,    45,    47,
      53,    45,   516,    73,   458,   121,    37,    15,   166,   -81,
     -81,   -81,   -81,   460,   -81,     1,   -81,    36,     4,   -81,
     197,   223,   257,   291,   -81,    36,   238,   -81,   -81,   -81,
     -81,   -81,   -81,   310,     7,   -81,   272,   -81,   306,   471,
     505,   344,    33,    21,   393,   -81,   -81,   -81,   -81,   -81,
     -81,   498,   -81,   340,   374,   408,   -81,   -81,   -81,   469,
     -81,    36,    31,   -81,    45,   -81,   -81,   -81,    36,   -81,
     -81,   -81,   437,   -81,   -81
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    16,     0,    25,    40,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,    38,    39,     0,
      45,    46,    47,    48,    41,    42,    43,    44,     0,     0,
       6,     0,    10,    11,    12,    15,    13,    14,     0,     7,
       8,     0,    51,    54,    52,    53,    55,    49,     1,     5,
       0,    24,     9,     0,    81,    82,    83,    84,    80,     0,
       0,     0,     0,    85,    86,    87,    88,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,     0,    60,     0,    50,     0,     0,    78,
       0,     0,     0,     0,    23,     0,     0,    71,    75,    73,
      72,    74,    76,     0,     0,    68,     0,   110,     0,     0,
       0,     0,     0,     0,     0,    20,    19,    21,    61,    63,
      62,     0,    70,     0,     0,     0,   112,    91,   103,     0,
      90,     0,     0,    99,     0,    69,    93,   111,     0,   108,
     106,    98,     0,    94,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,   -81,   447,   463,   -28,   -67,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -80,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   381,   -81,   368,   395,
     383,   -72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    28,    29,    30,    31,    32,    61,    33,    34,    35,
      36,    62,    47,    73,    83,    86,   103,   104,   105,    37,
      74,    38,    58,    67,    89,   111,   112,   132,   113,   106,
     125,   107
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      84,    75,    96,    52,    78,   108,    59,    97,    69,    98,
      99,   100,   101,    97,    70,    98,    99,   100,   101,    60,
     102,   -18,    52,   118,   122,    42,   102,    43,    44,    45,
     109,   110,    93,   -65,   126,    48,  -102,   128,    46,   -66,
     121,   135,    79,   -17,    68,    80,    81,   109,    91,   -56,
     -56,   136,   137,  -101,    92,    82,    71,   126,   110,   140,
    -105,   131,    60,  -100,    76,  -105,   143,   142,   -24,   -24,
      77,   -24,   -24,   -24,    39,    40,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -37,   -37,    85,   -37,   -37,    41,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,    -2,     1,    90,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   -79,   -79,   -79,
     -79,   -79,    20,    21,    22,    23,    24,    25,    26,    27,
      -4,     1,    94,    51,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   -79,   -79,   -79,   -79,   -79,    20,    21,    22,    23,
      24,    25,    26,    27,    -3,     1,   114,    51,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   -79,   -79,   -79,   -79,   -79,
      20,    21,    22,    23,    24,    25,    26,    27,   -64,   -64,
     115,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     119,   -64,   -97,   -97,   116,   -97,   -97,   -97,    79,   -97,
     -97,    80,    81,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,    82,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   123,   -97,   -97,   124,   -92,   -92,   117,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   127,   -92,
     -96,   -96,   120,   -96,   -96,   -96,    79,   -96,   -96,    80,
      81,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,    82,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,  -113,  -113,   130,  -113,  -113,  -113,
      79,  -113,  -113,    80,    81,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,    82,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,   -95,   -95,
     134,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   138,   -95,
     -95,   -95,     1,   144,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   -79,   -79,   -79,   -79,   -79,    20,    21,    22,
      23,    24,    25,    26,    27,    79,    49,    79,    80,    81,
      80,    81,    53,    54,    55,    56,    57,    87,    82,    88,
      82,   -58,    50,    95,   133,  -107,    72,   -57,  -104,  -104,
     141,  -107,   124,  -104,    97,   129,    98,    99,   100,   101,
       0,    79,   139,     0,    80,    81,    63,   102,     0,    64,
      65,     0,    79,     0,    82,    80,    81,     0,     0,    66,
     -67,  -109,     0,     0,     0,    82,     0,  -109,     0,   -89,
       0,   -89,     0,     0,     0,     0,     0,   -59
};

static const yytype_int16 yycheck[] =
{
      72,    68,     1,    31,    71,     1,     4,     6,    11,     8,
       9,    10,    11,     6,    17,     8,     9,    10,    11,    17,
      19,     6,    50,    95,   104,     6,    19,     8,     9,    10,
      26,    27,    17,    32,   106,     0,    32,   109,    19,    32,
      33,   121,     6,     6,     6,     9,    10,    26,    11,    30,
      31,   123,   124,    32,    17,    19,    17,   129,    27,   131,
      27,    28,    17,    32,    17,    32,   138,   134,     0,     1,
      17,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,     1,    31,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,     1,    17,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,     1,     6,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     1,     9,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,     1,
      17,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,     1,    17,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,     1,    17,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,     1,    32,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     1,    32,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,     1,
      17,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     1,     6,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     6,    29,     6,     9,    10,
       9,    10,    21,    22,    23,    24,    25,    29,    19,    31,
      19,    31,    29,    33,   113,    26,    30,    31,    27,    28,
     132,    32,    33,    32,     6,   110,     8,     9,    10,    11,
      -1,     6,   129,    -1,     9,    10,     6,    19,    -1,     9,
      10,    -1,     6,    -1,    19,     9,    10,    -1,    -1,    19,
      32,    26,    -1,    -1,    -1,    19,    -1,    32,    -1,    29,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      26,    27,    28,    29,    30,    31,    32,    33,    36,    37,
      38,    39,    40,    42,    43,    44,    45,    54,    56,     6,
       7,     5,     6,     8,     9,    10,    19,    47,     0,    38,
      39,     3,    40,    21,    22,    23,    24,    25,    57,     4,
      17,    41,    46,     6,     9,    10,    19,    58,     6,    11,
      17,    17,    30,    48,    55,    41,    17,    17,    41,     6,
       9,    10,    19,    49,    66,    31,    50,    29,    31,    59,
      17,    11,    17,    17,     6,    33,     1,     6,     8,     9,
      10,    11,    19,    51,    52,    53,    64,    66,     1,    26,
      27,    60,    61,    63,     9,    17,    17,    17,    66,    32,
      32,    33,    53,    30,    33,    65,    66,    32,    66,    64,
      32,    28,    62,    61,    17,    53,    66,    66,    30,    65,
      66,    63,    41,    66,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    36,    37,    37,    38,    38,    39,
      39,    40,    40,    40,    40,    40,    40,    41,    41,    41,
      41,    41,    42,    43,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    46,
      45,    47,    47,    47,    47,    47,    47,    48,    48,    48,
      49,    49,    50,    50,    50,    51,    51,    51,    52,    52,
      52,    53,    53,    53,    53,    53,    53,    55,    54,    56,
      56,    57,    57,    57,    57,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    63,    63,    63,
      64,    64,    64,    65,    66,    66,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     5,
       5,     5,    10,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     1,     1,     1,     1,     1,     0,     0,     2,     1,
       1,     3,     3,     3,     2,     0,     1,     2,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     0,     5,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     3,     2,     4,     5,     3,     3,     2,     3,     2,
       2,     1,     0,     2,     1,     0,     2,     2,     3,     1,
       1,     3,     2,     1,     1,     1,     1,     1
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
#line 83 "parser.y"
                   { inserir_simbolo((yyvsp[0].str), "Pacote", yylineno); definir_pacote_atual((yyvsp[0].str)); }
#line 1768 "parser.tab.cpp"
    break;

  case 8: /* declaracao_pacote: PACKAGE ID_ATRIBUTO  */
#line 84 "parser.y"
                          { inserir_simbolo((yyvsp[0].str), "Pacote", yylineno); definir_pacote_atual((yyvsp[0].str)); }
#line 1774 "parser.tab.cpp"
    break;

  case 16: /* elemento: error  */
#line 101 "parser.y"
            {
        enum_genset_recuperar_erro();   /* [Tópicos 4/5] fecha enum/genset interrompido */
        yyerrok;
    }
#line 1783 "parser.tab.cpp"
    break;

  case 22: /* declaracao_relacao_externa: SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO RELATION CLASSE cardinalidade SIMBOLO_ESPECIAL RELACOES SIMBOLO_ESPECIAL cardinalidade CLASSE  */
#line 118 "parser.y"
                                                                                                                                       {
        inserir_simbolo((yyvsp[-3].str), "Relação Externa", yylineno);
    }
#line 1791 "parser.tab.cpp"
    break;

  case 23: /* declaracao_relacao_interna: SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO cardinalidade SIMBOLO_ESPECIAL cardinalidade CLASSE  */
#line 124 "parser.y"
                                                                                             {
        string identificador = string("Interna_") + (yyvsp[-4].str) + "_para_" + (yyvsp[0].str) + "_L" + to_string(yylineno);
        inserir_simbolo(identificador, "Relação Interna", yylineno);
    }
#line 1800 "parser.tab.cpp"
    break;

  case 49: /* $@1: %empty  */
#line 152 "parser.y"
                   { enum_iniciar((yyvsp[0].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 1806 "parser.tab.cpp"
    break;

  case 51: /* nome_enum: CLASSE  */
#line 157 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1812 "parser.tab.cpp"
    break;

  case 52: /* nome_enum: RELACOES  */
#line 158 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Enum",
            string("Nome de enum '") + (yyvsp[0].str) + "' inicia com letra minúscula.",
            "Classes enumeradas seguem a convenção de nomes de classe (inicial maiúscula): '" +
            capitalizar((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 1824 "parser.tab.cpp"
    break;

  case 53: /* nome_enum: INSTANCIA  */
#line 165 "parser.y"
                {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Enum",
            string("Nome de enum '") + (yyvsp[0].str) + "' contém números.",
            "Nomes terminados em número são reservados a instâncias; use '" +
            remover_digitos((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 1836 "parser.tab.cpp"
    break;

  case 54: /* nome_enum: DADOS_CRIADOS  */
#line 172 "parser.y"
                    {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Enum",
            string("Nome de enum '") + (yyvsp[0].str) + "' usa o sufixo 'DataType'.",
            "O sufixo DataType é exclusivo de novos tipos de dados (datatype). Para um enum, use um "
            "nome de classe, ex.: '" + string((yyvsp[0].str)).substr(0, strlen((yyvsp[0].str)) - 8) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 1848 "parser.tab.cpp"
    break;

  case 55: /* nome_enum: INVALIDO  */
#line 179 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Enum",
            string("Nome de enum '") + (yyvsp[0].str) + "' " + motivo_lexema_invalido((yyvsp[0].str)) + ".",
            "Use apenas letras e sublinhado, com inicial maiúscula: '" +
            capitalizar(sanitizar_identificador((yyvsp[0].str))) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 1860 "parser.tab.cpp"
    break;

  case 56: /* nome_enum: %empty  */
#line 186 "parser.y"
                  {
        registrar_erro((yyloc).first_line, (yyloc).first_column, "Enum",
            "Declaração de enum sem nome.",
            "Informe o nome logo após 'enum': enum NomeDoEnum { Literal1, Literal2 }.");
        (yyval.str) = strdup("");
    }
#line 1871 "parser.tab.cpp"
    break;

  case 59: /* especializacao_enum_opt: SPECIALIZES  */
#line 197 "parser.y"
                  {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "'specializes' sem o tipo especializado.",
            "Informe o tipo pai: enum Nome specializes TipoPai { ... }, ou remova 'specializes'.");
    }
#line 1881 "parser.tab.cpp"
    break;

  case 60: /* lista_especializacao_enum: ref_classe  */
#line 205 "parser.y"
               { enum_adicionar_especializacao((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 1887 "parser.tab.cpp"
    break;

  case 61: /* lista_especializacao_enum: lista_especializacao_enum VIRGULA ref_classe  */
#line 206 "parser.y"
                                                   {
        enum_adicionar_especializacao((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 1895 "parser.tab.cpp"
    break;

  case 62: /* corpo_enum: ABRE_CHAVE literais_enum_opt FECHA_CHAVE  */
#line 212 "parser.y"
                                             { enum_finalizar(false, (yylsp[0]).first_line); }
#line 1901 "parser.tab.cpp"
    break;

  case 63: /* corpo_enum: ABRE_CHAVE error FECHA_CHAVE  */
#line 214 "parser.y"
                                             { enum_finalizar(true, (yylsp[0]).first_line); yyerrok; }
#line 1907 "parser.tab.cpp"
    break;

  case 64: /* corpo_enum: ABRE_CHAVE error  */
#line 216 "parser.y"
                                              { enum_finalizar(true, (yylsp[0]).last_line); yyerrok; }
#line 1913 "parser.tab.cpp"
    break;

  case 67: /* literais_enum_opt: lista_literais_enum VIRGULA  */
#line 222 "parser.y"
                                  {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Vírgula sobrando após o último literal.",
            "Remova a vírgula antes de '}'.");
    }
#line 1923 "parser.tab.cpp"
    break;

  case 68: /* lista_literais_enum: literal_enum  */
#line 230 "parser.y"
                 { enum_adicionar_literal((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 1929 "parser.tab.cpp"
    break;

  case 69: /* lista_literais_enum: lista_literais_enum VIRGULA literal_enum  */
#line 231 "parser.y"
                                               {
        consumir_separador_invalido();
        enum_adicionar_literal((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 1938 "parser.tab.cpp"
    break;

  case 70: /* lista_literais_enum: lista_literais_enum literal_enum  */
#line 235 "parser.y"
                                       {
        if (!consumir_separador_invalido() && *(yyvsp[0].str))
            registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
                string("Falta vírgula antes do literal '") + (yyvsp[0].str) + "'.",
                "Separe os literais do enum por vírgula: Literal1, Literal2.");
        if (*(yyvsp[0].str) == '\0') separador_invalido_pendente = true;
        enum_adicionar_literal((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 1951 "parser.tab.cpp"
    break;

  case 71: /* literal_enum: CLASSE  */
#line 249 "parser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 1957 "parser.tab.cpp"
    break;

  case 72: /* literal_enum: INSTANCIA  */
#line 250 "parser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 1963 "parser.tab.cpp"
    break;

  case 73: /* literal_enum: RELACOES  */
#line 251 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            string("Literal '") + (yyvsp[0].str) + "' inicia com letra minúscula.",
            "Literais de enum iniciam com maiúscula (ex.: '" + capitalizar((yyvsp[0].str)) +
            "') ou seguem a convenção de instância terminando em número (ex.: '" +
            capitalizar((yyvsp[0].str)) + "01').");
        (yyval.str) = (yyvsp[0].str);
    }
#line 1976 "parser.tab.cpp"
    break;

  case 74: /* literal_enum: NUMERO  */
#line 259 "parser.y"
             {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            string("Literal '") + (yyvsp[0].str) + "' é apenas um número.",
            string("Um literal precisa de um nome iniciado por letra, ex.: 'Valor") + (yyvsp[0].str) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 1987 "parser.tab.cpp"
    break;

  case 75: /* literal_enum: DADOS_CRIADOS  */
#line 265 "parser.y"
                    {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            string("Literal '") + (yyvsp[0].str) + "' usa o sufixo 'DataType'.",
            "Literais são instâncias, não tipos; remova o sufixo DataType.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 1998 "parser.tab.cpp"
    break;

  case 76: /* literal_enum: INVALIDO  */
#line 271 "parser.y"
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
#line 2017 "parser.tab.cpp"
    break;

  case 77: /* $@2: %empty  */
#line 304 "parser.y"
                                            {
        genset_iniciar((yyvsp[0].str), (yyvsp[-2].num), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2025 "parser.tab.cpp"
    break;

  case 79: /* modificadores_genset: %empty  */
#line 311 "parser.y"
                { (yyval.num) = 0; }
#line 2031 "parser.tab.cpp"
    break;

  case 80: /* modificadores_genset: modificadores_genset modificador_genset  */
#line 312 "parser.y"
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
#line 2064 "parser.tab.cpp"
    break;

  case 81: /* modificador_genset: DISJOINT  */
#line 343 "parser.y"
                  { (yyval.num) = MOD_DISJOINT; }
#line 2070 "parser.tab.cpp"
    break;

  case 82: /* modificador_genset: OVERLAPPING  */
#line 344 "parser.y"
                  { (yyval.num) = MOD_OVERLAPPING; }
#line 2076 "parser.tab.cpp"
    break;

  case 83: /* modificador_genset: COMPLETE  */
#line 345 "parser.y"
                  { (yyval.num) = MOD_COMPLETE; }
#line 2082 "parser.tab.cpp"
    break;

  case 84: /* modificador_genset: INCOMPLETE  */
#line 346 "parser.y"
                  { (yyval.num) = MOD_INCOMPLETE; }
#line 2088 "parser.tab.cpp"
    break;

  case 85: /* nome_genset: CLASSE  */
#line 350 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2094 "parser.tab.cpp"
    break;

  case 86: /* nome_genset: RELACOES  */
#line 351 "parser.y"
               {
        registrar_aviso((yylsp[0]).first_line, (yylsp[0]).first_column, "Genset",
            string("Nome de genset '") + (yyvsp[0].str) + "' inicia com letra minúscula.",
            "Por consistência com os nomes de classe, prefira '" + capitalizar((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2105 "parser.tab.cpp"
    break;

  case 87: /* nome_genset: INSTANCIA  */
#line 357 "parser.y"
                {
        registrar_aviso((yylsp[0]).first_line, (yylsp[0]).first_column, "Genset",
            string("Nome de genset '") + (yyvsp[0].str) + "' termina com número (convenção de instâncias).",
            "Prefira um nome que descreva o aspecto da classificação, ex.: '" +
            remover_digitos((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2117 "parser.tab.cpp"
    break;

  case 88: /* nome_genset: INVALIDO  */
#line 364 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Genset",
            string("Nome de genset '") + (yyvsp[0].str) + "' " + motivo_lexema_invalido((yyvsp[0].str)) + ".",
            "Use letras e sublinhado: '" + capitalizar(sanitizar_identificador((yyvsp[0].str))) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2128 "parser.tab.cpp"
    break;

  case 89: /* nome_genset: %empty  */
#line 370 "parser.y"
                  {
        registrar_erro((yyloc).first_line, (yyloc).first_column, "Genset",
            "Generalization set sem nome.",
            "Informe o nome logo após 'genset': genset NomeDoGenset { ... }.");
        (yyval.str) = strdup("");
    }
#line 2139 "parser.tab.cpp"
    break;

  case 90: /* resto_genset: ABRE_CHAVE corpo_genset FECHA_CHAVE  */
#line 380 "parser.y"
                                        { genset_definir_forma(false); genset_finalizar(false, (yylsp[0]).first_line); }
#line 2145 "parser.tab.cpp"
    break;

  case 91: /* resto_genset: ABRE_CHAVE error FECHA_CHAVE  */
#line 381 "parser.y"
                                        { genset_definir_forma(false); genset_finalizar(true, (yylsp[0]).first_line); yyerrok; }
#line 2151 "parser.tab.cpp"
    break;

  case 92: /* resto_genset: ABRE_CHAVE error  */
#line 382 "parser.y"
                                              { genset_definir_forma(false); genset_finalizar(true, (yylsp[0]).last_line); yyerrok; }
#line 2157 "parser.tab.cpp"
    break;

  case 93: /* resto_genset: WHERE lista_especificas SPECIALIZES ref_classe  */
#line 384 "parser.y"
                                                     {
        genset_definir_forma(true);
        genset_definir_geral((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
        genset_finalizar(false, (yylsp[0]).first_line);
    }
#line 2167 "parser.tab.cpp"
    break;

  case 94: /* resto_genset: WHERE lista_especificas virgula_sobrando SPECIALIZES ref_classe  */
#line 389 "parser.y"
                                                                      {
        genset_definir_forma(true);
        genset_definir_geral((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
        genset_finalizar(false, (yylsp[0]).first_line);
    }
#line 2177 "parser.tab.cpp"
    break;

  case 95: /* resto_genset: WHERE lista_especificas virgula_sobrando  */
#line 394 "parser.y"
                                                                      {
        registrar_erro((yylsp[0]).last_line, (yylsp[0]).last_column, contexto_enum_genset(),
            "Falta 'specializes <ClasseGeral>' ao final da forma curta.",
            "Forma curta completa: genset Nome where Filha1, Filha2 specializes ClasseMae.");
        genset_definir_forma(true);
        genset_finalizar(false, (yylsp[0]).last_line);
    }
#line 2189 "parser.tab.cpp"
    break;

  case 96: /* resto_genset: WHERE lista_especificas SPECIALIZES  */
#line 401 "parser.y"
                                                                 {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Falta a classe geral após 'specializes'.",
            "Complete com a classe-mãe: ... where Filha1, Filha2 specializes ClasseMae.");
        genset_definir_forma(true);
        genset_finalizar(false, (yylsp[0]).first_line);
    }
#line 2201 "parser.tab.cpp"
    break;

  case 97: /* resto_genset: WHERE lista_especificas  */
#line 408 "parser.y"
                                                     {
        registrar_erro((yylsp[0]).last_line, (yylsp[0]).last_column, contexto_enum_genset(),
            "Falta 'specializes <ClasseGeral>' ao final da forma curta.",
            "Forma curta completa: genset Nome where Filha1, Filha2 specializes ClasseMae.");
        genset_definir_forma(true);
        genset_finalizar(false, (yylsp[0]).last_line);
    }
#line 2213 "parser.tab.cpp"
    break;

  case 99: /* corpo_genset: clausula_specifics clausula_general  */
#line 419 "parser.y"
                                          {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Ordem invertida: 'specifics' declarado antes de 'general'.",
            "Declare primeiro a classe-mãe e depois as filhas: { general Mae specifics Filha1, Filha2 }.");
    }
#line 2223 "parser.tab.cpp"
    break;

  case 100: /* corpo_genset: clausula_general clausula_categorizer_opt  */
#line 424 "parser.y"
                                                {
        registrar_erro((yylsp[-1]).first_line, (yylsp[-1]).first_column, contexto_enum_genset(),
            "Generalization set sem a cláusula 'specifics'.",
            "Liste as classes filhas: specifics Filha1, Filha2.");
    }
#line 2233 "parser.tab.cpp"
    break;

  case 101: /* corpo_genset: clausula_specifics  */
#line 429 "parser.y"
                         {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Generalization set sem a cláusula 'general'.",
            "Informe a classe-mãe antes das filhas: general ClasseMae.");
    }
#line 2243 "parser.tab.cpp"
    break;

  case 102: /* corpo_genset: %empty  */
#line 434 "parser.y"
                  {
        registrar_erro((yyloc).first_line, (yyloc).first_column, contexto_enum_genset(),
            "Generalization set com corpo vazio.",
            "Preencha o bloco: { general ClasseMae specifics Filha1, Filha2 }.");
    }
#line 2253 "parser.tab.cpp"
    break;

  case 103: /* clausula_general: GENERAL ref_classe  */
#line 442 "parser.y"
                       { genset_definir_geral((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2259 "parser.tab.cpp"
    break;

  case 104: /* clausula_general: GENERAL  */
#line 443 "parser.y"
              {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "'general' sem a classe geral.",
            "Informe a classe-mãe: general ClasseMae.");
    }
#line 2269 "parser.tab.cpp"
    break;

  case 106: /* clausula_categorizer_opt: CATEGORIZER ref_classe  */
#line 452 "parser.y"
                             { genset_definir_categorizador((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2275 "parser.tab.cpp"
    break;

  case 109: /* clausula_specifics: SPECIFICS  */
#line 458 "parser.y"
                {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "'specifics' sem nenhuma classe específica.",
            "Liste as classes filhas separadas por vírgula: specifics Filha1, Filha2.");
    }
#line 2285 "parser.tab.cpp"
    break;

  case 110: /* lista_especificas: ref_classe  */
#line 466 "parser.y"
               { genset_adicionar_especifica((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2291 "parser.tab.cpp"
    break;

  case 111: /* lista_especificas: lista_especificas VIRGULA ref_classe  */
#line 467 "parser.y"
                                           {
        consumir_separador_invalido();
        genset_adicionar_especifica((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2300 "parser.tab.cpp"
    break;

  case 112: /* lista_especificas: lista_especificas ref_classe  */
#line 471 "parser.y"
                                   {
        if (!consumir_separador_invalido() && *(yyvsp[0].str))
            registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
                string("Falta vírgula antes de '") + (yyvsp[0].str) + "'.",
                "Separe as classes específicas por vírgula: Filha1, Filha2.");
        if (*(yyvsp[0].str) == '\0') separador_invalido_pendente = true;
        genset_adicionar_especifica((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2313 "parser.tab.cpp"
    break;

  case 113: /* virgula_sobrando: VIRGULA  */
#line 482 "parser.y"
                                   {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Vírgula sobrando após a última classe específica.",
            "Remova a vírgula final da lista.");
    }
#line 2323 "parser.tab.cpp"
    break;

  case 114: /* ref_classe: CLASSE  */
#line 492 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2329 "parser.tab.cpp"
    break;

  case 115: /* ref_classe: RELACOES  */
#line 493 "parser.y"
               {
        string ctx = contexto_enum_genset();
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, ctx.empty() ? "Genset" : ctx,
            string("'") + (yyvsp[0].str) + "' não é um nome de classe válido (inicia com minúscula).",
            "Nomes de classe iniciam com letra maiúscula: '" + capitalizar((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2341 "parser.tab.cpp"
    break;

  case 116: /* ref_classe: INSTANCIA  */
#line 500 "parser.y"
                {
        string ctx = contexto_enum_genset();
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, ctx.empty() ? "Genset" : ctx,
            string("'") + (yyvsp[0].str) + "' não é um nome de classe válido (contém números).",
            "Nomes de classe não têm números; se for uma classe, use '" + remover_digitos((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2353 "parser.tab.cpp"
    break;

  case 117: /* ref_classe: INVALIDO  */
#line 507 "parser.y"
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
#line 2373 "parser.tab.cpp"
    break;


#line 2377 "parser.tab.cpp"

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

#line 524 "parser.y"


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
