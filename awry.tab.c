
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
#line 1 "awry.y"

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <map>
#include <cassert>
using namespace std;
#include "ttree.h"
#include "ttfunc.cpp"
#include "symboltree.h"
#include "mipscode.cpp"
#include "threecode.cpp"


ttnode *root;
extern "C" int yylex();
extern "C" int yyparse();
extern int yylineno;
void yyerror(string s);



/* Line 189 of yacc.c  */
#line 100 "awry.tab.c"

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
     GET = 258,
     PUT = 259,
     MAIN = 260,
     LE_OP = 261,
     GE_OP = 262,
     EQ_OP = 263,
     NE_OP = 264,
     LT_OP = 265,
     GT_OP = 266,
     AD_OP = 267,
     SU_OP = 268,
     MU_OP = 269,
     DI_OP = 270,
     AND = 271,
     OR = 272,
     CONST = 273,
     IF = 274,
     ELSE = 275,
     WHILE = 276,
     FOR = 277,
     IN = 278,
     CONTINUE = 279,
     BREAK = 280,
     RETURN = 281,
     INT_CONSTANT = 282,
     FLOAT_CONSTANT = 283,
     TRUE = 284,
     FALSE = 285,
     IDENTIFIER = 286,
     INT = 287,
     FLOAT = 288,
     BOOL = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 28 "awry.y"

	ttnode *tval;



