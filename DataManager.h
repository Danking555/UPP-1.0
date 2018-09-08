#pragma once

#include "Math.h"

typedef struct d
{
	string key;
	void* value;
	int val_type;
	struct d* next;
	struct d* before;
}dict, *dictp, **dictpp;

typedef struct ld
{
	dictp start;
	dictp end;
	int size;
}dict_list, *dict_listp;



dict_listp allocateListDictionary();

void freeDictList(dict_listp list);

dictp getDictByKey(dict_list list, string key);


dictp assignToDict(string* keyValue);

dict_listp assignToDictList(dict_listp list, string* keyValue);

void changeStringToValues(dict_list list, string command, int type);
