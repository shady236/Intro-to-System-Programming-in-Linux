#include <stdio.h>
#include "arrayList.h"
#include "stringUtil.h"
#include "var.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


extern char **environ;


void printLocalVar(int idx, void* var) {
	printf("localVar[%d]: ", idx);
	printVar((Var*) var, "\n");
}


int cmpLocalVars(void* var1, void* var2) {
	return compareVars((Var*) var1, (Var*) var2);
}


int main(int argc, char** argv) {
	char cmd[1024];
	int cmdArgc;
	char** cmdArgv;
	ArrayList localVars;
	
	if (newArrayList(&localVars, 1) == false) {
		fprintf(stderr, "failed to initialize localVars array list\n");
		return -1;
	}
	
	while (true) {
		printf("Your command: ");
		fgets(cmd, 1024, stdin);
		cmd[strlen(cmd) - 1] = 0;		// remove '\n' character at the end of cmd
		
		if (isStringStartWith(cmd, "set")) {
			traverseArrayList(&localVars, printLocalVar);
		}
		else if (isStringStartWith(cmd, "env")) {
			for (int i = 0; environ[i]; i++) {
				printf("%s\n", environ[i]);
			}
		}
		else if (isStringStartWith(cmd, "export")) {
			cmdArgv = splitString(cmd, ' ', &cmdArgc);
			cmdArgc--;
			
			for (int i = 1; i < cmdArgc; i++) {
				char* varName = cmdArgv[i];
				Var tempVar = {
					.name = varName,
				};

				Var* var = getFromArrayList(&localVars, &tempVar, cmpLocalVars);
				char* varAsStr = malloc(strlen(var->name) + strlen(var->val) + 2);
				sprintf(varAsStr, "%s=%s", var->name, var->val);
				putenv(varAsStr);
			}
		}
		else {
			cmdArgv = splitString(cmd, '=', &cmdArgc);
			cmdArgc--;

			if (cmdArgc == 2) {
				Var* var = malloc(sizeof(Var));
				trimString(&cmdArgv[0]);
				trimString(&cmdArgv[1]);
				var->name = cmdArgv[0];
				var->val = cmdArgv[1];

				if (var->name[0] == '\0' || var->val[0] == '\0') {
					fprintf(stderr, "Invalid assignment command");
					free(var);
				}
				else {
					Var* v = getFromArrayList(&localVars, var, cmpLocalVars);
					if (v == NULL) {
						addToArrayList(&localVars, var);
					}
					else {
						v->val = var->val;
						free(var);
					}
				}
			}
			else if (cmdArgc > 2) {
				fprintf(stderr, "Invalid assignment command");
			}
			else {
				cmdArgv = splitString(cmd, ' ', &cmdArgc);
				cmdArgc--;
				pid_t id = fork();

				if (id == -1) {
					fprintf(stderr, "Failed to fork");
					continue;
				}
				else if (id == 0) {
					execvp(cmdArgv[0], cmdArgv);
				}
				else {
					int status;
					waitpid(id, &status, 0);
				}
			}
		}
	}
	
	
	return 0;
}
