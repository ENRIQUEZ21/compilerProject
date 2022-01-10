struct Param {
	char *name;
	int type;
	char *reference;
	struct Param *next;
};
typedef struct Param Param;

Param *param;

Param *param_list  = (Param *)0;

Param * putParam(char *name, int type, char *reference) {
	Param *ptr;
    ptr = (Param *) malloc (sizeof(Param));
    ptr->name = (char *) malloc (strlen(name)+1);
    strcpy (ptr->name, name);
    ptr->type = type;
	ptr->reference = (char *) malloc (strlen(reference)+1);
    strcpy (ptr->reference, reference);
	ptr->next = (struct Param *)param_list;
    param_list = ptr;
	printf("PARAMETERS PUT WITH NAME = %s, TYPE = %d, REF = %s !!!!", name, type, reference);
    return ptr;
}

Param * getParamByNumber(int number, char *reference) {
    int cnt = 0;
    Param *ptr;
    printf("OKOKOK");
    for ( ptr = param_list; ptr != (Param *) 0; ptr = (Param *)ptr->next )
        printf("AAAAAA");
        if (strcmp (ptr->reference,reference) == 0)
            cnt++;
            printf("THE PARAMETER IS REFERENCED BY %s\n", reference);
            printf("cnt = %d and number  = %d", cnt, number);
            if(cnt == number)
                return ptr;
    return 0;
}