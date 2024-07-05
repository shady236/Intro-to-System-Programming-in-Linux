#ifndef __VAR__
#define __VAR__

#include <string.h>
#include <stdio.h>

typedef struct {
	char* name;
	char* val;
} Var;



void printVar(Var* var, char* end);
int  compareVars(Var* var1, Var* var2);


#endif
