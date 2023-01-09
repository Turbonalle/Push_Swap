#include "push_swap.h"

void move_min_to_b(t_list *data, int n)
{
	int i;
	int min_value_index;

	i = data->i_max_a;
	min_value_index = i;
	printf("MTB:\tn = %d\n", n);
	while (--i >= data->i_max_a - n)
	{
		if (data->stack_a[min_value_index] > data->stack_a[i])
			min_value_index = i;
	}
	while (min_value_index < data->i_max_a)
	{
		rotate(data, 'a');
		min_value_index++;
	}
	push(data, 'b');
}

void sort_group(t_list *data, int n)
{
	int i;

	i = 0;
	printf("SG:\tn = %d\n", n);
	if (n == 2)
	{
		if (data->stack_a[data->i_max_a] > data->stack_a[data->i_max_a - 1])
			swap(data, 'a');
	}
	else
	{
		i = n;
		while (i > 0)
		{
			move_min_to_b(data, i);
			i--;
		}
		while (i < n)
		{
			push(data, 'a');
			i++;
		}
	}
	while (i > 0)
	{
		rotate(data, 'a');
		i--;
	}
}

void divide_into_groups(t_list *data, int n)
{
	printf("DIG:\tn = %d\n", n);
	if (n < 2)
		return;
	else if (n == 2)
		sort_group(data, n);
	else
	{
		divide_into_groups(data, n / 2);
		divide_into_groups(data, n / 2);
		sort_group(data, n);
	}
}

void sort_merge(t_list *data)
{
	divide_into_groups(data, data->i_max_a + 1);
}