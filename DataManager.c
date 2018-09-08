#include "DataManager.h"


dict_listp allocateListDictionary()
{
	dict_listp ret = (dict_listp)malloc(sizeof(dict_list));
	if (!ret) notEnoughMem();
	ret->start = NULL;
	return ret;
}

void freeDictList(dict_listp list)
{
	dictp runner = list->start, tmp = list->start;

	for (runner; runner != NULL; runner = tmp)
	{
		tmp = runner->next;
		free(runner->key);
		free(runner->value);
		free(runner);
	}
}

// Look in the list of variables for variable and return it.
dictp getDictByKey(dict_list list, string key)
{
	dictp runner = list.start;
	for (runner; runner != NULL; runner = runner->next)
		if (!strncmp(runner->key, key,strlen(key))) return runner;
	return NULL;
}

// Makes the given input an expression by changing variables names by their value i.e x+5 =-> 555+5
void changeStringToValues(dict_list list, string arguments, int type)
{
	int i = 0, j = 0, tmp_type = 0;
	dictp found = list.start;
	string pointer = arguments; // We don't want to change the main input
	char one_argument[MAX_GET] = { 0 }; // one variable of number (until operator)
	char add[MAX_GET] = { 0 }; // The value of a variable


	while (true)
	{
		strcpy(add, "");
		strcpy(one_argument, "");
		tmp_type = getArgument(one_argument, pointer);

		if (tmp_type == ARG)
		{
			dictp d = getDictByKey(list, one_argument);
			if (!d) {
				fprintf(stderr, "NameError: Name '%s' is not defined!\n", one_argument);
				return;
			}
			strcpy(add, (string)(d->value)); // Get variable value
			add[strlen(add)] = 0;
			type = type == ARG ? getType(d->value) : type;

			if (getType(d->value) != type) {
				fprintf(stderr, "TypeError: Operations of different types are not supported\n");
				return;
			}
			int times = (strlen(pointer) - strlen(one_argument));
			for (i = 0; i < times; i++) // Main Changes
				pointer[i + strlen(add)] = pointer[i + strlen(one_argument)];
			for (i = 0; i < strlen(add); i++)	pointer[i] = add[i];

			pointer += strlen(add);

		}
		else {
			if (tmp_type != type) {
				fprintf(stderr, "TypeError: Operations of different types are not supported\n");
				return;
			}
			pointer += strlen(one_argument);
		}

		if (!strcmp(pointer, "")) return;
		pointer++;
	}

}

dictp assignToDict(string* keyValue)
{

	char tmp[MAX_GET] = { 0 };
	dictp insert = (dictp)malloc(sizeof(dict));
	int type = UKNOWN;
	float res; int int_res;
	if (!insert) notEnoughMem();

	type = getArgument(tmp, keyValue[1]);

	insert->key = keyValue[0];
	insert->val_type = type;
	if (type == INT)  insert->value = (void*)(getStringValueOf_int_operations(keyValue[1]));
	else if (type == STRING) insert->value = (void*)(getStringValue(keyValue[1]));

	insert->next = NULL;
	return insert;
}


dict_listp assignToDictList(dict_listp list, string* keyValue)
{
	dictp insert = NULL, found = NULL;;
	if (!keyValue) return list;
	found = getDictByKey(*list, keyValue[0]);
	insert = assignToDict(keyValue);

	if (found)
	{
		found->value = (void*)keyValue[1];
	}
	else if (!list->start)
	{
		list->start = insert;
		list->start->next = NULL;
		list->start->before = NULL;
		list->end = list->start;
		list->size = 0;

	}
	else
	{
		list->end->next = insert;
		list->end->next->before = list->end;
		list->end = list->end->next;
		list->end->next = NULL;
		list->size++;
	}
	return list;

}


