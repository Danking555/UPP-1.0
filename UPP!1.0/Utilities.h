#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#pragma warning(disable:4996)

#define MAX_GET 256
#define MAX_ALLOCATE 256

typedef enum { false = 0, true = !false }bool;
typedef char* string;

void notEnoughMem();

string allocateString(int size);

string* allocateStringArray(int size);


string getMin(string a, string b);

string getMinBetween4(string a, string b, string c, string d);

bool isAssign(string line);

bool isCondition(string line);

string trim(string line);
