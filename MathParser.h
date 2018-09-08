#pragma once

#include "Types.h"


bool isAssign(string line);

bool isCondition(string line);


//string* getKeyValue(string line);

//void freeKeyValue(string *keyValue);



string getCurrentExpressionEnd(string arguments);

int getArgument(string assign, string arguments);


//string increaseArgument(string line, char sep);

//string getArgumentBetween(string command, char sep1, char sep2);