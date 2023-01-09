#include "push_swap.h"
#include <stdio.h>

void sort_two_halves(t_list *data)
{
	int i;
	int max_a;
	int max_b;

	i = 0;
	while (i < data->i_max_a)
	{
		push(data, 'b');
		i++;
	}
	max_a = max_value(data, 'a');
	max_b = max_value(data, 'b');
	//printf("max_a = %d\nmax_b = %d\n\n", max_a, max_b);
	i = data->i_max_a;
	while (!order(data) || !rev_order(data))
	{
		//printf("Rotate check 1!\n");
		if (data->stack_a[i - 1] == max_a && data->stack_b[i - 1] == max_b)
			rotate(data, 'r');
		else if (data->stack_a[i - 1] == max_a)
			rotate(data, 'a');
		else if (data->stack_b[i - 1] == max_b)
			rotate(data, 'b');
		//printf("Rotate check 2!\n");
		if (data->stack_a[i] == max_a && data->stack_b[i] == max_b)
			rotate(data, 'r');
		else if (data->stack_a[i] == max_a)
			rotate(data, 'a');
		else if (data->stack_b[i] == max_b)
			rotate(data, 'b');
		//printf("Swapping!\n");
		if (data->stack_a[i] > data->stack_a[i - 1] && data->stack_b[i] < data->stack_b[i - 1])
			swap(data, 's');
		else if (data->stack_a[i] > data->stack_a[i - 1])
			swap(data, 'a');
		else if (data->stack_b[i] < data->stack_b[i - 1])
			swap(data, 'b');
		rotate(data, 'r');
		//printf("----n = %d----\n\n", n);
	}
	while (data->i_max_b >= 0)
	{
		find_position_in_a(data);
		push(data, 'a');
	}
	shift_a(data, find_index_of_min_value(data, 'a'));
}