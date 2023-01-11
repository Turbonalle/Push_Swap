#include "push_swap.h"

void move_min_to_b(t_list *data, int n)
{
	int i;
	int min_value_index;

	i = data->i_max_a;
	min_value_index = i;
	//printf("MTB:\tn = %d\n", n);
	while (--i > data->i_max_a - n)
	{
		if (data->stack_a[min_value_index] > data->stack_a[i])
			min_value_index = i;
	}
	i = 0;
	while (min_value_index < data->i_max_a)
	{
		rotate(data, 'a');
		min_value_index++;
		i++;
	}
	push(data, 'b');
	while (i-- > 0)
		reverse(data, 'a');
	//printf("MTB:\tn = %d, END!\n", n);
}

void sort_group(t_list *data, int n)
{
	int i;

	i = n;
	//printf("SG:\tn = %d\n", n);
	if (n == 2)
	{
		if (data->stack_a[data->i_max_a] > data->stack_a[data->i_max_a - 1])
			swap(data, 'a');
	}
	else
	{
		while (i > 1)
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
	//printf("SG:\tn = %d, END!\n", n);
}

void divide_into_groups(t_list *data, int n)
{
	int i;
	//printf("DIG:\tn = %d\n", n);
	//printf("%d < %d, %d < %d\n", data->stack_a[data->i_max_a], data->stack_a[data->i_max_a - 1], data->stack_a[data->i_max_a - 2], data->stack_a[data->i_max_a - 3]);
	if (n < 2)
		return;
	else if (n == 2)
	{
		sort_group(data, n);
		//display_stacks(data);
	}
	else
	{
		//printf("DIG:\tn = %d, Entering 'else'\n", n);
		divide_into_groups(data, n / 2);
		i = 0;
		if (n == 4 && data->stack_a[data->i_max_a - 2] > data->stack_a[data->i_max_a - 3])
		{
			return;
		}
		while (i++ < n / 2)
			rotate(data, 'a');
		divide_into_groups(data, n / 2);
		i = 0;
		while (i++ < n / 2)
			reverse(data, 'a');
		sort_group(data, n);
		//display_stacks(data);
	}
	//printf("DIG:\tn = %d, END!\n", n);
}

void sort_merge(t_list *data)
{
	divide_into_groups(data, data->i_max_a + 1);
}