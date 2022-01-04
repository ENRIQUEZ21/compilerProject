


struct symrec
{
    char *name; 
    int type;
    int int_val;
    double real_val;
    int bool_val;
    struct symrec *next;        
};
typedef struct symrec symrec;

symrec *identifier;

symrec *sym_table = (symrec *)0; 

symrec * putsym (char *sym_name, int type, int int_val, double real_val, int bool_val) 
{
    symrec *ptr;
    ptr = (symrec *) malloc (sizeof(symrec));
    ptr->name = (char *) malloc (strlen(sym_name)+1);
    strcpy (ptr->name,sym_name);
    ptr->type = type;
    ptr->int_val = int_val;
    ptr->real_val = real_val;
    ptr->bool_val = bool_val;
    /*ptr->offset = data_location();*/
    ptr->next = (struct symrec *)sym_table;
    sym_table = ptr;
    return ptr;
}
symrec * getsym (char *sym_name)
{
    symrec *ptr;
    for ( ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next )
        if (strcmp (ptr->name,sym_name) == 0)
            return ptr;
    return 0;
}

void setrealval(char * sym_name, double real_val) {
    symrec *ptr;
    ptr = getsym(sym_name);
    ptr->real_val = real_val;
    ptr->next = (struct symrec *)sym_table;
    sym_table = ptr;
}

double getrealval(char * sym_name) {
    symrec *ptr;
    ptr = getsym(sym_name);
    return ptr->real_val;

}

void setboolval(char * sym_name, int bool_val) {
    symrec *ptr;
    ptr = getsym(sym_name);
    ptr->bool_val = bool_val;
    ptr->next = (struct symrec *)sym_table;
    sym_table = ptr;
}

int getboolval(char * sym_name) {
    symrec *ptr;
    ptr = getsym(sym_name);
    return ptr->bool_val;

}

void setintval(char * sym_name, int int_val) {
    symrec *ptr;
    ptr = getsym(sym_name);
    ptr->int_val = int_val;
    ptr->next = (struct symrec *)sym_table;
    sym_table = ptr;
}

int getintval(char * sym_name) {
    symrec *ptr;
    ptr = getsym(sym_name);
    return ptr->int_val;
}