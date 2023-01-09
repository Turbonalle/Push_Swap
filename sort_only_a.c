#include "push_swap.h"

void sort_only_a(t_list *data)
{
	int max = max_value(data, 'a');

	while (!order(data))
	{
		if (data->stack_a[data->i_max_a - 1] == max)
			rotate(data, 'a');
		if (data->stack_a[data->i_max_a] == max)
			rotate(data, 'a');
		if (data->stack_a[data->i_max_a] > data->stack_a[data->i_max_a - 1])
			swap(data, 'a');
		rotate(data, 'a');
	}
	shift_a(data, find_index_of_min_value(data, 'a'));
}