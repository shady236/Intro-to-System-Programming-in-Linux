#ifndef  __STRUTIL__
#define  __STRUTIL__


#include <string.h>
#include "arrayList.h"


bool isStringEqual(char* searchStr, char* patternStr);
bool isStringStartWith(char* searchStr, char* patternStr);
char** splitString(char* str, char delim, int* retSize);
void trimString(char** str);




#endif