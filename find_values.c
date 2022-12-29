#include "push_swap.h"
#include <stdarg.h>
#include <limits.h>

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

int max_index(int *stack)
{
	int i;

	i = 0;
	while (stack[i] != 0)
		i++;
	return (i - 1);
}

int max_value(int *stack, int max_index)
{
	int max;

	max = stack[max_index];
	while (--max_index >= 0)
	{
		if (max < stack[max_index])
			max = stack[max_index];
	}
	return (max);
}

int min_value(int *stack, int max_index)
{
	int min;

	min = stack[max_index];
	while (--max_index >= 0)
	{
		if (min > stack[max_index])
			min = stack[max_index];
	}
	return (min);
}

int find_index_of_max_value(int *stack, int max_index)
{
	int max_value_index;
	int i;

	max_value_index = 0;
	i = -1;
	while (++i < (max_index + 1))
	{
		if (stack[max_value_index] < stack[i])
			max_value_index = i;
	}
	return (max_value_index);
}

int find_index_of_min_value(int *stack, int max_index)
{
	int min_value_index;
	int i;

	min_value_index = 0;
	i = -1;
	while (++i < (max_index + 1))
	{
		if (stack[min_value_index] > stack[i])
			min_value_index = i;
	}
	return (min_value_index);
}