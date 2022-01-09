
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
#line 1 "yacc2.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
  #include <ctype.h>
  #include "variables.h"
  #include "ST.h"
  #include "ast.h"
  #define YYDEBUG 1
  int yylex(void);
  void yyerror(char *);

  

  int curr_scope = 0;


  void install ( char *sym_name, int type, int int_val, double real_val, int bool_val, char *char_val, char *string_val, int current_scope)
  {
    symrec *s;
    symrec *i;
    s = getsym (sym_name, current_scope);
    if (s == 0) {
      putsym (sym_name, type, int_val, real_val, bool_val, char_val, string_val, current_scope);   
    } else { 
      printf( "%s is already defined\n", sym_name );
      exit(1);
    }
  }

  void context_check( char *sym_name, int scope ) { 
    symrec *identifier;
    identifier = getsym( sym_name, scope );
    if ( identifier == 0 ) { 
      printf( "%s", sym_name );
      printf( "%s\n", " is an undeclared identifier" );
      exit(1);
    }
  }

  void check_type( char *sym_name, int type, int scope) { 
    symrec *identifier;
    identifier = getsym( sym_name , scope);
    if(identifier->type != type) {
      printf( "%s", sym_name );
      int int_type = identifier->type;
      printf( "%s\n", " hasn't the right type" );
      exit(1);
    }
    
  }

  int get_type(char *sym_name, int scope) {
    symrec *identifier;
    identifier = getsym(sym_name, scope);
    return identifier->type;
  }

  void set_real_value(char *sym_name, double real_value, int current_scope) {
    setrealval(sym_name, real_value, current_scope);
  }

  double get_real_value(char *sym_name, int current_scope) {
    return getrealval(sym_name, current_scope);
  }

  void set_bool_value(char *sym_name, int bool_value, int current_scope) {
    setboolval(sym_name, bool_value, current_scope);
  }

  int get_bool_value(char *sym_name, int current_scope) {
    return getboolval(sym_name, current_scope);
  }

  void set_int_value(char *sym_name, int int_value, int current_scope) {
    setintval(sym_name, int_value, current_scope);
  }

  int get_int_value(char *sym_name, int current_scope) {
    return getintval(sym_name, current_scope);
  }

  void set_char_value(char *sym_name, char *char_value, int current_scope) {
    setcharval(sym_name, char_value, current_scope);
  }

  char * get_char_value(char *sym_name, int current_scope) {
    return getcharval(sym_name, current_scope);
  }

  void set_string_value(char *sym_name, char *string_value, int current_scope) {
    setstringval(sym_name, string_value, current_scope);
  }

  char * get_string_value(char *sym_name, int current_scope) {
    return getstringval(sym_name, current_scope);
  }
  
  



