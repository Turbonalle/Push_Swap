#include "push_swap.h"

int max_value(t_list *data)
{
	int i;
	int max;

	i = data->i_max_a;
	max = data->stack_a[i];
	while (--i >= 0)
	{
		if (max < data->stack_a[i])
			max = data->stack_a[i];
	}
	return (max);
}

int min_value(t_list *data)
{
	int i;
	int min;

	i = data->i_max_a;
	min = data->stack_a[i];
	while (--i >= 0)
	{
		if (min > data->stack_a[i])
			min = data->stack_a[i];
	}
	return (min);
}

int find_index_of_max_value(t_list *data)
{
	int max_value_index;
	int i;

	max_value_index = 0;
	i = -1;
	while (++i < (data->i_max_a + 1))
	{
		if (data->stack_a[max_value_index] < data->stack_a[i])
			max_value_index = i;
	}
	return (max_value_index);
}

int find_index_of_min_value(t_list *data)
{
	int min_value_index;
	int i;

	min_value_index = 0;
	i = -1;
	while (++i < (data->i_max_a + 1))
	{
		if (data->stack_a[min_value_index] > data->stack_a[i])
			min_value_index = i;
	}
	return (min_value_index);
}