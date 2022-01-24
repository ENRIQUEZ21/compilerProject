%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
  #include <ctype.h>
  #include "CG.h"
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

  void hide_scope(int curr_scope) {
    hidescope(curr_scope);
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

%type <id> id;
%type <val> INTEGER REAL TRUE FALSE CHAR STRING;

%type <val> expr factor term;

%type <val> instances;


%token DECLARATIONS FUNCTIONS STATEMENTS

%token VAR COLON OPENPAR CLOSEPAR COMMA COMMENT SEMICOLON 
%token STARTPRGM ENDPRGM BEGSTMT ENDSTMT
%token IF THEN ELIF ELSE ENDIF WHILE DO ENDWHILE 
%token WRITE FCT RETURN
%token OR AND

%left ADDOP MINOP MULOP DIVOP MOD ASSIGNMENT LE GE LT GT EQ NE 
%right NOT FLOOR CEIL POW ABS EXP LOG LN COS SIN TAN SQRT


%%

program: STARTPRGM {generate_code("import java.lang.Math;\npublic class out{ \n"); } FUNCTIONS fcts STATEMENTS { generate_code("\npublic static void main(String args[]){\n");} stmts ENDPRGM {generate_code("}\n}");} 
;

groupstmts: BEGSTMT stmts ENDSTMT
;


stmts:                            
|   stmts comment stmt SEMICOLON {generate_code(";\n");}
;

stmt:  assignexpr  
|   declaration 
|   write    
|   conditionalstmt    {}
|   loopstmt       {}
|   callfct         { }
;

comma: COMMA        {generate_code(" , ");};

declaration: VAR ID COLON type    { generate_decl($2, $4); install($2, $4, 0, 0, 0, "N", "null", curr_scope);}

comment: 
|   COMMENT
;

assignment: ASSIGNMENT  {generate_code(" = ");};
assignexpr: id  assignment expr { context_check($1, curr_scope); if($3.type == INT_TYPE) {if(get_type($1, curr_scope) == INT_TYPE) { set_int_value($1, $3.ival, curr_scope); } else if(get_type($1, curr_scope) == REAL_TYPE) {set_real_value($1, $3.rval, curr_scope);} else {yyerror("Error assignment: bad type"); exit(1);}} else if($3.type == REAL_TYPE) {check_type($1, REAL_TYPE, curr_scope); set_real_value($1, $3.rval, curr_scope);} else if($3.type == BOOL_TYPE) {check_type($1, BOOL_TYPE, curr_scope); set_bool_value($1, $3.bval, curr_scope);} else if($3.type == CHAR_TYPE) {check_type($1, CHAR_TYPE, curr_scope); set_char_value($1, $3.cval, curr_scope);} else if($3.type == STRING_TYPE) {check_type($1, STRING_TYPE, curr_scope); set_string_value($1, $3.sval, curr_scope);} }
;

addop: ADDOP        {generate_code(" + "); } ;
minop: MINOP       {generate_code(" - ");};
ge: GE            {generate_code(" >= ");};
le: LE            {generate_code(" <= ");};
gt: GT            {generate_code(" > ");};
lt: LT            {generate_code(" < ");};
eq: EQ            {generate_code(" == ");};
ne: NE            {generate_code(" != ");};
and: AND            {generate_code(" && ");};
or: OR            {generate_code(" || ");};
not: NOT            {generate_code(" !");};
mulop: MULOP            {generate_code(" * ");};
divop: DIVOP          {generate_code(" / ");}
mod: MOD            {generate_code(" % ");}

expr: factor              {$$.type = $1.type;  if($1.type == INT_TYPE) {$$.ival = $1.ival;} else if($1.type == REAL_TYPE) {$$.rval = $1.rval;} else if($1.type == BOOL_TYPE) {$$.bval = $1.bval;} else if($1.type == CHAR_TYPE) {$$.cval = $1.cval;} else if($1.type == STRING_TYPE) {$$.sval = $1.sval;}}
|   expr addop factor     { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = $1.ival+$3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval+(float)$3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float)$1.ival+$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval+$3.rval; } else { yyerror("Must add numbers"); exit(1);} }
|   expr minop factor      { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = $1.ival-$3.ival;} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval-(float)$3.ival;} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float)$1.ival-$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval-$3.rval; } else { yyerror("Must substract numbers"); exit(1);} }
|   minop factor                { $$.type = $2.type; if($2.type == INT_TYPE) {$$.ival = -$2.ival; } else if($2.type == REAL_TYPE) {$$.rval = -$2.rval; } else {yyerror("- must be on number only"); exit(1);} }
|   expr ge factor      { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival >= $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval >= $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival >= $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval >= $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr le factor      { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival <= $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval <= $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival <= $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval <= $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr gt factor     { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival > $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval > $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival > $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval > $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr lt factor     { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival < $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval < $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival < $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval < $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr eq factor     { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival == $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval == $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival == $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval == $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr ne factor   { $$.type = BOOL_TYPE; if($1.type == INT_TYPE && $3.type == INT_TYPE) { $$.bval = $1.ival != $3.ival; } else if($1.type == REAL_TYPE && $3.type == INT_TYPE) { $$.bval = $1.rval != $3.ival; } else if($1.type == INT_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.ival != $3.rval; } else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) { $$.bval = $1.rval != $3.rval; } else {yyerror("Must make boolean op on numbers"); exit(1);}}  
|   expr and factor   { $$.type = BOOL_TYPE; if($1.type == BOOL_TYPE && $3.type == BOOL_TYPE) {$$.bval = $1.bval && $3.bval;} else {yyerror("Must make AND operation on boolean");}}
|   expr or factor    { $$.type = BOOL_TYPE; if($1.type == BOOL_TYPE && $3.type == BOOL_TYPE) {$$.bval = $1.bval || $3.bval;} else {yyerror("Must make OR operation on boolean");}}
|   not factor            { $$.type = BOOL_TYPE; if($2.type == BOOL_TYPE) {$$.bval = (!$2.bval); } else {yyerror("Must make NOT operation on boolean");}}
;

factor: term              {$$.type = $1.type;  if($1.type == INT_TYPE) {$$.ival = $1.ival; } else if($1.type == REAL_TYPE) {$$.rval = $1.rval;} else if($1.type == BOOL_TYPE) {$$.bval = $1.bval;} else if($1.type == CHAR_TYPE) {$$.cval = $1.cval;} else if($1.type == STRING_TYPE) {$$.sval = $1.sval;} }
|   factor mulop term    { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = $1.ival*$3.ival;} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval*(float)$3.ival;} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float)$1.ival*$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval*$3.rval;} else { yyerror("Must multiply numbers"); exit(1);} }
|   factor divop term    {  if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = $1.ival/$3.ival;} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = $1.rval/(float)$3.ival;} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float)$1.ival/$3.rval;} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = (float) $1.rval/$3.rval;} else { yyerror("Must divide numbers"); exit(1);} }
|   factor mod term      { if($1.type == INT_TYPE && $3.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = (int)fmod($1.ival, $3.ival);} else if($1.type == REAL_TYPE && $3.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = fmod($1.rval, (float)$3.ival);} else if($1.type == INT_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = fmod((float)$1.ival, $3.rval);} else if($1.type == REAL_TYPE && $3.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = fmod($1.rval, $3.rval);} else { yyerror("Must divide numbers"); exit(1);}}
;

