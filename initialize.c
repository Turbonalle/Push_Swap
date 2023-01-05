#include "push_swap.h"

int init_list(t_list *data, int size)
{
	data->stack_a = malloc(sizeof(int) * (size));
	if (!(data->stack_a))
	{
		printf("Malloc failed!\n");
		return (0);
	}
	data->stack_b = malloc(sizeof(int) * (size));
	if (!data->stack_b)
	{
		printf("Malloc failed!\n");
		return (0);
	}
	data->i_max_a = size - 1;
	while (size >= 0)
	{
		data->stack_b[size] = 0;
		size--;
	}
	data->i_max_b = -1;
	return (1);
}