/* Line 214 of yacc.c  */
#line 176 "awry.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 188 "awry.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   389

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    13,    15,    19,    23,
      25,    27,    29,    31,    33,    34,    43,    51,    53,    55,
      59,    61,    64,    69,    72,    74,    76,    79,    81,    83,
      86,    89,    92,    95,    98,   101,   113,   121,   123,   125,
     135,   143,   145,   148,   153,   158,   162,   164,   168,   170,
     174,   176,   180,   182,   186,   188,   192,   194,   197,   199,
     203,   205,   207,   209,   214,   216,   218,   222,   224,   226,
     228,   230,   232,   234,   236,   238,   240,   242,   244,   246,
     248,   250,   252
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    55,    -1,    44,    45,    -1,    50,
      -1,    46,    -1,    51,    -1,    49,    47,    35,    -1,    47,
      36,    48,    -1,    48,    -1,    31,    -1,    32,    -1,    33,
      -1,    34,    -1,    -1,    49,    31,    37,    52,    38,    39,
      56,    40,    -1,    31,    37,    52,    38,    39,    56,    40,
      -1,    53,    -1,    50,    -1,    53,    36,    54,    -1,    54,
      -1,    49,    48,    -1,     5,    39,    56,    40,    -1,    56,
      57,    -1,    57,    -1,    46,    -1,    65,    35,    -1,    58,
      -1,    59,    -1,    25,    35,    -1,    24,    35,    -1,    62,
      35,    -1,    63,    35,    -1,    64,    35,    -1,     1,    35,
      -1,    19,    37,    65,    38,    39,    56,    40,    20,    39,
      56,    40,    -1,    19,    37,    65,    38,    39,    56,    40,
      -1,    60,    -1,    61,    -1,    22,    37,    48,    23,    69,
      38,    39,    56,    40,    -1,    21,    37,    65,    38,    39,
      56,    40,    -1,    26,    -1,    26,    65,    -1,     3,    37,
      48,    38,    -1,     4,    37,    65,    38,    -1,    48,    41,
      65,    -1,    66,    -1,    66,    17,    67,    -1,    67,    -1,
      67,    16,    68,    -1,    68,    -1,    68,    79,    69,    -1,
      69,    -1,    69,    77,    70,    -1,    70,    -1,    70,    78,
      71,    -1,    71,    -1,    80,    71,    -1,    72,    -1,    37,
      65,    38,    -1,    73,    -1,    76,    -1,    48,    -1,    31,
      37,    74,    38,    -1,    75,    -1,    50,    -1,    75,    36,
      65,    -1,    65,    -1,    27,    -1,    28,    -1,    29,    -1,
      30,    -1,    12,    -1,    13,    -1,    14,    -1,    15,    -1,
       7,    -1,     6,    -1,    11,    -1,    10,    -1,     8,    -1,
       9,    -1,    13,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    57,    59,    64,    66,    71,    76,    78,
      83,    88,    90,    92,    98,   102,   104,   109,   111,   116,
     118,   123,   128,   133,   135,   140,   142,   144,   146,   148,
     150,   152,   154,   156,   158,   162,   164,   169,   171,   176,
     181,   186,   188,   193,   198,   203,   205,   210,   212,   217,
     219,   224,   226,   231,   233,   238,   240,   245,   247,   252,
     254,   256,   258,   263,   268,   270,   275,   277,   282,   284,
     286,   288,   293,   295,   300,   302,   307,   309,   311,   313,
     315,   317,   322
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GET", "PUT", "MAIN", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "LT_OP", "GT_OP", "AD_OP", "SU_OP", "MU_OP", "DI_OP",
  "AND", "OR", "CONST", "IF", "ELSE", "WHILE", "FOR", "IN", "CONTINUE",
  "BREAK", "RETURN", "INT_CONSTANT", "FLOAT_CONSTANT", "TRUE", "FALSE",
  "IDENTIFIER", "INT", "FLOAT", "BOOL", "';'", "','", "'('", "')'", "'{'",
  "'}'", "'='", "$accept", "program", "declaration_list", "declaration",
  "variable_declaration", "variable_list", "variable", "type", "epsilon",
  "function_declaration", "parameters", "parameter_list", "parameter",
  "main_function", "code_block", "statement", "condition_stat",
  "loop_stat", "for_loop", "while_loop", "return_stat", "read", "write",
  "expression", "logic_expression", "and_expression",
  "relation_expression", "simple_expression", "mul_expression",
  "unary_expression", "climax", "call", "arguments", "argument_list",
  "constants", "op1", "op2", "op3", "unary_op", 0
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
     285,   286,   287,   288,   289,    59,    44,    40,    41,   123,
     125,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    47,    47,
      48,    49,    49,    49,    50,    51,    51,    52,    52,    53,
      53,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    59,    59,    60,
      61,    62,    62,    63,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    72,    72,    73,    74,    74,    75,    75,    76,    76,
      76,    76,    77,    77,    78,    78,    79,    79,    79,    79,
      79,    79,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     0,     8,     7,     1,     1,     3,
       1,     2,     4,     2,     1,     1,     2,     1,     1,     2,
       2,     2,     2,     2,     2,    11,     7,     1,     1,     9,
       7,     1,     2,     4,     4,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     1,     3,
       1,     1,     1,     4,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      14,     0,     0,     4,     1,     0,     0,    11,    12,    13,
       3,     5,     0,     6,     2,     0,    14,    10,     0,     9,
       0,     0,     0,    82,     0,     0,     0,     0,     0,    41,
      68,    69,    70,    71,    10,     0,    25,    62,     0,     0,
      24,    27,    28,    37,    38,     0,     0,     0,     0,    46,
      48,    50,    52,    54,    56,    58,    60,    61,     0,     0,
      18,     0,    17,    20,    14,     7,     0,    34,     0,     0,
       0,     0,     0,    30,    29,    42,    14,     0,     0,    10,
      22,    23,    31,    32,    33,    26,     0,     0,    77,    76,
      80,    81,    79,    78,     0,    72,    73,     0,    74,    75,
       0,    62,    57,    21,     0,     0,     0,     8,     0,     0,
       0,     0,     0,    65,    67,     0,    64,    59,    45,    47,
      49,    51,    53,    55,     0,    19,     0,    43,    44,     0,
       0,     0,    63,     0,     0,     0,     0,     0,     0,    66,
      16,     0,     0,     0,     0,    15,    36,    40,     0,     0,
       0,     0,    39,     0,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    10,    36,    18,    37,    38,    60,    13,
      61,    62,    63,    14,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,   115,   116,    57,    97,   100,    94,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -114
