#include "DataPrinter.h"

#pragma warning(disable:4996)


int main()
{
	FILE* reading_file = stdin;
	char line[MAX_GET] = { 0 };
	dict_listp listp = allocateListDictionary();
	string argument = NULL, command = NULL;

	
	puts("\nWelcome to the Ultimate python parser poc 1.0.0!");
	puts("*********************************************\n");
	puts("Supported: ");
	puts("* Variables definitions and manipulations");
	puts("* Arithmethic operations such as: +,-,*,/ for integers only [Strings(\"Only this, is a string for now\"), floats in the future]");
	puts("* Notice: This is a Beta version, not all exceptions are handled so be careful!");


	printf("\n>> ");
	while (!feof(reading_file) && (int)(fgets(line, MAX_GET, reading_file)) != EOF && strcmp(line, "exit()\n") && strcmp(line, "exit\n"))
	{
		line[strlen(line) - 1] = 0; 
		if (!strcmp(line, "")) { printf(">> "); continue; }
		strcpy(line,trim(line));
		
		
		// Check which command to use
		if (isAssign(line))
			listp = assignToDictList(listp,getKeyValue(line, '='));
		else if (isPrint(line))
			printValue(listp, getArgumentBetween(line, '(', ')'));
		else
			printValue(listp, line);
			
		printf(">> ");
	}


	freeDictList(listp);
	system("pause");
	return 0;
}
