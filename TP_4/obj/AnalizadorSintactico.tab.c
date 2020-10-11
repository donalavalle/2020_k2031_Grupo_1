
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
#line 1 "../src/AnalizadorSintactico.y"


#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define YYDEBUG 1

int yylex ();
int yyerror (char*);
int printError(char*, int);

unsigned count = 0;

FILE* yyin;
FILE* yyout;

char* tempVar = NULL;
char* tempPointer = NULL;



/* Line 189 of yacc.c  */
#line 97 "AnalizadorSintactico.tab.c"

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
     NUM_ENTERO = 258,
     NUM_REAL = 259,
     TIPO_DATO = 260,
     ID = 261,
     ASIG_MULT = 262,
     ASIG_DIV = 263,
     ASIG_MOD = 264,
     ASIG_SUMA = 265,
     ASIG_RESTA = 266,
     ASIG_DESP_IZQ = 267,
     ASIG_DESP_DER = 268,
     ASIG_AND_BIN = 269,
     ASIG_XOR_BIN = 270,
     ASIG_OR_BIN = 271,
     OP_INC = 272,
     OP_DEC = 273,
     OP_IGUALDAD = 274,
     OP_DESIGUALDAD = 275,
     OP_AND = 276,
     OP_OR = 277,
     OP_MENOR_IGUAL = 278,
     OP_MAYOR_IGUAL = 279,
     OP_DESP_IZQ = 280,
     OP_DESP_DER = 281,
     OP_MIEMBRO_PUNT = 282,
     CHAR = 283,
     STRING = 284,
     SIZEOF = 285,
     CLASE_ALM = 286,
     CALIF_TIPO = 287,
     STRUCT_UNION = 288,
     ENUM = 289,
     CONTINUE = 290,
     BREAK = 291,
     IF = 292,
     ELSE = 293,
     SWITCH = 294,
     FOR = 295,
     DO = 296,
     WHILE = 297,
     CASE = 298,
     DEFAULT = 299,
     RETURN = 300,
     GOTO = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 77 "../src/AnalizadorSintactico.y"

  int    valorEntero;
  double valorReal;
  char*  valorString;



