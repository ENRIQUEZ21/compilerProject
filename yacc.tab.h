
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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 11 "yacc.y"

    #define YYSTYPE double
  


/* Line 1676 of yacc.c  */
#line 46 "yacc.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     WS = 259,
     LINE = 260,
     COMMENT = 261,
     STARTPRGM = 262,
     ENDPRGM = 263,
     IF = 264,
     THEN = 265,
     ELIF = 266,
     ELSE = 267,
     ENDIF = 268,
     WHILE = 269,
     DO = 270,
     ENDWHILE = 271,
     BEGSTMT = 272,
     ENDSTMT = 273,
     CLASS = 274,
     ENDCLASS = 275,
     WRITE = 276,
     COMMA = 277,
     DBPTS = 278,
     OPENPAR = 279,
     CLOSEPAR = 280,
     OPENBRA = 281,
     CLOSEBRA = 282,
     SEMICOLON = 283,
     DOT = 284,
     INTEGER = 285,
     REAL = 286,
     CHAR = 287,
     STRING = 288,
     BOOLEAN = 289,
     MODIFIER = 290,
     TYPE = 291,
     VAR = 292,
     NEWINSTCLASS = 293,
     FCT = 294,
     RETURN = 295,
     AND = 296,
     OR = 297,
     NE = 298,
     EQ = 299,
     GT = 300,
     LT = 301,
     GE = 302,
     LE = 303,
     ASSIGNMENT = 304,
     MOD = 305,
     DIV = 306,
     DIVOP = 307,
     MULOP = 308,
     MINOP = 309,
     ADDOP = 310,
     LN = 311,
     LOG = 312,
     EXP = 313,
     SQRT = 314,
     POW = 315,
     ABS = 316,
     NOT = 317
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


