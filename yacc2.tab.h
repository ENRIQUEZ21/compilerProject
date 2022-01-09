
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
/* Line 1676 of yacc.c  */
#line 105 "yacc2.y"
semrec
{

/* Line 1676 of yacc.c  */
#line 106 "yacc2.y"
 
  struct Value val;
  double doubleval;
  int intval; 
  char *chstval;
  char *id;
  struct lbs *lbls; 



/* Line 1676 of yacc.c  */
#line 132 "yacc2.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