/* Line 214 of yacc.c  */
#line 187 "AnalizadorSintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 199 "AnalizadorSintactico.tab.c"

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
#define YYLAST   713

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  200
/* YYNRULES -- Number of states.  */
#define YYNSTATES  325

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,     2,     2,     2,    61,    54,     2,
      62,    63,    59,    57,    48,    58,    68,    60,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    47,
      55,    51,    56,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,    52,    70,    64,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    11,    13,    15,    17,
      19,    21,    23,    25,    29,    31,    35,    37,    43,    45,
      47,    49,    51,    53,    55,    57,    59,    61,    63,    65,
      67,    71,    73,    77,    79,    83,    85,    89,    91,    95,
      97,   101,   105,   107,   111,   115,   119,   123,   125,   129,
     133,   135,   139,   143,   145,   149,   153,   157,   159,   165,
     167,   170,   173,   176,   179,   184,   186,   188,   190,   192,
     194,   196,   198,   203,   208,   212,   216,   219,   222,   224,
     228,   230,   232,   236,   239,   242,   245,   248,   249,   251,
     253,   257,   259,   263,   265,   270,   271,   273,   275,   279,
     281,   283,   285,   291,   294,   295,   297,   299,   302,   306,
     309,   312,   313,   315,   317,   321,   323,   327,   328,   330,
     332,   333,   335,   338,   339,   341,   344,   348,   349,   351,
     353,   356,   358,   362,   367,   372,   377,   378,   380,   382,
     384,   388,   391,   394,   395,   397,   399,   403,   409,   412,
     414,   418,   420,   424,   426,   429,   431,   434,   438,   443,
     448,   449,   451,   452,   454,   456,   458,   460,   462,   464,
     466,   470,   473,   474,   476,   480,   483,   487,   488,   490,
     491,   493,   496,   500,   502,   505,   511,   519,   525,   531,
     539,   549,   550,   552,   554,   559,   563,   567,   570,   573,
     577
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      72,     0,    -1,    -1,    72,    73,    -1,    -1,    96,    47,
      -1,   137,    -1,     3,    -1,     4,    -1,    28,    -1,    75,
      -1,     6,    -1,    77,    -1,    76,    48,    77,    -1,    78,
      -1,    91,    79,    77,    -1,    80,    -1,    80,    49,    76,
      50,    78,    -1,    51,    -1,     7,    -1,     8,    -1,     9,
      -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,    14,
      -1,    15,    -1,    16,    -1,    81,    -1,    80,    22,    81,
      -1,    82,    -1,    81,    21,    82,    -1,    83,    -1,    82,
      52,    83,    -1,    84,    -1,    83,    53,    84,    -1,    85,
      -1,    84,    54,    85,    -1,    86,    -1,    85,    19,    86,
      -1,    85,    20,    86,    -1,    87,    -1,    86,    55,    87,
      -1,    86,    56,    87,    -1,    86,    23,    87,    -1,    86,
      24,    87,    -1,    88,    -1,    87,    25,    88,    -1,    87,
      26,    88,    -1,    89,    -1,    88,    57,    89,    -1,    88,
      58,    89,    -1,    90,    -1,    89,    59,    90,    -1,    89,
      60,    90,    -1,    89,    61,    90,    -1,    91,    -1,    62,
     132,    63,    90,    91,    -1,    93,    -1,    17,    91,    -1,
      18,    91,    -1,    92,    90,    -1,    30,    91,    -1,    30,
      62,   132,    63,    -1,    54,    -1,    59,    -1,    57,    -1,
      58,    -1,    64,    -1,    65,    -1,    95,    -1,    93,    66,
      76,    67,    -1,    93,    62,    94,    63,    -1,    93,    68,
       6,    -1,    93,    27,     6,    -1,    93,    17,    -1,    93,
      18,    -1,    77,    -1,    94,    48,    77,    -1,    74,    -1,
      29,    -1,    62,    76,    63,    -1,    97,    99,    -1,    31,
      98,    -1,   104,    98,    -1,    32,    98,    -1,    -1,    97,
      -1,   100,    -1,   100,    48,    99,    -1,   116,    -1,   116,
      51,   101,    -1,    77,    -1,    69,   103,   102,    70,    -1,
      -1,    48,    -1,   101,    -1,   103,    48,   101,    -1,     5,
      -1,   105,    -1,   128,    -1,    33,   106,    69,   107,    70,
      -1,    33,     6,    -1,    -1,     6,    -1,   108,    -1,   107,
     108,    -1,   109,   111,    47,    -1,   104,   110,    -1,    32,
     110,    -1,    -1,   109,    -1,   112,    -1,   111,    48,   112,
      -1,   116,    -1,   113,    50,   114,    -1,    -1,   116,    -1,
      78,    -1,    -1,   114,    -1,   117,   121,    -1,    -1,   118,
      -1,    59,   119,    -1,    59,   119,   118,    -1,    -1,   120,
      -1,    32,    -1,   120,    32,    -1,     6,    -1,    62,   116,
      63,    -1,   121,    66,   115,    67,    -1,   121,    62,   136,
      63,    -1,   121,    62,   122,    63,    -1,    -1,   127,    -1,
     124,    -1,   125,    -1,   124,    48,   125,    -1,    97,   116,
      -1,    97,   126,    -1,    -1,   133,    -1,     6,    -1,   127,
      48,     6,    -1,    34,   106,    69,   129,    70,    -1,    34,
       6,    -1,   130,    -1,   129,    48,   130,    -1,   131,    -1,
     131,    51,   114,    -1,     6,    -1,   109,   126,    -1,   118,
      -1,   117,   134,    -1,    62,   133,    63,    -1,   135,    66,
     115,    67,    -1,   135,    62,   136,    63,    -1,    -1,   134,
      -1,    -1,   123,    -1,   138,    -1,   140,    -1,   146,    -1,
     147,    -1,   149,    -1,   150,    -1,    97,   116,   140,    -1,
     139,    47,    -1,    -1,    76,    -1,    69,   141,    70,    -1,
     142,   143,    -1,   141,   142,   143,    -1,    -1,   144,    -1,
      -1,   145,    -1,    96,    47,    -1,   144,    96,    47,    -1,
     137,    -1,   145,   137,    -1,    37,    62,    76,    63,   137,
      -1,    37,    62,    76,    63,   137,    38,   137,    -1,    39,
      62,    76,    63,   137,    -1,    42,    62,    76,    63,   137,
      -1,    41,   137,    42,    62,    76,    63,    47,    -1,    40,
      62,   148,    47,   139,    47,   139,    63,   137,    -1,    -1,
      76,    -1,    96,    -1,    43,   114,    50,   137,    -1,    44,
      50,   137,    -1,     6,    50,   137,    -1,    35,    47,    -1,
      36,    47,    -1,    45,   139,    47,    -1,    46,     6,    47,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    86,    89,    90,    91,    94,    95,    96,
      97,   100,   103,   104,   107,   108,   111,   112,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   128,
     129,   132,   133,   136,   137,   140,   141,   144,   145,   148,
     149,   150,   153,   154,   155,   156,   157,   160,   161,   162,
     165,   166,   167,   170,   171,   172,   173,   176,   177,   180,
     181,   182,   183,   184,   185,   188,   189,   190,   191,   192,
     193,   196,   197,   198,   199,   200,   201,   202,   205,   206,
     209,   210,   211,   215,   218,   219,   220,   223,   224,   227,
     228,   231,   232,   235,   236,   239,   240,   243,   244,   247,
     248,   249,   252,   253,   256,   257,   260,   261,   264,   267,
     268,   271,   272,   275,   276,   279,   280,   283,   284,   287,
     290,   291,   294,   297,   298,   301,   302,   305,   306,   309,
     310,   313,   314,   315,   316,   317,   320,   321,   324,   327,
     328,   331,   332,   335,   336,   339,   340,   343,   344,   347,
     348,   351,   352,   355,   358,   361,   362,   365,   366,   367,
     370,   371,   374,   375,   378,   379,   380,   381,   382,   383,
     384,   387,   390,   391,   394,   397,   398,   401,   402,   405,
     406,   409,   410,   413,   414,   418,   419,   420,   423,   424,
     425,   428,   429,   430,   433,   434,   435,   438,   439,   440,
     441
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM_ENTERO", "NUM_REAL", "TIPO_DATO",
  "ID", "ASIG_MULT", "ASIG_DIV", "ASIG_MOD", "ASIG_SUMA", "ASIG_RESTA",
  "ASIG_DESP_IZQ", "ASIG_DESP_DER", "ASIG_AND_BIN", "ASIG_XOR_BIN",
  "ASIG_OR_BIN", "OP_INC", "OP_DEC", "OP_IGUALDAD", "OP_DESIGUALDAD",
  "OP_AND", "OP_OR", "OP_MENOR_IGUAL", "OP_MAYOR_IGUAL", "OP_DESP_IZQ",
  "OP_DESP_DER", "OP_MIEMBRO_PUNT", "CHAR", "STRING", "SIZEOF",
  "CLASE_ALM", "CALIF_TIPO", "STRUCT_UNION", "ENUM", "CONTINUE", "BREAK",
  "IF", "ELSE", "SWITCH", "FOR", "DO", "WHILE", "CASE", "DEFAULT",
  "RETURN", "GOTO", "';'", "','", "'?'", "':'", "'='", "'|'", "'^'", "'&'",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", "'~'",
  "'!'", "'['", "']'", "'.'", "'{'", "'}'", "$accept", "input", "line",
  "const", "const_enum", "expresion", "exp_asignacion", "exp_condicional",
  "op_asignacion", "exp_OR_log", "exp_AND_log", "exp_OR_in", "exp_OR_ex",
  "exp_AND", "exp_igualdad", "exp_relacional", "exp_desp", "exp_aditiva",
  "exp_multip", "exp_conversion", "exp_unaria", "op_unario", "exp_sufijo",
  "lista_argumentos", "exp_primaria", "declaracion",
  "especificadores_declaracion", "especificadores_declaracion_opc",
  "lista_declaradores", "declarador", "inicializador", "coma_opc",
  "lista_inicializadores", "especificador_tipo",
  "especificador_struct_union", "ID_opc", "lista_declaradores_struct",
  "declaracion_struct", "lista_calificadores", "lista_calificadores_opc",
  "declaradores_struct", "decla_struct", "decla_opc", "exp_constante",
  "exp_constante_opc", "decla", "puntero_opc", "puntero",
  "lista_calificadores_tipos_opc", "lista_calificadores_tipos",
  "declarador_directo", "lista_identificadores_opc", "lista_tipos_param",
  "lista_parametros", "declaracion_parametro", "declarador_abstracto_opc",
  "lista_identificadores", "especificador_enum", "lista_enumeradores",
  "enumerador", "const_de_enumeracion", "nombre_tipo",
  "declarador_abstracto", "declarador_abstracto_directo",
  "declarador_abstracto_directo_opc", "lista_tipos_param_opc", "sentencia",
  "sentencia_exp", "expresion_opc", "sentencia_compuesta",
  "lista_compuesta", "lista_declaraciones_opc", "lista_sentencias_opc",
  "lista_declaraciones", "lista_sentencias", "sentencia_seleccion",
  "sentencia_iteracion", "for_opc", "sentencia_etiquetada",
  "sentencia_salto", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    59,    44,    63,
      58,    61,   124,    94,    38,    60,    62,    43,    45,    42,
      47,    37,    40,    41,   126,    33,    91,    93,    46,   123,
     125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    73,    74,    74,    74,
      74,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    86,    86,    86,    86,    86,    87,    87,    87,
      88,    88,    88,    89,    89,    89,    89,    90,    90,    91,
      91,    91,    91,    91,    91,    92,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      95,    95,    95,    96,    97,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   104,   105,   105,   106,   106,   107,   107,   108,   109,
     109,   110,   110,   111,   111,   112,   112,   113,   113,   114,
     115,   115,   116,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   121,   121,   121,   122,   122,   123,   124,
     124,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   131,   132,   133,   133,   134,   134,   134,
     135,   135,   136,   136,   137,   137,   137,   137,   137,   137,
     137,   138,   139,   139,   140,   141,   141,   142,   142,   143,
     143,   144,   144,   145,   145,   146,   146,   146,   147,   147,
     147,   148,   148,   148,   149,   149,   149,   150,   150,   150,
     150
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     5,     1,
       2,     2,     2,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     3,     3,     2,     2,     1,     3,
       1,     1,     3,     2,     2,     2,     2,     0,     1,     1,
       3,     1,     3,     1,     4,     0,     1,     1,     3,     1,
       1,     1,     5,     2,     0,     1,     1,     2,     3,     2,
       2,     0,     1,     1,     3,     1,     3,     0,     1,     1,
       0,     1,     2,     0,     1,     2,     3,     0,     1,     1,
       2,     1,     3,     4,     4,     4,     0,     1,     1,     1,
       3,     2,     2,     0,     1,     1,     3,     5,     2,     1,
       3,     1,     3,     1,     2,     1,     2,     3,     4,     4,
       0,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     0,     1,     3,     2,     3,     0,     1,     0,
       1,     2,     3,     1,     2,     5,     7,     5,     5,     7,
       9,     0,     1,     1,     4,     3,     3,     2,     2,     3,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     1,     7,     8,    99,    11,     0,     0,     9,
      81,     0,    87,    87,   104,   104,     0,     0,     0,     0,
       0,   172,     0,     0,     0,   172,     0,    65,    67,    68,
      66,     0,    69,    70,   177,     3,    80,    10,   173,    12,
      14,    16,    29,    31,    33,    35,    37,    39,    42,    47,
      50,    53,    57,     0,    59,    71,     0,   123,    87,   100,
     101,     6,   164,     0,   165,   166,   167,   168,   169,   172,
      11,     0,    60,    61,     0,    63,    88,    84,    86,   103,
       0,   148,     0,   197,   198,     0,     0,   191,   123,     0,
       0,   119,    57,     0,   172,     0,     0,   111,     0,   111,
     123,     0,     0,   123,   177,   172,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    18,     0,    62,
      76,    77,     0,     0,     0,     0,     5,   127,    83,    89,
      91,     0,   124,    85,   171,   196,     0,     0,     0,     0,
       0,   192,   193,     0,     0,     0,     0,   172,   195,   199,
     200,   112,   110,    82,   109,   160,   124,   154,   144,     0,
     181,    91,   174,   172,   183,   175,   172,     0,    13,    30,
       0,    32,    34,    36,    38,    40,    41,    45,    46,    43,
      44,    48,    49,    51,    52,    54,    55,    56,    15,    75,
      78,     0,     0,    74,   129,   125,   128,   123,     0,   170,
     131,   123,   122,    64,     0,   106,   123,   153,     0,   149,
     151,   172,   172,   172,     0,   172,   194,   123,   156,     0,
       0,   176,   184,   182,     0,     0,    73,    72,   126,   130,
      90,     0,    93,    92,     0,   136,   120,   102,   107,     0,
     113,     0,   115,     0,   147,     0,   185,   187,     0,     0,
     188,     0,   162,   120,    58,    17,    79,    97,    95,   132,
     145,   123,     0,   163,   138,   139,   137,     0,   121,     0,
     108,   123,     0,   150,   152,   172,   172,     0,   157,     0,
       0,    96,     0,   141,   160,   142,   135,     0,     0,   134,
     133,   114,   116,   186,     0,   189,   159,   158,    98,    94,
     123,   140,   146,   172,   190
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    35,    36,    37,    38,    39,    40,   138,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,   211,    55,   102,    88,    77,   148,   149,
     253,   302,   278,    58,    59,    80,   224,   225,   100,   172,
     259,   260,   261,   288,   289,   181,   151,   152,   215,   216,
     222,   282,   283,   284,   285,   177,   286,    60,   228,   229,
     230,   101,   178,   238,   239,   287,   184,    62,    63,    64,
     104,   105,   185,   106,   186,    65,    66,   163,    67,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -222
