#include "push_swap.h"

void A_up_B_up(t_list *data, int index_a, int index_b)
{
	while (index_a < data->i_max_a && index_b < data->i_max_b)
	{
		rotate(data, 'r');
		index_a++;
		index_b++;
	}
	while (index_a < data->i_max_a)
	{
		rotate(data, 'a');
		index_a++;
	}
	while (index_b < data->i_max_b)
	{
		rotate(data, 'b');
		index_b++;
	}
}

void A_up_B_down(t_list *data, int index_a, int index_b)
{
	while (index_a < data->i_max_a)
	{
		rotate(data, 'a');
		index_a++;
	}
	while (index_b > -1)
	{
		reverse(data, 'b');
		index_b--;
	}
}

void A_down_B_up(t_list *data, int index_a, int index_b)
{
	while (index_a > -1)
	{
		reverse(data, 'a');
		index_a--;
	}
	while (index_b < data->i_max_b)
	{
		rotate(data, 'b');
		index_b++;
	}
}

void A_down_B_down(t_list *data, int index_a, int index_b)
{
	while (index_a > -1 && index_b > -1)
	{
		reverse(data, 'r');
		index_a--;
		index_b--;
	}
	while (index_a > -1)
	{
		reverse(data, 'a');
		index_a--;
	}
	while (index_b > -1)
	{
		reverse(data, 'b');
		index_b--;
	}
}