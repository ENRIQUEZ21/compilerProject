%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
  #include <ctype.h>
  #include "variables.h"
  #include "ast.h"
  #include "ST.h"
  #define YYDEBUG 1
  int yylex(void);
  void yyerror(char *);

  

  int curr_scope = 0;
  char *curr_fct = "N";
  char *curr_call = "N";
  int num_param = 0; 


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
    if (identifier == 0) { 
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
    if (identifier == 0) { 
      printf( "%s", sym_name );
      printf( "%s\n", " is an undeclared identifier" );
      exit(1);
    }
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

  void put_param(char *name, int type, char *reference) {
      putParam(name, type, reference);
  }

  void param_check(int num_param, char *name_param) {
    Param *parameter;
    parameter = getParamByNumber(num_param, name_param);
    if(parameter == 0) {
      printf("Your function %s doesn't contain parameter number %d\n", name_param, num_param);
      exit(1);
    }
  }

  void param_check_type(int num_param, char *name_param, int type) {
    Param *parameter;
    parameter = getParamByNumber(num_param, name_param);
    if(parameter->type != type) {
      printf("Your call function parameter number %d has wrong type\n", num_param);
      exit(1);
    }
  }

  int get_param_nb(char *ref) {
    return getParamNb(ref);

  }
  

%}


%union semrec 
{ 
  struct Value val;
  double doubleval;
  int intval; 
  char *id;
}



%token <id> ID;

%token TRUE FALSE REAL INTEGER CHAR STRING INT_TYPE REAL_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE;
%type <intval> type INT_TYPE REAL_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE;

%type <val> INTEGER REAL TRUE FALSE CHAR STRING;

%type <val> expr factor term;

%type <val> instances;


%token DECLARATIONS FUNCTIONS STATEMENTS

%token VAR COLON OPENPAR CLOSEPAR COMMA COMMENT SEMICOLON 
%token STARTPRGM ENDPRGM BEGSTMT ENDSTMT
%token IF THEN ELIF ELSE ENDIF WHILE DO ENDWHILE 
%token WRITE FCT RETURN
%token OR AND

%left ADDOP MINOP MULOP DIVOP DIV MOD ASSIGNMENT LE GE LT GT EQ NE 
%right NOT FLOOR CEIL POW ABS EXP LOG LN COS SIN TAN SQRT


%%

program: STARTPRGM DECLARATIONS declarations FUNCTIONS fcts STATEMENTS stmts ENDPRGM; 

groupstmts: BEGSTMT stmts ENDSTMT
;

declarations: 
|     declarations declaration SEMICOLON
;

stmts: 
|   stmts comment stmt SEMICOLON
;

stmt:  assignexpr  
|   declaration 
|   write    
|   conditionalstmt    {}
|   loopstmt       {}
|   callfct         { }
;

declaration: VAR ID COLON type    { install($2, $4, 0, 0, 0, "N", "null", curr_scope); printf("DECLARATION %s, %d \n", $2, $4);}

comment: 
|   COMMENT
;

assignexpr: ID ASSIGNMENT expr { context_check($1, curr_scope); if($3.type == INT_TYPE) {if(get_type($1, curr_scope) == INT_TYPE) { set_int_value($1, $3.ival, curr_scope); } else if(get_type($1, curr_scope) == REAL_TYPE) {set_real_value($1, $3.rval, curr_scope);} else {yyerror("Error assignment: bad type"); exit(1);}} else if($3.type == REAL_TYPE) {check_type($1, REAL_TYPE, curr_scope); set_real_value($1, $3.rval, curr_scope);} else if($3.type == BOOL_TYPE) {check_type($1, BOOL_TYPE, curr_scope); set_bool_value($1, $3.bval, curr_scope);} else if($3.type == CHAR_TYPE) {check_type($1, CHAR_TYPE, curr_scope); set_char_value($1, $3.cval, curr_scope);} else if($3.type == STRING_TYPE) {check_type($1, STRING_TYPE, curr_scope); set_string_value($1, $3.sval, curr_scope);} printf("ASSIGNED TO ID %s\n",$1); }
;



