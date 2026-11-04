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
  YYSYMBOL_ENUM = 23,                      /* ENUM  */
  YYSYMBOL_GENSET = 24,                    /* GENSET  */
  YYSYMBOL_DISJOINT = 25,                  /* DISJOINT  */
  YYSYMBOL_OVERLAPPING = 26,               /* OVERLAPPING  */
  YYSYMBOL_COMPLETE = 27,                  /* COMPLETE  */
  YYSYMBOL_INCOMPLETE = 28,                /* INCOMPLETE  */
  YYSYMBOL_GENERAL = 29,                   /* GENERAL  */
  YYSYMBOL_SPECIFICS = 30,                 /* SPECIFICS  */
  YYSYMBOL_CATEGORIZER = 31,               /* CATEGORIZER  */
  YYSYMBOL_WHERE = 32,                     /* WHERE  */
  YYSYMBOL_SPECIALIZES = 33,               /* SPECIALIZES  */
  YYSYMBOL_ABRE_CHAVE = 34,                /* ABRE_CHAVE  */
  YYSYMBOL_FECHA_CHAVE = 35,               /* FECHA_CHAVE  */
  YYSYMBOL_VIRGULA = 36,                   /* VIRGULA  */
  YYSYMBOL_REDUZ_INCOMPLETO = 37,          /* REDUZ_INCOMPLETO  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_programa = 39,                  /* programa  */
  YYSYMBOL_declaracoes_pacotes = 40,       /* declaracoes_pacotes  */
  YYSYMBOL_declaracao_pacote = 41,         /* declaracao_pacote  */
  YYSYMBOL_corpo_programa = 42,            /* corpo_programa  */
  YYSYMBOL_elemento = 43,                  /* elemento  */
  YYSYMBOL_cardinalidade = 44,             /* cardinalidade  */
  YYSYMBOL_declaracao_relacao_externa = 45, /* declaracao_relacao_externa  */
  YYSYMBOL_declaracao_relacao_interna = 46, /* declaracao_relacao_interna  */
  YYSYMBOL_token_invalido = 47,            /* token_invalido  */
  YYSYMBOL_declaracao_classe = 48,         /* declaracao_classe  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_nome_classe_decl = 50,          /* nome_classe_decl  */
  YYSYMBOL_especializacao_classe_opt = 51, /* especializacao_classe_opt  */
  YYSYMBOL_lista_especializacoes_classe = 52, /* lista_especializacoes_classe  */
  YYSYMBOL_corpo_classe_opt = 53,          /* corpo_classe_opt  */
  YYSYMBOL_membros_classe_opt = 54,        /* membros_classe_opt  */
  YYSYMBOL_membros_classe = 55,            /* membros_classe  */
  YYSYMBOL_membro_classe = 56,             /* membro_classe  */
  YYSYMBOL_atributo_classe = 57,           /* atributo_classe  */
  YYSYMBOL_nome_atributo = 58,             /* nome_atributo  */
  YYSYMBOL_tipo_atributo = 59,             /* tipo_atributo  */
  YYSYMBOL_meta_atributo_prefix_opt = 60,  /* meta_atributo_prefix_opt  */
  YYSYMBOL_meta_atributo_opt = 61,         /* meta_atributo_opt  */
  YYSYMBOL_cardinalidade_opt = 62,         /* cardinalidade_opt  */
  YYSYMBOL_declaracao_datatype = 63,       /* declaracao_datatype  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_nome_datatype = 67,             /* nome_datatype  */
  YYSYMBOL_membros_datatype_opt = 68,      /* membros_datatype_opt  */
  YYSYMBOL_membros_datatype = 69,          /* membros_datatype  */
  YYSYMBOL_atributo_datatype = 70,         /* atributo_datatype  */
  YYSYMBOL_relacao_interna = 71,           /* relacao_interna  */
  YYSYMBOL_declaracao_enum = 72,           /* declaracao_enum  */
  YYSYMBOL_73_5 = 73,                      /* $@5  */
  YYSYMBOL_nome_enum = 74,                 /* nome_enum  */
  YYSYMBOL_especializacao_enum_opt = 75,   /* especializacao_enum_opt  */
  YYSYMBOL_lista_especializacao_enum = 76, /* lista_especializacao_enum  */
  YYSYMBOL_corpo_enum = 77,                /* corpo_enum  */
  YYSYMBOL_literais_enum_opt = 78,         /* literais_enum_opt  */
  YYSYMBOL_lista_literais_enum = 79,       /* lista_literais_enum  */
  YYSYMBOL_literal_enum = 80,              /* literal_enum  */
  YYSYMBOL_declaracao_genset = 81,         /* declaracao_genset  */
  YYSYMBOL_82_6 = 82,                      /* $@6  */
  YYSYMBOL_modificadores_genset = 83,      /* modificadores_genset  */
  YYSYMBOL_modificador_genset = 84,        /* modificador_genset  */
  YYSYMBOL_nome_genset = 85,               /* nome_genset  */
  YYSYMBOL_resto_genset = 86,              /* resto_genset  */
  YYSYMBOL_corpo_genset = 87,              /* corpo_genset  */
  YYSYMBOL_clausula_general = 88,          /* clausula_general  */
  YYSYMBOL_clausula_categorizer_opt = 89,  /* clausula_categorizer_opt  */
  YYSYMBOL_clausula_specifics = 90,        /* clausula_specifics  */
  YYSYMBOL_lista_especificas = 91,         /* lista_especificas  */
  YYSYMBOL_virgula_sobrando = 92,          /* virgula_sobrando  */
  YYSYMBOL_ref_classe = 93                 /* ref_classe  */
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
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   906

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    75,    76,    80,    81,    85,    86,    93,
      94,    98,    99,   100,   101,   102,   103,   104,   105,   113,
     114,   115,   116,   117,   122,   128,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   134,   134,   134,   134,   134,
     135,   135,   135,   135,   136,   136,   140,   140,   140,   140,
     141,   141,   141,   141,   153,   153,   160,   161,   167,   173,
     181,   183,   184,   192,   193,   200,   201,   204,   208,   214,
     216,   220,   221,   225,   226,   230,   237,   238,   242,   243,
     244,   245,   254,   255,   259,   260,   263,   265,   276,   276,
     282,   282,   289,   289,   298,   299,   300,   308,   310,   314,
     315,   319,   326,   342,   342,   347,   348,   355,   362,   369,
     376,   384,   386,   387,   395,   396,   402,   404,   406,   409,
     411,   412,   420,   421,   425,   439,   440,   441,   449,   455,
     461,   494,   494,   501,   502,   533,   534,   535,   536,   540,
     541,   547,   554,   560,   570,   571,   572,   574,   579,   584,
     591,   598,   608,   609,   614,   619,   624,   632,   633,   640,
     642,   646,   647,   648,   656,   657,   661,   672,   682,   683,
     690,   697
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
  "INVALIDO_CLASSE", "INVALIDO", "ENUM", "GENSET", "DISJOINT",
  "OVERLAPPING", "COMPLETE", "INCOMPLETE", "GENERAL", "SPECIFICS",
  "CATEGORIZER", "WHERE", "SPECIALIZES", "ABRE_CHAVE", "FECHA_CHAVE",
  "VIRGULA", "REDUZ_INCOMPLETO", "$accept", "programa",
  "declaracoes_pacotes", "declaracao_pacote", "corpo_programa", "elemento",
  "cardinalidade", "declaracao_relacao_externa",
  "declaracao_relacao_interna", "token_invalido", "declaracao_classe",
  "$@1", "nome_classe_decl", "especializacao_classe_opt",
  "lista_especializacoes_classe", "corpo_classe_opt", "membros_classe_opt",
  "membros_classe", "membro_classe", "atributo_classe", "nome_atributo",
  "tipo_atributo", "meta_atributo_prefix_opt", "meta_atributo_opt",
  "cardinalidade_opt", "declaracao_datatype", "$@2", "$@3", "$@4",
  "nome_datatype", "membros_datatype_opt", "membros_datatype",
  "atributo_datatype", "relacao_interna", "declaracao_enum", "$@5",
  "nome_enum", "especializacao_enum_opt", "lista_especializacao_enum",
  "corpo_enum", "literais_enum_opt", "lista_literais_enum", "literal_enum",
  "declaracao_genset", "$@6", "modificadores_genset", "modificador_genset",
  "nome_genset", "resto_genset", "corpo_genset", "clausula_general",
  "clausula_categorizer_opt", "clausula_specifics", "lista_especificas",
  "virgula_sobrando", "ref_classe", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-168)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     748,  -109,     4,  -109,   120,  -109,  -109,  -109,   157,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,   194,
    -109,  -109,   847,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,     2,   231,  -109,   268,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,    88,  -109,  -109,  -109,  -109,  -109,
     -28,  -109,  -109,  -109,  -109,  -109,    48,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,   305,  -109,  -109,   857,  -109,
    -109,  -109,  -109,  -109,    13,    26,    43,   342,    38,    77,
      60,    33,  -109,  -109,  -109,  -109,  -109,   855,    82,    99,
     379,   416,    84,    98,   139,    84,   863,   162,    85,  -109,
    -109,   227,   235,   871,  -109,   272,  -109,  -109,   453,    58,
    -109,   324,    74,   778,   371,  -109,  -109,  -109,  -109,   766,
    -109,    41,  -109,    89,    44,  -109,   876,  -109,  -109,  -109,
     408,   490,   438,   484,   494,    75,  -109,  -109,   818,  -109,
     553,   583,   620,   657,  -109,    89,   527,  -109,  -109,  -109,
    -109,  -109,  -109,   679,   797,  -109,   564,  -109,   601,   814,
     829,   715,    27,    14,  -109,  -109,  -109,  -109,   803,  -109,
    -109,  -109,    84,  -109,  -109,   780,   767,  -109,  -109,  -109,
    -109,  -109,  -109,   840,  -109,   638,   675,   712,  -109,  -109,
    -109,   812,  -109,    89,    71,  -109,   775,   852,   876,    84,
    -109,  -109,  -109,    89,  -109,  -109,  -109,   760,  -109,  -109,
     783,   791,  -109,  -109,   786,  -109,  -109
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,     0,    27,     0,    29,    30,    45,     0,    31,
      32,    33,    34,    35,    36,    39,    40,    38,    41,     0,
      43,    44,     0,    50,    51,    52,    53,    46,    47,    48,
      49,     0,     0,     6,     0,    10,    11,    12,    17,    15,
      16,    25,    13,    14,     0,     7,     8,    94,    95,    96,
       0,    56,    57,    58,    59,    54,     0,   105,   108,   106,
     107,   109,   103,     1,     5,     0,    26,     9,     0,   135,
     136,   137,   138,   134,     0,     0,     0,     0,     0,     0,
       0,     0,   139,   140,   141,   142,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
      77,     0,     0,     0,    99,     0,    93,    63,     0,     0,
      55,     0,     0,     0,     0,   168,   169,   170,   171,     0,
     114,     0,   104,     0,     0,   132,     0,    89,   100,    91,
       0,     0,     0,     0,     0,     0,    71,    73,     0,    74,
       0,     0,     0,     0,   102,     0,     0,   125,   129,   127,
     126,   128,   130,     0,     0,   122,     0,   164,     0,     0,
       0,     0,     0,     0,    79,    80,    78,    81,     0,    64,
      67,    83,     0,    66,    72,     0,     0,    22,    21,    23,
     115,   117,   116,     0,   124,     0,     0,     0,   166,   145,
     157,     0,   144,     0,     0,   153,     0,     0,     0,     0,
     123,   147,   165,     0,   162,   160,   152,     0,    87,   101,
       0,     0,   148,    85,     0,    24,    75
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,   772,   773,     7,   -92,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,   673,  -109,
     677,   622,  -109,   625,   616,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,   737,   -65,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -108,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
     683,  -109,   662,   714,   687,   -95
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    31,    32,    33,    34,    35,    80,    36,    37,    38,
      39,    77,    55,    91,   108,   110,   134,   135,   136,   137,
     101,   168,   138,   197,   209,    40,    74,    75,    76,    50,
     102,   103,   104,    41,    42,    81,    62,    97,   119,   122,
     153,   154,   155,    43,    98,    44,    73,    86,   125,   161,
     162,   194,   163,   156,   187,   157
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     111,   120,    63,   114,   -26,   -26,   -88,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,    45,    46,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,    67,   146,   159,   139,   158,   184,    87,    92,  -155,
     180,   147,    78,   148,   149,   150,   151,  -159,   193,   131,
      88,   188,  -159,   152,   190,   132,    96,  -111,    79,   -82,
     139,   -82,    67,   159,   160,   200,  -119,    89,   133,  -156,
      95,   -19,   132,   105,   -19,   -19,   -82,   -19,   -82,   141,
     201,   202,    93,   -69,   142,   133,   188,    94,   205,   115,
     106,   160,   116,   117,    79,   208,  -154,   211,   212,   -19,
     -70,   118,    68,    69,    70,    71,    72,   123,   112,   124,
     -28,   -28,   208,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
      47,   -28,    48,   -28,   -28,   -28,   -28,   -28,   -28,    49,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -37,   -37,   113,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,    51,   -37,   -37,
      52,    53,   -37,   -37,   -37,   -37,   -37,   -37,   -37,    54,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -42,   -42,   121,   -42,   -42,   -42,
     -42,   -42,    56,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,    -2,     1,   126,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,  -133,  -133,  -133,  -133,  -133,
      23,    24,    25,    26,    27,    28,    29,    30,    -4,     1,
     127,    66,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,  -133,  -133,  -133,  -133,  -133,    23,    24,    25,
      26,    27,    28,    29,    30,    -3,     1,   129,    66,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,  -133,
    -133,  -133,  -133,  -133,    23,    24,    25,    26,    27,    28,
      29,    30,   -60,   -60,   140,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,    90,   -60,   -60,   -60,   -62,
     -62,   144,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   107,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -65,   -65,   169,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     109,   -65,   -65,   -61,   -61,   171,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   130,
     -68,   -68,   172,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   170,   -68,  -118,  -118,   173,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,   181,  -118,  -151,  -151,   176,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,   115,  -151,  -151,   116,   117,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,   118,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,   185,  -151,  -151,
     186,  -146,  -146,   177,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,   189,  -146,  -150,  -150,
     178,  -150,  -150,  -150,  -150,  -150,  -150,  -150,   115,  -150,
    -150,   116,   117,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
     118,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -167,  -167,   179,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,   115,  -167,  -167,   116,   117,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,   118,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -149,  -149,   182,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,   203,  -149,  -149,  -149,     1,
     192,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,  -133,  -133,  -133,  -133,  -133,    23,    24,    25,
      26,    27,    28,    29,    30,   -20,   198,   199,   -20,   -20,
     -84,   -20,   207,   -86,   -84,   213,   -84,   -86,   143,   -86,
    -112,   215,   145,   -84,    64,    65,    79,   147,   174,   148,
     149,   150,   151,   -20,   -84,   175,   -84,   196,   -84,   152,
     210,   -86,   115,   -84,   115,   116,   117,   116,   117,    99,
     216,   100,  -120,   183,   118,   214,   118,   196,   -84,   115,
     128,  -161,   116,   117,  -158,  -158,   195,  -161,   186,  -158,
     147,   118,   148,   149,   150,   151,   206,    57,  -163,    58,
      59,    60,   152,   -86,  -163,   -86,    99,    82,   100,    61,
      83,    84,    79,   115,   191,  -121,   116,   117,   204,    85,
    -110,  -110,    99,     0,   100,   118,   164,   -86,   165,  -143,
     -97,  -143,   166,     0,     0,   167,     0,  -113,     0,     0,
       0,     0,     0,     0,     0,     0,   -98
};

