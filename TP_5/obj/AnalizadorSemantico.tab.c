
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "../src/AnalizadorSemantico.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tabla_Simbolos.h"

#include <stddef.h>
#include <stdint.h> 

//[!] Definir funciones con DEFINE, permite no estandarizar el tipo de dato de los parametros. 
#define tipoDeDato(x) _Generic((x), char: "char", int: "int", float: "float", char *: "char*", default: "other")
#define sonIguales(var1, var2) (! strcmp(tipoDeDato(var1), tipoDeDato(var2))) 

#define YYDEBUG 1

int yylex ();
int yyerror (char*);
void ingresarErrorSemantico(char*);
void ingresarErrorSintactico();
void mostrarErrorDeVariable(char*);

unsigned flagErrorExp = 0;
unsigned flagHayPyC = 1;  

char* tipoDeDatoVar   = NULL; // [❗] Variable global utilizada para almacenar el tipo de dato de variables.
char* tipoDeDatoID    = NULL; // [❗] Variable global utilizada para almacenar el tipo de dato de los identificadores.
char* tipoDeDatoParam = NULL; // [❗] Variable global utilizada para almacenar el tipo de dato de los parametros de una funcion.
char* tipoDatoExp     = NULL; // [❗] Variable global utilizada para almacenar el tipo de dato de expresiones.

FILE* yyin;
FILE* yyout;

union TipoValor valorTemporal;        // [❗] Variable global utilizada para almacenar el valor semantico de las constantes (UNION -> ya que cambia dependiendo del tipo de dato).
union TipoValor valorExp;             // [❗] Variable global utilizada para almacenar el valor semantico de las expresiones (UNION -> ya que cambia dependiendo del tipo de dato).
Funcion* listaDeParametrosTemporal;   // [❗] Lista de paramatros global que se utiliza para realizar las rutinas semanticas de una funcion.




/* Line 189 of yacc.c  */
#line 114 "AnalizadorSemantico.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ENTERO = 258,
     REAL = 259,
     CHAR = 260,
     STRING = 261,
     TIPO_DATO = 262,
     IDENTIFICADOR = 263,
     IF = 264,
     ELSE = 265,
     DO = 266,
     FOR = 267,
     WHILE = 268,
     CONTINUE = 269,
     BREAK = 270,
     RETURN = 271
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 59 "../src/AnalizadorSemantico.y"

    int   entero;
    float real;
    char   caracter;
    char* string;
    
    struct {    // [❗] Declaramos este Struct 'tipo' para que el NT 'exp' pueda almacenar el valor y el tipo de dato según qué regla siga
      union {   
        int      valEnt; 
        double   valReal;
        char     valChar;
        char*    valString;
      } valor; 
    
      char* tipoDato;
    } tipo;



