
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
     ENUM = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 57 "../src/AnalizadorSintactico.y"

  int   valorEntero;
  double valorReal;
  char* valorString;



/* Line 214 of yacc.c  */
#line 171 "AnalizadorSintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 183 "AnalizadorSintactico.tab.c"

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
#define YYLAST   364

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNRULES -- Number of states.  */
#define YYNSTATES  247

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,     2,     2,    50,    43,     2,
      51,    52,    48,    46,    38,    47,    57,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    37,
      44,     3,    45,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    41,    59,    53,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    17,    19,
      21,    23,    25,    27,    31,    33,    37,    39,    45,    47,
      49,    51,    53,    55,    57,    59,    61,    63,    65,    67,
      69,    73,    75,    79,    81,    85,    87,    91,    93,    97,
      99,   103,   107,   109,   113,   117,   121,   125,   127,   131,
     135,   137,   141,   145,   147,   151,   155,   159,   161,   167,
     169,   172,   175,   178,   181,   186,   188,   190,   192,   194,
     196,   198,   200,   205,   210,   214,   218,   221,   224,   226,
     230,   232,   234,   238,   241,   242,   244,   247,   250,   253,
     254,   256,   258,   262,   264,   268,   270,   275,   276,   278,
     280,   284,   286,   288,   290,   296,   299,   300,   302,   304,
     307,   311,   314,   317,   318,   320,   322,   326,   328,   332,
     333,   335,   337,   338,   340,   343,   344,   346,   349,   353,
     354,   356,   358,   361,   363,   367,   372,   377,   382,   383,
     385,   387,   393,   395,   399,   402,   405,   406,   408,   410,
     414,   420,   423,   425,   429,   431,   435,   437,   440,   442,
     445,   449,   454,   459,   460,   462,   463
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      61,     0,    -1,    -1,    61,    62,    -1,    36,    -1,    65,
      37,    -1,    85,    37,    -1,     4,    -1,     5,    -1,    29,
      -1,    64,    -1,     7,    -1,    66,    -1,    65,    38,    66,
      -1,    67,    -1,    80,    68,    66,    -1,    69,    -1,    69,
      39,    65,    40,    67,    -1,     3,    -1,     8,    -1,     9,
      -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,    14,
      -1,    15,    -1,    16,    -1,    17,    -1,    70,    -1,    69,
      23,    70,    -1,    71,    -1,    70,    22,    71,    -1,    72,
      -1,    71,    41,    72,    -1,    73,    -1,    72,    42,    73,
      -1,    74,    -1,    73,    43,    74,    -1,    75,    -1,    74,
      20,    75,    -1,    74,    21,    75,    -1,    76,    -1,    75,
      44,    76,    -1,    75,    45,    76,    -1,    75,    24,    76,
      -1,    75,    25,    76,    -1,    77,    -1,    76,    26,    77,
      -1,    76,    27,    77,    -1,    78,    -1,    77,    46,    78,
      -1,    77,    47,    78,    -1,    79,    -1,    78,    48,    79,
      -1,    78,    49,    79,    -1,    78,    50,    79,    -1,    80,
      -1,    51,   122,    52,    79,    80,    -1,    82,    -1,    18,
      80,    -1,    19,    80,    -1,    81,    79,    -1,    31,    80,
      -1,    31,    51,   122,    52,    -1,    43,    -1,    48,    -1,
      46,    -1,    47,    -1,    53,    -1,    54,    -1,    84,    -1,
      82,    55,    65,    56,    -1,    82,    51,    83,    52,    -1,
      82,    57,     7,    -1,    82,    28,     7,    -1,    82,    18,
      -1,    82,    19,    -1,    66,    -1,    83,    38,    66,    -1,
      63,    -1,    30,    -1,    51,    65,    52,    -1,    87,    86,
      -1,    -1,    89,    -1,    32,    88,    -1,    94,    88,    -1,
      33,    88,    -1,    -1,    87,    -1,    90,    -1,    89,    38,
      90,    -1,   106,    -1,   106,     3,    91,    -1,    66,    -1,
      58,    93,    92,    59,    -1,    -1,    38,    -1,    91,    -1,
      93,    38,    91,    -1,     6,    -1,    95,    -1,   118,    -1,
      34,    96,    58,    97,    59,    -1,    34,     7,    -1,    -1,
       7,    -1,    98,    -1,    97,    98,    -1,    99,   101,    37,
      -1,    94,   100,    -1,    33,   100,    -1,    -1,    99,    -1,
     102,    -1,   101,    38,   102,    -1,   106,    -1,   103,    40,
     104,    -1,    -1,   106,    -1,    67,    -1,    -1,   104,    -1,
     107,   111,    -1,    -1,   108,    -1,    48,   109,    -1,    48,
     109,   108,    -1,    -1,   110,    -1,    33,    -1,   110,    33,
      -1,     7,    -1,    51,   106,    52,    -1,   111,    55,   105,
      56,    -1,   111,    51,   113,    52,    -1,   111,    51,   112,
      52,    -1,    -1,   117,    -1,   114,    -1,   114,    38,    57,
      57,    57,    -1,   115,    -1,   114,    38,   115,    -1,    87,
     106,    -1,    87,   116,    -1,    -1,   123,    -1,     7,    -1,
     117,    38,     7,    -1,    35,    96,    58,   119,    59,    -1,
      35,     7,    -1,   120,    -1,   119,    38,   120,    -1,   121,
      -1,   121,     3,   104,    -1,     7,    -1,    99,   116,    -1,
     108,    -1,   107,   124,    -1,    51,   123,    52,    -1,   125,
      55,   105,    56,    -1,   125,    51,   126,    52,    -1,    -1,
     124,    -1,    -1,   113,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    66,    69,    70,    71,    74,    75,    76,
      77,    80,    83,    84,    87,    88,    91,    92,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   108,
     109,   112,   113,   116,   117,   120,   121,   124,   125,   128,
     129,   130,   133,   134,   135,   136,   137,   140,   141,   142,
     145,   146,   147,   150,   151,   152,   153,   156,   157,   160,
     161,   162,   163,   164,   165,   168,   169,   170,   171,   172,
     173,   176,   177,   178,   179,   180,   181,   182,   185,   186,
     189,   190,   191,   195,   198,   199,   202,   203,   204,   207,
     208,   211,   212,   215,   216,   219,   220,   223,   224,   227,
     228,   231,   232,   233,   236,   237,   240,   241,   244,   245,
     248,   251,   252,   255,   256,   259,   260,   263,   264,   267,
     268,   271,   274,   275,   278,   281,   282,   285,   286,   289,
     290,   293,   294,   297,   298,   299,   300,   301,   304,   305,
     308,   309,   312,   313,   316,   317,   320,   321,   324,   325,
     328,   329,   332,   333,   336,   337,   340,   343,   346,   347,
     350,   351,   352,   355,   356,   359,   360
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "NUM_ENTERO", "NUM_REAL",
  "TIPO_DATO", "ID", "ASIG_MULT", "ASIG_DIV", "ASIG_MOD", "ASIG_SUMA",
  "ASIG_RESTA", "ASIG_DESP_IZQ", "ASIG_DESP_DER", "ASIG_AND_BIN",
  "ASIG_XOR_BIN", "ASIG_OR_BIN", "OP_INC", "OP_DEC", "OP_IGUALDAD",
  "OP_DESIGUALDAD", "OP_AND", "OP_OR", "OP_MENOR_IGUAL", "OP_MAYOR_IGUAL",
  "OP_DESP_IZQ", "OP_DESP_DER", "OP_MIEMBRO_PUNT", "CHAR", "STRING",
  "SIZEOF", "CLASE_ALM", "CALIF_TIPO", "STRUCT_UNION", "ENUM", "'\\n'",
  "';'", "','", "'?'", "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'('", "')'", "'~'", "'!'", "'['", "']'",
  "'.'", "'{'", "'}'", "$accept", "input", "line", "const", "const_enum",
  "expresion", "exp_asignacion", "exp_condicional", "op_asignacion",
  "exp_OR_log", "exp_AND_log", "exp_OR_in", "exp_OR_ex", "exp_AND",
  "exp_igualdad", "exp_relacional", "exp_desp", "exp_aditiva",
  "exp_multip", "exp_conversion", "exp_unaria", "op_unario", "exp_sufijo",
  "lista_argumentos", "exp_primaria", "declaracion",
  "lista_declaradores_opc", "especificadores_declaracion",
  "especificadores_declaracion_opc", "lista_declaradores", "declarador",
  "inicializador", "coma_opc", "lista_inicializadores",
  "especificador_tipo", "especificador_struct_union", "ID_opc",
  "lista_declaradores_struct", "declaracion_struct", "lista_calificadores",
  "lista_calificadores_opc", "declaradores_struct", "decla_struct",
  "decla_opc", "exp_constante", "exp_constante_opc", "decla",
  "puntero_opc", "puntero", "lista_calificadores_tipos_opc",
  "lista_calificadores_tipos", "declarador_directo",
  "lista_identificadores_opc", "lista_tipos_param", "lista_parametros",
  "declaracion_parametro", "declarador_abstracto_opc",
  "lista_identificadores", "especificador_enum", "lista_enumeradores",
  "enumerador", "const_de_enumeracion", "nombre_tipo",
  "declarador_abstracto", "declarador_abstracto_directo",
  "declarador_abstracto_directo_opc", "lista_tipos_param_opc", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    61,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,    10,    59,    44,    63,
      58,   124,    94,    38,    60,    62,    43,    45,    42,    47,
      37,    40,    41,   126,    33,    91,    93,    46,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    62,    63,    63,    63,
      63,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    75,    75,    75,    75,    75,    76,    76,    76,
      77,    77,    77,    78,    78,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    83,    83,
      84,    84,    84,    85,    86,    86,    87,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    99,    99,   100,   100,   101,   101,   102,   102,   103,
     103,   104,   105,   105,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   116,   116,   117,   117,
     118,   118,   119,   119,   120,   120,   121,   122,   123,   123,
     124,   124,   124,   125,   125,   126,   126
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     5,     1,
       2,     2,     2,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     3,     3,     2,     2,     1,     3,
       1,     1,     3,     2,     0,     1,     2,     2,     2,     0,
       1,     1,     3,     1,     3,     1,     4,     0,     1,     1,
       3,     1,     1,     1,     5,     2,     0,     1,     1,     2,
       3,     2,     2,     0,     1,     1,     3,     1,     3,     0,
       1,     1,     0,     1,     2,     0,     1,     2,     3,     0,
       1,     1,     2,     1,     3,     4,     4,     4,     0,     1,
       1,     5,     1,     3,     2,     2,     0,     1,     1,     3,
       5,     2,     1,     3,     1,     3,     1,     2,     1,     2,
       3,     4,     4,     0,     1,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,     8,   101,    11,     0,     0,     9,
      81,     0,    89,    89,   106,   106,     4,    65,    67,    68,
      66,     0,    69,    70,     3,    80,    10,     0,    12,    14,
      16,    29,    31,    33,    35,    37,    39,    42,    47,    50,
      53,    57,     0,    59,    71,     0,   125,    89,   102,   103,
       0,    60,    61,     0,    63,    90,    86,    88,   105,     0,
     151,     0,   113,     0,   113,   125,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      62,    57,    76,    77,     0,     0,     0,     0,     6,   129,
      83,    85,    91,    93,     0,   126,    87,     0,     0,     0,
     114,   112,    82,   111,   163,   126,   157,   147,     0,    13,
      30,     0,    32,    34,    36,    38,    40,    41,    45,    46,
      43,    44,    48,    49,    51,    52,    54,    55,    56,    15,
      75,    78,     0,     0,    74,   131,   127,   130,   125,     0,
     133,   125,   124,    64,     0,   108,   125,   156,     0,   152,
     154,   125,   159,     0,     0,     0,     0,    73,    72,   128,
     132,    92,     0,    95,    94,     0,   138,   122,   104,   109,
       0,   115,     0,   117,     0,   150,     0,     0,   165,   122,
      58,    17,    79,    99,    97,   134,   148,   125,     0,     0,
     140,   142,   139,   121,   123,     0,   110,   125,     0,   153,
     155,   160,   166,     0,     0,    98,     0,   144,   163,   145,
     137,   136,     0,     0,   135,   116,   118,   162,   161,   100,
      96,   125,     0,   143,   149,     0,   141
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,    25,    26,    63,    28,    29,    99,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
     101,    42,    43,   152,    44,    45,   110,    55,    56,   111,
     112,   184,   226,   204,    47,    48,    59,   164,   165,    65,
     121,   190,   191,   192,   214,   215,   113,   114,   115,   156,
     157,   162,   208,   209,   210,   211,   126,   212,    49,   168,
     169,   170,    66,   127,   172,   173,   223
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -183
static const yytype_int16 yypact[] =
{
    -183,   186,  -183,  -183,  -183,  -183,  -183,   246,   246,  -183,
    -183,   291,   101,   101,    17,    76,  -183,  -183,  -183,  -183,
    -183,   237,  -183,  -183,  -183,  -183,  -183,    39,  -183,  -183,
      49,    70,    -9,    52,    67,   133,    56,   138,   134,   139,
    -183,   347,   300,    68,  -183,    83,    37,   101,  -183,  -183,
     300,  -183,  -183,   237,  -183,  -183,  -183,  -183,    66,    85,
      66,    89,   116,   -13,   116,    69,    74,  -183,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,   300,
    -183,  -183,  -183,  -183,   151,   300,   300,   159,  -183,   135,
    -183,   137,  -183,   170,     3,  -183,  -183,   125,   116,   189,
    -183,  -183,  -183,  -183,   149,    13,  -183,  -183,   300,  -183,
      70,    51,    -9,    52,    67,   133,    56,    56,   138,   138,
     138,   138,   134,   134,   139,   139,  -183,  -183,  -183,  -183,
    -183,  -183,    26,   -18,  -183,  -183,   155,   173,   155,   109,
    -183,   155,   -21,  -183,    25,  -183,    42,  -183,   -12,  -183,
     204,   155,    86,    91,   246,   300,   300,  -183,  -183,  -183,
    -183,  -183,   109,  -183,  -183,   156,    97,   300,  -183,  -183,
     146,  -183,   169,   171,   189,  -183,   300,   158,   101,   300,
    -183,  -183,  -183,  -183,   174,  -183,  -183,   -19,   161,   162,
     185,  -183,   188,  -183,  -183,   168,  -183,    42,   300,  -183,
    -183,  -183,  -183,   175,   172,   109,   176,  -183,    11,  -183,
    -183,  -183,    10,   223,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,   155,   179,  -183,  -183,   181,  -183
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,  -183,  -183,     5,   -64,  -147,  -183,  -183,
     177,   178,   180,   184,   187,   119,    92,   117,   118,   -30,
       0,  -183,  -183,  -183,  -183,  -183,  -183,    -1,    14,  -183,
      87,  -159,  -183,  -183,   -16,  -183,   232,  -183,    84,   -49,
     190,  -183,    41,  -183,  -182,    60,  -144,   -62,   -63,  -183,
    -183,  -183,  -183,    62,  -183,    30,    71,  -183,  -183,  -183,
      75,  -183,   210,  -162,  -183,  -183,  -183
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -165
static const yytype_int16 yytable[] =
{
      46,    41,   125,   124,   129,    64,    27,    51,    52,   197,
     160,    54,   100,   120,   220,   120,     5,   185,   160,  -146,
      68,    41,   193,   203,    58,    68,   194,    57,   201,   109,
     186,     5,    72,  -146,   187,   149,   236,    64,   178,   122,
     213,   151,    12,    13,    14,    15,    64,   195,    64,   213,
      41,  -158,   213,    41,   161,   146,   147,   148,    62,    14,
      15,   116,   241,   227,   176,  -158,   239,   242,    41,   166,
      41,   213,    69,   193,   -84,   131,    67,    68,   177,   197,
      77,    78,  -119,    60,   188,   109,   102,   103,    70,    68,
     109,   175,    71,   179,    73,   183,   104,   185,   174,    41,
      79,    80,    64,     5,   206,    41,    41,     5,   125,   124,
      74,   153,   202,     3,     4,   166,     6,   109,   183,   105,
     108,  -146,     5,   106,  -107,   107,   128,     7,     8,    12,
      13,    14,    15,    12,    13,    14,    15,  -164,     9,    10,
      11,  -164,   198,   118,   125,   228,   199,   119,    64,    62,
      14,    15,    17,    75,    76,    18,    19,    20,   150,    41,
      21,   183,    22,    23,    81,    82,   154,   182,   155,   138,
     139,   140,   141,   159,   200,   158,    41,   163,   125,   228,
      83,    84,    41,   216,   217,   207,     2,    85,    86,    87,
       3,     4,     5,     6,   136,   137,   167,   207,   142,   143,
     171,   144,   145,   109,     7,     8,   180,   196,   205,   218,
     221,  -120,   225,   230,   231,     9,    10,    11,    12,    13,
      14,    15,    16,   232,   234,    41,   233,   237,   238,    17,
     244,   207,    18,    19,    20,   240,   245,    21,   246,    22,
      23,     3,     4,     5,     6,   181,   130,    61,   189,   132,
       3,     4,   133,     6,   123,     7,     8,   134,   235,   224,
     222,   135,   243,   117,     7,     8,     9,    10,    11,   219,
      62,    14,    15,     0,     0,     9,    10,    11,   229,     0,
      17,     0,     0,    18,    19,    20,     0,     0,    21,    17,
      22,    23,    18,    19,    20,     3,     4,    50,     6,    22,
      23,     0,     0,     0,     3,     4,     0,     6,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       9,    10,    11,     0,     0,     0,     0,     0,     0,     9,
      10,    11,     0,     0,    17,     0,     0,    18,    19,    20,
       0,     0,    53,    17,    22,    23,    18,    19,    20,     0,
      88,    21,     0,    22,    23,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98
};

static const yytype_int16 yycheck[] =
{
       1,     1,    65,    65,    68,    21,     1,     7,     8,   171,
       7,    11,    42,    62,   196,    64,     6,   161,     7,    38,
      38,    21,   166,   182,     7,    38,    38,    13,   175,    48,
      51,     6,    41,    52,    55,    99,   218,    53,    56,    52,
     187,   105,    32,    33,    34,    35,    62,    59,    64,   196,
      50,    38,   199,    53,    51,    85,    86,    87,    33,    34,
      35,    47,    51,   207,    38,    52,   225,    57,    68,   118,
      70,   218,    23,   217,    37,    70,    37,    38,    52,   241,
      24,    25,    40,     7,    59,    48,    18,    19,    39,    38,
      48,    40,    22,   156,    42,   159,    28,   241,   128,    99,
      44,    45,   118,     6,     7,   105,   106,     6,   171,   171,
      43,   106,   176,     4,     5,   164,     7,    48,   182,    51,
      37,    52,     6,    55,    58,    57,    52,    18,    19,    32,
      33,    34,    35,    32,    33,    34,    35,    51,    29,    30,
      31,    55,    51,    58,   207,   207,    55,    58,   164,    33,
      34,    35,    43,    20,    21,    46,    47,    48,     7,   159,
      51,   225,    53,    54,    26,    27,     7,    58,    33,    77,
      78,    79,    80,     3,   174,    38,   176,    52,   241,   241,
      46,    47,   182,    37,    38,   186,     0,    48,    49,    50,
       4,     5,     6,     7,    75,    76,     7,   198,    81,    82,
      51,    83,    84,    48,    18,    19,    33,     3,    52,    40,
      52,    40,    38,    52,    52,    29,    30,    31,    32,    33,
      34,    35,    36,    38,    56,   225,    38,    52,    56,    43,
       7,   232,    46,    47,    48,    59,    57,    51,    57,    53,
      54,     4,     5,     6,     7,   158,    69,    15,   164,    71,
       4,     5,    72,     7,    64,    18,    19,    73,   217,   199,
     198,    74,   232,    53,    18,    19,    29,    30,    31,   194,
      33,    34,    35,    -1,    -1,    29,    30,    31,   207,    -1,
      43,    -1,    -1,    46,    47,    48,    -1,    -1,    51,    43,
      53,    54,    46,    47,    48,     4,     5,    51,     7,    53,
      54,    -1,    -1,    -1,     4,     5,    -1,     7,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    -1,    -1,    43,    -1,    -1,    46,    47,    48,
      -1,    -1,    51,    43,    53,    54,    46,    47,    48,    -1,
       3,    51,    -1,    53,    54,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,     0,     4,     5,     6,     7,    18,    19,    29,
      30,    31,    32,    33,    34,    35,    36,    43,    46,    47,
      48,    51,    53,    54,    62,    63,    64,    65,    66,    67,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    84,    85,    87,    94,    95,   118,
      51,    80,    80,    51,    80,    87,    88,    88,     7,    96,
       7,    96,    33,    65,    94,    99,   122,    37,    38,    23,
      39,    22,    41,    42,    43,    20,    21,    24,    25,    44,
      45,    26,    27,    46,    47,    48,    49,    50,     3,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    68,
      79,    80,    18,    19,    28,    51,    55,    57,    37,    48,
      86,    89,    90,   106,   107,   108,    88,   122,    58,    58,
      99,   100,    52,   100,   107,   108,   116,   123,    52,    66,
      70,    65,    71,    72,    73,    74,    75,    75,    76,    76,
      76,    76,    77,    77,    78,    78,    79,    79,    79,    66,
       7,    66,    83,    65,     7,    33,   109,   110,    38,     3,
       7,    51,   111,    52,    97,    98,    99,     7,   119,   120,
     121,    51,   124,   125,    79,    40,    38,    52,    56,   108,
      33,    90,    58,    66,    91,   106,    51,    55,    59,    98,
     101,   102,   103,   106,    38,    59,     3,   123,    51,    55,
      80,    67,    66,    91,    93,    52,     7,    87,   112,   113,
     114,   115,   117,    67,   104,   105,    37,    38,    40,   120,
     104,    52,   113,   126,   105,    38,    92,   106,   107,   116,
      52,    52,    38,    38,    56,   102,   104,    52,    56,    91,
      59,    51,    57,   115,     7,    57,    57
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
        case 7:

/* Line 1455 of yacc.c  */
#line 74 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Numero Entero = %d\n", (yyvsp[(1) - (1)].valorEntero));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 75 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Numero Real = %.2f\n", (yyvsp[(1) - (1)].valorReal));;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 76 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Caracter = %s\n", (yyvsp[(1) - (1)].valorString));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 80 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "ID = %s\n", (yyvsp[(1) - (1)].valorString));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 84 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \',\'\n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 92 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \': ?\'\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 95 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'=\'\n"  );;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 96 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'*=\'\n" );;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 97 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'/=\'\n" );;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 98 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'%=\'\n" );;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 99 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'+=\'\n" );;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 100 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'-=\'\n" );;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 101 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'<<=\'\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 102 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'>>=\'\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 103 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'&=\'\n" );;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 104 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'^=\'\n" );;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 105 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'|=\'\n" );;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 109 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'||\'\n");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 113 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'&&\'\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 117 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'|\'\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 121 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'^\'\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 125 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'&\'\n");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 129 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'==\'\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 130 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'!=\'\n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 134 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'<\'\n" );;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 135 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'>\'\n" );;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 136 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'<=\'\n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 137 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'>=\'\n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 141 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'<<\'\n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 142 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'>>\'\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 146 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'+\'\n");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 147 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'-\'\n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 151 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'*\'\n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 152 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'/\'\n");}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 153 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'%\'\n");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 157 "../src/AnalizadorSintactico.y"
    {/*CAMBIAR POR nombre_tipo*/;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 161 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'++\'\n");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 162 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'--\'\n");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 165 "../src/AnalizadorSintactico.y"
    {/*CAMBIAR POR nombre_tipo*/;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 177 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'[\' y el \']\'\n");                                    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 178 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'(\' y el \')\'\n");                                    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 179 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'.\'\n"); fprintf(yyout, "ID = %s\n", (yyvsp[(3) - (3)].valorString)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 180 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'->\'\n"); fprintf(yyout, "ID = %s\n", (yyvsp[(3) - (3)].valorString));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 181 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'++\'\n");                                              ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 182 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'--\'\n");                                              ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 190 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "String = %s\n", (yyvsp[(1) - (1)].valorString));  ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 191 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Se utiliza el \'(\' y el \')\'\n");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 216 "../src/AnalizadorSintactico.y"
    {fprintf(yyout, "Entra correctamente\n");}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 233 "../src/AnalizadorSintactico.y"
    {/*Sacamos nombre_typedef*/;}
    break;



/* Line 1455 of yacc.c  */
#line 2005 "AnalizadorSintactico.tab.c"
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
#line 371 "../src/AnalizadorSintactico.y"


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
