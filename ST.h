


struct symrec
{
    char *name; 
    int type;
    int int_val;
    double real_val;
    int bool_val;
    int scope;
    struct symrec *next;        
};
typedef struct symrec symrec;

symrec *identifier;

symrec *sym_table = (symrec *)0; 

symrec * putsym (char *sym_name, int type, int int_val, double real_val, int bool_val, int curr_scope) 
{
    symrec *ptr;
    ptr = (symrec *) malloc (sizeof(symrec));
    ptr->name = (char *) malloc (strlen(sym_name)+1);
    strcpy (ptr->name,sym_name);
    ptr->type = type;
    ptr->int_val = int_val;
    ptr->real_val = real_val;
    ptr->bool_val = bool_val;
    ptr->scope = curr_scope;
    printf("PUT AN ID\n He has %d type %f real and current scope of %d\n", ptr->type, ptr->real_val, ptr->scope);
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

void setrealval(char * sym_name, double real_val, int scope) {
    symrec *ptr;
    ptr = getsym(sym_name, scope);
    ptr->real_val = real_val;
    printf("PUT AREAL VAL TO AN ID \n He has %d type %f real\n", ptr->type, ptr->real_val);
}

double getrealval(char * sym_name, int scope) {
    symrec *ptr;
    ptr = getsym(sym_name, scope);
    printf("WE SEARCH A REAL VALUE");
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