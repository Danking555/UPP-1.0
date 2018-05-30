#pragma once
#include "Utilities.h"

void notEnoughMem()
{
	perror("Not enough memory to allocate! exiting...");
	exit(1);
}

string allocateString(int size)
{
	string ret = NULL;
	if (size == EOF) ret = (string)calloc(MAX_ALLOCATE, sizeof(char));
	else ret = (string)calloc(size, sizeof(char));
	if (!ret) notEnoughMem();
	strcpy(ret, "");
	return ret;
}


string* allocateStringArray(int size)
{
	string* ret = NULL;
	if (size == EOF) ret = (string*)calloc(MAX_ALLOCATE, sizeof(string));
	else ret = (string*)calloc(size, sizeof(string));
	if (!ret) notEnoughMem();
	return ret;
}


string getMin(string a, string b)
{
	if (!a) return b;
	if (!b) return a;
	if (!a && !b) return NULL;
	return (a < b) ? a : b;
}

string getMinBetween4(string a, string b, string c, string d)
{
	return getMin(getMin(getMin(a, b), c), d);
}


bool isCondition(string line)
{
	string big = strchr(line, '>'), smaller = strchr(line, '<'), equal = strstr(line, "=="), not_equal = strstr(line, "!=");

}


 string trim(string str)
 {
	 string tmp = NULL;
	 string pointer = NULL;
	 bool in_string = false;
	 while (isspace(*str)) str++;
	 pointer = str;
	 tmp = str;

	 while (*pointer != 0)
	 {
		 if (!in_string)
			 while (*pointer == ' ') { pointer++; }
		 *tmp++ = *pointer;
		 if (*pointer == '"')
			 in_string = !in_string;
		 pointer++;
	 }
	 *tmp = 0;
	 return str;
 }