#pragma once

#include "Utilities.h"

enum type { INT, FLOAT, STRING, LIST, ARG, UKNOWN};

bool isString(string line);

bool isInteger(string val);

bool isFloat(string val);

bool isList(string val);

int getType(string val);

float getFloatValue(void* val);

int getIntValue(void* val);

string getStringValue(string line);