static const yytype_int16 yypact[] =
{
    -222,   284,  -222,  -222,  -222,  -222,    16,   572,   572,  -222,
    -222,   629,   104,   104,    27,    35,    33,    61,    77,    81,
      85,   487,    96,   638,   105,   638,   157,  -222,  -222,  -222,
    -222,   563,  -222,  -222,   104,  -222,  -222,  -222,     2,  -222,
    -222,     6,   149,   122,   130,   140,   168,    14,   165,   145,
     158,  -222,   662,   638,   127,  -222,   179,   170,   104,  -222,
    -222,  -222,  -222,   185,  -222,  -222,  -222,  -222,  -222,   487,
    -222,   638,  -222,  -222,   563,  -222,  -222,  -222,  -222,   164,
     167,   164,   171,  -222,  -222,   638,   638,   554,   170,   195,
     638,  -222,  -222,   191,   487,   197,   198,   128,    -6,   128,
       1,   183,   202,   170,    12,   351,   104,   638,   638,   638,
     638,   638,   638,   638,   638,   638,   638,   638,   638,   638,
     638,   638,   638,   638,   638,   638,   638,  -222,  -222,  -222,
    -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,   638,  -222,
    -222,  -222,   245,   638,   638,   246,  -222,   221,  -222,   206,
     -22,    15,  -222,  -222,  -222,  -222,   194,   128,   252,    23,
      37,     2,  -222,   213,   192,   200,    44,   487,  -222,  -222,
    -222,  -222,  -222,  -222,  -222,   201,    83,  -222,  -222,   638,
    -222,   214,  -222,   351,  -222,  -222,   419,   217,  -222,   149,
     119,   122,   130,   140,   168,    14,    14,   165,   165,   165,
     165,   145,   145,   158,   158,  -222,  -222,  -222,  -222,  -222,
    -222,    93,   -18,  -222,  -222,   170,   234,   170,   147,  -222,
    -222,   170,   -26,  -222,    19,  -222,    53,  -222,   -16,  -222,
     218,   487,   487,   638,   638,   487,  -222,   170,    36,    39,
     572,  -222,  -222,  -222,   638,   638,  -222,  -222,  -222,  -222,
    -222,   147,  -222,  -222,   207,   166,   638,  -222,  -222,   160,
    -222,   224,   228,   252,  -222,   638,   233,  -222,   232,    94,
    -222,   219,   104,   638,  -222,  -222,  -222,  -222,   235,  -222,
    -222,    13,   222,  -222,   238,  -222,   243,   229,  -222,   226,
    -222,    53,   638,  -222,  -222,   487,   638,   249,  -222,   236,
     230,   147,   210,  -222,    21,  -222,  -222,   104,   275,  -222,
    -222,  -222,  -222,  -222,   237,  -222,  -222,  -222,  -222,  -222,
     170,  -222,  -222,   487,  -222
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -222,  -222,  -222,  -222,  -222,   -12,   -59,   -17,  -222,  -222,
     190,   193,   199,   196,   220,    99,    62,   100,   102,   -30,
       3,  -222,  -222,  -222,  -222,     4,     0,     5,    87,  -222,
    -220,  -222,  -222,    -9,  -222,   290,  -222,    82,   -90,   212,
    -222,    18,  -222,   -15,    58,   -53,   -97,   -85,  -222,  -222,
    -222,  -222,  -222,  -222,    25,    54,  -222,  -222,  -222,    71,
    -222,   262,  -221,  -222,  -222,    65,    -1,  -222,   -23,  -125,
    -222,   240,   156,  -222,  -222,  -222,  -222,  -222,  -222,  -222
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -181
static const yytype_int16 yytable[] =
{
      61,    57,    95,   175,   150,    56,    91,   171,    93,   171,
      72,    73,    76,    76,    75,   176,   271,     5,    78,    98,
      89,   220,    99,   139,     5,   219,    92,   220,   108,   218,
     107,   277,   263,    79,   103,   164,   255,   116,   117,   219,
     256,    81,   107,    12,    13,    14,    15,    34,   188,   247,
     107,    97,    14,    15,   264,   109,    92,   173,    76,    98,
     147,  -143,    98,   153,  -143,    99,    69,   226,   155,   118,
     119,   107,   147,   159,   160,   161,  -143,   221,   166,   208,
      83,   318,   182,   320,   210,   107,   231,   103,    99,   257,
      99,   162,   107,   168,   205,   206,   207,   190,  -161,   271,
     232,   272,  -161,  -117,   103,   273,   103,   235,    84,     5,
     187,    92,   147,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
     248,  -155,   212,     5,   226,    12,    13,    14,    15,    85,
     175,   245,   107,    86,   140,   141,  -155,    87,    99,   240,
       3,     4,   176,    70,   142,    94,   246,   297,    90,   252,
      97,    14,    15,    96,     7,     8,   236,   107,   254,   244,
     110,     5,   280,   262,   111,     9,    10,    11,   197,   198,
     199,   200,    92,   112,   304,   242,   276,   114,   115,   143,
     120,   121,   252,   144,   113,   145,   176,    12,    13,    14,
      15,    27,   122,   123,    28,    29,    30,   290,   291,    31,
     268,    32,    33,   195,   196,    99,   251,   124,   125,   126,
     201,   202,   269,   304,   203,   204,   146,   275,   303,   147,
     266,   267,   154,  -105,   270,   176,   157,   165,   262,    91,
     158,   167,   252,   274,   169,   170,   179,    92,    91,   180,
     294,   209,   213,   214,   217,   281,    91,   223,   227,    92,
     233,    34,   234,   237,   243,   218,   249,   254,    92,   265,
     279,   295,   281,   314,   292,    91,    92,   312,  -118,   296,
     319,   322,   298,   301,     2,   306,   307,     3,     4,     5,
       6,   308,   309,   310,   313,    92,   315,   317,   189,   316,
     323,     7,     8,   191,   250,    82,   258,   281,   193,   311,
     192,   174,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   324,    19,    20,    21,    22,    23,    24,    25,
      26,   300,   321,   194,   293,   305,   156,   299,    27,   241,
       0,    28,    29,    30,   183,     0,    31,     0,    32,    33,
       0,     0,     0,    34,     3,     4,     5,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,    28,    29,
      30,     0,     0,    31,     0,    32,    33,     0,     0,     0,
      34,  -179,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     0,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
       0,     0,     0,    27,     0,     0,    28,    29,    30,     0,
       0,    31,     0,    32,    33,     0,     0,     0,    34,  -180,
       3,     4,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     0,    19,    20,    21,    22,
      23,    24,    25,    26,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,    28,    29,    30,     0,     0,    31,
       0,    32,    33,     0,     0,     0,    34,     3,     4,     5,
      70,     0,     0,     0,     0,     0,     3,     4,     5,    70,
       0,     7,     8,     0,     0,     3,     4,     0,    70,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     7,
       8,     9,    10,    11,     0,    97,    14,    15,     0,     0,
       9,    10,    11,     0,     0,     0,     0,     0,    27,     0,
       0,    28,    29,    30,     0,     0,    31,    27,    32,    33,
      28,    29,    30,     0,     0,    31,    27,    32,    33,    28,
      29,    30,     3,     4,    71,    70,    32,    33,     0,     0,
       0,     3,     4,     0,    70,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     9,    10,    11,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,     0,
       0,     0,     0,    27,     0,     0,    28,    29,    30,     0,
       0,    74,    27,    32,    33,    28,    29,    30,     0,     0,
      31,     0,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137
};

static const yytype_int16 yycheck[] =
{
       1,     1,    25,   100,    57,     1,    23,    97,    23,    99,
       7,     8,    12,    13,    11,   100,   237,     5,    13,    31,
      21,     6,    31,    53,     5,   150,    23,     6,    22,    51,
      48,   251,    48,     6,    34,    88,    62,    23,    24,   164,
      66,     6,    48,    31,    32,    33,    34,    69,   107,    67,
      48,    32,    33,    34,    70,    49,    53,    63,    58,    71,
      59,    48,    74,    58,    63,    74,    50,   157,    69,    55,
      56,    48,    59,    85,    86,    87,    63,    62,    90,   138,
      47,   301,    70,    62,   143,    48,    63,    87,    97,    70,
      99,    87,    48,    94,   124,   125,   126,   109,    62,   320,
      63,    62,    66,    50,   104,    66,   106,    63,    47,     5,
     106,   108,    59,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     215,    48,   144,     5,   224,    31,    32,    33,    34,    62,
     237,    48,    48,    62,    17,    18,    63,    62,   157,   179,
       3,     4,   237,     6,    27,    50,    63,    63,    62,   218,
      32,    33,    34,     6,    17,    18,   167,    48,   221,    50,
      21,     5,     6,   226,    52,    28,    29,    30,   116,   117,
     118,   119,   179,    53,   281,   186,   245,    19,    20,    62,
      25,    26,   251,    66,    54,    68,   281,    31,    32,    33,
      34,    54,    57,    58,    57,    58,    59,    47,    48,    62,
     233,    64,    65,   114,   115,   224,    69,    59,    60,    61,
     120,   121,   234,   320,   122,   123,    47,   244,   281,    59,
     231,   232,    47,    69,   235,   320,    69,    42,   291,   256,
      69,    50,   301,   240,    47,    47,    63,   244,   265,    47,
     265,     6,     6,    32,    48,   255,   273,    63,     6,   256,
      47,    69,    62,    62,    47,    51,    32,   320,   265,    51,
      63,    38,   272,   296,    50,   292,   273,   292,    50,    47,
      70,     6,    63,    48,     0,    63,    48,     3,     4,     5,
       6,    48,    63,    67,   295,   292,    47,    67,   108,    63,
      63,    17,    18,   110,   217,    15,   224,   307,   112,   291,
     111,    99,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,   323,    39,    40,    41,    42,    43,    44,    45,
      46,   273,   307,   113,   263,   281,    74,   272,    54,   183,
      -1,    57,    58,    59,   104,    -1,    62,    -1,    64,    65,
      -1,    -1,    -1,    69,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,
      59,    -1,    -1,    62,    -1,    64,    65,    -1,    -1,    -1,
      69,    70,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    57,    58,    59,    -1,
      -1,    62,    -1,    64,    65,    -1,    -1,    -1,    69,    70,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    57,    58,    59,    -1,    -1,    62,
      -1,    64,    65,    -1,    -1,    -1,    69,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    17,    18,    -1,    -1,     3,     4,    -1,     6,    -1,
      17,    18,    28,    29,    30,    31,    32,    33,    34,    17,
      18,    28,    29,    30,    -1,    32,    33,    34,    -1,    -1,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    57,    58,    59,    -1,    -1,    62,    54,    64,    65,
      57,    58,    59,    -1,    -1,    62,    54,    64,    65,    57,
      58,    59,     3,     4,    62,     6,    64,    65,    -1,    -1,
      -1,     3,     4,    -1,     6,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    57,    58,    59,    -1,
      -1,    62,    54,    64,    65,    57,    58,    59,    -1,    -1,
      62,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    72,     0,     3,     4,     5,     6,    17,    18,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    39,
      40,    41,    42,    43,    44,    45,    46,    54,    57,    58,
      59,    62,    64,    65,    69,    73,    74,    75,    76,    77,
      78,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    95,    96,    97,   104,   105,
     128,   137,   138,   139,   140,   146,   147,   149,   150,    50,
       6,    62,    91,    91,    62,    91,    97,    98,    98,     6,
     106,     6,   106,    47,    47,    62,    62,    62,    97,   137,
      62,    78,    91,   114,    50,   139,     6,    32,    76,   104,
     109,   132,    96,    97,   141,   142,   144,    48,    22,    49,
      21,    52,    53,    54,    19,    20,    23,    24,    55,    56,
      25,    26,    57,    58,    59,    60,    61,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    51,    79,    90,
      17,    18,    27,    62,    66,    68,    47,    59,    99,   100,
     116,   117,   118,    98,    47,   137,   132,    69,    69,    76,
      76,    76,    96,   148,   116,    42,    76,    50,   137,    47,
      47,   109,   110,    63,   110,   117,   118,   126,   133,    63,
      47,   116,    70,   142,   137,   143,   145,    96,    77,    81,
      76,    82,    83,    84,    85,    86,    86,    87,    87,    87,
      87,    88,    88,    89,    89,    90,    90,    90,    77,     6,
      77,    94,    76,     6,    32,   119,   120,    48,    51,   140,
       6,    62,   121,    63,   107,   108,   109,     6,   129,   130,
     131,    63,    63,    47,    62,    63,   137,    62,   134,   135,
      90,   143,   137,    47,    50,    48,    63,    67,   118,    32,
      99,    69,    77,   101,   116,    62,    66,    70,   108,   111,
     112,   113,   116,    48,    70,    51,   137,   137,   139,    76,
     137,   133,    62,    66,    91,    78,    77,   101,   103,    63,
       6,    97,   122,   123,   124,   125,   127,   136,   114,   115,
      47,    48,    50,   130,   114,    38,    47,    63,    63,   136,
     115,    48,   102,   116,   117,   126,    63,    48,    48,    63,
      67,   112,   114,   137,   139,    47,    63,    67,   101,    70,
      62,   125,     6,    63,   137
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
        case 5:

/* Line 1455 of yacc.c  */
#line 90 "../src/AnalizadorSintactico.y"
    {tempVar = NULL; tempPointer = NULL;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 177 "../src/AnalizadorSintactico.y"
    {/*CAMBIAR POR nombre_tipo*/;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 185 "../src/AnalizadorSintactico.y"
    {/*CAMBIAR POR nombre_tipo*/;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 218 "../src/AnalizadorSintactico.y"
    {(yyval.valorString) = strdup((yyvsp[(1) - (2)].valorString));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 219 "../src/AnalizadorSintactico.y"
    {(yyval.valorString) = strdup((yyvsp[(1) - (2)].valorString));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 220 "../src/AnalizadorSintactico.y"
    {(yyval.valorString) = strdup((yyvsp[(1) - (2)].valorString));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 227 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se declara la variable: \'%s\' de tipo: \'%s\'\n", (yyvsp[(1) - (1)].valorString), tempVar);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 228 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se declara la variable: \'%s\' de tipo: \'%s\'\n", (yyvsp[(1) - (3)].valorString), tempVar);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 231 "../src/AnalizadorSintactico.y"
    {(yyval.valorString) = strdup((yyvsp[(1) - (1)].valorString));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 232 "../src/AnalizadorSintactico.y"
    {(yyval.valorString) = strdup((yyvsp[(1) - (3)].valorString));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 247 "../src/AnalizadorSintactico.y"
    {tempVar = strdup((yyvsp[(1) - (1)].valorString));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 249 "../src/AnalizadorSintactico.y"
    {/*Sacamos nombre_typedef*/;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 252 "../src/AnalizadorSintactico.y"
    {/*Hay problemas con el typedef ya que no tiene un identificador final*/;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 294 "../src/AnalizadorSintactico.y"
    {(yyval.valorString) = strdup((yyvsp[(2) - (2)].valorString));;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 313 "../src/AnalizadorSintactico.y"
    {(yyval.valorString) = strdup((yyvsp[(1) - (1)].valorString));;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 314 "../src/AnalizadorSintactico.y"
    {(yyval.valorString) = strdup((yyvsp[(2) - (3)].valorString));;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 315 "../src/AnalizadorSintactico.y"
    {(yyval.valorString) = strdup((yyvsp[(1) - (4)].valorString));;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 316 "../src/AnalizadorSintactico.y"
    {(yyval.valorString) = strdup((yyvsp[(1) - (4)].valorString));;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 317 "../src/AnalizadorSintactico.y"
    {(yyval.valorString) = strdup((yyvsp[(1) - (4)].valorString));;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 384 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se declara la funcion: \'%s\' que devuelve: \'%s\'\n", (yyvsp[(2) - (3)].valorString), (yyvsp[(1) - (3)].valorString));;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 418 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro la sentencia IF\n");;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 419 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro la sentencia IF y ELSE\n");;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 420 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro la sentencia SWITCH\n");;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 423 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro la sentencia WHILE\n");;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 424 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro la sentencia DO WHILE\n");;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 425 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro la sentencia FOR\n");;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 438 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro la sentencia CONTINUE\n");;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 439 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro la sentencia BREAK\n");;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 440 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro la sentencia RETURN\n");;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 441 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se encontro la sentencia GO TO\n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2021 "AnalizadorSintactico.tab.c"
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
#line 446 "../src/AnalizadorSintactico.y"


int yyerror (char *mensaje)  /* Funcion de error */
{
  fprintf (yyout, "Error: %s\n", mensaje);
}

int printError(char *mensaje, int linea)
{
  fprintf(yyout, "Se encontro la cadena erronea: %s en la linea: %d\n", mensaje, linea);
}

void main(){ 

    yyin = fopen("Codigo.c", "r");
    yyout = fopen("Salida.txt", "w");

    #ifdef BISON_DEBUG
       yydebug = 1;
    #endif
    
    yyparse();

    fclose(yyin);
    fclose(yyout);
}