/* Line 189 of yacc.c  */
#line 177 "yacc2.tab.c"

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
     ID = 258,
     TRUE = 259,
     FALSE = 260,
     REAL = 261,
     INTEGER = 262,
     CHAR = 263,
     STRING = 264,
     INT_TYPE = 265,
     REAL_TYPE = 266,
     CHAR_TYPE = 267,
     STRING_TYPE = 268,
     BOOL_TYPE = 269,
     DECLARATIONS = 270,
     FUNCTIONS = 271,
     STATEMENTS = 272,
     VAR = 273,
     COLON = 274,
     OPENPAR = 275,
     CLOSEPAR = 276,
     COMMA = 277,
     COMMENT = 278,
     SEMICOLON = 279,
     STARTPRGM = 280,
     ENDPRGM = 281,
     BEGSTMT = 282,
     ENDSTMT = 283,
     IF = 284,
     THEN = 285,
     ELIF = 286,
     ELSE = 287,
     ENDIF = 288,
     WHILE = 289,
     DO = 290,
     ENDWHILE = 291,
     WRITE = 292,
     FCT = 293,
     RETURN = 294,
     OR = 295,
     AND = 296,
     NE = 297,
     EQ = 298,
     GT = 299,
     LT = 300,
     GE = 301,
     LE = 302,
     ASSIGNMENT = 303,
     MOD = 304,
     DIV = 305,
     DIVOP = 306,
     MULOP = 307,
     MINOP = 308,
     ADDOP = 309,
     SQRT = 310,
     TAN = 311,
     SIN = 312,
     COS = 313,
     LN = 314,
     LOG = 315,
     EXP = 316,
     ABS = 317,
     POW = 318,
     CEIL = 319,
     FLOOR = 320,
     NOT = 321
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union 
/* Line 214 of yacc.c  */
#line 105 "yacc2.y"
semrec
{

/* Line 214 of yacc.c  */
#line 106 "yacc2.y"
 
  struct Value val;
  double doubleval;
  int intval; 
  char *chstval;
  char *id;
  struct lbs *lbls; 



/* Line 214 of yacc.c  */
#line 293 "yacc2.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 305 "yacc2.tab.c"

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
#define YYLAST   400

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    12,    16,    17,    21,    22,    27,    29,
      31,    33,    35,    37,    42,    43,    45,    49,    51,    55,
      59,    62,    66,    70,    74,    78,    82,    86,    90,    94,
      97,    99,   103,   107,   111,   115,   117,   119,   121,   123,
     125,   127,   129,   133,   138,   145,   150,   155,   160,   165,
     170,   175,   180,   185,   190,   193,   195,   197,   199,   201,
     203,   211,   212,   218,   219,   222,   228,   229,   232,   236,
     244
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      68,     0,    -1,    25,    15,    70,    16,    85,    17,    71,
      26,    -1,    27,    71,    28,    -1,    -1,    70,    73,    24,
      -1,    -1,    71,    74,    72,    24,    -1,    75,    -1,    73,
      -1,    79,    -1,    81,    -1,    84,    -1,    18,     3,    19,
      80,    -1,    -1,    23,    -1,     3,    48,    76,    -1,    77,
      -1,    76,    54,    77,    -1,    76,    53,    77,    -1,    53,
      77,    -1,    76,    46,    77,    -1,    76,    47,    77,    -1,
      76,    44,    77,    -1,    76,    45,    77,    -1,    76,    43,
      77,    -1,    76,    42,    77,    -1,    76,    41,    77,    -1,
      76,    40,    77,    -1,    66,    77,    -1,    78,    -1,    77,
      52,    78,    -1,    77,    51,    78,    -1,    77,    50,    78,
      -1,    77,    49,    78,    -1,     3,    -1,     7,    -1,     6,
      -1,     4,    -1,     5,    -1,     8,    -1,     9,    -1,    20,
      76,    21,    -1,    62,    20,    76,    21,    -1,    63,    20,
      76,    22,    76,    21,    -1,    55,    20,    76,    21,    -1,
      61,    20,    76,    21,    -1,    60,    20,    76,    21,    -1,
      59,    20,    76,    21,    -1,    65,    20,    76,    21,    -1,
      64,    20,    76,    21,    -1,    58,    20,    76,    21,    -1,
      57,    20,    76,    21,    -1,    56,    20,    76,    21,    -1,
      37,    76,    -1,    10,    -1,    11,    -1,    12,    -1,    13,
      -1,    14,    -1,    29,    76,    30,    69,    82,    83,    33,
      -1,    -1,    82,    31,    76,    30,    69,    -1,    -1,    32,
      71,    -1,    34,    76,    35,    69,    36,    -1,    -1,    85,
      86,    -1,    87,    69,    88,    -1,    38,     3,    20,     3,
      21,    19,    80,    -1,    39,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   146,   149,   150,   153,   154,   157,   158,
     159,   160,   161,   165,   167,   168,   171,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     193,   194,   195,   196,   197,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   222,   284,   285,   286,   287,   288,
     291,   294,   295,   298,   299,   302,   305,   306,   309,   312,
     315
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "TRUE", "FALSE", "REAL", "INTEGER",
  "CHAR", "STRING", "INT_TYPE", "REAL_TYPE", "CHAR_TYPE", "STRING_TYPE",
  "BOOL_TYPE", "DECLARATIONS", "FUNCTIONS", "STATEMENTS", "VAR", "COLON",
  "OPENPAR", "CLOSEPAR", "COMMA", "COMMENT", "SEMICOLON", "STARTPRGM",
  "ENDPRGM", "BEGSTMT", "ENDSTMT", "IF", "THEN", "ELIF", "ELSE", "ENDIF",
  "WHILE", "DO", "ENDWHILE", "WRITE", "FCT", "RETURN", "OR", "AND", "NE",
  "EQ", "GT", "LT", "GE", "LE", "ASSIGNMENT", "MOD", "DIV", "DIVOP",
  "MULOP", "MINOP", "ADDOP", "SQRT", "TAN", "SIN", "COS", "LN", "LOG",
  "EXP", "ABS", "POW", "CEIL", "FLOOR", "NOT", "$accept", "program",
  "groupstmts", "declarations", "stmts", "stmt", "declaration", "comment",
  "assignexpr", "expr", "factor", "term", "write", "type",
  "conditionalstmt", "elifstmt", "elsestmt", "loopstmt", "fcts", "fct",
  "headfct", "returnfct", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    69,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    73,    74,    74,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    77,    77,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    79,    80,    80,    80,    80,    80,
      81,    82,    82,    83,    83,    84,    85,    85,    86,    87,
      88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     3,     0,     3,     0,     4,     1,     1,
       1,     1,     1,     4,     0,     1,     3,     1,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     2,     1,     1,     1,     1,     1,
       7,     0,     5,     0,     2,     5,     0,     2,     3,     7,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     1,     0,    66,     0,     0,     0,
       0,     5,     6,     0,    67,     0,     0,    14,     0,     6,
       0,    55,    56,    57,    58,    59,    13,    15,     2,     0,
       0,    14,     0,    68,     0,     0,     0,     0,     0,     9,
       8,    10,    11,    12,     0,     3,    70,     0,    35,    38,
      39,    37,    36,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    30,     0,    54,     7,     0,    16,     0,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,    28,    27,    26,    25,    23,    24,    21,    22,    19,
      18,    34,    33,    32,    31,     0,    69,    45,    53,    52,
      51,    48,    47,    46,    43,     0,    50,    49,    63,    65,
       0,     0,     6,     0,    44,     0,    14,    60,     0,    62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    20,     5,    17,    38,     8,    29,    40,    69,
      70,    71,    41,    26,    42,   148,   153,    43,     9,    14,
      15,    33
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -89
static const yytype_int16 yypact[] =
{
       8,    21,    42,   -89,   -89,    23,   -89,    40,    32,    -4,
      68,   -89,   -89,    96,   -89,    69,    93,    -9,    77,   -89,
      61,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,     1,
     105,     9,   106,   -89,    63,     2,     2,     2,    88,   -89,
     -89,   -89,   -89,   -89,    92,   -89,   -89,     2,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,     2,    20,   101,   122,   123,
     124,   125,   126,   130,   139,   140,   141,   142,    20,   298,
      22,   -89,   331,   346,   -89,    95,   346,    48,    22,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      22,    69,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    69,    93,   -89,    94,
     111,   128,   145,   162,   179,   196,   213,   280,   230,   247,
     -89,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,   -89,   -89,   -89,   -89,   127,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,     2,   -89,   -89,   -16,   -89,
     264,     2,   -89,   134,   -89,   316,    -2,   -89,    69,   -89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   -89,   -88,   -89,   -19,   -89,   147,   -89,   -89,   -35,
      30,    15,   -89,    70,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -65
static const yytype_int16 yytable[] =
{
      31,    72,    73,   120,    34,    48,    49,    50,    51,    52,
      53,    54,    76,    12,    27,   151,   152,    28,   135,     7,
      77,    27,    55,    48,    49,    50,    51,    52,    53,    54,
      35,   -64,    27,     1,    13,    36,     3,    45,    37,     6,
      55,     7,     4,    10,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    56,    11,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   108,
     159,   102,   103,   104,   105,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    78,    16,    92,    93,
      94,    95,    96,    97,    98,    99,    19,    30,    90,    18,
      32,   100,   101,    21,    22,    23,    24,    25,    44,    46,
     150,    47,    74,    75,   107,   137,   155,   131,   132,   133,
     134,    79,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   138,   156,    92,    93,    94,    95,    96,    97,
      98,    99,    80,    81,    82,    83,    84,   100,   101,   139,
      85,    92,    93,    94,    95,    96,    97,    98,    99,    86,
      87,    88,    89,   149,   100,   101,   140,   157,    92,    93,
      94,    95,    96,    97,    98,    99,    39,   136,     0,     0,
       0,   100,   101,   141,     0,    92,    93,    94,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,   100,   101,
     142,     0,    92,    93,    94,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,   100,   101,   143,     0,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,   100,   101,   144,     0,    92,    93,    94,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,   100,
     101,   146,     0,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,   100,   101,   147,     0,
      92,    93,    94,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,   100,   101,   154,     0,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
     100,   101,   145,     0,    92,    93,    94,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,   100,   101,     0,
      92,    93,    94,    95,    96,    97,    98,    99,    91,     0,
       0,     0,     0,   100,   101,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   158,     0,     0,     0,
       0,   100,   101,     0,     0,     0,    92,    93,    94,    95,
      96,    97,    98,    99,     0,     0,   106,     0,     0,   100,
     101,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,   100,   101,    92,    93,    94,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,   100,
     101
};

static const yytype_int16 yycheck[] =
{
      19,    36,    37,    91,     3,     3,     4,     5,     6,     7,
       8,     9,    47,    17,    23,    31,    32,    26,   106,    18,
      55,    23,    20,     3,     4,     5,     6,     7,     8,     9,
      29,    33,    23,    25,    38,    34,    15,    28,    37,    16,
      20,    18,     0,     3,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    53,    24,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    21,
     158,    49,    50,    51,    52,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    56,    19,    40,    41,
      42,    43,    44,    45,    46,    47,    27,    20,    68,     3,
      39,    53,    54,    10,    11,    12,    13,    14,     3,     3,
     145,    48,    24,    21,    19,    21,   151,   102,   103,   104,
     105,    20,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    21,   152,    40,    41,    42,    43,    44,    45,
      46,    47,    20,    20,    20,    20,    20,    53,    54,    21,
      20,    40,    41,    42,    43,    44,    45,    46,    47,    20,
      20,    20,    20,    36,    53,    54,    21,    33,    40,    41,
      42,    43,    44,    45,    46,    47,    29,   107,    -1,    -1,
      -1,    53,    54,    21,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,    54,
      21,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    53,    54,    21,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    53,    54,    21,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,
      54,    21,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    53,    54,    21,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    53,    54,    21,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      53,    54,    22,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    53,    54,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    30,    -1,
      -1,    -1,    -1,    53,    54,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    30,    -1,    -1,    -1,
      -1,    53,    54,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    35,    -1,    -1,    53,
      54,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    53,    54,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,
      54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    68,    15,     0,    70,    16,    18,    73,    85,
       3,    24,    17,    38,    86,    87,    19,    71,     3,    27,
      69,    10,    11,    12,    13,    14,    80,    23,    26,    74,
      20,    71,    39,    88,     3,    29,    34,    37,    72,    73,
      75,    79,    81,    84,     3,    28,     3,    48,     3,     4,
       5,     6,     7,     8,     9,    20,    53,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    76,
      77,    78,    76,    76,    24,    21,    76,    76,    77,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      77,    30,    40,    41,    42,    43,    44,    45,    46,    47,
      53,    54,    49,    50,    51,    52,    35,    19,    21,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      69,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    78,    78,    78,    69,    80,    21,    21,    21,
      21,    21,    21,    21,    21,    22,    21,    21,    82,    36,
      76,    31,    32,    83,    21,    76,    71,    33,    30,    69
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
        case 11:

/* Line 1455 of yacc.c  */
#line 160 "yacc2.y"
    {printf("CONDITIONAL STATEMENT");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 161 "yacc2.y"
    {printf("LOOP STATEMENT");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 165 "yacc2.y"
    { printf("curr_scope = %d\n", curr_scope); install((yyvsp[(2) - (4)].id), (yyvsp[(4) - (4)].intval), 0, 0, 0, "N", "null", curr_scope); printf("DECLARATION %s, %d \n", (yyvsp[(2) - (4)].id), (yyvsp[(4) - (4)].intval));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 171 "yacc2.y"
    { context_check((yyvsp[(1) - (3)].id), curr_scope); if((yyvsp[(3) - (3)].val).type == INT_TYPE) {if(get_type((yyvsp[(1) - (3)].id), curr_scope) == INT_TYPE) { set_int_value((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].val).ival, curr_scope); } else if(get_type((yyvsp[(1) - (3)].id), curr_scope) == REAL_TYPE) {set_real_value((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].val).rval, curr_scope);} else {yyerror("Error assignment: bad type"); exit(1);}} else if((yyvsp[(3) - (3)].val).type == REAL_TYPE) {check_type((yyvsp[(1) - (3)].id), REAL_TYPE, curr_scope); set_real_value((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].val).rval, curr_scope);} else if((yyvsp[(3) - (3)].val).type == BOOL_TYPE) {check_type((yyvsp[(1) - (3)].id), BOOL_TYPE, curr_scope); set_bool_value((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].val).bval, curr_scope);} else if((yyvsp[(3) - (3)].val).type == CHAR_TYPE) {check_type((yyvsp[(1) - (3)].id), CHAR_TYPE, curr_scope); set_char_value((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].val).cval, curr_scope);} else if((yyvsp[(3) - (3)].val).type == STRING_TYPE) {check_type((yyvsp[(1) - (3)].id), STRING_TYPE, curr_scope); set_string_value((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].val).sval, curr_scope);} printf("ASSIGNED TO ID %s\n",(yyvsp[(1) - (3)].id)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 178 "yacc2.y"
    {(yyval.val).type = (yyvsp[(1) - (1)].val).type;  if((yyvsp[(1) - (1)].val).type == INT_TYPE) {(yyval.val).ival = (yyvsp[(1) - (1)].val).ival;} else if((yyvsp[(1) - (1)].val).type == REAL_TYPE) {(yyval.val).rval = (yyvsp[(1) - (1)].val).rval;} else if((yyvsp[(1) - (1)].val).type == BOOL_TYPE) {(yyval.val).bval = (yyvsp[(1) - (1)].val).bval;} else if((yyvsp[(1) - (1)].val).type == CHAR_TYPE) {(yyval.val).cval = (yyvsp[(1) - (1)].val).cval;} else if((yyvsp[(1) - (1)].val).type == STRING_TYPE) {(yyval.val).sval = (yyvsp[(1) - (1)].val).sval;};}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 179 "yacc2.y"
    { if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) {(yyval.val).type = INT_TYPE; (yyval.val).ival = (yyvsp[(1) - (3)].val).ival+(yyvsp[(3) - (3)].val).ival;} else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = (yyvsp[(1) - (3)].val).rval+(float)(yyvsp[(3) - (3)].val).ival;} else if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = (float)(yyvsp[(1) - (3)].val).ival+(yyvsp[(3) - (3)].val).rval;} else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = (yyvsp[(1) - (3)].val).rval+(yyvsp[(3) - (3)].val).rval;} else { yyerror("Must add numbers"); exit(1);} ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 180 "yacc2.y"
    { if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) {(yyval.val).type = INT_TYPE; (yyval.val).ival = (yyvsp[(1) - (3)].val).ival-(yyvsp[(3) - (3)].val).ival;} else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = (yyvsp[(1) - (3)].val).rval-(float)(yyvsp[(3) - (3)].val).ival;} else if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = (float)(yyvsp[(1) - (3)].val).ival-(yyvsp[(3) - (3)].val).rval;} else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = (yyvsp[(1) - (3)].val).rval-(yyvsp[(3) - (3)].val).rval;} else { yyerror("Must substract numbers"); exit(1);} ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 181 "yacc2.y"
    { (yyval.val).type = (yyvsp[(2) - (2)].val).type; if((yyvsp[(2) - (2)].val).type == INT_TYPE) {(yyval.val).ival = -(yyvsp[(2) - (2)].val).ival;} else if((yyvsp[(2) - (2)].val).type == REAL_TYPE) {(yyval.val).rval = -(yyvsp[(2) - (2)].val).rval;} else {yyerror("- must be on number only"); exit(1);} ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 182 "yacc2.y"
    { (yyval.val).type = BOOL_TYPE; if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).ival >= (yyvsp[(3) - (3)].val).ival; } else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).rval >= (yyvsp[(3) - (3)].val).ival; } else if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).ival >= (yyvsp[(3) - (3)].val).rval; } else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).rval >= (yyvsp[(3) - (3)].val).rval; } else {yyerror("Must make boolean op on numbers"); exit(1);};}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 183 "yacc2.y"
    { (yyval.val).type = BOOL_TYPE; if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).ival <= (yyvsp[(3) - (3)].val).ival; } else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).rval <= (yyvsp[(3) - (3)].val).ival; } else if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).ival <= (yyvsp[(3) - (3)].val).rval; } else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).rval <= (yyvsp[(3) - (3)].val).rval; } else {yyerror("Must make boolean op on numbers"); exit(1);};}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 184 "yacc2.y"
    { (yyval.val).type = BOOL_TYPE; if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).ival > (yyvsp[(3) - (3)].val).ival; } else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).rval > (yyvsp[(3) - (3)].val).ival; } else if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).ival > (yyvsp[(3) - (3)].val).rval; } else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).rval > (yyvsp[(3) - (3)].val).rval; } else {yyerror("Must make boolean op on numbers"); exit(1);};}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 185 "yacc2.y"
    { (yyval.val).type = BOOL_TYPE; if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).ival < (yyvsp[(3) - (3)].val).ival; } else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).rval < (yyvsp[(3) - (3)].val).ival; } else if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).ival < (yyvsp[(3) - (3)].val).rval; } else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).rval < (yyvsp[(3) - (3)].val).rval; } else {yyerror("Must make boolean op on numbers"); exit(1);};}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 186 "yacc2.y"
    { (yyval.val).type = BOOL_TYPE; if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).ival == (yyvsp[(3) - (3)].val).ival; } else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).rval == (yyvsp[(3) - (3)].val).ival; } else if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).ival == (yyvsp[(3) - (3)].val).rval; } else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).rval == (yyvsp[(3) - (3)].val).rval; } else {yyerror("Must make boolean op on numbers"); exit(1);};}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 187 "yacc2.y"
    { (yyval.val).type = BOOL_TYPE; if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).ival != (yyvsp[(3) - (3)].val).ival; } else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).rval != (yyvsp[(3) - (3)].val).ival; } else if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).ival != (yyvsp[(3) - (3)].val).rval; } else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) { (yyval.val).bval = (yyvsp[(1) - (3)].val).rval != (yyvsp[(3) - (3)].val).rval; } else {yyerror("Must make boolean op on numbers"); exit(1);};}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 188 "yacc2.y"
    { (yyval.val).type = BOOL_TYPE; if((yyvsp[(1) - (3)].val).type == BOOL_TYPE && (yyvsp[(3) - (3)].val).type == BOOL_TYPE) {(yyval.val).bval = (yyvsp[(1) - (3)].val).bval && (yyvsp[(3) - (3)].val).bval;} else {yyerror("Must make AND operation on boolean");};}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 189 "yacc2.y"
    { (yyval.val).type = BOOL_TYPE; if((yyvsp[(1) - (3)].val).type == BOOL_TYPE && (yyvsp[(3) - (3)].val).type == BOOL_TYPE) {(yyval.val).bval = (yyvsp[(1) - (3)].val).bval || (yyvsp[(3) - (3)].val).bval;} else {yyerror("Must make OR operation on boolean");};}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 190 "yacc2.y"
    { (yyval.val).type = BOOL_TYPE; if((yyvsp[(2) - (2)].val).type == BOOL_TYPE) {(yyval.val).bval = (!(yyvsp[(2) - (2)].val).bval); } else {yyerror("Must make NOT operation on boolean");};}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 193 "yacc2.y"
    {(yyval.val).type = (yyvsp[(1) - (1)].val).type;  if((yyvsp[(1) - (1)].val).type == INT_TYPE) {(yyval.val).ival = (yyvsp[(1) - (1)].val).ival;} else if((yyvsp[(1) - (1)].val).type == REAL_TYPE) {(yyval.val).rval = (yyvsp[(1) - (1)].val).rval;} else if((yyvsp[(1) - (1)].val).type == BOOL_TYPE) {(yyval.val).bval = (yyvsp[(1) - (1)].val).bval;} else if((yyvsp[(1) - (1)].val).type == CHAR_TYPE) {(yyval.val).cval = (yyvsp[(1) - (1)].val).cval;} else if((yyvsp[(1) - (1)].val).type == STRING_TYPE) {(yyval.val).sval = (yyvsp[(1) - (1)].val).sval;} ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 194 "yacc2.y"
    { if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) {(yyval.val).type = INT_TYPE; (yyval.val).ival = (yyvsp[(1) - (3)].val).ival*(yyvsp[(3) - (3)].val).ival;} else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = (yyvsp[(1) - (3)].val).rval*(float)(yyvsp[(3) - (3)].val).ival;} else if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = (float)(yyvsp[(1) - (3)].val).ival*(yyvsp[(3) - (3)].val).rval;} else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = (yyvsp[(1) - (3)].val).rval*(yyvsp[(3) - (3)].val).rval;} else { yyerror("Must multiply numbers"); exit(1);} ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 195 "yacc2.y"
    { if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) {(yyval.val).type = INT_TYPE; (yyval.val).ival = (yyvsp[(1) - (3)].val).ival/(yyvsp[(3) - (3)].val).ival;} else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = (yyvsp[(1) - (3)].val).rval/(float)(yyvsp[(3) - (3)].val).ival;} else if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = (float)(yyvsp[(1) - (3)].val).ival/(yyvsp[(3) - (3)].val).rval;} else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = (float) (yyvsp[(1) - (3)].val).rval/(yyvsp[(3) - (3)].val).rval;} else { yyerror("Must divide numbers"); exit(1);} ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 196 "yacc2.y"
    { (yyval.val).type = INT_TYPE; if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) {(yyval.val).ival = (yyvsp[(1) - (3)].val).ival/(yyvsp[(3) - (3)].val).ival;} else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) {(yyval.val).ival = (int) (yyvsp[(1) - (3)].val).rval/(yyvsp[(3) - (3)].val).ival;} else if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) {(yyval.val).ival = (int)(yyvsp[(1) - (3)].val).ival/(yyvsp[(3) - (3)].val).rval;} else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) {(yyval.val).ival = (int) (yyvsp[(1) - (3)].val).rval/(yyvsp[(3) - (3)].val).rval;} else { yyerror("Must divide numbers"); exit(1);} ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 197 "yacc2.y"
    { if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) {(yyval.val).type = INT_TYPE; (yyval.val).ival = (int)fmod((yyvsp[(1) - (3)].val).ival, (yyvsp[(3) - (3)].val).ival);} else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == INT_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = fmod((yyvsp[(1) - (3)].val).rval, (float)(yyvsp[(3) - (3)].val).ival);} else if((yyvsp[(1) - (3)].val).type == INT_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = fmod((float)(yyvsp[(1) - (3)].val).ival, (yyvsp[(3) - (3)].val).rval);} else if((yyvsp[(1) - (3)].val).type == REAL_TYPE && (yyvsp[(3) - (3)].val).type == REAL_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = fmod((yyvsp[(1) - (3)].val).rval, (yyvsp[(3) - (3)].val).rval);} else { yyerror("Must divide numbers"); exit(1);};}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 200 "yacc2.y"
    { context_check((yyvsp[(1) - (1)].id), curr_scope); (yyval.val).type = get_type((yyvsp[(1) - (1)].id), curr_scope); if(get_type((yyvsp[(1) - (1)].id), curr_scope) == INT_TYPE) { (yyval.val).ival = get_int_value((yyvsp[(1) - (1)].id), curr_scope);} else if(get_type((yyvsp[(1) - (1)].id), curr_scope) == REAL_TYPE) {(yyval.val).rval = get_real_value((yyvsp[(1) - (1)].id), curr_scope);} else if(get_type((yyvsp[(1) - (1)].id), curr_scope) == BOOL_TYPE) {(yyval.val).bval = get_bool_value((yyvsp[(1) - (1)].id), curr_scope);} else if(get_type((yyvsp[(1) - (1)].id), curr_scope) == CHAR_TYPE) {(yyval.val).cval = get_char_value((yyvsp[(1) - (1)].id), curr_scope);} else if(get_type((yyvsp[(1) - (1)].id), curr_scope) == STRING_TYPE) {(yyval.val).sval = get_string_value((yyvsp[(1) - (1)].id), curr_scope);};}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 201 "yacc2.y"
    {(yyval.val).type = (yyvsp[(1) - (1)].val).type; (yyval.val).ival = (yyvsp[(1) - (1)].val).ival;;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 202 "yacc2.y"
    {(yyval.val).type = (yyvsp[(1) - (1)].val).type; (yyval.val).rval = (yyvsp[(1) - (1)].val).rval;;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 203 "yacc2.y"
    {(yyval.val).type = (yyvsp[(1) - (1)].val).type; (yyval.val).bval = 1;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 204 "yacc2.y"
    {(yyval.val).type = (yyvsp[(1) - (1)].val).type; (yyval.val).bval = 0;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 205 "yacc2.y"
    {(yyval.val).type = (yyvsp[(1) - (1)].val).type; (yyval.val).cval = (yyvsp[(1) - (1)].val).cval;;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 206 "yacc2.y"
    {(yyval.val).type = (yyvsp[(1) - (1)].val).type; (yyval.val).sval = (yyvsp[(1) - (1)].val).sval;;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 207 "yacc2.y"
    {(yyval.val) = (yyvsp[(2) - (3)].val); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 208 "yacc2.y"
    {(yyval.val).type = (yyvsp[(3) - (4)].val).type; if((yyvsp[(3) - (4)].val).type == INT_TYPE) {(yyval.val).ival = (int)abs((yyvsp[(3) - (4)].val).ival);} else if((yyvsp[(3) - (4)].val).type == REAL_TYPE) {(yyval.val).rval = abs((yyvsp[(3) - (4)].val).rval);} ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 209 "yacc2.y"
    { if((yyvsp[(3) - (6)].val).type == INT_TYPE && (yyvsp[(5) - (6)].val).type == INT_TYPE) {(yyval.val).type = INT_TYPE; (yyval.val).ival = pow((yyvsp[(3) - (6)].val).ival, (yyvsp[(5) - (6)].val).ival);} else if((yyvsp[(3) - (6)].val).type == REAL_TYPE && (yyvsp[(5) - (6)].val).type == INT_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = pow((yyvsp[(3) - (6)].val).rval, (float)(yyvsp[(5) - (6)].val).ival);} else if((yyvsp[(3) - (6)].val).type == INT_TYPE && (yyvsp[(5) - (6)].val).type == REAL_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = pow((float)(yyvsp[(3) - (6)].val).ival, (yyvsp[(5) - (6)].val).rval);} else if((yyvsp[(3) - (6)].val).type == REAL_TYPE && (yyvsp[(5) - (6)].val).type == REAL_TYPE) {(yyval.val).type = REAL_TYPE; (yyval.val).rval = pow((yyvsp[(3) - (6)].val).rval, (yyvsp[(5) - (6)].val).rval);} else { yyerror("Must power numbers"); exit(1);} ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 210 "yacc2.y"
    {(yyval.val).type = (yyvsp[(3) - (4)].val).type; if((yyvsp[(3) - (4)].val).type == INT_TYPE) {if((yyvsp[(3) - (4)].val).ival >= 0) {(yyval.val).ival = (int)sqrt((yyvsp[(3) - (4)].val).ival);}} else if((yyvsp[(3) - (4)].val).type == REAL_TYPE) {if((yyvsp[(3) - (4)].val).rval >= 0) {(yyval.val).rval = sqrt((yyvsp[(3) - (4)].val).rval);}} else{yyerror("Cannot make sqrt on negative number");exit(1);};}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 211 "yacc2.y"
    {(yyval.val).type = (yyvsp[(3) - (4)].val).type; if((yyvsp[(3) - (4)].val).type == INT_TYPE) {(yyval.val).ival = (int)exp((yyvsp[(3) - (4)].val).ival);} else if((yyvsp[(3) - (4)].val).type == REAL_TYPE) {(yyval.val).rval = exp((yyvsp[(3) - (4)].val).rval);} ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 212 "yacc2.y"
    {(yyval.val).type = (yyvsp[(3) - (4)].val).type; if((yyvsp[(3) - (4)].val).type == INT_TYPE) {if((yyvsp[(3) - (4)].val).ival >= 0) {(yyval.val).ival = (int)log10((yyvsp[(3) - (4)].val).ival);}} else if((yyvsp[(3) - (4)].val).type == REAL_TYPE) {if((yyvsp[(3) - (4)].val).rval >= 0) {(yyval.val).rval = log10((yyvsp[(3) - (4)].val).rval);}} else{yyerror("Cannot make log on negative number");exit(1);};}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 213 "yacc2.y"
    {(yyval.val).type = (yyvsp[(3) - (4)].val).type; if((yyvsp[(3) - (4)].val).type == INT_TYPE) {if((yyvsp[(3) - (4)].val).ival >= 0) {(yyval.val).ival = (int)log((yyvsp[(3) - (4)].val).ival);}} else if((yyvsp[(3) - (4)].val).type == REAL_TYPE) {if((yyvsp[(3) - (4)].val).rval >= 0) {(yyval.val).rval = log((yyvsp[(3) - (4)].val).rval);}} else{yyerror("Cannot make ln on negative number");exit(1);};}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 214 "yacc2.y"
    {(yyval.val).type = INT_TYPE; if((yyvsp[(3) - (4)].val).type == INT_TYPE) {(yyval.val).ival = (yyvsp[(3) - (4)].val).ival;} else if((yyvsp[(3) - (4)].val).type == REAL_TYPE) {(yyval.val).ival = (int)floor((yyvsp[(3) - (4)].val).rval);} else {yyerror("Must floor on number");} ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 215 "yacc2.y"
    {(yyval.val).type = INT_TYPE; if((yyvsp[(3) - (4)].val).type == INT_TYPE) {(yyval.val).ival = (yyvsp[(3) - (4)].val).ival;} else if((yyvsp[(3) - (4)].val).type == REAL_TYPE) {(yyval.val).ival = (int)ceil((yyvsp[(3) - (4)].val).rval);} else {yyerror("Must ceil on number");} ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 216 "yacc2.y"
    {(yyval.val).type = REAL_TYPE; if((yyvsp[(3) - (4)].val).type == REAL_TYPE) {(yyval.val).rval = cos((yyvsp[(3) - (4)].val).rval);} else {yyerror("Must make cos on real");};}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 217 "yacc2.y"
    {(yyval.val).type = REAL_TYPE; if((yyvsp[(3) - (4)].val).type == REAL_TYPE) {(yyval.val).rval = sin((yyvsp[(3) - (4)].val).rval);} else {yyerror("Must make sin on real");};}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 218 "yacc2.y"
    {(yyval.val).type = REAL_TYPE; if((yyvsp[(3) - (4)].val).type == REAL_TYPE) {(yyval.val).rval = tan((yyvsp[(3) - (4)].val).rval);} else {yyerror("Must make tan on real");};}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 222 "yacc2.y"
    {if((yyvsp[(2) - (2)].val).type == CHAR_TYPE) {printf("WRITE: %s\n", (yyvsp[(2) - (2)].val).cval);} else if((yyvsp[(2) - (2)].val).type == STRING_TYPE) {printf("WRITE: %s\n", (yyvsp[(2) - (2)].val).sval);} else if((yyvsp[(2) - (2)].val).type == REAL_TYPE) {printf("WRITE: %f\n", (yyvsp[(2) - (2)].val).rval);} else if((yyvsp[(2) - (2)].val).type == INT_TYPE) {printf("WRITE: %d\n", (yyvsp[(2) - (2)].val).ival);} else if((yyvsp[(2) - (2)].val).type == BOOL_TYPE) {printf("WRITE: %d\n", (yyvsp[(2) - (2)].val).bval);} ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 284 "yacc2.y"
    {(yyval.intval) = INT_TYPE;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 285 "yacc2.y"
    {(yyval.intval) = REAL_TYPE;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 286 "yacc2.y"
    {(yyval.intval) = CHAR_TYPE;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 287 "yacc2.y"
    {(yyval.intval) = STRING_TYPE;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 288 "yacc2.y"
    {(yyval.intval) = BOOL_TYPE;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 291 "yacc2.y"
    {if((yyvsp[(2) - (7)].val).type != BOOL_TYPE) {yyerror("You must have a boolean condition with if statement"); exit(1);};}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 295 "yacc2.y"
    {if((yyvsp[(3) - (5)].val).type != BOOL_TYPE) { yyerror("You must have a boolean condition with elif statement"); exit(1);};}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 302 "yacc2.y"
    {if((yyvsp[(2) - (5)].val).type != BOOL_TYPE) {yyerror("You must choose a boolean condition with loop statement"); exit(1);};}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 309 "yacc2.y"
    { printf("curr_scope finishing = %d\n", curr_scope);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 312 "yacc2.y"
    { context_check((yyvsp[(4) - (7)].id), curr_scope); install((yyvsp[(2) - (7)].id), (yyvsp[(7) - (7)].intval), 0, 0, 0, "N", "null", curr_scope); curr_scope++; printf("%d\n", curr_scope); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 315 "yacc2.y"
    {curr_scope--; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2058 "yacc2.tab.c"
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
#line 354 "yacc2.y"

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
int main( int argc, char *argv[] ){ 
    extern FILE *yyin;
    ++argv; argc = argc-1;
    yyin = fopen( argv[0], "r" );
    int errors = 0;
    yyparse ();
}
