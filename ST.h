

struct symrec
{
    char *name; 
    int type;
    int int_val;
    double real_val;
    int bool_val;
    char *char_val;
    char *string_val;
    int scope;
    struct symrec *next;        
};
typedef struct symrec symrec;

symrec *identifier;

symrec *sym_table = (symrec *)0; 


symrec * putsym (char *sym_name, int type, int int_val, double real_val, int bool_val, char *char_val, char *string_val, int curr_scope) 
{
    symrec *ptr;
    ptr = (symrec *) malloc (sizeof(symrec));
    ptr->name = (char *) malloc (strlen(sym_name)+1);
    strcpy (ptr->name,sym_name);
    ptr->type = type;
    ptr->int_val = int_val;
    ptr->real_val = real_val;
    ptr->bool_val = bool_val;
    ptr->char_val = (char *) char_val;
    ptr->string_val = (char *) string_val;
    ptr->scope = curr_scope;
    /*ptr->offset = data_location();*/
    ptr->next = (struct symrec *)sym_table;
    sym_table = ptr;
    return ptr;
}
symrec * getsym (char *sym_name, int curr_scope)
{
    symrec *ptr;
    for ( ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next )
        if (strcmp (ptr->name,sym_name) == 0 && ptr->scope <= curr_scope)
            return ptr;
    return 0;
}

/*void hidescope(int curr_scope) {
    symrec *ptr;
    for ( ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next ) {
        while(ptr->scope == curr_scope) {
            ptr = ptr->next;
            printf("Hidden %s \n", ptr->name);
        } 
        sym_table = ptr;
    }
    printf("HIDDEN SCOPE\n");
}*/

void setrealval(char * sym_name, double real_val, int scope) {
    symrec *ptr;
    ptr = getsym(sym_name, scope);
    ptr->real_val = real_val;
}

double getrealval(char * sym_name, int scope) {
    symrec *ptr;
    ptr = getsym(sym_name, scope);
    return ptr->real_val;

}

void setboolval(char * sym_name, int bool_val, int scope) {
    symrec *ptr;
    ptr = getsym(sym_name, scope);
    ptr->bool_val = bool_val;
}

int getboolval(char * sym_name, int scope) {
    symrec *ptr;
    ptr = getsym(sym_name, scope);
    return ptr->bool_val;

}

void setintval(char * sym_name, int int_val, int scope) {
    symrec *ptr;
    ptr = getsym(sym_name, scope);
    ptr->int_val = int_val;
}

int getintval(char * sym_name, int scope) {
    symrec *ptr;
    ptr = getsym(sym_name, scope);
    return ptr->int_val;
}

void setcharval(char * sym_name, char *char_val, int scope) {
    symrec *ptr;
    ptr = getsym(sym_name, scope);
    ptr->char_val = char_val;
}

char * getcharval(char * sym_name, int scope) {
    symrec *ptr;
    ptr = getsym(sym_name, scope);
    return ptr->char_val;
}


void setstringval(char * sym_name, char *string_val, int scope) {
    symrec *ptr;
    ptr = getsym(sym_name, scope);
    ptr->string_val = string_val;
}

char * getstringval(char * sym_name, int scope) {
    symrec *ptr;
    ptr = getsym(sym_name, scope);
    return ptr->string_val;
}

struct Param {
	char *name;
	int type;
	char *reference;
	struct Param *next;
};
typedef struct Param Param;

Param *param;

Param *param_list  = (Param *)0;


Param * putParam(char *name_param, int type, char *ref) {
	Param *ptr;
    ptr = (Param *) malloc (sizeof(Param));
    ptr->name = (char *) malloc (strlen(name_param)+1);
    strcpy (ptr->name, name_param);
    ptr->type = type;
	ptr->reference = (char *) malloc (strlen(ref)+1);
    strcpy (ptr->reference, ref);
	ptr->next = (struct Param *)param_list;
    param_list = ptr;
    return ptr;
}

Param * getParamByNumber(int number, char *ref) {
    int cnt = 0;
    Param *ptr;
    for ( ptr = param_list; ptr != (Param *) 0; ptr = (Param *)ptr->next )
        if (strcmp(ptr->reference, ref) == 0) {
            cnt++;
            if(cnt == number)
                return ptr;
        } 
    return 0;
}



int getParamNb(char *ref) {
    int cnt = 0;
    Param *ptr;
    for ( ptr = param_list; ptr != (Param *) 0; ptr = (Param *)ptr->next ) {
        if (strcmp(ptr->reference, ref) == 0) {
             cnt++;
        }
    }
    return cnt;
}