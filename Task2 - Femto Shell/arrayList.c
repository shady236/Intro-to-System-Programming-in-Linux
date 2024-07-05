#include "arrayList.h"


bool newArrayList(ArrayList* list, int initCapacity) {
	if (initCapacity <= 0) {
		list->data = NULL;
		return false;
	}
	
	list->size = 0;
	list->cap = initCapacity;
	list->data = malloc(list->cap * sizeof(void*));
	
	if (list->data == NULL) {
		return false;
	}
	return true;
}


bool addToArrayList(ArrayList* list, void* data) {
	if (list == NULL || list->data == NULL) {
		return false;
	}

	if (list->size >= list->cap) {
		list->cap *= 2;
		void** newData = realloc(list->data, list->cap * sizeof(void*));
		
		if (newData == NULL) {
			return false;
		}

		list->data = newData;
	}
	
	list->data[list->size] = data;
	list->size++;
	return true;
}


bool traverseArrayList(ArrayList* list, TraverseCallBackFun fun) {
	if (list == NULL || list->data == NULL) {
		return false;
	}
	
	if (fun != NULL) {
		for (int i = 0; i < list->size; i++) {
			fun(i, list->data[i]);
		}
	}
	
	return true;
}


void* getFromArrayList(ArrayList* list, void* data, CmpFun cmpFun) {
	if (list == NULL || list->data == NULL || cmpFun == NULL) {
		return NULL;
	}
	
	for (int i = 0; i < list->size; i++) {
		if (cmpFun(list->data[i], data) == 0) {
			return list->data[i];
		}
	}

	return NULL;	
}


void** ArrayListToArray(ArrayList* list, int* arrSize) {
	void** arr = malloc(list->size * sizeof(void*));
	
	for (int i = 0; i < list->size; i++) {
		arr[i] = list->data[i];
	}

	*arrSize = list->size;
	return arr;
}


bool clearArrayList(ArrayList* list, FreeCallBackFun freeFun) {
	if (list == NULL || list->data == NULL) {
		return false;
	}
	
	if (freeFun != NULL) {
		for (int i = 0; i < list->size; i++) {
			freeFun(list->data[i]);
		}
	}
	
	free(list->data);
	list->data = NULL;
	list->size = 0;
	list->cap = 0;

	return true;
}

