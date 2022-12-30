#include "push_swap.h"

int smallest(int n, ...)
{
	int min;
	int current;
	va_list ptr;

	va_start(ptr, n);
	min = INT_MAX;
	while (n-- > 0)
	{
		current = va_arg(ptr, int);
		if (min > current)
			min = current;
	}
	va_end(ptr);
	return (min);
}

int smaller(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int bigger(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}