static const yytype_int16 yypact[] =
{
    -114,    12,     0,  -114,  -114,   -32,   -20,  -114,  -114,  -114,
    -114,  -114,   -10,  -114,  -114,   352,   -18,    -8,   -26,  -114,
      -5,     4,    18,  -114,    20,    21,    24,     5,    17,    40,
    -114,  -114,  -114,  -114,    25,    40,  -114,   -16,     8,   107,
    -114,  -114,  -114,  -114,  -114,    28,    29,    30,    37,    42,
      57,    83,    15,    22,  -114,  -114,  -114,  -114,    40,     8,
    -114,    38,    44,  -114,   -18,  -114,     8,  -114,     8,    40,
      40,    40,     8,  -114,  -114,  -114,    40,    43,    40,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,    40,    40,  -114,  -114,
    -114,  -114,  -114,  -114,    40,  -114,  -114,    40,  -114,  -114,
      40,  -114,  -114,  -114,    39,   -18,    45,  -114,    46,    48,
      49,    59,    72,  -114,  -114,    60,    63,  -114,  -114,    57,
      83,    15,    22,  -114,   352,  -114,    61,  -114,  -114,    62,
      70,    40,  -114,    40,   142,   352,   352,   352,     7,  -114,
    -114,   177,   212,   247,    74,  -114,    82,  -114,   352,    75,
     282,   352,  -114,   317,  -114
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -114,  -114,  -114,  -114,   114,  -114,   -12,     2,     3,  -114,
      53,  -114,    13,  -114,  -113,   -38,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,   -27,  -114,    35,    36,   -81,    27,   -52,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      19,    81,    75,     3,    12,     5,   102,    15,    77,    65,
      66,   134,     4,   121,     7,     8,     9,    16,    59,    95,
      96,    17,   141,   142,   143,    78,    19,    95,    96,    64,
      67,     6,     7,     8,     9,   150,    98,    99,   153,    79,
      73,    68,   109,   110,   111,   144,   101,   103,   123,   114,
     138,   118,    74,    23,   107,    69,   108,    70,    71,    86,
     112,    72,    76,    82,    83,    84,    59,    30,    31,    32,
      33,    34,    85,    87,   101,   101,   104,    35,   124,   113,
     105,   117,   101,   126,   127,   101,   128,   129,   101,    88,
      89,    90,    91,    92,    93,   131,    81,   130,   132,   133,
     135,   136,   149,    81,    81,    81,   139,    59,    20,   137,
      21,    22,    81,   148,   151,    81,    11,   106,   125,   101,
      23,   119,     0,   120,   122,     0,    24,     0,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,     7,
       8,     9,     0,    20,    35,    21,    22,    80,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,     0,
       0,    24,     0,    25,    26,     0,    27,    28,    29,    30,
      31,    32,    33,    34,     7,     8,     9,     0,    20,    35,
      21,    22,   140,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,    24,     0,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,     7,
       8,     9,     0,    20,    35,    21,    22,   145,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,     0,
       0,    24,     0,    25,    26,     0,    27,    28,    29,    30,
      31,    32,    33,    34,     7,     8,     9,     0,    20,    35,
      21,    22,   146,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,    24,     0,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,     7,
       8,     9,     0,    20,    35,    21,    22,   147,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,     0,
       0,    24,     0,    25,    26,     0,    27,    28,    29,    30,
      31,    32,    33,    34,     7,     8,     9,     0,    20,    35,
      21,    22,   152,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,    24,     0,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,     7,
       8,     9,     0,    20,    35,    21,    22,   154,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,     0,
       0,    24,     0,    25,    26,     0,    27,    28,    29,    30,
      31,    32,    33,    34,     7,     8,     9,     0,     0,    35
};

