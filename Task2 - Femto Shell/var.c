#include "var.h"


void printVar(Var* var, char* end) {
	printf("%s=%s%s", var->name, var->val, end);
}

int compareVars(Var* var1, Var* var2) {
	return strcmp(var1->name, var2->name);
}
