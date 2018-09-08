#pragma once

#include "Math.h"

extern char op[MAX_GET] = { 0 };

char top_op()
{
	if (!strlen(op)) return EOF;
	return op[strlen(op) - 1];
}

char pop_op()
{
	char ret = op[strlen(op) - 1];
	op[strlen(op) - 1] = 0;
	return ret;
}

void push_op(char insert)
{
	op[strlen(op)] = insert;
}



void push_int(int val)
{
	if (sp < MAX_GET) int_val[sp++] = val;
	else printf("Error! full stack\n");
}

int pop_int()
{
	if (sp > 0) return int_val[--sp];
	else printf("Error! empty stack\n");
}


int popLast_int_Values()
{
	char op_type = 0;
	int tmp = 0;
	while (top_op() != EOF)
	{
		op_type = pop_op();
		if (op_type == '+')
			push_int(pop_int() + pop_int());
		else if (op_type == '-')
		{
			tmp = pop_int();
			push_int(pop_int() - tmp);
		}

	}
	return pop_int();
}


void push_int_operators(char operat)
{
	int tmp = 0;
	if (top_op() == '*')
	{
		push_int(pop_int() * pop_int());
		pop_op();
	}
	else if (top_op() == '/')
	{
		tmp = pop_int();
		if (tmp) push_int(pop_int() / tmp);
		else printf("Cannot divide by 0!");
		pop_op();
	}
	push_op(operat);
}

int getValueOf_int_Operations(string arguments)
{
	char one_argument[MAX_GET] = { 0 };
	int type = 0;
	int data = 0;

	while (true)
	{
		strcpy(one_argument, "");
		type = getArgument(one_argument, arguments);
		push_int(getIntValue(one_argument));
		arguments += strlen(one_argument);
		push_int_operators(*arguments);
		if (!strcmp(arguments, ""))
			return popLast_int_Values();
		arguments++;
	}
}

string getStringValueOf_int_operations(string keyValue)
{
	sprintf(keyValue, "%d", getValueOf_int_Operations(keyValue));
	return keyValue;
}


void expressionRealize(string line)
{

	string operat = getCurrentExpressionEnd(line);

	char result[MAX_GET] = { 0 };
	char first_part[MAX_GET] = { 0 };
	int size = operat ? operat - line : strlen(line);

	strncpy(first_part, line, size);
	if (getIntValue(first_part) != 0.0)
		printf("%s\n", getStringValueOf_int_operations(line));
	else if (operat == NULL)
		return;
	else if (*operat == '+')
	{
		while (strcmp(line, ""))
		{
			size = operat ? operat - line : strlen(line);
			strncpy(first_part, line, size);

			if (!getStringValue(first_part)) 
				break;
	
			strcat(result, first_part);
			strcpy(first_part, "");
			line += size + 1;
		}
		puts(result);
	}
	else printf("Error cannot manipulate/add other types of data");
}
