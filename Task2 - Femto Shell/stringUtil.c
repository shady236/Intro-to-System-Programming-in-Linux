#include "stringUtil.h"


bool isStringEqual(char* searchStr, char* patternStr) {
	return (strcmp(searchStr, patternStr) == 0);
}


bool isStringStartWith(char* searchStr, char* patternStr) {
	return (strncmp(searchStr, patternStr, strlen(patternStr)) == 0);
}


char** splitString(char* str, char delim, int* retSize) {
	ArrayList segments;
	newArrayList(&segments, 1);
	
	int prevDelimIdx = -1;
	
	for (int i = 0; ; i++) {
		if (str[i] != delim && str[i] != '\0') {
			continue;
		}

		if (prevDelimIdx + 1 < i) {
			int segLen = i - prevDelimIdx - 1;
			char* seg = malloc(segLen + 1);
			strncpy(seg, str + prevDelimIdx + 1, segLen);
			seg[segLen] = 0;
			addToArrayList(&segments, seg);
		}

		prevDelimIdx = i;

		if (str[i] == '\0') {
			break;
		}
	}
	addToArrayList(&segments, NULL);

	char** ret = (char**) ArrayListToArray(&segments, retSize);
	clearArrayList(&segments, NULL);
	return ret;
}


void trimString(char** str) {
	while ((*str)[0] == ' ') {
		(*str)++;
	}

	int l = strlen(*str);
	while (l > 0 && (*str)[l - 1] == ' ') {
		l--;
	}
	(*str)[l] = 0;
}