id: ID            { generate_code($1);};

openpar: OPENPAR    {generate_code("(");};
closepar: CLOSEPAR    {generate_code(")");};
abs: ABS              {generate_code("Math.abs");};
pow: POW              {generate_code("Math.pow");};
sqrt:  SQRT            {generate_code("Math.sqrt");};
exp: EXP              {generate_code("Math.exp");};
log: LOG              {generate_code("Math.log10");};
ln: LN                {generate_code("Math.log");};
floor: FLOOR          {generate_code("Math.floor");};
ceil: CEIL            {generate_code("Math.ceil");};
cos:  COS             {generate_code("Math.cos");};
sin: SIN              {generate_code("Math.sin");};
tan: TAN              {generate_code("Math.tan");};

term: id          { context_check($1, curr_scope); $$.type = get_type($1, curr_scope); if(get_type($1, curr_scope) == INT_TYPE) { $$.ival = get_int_value($1, curr_scope);} else if(get_type($1, curr_scope) == REAL_TYPE) {$$.rval = get_real_value($1, curr_scope);} else if(get_type($1, curr_scope) == BOOL_TYPE) {$$.bval = get_bool_value($1, curr_scope);} else if(get_type($1, curr_scope) == CHAR_TYPE) {$$.cval = get_char_value($1, curr_scope);} else if(get_type($1, curr_scope) == STRING_TYPE) {$$.sval = get_string_value($1, curr_scope);}}
|      INTEGER             {generate_int($1.ival); $$.type = $1.type; $$.ival = $1.ival;}
|     REAL                  {generate_real($1.rval); $$.type = $1.type; $$.rval = $1.rval;}
|     TRUE                  {generate_code(" true "); $$.type = $1.type; $$.bval = 1;}
|     FALSE                 {generate_code(" false "); $$.type = $1.type; $$.bval = 0;}
|     CHAR                  {generate_code($1.cval); $$.type = $1.type; $$.cval = $1.cval;}
|     STRING                {generate_code($1.sval); $$.type = $1.type; $$.sval = $1.sval;}
|    openpar expr closepar  {$$ = $2; }
|   abs openpar expr closepar {$$.type = $3.type; if($3.type == INT_TYPE) {$$.ival = (int)abs($3.ival);} else if($3.type == REAL_TYPE) {$$.rval = abs($3.rval);} }
|   pow openpar expr comma expr closepar      { if($3.type == INT_TYPE && $5.type == INT_TYPE) {$$.type = INT_TYPE; $$.ival = pow($3.ival, $5.ival);} else if($3.type == REAL_TYPE && $5.type == INT_TYPE) {$$.type = REAL_TYPE; $$.rval = pow($3.rval, (float)$5.ival);} else if($3.type == INT_TYPE && $5.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = pow((float)$3.ival, $5.rval);} else if($3.type == REAL_TYPE && $5.type == REAL_TYPE) {$$.type = REAL_TYPE; $$.rval = pow($3.rval, $5.rval);} else { yyerror("Must power numbers"); exit(1);} }
|   sqrt openpar expr closepar {$$.type = $3.type; if($3.type == INT_TYPE) {if($3.ival >= 0) {$$.ival = (int)sqrt($3.ival);}} else if($3.type == REAL_TYPE) {if($3.rval >= 0) {$$.rval = sqrt($3.rval);}} else{yyerror("Cannot make sqrt on negative number");exit(1);}}
|   exp openpar expr closepar {$$.type = $3.type; if($3.type == INT_TYPE) {$$.ival = (int)exp($3.ival);} else if($3.type == REAL_TYPE) {$$.rval = exp($3.rval);} }
|   log openpar expr closepar {$$.type = $3.type; if($3.type == INT_TYPE) {if($3.ival >= 0) {$$.ival = (int)log10($3.ival);}} else if($3.type == REAL_TYPE) {if($3.rval >= 0) {$$.rval = log10($3.rval);}} else{yyerror("Cannot make log on negative number");exit(1);}}
|   ln openpar expr closepar  {$$.type = $3.type; if($3.type == INT_TYPE) {if($3.ival >= 0) {$$.ival = (int)log($3.ival);}} else if($3.type == REAL_TYPE) {if($3.rval >= 0) {$$.rval = log($3.rval);}} else{yyerror("Cannot make ln on negative number");exit(1);}}
|   floor openpar expr closepar {$$.type = INT_TYPE; if($3.type == INT_TYPE) {$$.ival = $3.ival;} else if($3.type == REAL_TYPE) {$$.ival = (int)floor($3.rval);} else {yyerror("Must floor on number");} }
|   ceil openpar expr closepar  {$$.type = INT_TYPE; if($3.type == INT_TYPE) {$$.ival = $3.ival;} else if($3.type == REAL_TYPE) {$$.ival = (int)ceil($3.rval);} else {yyerror("Must ceil on number");} }
|   cos openpar expr closepar  {$$.type = REAL_TYPE; if($3.type == REAL_TYPE) {$$.rval = cos($3.rval);} else {yyerror("Must make cos on real");}}
|   sin openpar expr closepar  {$$.type = REAL_TYPE; if($3.type == REAL_TYPE) {$$.rval = sin($3.rval);} else {yyerror("Must make sin on real");}}
|   tan openpar expr closepar  {$$.type = REAL_TYPE; if($3.type == REAL_TYPE) {$$.rval = tan($3.rval);} else {yyerror("Must make tan on real");}}
;

