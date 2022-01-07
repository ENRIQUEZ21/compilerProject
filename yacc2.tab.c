
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
  #include "ST.h"
  #define YYDEBUG 1
  int yylex(void);
  void yyerror(char *);

  int curr_scope = 0;


  void install ( char *sym_name, int type, int int_val, double real_val, int bool_val, int current_scope)
  {
    symrec *s;
    symrec *i;
    s = getsym (sym_name, current_scope);
    if (s == 0) {
      putsym (sym_name, type, int_val, real_val, bool_val, current_scope);   
    } else { 
      printf( "%s is already defined\n", sym_name );
    }
  }

  void context_check( char *sym_name, int scope ) { 
    symrec *identifier;
    identifier = getsym( sym_name, scope );
    if ( identifier == 0 ) { 
      printf( "%s", sym_name );
      printf( "%s\n", " is an undeclared identifier" );
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





/* Line 189 of yacc.c  */
#line 149 "yacc2.tab.c"

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
     VAR = 270,
     COLON = 271,
     OPENPAR = 272,
     CLOSEPAR = 273,
     COMMA = 274,
     COMMENT = 275,
     SEMICOLON = 276,
     STARTPRGM = 277,
     ENDPRGM = 278,
     BEGSTMT = 279,
     ENDSTMT = 280,
     IF = 281,
     THEN = 282,
     ELIF = 283,
     ELSE = 284,
     ENDIF = 285,
     WHILE = 286,
     DO = 287,
     ENDWHILE = 288,
     WRITE = 289,
     FCT = 290,
     RETURN = 291,
     OR = 292,
     AND = 293,
     NE = 294,
     EQ = 295,
     GT = 296,
     LT = 297,
     GE = 298,
     LE = 299,
     ASSIGNMENT = 300,
     MOD = 301,
     DIV = 302,
     DIVOP = 303,
     MULOP = 304,
     MINOP = 305,
     ADDOP = 306,
     SQRT = 307,
     TAN = 308,
     SIN = 309,
     COS = 310,
     LN = 311,
     LOG = 312,
     EXP = 313,
     ABS = 314,
     POW = 315,
     CEIL = 316,
     FLOOR = 317,
     NOT = 318
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union 
/* Line 214 of yacc.c  */
#line 77 "yacc2.y"
semrec
{

/* Line 214 of yacc.c  */
#line 78 "yacc2.y"

  double doubleval;
  int intval; 
  char *chstval;
  char *id;
  struct lbs *lbls; 



/* Line 214 of yacc.c  */
#line 261 "yacc2.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 273 "yacc2.tab.c"

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
#define YYLAST   354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNRULES -- Number of states.  */
#define YYNSTATES  265

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    13,    14,    18,    22,    27,    29,
      31,    39,    45,    47,    49,    54,    55,    57,    59,    61,
      63,    68,    73,    78,    80,    84,    88,    91,    93,    97,
     101,   105,   109,   112,   114,   118,   123,   130,   135,   140,
     145,   150,   155,   160,   165,   170,   175,   177,   181,   185,
     188,   190,   194,   198,   202,   206,   209,   211,   215,   220,
     227,   232,   237,   242,   247,   252,   257,   262,   267,   272,
     274,   276,   278,   282,   286,   290,   294,   298,   302,   306,
     310,   313,   315,   318,   320,   324,   326,   328,   330,   332,
     334,   336,   338,   339,   345,   346,   349,   352,   354,   356,
     358,   361,   365,   373,   376,   378,   382,   384,   386,   388,
     390,   392,   394,   396,   400
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      65,     0,    -1,    22,    67,    92,    68,    23,    -1,    24,
      68,    25,    -1,    -1,    67,    70,    21,    -1,    71,    69,
      21,    -1,    68,    71,    69,    21,    -1,    72,    -1,    70,
      -1,    26,    83,    27,    66,    88,    89,    30,    -1,    31,
      83,    32,    66,    33,    -1,    90,    -1,    99,    -1,    15,
       3,    16,    87,    -1,    -1,    20,    -1,    73,    -1,    74,
      -1,    75,    -1,     3,    45,    10,    76,    -1,     3,    45,
      11,    79,    -1,     3,    45,    14,    83,    -1,    77,    -1,
      76,    51,    77,    -1,    76,    50,    77,    -1,    50,    77,
      -1,    78,    -1,    77,    49,    78,    -1,    77,    48,    78,
      -1,    77,    47,    78,    -1,    77,    46,    78,    -1,    10,
       3,    -1,     7,    -1,    17,    76,    18,    -1,    59,    17,
      76,    18,    -1,    60,    17,    76,    19,    76,    18,    -1,
      52,    17,    76,    18,    -1,    58,    17,    76,    18,    -1,
      57,    17,    76,    18,    -1,    56,    17,    76,    18,    -1,
      62,    17,    76,    18,    -1,    61,    17,    76,    18,    -1,
      55,    17,    76,    18,    -1,    54,    17,    76,    18,    -1,
      53,    17,    76,    18,    -1,    80,    -1,    79,    51,    80,
      -1,    79,    50,    80,    -1,    50,    80,    -1,    81,    -1,
      80,    49,    81,    -1,    80,    48,    81,    -1,    80,    47,
      81,    -1,    80,    46,    81,    -1,    11,     3,    -1,    82,
      -1,    17,    79,    18,    -1,    59,    17,    79,    18,    -1,
      60,    17,    79,    19,    79,    18,    -1,    52,    17,    79,
      18,    -1,    58,    17,    79,    18,    -1,    57,    17,    79,
      18,    -1,    56,    17,    79,    18,    -1,    62,    17,    79,
      18,    -1,    61,    17,    79,    18,    -1,    55,    17,    79,
      18,    -1,    54,    17,    79,    18,    -1,    53,    17,    79,
      18,    -1,     7,    -1,     6,    -1,    84,    -1,    79,    43,
      80,    -1,    79,    44,    80,    -1,    79,    41,    80,    -1,
      79,    42,    80,    -1,    79,    40,    80,    -1,    79,    39,
      80,    -1,    83,    38,    84,    -1,    83,    37,    84,    -1,
      63,    84,    -1,    85,    -1,    14,     3,    -1,    86,    -1,
      17,    83,    18,    -1,     4,    -1,     5,    -1,    10,    -1,
      11,    -1,    12,    -1,    13,    -1,    14,    -1,    -1,    88,
      28,    83,    27,    66,    -1,    -1,    29,    66,    -1,    34,
      91,    -1,     8,    -1,     9,    -1,    21,    -1,    92,    93,
      -1,    94,    66,    95,    -1,    35,     3,    17,    96,    18,
      16,    87,    -1,    36,     3,    -1,     3,    -1,     3,    19,
      96,    -1,     3,    -1,     7,    -1,     6,    -1,     8,    -1,
       9,    -1,    86,    -1,    97,    -1,    97,    19,    98,    -1,
       3,    45,     3,    17,    98,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   109,   109,   111,   114,   115,   118,   119,   122,   123,
     124,   125,   126,   127,   130,   132,   133,   136,   137,   138,
     141,   144,   147,   150,   151,   152,   153,   156,   157,   158,
     159,   160,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   179,   180,   181,   182,
     185,   186,   187,   188,   189,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   209,
     210,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   225,   228,   229,   230,   233,   234,   238,   239,   240,
     241,   242,   245,   246,   249,   250,   253,   256,   257,   260,
     261,   264,   267,   270,   274,   275,   278,   279,   280,   281,
     282,   283,   286,   287,   290
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "TRUE", "FALSE", "REAL", "INTEGER",
  "CHAR", "STRING", "INT_TYPE", "REAL_TYPE", "CHAR_TYPE", "STRING_TYPE",
  "BOOL_TYPE", "VAR", "COLON", "OPENPAR", "CLOSEPAR", "COMMA", "COMMENT",
  "SEMICOLON", "STARTPRGM", "ENDPRGM", "BEGSTMT", "ENDSTMT", "IF", "THEN",
  "ELIF", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "WRITE", "FCT",
  "RETURN", "OR", "AND", "NE", "EQ", "GT", "LT", "GE", "LE", "ASSIGNMENT",
  "MOD", "DIV", "DIVOP", "MULOP", "MINOP", "ADDOP", "SQRT", "TAN", "SIN",
  "COS", "LN", "LOG", "EXP", "ABS", "POW", "CEIL", "FLOOR", "NOT",
  "$accept", "program", "groupstmts", "declarations", "stmts", "stmt",
  "declaration", "comment", "assignexpr", "assignintexpr", "assignreaexpr",
  "assignbooexpr", "intexpr", "intfactor", "intterm", "reaexpr",
  "reafactor", "reaterm", "number", "booexpr", "boofactor", "booterm",
  "boolean", "type", "elifstmt", "elsestmt", "write", "charsandstrings",
  "fcts", "fct", "headfct", "returnfct", "parameters", "instances",
  "parametersinstances", "callfct", 0
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
     315,   316,   317,   318
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    67,    67,    68,    68,    69,    69,
      69,    69,    69,    69,    70,    71,    71,    72,    72,    72,
      73,    74,    75,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    79,    79,
      80,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    84,    85,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    88,    88,    89,    89,    90,    91,    91,    92,
      92,    93,    94,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    98,    98,    99
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     0,     3,     3,     4,     1,     1,
       7,     5,     1,     1,     4,     0,     1,     1,     1,     1,
       4,     4,     4,     1,     3,     3,     2,     1,     3,     3,
       3,     3,     2,     1,     3,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     1,     3,     3,     2,
       1,     3,     3,     3,     3,     2,     1,     3,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     0,     2,     2,     1,     1,     1,
       2,     3,     7,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     1,     0,    99,     0,    15,     0,
       5,    16,     0,    15,     0,   100,     0,     0,     0,     2,
       0,     0,     0,     0,     0,     0,     9,     8,    17,    18,
      19,    12,    13,    15,     0,    87,    88,    89,    90,    91,
      14,     0,     0,     0,    85,    86,    70,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,    50,    56,     0,    71,
      81,    83,     0,    97,    98,    96,     6,    15,     0,   101,
     104,     0,     7,     0,     0,     0,     0,    55,    82,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,   103,     0,     0,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    23,    27,    21,    22,    57,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    76,    74,    75,    72,    73,    48,    47,    54,
      53,    52,    51,    92,    79,    78,     0,   105,     0,   106,
     108,   107,   109,   110,   111,   112,     0,    32,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    68,    67,
      66,    63,    62,    61,    58,     0,    65,    64,    94,    11,
     102,     0,   114,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    24,    31,    30,    29,
      28,     0,     0,     0,     0,   113,    37,    45,    44,    43,
      40,    39,    38,    35,     0,    42,    41,    59,     0,    95,
      10,     0,     0,    36,    93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    34,     3,    13,    25,    26,    14,    27,    28,
      29,    30,   142,   143,   144,    64,    65,    66,    67,    90,
      69,    70,    71,    40,   218,   244,    31,    75,     8,    15,
      16,    79,    81,   185,   186,    32
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -126
static const yytype_int16 yypact[] =
{
       1,  -126,    15,    78,  -126,    18,  -126,    23,     0,    11,
    -126,  -126,    26,    90,   306,  -126,    53,   267,    19,  -126,
     306,    49,    98,    98,   108,    76,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,    91,    99,  -126,  -126,  -126,  -126,  -126,
    -126,   111,   105,    28,  -126,  -126,  -126,  -126,   146,   160,
      98,   116,   164,   184,   194,   202,   256,   258,   265,   266,
     269,   270,   293,     5,   272,   271,  -126,  -126,    69,  -126,
    -126,  -126,   -21,  -126,  -126,  -126,  -126,    -7,   212,  -126,
     319,   240,  -126,   322,   172,    84,    98,  -126,  -126,   144,
      -4,    84,   271,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    98,  -126,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,    53,     5,
       5,    53,  -126,  -126,   111,   201,   199,  -126,   259,   172,
     183,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,    70,   278,  -126,   141,   159,  -126,  -126,   -10,
       6,     8,    10,    12,    74,    80,   114,   148,   255,   162,
     196,   271,   271,   271,   271,   271,   271,   271,   271,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,   227,  -126,   267,  -126,
    -126,  -126,  -126,  -126,  -126,   335,   246,  -126,   198,   278,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   183,   183,   183,   183,   183,   183,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,    84,  -126,  -126,   181,  -126,
    -126,   199,  -126,  -126,   200,   203,   205,   234,   239,   241,
     243,   245,   257,   247,   249,   278,   278,  -126,  -126,  -126,
    -126,   251,    98,    53,   236,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,   172,  -126,  -126,  -126,    81,  -126,
    -126,   253,    53,  -126,  -126
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -115,  -126,   235,   250,   285,    -1,  -126,  -126,
    -126,  -126,  -125,  -123,   125,   -48,   -26,   219,  -126,   -22,
     -31,  -126,  -121,    94,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,   228,  -126,   132,  -126
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      68,    72,    89,   173,   188,   184,   176,   189,   147,    44,
      45,   121,    20,    11,   148,     4,   119,   120,   122,    49,
      11,     9,   104,     1,   207,    92,   208,    17,   209,    18,
     210,    83,   105,   119,   120,    12,    41,   145,    84,    85,
     112,   113,    86,   149,    10,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   112,   113,   112,   113,
     112,   113,   112,   113,   146,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,    20,    33,   235,   236,
     161,   162,   163,   164,   165,   166,   167,   168,   174,   175,
      46,    47,   211,     5,    43,    48,   118,    76,   212,     6,
     184,    91,    44,    45,    46,    47,   119,   120,   262,    48,
      11,    11,    49,    19,    80,    50,    73,    74,   119,   120,
     201,   202,    46,    47,   112,   113,    82,    48,   259,   261,
     112,   113,   213,    91,    51,    78,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   264,    51,    87,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,   147,    88,   112,   113,   214,   241,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,   127,
     216,    93,   128,   106,   107,   108,   109,   110,   111,   129,
     127,   112,   113,   128,   112,   113,   119,   120,   112,   113,
     129,    94,   179,    44,    45,   180,   181,   182,   183,   242,
     243,    95,   112,   113,   217,   123,   223,   178,   246,    96,
     258,   247,   130,   248,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   112,   113,   201,   202,
     201,   202,   249,   201,   202,   201,   202,   250,   125,   251,
     219,   252,   187,   253,   222,   255,   260,   256,    77,   257,
      42,   263,   220,    97,   215,    98,   254,    35,    36,    37,
      38,    39,    99,   100,   201,   202,   101,   102,     7,   201,
     202,   201,   202,   201,   202,   201,   202,   201,   202,   201,
     202,   112,   113,   201,   202,   112,   113,   201,   202,    21,
     103,   106,   107,   108,   109,   110,   111,   114,   115,   116,
     117,     5,   112,   113,   203,   204,   205,   206,   237,   238,
     239,   240,    22,   169,   170,   171,   172,    23,   124,   126,
      24,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   177,   245,   221
};

static const yytype_uint16 yycheck[] =
{
      22,    23,    50,   118,   129,   126,   121,   130,    18,     4,
       5,    32,    13,    20,    18,     0,    37,    38,    25,    14,
      20,     3,    17,    22,    18,    51,    18,    16,    18,     3,
      18,     3,    63,    37,    38,    35,    17,    85,    10,    11,
      50,    51,    14,    91,    21,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    50,    51,    50,    51,
      50,    51,    50,    51,    86,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    77,    24,   201,   202,
     106,   107,   108,   109,   110,   111,   112,   113,   119,   120,
       6,     7,    18,    15,    45,    11,    27,    21,    18,    21,
     221,    17,     4,     5,     6,     7,    37,    38,    27,    11,
      20,    20,    14,    23,     3,    17,     8,     9,    37,    38,
      50,    51,     6,     7,    50,    51,    21,    11,   243,   254,
      50,    51,    18,    17,    50,    36,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   262,    50,     3,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    18,     3,    50,    51,    18,   215,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     7,
      18,    17,    10,    39,    40,    41,    42,    43,    44,    17,
       7,    50,    51,    10,    50,    51,    37,    38,    50,    51,
      17,    17,     3,     4,     5,     6,     7,     8,     9,    28,
      29,    17,    50,    51,    18,     3,    18,    16,    18,    17,
     242,    18,    50,    18,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    50,    51,    50,    51,
      50,    51,    18,    50,    51,    50,    51,    18,    18,    18,
      33,    18,     3,    18,    18,    18,    30,    18,    33,    18,
      20,    18,   178,    17,    19,    17,    19,    10,    11,    12,
      13,    14,    17,    17,    50,    51,    17,    17,     3,    50,
      51,    50,    51,    50,    51,    50,    51,    50,    51,    50,
      51,    50,    51,    50,    51,    50,    51,    50,    51,     3,
      17,    39,    40,    41,    42,    43,    44,    46,    47,    48,
      49,    15,    50,    51,    46,    47,    48,    49,   203,   204,
     205,   206,    26,   114,   115,   116,   117,    31,    19,    17,
      34,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,   124,   221,    19
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    65,    67,     0,    15,    21,    70,    92,     3,
      21,    20,    35,    68,    71,    93,    94,    16,     3,    23,
      71,     3,    26,    31,    34,    69,    70,    72,    73,    74,
      75,    90,    99,    24,    66,    10,    11,    12,    13,    14,
      87,    17,    69,    45,     4,     5,     6,     7,    11,    14,
      17,    50,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    79,    80,    81,    82,    83,    84,
      85,    86,    83,     8,     9,    91,    21,    68,    36,    95,
       3,    96,    21,     3,    10,    11,    14,     3,     3,    79,
      83,    17,    80,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    84,    39,    40,    41,    42,
      43,    44,    50,    51,    46,    47,    48,    49,    27,    37,
      38,    32,    25,     3,    19,    18,    17,     7,    10,    17,
      50,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    76,    77,    78,    79,    83,    18,    18,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    81,    81,    66,    84,    84,    66,    96,    16,     3,
       6,     7,     8,     9,    86,    97,    98,     3,    76,    77,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    50,    51,    46,    47,    48,    49,    18,    18,    18,
      18,    18,    18,    18,    18,    19,    18,    18,    88,    33,
      87,    19,    18,    18,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    77,    77,    78,    78,    78,
      78,    79,    28,    29,    89,    98,    18,    18,    18,    18,
      18,    18,    18,    18,    19,    18,    18,    18,    83,    66,
      30,    76,    27,    18,    66
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
        case 10:

/* Line 1455 of yacc.c  */
#line 124 "yacc2.y"
    {printf("CONDITIONAL STATEMENT");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 125 "yacc2.y"
    {printf("LOOP STATEMENT");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 130 "yacc2.y"
    { printf("curr_scope = %d\n", curr_scope); install((yyvsp[(2) - (4)].id), (yyvsp[(4) - (4)].intval), 0, 0, 0, curr_scope); printf("DECLARATION %s, %d \n", (yyvsp[(2) - (4)].id), (yyvsp[(4) - (4)].intval));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 141 "yacc2.y"
    { context_check((yyvsp[(1) - (4)].id), curr_scope); check_type((yyvsp[(1) - (4)].id), INT_TYPE, curr_scope); set_int_value((yyvsp[(1) - (4)].id), (yyvsp[(4) - (4)].intval), curr_scope); printf("INTEGER %d ASSIGNED TO %s\n", (yyvsp[(4) - (4)].intval), (yyvsp[(1) - (4)].id));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 144 "yacc2.y"
    { context_check((yyvsp[(1) - (4)].id), curr_scope); check_type((yyvsp[(1) - (4)].id), REAL_TYPE, curr_scope); set_real_value((yyvsp[(1) - (4)].id), (yyvsp[(4) - (4)].doubleval), curr_scope); printf("REAL %f ASSIGNED TO %s\n", (yyvsp[(4) - (4)].doubleval), (yyvsp[(1) - (4)].id));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 147 "yacc2.y"
    { context_check((yyvsp[(1) - (4)].id), curr_scope); check_type((yyvsp[(1) - (4)].id), BOOL_TYPE, curr_scope); set_bool_value((yyvsp[(1) - (4)].id), (yyvsp[(4) - (4)].intval), curr_scope); printf("BOOLEAN %d ASSIGNED TO %s\n", (yyvsp[(4) - (4)].intval), (yyvsp[(1) - (4)].id));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 150 "yacc2.y"
    {(yyval.intval) = (yyvsp[(1) - (1)].intval); printf("MY INT FACTOR = %d\n", (yyval.intval));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 151 "yacc2.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].intval)+(yyvsp[(3) - (3)].intval); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 152 "yacc2.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].intval)-(yyvsp[(3) - (3)].intval); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 153 "yacc2.y"
    { (yyval.intval) = -(yyvsp[(2) - (2)].intval); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 156 "yacc2.y"
    {(yyval.intval) = (yyvsp[(1) - (1)].intval); printf("MY INT TERM = %d\n", (yyval.intval));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 157 "yacc2.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].intval)*(yyvsp[(3) - (3)].intval); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 158 "yacc2.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].intval)/(yyvsp[(3) - (3)].intval); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 159 "yacc2.y"
    { (yyval.intval) = floor((yyvsp[(1) - (3)].intval) / (yyvsp[(3) - (3)].intval)); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 160 "yacc2.y"
    { (yyval.intval) = fmod((yyvsp[(1) - (3)].intval), (yyvsp[(3) - (3)].intval)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 163 "yacc2.y"
    { check_type((yyvsp[(2) - (2)].id), INT_TYPE, curr_scope); (yyval.intval) = get_int_value((yyvsp[(2) - (2)].id), curr_scope); printf("MY INT = %d\n", (yyval.intval)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 164 "yacc2.y"
    {(yyval.intval) = (yyvsp[(1) - (1)].intval);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 165 "yacc2.y"
    {(yyval.intval) = (yyvsp[(2) - (3)].intval);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 166 "yacc2.y"
    {(yyval.intval) = abs((yyvsp[(3) - (4)].intval));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 167 "yacc2.y"
    {(yyval.intval) = pow((yyvsp[(3) - (6)].intval), (yyvsp[(5) - (6)].intval));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 168 "yacc2.y"
    { if((yyvsp[(3) - (4)].intval) >= 0) {(yyval.intval) = sqrt((yyvsp[(3) - (4)].intval)); printf("result = %d\n", (yyval.intval));} else{yyerror("Cannot make sqrt on negative number");exit(1);};}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 169 "yacc2.y"
    {(yyval.intval) = exp((yyvsp[(3) - (4)].intval)); printf("result = %d\n", (yyval.intval));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 170 "yacc2.y"
    {if((yyvsp[(3) - (4)].intval) >= 0) {(yyval.intval) = log10((yyvsp[(3) - (4)].intval)); printf("result = %d\n", (yyval.intval));} else {yyerror("Cannot make log on negative number");exit(1);};}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 171 "yacc2.y"
    {if((yyvsp[(3) - (4)].intval) >= 0) {(yyval.intval) = log((yyvsp[(3) - (4)].intval)); printf("result = %d\n", (yyval.intval));} else {yyerror("Cannot make ln on negative number");exit(1);};}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 172 "yacc2.y"
    {(yyval.intval) = floor((yyvsp[(3) - (4)].intval)); printf("result = %d\n", (yyval.intval));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 173 "yacc2.y"
    {(yyval.intval) = ceil((yyvsp[(3) - (4)].intval)); printf("result = %d\n", (yyval.intval));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 174 "yacc2.y"
    {(yyval.intval) = cos((yyvsp[(3) - (4)].intval)); printf("result = %d\n", (yyval.intval));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 175 "yacc2.y"
    {(yyval.intval) = sin((yyvsp[(3) - (4)].intval)); printf("result = %d\n", (yyval.intval));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 176 "yacc2.y"
    {(yyval.intval) = tan((yyvsp[(3) - (4)].intval)); printf("result = %d\n", (yyval.intval));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 179 "yacc2.y"
    {(yyval.doubleval) = (yyvsp[(1) - (1)].doubleval); printf("MY REAL FACTOR = %f\n", (yyval.doubleval));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 180 "yacc2.y"
    {(yyval.doubleval) = (yyvsp[(1) - (3)].doubleval)+(yyvsp[(3) - (3)].doubleval);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 181 "yacc2.y"
    {(yyval.doubleval) = (yyvsp[(1) - (3)].doubleval)-(yyvsp[(3) - (3)].doubleval);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 182 "yacc2.y"
    {(yyval.doubleval) = -(yyvsp[(2) - (2)].doubleval);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 185 "yacc2.y"
    {(yyval.doubleval) = (yyvsp[(1) - (1)].doubleval);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 186 "yacc2.y"
    {(yyval.doubleval) = (yyvsp[(1) - (3)].doubleval)*(yyvsp[(3) - (3)].doubleval);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 187 "yacc2.y"
    {(yyval.doubleval) = (yyvsp[(1) - (3)].doubleval)/(yyvsp[(3) - (3)].doubleval);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 188 "yacc2.y"
    {(yyval.doubleval) = floor((yyvsp[(1) - (3)].doubleval)/(yyvsp[(3) - (3)].doubleval));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 189 "yacc2.y"
    {(yyval.doubleval) = fmod((yyvsp[(1) - (3)].doubleval), (yyvsp[(3) - (3)].doubleval));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 192 "yacc2.y"
    { check_type((yyvsp[(2) - (2)].id), REAL_TYPE, curr_scope); (yyval.doubleval) = get_real_value((yyvsp[(2) - (2)].id), curr_scope); printf("MY REAL = %f\n", (yyval.doubleval)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 193 "yacc2.y"
    {(yyval.doubleval) = (yyvsp[(1) - (1)].doubleval);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 194 "yacc2.y"
    {(yyval.doubleval) = (yyvsp[(2) - (3)].doubleval);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 195 "yacc2.y"
    {(yyval.doubleval) = abs((yyvsp[(3) - (4)].doubleval));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 196 "yacc2.y"
    {(yyval.doubleval) = pow((yyvsp[(3) - (6)].doubleval), (yyvsp[(5) - (6)].doubleval));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 197 "yacc2.y"
    { if((yyvsp[(3) - (4)].doubleval) >= 0) {(yyval.doubleval) = sqrt((yyvsp[(3) - (4)].doubleval)); printf("result = %f\n", (yyval.doubleval));} else{yyerror("Cannot make sqrt on negative number");exit(1);};}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 198 "yacc2.y"
    {(yyval.doubleval) = exp((yyvsp[(3) - (4)].doubleval)); printf("result = %f\n", (yyval.doubleval));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 199 "yacc2.y"
    {if((yyvsp[(3) - (4)].doubleval) >= 0) {(yyval.doubleval) = log10((yyvsp[(3) - (4)].doubleval)); printf("result = %f\n", (yyval.doubleval));} else {yyerror("Cannot make log on negative number");exit(1);};}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 200 "yacc2.y"
    {if((yyvsp[(3) - (4)].doubleval) >= 0) {(yyval.doubleval) = log((yyvsp[(3) - (4)].doubleval)); printf("result = %f\n", (yyval.doubleval));} else {yyerror("Cannot make ln on negative number");exit(1);};}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 201 "yacc2.y"
    {(yyval.doubleval) = floor((yyvsp[(3) - (4)].doubleval)); printf("result = %f\n", (yyval.doubleval));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 202 "yacc2.y"
    {(yyval.doubleval) = ceil((yyvsp[(3) - (4)].doubleval)); printf("result = %f\n", (yyval.doubleval));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 203 "yacc2.y"
    {(yyval.doubleval) = cos((yyvsp[(3) - (4)].doubleval)); printf("result = %f\n", (yyval.doubleval));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 204 "yacc2.y"
    {(yyval.doubleval) = sin((yyvsp[(3) - (4)].doubleval)); printf("result = %f\n", (yyval.doubleval));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 205 "yacc2.y"
    {(yyval.doubleval) = tan((yyvsp[(3) - (4)].doubleval)); printf("result = %f\n", (yyval.doubleval));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 209 "yacc2.y"
    {(yyval.doubleval) = (float)(yyvsp[(1) - (1)].intval); printf("MY INTEGER IS IN REAL = %f", (yyval.doubleval));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 210 "yacc2.y"
    {(yyval.doubleval) = (yyvsp[(1) - (1)].doubleval); printf("MY REAL = %f", (yyval.doubleval));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 213 "yacc2.y"
    {(yyval.intval) = (yyvsp[(1) - (1)].intval); printf("MY BOOL EXPR = %d\n", (yyval.intval));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 214 "yacc2.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].doubleval) >= (yyvsp[(3) - (3)].doubleval); printf("result = %d\n", (yyval.intval));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 215 "yacc2.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].doubleval) <= (yyvsp[(3) - (3)].doubleval); printf("result = %d\n", (yyval.intval));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 216 "yacc2.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].doubleval) > (yyvsp[(3) - (3)].doubleval); printf("result = %d\n", (yyval.intval));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 217 "yacc2.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].doubleval) < (yyvsp[(3) - (3)].doubleval); printf("result = %d\n", (yyval.intval));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 218 "yacc2.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].doubleval) == (yyvsp[(3) - (3)].doubleval); printf("result = %d\n", (yyval.intval));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 219 "yacc2.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].doubleval) != (yyvsp[(3) - (3)].doubleval); printf("result = %d\n", (yyval.intval));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 220 "yacc2.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].intval) && (yyvsp[(3) - (3)].intval); printf("result = %d\n", (yyval.intval));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 221 "yacc2.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].intval) || (yyvsp[(3) - (3)].intval); printf("result = %d\n", (yyval.intval));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 222 "yacc2.y"
    { (yyval.intval) = (!(yyvsp[(2) - (2)].intval)); printf("result = %d\n", (yyval.intval));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 225 "yacc2.y"
    {(yyval.intval) = (yyvsp[(1) - (1)].intval); printf("result = %d\n", (yyval.intval));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 228 "yacc2.y"
    { check_type((yyvsp[(2) - (2)].id), BOOL_TYPE, curr_scope); (yyval.intval) = get_bool_value((yyvsp[(2) - (2)].id), curr_scope); printf("MY BOOL = %d\n", (yyval.intval)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 229 "yacc2.y"
    {(yyval.intval) = (yyvsp[(1) - (1)].intval); printf("IT IS A BOOLEAN \n");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 230 "yacc2.y"
    {(yyval.intval) = (yyvsp[(2) - (3)].intval); printf("result = %d\n", (yyval.intval));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 233 "yacc2.y"
    { (yyval.intval) = 1; printf("BOOL VALUE = %d\n", (yyval.intval));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 234 "yacc2.y"
    { (yyval.intval) = 0; printf("BOOL VALUE = %d\n", (yyval.intval));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 238 "yacc2.y"
    {(yyval.intval) = INT_TYPE;;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 239 "yacc2.y"
    {(yyval.intval) = REAL_TYPE;;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 240 "yacc2.y"
    {(yyval.intval) = CHAR_TYPE;;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 241 "yacc2.y"
    {(yyval.intval) = STRING_TYPE;;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 242 "yacc2.y"
    {(yyval.intval) = BOOL_TYPE;;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 253 "yacc2.y"
    {printf("WRITE: %s\n", (yyvsp[(2) - (2)].chstval));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 256 "yacc2.y"
    { (yyval.chstval) = (yyvsp[(1) - (1)].chstval); printf("OUR CHAR IS %s\n", (yyval.chstval));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 257 "yacc2.y"
    { (yyval.chstval) = (yyvsp[(1) - (1)].chstval); printf("OUR STRING IS %s\n", (yyval.chstval));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 267 "yacc2.y"
    { curr_scope++; printf("curr_scope = %d\n", curr_scope); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 270 "yacc2.y"
    {curr_scope--;  printf("curr_scope = %d\n", curr_scope);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 274 "yacc2.y"
    { context_check((yyvsp[(1) - (1)].id), curr_scope); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 275 "yacc2.y"
    { context_check((yyvsp[(1) - (3)].id), curr_scope);;}
    break;



/* Line 1455 of yacc.c  */
#line 2287 "yacc2.tab.c"
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
#line 293 "yacc2.y"

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
