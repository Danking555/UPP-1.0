#pragma once
#include "Types.h"



bool isString(string line)
{
	int i = 0;
	if (line[0] != '\"' || line[strlen(line) - 1] != '\"') return false;

	for (int i = 1; i < strlen(line) - 1; i++) if (!isalpha(line[i])) return false;

	return true;
}

bool isInteger(string val)
{
	return (strtol(val, NULL, 10) != 0 || !strcmp(val, "0")) && !strchr(val, '.');
}

bool isFloat(string val)
{
	return (strtof(val, NULL) != 0.0) || !strcmp(val, "0.0");
}

bool isList(string val)
{
	return val[0] == '[' && val[strlen(val) - 1] == ']';
}

int getType(string val)
{
	if (!val) return UKNOWN;
	if (isString(val)) return STRING;
	if (isInteger(val)) return INT;
	if (isFloat(val)) return FLOAT;
	if (isList(val)) return LIST;
	return ARG;
}

float getFloatValue(void* val)
{
	return strtof((string)val, NULL);
}

int getIntValue(void* val)
{
	return strtol((string)val, NULL, 10);
}

string getStringValue(string line)
{
	int i = 0;
	if (line[0] != '\"' && line[strlen(line) - 1] != '\"') return line;
	line[strlen(line) - 1] = 0;
	for (i = 0; i < strlen(line); i++) line[i] = line[i + 1];
	return line;
}


