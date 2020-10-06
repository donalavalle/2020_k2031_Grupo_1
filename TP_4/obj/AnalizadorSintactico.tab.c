
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
#include <math.h>
#include <ctype.h>

#define YYDEBUG 1

int yylex ();
int yyerror (char*);
int printError(char*, int);

unsigned count = 0; 

FILE* yyin;
FILE* yyout;



/* Line 189 of yacc.c  */
#line 94 "AnalizadorSintactico.tab.c"

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
     CONTINUE_BREAK = 290,
     IF = 291,
     ELSE = 292,
     SWITCH = 293,
     FOR = 294,
     DO = 295,
     WHILE = 296,
     CASE = 297,
     DEFAULT = 298,
     RETURN = 299,
     GOTO = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 67 "../src/AnalizadorSintactico.y"

  int   valorEntero;
  double valorReal;
  char* valorString;



/* Line 214 of yacc.c  */
#line 183 "AnalizadorSintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 195 "AnalizadorSintactico.tab.c"

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
#define YYLAST   616

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  199
/* YYNRULES -- Number of states.  */
#define YYNSTATES  325

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,     2,     2,    60,    53,     2,
      61,    62,    58,    56,    47,    57,    67,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    46,
      54,    50,    55,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,    51,    69,    63,     2,     2,     2,
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
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    11,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    34,    36,    40,    42,
      48,    50,    52,    54,    56,    58,    60,    62,    64,    66,
      68,    70,    72,    76,    78,    82,    84,    88,    90,    94,
      96,   100,   102,   106,   110,   112,   116,   120,   124,   128,
     130,   134,   138,   140,   144,   148,   150,   154,   158,   162,
     164,   170,   172,   175,   178,   181,   184,   189,   191,   193,
     195,   197,   199,   201,   203,   208,   213,   217,   221,   224,
     227,   229,   233,   235,   237,   241,   244,   247,   250,   253,
     254,   256,   258,   262,   264,   268,   270,   275,   276,   278,
     280,   284,   286,   288,   290,   296,   299,   300,   302,   304,
     307,   311,   314,   317,   318,   320,   322,   326,   328,   332,
     333,   335,   337,   338,   340,   343,   344,   346,   349,   353,
     354,   356,   358,   361,   363,   367,   372,   377,   382,   383,
     385,   387,   389,   393,   396,   399,   400,   402,   404,   408,
     414,   417,   419,   423,   425,   429,   431,   434,   436,   439,
     443,   448,   453,   454,   456,   457,   459,   461,   463,   465,
     467,   469,   471,   474,   475,   477,   482,   483,   485,   486,
     488,   490,   493,   495,   498,   504,   512,   518,   524,   532,
     542,   547,   551,   555,   558,   562,   566,   573,   575,   579
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      71,     0,    -1,    -1,    71,    72,    -1,    -1,    75,    46,
      -1,    95,    46,    -1,   136,    -1,   148,    -1,     3,    -1,
       4,    -1,    28,    -1,    74,    -1,     6,    -1,    76,    -1,
      75,    47,    76,    -1,    77,    -1,    90,    78,    76,    -1,
      79,    -1,    79,    48,    75,    49,    77,    -1,    50,    -1,
       7,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,
      12,    -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,
      80,    -1,    79,    22,    80,    -1,    81,    -1,    80,    21,
      81,    -1,    82,    -1,    81,    51,    82,    -1,    83,    -1,
      82,    52,    83,    -1,    84,    -1,    83,    53,    84,    -1,
      85,    -1,    84,    19,    85,    -1,    84,    20,    85,    -1,
      86,    -1,    85,    54,    86,    -1,    85,    55,    86,    -1,
      85,    23,    86,    -1,    85,    24,    86,    -1,    87,    -1,
      86,    25,    87,    -1,    86,    26,    87,    -1,    88,    -1,
      87,    56,    88,    -1,    87,    57,    88,    -1,    89,    -1,
      88,    58,    89,    -1,    88,    59,    89,    -1,    88,    60,
      89,    -1,    90,    -1,    61,   131,    62,    89,    90,    -1,
      92,    -1,    17,    90,    -1,    18,    90,    -1,    91,    89,
      -1,    30,    90,    -1,    30,    61,   131,    62,    -1,    53,
      -1,    58,    -1,    56,    -1,    57,    -1,    63,    -1,    64,
      -1,    94,    -1,    92,    65,    75,    66,    -1,    92,    61,
      93,    62,    -1,    92,    67,     6,    -1,    92,    27,     6,
      -1,    92,    17,    -1,    92,    18,    -1,    76,    -1,    93,
      47,    76,    -1,    73,    -1,    29,    -1,    61,    75,    62,
      -1,    96,    98,    -1,    31,    97,    -1,   103,    97,    -1,
      32,    97,    -1,    -1,    96,    -1,    99,    -1,    98,    47,
      99,    -1,   115,    -1,   115,    50,   100,    -1,    76,    -1,
      68,   102,   101,    69,    -1,    -1,    47,    -1,   100,    -1,
     102,    47,   100,    -1,     5,    -1,   104,    -1,   127,    -1,
      33,   105,    68,   106,    69,    -1,    33,     6,    -1,    -1,
       6,    -1,   107,    -1,   106,   107,    -1,   108,   110,    46,
      -1,   103,   109,    -1,    32,   109,    -1,    -1,   108,    -1,
     111,    -1,   110,    47,   111,    -1,   115,    -1,   112,    49,
     113,    -1,    -1,   115,    -1,    77,    -1,    -1,   113,    -1,
     116,   120,    -1,    -1,   117,    -1,    58,   118,    -1,    58,
     118,   117,    -1,    -1,   119,    -1,    32,    -1,   119,    32,
      -1,     6,    -1,    61,   115,    62,    -1,   120,    65,   114,
      66,    -1,   120,    61,   122,    62,    -1,   120,    61,   121,
      62,    -1,    -1,   126,    -1,   123,    -1,   124,    -1,   123,
      47,   124,    -1,    96,   115,    -1,    96,   125,    -1,    -1,
     132,    -1,     6,    -1,   126,    47,     6,    -1,    34,   105,
      68,   128,    69,    -1,    34,     6,    -1,   129,    -1,   128,
      47,   129,    -1,   130,    -1,   130,    50,   113,    -1,     6,
      -1,   108,   125,    -1,   117,    -1,   116,   133,    -1,    61,
     132,    62,    -1,   134,    65,   114,    66,    -1,   134,    61,
     135,    62,    -1,    -1,   133,    -1,    -1,   122,    -1,   137,
      -1,   139,    -1,   144,    -1,   145,    -1,   146,    -1,   147,
      -1,   138,    46,    -1,    -1,    75,    -1,    68,   140,   141,
      69,    -1,    -1,   142,    -1,    -1,   143,    -1,    95,    -1,
     142,    95,    -1,   136,    -1,   143,   136,    -1,    36,    61,
      75,    62,   136,    -1,    36,    61,    75,    62,   136,    37,
     136,    -1,    38,    61,    75,    62,   136,    -1,    41,    61,
      75,    62,   136,    -1,    40,   136,    41,    61,    75,    62,
      46,    -1,    39,    61,   138,    46,   138,    46,   138,    62,
     136,    -1,    42,   113,    49,   136,    -1,    43,    49,   136,
      -1,     6,    49,   136,    -1,    35,    46,    -1,    44,   138,
      46,    -1,    45,     6,    46,    -1,     5,     6,    61,   149,
      62,   139,    -1,   150,    -1,   149,    47,   150,    -1,     5,
       6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    76,    79,    80,    81,    82,    83,    86,
      87,    88,    89,    92,    95,    96,    99,   100,   103,   104,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   120,   121,   124,   125,   128,   129,   132,   133,   136,
     137,   140,   141,   142,   145,   146,   147,   148,   149,   152,
     153,   154,   157,   158,   159,   162,   163,   164,   165,   168,
     169,   172,   173,   174,   175,   176,   177,   180,   181,   182,
     183,   184,   185,   188,   189,   190,   191,   192,   193,   194,
     197,   198,   201,   202,   203,   207,   210,   211,   212,   215,
     216,   219,   220,   223,   224,   227,   228,   231,   232,   235,
     236,   239,   240,   241,   244,   245,   248,   249,   252,   253,
     256,   259,   260,   263,   264,   267,   268,   271,   272,   275,
     276,   279,   282,   283,   286,   289,   290,   293,   294,   297,
     298,   301,   302,   305,   306,   307,   308,   309,   312,   313,
     316,   319,   320,   323,   324,   327,   328,   331,   332,   335,
     336,   339,   340,   343,   344,   347,   350,   353,   354,   357,
     358,   359,   362,   363,   366,   367,   370,   371,   372,   373,
     374,   375,   378,   381,   382,   385,   388,   389,   392,   393,
     396,   397,   400,   401,   405,   406,   407,   410,   411,   412,
     415,   416,   417,   420,   421,   422,   425,   429,   430,   434
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
  "CLASE_ALM", "CALIF_TIPO", "STRUCT_UNION", "ENUM", "CONTINUE_BREAK",
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
  "lista_declaraciones_opc", "lista_sentencias_opc", "lista_declaraciones",
  "lista_sentencias", "sentencia_seleccion", "sentencia_iteracion",
  "sentencia_etiquetada", "sentencia_salto", "definicion",
  "lista_declaradores_def", "decla_def", 0
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
     295,   296,   297,   298,   299,   300,    59,    44,    63,    58,
      61,   124,    94,    38,    60,    62,    43,    45,    42,    47,
      37,    40,    41,   126,    33,    91,    93,    46,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    85,    85,    85,    85,    85,    86,
      86,    86,    87,    87,    87,    88,    88,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    94,    94,    94,    95,    96,    96,    96,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   113,   114,   114,   115,   116,   116,   117,   117,   118,
     118,   119,   119,   120,   120,   120,   120,   120,   121,   121,
     122,   123,   123,   124,   124,   125,   125,   126,   126,   127,
     127,   128,   128,   129,   129,   130,   131,   132,   132,   133,
     133,   133,   134,   134,   135,   135,   136,   136,   136,   136,
     136,   136,   137,   138,   138,   139,   140,   140,   141,   141,
     142,   142,   143,   143,   144,   144,   144,   145,   145,   145,
     146,   146,   146,   147,   147,   147,   148,   149,   149,   150
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       5,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     3,     3,     2,     2,
       1,     3,     1,     1,     3,     2,     2,     2,     2,     0,
       1,     1,     3,     1,     3,     1,     4,     0,     1,     1,
       3,     1,     1,     1,     5,     2,     0,     1,     1,     2,
       3,     2,     2,     0,     1,     1,     3,     1,     3,     0,
       1,     1,     0,     1,     2,     0,     1,     2,     3,     0,
       1,     1,     2,     1,     3,     4,     4,     4,     0,     1,
       1,     1,     3,     2,     2,     0,     1,     1,     3,     5,
       2,     1,     3,     1,     3,     1,     2,     1,     2,     3,
       4,     4,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     0,     1,     4,     0,     1,     0,     1,
       1,     2,     1,     2,     5,     7,     5,     5,     7,     9,
       4,     3,     3,     2,     3,     3,     6,     1,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     1,     9,    10,   101,    13,     0,     0,    11,
      83,     0,    89,    89,   106,   106,     0,     0,     0,     0,
     173,     0,     0,     0,   173,     0,    67,    69,    70,    68,
       0,    71,    72,   176,     3,    82,    12,     0,    14,    16,
      18,    31,    33,    35,    37,    39,    41,    44,    49,    52,
      55,    59,     0,    61,    73,     0,   125,    89,   102,   103,
       7,   166,     0,   167,   168,   169,   170,   171,     8,     0,
     173,    13,     0,    62,    63,     0,    65,   101,    90,    86,
      88,   105,     0,   150,     0,   193,     0,     0,   173,   174,
       0,     0,   121,    59,     0,   173,     0,     0,   113,     0,
     113,   125,     0,   180,   173,   177,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    20,     0,    64,
      78,    79,     0,     0,     0,     0,     6,   129,    85,    91,
      93,     0,   126,    87,   172,     0,   192,     0,     0,     0,
       0,     0,     0,     0,     0,   173,   191,   194,   195,   114,
     112,    84,   111,   162,   126,   156,   146,     0,   182,     0,
     173,   181,    15,    32,     0,    34,    36,    38,    40,    42,
      43,    47,    48,    45,    46,    50,    51,    53,    54,    56,
      57,    58,    17,    77,    80,     0,     0,    76,   131,   127,
     130,   125,     0,   133,   125,   124,     0,     0,   197,    66,
       0,   108,   125,   155,     0,   151,   153,   173,   173,   173,
       0,   173,   190,   125,   158,     0,     0,   175,   183,     0,
       0,    75,    74,   128,   132,    92,     0,    95,    94,     0,
     138,   122,   199,     0,     0,   104,   109,     0,   115,     0,
     117,     0,   149,     0,   184,   186,     0,     0,   187,     0,
     164,   122,    60,    19,    81,    99,    97,   134,   147,   125,
       0,     0,   140,   141,   139,   123,     0,   198,   196,   110,
     125,     0,   152,   154,   173,   173,     0,   159,   165,     0,
       0,    98,     0,   143,   162,   144,   137,   136,     0,     0,
     135,   116,   118,   185,     0,   188,   161,   160,   100,    96,
     125,   142,   148,   173,   189
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    34,    35,    36,    89,    38,    39,   138,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,   205,    54,    55,    56,    79,   148,   149,
     248,   302,   276,    57,    58,    82,   220,   221,   101,   170,
     257,   258,   259,   285,   286,   150,   151,   152,   209,   210,
     215,   280,   281,   282,   283,   175,   284,    59,   224,   225,
     226,   102,   176,   234,   235,   299,    60,    61,    62,    63,
     104,   179,   105,   180,    64,    65,    66,    67,    68,   217,
     218
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -233
static const yytype_int16 yypact[] =
{
    -233,   276,  -233,  -233,  -233,    24,    37,   468,   468,  -233,
    -233,   505,    34,    34,    67,    72,    30,    42,    64,    69,
     420,   105,   542,    49,   542,    85,  -233,  -233,  -233,  -233,
     486,  -233,  -233,    34,  -233,  -233,  -233,   110,  -233,  -233,
       4,   107,   117,   123,   109,   173,     5,   169,   141,   125,
    -233,   566,   542,   115,  -233,   131,   128,    34,  -233,  -233,
    -233,  -233,   135,  -233,  -233,  -233,  -233,  -233,  -233,   127,
     420,  -233,   542,  -233,  -233,   486,  -233,  -233,  -233,  -233,
    -233,   133,   137,   133,   145,  -233,   542,   542,   542,   159,
     174,   542,  -233,  -233,   172,   420,   177,   184,    29,    27,
      29,    -7,   176,  -233,   324,    34,  -233,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,  -233,  -233,  -233,
    -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,   542,  -233,
    -233,  -233,   225,   542,   542,   228,  -233,   203,   193,  -233,
     191,     9,  -233,  -233,  -233,   237,  -233,   181,    29,   240,
      87,    89,   204,   188,    90,   420,  -233,  -233,  -233,  -233,
    -233,  -233,  -233,   190,    91,  -233,  -233,   542,  -233,   185,
     372,  -233,  -233,   107,    32,   117,   123,   109,   173,     5,
       5,   169,   169,   169,   169,   141,   141,   125,   125,  -233,
    -233,  -233,  -233,  -233,  -233,    92,   -23,  -233,  -233,   128,
     221,   128,   161,  -233,   128,    31,   249,   101,  -233,  -233,
       8,  -233,    -2,  -233,   -15,  -233,   206,   420,   420,   542,
     542,   420,  -233,   128,    39,    70,   468,  -233,  -233,   542,
     542,  -233,  -233,  -233,  -233,  -233,   161,  -233,  -233,   195,
     138,   542,  -233,   237,   194,  -233,  -233,   153,  -233,   209,
     212,   240,  -233,   542,   226,  -233,   218,   111,  -233,   205,
      34,   542,  -233,  -233,  -233,  -233,   219,  -233,  -233,   -14,
     207,   208,   224,  -233,   230,  -233,   199,  -233,  -233,  -233,
      -2,   542,  -233,  -233,   420,   542,   227,  -233,  -233,   222,
     217,   161,   216,  -233,    11,  -233,  -233,  -233,    34,   280,
    -233,  -233,  -233,  -233,   229,  -233,  -233,  -233,  -233,  -233,
     128,  -233,  -233,   420,  -233
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -233,  -233,  -233,  -233,  -233,    15,   -85,   -19,  -233,  -233,
     179,   180,   178,   183,   186,    95,   -81,    83,   104,   -31,
      -3,  -233,  -233,  -233,  -233,   -22,   -11,     7,  -233,    81,
    -232,  -233,  -233,   -18,  -233,   281,  -233,    78,   -73,   200,
    -233,    12,  -233,   -16,    51,  -191,   -92,   -83,  -233,  -233,
    -233,  -233,    43,  -233,    16,    22,  -233,  -233,  -233,    62,
    -233,   250,  -223,  -233,  -233,  -233,   -20,  -233,   -17,    77,
    -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,
      73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -180
static const yytype_int16 yytable[] =
{
      90,    78,    78,    92,    73,    74,    94,    96,    76,   173,
     269,   103,   100,    77,   275,   213,    37,   213,   174,    93,
      80,   139,   182,   249,   107,   169,   108,   169,   116,   117,
      69,   260,   261,  -145,    77,   191,   192,   193,   194,    77,
      98,    14,    15,   242,   147,    99,    78,  -119,  -145,    93,
     156,   147,   109,   202,   262,  -145,   147,   100,   204,   118,
     119,    98,    14,    15,   153,    12,    13,    14,    15,   318,
     214,   162,   320,    81,   107,   166,    85,   255,    83,   107,
     100,   239,   100,   181,   178,   222,    70,    99,   303,   171,
      99,    97,   250,   199,   200,   201,   251,   269,    95,   260,
    -163,   160,   161,    86,  -163,    93,   164,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,   184,    87,   243,   247,   110,   249,
      88,   270,   140,   141,   107,   271,   107,   107,  -157,   240,
     100,   173,   142,    77,   278,   232,   236,   222,   253,   227,
     174,   228,   231,  -157,   241,   274,   106,   107,   107,   206,
     238,   247,   113,   254,     3,     4,    91,    71,   111,    12,
      13,    14,    15,   296,    93,   112,   143,   146,     7,     8,
     144,   154,   145,   124,   125,   126,   147,   304,   155,     9,
      10,    11,   114,   115,   120,   121,   174,   122,   123,   289,
     290,  -107,   100,   195,   196,   158,   107,   264,   265,   189,
     190,   268,   266,   159,    26,   163,   247,    27,    28,    29,
     273,   165,    30,   167,    31,    32,   197,   198,   304,   246,
     168,   203,    92,   272,   207,   208,    93,   174,   177,   279,
     211,   212,   216,   219,    92,   267,   223,   293,    93,   230,
     229,   233,    92,   244,   237,   252,   263,   277,   291,   279,
      93,  -120,    33,   294,   295,   310,   301,   297,    93,   306,
     307,   308,    92,   315,   313,   312,     2,   309,   314,     3,
       4,     5,     6,   317,   316,   319,   322,   183,    93,   186,
     185,   323,   245,     7,     8,   187,    84,   279,   256,   188,
     172,   305,   311,   324,     9,    10,    11,    12,    13,    14,
      15,    16,    17,   298,    18,    19,    20,    21,    22,    23,
      24,    25,   300,   292,   321,   157,   287,     3,     4,    26,
       6,   288,    27,    28,    29,     0,     0,    30,     0,    31,
      32,     7,     8,     0,    33,     0,     0,     0,     0,     0,
       0,     0,     9,    10,    11,     0,     0,     0,     0,    16,
      17,     0,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     3,     4,    26,     6,     0,
      27,    28,    29,     0,     0,    30,     0,    31,    32,     7,
       8,     0,    33,  -178,     0,     0,     0,     0,     0,     0,
       9,    10,    11,     0,     0,     0,     0,    16,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     3,     4,    26,     6,     0,    27,    28,
      29,     0,     0,    30,     0,    31,    32,     7,     8,     0,
      33,  -179,     0,     0,     0,     0,     0,     0,     9,    10,
      11,     0,     0,     0,     0,    16,    17,     0,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     3,     4,    26,    71,     0,    27,    28,    29,     0,
       0,    30,     0,    31,    32,     7,     8,     0,    33,     3,
       4,    77,    71,     0,     0,     0,     9,    10,    11,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     3,     4,
       0,    71,     0,     0,     9,    10,    11,     0,    98,    14,
      15,    26,     7,     8,    27,    28,    29,     0,     0,    72,
       0,    31,    32,     9,    10,    11,     0,     0,     0,    26,
       0,     0,    27,    28,    29,     3,     4,    30,    71,    31,
      32,     0,     0,     0,     0,     0,     0,     0,    26,     7,
       8,    27,    28,    29,     0,     0,    75,     0,    31,    32,
       9,    10,    11,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,    27,    28,
      29,     0,     0,    30,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137
};

static const yytype_int16 yycheck[] =
{
      20,    12,    13,    22,     7,     8,    22,    24,    11,   101,
     233,    33,    30,     5,   246,     6,     1,     6,   101,    22,
      13,    52,   107,   214,    47,    98,    22,   100,    23,    24,
       6,   222,    47,    47,     5,   116,   117,   118,   119,     5,
      32,    33,    34,    66,    58,    30,    57,    49,    62,    52,
      70,    58,    48,   138,    69,    62,    58,    75,   143,    54,
      55,    32,    33,    34,    57,    31,    32,    33,    34,   301,
      61,    88,    61,     6,    47,    95,    46,    69,     6,    47,
      98,    49,   100,   105,   104,   158,    49,    72,   279,    62,
      75,     6,    61,   124,   125,   126,    65,   320,    49,   290,
      61,    86,    87,    61,    65,   108,    91,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   109,    61,   209,   212,    21,   320,
      61,    61,    17,    18,    47,    65,    47,    47,    47,    47,
     158,   233,    27,     5,     6,   165,   177,   220,    47,    62,
     233,    62,    62,    62,    62,   240,    46,    47,    47,   144,
     180,   246,    53,    62,     3,     4,    61,     6,    51,    31,
      32,    33,    34,    62,   177,    52,    61,    46,    17,    18,
      65,    46,    67,    58,    59,    60,    58,   279,    61,    28,
      29,    30,    19,    20,    25,    26,   279,    56,    57,    46,
      47,    68,   220,   120,   121,    68,    47,   227,   228,   114,
     115,   231,   229,    68,    53,    41,   301,    56,    57,    58,
     239,    49,    61,    46,    63,    64,   122,   123,   320,    68,
      46,     6,   251,   236,     6,    32,   239,   320,    62,   250,
      47,    50,     5,    62,   263,   230,     6,   263,   251,    61,
      46,    61,   271,    32,    69,     6,    50,    62,    49,   270,
     263,    49,    68,    37,    46,    66,    47,    62,   271,    62,
      62,    47,   291,    46,   294,   291,     0,    47,   295,     3,
       4,     5,     6,    66,    62,    69,     6,   108,   291,   111,
     110,    62,   211,    17,    18,   112,    15,   308,   220,   113,
     100,   279,   290,   323,    28,    29,    30,    31,    32,    33,
      34,    35,    36,   270,    38,    39,    40,    41,    42,    43,
      44,    45,   271,   261,   308,    75,   253,     3,     4,    53,
       6,   254,    56,    57,    58,    -1,    -1,    61,    -1,    63,
      64,    17,    18,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,    -1,    -1,    -1,    -1,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,     3,     4,    53,     6,    -1,
      56,    57,    58,    -1,    -1,    61,    -1,    63,    64,    17,
      18,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,     3,     4,    53,     6,    -1,    56,    57,
      58,    -1,    -1,    61,    -1,    63,    64,    17,    18,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,     3,     4,    53,     6,    -1,    56,    57,    58,    -1,
      -1,    61,    -1,    63,    64,    17,    18,    -1,    68,     3,
       4,     5,     6,    -1,    -1,    -1,    28,    29,    30,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,     3,     4,
      -1,     6,    -1,    -1,    28,    29,    30,    -1,    32,    33,
      34,    53,    17,    18,    56,    57,    58,    -1,    -1,    61,
      -1,    63,    64,    28,    29,    30,    -1,    -1,    -1,    53,
      -1,    -1,    56,    57,    58,     3,     4,    61,     6,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    17,
      18,    56,    57,    58,    -1,    -1,    61,    -1,    63,    64,
      28,    29,    30,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
      58,    -1,    -1,    61,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,     0,     3,     4,     5,     6,    17,    18,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    38,    39,
      40,    41,    42,    43,    44,    45,    53,    56,    57,    58,
      61,    63,    64,    68,    72,    73,    74,    75,    76,    77,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    94,    95,    96,   103,   104,   127,
     136,   137,   138,   139,   144,   145,   146,   147,   148,     6,
      49,     6,    61,    90,    90,    61,    90,     5,    96,    97,
      97,     6,   105,     6,   105,    46,    61,    61,    61,    75,
     136,    61,    77,    90,   113,    49,   138,     6,    32,    75,
     103,   108,   131,    95,   140,   142,    46,    47,    22,    48,
      21,    51,    52,    53,    19,    20,    23,    24,    54,    55,
      25,    26,    56,    57,    58,    59,    60,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    50,    78,    89,
      17,    18,    27,    61,    65,    67,    46,    58,    98,    99,
     115,   116,   117,    97,    46,    61,   136,   131,    68,    68,
      75,    75,   138,    41,    75,    49,   136,    46,    46,   108,
     109,    62,   109,   116,   117,   125,   132,    62,   136,   141,
     143,    95,    76,    80,    75,    81,    82,    83,    84,    85,
      85,    86,    86,    86,    86,    87,    87,    88,    88,    89,
      89,    89,    76,     6,    76,    93,    75,     6,    32,   118,
     119,    47,    50,     6,    61,   120,     5,   149,   150,    62,
     106,   107,   108,     6,   128,   129,   130,    62,    62,    46,
      61,    62,   136,    61,   133,   134,    89,    69,   136,    49,
      47,    62,    66,   117,    32,    99,    68,    76,   100,   115,
      61,    65,     6,    47,    62,    69,   107,   110,   111,   112,
     115,    47,    69,    50,   136,   136,   138,    75,   136,   132,
      61,    65,    90,    77,    76,   100,   102,    62,     6,    96,
     121,   122,   123,   124,   126,   113,   114,   150,   139,    46,
      47,    49,   129,   113,    37,    46,    62,    62,   122,   135,
     114,    47,   101,   115,   116,   125,    62,    62,    47,    47,
      66,   111,   113,   136,   138,    46,    62,    66,   100,    69,
      61,   124,     6,    62,   136
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
        case 9:

/* Line 1455 of yacc.c  */
#line 86 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Numero Entero = %d\n", (yyvsp[(1) - (1)].valorEntero));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 87 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Numero Real = %.2f\n", (yyvsp[(1) - (1)].valorReal));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 88 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Caracter = %s\n", (yyvsp[(1) - (1)].valorString));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 92 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "ID = %s\n", (yyvsp[(1) - (1)].valorString));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 96 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \',\'\n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 104 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \': ?\'\n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 107 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'=\'\n"  );;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 108 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'*=\'\n" );;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 109 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'/=\'\n" );;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 110 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'%=\'\n" );;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 111 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'+=\'\n" );;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 112 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'-=\'\n" );;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 113 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'<<=\'\n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 114 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'>>=\'\n");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 115 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'&=\'\n" );;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 116 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'^=\'\n" );;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 117 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'|=\'\n" );;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 121 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'||\'\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 125 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'&&\'\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 129 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'|\'\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 133 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'^\'\n");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 137 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'&\'\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 141 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'==\'\n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 142 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'!=\'\n");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 146 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'<\'\n" );;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 147 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'>\'\n" );;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 148 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'<=\'\n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 149 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'>=\'\n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 153 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'<<\'\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 154 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'>>\'\n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 158 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'+\'\n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 159 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'-\'\n");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 163 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'*\'\n");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 164 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'/\'\n");}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 165 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'%\'\n");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 169 "../src/AnalizadorSintactico.y"
    {/*CAMBIAR POR nombre_tipo*/;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 173 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'++\'\n");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 174 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'--\'\n");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 177 "../src/AnalizadorSintactico.y"
    {/*CAMBIAR POR nombre_tipo*/;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 189 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'[\' y el \']\'\n");                                    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 190 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'(\' y el \')\'\n");                                    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 191 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'.\'\n"); fprintf(yyout, "ID = %s\n", (yyvsp[(3) - (3)].valorString)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 192 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'->\'\n"); fprintf(yyout, "ID = %s\n", (yyvsp[(3) - (3)].valorString));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 193 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'++\'\n");                                              ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 194 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'--\'\n");                                              ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 202 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "String = %s\n", (yyvsp[(1) - (1)].valorString));  ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 203 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'(\' y el \')\'\n");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 210 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "String = %s\n", (yyvsp[(1) - (2)].valorString));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 241 "../src/AnalizadorSintactico.y"
    {/*Sacamos nombre_typedef*/;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 244 "../src/AnalizadorSintactico.y"
    {/*Hay problemas con el typedef ya que no tiene un identificador final*/;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 305 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "ID = %s\n", (yyvsp[(1) - (1)].valorString));;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 405 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el IF\n");;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 406 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el IF y el ELSE\n");;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 407 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el SWITCH\n");;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 410 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el WHILE\n");;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 411 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el DO WHILE\n");;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 412 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el FOR\n");;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 415 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza un CASE\n");;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 416 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el DEFAULT\n");;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 420 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el CONTINUE o BREAK\n");;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 421 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el RETURN\n");;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 422 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el GOTO\n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2218 "AnalizadorSintactico.tab.c"
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
#line 438 "../src/AnalizadorSintactico.y"


int yyerror (char *mensaje)  /* Funcion de error */
{
  printf ("Error: %s\n", mensaje);
}

int printError(char *mensaje, int linea)
{
  fprintf(yyout, "Se encontro la cadena erronea: %s en la linea: %d\n", mensaje, linea);
}

void main(){ 

    yyin = fopen("Input.txt", "r");
    yyout = fopen("Salida.txt", "w");

    #ifdef BISON_DEBUG
       yydebug = 1;
    #endif
    
    yyparse();

    fclose(yyin);
    fclose(yyout);
}
