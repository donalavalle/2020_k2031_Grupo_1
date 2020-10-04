
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

unsigned count = 0; 

FILE* yyin;
FILE* yyout;



/* Line 189 of yacc.c  */
#line 93 "AnalizadorSintactico.tab.c"

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
#line 66 "../src/AnalizadorSintactico.y"

  int   valorEntero;
  double valorReal;
  char* valorString;



/* Line 214 of yacc.c  */
#line 182 "AnalizadorSintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 194 "AnalizadorSintactico.tab.c"

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
#define YYLAST   605

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  195
/* YYNRULES -- Number of states.  */
#define YYNSTATES  316

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
      20,    22,    24,    26,    28,    32,    34,    38,    40,    46,
      48,    50,    52,    54,    56,    58,    60,    62,    64,    66,
      68,    70,    74,    76,    80,    82,    86,    88,    92,    94,
      98,   100,   104,   108,   110,   114,   118,   122,   126,   128,
     132,   136,   138,   142,   146,   148,   152,   156,   160,   162,
     168,   170,   173,   176,   179,   182,   187,   189,   191,   193,
     195,   197,   199,   201,   206,   211,   215,   219,   222,   225,
     227,   231,   233,   235,   239,   242,   245,   248,   251,   252,
     254,   256,   260,   262,   266,   268,   273,   274,   276,   278,
     282,   284,   286,   288,   294,   297,   298,   300,   302,   305,
     309,   312,   315,   316,   318,   320,   324,   326,   330,   331,
     333,   335,   336,   338,   341,   342,   344,   347,   351,   352,
     354,   356,   359,   361,   365,   370,   375,   380,   381,   383,
     385,   391,   393,   397,   400,   403,   404,   406,   408,   412,
     418,   421,   423,   427,   429,   433,   435,   438,   440,   443,
     447,   452,   457,   458,   460,   461,   463,   465,   467,   469,
     471,   473,   475,   478,   479,   481,   486,   487,   489,   490,
     492,   494,   497,   499,   502,   508,   516,   522,   528,   536,
     546,   551,   555,   559,   562,   566
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      71,     0,    -1,    -1,    71,    72,    -1,    -1,    75,    46,
      -1,    95,    46,    -1,   136,    -1,     3,    -1,     4,    -1,
      28,    -1,    74,    -1,     6,    -1,    76,    -1,    75,    47,
      76,    -1,    77,    -1,    90,    78,    76,    -1,    79,    -1,
      79,    48,    75,    49,    77,    -1,    50,    -1,     7,    -1,
       8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,
      13,    -1,    14,    -1,    15,    -1,    16,    -1,    80,    -1,
      79,    22,    80,    -1,    81,    -1,    80,    21,    81,    -1,
      82,    -1,    81,    51,    82,    -1,    83,    -1,    82,    52,
      83,    -1,    84,    -1,    83,    53,    84,    -1,    85,    -1,
      84,    19,    85,    -1,    84,    20,    85,    -1,    86,    -1,
      85,    54,    86,    -1,    85,    55,    86,    -1,    85,    23,
      86,    -1,    85,    24,    86,    -1,    87,    -1,    86,    25,
      87,    -1,    86,    26,    87,    -1,    88,    -1,    87,    56,
      88,    -1,    87,    57,    88,    -1,    89,    -1,    88,    58,
      89,    -1,    88,    59,    89,    -1,    88,    60,    89,    -1,
      90,    -1,    61,   131,    62,    89,    90,    -1,    92,    -1,
      17,    90,    -1,    18,    90,    -1,    91,    89,    -1,    30,
      90,    -1,    30,    61,   131,    62,    -1,    53,    -1,    58,
      -1,    56,    -1,    57,    -1,    63,    -1,    64,    -1,    94,
      -1,    92,    65,    75,    66,    -1,    92,    61,    93,    62,
      -1,    92,    67,     6,    -1,    92,    27,     6,    -1,    92,
      17,    -1,    92,    18,    -1,    76,    -1,    93,    47,    76,
      -1,    73,    -1,    29,    -1,    61,    75,    62,    -1,    96,
      98,    -1,    31,    97,    -1,   103,    97,    -1,    32,    97,
      -1,    -1,    96,    -1,    99,    -1,    98,    47,    99,    -1,
     115,    -1,   115,    50,   100,    -1,    76,    -1,    68,   102,
     101,    69,    -1,    -1,    47,    -1,   100,    -1,   102,    47,
     100,    -1,     5,    -1,   104,    -1,   127,    -1,    33,   105,
      68,   106,    69,    -1,    33,     6,    -1,    -1,     6,    -1,
     107,    -1,   106,   107,    -1,   108,   110,    46,    -1,   103,
     109,    -1,    32,   109,    -1,    -1,   108,    -1,   111,    -1,
     110,    47,   111,    -1,   115,    -1,   112,    49,   113,    -1,
      -1,   115,    -1,    77,    -1,    -1,   113,    -1,   116,   120,
      -1,    -1,   117,    -1,    58,   118,    -1,    58,   118,   117,
      -1,    -1,   119,    -1,    32,    -1,   119,    32,    -1,     6,
      -1,    61,   115,    62,    -1,   120,    65,   114,    66,    -1,
     120,    61,   122,    62,    -1,   120,    61,   121,    62,    -1,
      -1,   126,    -1,   123,    -1,   123,    47,    67,    67,    67,
      -1,   124,    -1,   123,    47,   124,    -1,    96,   115,    -1,
      96,   125,    -1,    -1,   132,    -1,     6,    -1,   126,    47,
       6,    -1,    34,   105,    68,   128,    69,    -1,    34,     6,
      -1,   129,    -1,   128,    47,   129,    -1,   130,    -1,   130,
      50,   113,    -1,     6,    -1,   108,   125,    -1,   117,    -1,
     116,   133,    -1,    61,   132,    62,    -1,   134,    65,   114,
      66,    -1,   134,    61,   135,    62,    -1,    -1,   133,    -1,
      -1,   122,    -1,   137,    -1,   139,    -1,   144,    -1,   145,
      -1,   146,    -1,   147,    -1,   138,    46,    -1,    -1,    75,
      -1,    68,   140,   141,    69,    -1,    -1,   142,    -1,    -1,
     143,    -1,    95,    -1,   142,    95,    -1,   136,    -1,   143,
     136,    -1,    36,    61,    75,    62,   136,    -1,    36,    61,
      75,    62,   136,    37,   136,    -1,    38,    61,    75,    62,
     136,    -1,    41,    61,    75,    62,   136,    -1,    40,   136,
      41,    61,    75,    62,    46,    -1,    39,    61,   138,    46,
     138,    46,   138,    62,   136,    -1,    42,   113,    49,   136,
      -1,    43,    49,   136,    -1,     6,    49,   136,    -1,    35,
      46,    -1,    44,   138,    46,    -1,    45,     6,    46,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    75,    78,    79,    80,    81,    84,    85,
      86,    87,    90,    93,    94,    97,    98,   101,   102,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     118,   119,   122,   123,   126,   127,   130,   131,   134,   135,
     138,   139,   140,   143,   144,   145,   146,   147,   150,   151,
     152,   155,   156,   157,   160,   161,   162,   163,   166,   167,
     170,   171,   172,   173,   174,   175,   178,   179,   180,   181,
     182,   183,   186,   187,   188,   189,   190,   191,   192,   195,
     196,   199,   200,   201,   205,   208,   209,   210,   213,   214,
     217,   218,   221,   222,   225,   226,   229,   230,   233,   234,
     237,   238,   239,   242,   243,   246,   247,   250,   251,   254,
     257,   258,   261,   262,   265,   266,   269,   270,   273,   274,
     277,   280,   281,   284,   287,   288,   291,   292,   295,   296,
     299,   300,   303,   304,   305,   306,   307,   310,   311,   314,
     315,   318,   319,   322,   323,   326,   327,   330,   331,   334,
     335,   338,   339,   342,   343,   346,   349,   352,   353,   356,
     357,   358,   361,   362,   365,   366,   372,   373,   374,   375,
     376,   377,   380,   383,   384,   387,   390,   391,   394,   395,
     398,   399,   402,   403,   407,   408,   409,   412,   413,   414,
     417,   418,   419,   422,   423,   424
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
  "sentencia_etiquetada", "sentencia_salto", 0
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
       0,    70,    71,    71,    72,    72,    72,    72,    73,    73,
      73,    73,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    83,
      84,    84,    84,    85,    85,    85,    85,    85,    86,    86,
      86,    87,    87,    87,    88,    88,    88,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    94,    94,    94,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     108,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     113,   114,   114,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   120,   120,   120,   121,   121,   122,
     122,   123,   123,   124,   124,   125,   125,   126,   126,   127,
     127,   128,   128,   129,   129,   130,   131,   132,   132,   133,
     133,   133,   134,   134,   135,   135,   136,   136,   136,   136,
     136,   136,   137,   138,   138,   139,   140,   140,   141,   141,
     142,   142,   143,   143,   144,   144,   144,   145,   145,   145,
     146,   146,   146,   147,   147,   147
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     5,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     3,     3,     2,     2,     1,
       3,     1,     1,     3,     2,     2,     2,     2,     0,     1,
       1,     3,     1,     3,     1,     4,     0,     1,     1,     3,
       1,     1,     1,     5,     2,     0,     1,     1,     2,     3,
       2,     2,     0,     1,     1,     3,     1,     3,     0,     1,
       1,     0,     1,     2,     0,     1,     2,     3,     0,     1,
       1,     2,     1,     3,     4,     4,     4,     0,     1,     1,
       5,     1,     3,     2,     2,     0,     1,     1,     3,     5,
       2,     1,     3,     1,     3,     1,     2,     1,     2,     3,
       4,     4,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     0,     1,     4,     0,     1,     0,     1,
       1,     2,     1,     2,     5,     7,     5,     5,     7,     9,
       4,     3,     3,     2,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     1,     8,     9,   100,    12,     0,     0,    10,
      82,     0,    88,    88,   105,   105,     0,     0,     0,     0,
     173,     0,     0,     0,   173,     0,    66,    68,    69,    67,
       0,    70,    71,   176,     3,    81,    11,     0,    13,    15,
      17,    30,    32,    34,    36,    38,    40,    43,    48,    51,
      54,    58,     0,    60,    72,     0,   124,    88,   101,   102,
       7,   166,     0,   167,   168,   169,   170,   171,   173,    12,
       0,    61,    62,     0,    64,    89,    85,    87,   104,     0,
     150,     0,   193,     0,     0,   173,   174,     0,     0,   120,
      58,     0,   173,     0,     0,   112,     0,   112,   124,     0,
     180,   173,   177,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    19,     0,    63,    77,    78,     0,
       0,     0,     0,     6,   128,    84,    90,    92,     0,   125,
      86,   172,   192,     0,     0,     0,     0,     0,     0,     0,
       0,   173,   191,   194,   195,   113,   111,    83,   110,   162,
     125,   156,   146,     0,   182,     0,   173,   181,    14,    31,
       0,    33,    35,    37,    39,    41,    42,    46,    47,    44,
      45,    49,    50,    52,    53,    55,    56,    57,    16,    76,
      79,     0,     0,    75,   130,   126,   129,   124,     0,   132,
     124,   123,    65,     0,   107,   124,   155,     0,   151,   153,
     173,   173,   173,     0,   173,   190,   124,   158,     0,     0,
     175,   183,     0,     0,    74,    73,   127,   131,    91,     0,
      94,    93,     0,   137,   121,   103,   108,     0,   114,     0,
     116,     0,   149,     0,   184,   186,     0,     0,   187,     0,
     164,   121,    59,    18,    80,    98,    96,   133,   147,   124,
       0,     0,   139,   141,   138,   122,     0,   109,   124,     0,
     152,   154,   173,   173,     0,   159,   165,     0,     0,    97,
       0,   143,   162,   144,   136,   135,     0,     0,   134,   115,
     117,   185,     0,   188,   161,   160,    99,    95,   124,     0,
     142,   148,   173,     0,   189,   140
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    34,    35,    36,    86,    38,    39,   135,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,   201,    54,    55,    56,    76,   145,   146,
     241,   290,   266,    57,    58,    79,   213,   214,    98,   166,
     247,   248,   249,   275,   276,   147,   148,   149,   205,   206,
     211,   270,   271,   272,   273,   171,   274,    59,   217,   218,
     219,    99,   172,   227,   228,   287,    60,    61,    62,    63,
     101,   175,   102,   176,    64,    65,    66,    67
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -217
static const yytype_int16 yypact[] =
{
    -217,   265,  -217,  -217,  -217,  -217,   -13,   457,   457,  -217,
    -217,   494,    98,    98,    44,    50,    -7,     1,    17,    29,
     409,    35,   531,    10,   531,   120,  -217,  -217,  -217,  -217,
     475,  -217,  -217,    98,  -217,  -217,  -217,    -2,  -217,  -217,
      -5,   124,    87,    95,   102,    11,     3,   158,   150,   138,
    -217,   555,   531,    34,  -217,   146,   106,    98,  -217,  -217,
    -217,  -217,   148,  -217,  -217,  -217,  -217,  -217,   409,  -217,
     531,  -217,  -217,   475,  -217,  -217,  -217,  -217,   131,   140,
     131,   153,  -217,   531,   531,   531,   155,   173,   531,  -217,
    -217,   169,   409,   182,   187,   134,   -15,   134,    22,   178,
    -217,   313,    98,  -217,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,  -217,  -217,  -217,  -217,  -217,  -217,
    -217,  -217,  -217,  -217,  -217,   531,  -217,  -217,  -217,   237,
     531,   531,   238,  -217,   213,   199,  -217,   197,     9,  -217,
    -217,  -217,  -217,   186,   134,   245,    24,    27,   206,   192,
      36,   409,  -217,  -217,  -217,  -217,  -217,  -217,  -217,   193,
      86,  -217,  -217,   531,  -217,   188,   361,  -217,  -217,   124,
     132,    87,    95,   102,    11,     3,     3,   158,   158,   158,
     158,   150,   150,   138,   138,  -217,  -217,  -217,  -217,  -217,
    -217,   107,   -12,  -217,  -217,   106,   223,   106,   159,  -217,
     106,   117,  -217,     8,  -217,   -21,  -217,   -36,  -217,   209,
     409,   409,   531,   531,   409,  -217,   106,   125,   130,   457,
    -217,  -217,   531,   531,  -217,  -217,  -217,  -217,  -217,   159,
    -217,  -217,   194,   118,   531,  -217,  -217,   164,  -217,   212,
     215,   245,  -217,   531,   230,  -217,   226,   113,  -217,   211,
      98,   531,  -217,  -217,  -217,  -217,   227,  -217,  -217,    99,
     216,   217,   233,  -217,   234,  -217,   218,  -217,   -21,   531,
    -217,  -217,   409,   531,   231,  -217,  -217,   224,   221,   159,
     219,  -217,    15,  -217,  -217,  -217,    33,   283,  -217,  -217,
    -217,  -217,   228,  -217,  -217,  -217,  -217,  -217,   106,   235,
    -217,  -217,   409,   244,  -217,  -217
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -217,  -217,  -217,  -217,  -217,    52,   -80,   -19,  -217,  -217,
     207,   184,   205,   225,   204,   119,    58,   121,   116,   -30,
      -3,  -217,  -217,  -217,  -217,   -23,   -11,    12,  -217,   108,
    -216,  -217,  -217,   -10,  -217,   305,  -217,   111,   -79,   239,
    -217,    47,  -217,   -16,    66,  -181,   -89,   -84,  -217,  -217,
    -217,  -217,    72,  -217,    39,    68,  -217,  -217,  -217,    88,
    -217,   267,  -214,  -217,  -217,  -217,   -20,  -217,   -17,  -217,
    -217,  -217,  -217,  -217,  -217,  -217,  -217,  -217
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -180
static const yytype_int16 yytable[] =
{
      87,    75,    75,    89,    71,    72,    91,    93,    74,   169,
     100,   251,   259,     5,   170,   209,   165,   105,   165,    90,
      97,   209,   136,   265,   178,    77,   113,   114,  -118,   242,
     111,   112,   104,   252,   250,   104,    68,   144,     5,    82,
      95,    14,    15,   106,   103,   104,    75,   167,   152,    90,
      78,   137,   138,    37,   235,   198,    80,   115,   116,    92,
     200,   139,    83,    97,    12,    13,    14,    15,   158,   150,
     210,   104,   162,   306,   104,   215,   308,   245,    84,   177,
     144,   174,    96,   104,  -145,    97,   220,    97,   291,   221,
      85,   195,   196,   197,   259,   140,    88,   250,   224,   141,
     309,   142,    90,     5,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,   236,    96,     5,   268,    96,    94,   242,   240,    12,
      13,    14,    15,  -157,   215,   156,   157,   169,   108,     5,
     160,   225,   170,   229,    97,   107,  -145,   109,  -157,    12,
      13,    14,    15,   264,   233,   110,   231,   144,   180,   240,
     104,  -145,     3,     4,   144,    69,    95,    14,    15,   234,
      90,   187,   188,   189,   190,   284,     7,     8,   243,   104,
     292,   232,   244,   117,   118,   170,  -163,     9,    10,    11,
    -163,   260,   143,   202,   151,   261,   121,   122,   123,  -106,
     254,   255,   104,    97,   258,   256,   119,   120,   154,   240,
     277,   278,    26,   263,   159,    27,    28,    29,   161,   292,
      30,   155,    31,    32,   170,    89,   262,   239,   163,    90,
     185,   186,   269,   164,    89,   193,   194,   281,   191,   192,
     173,    90,    89,   199,   203,   204,   207,   208,   212,   269,
      90,   216,   222,   223,   226,   237,   267,   230,    90,   253,
      89,   279,   301,   300,  -119,     2,   302,   282,     3,     4,
       5,     6,   283,   285,   289,   257,    90,   303,   294,   295,
     296,   297,     7,     8,   298,   269,   304,   305,   307,   311,
     312,   181,   314,     9,    10,    11,    12,    13,    14,    15,
      16,    17,   313,    18,    19,    20,    21,    22,    23,    24,
      25,   315,   179,   182,   184,   238,     3,     4,    26,     6,
      81,    27,    28,    29,   246,   299,    30,   288,    31,    32,
       7,     8,   286,    33,   183,   310,   168,   293,     0,   280,
     153,     9,    10,    11,     0,     0,     0,     0,    16,    17,
       0,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     3,     4,    26,     6,     0,    27,
      28,    29,     0,     0,    30,     0,    31,    32,     7,     8,
       0,    33,  -178,     0,     0,     0,     0,     0,     0,     9,
      10,    11,     0,     0,     0,     0,    16,    17,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     3,     4,    26,     6,     0,    27,    28,    29,
       0,     0,    30,     0,    31,    32,     7,     8,     0,    33,
    -179,     0,     0,     0,     0,     0,     0,     9,    10,    11,
       0,     0,     0,     0,    16,    17,     0,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       3,     4,    26,    69,     0,    27,    28,    29,     0,     0,
      30,     0,    31,    32,     7,     8,     0,    33,     3,     4,
       5,    69,     0,     0,     0,     9,    10,    11,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     3,     4,     0,
      69,     0,     0,     9,    10,    11,     0,    95,    14,    15,
      26,     7,     8,    27,    28,    29,     0,     0,    70,     0,
      31,    32,     9,    10,    11,     0,     0,     0,    26,     0,
       0,    27,    28,    29,     3,     4,    30,    69,    31,    32,
       0,     0,     0,     0,     0,     0,     0,    26,     7,     8,
      27,    28,    29,     0,     0,    73,     0,    31,    32,     9,
      10,    11,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,    27,    28,    29,
       0,     0,    30,     0,    31,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134
};

static const yytype_int16 yycheck[] =
{
      20,    12,    13,    22,     7,     8,    22,    24,    11,    98,
      33,    47,   226,     5,    98,     6,    95,    22,    97,    22,
      30,     6,    52,   239,   104,    13,    23,    24,    49,   210,
      19,    20,    47,    69,   215,    47,    49,    58,     5,    46,
      32,    33,    34,    48,    46,    47,    57,    62,    68,    52,
       6,    17,    18,     1,    66,   135,     6,    54,    55,    49,
     140,    27,    61,    73,    31,    32,    33,    34,    85,    57,
      61,    47,    92,   289,    47,   154,    61,    69,    61,   102,
      58,   101,    30,    47,    62,    95,    62,    97,   269,    62,
      61,   121,   122,   123,   308,    61,    61,   278,    62,    65,
      67,    67,   105,     5,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   205,    70,     5,     6,    73,     6,   308,   208,    31,
      32,    33,    34,    47,   213,    83,    84,   226,    51,     5,
      88,   161,   226,   173,   154,    21,    47,    52,    62,    31,
      32,    33,    34,   233,    47,    53,   176,    58,   106,   239,
      47,    62,     3,     4,    58,     6,    32,    33,    34,    62,
     173,   113,   114,   115,   116,    62,    17,    18,    61,    47,
     269,    49,    65,    25,    26,   269,    61,    28,    29,    30,
      65,    61,    46,   141,    46,    65,    58,    59,    60,    68,
     220,   221,    47,   213,   224,   222,    56,    57,    68,   289,
      46,    47,    53,   232,    41,    56,    57,    58,    49,   308,
      61,    68,    63,    64,   308,   244,   229,    68,    46,   232,
     111,   112,   243,    46,   253,   119,   120,   253,   117,   118,
      62,   244,   261,     6,     6,    32,    47,    50,    62,   260,
     253,     6,    46,    61,    61,    32,    62,    69,   261,    50,
     279,    49,   282,   279,    49,     0,   283,    37,     3,     4,
       5,     6,    46,    62,    47,   223,   279,    46,    62,    62,
      47,    47,    17,    18,    66,   296,    62,    66,    69,     6,
      62,   107,   312,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    67,    38,    39,    40,    41,    42,    43,    44,
      45,    67,   105,   108,   110,   207,     3,     4,    53,     6,
      15,    56,    57,    58,   213,   278,    61,   261,    63,    64,
      17,    18,   260,    68,   109,   296,    97,   269,    -1,   251,
      73,    28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,     3,     4,    53,     6,    -1,    56,
      57,    58,    -1,    -1,    61,    -1,    63,    64,    17,    18,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,     3,     4,    53,     6,    -1,    56,    57,    58,
      -1,    -1,    61,    -1,    63,    64,    17,    18,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      -1,    -1,    -1,    -1,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
       3,     4,    53,     6,    -1,    56,    57,    58,    -1,    -1,
      61,    -1,    63,    64,    17,    18,    -1,    68,     3,     4,
       5,     6,    -1,    -1,    -1,    28,    29,    30,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,     3,     4,    -1,
       6,    -1,    -1,    28,    29,    30,    -1,    32,    33,    34,
      53,    17,    18,    56,    57,    58,    -1,    -1,    61,    -1,
      63,    64,    28,    29,    30,    -1,    -1,    -1,    53,    -1,
      -1,    56,    57,    58,     3,     4,    61,     6,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    17,    18,
      56,    57,    58,    -1,    -1,    61,    -1,    63,    64,    28,
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    58,
      -1,    -1,    61,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50
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
     136,   137,   138,   139,   144,   145,   146,   147,    49,     6,
      61,    90,    90,    61,    90,    96,    97,    97,     6,   105,
       6,   105,    46,    61,    61,    61,    75,   136,    61,    77,
      90,   113,    49,   138,     6,    32,    75,   103,   108,   131,
      95,   140,   142,    46,    47,    22,    48,    21,    51,    52,
      53,    19,    20,    23,    24,    54,    55,    25,    26,    56,
      57,    58,    59,    60,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    50,    78,    89,    17,    18,    27,
      61,    65,    67,    46,    58,    98,    99,   115,   116,   117,
      97,    46,   136,   131,    68,    68,    75,    75,   138,    41,
      75,    49,   136,    46,    46,   108,   109,    62,   109,   116,
     117,   125,   132,    62,   136,   141,   143,    95,    76,    80,
      75,    81,    82,    83,    84,    85,    85,    86,    86,    86,
      86,    87,    87,    88,    88,    89,    89,    89,    76,     6,
      76,    93,    75,     6,    32,   118,   119,    47,    50,     6,
      61,   120,    62,   106,   107,   108,     6,   128,   129,   130,
      62,    62,    46,    61,    62,   136,    61,   133,   134,    89,
      69,   136,    49,    47,    62,    66,   117,    32,    99,    68,
      76,   100,   115,    61,    65,    69,   107,   110,   111,   112,
     115,    47,    69,    50,   136,   136,   138,    75,   136,   132,
      61,    65,    90,    77,    76,   100,   102,    62,     6,    96,
     121,   122,   123,   124,   126,   113,   114,    46,    47,    49,
     129,   113,    37,    46,    62,    62,   122,   135,   114,    47,
     101,   115,   116,   125,    62,    62,    47,    47,    66,   111,
     113,   136,   138,    46,    62,    66,   100,    69,    61,    67,
     124,     6,    62,    67,   136,    67
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
#line 84 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Numero Entero = %d\n", (yyvsp[(1) - (1)].valorEntero));;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 85 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Numero Real = %.2f\n", (yyvsp[(1) - (1)].valorReal));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 86 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Caracter = %s\n", (yyvsp[(1) - (1)].valorString));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 90 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "ID = %s\n", (yyvsp[(1) - (1)].valorString));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 94 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \',\'\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 102 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \': ?\'\n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 105 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'=\'\n"  );;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 106 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'*=\'\n" );;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 107 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'/=\'\n" );;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 108 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'%=\'\n" );;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 109 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'+=\'\n" );;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 110 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'-=\'\n" );;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 111 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'<<=\'\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 112 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'>>=\'\n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 113 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'&=\'\n" );;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 114 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'^=\'\n" );;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 115 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'|=\'\n" );;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 119 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'||\'\n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 123 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'&&\'\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 127 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'|\'\n");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 131 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'^\'\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 135 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'&\'\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 139 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'==\'\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 140 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'!=\'\n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 144 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'<\'\n" );;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 145 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'>\'\n" );;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 146 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'<=\'\n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 147 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'>=\'\n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 151 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'<<\'\n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 152 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'>>\'\n");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 156 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'+\'\n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 157 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'-\'\n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 161 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'*\'\n");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 162 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'/\'\n");}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 163 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'%\'\n");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 167 "../src/AnalizadorSintactico.y"
    {/*CAMBIAR POR nombre_tipo*/;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 171 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'++\'\n");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 172 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'--\'\n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 175 "../src/AnalizadorSintactico.y"
    {/*CAMBIAR POR nombre_tipo*/;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 187 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'[\' y el \']\'\n");                                    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 188 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'(\' y el \')\'\n");                                    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 189 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'.\'\n"); fprintf(yyout, "ID = %s\n", (yyvsp[(3) - (3)].valorString)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 190 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'->\'\n"); fprintf(yyout, "ID = %s\n", (yyvsp[(3) - (3)].valorString));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 191 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'++\'\n");                                              ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 192 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'--\'\n");                                              ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 200 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "String = %s\n", (yyvsp[(1) - (1)].valorString));  ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 201 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'(\' y el \')\'\n");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 208 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "String = %s\n", (yyvsp[(1) - (2)].valorString));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 239 "../src/AnalizadorSintactico.y"
    {/*Sacamos nombre_typedef*/;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 242 "../src/AnalizadorSintactico.y"
    {/*Hay problemas con el typedef ya que no tiene un identificador final*/;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 303 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "ID = %s\n", (yyvsp[(1) - (1)].valorString));;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 407 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el IF\n");;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 408 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el IF y el ELSE\n");;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 409 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el SWITCH\n");;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 412 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el WHILE\n");;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 413 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el DO WHILE\n");;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 414 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el FOR\n");;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 417 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza un CASE\n");;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 418 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el DEFAULT\n");;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 422 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el CONTINUE o BREAK\n");;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 423 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el RETURN\n");;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 424 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el GOTO\n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2207 "AnalizadorSintactico.tab.c"
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
#line 427 "../src/AnalizadorSintactico.y"


int yyerror (char *mensaje)  /* Funcion de error */
{
  printf ("Error: %s\n", mensaje);
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