write_symb: WRITE {generate_code("System.out.println(");}

write: write_symb expr   { generate_code(")"); if($2.type == CHAR_TYPE) {printf("WRITE: %s\n", $2.cval);} else if($2.type == STRING_TYPE) {printf("WRITE: %s\n", $2.sval);} else if($2.type == REAL_TYPE) {printf("WRITE: %f\n", $2.rval);} else if($2.type == INT_TYPE) {printf("WRITE: %d\n", $2.ival);} else if($2.type == BOOL_TYPE) {printf("WRITE: %d\n", $2.bval);} }
;


type: INT_TYPE   {$$ = INT_TYPE;}
|   REAL_TYPE     {$$ = REAL_TYPE;}
|   CHAR_TYPE     {$$ = CHAR_TYPE;}
|   STRING_TYPE   {$$ = STRING_TYPE;}
|   BOOL_TYPE     {$$ = BOOL_TYPE;}
;

if: IF        {generate_code("\nif( "); curr_scope++;};
then: THEN      {generate_code(" {\n");};
elif: ELIF      {generate_code(" } else if(");};
else: ELSE      {generate_code("} else {\n")}
endif: ENDIF    {generate_code("}"); hidescope(curr_scope); curr_scope--;};

conditionalstmt: if expr {generate_code(")"); if($2.type != BOOL_TYPE) {yyerror("You must have a boolean condition with if statement"); exit(1);}} then groupstmts elifstmt elsestmt endif    
;