/* Line 214 of yacc.c  */
#line 186 "AnalizadorSemantico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 198 "AnalizadorSemantico.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  128

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   271

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      19,    20,    24,    25,    22,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    21,
       2,    23,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,    18,     2,     2,     2,     2,
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
      15,    16
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    10,    12,    13,    15,
      17,    19,    21,    23,    25,    27,    29,    32,    35,    36,
      38,    42,    45,    49,    50,    52,    54,    57,    59,    61,
      63,    64,    66,    68,    71,    78,    79,    82,    88,    96,
     106,   107,   109,   111,   113,   115,   118,   120,   126,   128,
     130,   133,   134,   136,   137,   140,   145,   149,   150,   152,
     154,   158,   162,   170,   173,   174,   177,   178,   181,   182,
     186,   190,   192,   193,   195,   196,   198,   200,   202,   204,
     206,   208,   210,   212
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      27,     0,    -1,    -1,    27,    28,    -1,    -1,    29,    -1,
      30,    -1,    -1,    51,    -1,    52,    -1,    56,    -1,    46,
      -1,    31,    -1,    33,    -1,    40,    -1,    42,    -1,    44,
      47,    -1,    32,    47,    -1,    -1,    45,    -1,    17,    34,
      18,    -1,    35,    38,    -1,    34,    35,    38,    -1,    -1,
      36,    -1,    37,    -1,    36,    37,    -1,    52,    -1,    46,
      -1,    51,    -1,    -1,    39,    -1,    30,    -1,    39,    30,
      -1,     9,    19,    45,    20,    30,    41,    -1,    -1,    10,
      30,    -1,    13,    19,    45,    20,    30,    -1,    11,    30,
      13,    19,    45,    20,    21,    -1,    12,    19,    43,    21,
      32,    21,    32,    20,    30,    -1,    -1,    52,    -1,    51,
      -1,    14,    -1,    15,    -1,    16,    32,    -1,    66,    -1,
       8,    19,    48,    20,    47,    -1,    21,    -1,     1,    -1,
      49,    50,    -1,    -1,    65,    -1,    -1,    22,    48,    -1,
       8,    23,    66,    47,    -1,    54,    53,    55,    -1,    -1,
      24,    -1,     7,    -1,     8,    58,    47,    -1,    57,    22,
      55,    -1,    54,    53,     8,    19,    59,    20,    47,    -1,
       8,    58,    -1,    -1,    23,    66,    -1,    -1,    61,    60,
      -1,    -1,    22,    61,    60,    -1,    62,    63,    64,    -1,
       7,    -1,    -1,    24,    -1,    -1,     8,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,     8,    -1,    67,    -1,
      65,    -1,    67,    25,    67,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    80,    83,    84,    85,    88,    88,    91,
      97,    98,   101,   102,   103,   104,   105,   110,   115,   116,
     119,   122,   123,   126,   127,   130,   131,   134,   135,   136,
     139,   140,   143,   144,   147,   150,   151,   154,   155,   156,
     159,   160,   161,   164,   165,   166,   169,   176,   196,   197,
     203,   207,   208,   213,   214,   218,   242,   245,   246,   251,
     256,   280,   282,   301,   323,   324,   334,   337,   340,   341,
     344,   349,   354,   355,   360,   361,   364,   372,   376,   380,
     384,   398,   420,   431
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENTERO", "REAL", "CHAR", "STRING",
  "TIPO_DATO", "IDENTIFICADOR", "IF", "ELSE", "DO", "FOR", "WHILE",
  "CONTINUE", "BREAK", "RETURN", "'{'", "'}'", "'('", "')'", "';'", "','",
  "'='", "'*'", "'+'", "$accept", "input", "line", "declaAsig",
  "sentencia", "sentenciaExp", "expOpc", "sentenciaComp", "listaComp",
  "listaDeclaracionesOpc", "listaDeclaraciones", "declaraciones",
  "listaSentenciasOpc", "listaSentencias", "sentenciaSel", "elseOpc",
  "sentenciaIter", "forOpc", "sentenciaSalto", "expDeSentencia",
  "llamadoFuncion", "puntoComaError", "argumentos", "tipoDeArgumento",
  "otroArgumentoOPC", "asignacion", "declaracion", "punteroOpcional",
  "declaradorDeTipo", "tipoDeclaracion", "declaracionFuncion", "decla",
  "asignacionOPC", "listaDeParametros", "otrosParametros", "parametro",
  "declaradorDeTipoParam", "punteroOpcionalParam", "idOPC", "valor",
  "expresion", "exp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   123,   125,    40,
      41,    59,    44,    61,    42,    43
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    26,    27,    27,    28,    28,    28,    29,    29,    29,
      29,    29,    30,    30,    30,    30,    30,    31,    32,    32,
      33,    34,    34,    35,    35,    36,    36,    37,    37,    37,
      38,    38,    39,    39,    40,    41,    41,    42,    42,    42,
      43,    43,    43,    44,    44,    44,    45,    46,    47,    47,
      48,    49,    49,    50,    50,    51,    52,    53,    53,    54,
      55,    55,    56,    57,    58,    58,    59,    59,    60,    60,
      61,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      65,    66,    67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     1,
       3,     2,     3,     0,     1,     1,     2,     1,     1,     1,
       0,     1,     1,     2,     6,     0,     2,     5,     7,     9,
       0,     1,     1,     1,     1,     2,     1,     5,     1,     1,
       2,     0,     1,     0,     2,     4,     3,     0,     1,     1,
       3,     3,     7,     2,     0,     2,     0,     2,     0,     3,
       3,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     1,    76,    77,    78,    79,    59,    80,     0,
      18,     0,     0,    43,    44,    18,    23,     3,     5,     6,
      12,     0,    13,    14,    15,     0,    19,    11,     8,     9,
      57,    10,    82,    46,    81,    51,     0,     0,    80,     0,
      40,     0,    45,     0,    23,    18,    24,    25,    28,    29,
      27,    57,    49,    48,    17,    16,    58,     0,     0,     0,
      53,    52,     0,     0,     0,     0,     0,    42,    41,     0,
      20,    18,    32,    21,    18,    26,     0,    64,    56,     0,
      83,     0,    51,    50,    55,    18,     0,    18,    18,    22,
      33,    64,    66,     0,     0,     0,    47,    54,    35,     0,
       0,    37,    71,     0,    68,    72,    65,    60,    61,    18,
      34,     0,    18,     0,     0,    67,    73,    74,    36,    38,
       0,    62,    68,    75,    70,    18,    69,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    17,    18,    72,    20,    21,    22,    44,    45,
      46,    47,    73,    74,    23,   110,    24,    66,    25,    26,
      48,    54,    59,    60,    83,    49,    50,    57,    51,    78,
      31,    79,    94,   103,   115,   104,   105,   117,   124,    32,
      33,    34
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -34
static const yytype_int16 yypact[] =
{
     -34,    98,   -34,   -34,   -34,   -34,   -34,   -34,    13,     0,
     130,    11,    18,   -34,   -34,    45,    33,   -34,   -34,   -34,
     -34,    10,   -34,   -34,   -34,    10,   -34,   -34,   -34,   -34,
      21,   -34,   -34,   -34,    17,    45,    45,    45,   -34,    34,
      51,    45,   -34,    13,    26,     9,    33,   -34,   -34,   -34,
     -34,    21,   -34,   -34,   -34,   -34,   -34,    46,    45,    36,
      39,   -34,    10,    42,    44,    41,    47,   -34,   -34,    49,
     -34,     9,   -34,   -34,   114,   -34,    57,    16,   -34,    50,
      17,    10,    45,   -34,   -34,   130,    45,    45,   130,   -34,
     -34,    43,    60,    45,     7,    57,   -34,   -34,    61,    55,
      56,   -34,   -34,    58,    54,    59,   -34,   -34,   -34,   130,
     -34,    64,    45,    10,    60,   -34,   -34,    71,   -34,   -34,
      62,   -34,    54,   -34,   -34,   130,   -34,   -34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   -34,   -34,    -1,   -34,   -13,   -34,   -34,    37,
     -34,    40,    19,   -34,   -34,   -34,   -34,   -34,   -34,   -31,
      79,   -24,    12,   -34,   -34,     3,     6,    65,    87,    -4,
     -34,   -34,   -34,   -34,   -29,   -22,   -34,   -34,   -34,   -30,
     -33,    38
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -64
static const yytype_int8 yytable[] =
{
      19,    55,    42,    62,    28,    61,    63,    29,    52,    39,
      69,    52,     3,     4,     5,     6,   -30,    38,     9,    37,
      10,    11,    12,    13,    14,    15,    16,   -30,    53,   -63,
      40,    53,    35,     7,    43,    92,    36,    41,    84,    93,
       7,    43,    58,    67,    70,    56,    68,    64,     3,     4,
       5,     6,    61,    38,    77,    99,    81,    96,     7,    65,
     106,    82,    85,    86,    36,    91,    93,   102,    87,    88,
     107,   109,    95,    90,   100,   111,   114,   112,   113,   123,
      27,    71,   125,   116,    98,   119,    75,   101,    30,   121,
      89,   108,   122,   126,    97,     0,    80,     0,     2,   120,
       0,     3,     4,     5,     6,     7,     8,     9,   118,    10,
      11,    12,    13,    14,    15,    16,    76,     3,     4,     5,
       6,   -31,    38,     9,   127,    10,    11,    12,    13,    14,
      15,    16,   -31,     3,     4,     5,     6,     0,    38,     9,
       0,    10,    11,    12,    13,    14,    15,    16
};

static const yytype_int8 yycheck[] =
{
       1,    25,    15,    36,     1,    35,    37,     1,     1,    10,
      41,     1,     3,     4,     5,     6,     7,     8,     9,    19,
      11,    12,    13,    14,    15,    16,    17,    18,    21,    22,
      19,    21,    19,     7,     8,    19,    23,    19,    62,    23,
       7,     8,    25,    40,    18,    24,    40,    13,     3,     4,
       5,     6,    82,     8,     8,    86,    20,    81,     7,     8,
      93,    22,    20,    19,    23,     8,    23,     7,    21,    20,
      94,    10,    22,    74,    87,    20,    22,    21,    20,     8,
       1,    44,    20,    24,    85,    21,    46,    88,     1,   113,
      71,    95,   114,   122,    82,    -1,    58,    -1,     0,   112,
      -1,     3,     4,     5,     6,     7,     8,     9,   109,    11,
      12,    13,    14,    15,    16,    17,    51,     3,     4,     5,
       6,     7,     8,     9,   125,    11,    12,    13,    14,    15,
      16,    17,    18,     3,     4,     5,     6,    -1,     8,     9,
      -1,    11,    12,    13,    14,    15,    16,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,     0,     3,     4,     5,     6,     7,     8,     9,
      11,    12,    13,    14,    15,    16,    17,    28,    29,    30,
      31,    32,    33,    40,    42,    44,    45,    46,    51,    52,
      54,    56,    65,    66,    67,    19,    23,    19,     8,    30,
      19,    19,    32,     8,    34,    35,    36,    37,    46,    51,
      52,    54,     1,    21,    47,    47,    24,    53,    25,    48,
      49,    65,    66,    45,    13,     8,    43,    51,    52,    45,
      18,    35,    30,    38,    39,    37,    53,     8,    55,    57,
      67,    20,    22,    50,    47,    20,    19,    21,    20,    38,
      30,     8,    19,    23,    58,    22,    47,    48,    30,    45,
      32,    30,     7,    59,    61,    62,    66,    47,    55,    10,
      41,    20,    21,    20,    22,    60,    24,    63,    30,    21,
      32,    47,    61,     8,    64,    20,    60,    30
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:

/* Line 1455 of yacc.c  */
#line 88 "../src/AnalizadorSemantico.y"
    {
                          tipoDeDatoVar = NULL;
                        ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 91 "../src/AnalizadorSemantico.y"
    {
                          free(tipoDeDatoID); 
                          listaDeParametrosTemporal = NULL; // [❗] Limpia la lista de parametros temporal para poder reutilizarla en un futuro
                          tipoDeDatoVar = NULL;
                          tipoDatoExp = NULL;
                        ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 105 "../src/AnalizadorSemantico.y"
    {
                                            flagHayPyC = 1;
                                          ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 110 "../src/AnalizadorSemantico.y"
    {
                                      flagHayPyC = 1;
                                    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 169 "../src/AnalizadorSemantico.y"
    {
                          tipoDatoExp = NULL;
                          valorExp = limpiarUnion()
                        ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 176 "../src/AnalizadorSemantico.y"
    {
                                                                  if(flagHayPyC){ // [❗] Si hay punto y coma, realiza la accion asociada correspondiente.
                                                                    Simbolo* aux = devolverSimbolo((yyvsp[(1) - (5)].string));
                                                                    if(aux){
                                                                      if(aux -> tipoID != TIPO_FUNC) // [❗] Pregunta si el identificador es una FUNCION
                                                                        ingresarErrorSemantico("El ID utilizado no corresponde con una funcion");
                                                                      else
                                                                        verificarParametros(aux, listaDeParametrosTemporal, yyout); // [❗] Si es una funcion, verifica que la cantidad y el tipo de los argumentos sea correcta.
                                                                    }
                                                                    else
                                                                      mostrarErrorDeVariable((yyvsp[(1) - (5)].string));
                                                                      //ingresarErrorSemantico("La variable no fue declarada"); // [❗] Ingresa el mensaje indicado en la lista de errores SEMANTICOS. (No indicamos el nombre de la variable no decalarada) 
                                                                  }

                                                                  flagHayPyC = 1;

                                                                  listaDeParametrosTemporal = NULL; // [❗] Libera la lista temporal.
                                                                ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 197 "../src/AnalizadorSemantico.y"
    {
                          flagHayPyC = 0; 
                          insertarError(&erroresSintacticos, "Se esperaba ';' al final de la linea");
                        ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 208 "../src/AnalizadorSemantico.y"
    {
                                insertarParametro(&listaDeParametrosTemporal, tipoDeDatoVar);
                               ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 218 "../src/AnalizadorSemantico.y"
    {
                                                          if(flagHayPyC) {
                                                            Simbolo* aux = devolverSimbolo((yyvsp[(1) - (4)].string)); 
                                                            if(aux) { // [❗] Si existe...
                                                              if(aux -> tipoID != TIPO_VAR) // [❗] Pregunta si el identificador es una funcion. 
                                                                ingresarErrorSemantico("El ID utilizado no corresponde con una variable");
                                                              else{
                                                                if(! strcmp(aux -> tipoDato, tipoDatoExp)) // [❗] Si no hay error de tipo, cambia el valor correctamente dependiendo del tipo de dato.
                                                                    cambiarValor(aux, valorExp);
                                                                  else 
                                                                    ingresarErrorSemantico("No coinciden los tipos de datos");
                                                                }
                                                              }
                                                              else
                                                                mostrarErrorDeVariable((yyvsp[(1) - (4)].string));
                                                          }
                                                              //ingresarErrorSemantico("La variable no fue declarada");
                                                          flagHayPyC = 1;

                                                          valorExp = limpiarUnion();
                                                          tipoDatoExp = NULL;
                                                        ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 246 "../src/AnalizadorSemantico.y"
    {
                                  strcat(tipoDeDatoID, "*");    // [❗] Concatenación de string, para agregar * al tipo de dato.
                                ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 251 "../src/AnalizadorSemantico.y"
    { 
                                tipoDeDatoID = strdup((yyvsp[(1) - (1)].string));
                              ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 256 "../src/AnalizadorSemantico.y"
    {
                                                                        if(flagHayPyC){
                                                                          Simbolo* aux = devolverSimbolo((yyvsp[(1) - (3)].string));
                                                                          if(! aux){ // [❗] Pregunta si el valor no fue declarado anteriormente
                                                                            // [❗] Crea un simbolo nuevo y lo inserta en la TS.
                                                                            aux = crearSimbolo(tipoDeDatoID, (yyvsp[(1) - (3)].string), TIPO_VAR);
                                                                            insertarSimbolo(aux);

                                                                            if(tipoDatoExp){ // [❗] Pregunta si existe una inicializacion de la variable
                                                                              // [❗] Si es asi, verifica que los tipos coincidan. Si se cumple, modifica, si no, lanza un error
                                                                              if(! strcmp(tipoDeDatoID, tipoDatoExp)) // [❗] Si existe, verifica que el valor de asignacion coincidad con el tipo del identificador.
                                                                                cambiarValor(aux, valorExp);
                                                                              else
                                                                                ingresarErrorSemantico("El valor asignado no coincide con el tipo de dato declarado");
                                                                            }
                                                                          }
                                                                          else
                                                                            ingresarErrorSemantico("Doble declaración de la variable");

                                                                        }
                                                                        
                                                                        flagHayPyC = 1;
                                                                        valorExp = limpiarUnion(); // [❗] Limpio la variable que guarda el valor a asignar para su posterior reutilizacion.
                                                                     ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 282 "../src/AnalizadorSemantico.y"
    {
                                                                                                              if(flagHayPyC){
                                                                                                                Simbolo* aux = devolverSimbolo((yyvsp[(3) - (7)].string));
                                                                                                                if(! aux){ // [❗] Pregunta si el identificador no fue utilizado antes.
                                                                                                                  aux = crearSimbolo(tipoDeDatoID, (yyvsp[(3) - (7)].string), TIPO_FUNC); // [❗] Crea un simbolo de tipo FUNCION
                                                                                                                  insertarSimbolo(aux);
                                                                                                                  aux -> valor . func = listaDeParametrosTemporal; // [❗] Asigna la lista de parametros de la funcion generada previamente.
                                                                                                                } 
                                                                                                                else { // [❗] Si el identifidor ya fue utilizado, lanza error semantico.
                                                                                                                  ingresarErrorSemantico("Doble declaración de la variable");
                                                                                                                };  
                                                                                                              }

                                                                                                              flagHayPyC = 1;                               

                                                                                                              listaDeParametrosTemporal = NULL; // [❗] Limpia la lista temporal para su reutilizacion.
                                                                                                            ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 301 "../src/AnalizadorSemantico.y"
    {
                                      Simbolo* aux = devolverSimbolo((yyvsp[(1) - (2)].string));
                                      if(! aux){ // [❗] Pregunta si el valor no fue declarado anteriormente
                                        // [❗] Crea un simbolo nuevo y lo inserta en la TS.
                                        aux = crearSimbolo(tipoDeDatoID, (yyvsp[(1) - (2)].string), TIPO_VAR);
                                        insertarSimbolo(aux);

                                        if(tipoDatoExp){ // [❗] Pregunta si existe una inicializacion de la variable
                                          // [❗] Si es asi, verifica que los tipos coincidan. Si se cumple, modifica, si no, lanza un error
                                          if(! strcmp(tipoDeDatoID, tipoDatoExp)) // [❗] Si existe, verifica que el valor de asignacion coincidad con el tipo del identificador.
                                            cambiarValor(aux, valorExp);
                                          else
                                            ingresarErrorSemantico("El valor asignado no coincide con el tipo de dato declarado");
                                        }
                                      }
                                      else
                                        ingresarErrorSemantico("Doble declaración de la variable");

                                      valorExp = limpiarUnion(); // [❗] Limpio la variable que guarda el valor a asignar para su posterior reutilizacion.
                                   ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 324 "../src/AnalizadorSemantico.y"
    { /* // [❗] Guardo el valor semantico y el tipo de dato de la expresion en variables temporales para realizar las resticciones semant. correspondientes. 
                                          valorExp . valEnt     = $2 . valor . valEnt;
                                          valorExp . valReal    = $2 . valor . valReal;
                                          valorExp . valChar    = $2 . valor . valChar;
                                          valorExp . valString  = $2 . valor . valString;

                                          tipoDatoExp = strdup($2 . tipoDato); */
                                        ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 334 "../src/AnalizadorSemantico.y"
    {
                                                  insertarParametro(&listaDeParametrosTemporal, "void");
                                                ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 344 "../src/AnalizadorSemantico.y"
    {
                                                              insertarParametro(&listaDeParametrosTemporal, tipoDeDatoParam);
                                                            ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 349 "../src/AnalizadorSemantico.y"
    { 
                                     tipoDeDatoParam = strdup((yyvsp[(1) - (1)].string));
                                   ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 355 "../src/AnalizadorSemantico.y"
    {
                                      strcat(tipoDeDatoParam, "*"); // [❗] Concatenación de string, para agregar * al tipo de dato.
                                    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 364 "../src/AnalizadorSemantico.y"
    {
                        // [!] Asigna el tipo de dato del VALOR en la variable global para que posteriormente 
                        //     sea utilizado en la verificacion de tipos :)
                        // [!] Asigna el valor semantico del VALOR en la variable global para luego realizar
                        //     la asignacion correctamente. 
                        tipoDeDatoVar = strdup(tipoDeDato((yyvsp[(1) - (1)].entero)));
                        valorTemporal . valEnt = (yyvsp[(1) - (1)].entero);
                       ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 372 "../src/AnalizadorSemantico.y"
    {
                        tipoDeDatoVar = strdup(tipoDeDato((yyvsp[(1) - (1)].real)));
                        valorTemporal . valReal = (yyvsp[(1) - (1)].real);
                       ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 376 "../src/AnalizadorSemantico.y"
    {
                        tipoDeDatoVar = strdup(tipoDeDato((yyvsp[(1) - (1)].caracter)));
                        valorTemporal . valChar = (yyvsp[(1) - (1)].caracter);
                       ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 380 "../src/AnalizadorSemantico.y"
    {
                        tipoDeDatoVar = strdup(tipoDeDato((yyvsp[(1) - (1)].string)));
                        valorTemporal . valString = strdup((yyvsp[(1) - (1)].string));
                       ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 384 "../src/AnalizadorSemantico.y"
    {
                        Simbolo* aux = devolverSimbolo((yyvsp[(1) - (1)].string));

                        if(aux){ // Verifica que el identificador exista para luego obtener su valor semantico.
                          valorTemporal = aux -> valor;
                          tipoDeDatoVar = strdup(aux -> tipoDato);
                        }
                        else
                          mostrarErrorDeVariable((yyvsp[(1) - (1)].string));
                          //ingresarErrorSemantico("La variable no fue declarada");
                       ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 398 "../src/AnalizadorSemantico.y"
    {
                  if(flagErrorExp){ // [❗] Si la expresion no es valida, asignara a la variable valores DEFAULT.
                    valorExp.valEnt = 0;
                    valorExp.valReal = 0.0;
                    valorExp.valChar = '\0';
                    valorExp.valString = NULL;

                    tipoDatoExp = NULL;

                    flagErrorExp = 0;
                  }
                  else{ // [❗] Si es valida, asigna los valores correspondientes.
                    valorExp.valEnt    = (yyvsp[(1) - (1)].tipo).valor.valEnt;
                    valorExp.valReal   = (yyvsp[(1) - (1)].tipo).valor.valReal;
                    valorExp.valChar   = (yyvsp[(1) - (1)].tipo).valor.valChar;
                    valorExp.valString = (yyvsp[(1) - (1)].tipo).valor.valString;
                    
                    tipoDatoExp = strdup((yyvsp[(1) - (1)].tipo).tipoDato);
                  }
               ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 420 "../src/AnalizadorSemantico.y"
    {
                      // [❗] Guarda el valor semantico y el tipo de dato dentro de la expresion sea cual sea. 
                      (yyval.tipo) . tipoDato = tipoDeDatoVar;
                      
                      if(tipoDeDatoVar){
                        (yyval.tipo) . valor . valEnt    = valorTemporal . valEnt;
                        (yyval.tipo) . valor . valChar   = valorTemporal . valChar;
                        (yyval.tipo) . valor . valReal   = valorTemporal . valReal;
                        (yyval.tipo) . valor . valString = valorTemporal . valString;
                      }
                   ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 431 "../src/AnalizadorSemantico.y"
    {  
                      if((yyvsp[(1) - (3)].tipo).tipoDato && (yyvsp[(3) - (3)].tipo).tipoDato){
                        if(! strcmp((yyvsp[(1) - (3)].tipo) . tipoDato, (yyvsp[(3) - (3)].tipo) . tipoDato) && strcmp((yyvsp[(1) - (3)].tipo) . tipoDato, "char*")){ // [❗] Verifica que se pueda realizar la suma, es decir, que los valores a sumar sean un mismo tipo y que ninguno sea de tipo char*
                          // [❗] Guarda el valor semantico y el tipo de dato dentro de la expresion "madre" luego de realizar la sumatoria de los valores semanticos
                          (yyval.tipo) . valor . valEnt  = (yyvsp[(1) - (3)].tipo) . valor . valEnt  + (yyvsp[(3) - (3)].tipo) . valor . valEnt;
                          (yyval.tipo) . valor . valChar = (yyvsp[(1) - (3)].tipo) . valor . valChar + (yyvsp[(3) - (3)].tipo) . valor . valChar;
                          (yyval.tipo) . valor . valReal = (yyvsp[(1) - (3)].tipo) . valor . valReal + (yyvsp[(3) - (3)].tipo) . valor . valReal;

                          (yyval.tipo) . tipoDato = (yyvsp[(1) - (3)].tipo) . tipoDato; 
                        }
                        else{ // [❗] Lanza un error e iguala todos los campos de la union a valores DEFAULT,.  
                          ingresarErrorSemantico("Los valores no son compatibles");
                          flagErrorExp = 1; // [❗] Flag que permite saber si la expresion es valida
                        }
                      }
                      else
                        flagErrorExp = 1;
                   ;}
    break;



/* Line 1455 of yacc.c  */
#line 1911 "AnalizadorSemantico.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



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
		      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 451 "../src/AnalizadorSemantico.y"


Simbolo* tablaSimbolos;

Error* erroresSemanticos;
Error* erroresSintacticos;

unsigned cantidadDeLineas = 1;

void ingresarErrorSemantico(char* mensaje) {
  insertarError(&erroresSemanticos, mensaje);
}

int yyerror (char *mensaje) {  /* Función de error */
  //[❗] COMENTADO para que no haga nada al momento de encontrar un 'syntax error' ya que nos vamos a ocupar de ese error de otra manera (mensaje personalizado). 
}

void mostrarErrorDeVariable(char* nombreVariable) {
  char* mensaje = strdup("La variable '");
  strcat(mensaje, strdup(nombreVariable));
  strcat(mensaje, "' no fue declarada");
  

  ingresarErrorSemantico(mensaje);
  //fprintf(yyout, "\nError en linea %d: La variable \'%s\' no fue declarada\n", cantidadDeLineas, nombreVariable);
  
}

void main() {
    #ifdef BISON_DEBUG
       yydebug = 1;
    #endif

    yyin = fopen("Input.txt", "r");
    yyout = fopen("Reporte.txt", "w");

    yyparse();

    //mostrarTabla(yyout);
    generarReporte(yyout); // [❗] Muestra todos los errores ocurridos junto con las funciones y variables declaradas. 

    fclose(yyin);
    fclose(yyout);

    /* 📚 TO DO LIST 📚 
       ❌ Sentencias simples y compuestas (for, if, while, etc) -> Incluidas En TP4. 
       ❓  Declaracion variables y almacenamiento en TS: punteros y arreglos. (Casi: Faltan arrays). 
       ✅ Declaracion, llamada y almacenamiento en TS de funciones. 
       ✅ Expresiones  (CASI)
       ✅ Control de tipo de datos en alguna operacion binaria.(CASI)
       ✅ Control doble declaracion de variables. 
       ✅ Control de cantidad y tipo de datos en declaracion de funciones.
       ◼◾ (❗❗) GENERAR REPORTE (❗❗): 
          ❓  Lista variables declaradas con su tipo. (Casi: Modificar TS para adaptar a Reporte)
          ❓  Lista de funciones declaradas con su tipo (retorno), cantidad y tipo de parametros. (Casi: Modificar TS para adaptar a Reporte) 
          ❌ Errores lexicos (FLEX), sintacticos(TOKEN ERROR) y semanticos (RUTINAS) encontrados.


      COSAS A MEJORAR:
        ◾ Si faltase ';', en la declaración múltiple solo no va a declarar la ultima variable.
    */

    /*
    valorTemporal1;
    valorTemporal2;

    valorTemporal = valorTemporal1 + valorTemporal2;

    exp:   valor       {valorTemporal;}
         | exp '+' exp {$$ = $1 + $3;}
    ;
    
    */
}
