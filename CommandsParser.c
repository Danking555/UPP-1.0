#include "CommandsParser.h"


string* getKeyValue(string line, char seperator)
{
	string key = line;
	string *ret = allocateStringArray(2);
	string value = increaseArgument(key, seperator);
	if (!value) {
		free(ret[0]);
		free(ret[1]);
		free(ret);
		return NULL;
	}
	ret[0] = allocateString(strlen(key) + 1); /* plus one for the null terminator */
	ret[1] = allocateString(strlen(value) + 1);

	strcpy(ret[0], key);
	strcpy(ret[1], value);
	return ret;
}

void freeKeyValue(string *keyValue)
{
	free(keyValue[0]);
	free(keyValue[1]);
	free(keyValue);
}



string increaseArgument(string line, char sep)
{
	string index = strchr(line, sep);
	if (index) {
		*index = 0;
		index++;
	}
	return index;
}

string getArgumentBetween(string command, char sep1, char sep2)
{
	string value = increaseArgument(command, sep1);
	if (!value) return NULL;
	string null = increaseArgument(value, sep2);
	return value;
}


bool isPrint(string command)
{
	string print = "print";
	return !strncmp(command, print, strlen(print));
}


bool isAssign(string command)
{
	return strchr(command, '=') != NULL;
}