elifstmt: 
|   elifstmt elif expr {generate_code(")"); if($3.type != BOOL_TYPE) { yyerror("You must have a boolean condition with elif statement"); exit(1);}} then groupstmts  
;

elsestmt:
|   else groupstmts
;

while: WHILE        {generate_code("while ("); curr_scope++;};
do: DO              {generate_code(" {\n");};
endwhile: ENDWHILE  {generate_code(" }"); hidescope(curr_scope); curr_scope--;};

loopstmt: while expr {generate_code(")"); if($2.type != BOOL_TYPE) {yyerror("You must choose a boolean condition with loop statement"); exit(1);} } do groupstmts endwhile  
;

fcts: 
|     fcts fct
;

fct: declfct headfct groupstmts returnfct    { }
;

declfct: FCT  ID { curr_fct = $2; }
;

headfct: COLON type { generate_fct(curr_fct, $2); install(curr_fct, $2, 0, 0, 0, "N", "null", curr_scope); } openpar {curr_scope++; } paramfcts closepar { generate_code(" {\n");} 

paramfcts: 
|     parameters
;

param: VAR ID COLON type    {generate_decl($2, $4); install($2, $4, 0, 0, 0, "N", "null", curr_scope); put_param($2, $4, curr_fct); }
;
parameters: param     { }
|   param comma parameters     { }
;

return: RETURN        {generate_code("return ");};
returnfct: return id   {generate_code(";\n}"); check_type($2, get_type(curr_fct, curr_scope), curr_scope); if(get_type(curr_fct, curr_scope) == INT_TYPE) {set_int_value(curr_fct, get_int_value($2, curr_scope), curr_scope);} else if(get_type(curr_fct, curr_scope) == REAL_TYPE) {set_real_value(curr_fct, get_real_value($2, curr_scope), curr_scope);} else if(get_type(curr_fct, curr_scope) == BOOL_TYPE) {set_bool_value(curr_fct, get_bool_value($2, curr_scope), curr_scope);} else if(get_type(curr_fct, curr_scope) == CHAR_TYPE) {set_char_value(curr_fct, get_char_value($2, curr_scope), curr_scope);} else if(get_type(curr_fct, curr_scope) == STRING_TYPE) {set_string_value(curr_fct, get_string_value($2, curr_scope), curr_scope);} hidescope(curr_scope); printf("curr scope = %d", curr_scope); curr_scope--;  }
;

instances: id       { generate_code($1); $$.type = get_type($1, curr_scope); }
|   INTEGER         {generate_int($1.ival); $$.type = INT_TYPE;}
|   REAL            {generate_real($1.rval); $$.type = REAL_TYPE;}
|   CHAR            {generate_code($1.cval); $$.type = CHAR_TYPE;}
|   STRING          {generate_code($1.sval); $$.type = STRING_TYPE;}
|   TRUE            {generate_code(" true "); $$.type = BOOL_TYPE;}
|   FALSE           {generate_code(" false "); $$.type = BOOL_TYPE;}
;


callfct: startcall endcall
;

startcall: id assignment id          { check_type($1, get_type($3, curr_scope), curr_scope); curr_call = $3; if(get_type($1, curr_scope) == INT_TYPE) {set_int_value($1, get_int_value($3, curr_scope), curr_scope);} else if(get_type($1, curr_scope) == REAL_TYPE) {set_real_value($1, get_real_value($3, curr_scope), curr_scope);} else if(get_type($1, curr_scope) == BOOL_TYPE) {set_bool_value($1, get_bool_value($3, curr_scope), curr_scope);} else if(get_type($1, curr_scope) == CHAR_TYPE) {set_char_value($1, get_char_value($3, curr_scope), curr_scope);} else if(get_type(curr_fct, curr_scope) == STRING_TYPE) {set_string_value($1, get_string_value($3, curr_scope), curr_scope);} }
;

endcall: openpar paramcallfct closepar 
;

paramcallfct:     { if(get_param_nb(curr_call) != 0) { yyerror("Wrong number of parameters in the function call"); exit(1); } }
|     parametersinstances         { num_param = 0;}
;

parametersinstances: instances            {num_param++; printf("param number = %d\n", num_param); param_check(num_param, curr_call); param_check_type(num_param, curr_call, $1.type);  }
|    instances comma parametersinstances {num_param++; param_check(num_param, curr_call); printf("param number = %d\n", num_param); param_check_type(num_param, curr_call, $1.type); if(get_param_nb(curr_call) != num_param) { yyerror("Wrong number of parameters in the function call"); exit(1); }}
;


%%
void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
int main( int argc, char *argv[] ){ 
  init_hash_table();
  extern FILE *yyin;
  ++argv; argc = argc-1;
  yyin = fopen( argv[0], "r" );
  int errors = 0;
  yyparse ();
}