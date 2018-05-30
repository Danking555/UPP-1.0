#pragma once

#include "DataManager.h"
#include "CommandsParser.h"

/* Print variable */
void printExistingValue(dictp key_dict);

/* Print variable or expression */
void printValue(dict_listp list, string key);
