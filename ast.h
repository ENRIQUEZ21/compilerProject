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
	printf("STRCMP = %d\n", strcmp(ptr->name, "a"));
    return ptr;
}

Param * getParamByNumber(int number, char *ref) {
    int cnt = 0;
    Param *ptr;
    for ( ptr = param_list; ptr != (Param *) 0; ptr = (Param *)ptr->next )
        if (strcmp(ptr->reference, ref) == 0) {
            printf("EQUALITY FOUND\n");
            cnt++;
            printf("THE PARAMETER IS REFERENCED BY %s\n", ref);
            printf("cnt = %d and number  = %d\n", cnt, number);
            if(cnt == number)
                return ptr;
        } else {
            printf("OOPS!!! PROBLEM\n");
        }
    return 0;
}