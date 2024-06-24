#include <unistd.h>
#include <stdio.h>

#define MAX_PATH_LEN	(100)

int main(int argc, char** argv) {
	char path[MAX_PATH_LEN];
	
	char* ret = getcwd(path, MAX_PATH_LEN);
	if (ret != NULL) {
		printf("%s\n", path);
	}
	else {
		printf("Error while getting current working directory\n");
	}

	return 0;
}

