
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
     VAR = 270,
     DBPTS = 271,
     OPENPAR = 272,
     CLOSEPAR = 273,
     COMMA = 274,
     COMMENT = 275,
     NEWLINE = 276,
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
/* Line 1676 of yacc.c  */
#line 74 "yacc2.y"
semrec
{

/* Line 1676 of yacc.c  */
#line 75 "yacc2.y"

  double doubleval;
  int intval; 
  char *chstval;
  char *id;
  struct lbs *lbls; 



/* Line 1676 of yacc.c  */
#line 128 "yacc2.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