expr: factor              {$$.type = $1.type;  if($1.type == INT_TYPE) {$$.ival = $1.ival;} else if($1.type == REAL_TYPE) {$$.rval = $1.rval;} else if($1.type == BOOL_TYPE) {$$.bval = $1.bval;} else if($1.type == CHAR_TYPE) {$$.cval = $1.cval;} else if($1.type == STRING_TYPE) {$$.sval = $1.sval;}}
|   expr ADDOP factor     { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = $1.ival+$3.ival;} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval+(float)$3.ival;} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float)$1.ival+$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval+$3.rval;} else { yyerror("Must add numbers"); exit(1);} }
|   expr MINOP factor      { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = $1.ival-$3.ival;} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval-(float)$3.ival;} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float)$1.ival-$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval-$3.rval;} else { yyerror("Must substract numbers"); exit(1);} }
|   MINOP factor                { $$.type = $2.type; if($2.type == INT_TYPE) {$$.ival = -$2.ival;} else if($2.type == REAL_TYPE) {$$.rval = -$2.rval;} else {yyerror("- must be on number only"); exit(1);} }
|   expr GE factor      { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival >= $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval >= $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival >= $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval >= $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr LE factor      { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival <= $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval <= $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival <= $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval <= $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr GT factor     { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival > $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval > $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival > $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval > $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr LT factor     { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival < $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval < $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival < $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval < $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr EQ factor     { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival == $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval == $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival == $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval == $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr NE factor   { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival != $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval != $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival != $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval != $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr AND factor   { $$.type = BOOL_TYPE; if($1.type == BOOL_TYPE && $3.type == BOOL_TYPE) {$$.bval = $1.bval && $3.bval;} else {yyerror("Must make AND operation on boolean");}}
|   expr OR factor    { $$.type = BOOL_TYPE; if($1.type == BOOL_TYPE && $3.type == BOOL_TYPE) {$$.bval = $1.bval || $3.bval;} else {yyerror("Must make OR operation on boolean");}}
|   NOT factor            { $$.type = BOOL_TYPE; if($2.type == BOOL_TYPE) {$$.bval = (!$2.bval); } else {yyerror("Must make NOT operation on boolean");}}
;

factor: term              {$$.type = $1.type;  if($1.type == INT_TYPE) {$$.ival = $1.ival;} else if($1.type == REAL_TYPE) {$$.rval = $1.rval;} else if($1.type == BOOL_TYPE) {$$.bval = $1.bval;} else if($1.type == CHAR_TYPE) {$$.cval = $1.cval;} else if($1.type == STRING_TYPE) {$$.sval = $1.sval;} }
|   factor MULOP term    { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = $1.ival*$3.ival;} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval*(float)$3.ival;} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float)$1.ival*$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval*$3.rval;} else { yyerror("Must multiply numbers"); exit(1);} }
|   factor DIVOP term    { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = $1.ival/$3.ival;} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval/(float)$3.ival;} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float)$1.ival/$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float) $1.rval/$3.rval;} else { yyerror("Must divide numbers"); exit(1);} }
|   factor DIV term      { $$.type = INT_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.ival = $1.ival/$3.ival;} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.ival = (int) $1.rval/$3.ival;} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.ival = (int)$1.ival/$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.ival = (int) $1.rval/$3.rval;} else { yyerror("Must divide numbers"); exit(1);} }
|   factor MOD term      { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = (int)fmod($1.ival, $3.ival);} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = fmod($1.rval, (float)$3.ival);} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = fmod((float)$1.ival, $3.rval);} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = fmod($1.rval, $3.rval);} else { yyerror("Must divide numbers"); exit(1);}}
;