static const yytype_int16 yycheck[] =
{
      12,    39,    29,     0,     2,     5,    58,    39,    35,    35,
      36,   124,     0,    94,    32,    33,    34,    37,    16,    12,
      13,    31,   135,   136,   137,    41,    38,    12,    13,    37,
      35,    31,    32,    33,    34,   148,    14,    15,   151,    31,
      35,    37,    69,    70,    71,    38,    58,    59,   100,    76,
     131,    78,    35,    13,    66,    37,    68,    37,    37,    17,
      72,    37,    37,    35,    35,    35,    64,    27,    28,    29,
      30,    31,    35,    16,    86,    87,    38,    37,    39,    76,
      36,    38,    94,    38,    38,    97,    38,    38,   100,     6,
       7,     8,     9,    10,    11,    23,   134,    38,    38,    36,
      39,    39,    20,   141,   142,   143,   133,   105,     1,    39,
       3,     4,   150,    39,    39,   153,     2,    64,   105,   131,
      13,    86,    -1,    87,    97,    -1,    19,    -1,    21,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,     1,    37,     3,     4,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,     1,    37,
       3,     4,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,     1,    37,     3,     4,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,     1,    37,
       3,     4,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,     1,    37,     3,     4,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,     1,    37,
       3,     4,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,     1,    37,     3,     4,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,    44,    50,     0,     5,    31,    32,    33,    34,
      45,    46,    49,    51,    55,    39,    37,    31,    47,    48,
       1,     3,     4,    13,    19,    21,    22,    24,    25,    26,
      27,    28,    29,    30,    31,    37,    46,    48,    49,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    76,    80,    49,
      50,    52,    53,    54,    37,    35,    36,    35,    37,    37,
      37,    37,    37,    35,    35,    65,    37,    65,    41,    31,
      40,    57,    35,    35,    35,    35,    17,    16,     6,     7,
       8,     9,    10,    11,    79,    12,    13,    77,    14,    15,
      78,    48,    71,    48,    38,    36,    52,    48,    48,    65,
      65,    65,    48,    50,    65,    74,    75,    38,    65,    67,
      68,    69,    70,    71,    39,    54,    38,    38,    38,    38,
      38,    23,    38,    36,    56,    39,    39,    39,    69,    65,
      40,    56,    56,    56,    38,    40,    40,    40,    39,    20,
      56,    39,    40,    56,    40
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
        case 2:

/* Line 1455 of yacc.c  */
#line 53 "awry.y"
    { root = make_node("","program",(yyvsp[(1) - (2)].tval),(yyvsp[(2) - (2)].tval),NULL); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 58 "awry.y"
    { (yyval.tval) = make_node("","declaration_list",(yyvsp[(1) - (2)].tval),(yyvsp[(2) - (2)].tval),NULL); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 60 "awry.y"
    { (yyval.tval) = make_node("","declaration_list",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 65 "awry.y"
    { (yyval.tval) = make_node("","declaration",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 67 "awry.y"
    { (yyval.tval) = make_node("","declaration",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 72 "awry.y"
    { (yyval.tval) = make_node("","variable_declaration",(yyvsp[(1) - (3)].tval),(yyvsp[(2) - (3)].tval),NULL); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 77 "awry.y"
    { (yyval.tval) = make_node("","variable_list",(yyvsp[(1) - (3)].tval),(yyvsp[(3) - (3)].tval),NULL); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 79 "awry.y"
    { (yyval.tval) = make_node("","variable_list",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 84 "awry.y"
    { (yyval.tval) = make_node((yyvsp[(1) - (1)].tval)->item,"variable",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 89 "awry.y"
    { (yyval.tval) = make_node("","type",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 91 "awry.y"
    { (yyval.tval) = make_node("","type",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 93 "awry.y"
    { (yyval.tval) = make_node("","type",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 98 "awry.y"
    { (yyval.tval) = make_node("","epsilon",NULL,NULL,NULL); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 103 "awry.y"
    { (yyval.tval) = make_node((yyvsp[(2) - (8)].tval)->item,"function_declaration",(yyvsp[(1) - (8)].tval),(yyvsp[(4) - (8)].tval),(yyvsp[(7) - (8)].tval)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 105 "awry.y"
    { (yyval.tval) = make_node((yyvsp[(1) - (7)].tval)->item,"function_declaration",(yyvsp[(3) - (7)].tval),(yyvsp[(6) - (7)].tval),NULL); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 110 "awry.y"
    { (yyval.tval) = make_node("","parameters",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 112 "awry.y"
    { (yyval.tval) = make_node("","parameters",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 117 "awry.y"
    { (yyval.tval) = make_node("","parameter_list",(yyvsp[(1) - (3)].tval),(yyvsp[(3) - (3)].tval),NULL); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 119 "awry.y"
    { (yyval.tval) = make_node("","parameter_list",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 124 "awry.y"
    { (yyval.tval) = make_node("","parameter",(yyvsp[(1) - (2)].tval),(yyvsp[(2) - (2)].tval),NULL); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 129 "awry.y"
    { (yyval.tval) = make_node("","main_function",(yyvsp[(3) - (4)].tval),NULL,NULL); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 134 "awry.y"
    { (yyval.tval) = make_node("","code_block",(yyvsp[(1) - (2)].tval),(yyvsp[(2) - (2)].tval),NULL); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 136 "awry.y"
    { (yyval.tval) = make_node("","code_block",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 141 "awry.y"
    { (yyval.tval) = make_node("","statement",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 143 "awry.y"
    { (yyval.tval) = make_node("","statement",(yyvsp[(1) - (2)].tval),NULL,NULL); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 145 "awry.y"
    { (yyval.tval) = make_node("","statement",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 147 "awry.y"
    { (yyval.tval) = make_node("","statement",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 149 "awry.y"
    { (yyval.tval) = make_node("break","statement",(yyvsp[(1) - (2)].tval),NULL,NULL); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 151 "awry.y"
    { (yyval.tval) = make_node("continue","statement",(yyvsp[(1) - (2)].tval),NULL,NULL); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 153 "awry.y"
    { (yyval.tval) = make_node("","statement",(yyvsp[(1) - (2)].tval),NULL,NULL); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 155 "awry.y"
    { (yyval.tval) = make_node("","statement",(yyvsp[(1) - (2)].tval),NULL,NULL); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 157 "awry.y"
    { (yyval.tval) = make_node("","statement",(yyvsp[(1) - (2)].tval),NULL,NULL); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 158 "awry.y"
    { yyerrok;                  ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 163 "awry.y"
    { (yyval.tval) = make_node("op","condition_stat",(yyvsp[(3) - (11)].tval),(yyvsp[(6) - (11)].tval),(yyvsp[(10) - (11)].tval)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 165 "awry.y"
    { (yyval.tval) = make_node("","condition_stat",(yyvsp[(3) - (7)].tval),(yyvsp[(6) - (7)].tval),NULL); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 170 "awry.y"
    { (yyval.tval) = make_node("","loop_stat",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 172 "awry.y"
    { (yyval.tval) = make_node("","loop_stat",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 177 "awry.y"
    { (yyval.tval) = make_node("","for_loop",(yyvsp[(3) - (9)].tval),(yyvsp[(5) - (9)].tval),(yyvsp[(8) - (9)].tval)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 182 "awry.y"
    { (yyval.tval) = make_node("","while_loop",(yyvsp[(3) - (7)].tval),(yyvsp[(6) - (7)].tval),NULL); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 187 "awry.y"
    { (yyval.tval) = make_node("","return_stat",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 189 "awry.y"
    { (yyval.tval) = make_node("op","return_stat",(yyvsp[(1) - (2)].tval),(yyvsp[(2) - (2)].tval),NULL); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 194 "awry.y"
    { (yyval.tval) = make_node("get","read",(yyvsp[(3) - (4)].tval),NULL,NULL); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 199 "awry.y"
    { (yyval.tval) = make_node("put","write",(yyvsp[(3) - (4)].tval),NULL,NULL); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 204 "awry.y"
    { (yyval.tval) = make_node("=","expression",(yyvsp[(1) - (3)].tval),(yyvsp[(3) - (3)].tval),NULL); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 206 "awry.y"
    { (yyval.tval) = make_node("","expression",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 211 "awry.y"
    { (yyval.tval) = make_node("or","logic_expression",(yyvsp[(1) - (3)].tval),(yyvsp[(3) - (3)].tval),NULL); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 213 "awry.y"
    { (yyval.tval) = make_node("","logic_expression",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 218 "awry.y"
    { (yyval.tval) = make_node("and","and_expression",(yyvsp[(1) - (3)].tval),(yyvsp[(3) - (3)].tval),NULL); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 220 "awry.y"
    { (yyval.tval) = make_node("","and_expression",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 225 "awry.y"
    { (yyval.tval) = make_node("op","relation_expression",(yyvsp[(1) - (3)].tval),(yyvsp[(2) - (3)].tval),(yyvsp[(3) - (3)].tval)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 227 "awry.y"
    { (yyval.tval) = make_node("","relation_expression",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 232 "awry.y"
    { (yyval.tval) = make_node("op","simple_expression",(yyvsp[(1) - (3)].tval),(yyvsp[(2) - (3)].tval),(yyvsp[(3) - (3)].tval)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 234 "awry.y"
    { (yyval.tval) = make_node("","simple_expression",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 239 "awry.y"
    { (yyval.tval) = make_node("op","mul_expression",(yyvsp[(1) - (3)].tval),(yyvsp[(2) - (3)].tval),(yyvsp[(3) - (3)].tval)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 241 "awry.y"
    { (yyval.tval) = make_node("","mul_expression",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 246 "awry.y"
    { (yyval.tval) = make_node("op","unary_expression",(yyvsp[(1) - (2)].tval),(yyvsp[(2) - (2)].tval),NULL); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 248 "awry.y"
    { (yyval.tval) = make_node("","unary_expression",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 253 "awry.y"
    { (yyval.tval) = make_node("op","climax",(yyvsp[(2) - (3)].tval),NULL,NULL); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 255 "awry.y"
    { (yyval.tval) = make_node("","climax",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 257 "awry.y"
    { (yyval.tval) = make_node("","climax",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 259 "awry.y"
    { (yyval.tval) = make_node("","climax",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 264 "awry.y"
    { (yyval.tval) = make_node((yyvsp[(1) - (4)].tval)->item,"call",(yyvsp[(3) - (4)].tval),NULL,NULL); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 269 "awry.y"
    { (yyval.tval) = make_node("","arguments",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 271 "awry.y"
    { (yyval.tval) = make_node("","arguments",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 276 "awry.y"
    { (yyval.tval) = make_node("","argument_list",(yyvsp[(1) - (3)].tval),(yyvsp[(3) - (3)].tval),NULL); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 278 "awry.y"
    { (yyval.tval) = make_node("","argument_list",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 283 "awry.y"
    { (yyval.tval) = make_node("","constants",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 285 "awry.y"
    { (yyval.tval) = make_node("","constants",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 287 "awry.y"
    { (yyval.tval) = make_node("","constants",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 289 "awry.y"
    { (yyval.tval) = make_node("","constants",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 294 "awry.y"
    { (yyval.tval) = make_node("","op1",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 296 "awry.y"
    { (yyval.tval) = make_node("","op1",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 301 "awry.y"
    { (yyval.tval) = make_node("","op2",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 303 "awry.y"
    { (yyval.tval) = make_node("","op2",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 308 "awry.y"
    { (yyval.tval) = make_node("","op3",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 310 "awry.y"
    { (yyval.tval) = make_node("","op3",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 312 "awry.y"
    { (yyval.tval) = make_node("","op3",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 314 "awry.y"
    { (yyval.tval) = make_node("","op3",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 316 "awry.y"
    { (yyval.tval) = make_node("","op3",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 318 "awry.y"
    { (yyval.tval) = make_node("","op3",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 323 "awry.y"
    { (yyval.tval) = make_node("","unary_op",(yyvsp[(1) - (1)].tval),NULL,NULL); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2135 "awry.tab.c"
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
#line 326 "awry.y"

bool fail;
void yyerror(string s) 
{
	cerr << "Line " << yylineno << ": " << s << endl;
	fail = 1;
}

int main()
{
	freopen("test.txt","r",stdin);
	bool failure = yyparse();
	failure |= fail;
	if(failure) 
		std::cerr << "Parsing Failed\n";
	else
	{
		cerr << "Success!\n";
		printtree(root); printtreeold(root, "+-- ");
		mcode << ".text" << endl;
		generatecode(root);
		data();
	}
}
