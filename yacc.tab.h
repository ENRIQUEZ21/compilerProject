
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     INT_TYPE = 259,
     REAL_TYPE = 260,
     CHAR_TYPE = 261,
     STRING_TYPE = 262,
     BOOL_TYPE = 263,
     WS = 264,
     LINE = 265,
     COMMENT = 266,
     STARTPRGM = 267,
     ENDPRGM = 268,
     IF = 269,
     THEN = 270,
     ELIF = 271,
     ELSE = 272,
     ENDIF = 273,
     WHILE = 274,
     DO = 275,
     ENDWHILE = 276,
     BEGSTMT = 277,
     ENDSTMT = 278,
     CLASS = 279,
     ENDCLASS = 280,
     WRITE = 281,
     COMMA = 282,
     DBPTS = 283,
     OPENPAR = 284,
     CLOSEPAR = 285,
     OPENBRA = 286,
     CLOSEBRA = 287,
     SEMICOLON = 288,
     DOT = 289,
     INTEGER = 290,
     REAL = 291,
     CHAR = 292,
     STRING = 293,
     TRUE = 294,
     FALSE = 295,
     MODIFIER = 296,
     VAR = 297,
     NEWINSTCLASS = 298,
     FCT = 299,
     RETURN = 300,
     AND = 301,
     OR = 302,
     NE = 303,
     EQ = 304,
     GT = 305,
     LT = 306,
     GE = 307,
     LE = 308,
     ASSIGNMENT = 309,
     MOD = 310,
     DIV = 311,
     DIVOP = 312,
     MULOP = 313,
     MINOP = 314,
     ADDOP = 315,
     CEIL = 316,
     FLOOR = 317,
     SIN = 318,
     COS = 319,
     TAN = 320,
     RAND = 321,
     LN = 322,
     LOG = 323,
     EXP = 324,
     SQRT = 325,
     POW = 326,
     ABS = 327,
     NOT = 328
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union 
/* Line 1676 of yacc.c  */
#line 69 "yacc.y"
semrec
{

/* Line 1676 of yacc.c  */
#line 70 "yacc.y"

  double doubleval;
  int intval; 
  int boolval;
  char *id;
  struct lbs *lbls; 



/* Line 1676 of yacc.c  */
#line 138 "yacc.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


