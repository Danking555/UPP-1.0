#pragma once

#include "Utilities.h"




string* getKeyValue(string line, char seperator);

void freeKeyValue(string *keyValue);


string increaseArgument(string line, char sep);

string getArgumentBetween(string command, char sep1, char sep2);


bool isAssign(string command );

bool isPrint(string command);