term: ID          { context_check($1, curr_scope); $$.type = get_type($1, curr_scope); if(get_type($1, curr_scope) == INT_TYPE) { $$.ival = get_int_value($1, curr_scope);} else if(get_type($1, curr_scope) == REAL_TYPE) {$$.rval = get_real_value($1, curr_scope);} else if(get_type($1, curr_scope) == BOOL_TYPE) {$$.bval = get_bool_value($1, curr_scope);} else if(get_type($1, curr_scope) == CHAR_TYPE) {$$.cval = get_char_value($1, curr_scope);} else if(get_type($1, curr_scope) == STRING_TYPE) {$$.sval = get_string_value($1, curr_scope);}}
|      INTEGER             {$$.type = $1.type; $$.ival = $1.ival;}
|     REAL                  {$$.type = $1.type; $$.rval = $1.rval;}
|     TRUE                  {$$.type = $1.type; $$.bval = 1;}
|     FALSE                 {$$.type = $1.type; $$.bval = 0;}
|     CHAR                  {$$.type = $1.type; $$.cval = $1.cval;}
|     STRING                {$$.type = $1.type; $$.sval = $1.sval;}
|    OPENPAR expr CLOSEPAR  {$$ = $2; }
|   ABS OPENPAR expr CLOSEPAR {$$.type = $3.type; if($3.type == INT_TYPE) {$$.ival = (int)abs($3.ival);} else if($3.type == REAL_TYPE) {$$.rval = abs($3.rval);} }
|   POW OPENPAR expr COMMA expr CLOSEPAR      { if($3.type == INT_TYPE && $5.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = pow($3.ival, $5.ival);} else if($3.type == REAL_TYPE && $5.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = pow($3.rval, (float)$5.ival);} else if($3.type == INT_TYPE && $5.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = pow((float)$3.ival, $5.rval);} else if($3.type == REAL_TYPE && $5.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = pow($3.rval, $5.rval);} else { yyerror("Must power numbers"); exit(1);} }
|   SQRT OPENPAR expr CLOSEPAR {$$.type = $3.type; if($3.type == INT_TYPE) {if($3.ival >= 0) {$$.ival = (int)sqrt($3.ival);}} else if($3.type == REAL_TYPE) {if($3.rval >= 0) {$$.rval = sqrt($3.rval);}} else{yyerror("Cannot make sqrt on negative number");exit(1);}}
|   EXP OPENPAR expr CLOSEPAR {$$.type = $3.type; if($3.type == INT_TYPE) {$$.ival = (int)exp($3.ival);} else if($3.type == REAL_TYPE) {$$.rval = exp($3.rval);} }
|   LOG OPENPAR expr CLOSEPAR {$$.type = $3.type; if($3.type == INT_TYPE) {if($3.ival >= 0) {$$.ival = (int)log10($3.ival);}} else if($3.type == REAL_TYPE) {if($3.rval >= 0) {$$.rval = log10($3.rval);}} else{yyerror("Cannot make log on negative number");exit(1);}}
|   LN OPENPAR expr CLOSEPAR  {$$.type = $3.type; if($3.type == INT_TYPE) {if($3.ival >= 0) {$$.ival = (int)log($3.ival);}} else if($3.type == REAL_TYPE) {if($3.rval >= 0) {$$.rval = log($3.rval);}} else{yyerror("Cannot make ln on negative number");exit(1);}}
|   FLOOR OPENPAR expr CLOSEPAR {$$.type = INT_TYPE; if($3.type == INT_TYPE) {$$.ival = $3.ival;} else if($3.type == REAL_TYPE) {$$.ival = (int)floor($3.rval);} else {yyerror("Must floor on number");} }
|   CEIL OPENPAR expr CLOSEPAR  {$$.type = INT_TYPE; if($3.type == INT_TYPE) {$$.ival = $3.ival;} else if($3.type == REAL_TYPE) {$$.ival = (int)ceil($3.rval);} else {yyerror("Must ceil on number");} }
|   COS OPENPAR expr CLOSEPAR  {$$.type = REAL_TYPE; if($3.type == REAL_TYPE) {$$.rval = cos($3.rval);} else {yyerror("Must make cos on real");}}
|   SIN OPENPAR expr CLOSEPAR  {$$.type = REAL_TYPE; if($3.type == REAL_TYPE) {$$.rval = sin($3.rval);} else {yyerror("Must make sin on real");}}
|   TAN OPENPAR expr CLOSEPAR  {$$.type = REAL_TYPE; if($3.type == REAL_TYPE) {$$.rval = tan($3.rval);} else {yyerror("Must make tan on real");}}
;


write: WRITE expr   {if($2.type == CHAR_TYPE) {printf("WRITE: %s\n", $2.cval);} else if($2.type == STRING_TYPE) {printf("WRITE: %s\n", $2.sval);} else if($2.type == REAL_TYPE) {printf("WRITE: %f\n", $2.rval);} else if($2.type == INT_TYPE) {printf("WRITE: %d\n", $2.ival);} else if($2.type == BOOL_TYPE) {printf("WRITE: %d\n", $2.bval);} }
;


type: INT_TYPE   {$$ = INT_TYPE;}
|   REAL_TYPE     {$$ = REAL_TYPE;}
|   CHAR_TYPE     {$$ = CHAR_TYPE;}
|   STRING_TYPE   {$$ = STRING_TYPE;}
|   BOOL_TYPE     {$$ = BOOL_TYPE;}
;

