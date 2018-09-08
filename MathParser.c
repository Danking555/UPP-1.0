#include "MathParser.h"






string getCurrentExpressionEnd(string arguments)
{
	if (!arguments) return NULL;
	string plus = strchr(arguments, '+'), minus = strchr(arguments, '-'), mul = strchr(arguments, '*'), div = strchr(arguments, '/');
	if (!plus && !minus && !mul && !div) return NULL;
	return getMinBetween4(plus, minus, mul, div);
}



int getArgument(string assign, string arguments)
{
	string end_of_current_argument = getCurrentExpressionEnd(arguments);
	int len = 0;
	if (end_of_current_argument) len = end_of_current_argument - arguments;
	else
		len = strlen(arguments);
	strncpy(assign, arguments, len);
	assign[len] = 0;
	return getType(assign);
}


