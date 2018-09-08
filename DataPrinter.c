#include "DataPrinter.h"


void printExistingValue(dictp key_dict)
{
	if (key_dict->val_type == INT) printf("%d\n", getIntValue(key_dict->value));
	if (key_dict->val_type == FLOAT) printf("%f\n", getFloatValue(key_dict->value));
	if (key_dict->val_type == STRING) printf("%s\n", getStringValue((string)key_dict->value));

}


void printValue(dict_listp list, string command)
{
	int type = getType(command);
	if (list != NULL) 
		changeStringToValues(*list,command, type); // switch variables to their values in the string
	if (!command && list)
		fprintf(stderr, "Error in expression, Usage: print(expression)");
	
	// Only integers operations available
	if (isInteger(command)) printf("%s\n", getStringValueOf_int_operations(command));
	else if (isFloat(command))  printf("%f\nFloat operations not supported yet!\n", getFloatValue(command));
	else if (isString(command)) printf("%s\nString operations not supported yet!\n", getStringValue(command));

}