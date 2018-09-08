#pragma once

#include "MathParser.h"

enum operation { PLUS, MINUS, MUL, DIV };

float float_val[MAX_GET];
int int_val[MAX_GET];
int sp;

char op[MAX_GET];
enum { EMPTY, FULL };

char top_op();

char pop_op();

void push_op(char insert);

void push_int(int val);

int pop_int();

int popLast_int_Values();

void push_int_operators(char operat);

int getValueOf_int_Operations(string arguments);

string getStringValueOf_int_operations(string keyValue);


void expressionRealize(string line);
