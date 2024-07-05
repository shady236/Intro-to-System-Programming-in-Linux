#ifndef __ARRAYLIST__
#define __ARRAYLIST__


#include <stdlib.h>
#include <stdbool.h>


typedef struct {
	void** data;
	int cap;
	int size;
} ArrayList;

typedef void (*TraverseCallBackFun)(int, void*);
typedef void (*FreeCallBackFun)(void*);
typedef int  (*CmpFun)(void*, void*);



bool newArrayList(ArrayList* list, int initCapacity);
bool addToArrayList(ArrayList* list, void* data);
void* getFromArrayList(ArrayList* list, void* data, CmpFun cmpFun);
bool traverseArrayList(ArrayList* list, TraverseCallBackFun fun);
void** ArrayListToArray(ArrayList* list, int* arrSize);
bool clearArrayList(ArrayList* list, FreeCallBackFun freeFun);



#endif