conditionalstmt: IF expr THEN groupstmts elifstmt elsestmt ENDIF    {if($2.type != BOOL_TYPE) {yyerror("You must have a boolean condition with if statement"); exit(1);}}
;

elifstmt: 
|   elifstmt ELIF expr THEN groupstmts  {if($3.type != BOOL_TYPE) { yyerror("You must have a boolean condition with elif statement"); exit(1);}}
;

elsestmt:
|   ELSE stmts
;

loopstmt: WHILE expr DO groupstmts ENDWHILE   {if($2.type != BOOL_TYPE) {yyerror("You must choose a boolean condition with loop statement"); exit(1);}}
;

fcts: 
|     fcts fct
;

fct: declfct headfct groupstmts returnfct    { }
;

declfct: FCT  ID { curr_fct = $2; }
;

headfct: OPENPAR paramfcts CLOSEPAR COLON type { install(curr_fct, $5, 0, 0, 0, "N", "null", curr_scope); printf("curr_fct %s", curr_fct); curr_scope++; }

paramfcts: 
|     parameters
;

parameters: ID       { context_check($1, curr_scope); put_param($1, get_type($1, curr_scope), curr_fct); }
|   ID COMMA parameters     { context_check($1, curr_scope); put_param($1, get_type($1, curr_scope), curr_fct);}
;

returnfct: RETURN ID   {check_type($2, get_type(curr_fct, curr_scope), curr_scope); if(get_type(curr_fct, curr_scope) == INT_TYPE) {set_int_value(curr_fct, get_int_value($2, curr_scope), curr_scope);} else if(get_type(curr_fct, curr_scope) == REAL_TYPE) {set_real_value(curr_fct, get_real_value($2, curr_scope), curr_scope);} else if(get_type(curr_fct, curr_scope) == BOOL_TYPE) {set_bool_value(curr_fct, get_bool_value($2, curr_scope), curr_scope);} else if(get_type(curr_fct, curr_scope) == CHAR_TYPE) {set_char_value(curr_fct, get_char_value($2, curr_scope), curr_scope);} else if(get_type(curr_fct, curr_scope) == STRING_TYPE) {set_string_value(curr_fct, get_string_value($2, curr_scope), curr_scope);} curr_scope--; }
;

instances: ID       { $$.type = get_type($1, curr_scope); printf("ID");}
|   INTEGER         {$$.type = INT_TYPE;}
|   REAL            {$$.type = REAL_TYPE;}
|   CHAR            {$$.type = CHAR_TYPE;}
|   STRING          {$$.type = STRING_TYPE;}
|   TRUE            {$$.type = BOOL_TYPE;}
|   FALSE           {$$.type = BOOL_TYPE;}
;


callfct: startcall endcall
;

startcall: ID ASSIGNMENT ID          { check_type($1, get_type($3, curr_scope), curr_scope); curr_call = $3; if(get_type($1, curr_scope) == INT_TYPE) {set_int_value($1, get_int_value($3, curr_scope), curr_scope);} else if(get_type($1, curr_scope) == REAL_TYPE) {set_real_value($1, get_real_value($3, curr_scope), curr_scope);} else if(get_type($1, curr_scope) == BOOL_TYPE) {set_bool_value($1, get_bool_value($3, curr_scope), curr_scope);} else if(get_type($1, curr_scope) == CHAR_TYPE) {set_char_value($1, get_char_value($3, curr_scope), curr_scope);} else if(get_type(curr_fct, curr_scope) == STRING_TYPE) {set_string_value($1, get_string_value($3, curr_scope), curr_scope);}  printf("curr_call = %s\n", curr_call); }
;

endcall: OPENPAR paramcallfct CLOSEPAR 
;

paramcallfct:     { if(get_param_nb(curr_call) != 0) { yyerror("Wrong number of parameters in the function call"); exit(1); } }
|     parametersinstances
;

parametersinstances: instances            {num_param++; param_check(num_param, curr_call); param_check_type(num_param, curr_call, $1.type);  }
|    instances COMMA parametersinstances {num_param++; param_check(num_param, curr_call); param_check_type(num_param, curr_call, $1.type); printf("PARAM NB = %d AND NUM_PARAM = %d\n", get_param_nb(curr_call), num_param); if(get_param_nb(curr_call) != num_param) { yyerror("Wrong number of parameters in the function call"); exit(1); }}
;


%%
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