static const yytype_int16 yycheck[] =
{
      92,    96,     0,    95,     0,     1,    34,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    34,     1,    29,   109,     1,   154,    34,    10,    35,
     145,    10,     4,    12,    13,    14,    15,    30,    31,     1,
      34,   156,    35,    22,   159,     7,    33,    34,    20,    11,
     135,    13,    65,    29,    30,   183,    35,    34,    20,    35,
      20,     7,     7,     1,    10,    11,    11,    13,    13,    15,
     185,   186,    15,    35,    20,    20,   191,    20,   193,    10,
       1,    30,    13,    14,    20,   197,    35,   199,   203,    35,
      35,    22,    24,    25,    26,    27,    28,    32,    20,    34,
       0,     1,   214,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     1,    20,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     1,    34,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     1,     6,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     1,
      35,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     0,     1,    35,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     1,    20,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     0,
       1,    10,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     1,    10,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     1,    17,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     1,     8,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     1,    35,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     1,    13,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     1,    20,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     1,
      20,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     0,     1,    20,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     1,    35,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     1,
      35,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     7,     6,    20,    10,    11,
       7,    13,    17,     7,    11,    35,    13,    11,    20,    13,
      34,    10,    36,    20,    32,    32,    20,    10,   135,    12,
      13,    14,    15,    35,    11,   138,    13,    34,    35,    22,
     198,    35,    10,    20,    10,    13,    14,    13,    14,    11,
     214,    13,    35,    36,    22,   210,    22,    34,    35,    10,
     103,    29,    13,    14,    30,    31,   163,    35,    36,    35,
      10,    22,    12,    13,    14,    15,   194,    10,    29,    12,
      13,    14,    22,    11,    35,    13,    11,    10,    13,    22,
      13,    14,    20,    10,   160,    35,    13,    14,   191,    22,
      33,    34,    11,    -1,    13,    22,    10,    35,    12,    32,
      35,    34,    16,    -1,    -1,    19,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    29,    30,    31,    32,    33,    34,    35,
      36,    39,    40,    41,    42,    43,    45,    46,    47,    48,
      63,    71,    72,    81,    83,    10,    11,    10,    12,    19,
      67,    10,    13,    14,    22,    50,     8,    10,    12,    13,
      14,    22,    74,     0,    41,    42,     3,    43,    24,    25,
      26,    27,    28,    84,    64,    65,    66,    49,     4,    20,
      44,    73,    10,    13,    14,    22,    85,    34,    34,    34,
      33,    51,    10,    15,    20,    20,    33,    75,    82,    11,
      13,    58,    68,    69,    70,     1,     1,    10,    52,    34,
      53,    44,    20,    20,    44,    10,    13,    14,    22,    76,
      93,    34,    77,    32,    34,    86,     6,    35,    70,    35,
      36,     1,     7,    20,    54,    55,    56,    57,    60,    71,
      20,    15,    20,    20,    10,    36,     1,    10,    12,    13,
      14,    15,    22,    78,    79,    80,    91,    93,     1,    29,
      30,    87,    88,    90,    10,    12,    16,    19,    59,    10,
      35,    17,     8,    35,    56,    58,    13,    20,    20,    20,
      93,    35,    35,    36,    80,    33,    36,    92,    93,    35,
      93,    91,    35,    31,    89,    88,    34,    61,     6,    20,
      80,    93,    93,    33,    92,    93,    90,    17,    44,    62,
      59,    44,    93,    35,    61,    10,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    43,    43,    43,    43,    43,    43,    43,    44,
      44,    44,    44,    44,    45,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    49,    48,    50,    50,    50,    50,
      51,    51,    51,    52,    52,    53,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    58,    58,    59,    59,
      59,    59,    60,    60,    61,    61,    62,    62,    64,    63,
      65,    63,    66,    63,    67,    67,    67,    68,    68,    69,
      69,    70,    71,    73,    72,    74,    74,    74,    74,    74,
      74,    75,    75,    75,    76,    76,    77,    77,    77,    78,
      78,    78,    79,    79,    79,    80,    80,    80,    80,    80,
      80,    82,    81,    83,    83,    84,    84,    84,    84,    85,
      85,    85,    85,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    87,    87,    87,    87,    88,    88,    89,
      89,    90,    90,    90,    91,    91,    91,    92,    93,    93,
      93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     5,     5,     5,    10,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     1,     1,     1,     1,
       0,     2,     1,     1,     3,     0,     3,     3,     2,     0,
       1,     1,     2,     1,     1,     6,     1,     1,     1,     1,
       1,     1,     0,     2,     0,     3,     0,     1,     0,     6,
       0,     6,     0,     5,     1,     1,     1,     0,     1,     1,
       2,     5,     6,     0,     5,     1,     1,     1,     1,     1,
       0,     0,     2,     1,     1,     3,     3,     3,     2,     0,
       1,     2,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     0,     5,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     3,     2,     4,     5,     3,
       3,     2,     3,     2,     2,     1,     0,     2,     1,     0,
       2,     2,     3,     1,     1,     3,     2,     1,     1,     1,
       1,     1
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
#line 85 "parser.y"
                   { inserir_simbolo((yyvsp[0].str), "Pacote", yylineno); definir_pacote_atual((yyvsp[0].str)); }
#line 1920 "parser.tab.cpp"
    break;

  case 8: /* declaracao_pacote: PACKAGE ID_ATRIBUTO  */
#line 86 "parser.y"
                          { inserir_simbolo((yyvsp[0].str), "Pacote", yylineno); definir_pacote_atual((yyvsp[0].str)); }
#line 1926 "parser.tab.cpp"
    break;

  case 18: /* elemento: error  */
#line 105 "parser.y"
            {
        enum_genset_recuperar_erro();   /* [Tópicos 4/5] fecha enum/genset interrompido */
        yyerrok;
    }
#line 1935 "parser.tab.cpp"
    break;

  case 24: /* declaracao_relacao_externa: SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO RELATION CLASSE cardinalidade SIMBOLO_ESPECIAL RELACOES SIMBOLO_ESPECIAL cardinalidade CLASSE  */
#line 122 "parser.y"
                                                                                                                                       {
        inserir_simbolo((yyvsp[-3].str), "Relação Externa", yylineno);
    }
#line 1943 "parser.tab.cpp"
    break;

  case 54: /* $@1: %empty  */
#line 153 "parser.y"
                                        {
        classe_iniciar((yyvsp[-1].str), (yyvsp[0].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 1951 "parser.tab.cpp"
    break;

  case 56: /* nome_classe_decl: CLASSE  */
#line 160 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 1957 "parser.tab.cpp"
    break;

  case 57: /* nome_classe_decl: RELACOES  */
#line 161 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Classe",
            string("Nome de classe '") + (yyvsp[0].str) + "' inicia com letra minúscula.",
            "Nomes de classe iniciam com maiúscula: '" + capitalizar((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 1968 "parser.tab.cpp"
    break;

  case 58: /* nome_classe_decl: INSTANCIA  */
#line 167 "parser.y"
                {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Classe",
            string("Nome de classe '") + (yyvsp[0].str) + "' contém números.",
            "Remova os números do nome da classe: '" + remover_digitos((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 1979 "parser.tab.cpp"
    break;

  case 59: /* nome_classe_decl: INVALIDO  */
#line 173 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Classe",
            string("Nome de classe '") + (yyvsp[0].str) + "' " + motivo_lexema_invalido((yyvsp[0].str)) + ".",
            "Use letras e sublinhado, com inicial maiúscula.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 1990 "parser.tab.cpp"
    break;

  case 62: /* especializacao_classe_opt: SPECIALIZES  */
#line 184 "parser.y"
                  {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Classe",
            "'specializes' sem classe especializada.",
            "Informe a classe-mãe: phase Child specializes Person.");
    }
#line 2000 "parser.tab.cpp"
    break;

  case 63: /* lista_especializacoes_classe: CLASSE  */
#line 192 "parser.y"
           { classe_adicionar_especializacao((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2006 "parser.tab.cpp"
    break;

  case 64: /* lista_especializacoes_classe: lista_especializacoes_classe VIRGULA CLASSE  */
#line 193 "parser.y"
                                                  {
        classe_adicionar_especializacao((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2014 "parser.tab.cpp"
    break;

  case 65: /* corpo_classe_opt: %empty  */
#line 200 "parser.y"
           { classe_finalizar(false, (yyloc).last_line); }
#line 2020 "parser.tab.cpp"
    break;

  case 66: /* corpo_classe_opt: ABRE_CHAVE membros_classe_opt FECHA_CHAVE  */
#line 201 "parser.y"
                                                {
        classe_finalizar(false, (yylsp[0]).last_line);
    }
#line 2028 "parser.tab.cpp"
    break;

  case 67: /* corpo_classe_opt: ABRE_CHAVE error FECHA_CHAVE  */
#line 204 "parser.y"
                                   {
        classe_finalizar(true, (yylsp[0]).last_line);
        yyerrok;
    }
#line 2037 "parser.tab.cpp"
    break;

  case 68: /* corpo_classe_opt: ABRE_CHAVE error  */
#line 208 "parser.y"
                                              {
        classe_finalizar(true, (yylsp[0]).last_line);
        yyerrok;
    }
#line 2046 "parser.tab.cpp"
    break;

  case 75: /* atributo_classe: meta_atributo_prefix_opt nome_atributo DOIS_PONTOS tipo_atributo meta_atributo_opt cardinalidade_opt  */
#line 230 "parser.y"
                                                                                                         {
        string meta = ((yyvsp[-5].str) && *(yyvsp[-5].str)) ? string((yyvsp[-5].str)) : string((yyvsp[-1].str) ? (yyvsp[-1].str) : "");
        classe_adicionar_atributo((yyvsp[-4].str), (yyvsp[-2].str), meta.c_str(), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2055 "parser.tab.cpp"
    break;

  case 76: /* nome_atributo: ID_ATRIBUTO  */
#line 237 "parser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 2061 "parser.tab.cpp"
    break;

  case 77: /* nome_atributo: RELACOES  */
#line 238 "parser.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 2067 "parser.tab.cpp"
    break;

  case 78: /* tipo_atributo: DADOS_NATIVOS  */
#line 242 "parser.y"
                  { (yyval.str) = (yyvsp[0].str); }
#line 2073 "parser.tab.cpp"
    break;

  case 79: /* tipo_atributo: CLASSE  */
#line 243 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 2079 "parser.tab.cpp"
    break;

  case 80: /* tipo_atributo: DADOS_CRIADOS  */
#line 244 "parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2085 "parser.tab.cpp"
    break;

  case 81: /* tipo_atributo: ERRO_DATATYPE  */
#line 245 "parser.y"
                    {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "DataType",
            string("Tipo de dado '") + (yyvsp[0].str) + "' utiliza capitalização incorreta do sufixo DataType.",
            "Utilize o sufixo exato 'DataType' ou declare o tipo com a palavra-chave datatype.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2096 "parser.tab.cpp"
    break;

  case 82: /* meta_atributo_prefix_opt: %empty  */
#line 254 "parser.y"
                { (yyval.str) = strdup(""); }
#line 2102 "parser.tab.cpp"
    break;

  case 83: /* meta_atributo_prefix_opt: BARRA META_ATRIBUTOS  */
#line 255 "parser.y"
                           { (yyval.str) = (yyvsp[0].str); }
#line 2108 "parser.tab.cpp"
    break;

  case 84: /* meta_atributo_opt: %empty  */
#line 259 "parser.y"
                { (yyval.str) = strdup(""); }
#line 2114 "parser.tab.cpp"
    break;

  case 85: /* meta_atributo_opt: ABRE_CHAVE META_ATRIBUTOS FECHA_CHAVE  */
#line 260 "parser.y"
                                            { (yyval.str) = (yyvsp[-1].str); }
#line 2120 "parser.tab.cpp"
    break;

  case 88: /* $@2: %empty  */
#line 276 "parser.y"
                           {
        datatype_iniciar((yyvsp[0].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2128 "parser.tab.cpp"
    break;

  case 89: /* declaracao_datatype: DATATYPE nome_datatype $@2 ABRE_CHAVE membros_datatype_opt FECHA_CHAVE  */
#line 279 "parser.y"
                                                {
        datatype_finalizar(false, (yylsp[0]).last_line);
    }
#line 2136 "parser.tab.cpp"
    break;

  case 90: /* $@3: %empty  */
#line 282 "parser.y"
                             {
        datatype_iniciar((yyvsp[0].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2144 "parser.tab.cpp"
    break;

  case 91: /* declaracao_datatype: DATATYPE nome_datatype $@3 ABRE_CHAVE error FECHA_CHAVE  */
#line 285 "parser.y"
                                 {
        datatype_finalizar(true, (yylsp[0]).last_line);
        yyerrok;
    }
#line 2153 "parser.tab.cpp"
    break;

  case 92: /* $@4: %empty  */
#line 289 "parser.y"
                             {
        datatype_iniciar((yyvsp[0].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2161 "parser.tab.cpp"
    break;

  case 93: /* declaracao_datatype: DATATYPE nome_datatype $@4 ABRE_CHAVE error  */
#line 292 "parser.y"
                                            {
        datatype_finalizar(true, (yylsp[0]).last_line);
        yyerrok;
    }
#line 2170 "parser.tab.cpp"
    break;

  case 94: /* nome_datatype: CLASSE  */
#line 298 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2176 "parser.tab.cpp"
    break;

  case 95: /* nome_datatype: DADOS_CRIADOS  */
#line 299 "parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 2182 "parser.tab.cpp"
    break;

  case 96: /* nome_datatype: ERRO_DATATYPE  */
#line 300 "parser.y"
                    {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "DataType",
            string("Nome de tipo de dado '") + (yyvsp[0].str) + "' utiliza capitalização incorreta do sufixo.",
            "Quando utilizar o sufixo, escreva exatamente 'DataType' (D e T maiúsculos).");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2193 "parser.tab.cpp"
    break;

  case 101: /* atributo_datatype: nome_atributo DOIS_PONTOS tipo_atributo meta_atributo_opt cardinalidade_opt  */
#line 319 "parser.y"
                                                                                {
        datatype_adicionar_atributo((yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[-1].str), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2201 "parser.tab.cpp"
    break;

  case 102: /* relacao_interna: SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO cardinalidade SIMBOLO_ESPECIAL cardinalidade CLASSE  */
#line 326 "parser.y"
                                                                                             {
        string identificador = string("Interna_") + (yyvsp[-4].str) + "_para_" + (yyvsp[0].str) + "_L" + to_string((yylsp[-5]).first_line);
        inserir_simbolo(identificador, "Relação Interna", (yylsp[-5]).first_line);
        classe_adicionar_relacao_interna((yylsp[-5]).first_line);
    }
#line 2211 "parser.tab.cpp"
    break;

  case 103: /* $@5: %empty  */
#line 342 "parser.y"
                   { enum_iniciar((yyvsp[0].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column); }
#line 2217 "parser.tab.cpp"
    break;

  case 105: /* nome_enum: CLASSE  */
#line 347 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 2223 "parser.tab.cpp"
    break;

  case 106: /* nome_enum: RELACOES  */
#line 348 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Enum",
            string("Nome de enum '") + (yyvsp[0].str) + "' inicia com letra minúscula.",
            "Classes enumeradas seguem a convenção de nomes de classe (inicial maiúscula): '" +
            capitalizar((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2235 "parser.tab.cpp"
    break;

  case 107: /* nome_enum: INSTANCIA  */
#line 355 "parser.y"
                {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Enum",
            string("Nome de enum '") + (yyvsp[0].str) + "' contém números.",
            "Nomes terminados em número são reservados a instâncias; use '" +
            remover_digitos((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2247 "parser.tab.cpp"
    break;

  case 108: /* nome_enum: DADOS_CRIADOS  */
#line 362 "parser.y"
                    {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Enum",
            string("Nome de enum '") + (yyvsp[0].str) + "' usa o sufixo 'DataType'.",
            "O sufixo DataType é exclusivo de novos tipos de dados (datatype). Para um enum, use um "
            "nome de classe, ex.: '" + string((yyvsp[0].str)).substr(0, strlen((yyvsp[0].str)) - 8) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2259 "parser.tab.cpp"
    break;

  case 109: /* nome_enum: INVALIDO  */
#line 369 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Enum",
            string("Nome de enum '") + (yyvsp[0].str) + "' " + motivo_lexema_invalido((yyvsp[0].str)) + ".",
            "Use apenas letras e sublinhado, com inicial maiúscula: '" +
            capitalizar(sanitizar_identificador((yyvsp[0].str))) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2271 "parser.tab.cpp"
    break;

  case 110: /* nome_enum: %empty  */
#line 376 "parser.y"
                  {
        registrar_erro((yyloc).first_line, (yyloc).first_column, "Enum",
            "Declaração de enum sem nome.",
            "Informe o nome logo após 'enum': enum NomeDoEnum { Literal1, Literal2 }.");
        (yyval.str) = strdup("");
    }
#line 2282 "parser.tab.cpp"
    break;

  case 113: /* especializacao_enum_opt: SPECIALIZES  */
#line 387 "parser.y"
                  {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "'specializes' sem o tipo especializado.",
            "Informe o tipo pai: enum Nome specializes TipoPai { ... }, ou remova 'specializes'.");
    }
#line 2292 "parser.tab.cpp"
    break;

  case 114: /* lista_especializacao_enum: ref_classe  */
#line 395 "parser.y"
               { enum_adicionar_especializacao((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2298 "parser.tab.cpp"
    break;

  case 115: /* lista_especializacao_enum: lista_especializacao_enum VIRGULA ref_classe  */
#line 396 "parser.y"
                                                   {
        enum_adicionar_especializacao((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2306 "parser.tab.cpp"
    break;

  case 116: /* corpo_enum: ABRE_CHAVE literais_enum_opt FECHA_CHAVE  */
#line 402 "parser.y"
                                             { enum_finalizar(false, (yylsp[0]).first_line); }
#line 2312 "parser.tab.cpp"
    break;

  case 117: /* corpo_enum: ABRE_CHAVE error FECHA_CHAVE  */
#line 404 "parser.y"
                                             { enum_finalizar(true, (yylsp[0]).first_line); yyerrok; }
#line 2318 "parser.tab.cpp"
    break;

  case 118: /* corpo_enum: ABRE_CHAVE error  */
#line 406 "parser.y"
                                              { enum_finalizar(true, (yylsp[0]).last_line); yyerrok; }
#line 2324 "parser.tab.cpp"
    break;

  case 121: /* literais_enum_opt: lista_literais_enum VIRGULA  */
#line 412 "parser.y"
                                  {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Vírgula sobrando após o último literal.",
            "Remova a vírgula antes de '}'.");
    }
#line 2334 "parser.tab.cpp"
    break;

  case 122: /* lista_literais_enum: literal_enum  */
#line 420 "parser.y"
                 { enum_adicionar_literal((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2340 "parser.tab.cpp"
    break;

  case 123: /* lista_literais_enum: lista_literais_enum VIRGULA literal_enum  */
#line 421 "parser.y"
                                               {
        consumir_separador_invalido();
        enum_adicionar_literal((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2349 "parser.tab.cpp"
    break;

  case 124: /* lista_literais_enum: lista_literais_enum literal_enum  */
#line 425 "parser.y"
                                       {
        if (!consumir_separador_invalido() && *(yyvsp[0].str))
            registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
                string("Falta vírgula antes do literal '") + (yyvsp[0].str) + "'.",
                "Separe os literais do enum por vírgula: Literal1, Literal2.");
        if (*(yyvsp[0].str) == '\0') separador_invalido_pendente = true;
        enum_adicionar_literal((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2362 "parser.tab.cpp"
    break;

  case 125: /* literal_enum: CLASSE  */
#line 439 "parser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 2368 "parser.tab.cpp"
    break;

  case 126: /* literal_enum: INSTANCIA  */
#line 440 "parser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 2374 "parser.tab.cpp"
    break;

  case 127: /* literal_enum: RELACOES  */
#line 441 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            string("Literal '") + (yyvsp[0].str) + "' inicia com letra minúscula.",
            "Literais de enum iniciam com maiúscula (ex.: '" + capitalizar((yyvsp[0].str)) +
            "') ou seguem a convenção de instância terminando em número (ex.: '" +
            capitalizar((yyvsp[0].str)) + "01').");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2387 "parser.tab.cpp"
    break;

  case 128: /* literal_enum: NUMERO  */
#line 449 "parser.y"
             {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            string("Literal '") + (yyvsp[0].str) + "' é apenas um número.",
            string("Um literal precisa de um nome iniciado por letra, ex.: 'Valor") + (yyvsp[0].str) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2398 "parser.tab.cpp"
    break;

  case 129: /* literal_enum: DADOS_CRIADOS  */
#line 455 "parser.y"
                    {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            string("Literal '") + (yyvsp[0].str) + "' usa o sufixo 'DataType'.",
            "Literais são instâncias, não tipos; remova o sufixo DataType.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2409 "parser.tab.cpp"
    break;

  case 130: /* literal_enum: INVALIDO  */
#line 461 "parser.y"
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
#line 2428 "parser.tab.cpp"
    break;

  case 131: /* $@6: %empty  */
#line 494 "parser.y"
                                            {
        genset_iniciar((yyvsp[0].str), (yyvsp[-2].num), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2436 "parser.tab.cpp"
    break;

  case 133: /* modificadores_genset: %empty  */
#line 501 "parser.y"
                { (yyval.num) = 0; }
#line 2442 "parser.tab.cpp"
    break;

  case 134: /* modificadores_genset: modificadores_genset modificador_genset  */
#line 502 "parser.y"
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
#line 2475 "parser.tab.cpp"
    break;

  case 135: /* modificador_genset: DISJOINT  */
#line 533 "parser.y"
                  { (yyval.num) = MOD_DISJOINT; }
#line 2481 "parser.tab.cpp"
    break;

  case 136: /* modificador_genset: OVERLAPPING  */
#line 534 "parser.y"
                  { (yyval.num) = MOD_OVERLAPPING; }
#line 2487 "parser.tab.cpp"
    break;

  case 137: /* modificador_genset: COMPLETE  */
#line 535 "parser.y"
                  { (yyval.num) = MOD_COMPLETE; }
#line 2493 "parser.tab.cpp"
    break;

  case 138: /* modificador_genset: INCOMPLETE  */
#line 536 "parser.y"
                  { (yyval.num) = MOD_INCOMPLETE; }
#line 2499 "parser.tab.cpp"
    break;

  case 139: /* nome_genset: CLASSE  */
#line 540 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2505 "parser.tab.cpp"
    break;

  case 140: /* nome_genset: RELACOES  */
#line 541 "parser.y"
               {
        registrar_aviso((yylsp[0]).first_line, (yylsp[0]).first_column, "Genset",
            string("Nome de genset '") + (yyvsp[0].str) + "' inicia com letra minúscula.",
            "Por consistência com os nomes de classe, prefira '" + capitalizar((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2516 "parser.tab.cpp"
    break;

  case 141: /* nome_genset: INSTANCIA  */
#line 547 "parser.y"
                {
        registrar_aviso((yylsp[0]).first_line, (yylsp[0]).first_column, "Genset",
            string("Nome de genset '") + (yyvsp[0].str) + "' termina com número (convenção de instâncias).",
            "Prefira um nome que descreva o aspecto da classificação, ex.: '" +
            remover_digitos((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2528 "parser.tab.cpp"
    break;

  case 142: /* nome_genset: INVALIDO  */
#line 554 "parser.y"
               {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, "Genset",
            string("Nome de genset '") + (yyvsp[0].str) + "' " + motivo_lexema_invalido((yyvsp[0].str)) + ".",
            "Use letras e sublinhado: '" + capitalizar(sanitizar_identificador((yyvsp[0].str))) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2539 "parser.tab.cpp"
    break;

  case 143: /* nome_genset: %empty  */
#line 560 "parser.y"
                  {
        registrar_erro((yyloc).first_line, (yyloc).first_column, "Genset",
            "Generalization set sem nome.",
            "Informe o nome logo após 'genset': genset NomeDoGenset { ... }.");
        (yyval.str) = strdup("");
    }
#line 2550 "parser.tab.cpp"
    break;

  case 144: /* resto_genset: ABRE_CHAVE corpo_genset FECHA_CHAVE  */
#line 570 "parser.y"
                                        { genset_definir_forma(false); genset_finalizar(false, (yylsp[0]).first_line); }
#line 2556 "parser.tab.cpp"
    break;

  case 145: /* resto_genset: ABRE_CHAVE error FECHA_CHAVE  */
#line 571 "parser.y"
                                        { genset_definir_forma(false); genset_finalizar(true, (yylsp[0]).first_line); yyerrok; }
#line 2562 "parser.tab.cpp"
    break;

  case 146: /* resto_genset: ABRE_CHAVE error  */
#line 572 "parser.y"
                                              { genset_definir_forma(false); genset_finalizar(true, (yylsp[0]).last_line); yyerrok; }
#line 2568 "parser.tab.cpp"
    break;

  case 147: /* resto_genset: WHERE lista_especificas SPECIALIZES ref_classe  */
#line 574 "parser.y"
                                                     {
        genset_definir_forma(true);
        genset_definir_geral((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
        genset_finalizar(false, (yylsp[0]).first_line);
    }
#line 2578 "parser.tab.cpp"
    break;

  case 148: /* resto_genset: WHERE lista_especificas virgula_sobrando SPECIALIZES ref_classe  */
#line 579 "parser.y"
                                                                      {
        genset_definir_forma(true);
        genset_definir_geral((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
        genset_finalizar(false, (yylsp[0]).first_line);
    }
#line 2588 "parser.tab.cpp"
    break;

  case 149: /* resto_genset: WHERE lista_especificas virgula_sobrando  */
#line 584 "parser.y"
                                                                      {
        registrar_erro((yylsp[0]).last_line, (yylsp[0]).last_column, contexto_enum_genset(),
            "Falta 'specializes <ClasseGeral>' ao final da forma curta.",
            "Forma curta completa: genset Nome where Filha1, Filha2 specializes ClasseMae.");
        genset_definir_forma(true);
        genset_finalizar(false, (yylsp[0]).last_line);
    }
#line 2600 "parser.tab.cpp"
    break;

  case 150: /* resto_genset: WHERE lista_especificas SPECIALIZES  */
#line 591 "parser.y"
                                                                 {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Falta a classe geral após 'specializes'.",
            "Complete com a classe-mãe: ... where Filha1, Filha2 specializes ClasseMae.");
        genset_definir_forma(true);
        genset_finalizar(false, (yylsp[0]).first_line);
    }
#line 2612 "parser.tab.cpp"
    break;

  case 151: /* resto_genset: WHERE lista_especificas  */
#line 598 "parser.y"
                                                     {
        registrar_erro((yylsp[0]).last_line, (yylsp[0]).last_column, contexto_enum_genset(),
            "Falta 'specializes <ClasseGeral>' ao final da forma curta.",
            "Forma curta completa: genset Nome where Filha1, Filha2 specializes ClasseMae.");
        genset_definir_forma(true);
        genset_finalizar(false, (yylsp[0]).last_line);
    }
#line 2624 "parser.tab.cpp"
    break;

  case 153: /* corpo_genset: clausula_specifics clausula_general  */
#line 609 "parser.y"
                                          {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Ordem invertida: 'specifics' declarado antes de 'general'.",
            "Declare primeiro a classe-mãe e depois as filhas: { general Mae specifics Filha1, Filha2 }.");
    }
#line 2634 "parser.tab.cpp"
    break;

  case 154: /* corpo_genset: clausula_general clausula_categorizer_opt  */
#line 614 "parser.y"
                                                {
        registrar_erro((yylsp[-1]).first_line, (yylsp[-1]).first_column, contexto_enum_genset(),
            "Generalization set sem a cláusula 'specifics'.",
            "Liste as classes filhas: specifics Filha1, Filha2.");
    }
#line 2644 "parser.tab.cpp"
    break;

  case 155: /* corpo_genset: clausula_specifics  */
#line 619 "parser.y"
                         {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Generalization set sem a cláusula 'general'.",
            "Informe a classe-mãe antes das filhas: general ClasseMae.");
    }
#line 2654 "parser.tab.cpp"
    break;

  case 156: /* corpo_genset: %empty  */
#line 624 "parser.y"
                  {
        registrar_erro((yyloc).first_line, (yyloc).first_column, contexto_enum_genset(),
            "Generalization set com corpo vazio.",
            "Preencha o bloco: { general ClasseMae specifics Filha1, Filha2 }.");
    }
#line 2664 "parser.tab.cpp"
    break;

  case 157: /* clausula_general: GENERAL ref_classe  */
#line 632 "parser.y"
                       { genset_definir_geral((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2670 "parser.tab.cpp"
    break;

  case 158: /* clausula_general: GENERAL  */
#line 633 "parser.y"
              {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "'general' sem a classe geral.",
            "Informe a classe-mãe: general ClasseMae.");
    }
#line 2680 "parser.tab.cpp"
    break;

  case 160: /* clausula_categorizer_opt: CATEGORIZER ref_classe  */
#line 642 "parser.y"
                             { genset_definir_categorizador((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2686 "parser.tab.cpp"
    break;

  case 163: /* clausula_specifics: SPECIFICS  */
#line 648 "parser.y"
                {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "'specifics' sem nenhuma classe específica.",
            "Liste as classes filhas separadas por vírgula: specifics Filha1, Filha2.");
    }
#line 2696 "parser.tab.cpp"
    break;

  case 164: /* lista_especificas: ref_classe  */
#line 656 "parser.y"
               { genset_adicionar_especifica((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 2702 "parser.tab.cpp"
    break;

  case 165: /* lista_especificas: lista_especificas VIRGULA ref_classe  */
#line 657 "parser.y"
                                           {
        consumir_separador_invalido();
        genset_adicionar_especifica((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2711 "parser.tab.cpp"
    break;

  case 166: /* lista_especificas: lista_especificas ref_classe  */
#line 661 "parser.y"
                                   {
        if (!consumir_separador_invalido() && *(yyvsp[0].str))
            registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
                string("Falta vírgula antes de '") + (yyvsp[0].str) + "'.",
                "Separe as classes específicas por vírgula: Filha1, Filha2.");
        if (*(yyvsp[0].str) == '\0') separador_invalido_pendente = true;
        genset_adicionar_especifica((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2724 "parser.tab.cpp"
    break;

  case 167: /* virgula_sobrando: VIRGULA  */
#line 672 "parser.y"
                                   {
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, contexto_enum_genset(),
            "Vírgula sobrando após a última classe específica.",
            "Remova a vírgula final da lista.");
    }
#line 2734 "parser.tab.cpp"
    break;

  case 168: /* ref_classe: CLASSE  */
#line 682 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2740 "parser.tab.cpp"
    break;

  case 169: /* ref_classe: RELACOES  */
#line 683 "parser.y"
               {
        string ctx = contexto_enum_genset();
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, ctx.empty() ? "Genset" : ctx,
            string("'") + (yyvsp[0].str) + "' não é um nome de classe válido (inicia com minúscula).",
            "Nomes de classe iniciam com letra maiúscula: '" + capitalizar((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2752 "parser.tab.cpp"
    break;

  case 170: /* ref_classe: INSTANCIA  */
#line 690 "parser.y"
                {
        string ctx = contexto_enum_genset();
        registrar_erro((yylsp[0]).first_line, (yylsp[0]).first_column, ctx.empty() ? "Genset" : ctx,
            string("'") + (yyvsp[0].str) + "' não é um nome de classe válido (contém números).",
            "Nomes de classe não têm números; se for uma classe, use '" + remover_digitos((yyvsp[0].str)) + "'.");
        (yyval.str) = (yyvsp[0].str);
    }
#line 2764 "parser.tab.cpp"
    break;

  case 171: /* ref_classe: INVALIDO  */
#line 697 "parser.y"
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
#line 2784 "parser.tab.cpp"
    break;


#line 2788 "parser.tab.cpp"

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

#line 714 "parser.y"


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
