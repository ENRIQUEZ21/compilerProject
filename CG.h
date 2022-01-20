#include "variables.h"
#include "yacc2.tab.h"


void generate_code(char *symbol) {
    FILE *fp;
    fp = fopen("out.java", "a");
    fprintf(fp, "%s", symbol);
}



void generate_decl(char *id, int type) {
     FILE *fp;
	fp = fopen("out.java", "a");
    if(type == INT_TYPE) {
        fprintf(fp, "%s %s", "Integer", id);
    } else if(type == REAL_TYPE) {
        fprintf(fp, "%s %s", "double", id);
    } else if(type == CHAR_TYPE) {
        fprintf(fp, "%s %s", "char", id);
    } else if(type == STRING_TYPE) {
        fprintf(fp, "%s %s", "String", id);
    } else {
        fprintf(fp, "%s %s", "boolean", id);
    }    
}

void generate_fct(char *curr_fct, int type) {
    FILE *fp;
	fp = fopen("out.java", "a");
    if(type == INT_TYPE) {
        fprintf(fp, "\npublic static %s %s", "Integer", curr_fct);
    } else if(type == REAL_TYPE) {
        fprintf(fp, "\npublic static %s %s", "double", curr_fct);
    } else if(type == CHAR_TYPE) {
        fprintf(fp, "\npublic static %s %s", "char", curr_fct);
    } else if(type == STRING_TYPE) {
        fprintf(fp, "\npublic static %s %s", "String", curr_fct);
    } else {
        fprintf(fp, "\npublic static %s %s", "boolean", curr_fct);
    }   
}


void generate_int( int myint) {
    FILE *fp;
	fp = fopen("out.java", "a");
    fprintf(fp," %d ", myint);
}

void generate_real( double myfloat) {
    FILE *fp;
	fp = fopen("out.java", "a");
    fprintf(fp," %f ", myfloat);
}


