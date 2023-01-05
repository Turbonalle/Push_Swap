#include "push_swap.h"

int order(t_list *data)
{
	int max_value_index;
	int i;

	max_value_index = find_index_of_max_value(data);
	i = data->i_max_a;
	while (i-- > 0)
	{
		if (data->stack_a[max_value_index % (data->i_max_a + 1)] < data->stack_a[(max_value_index + 1) % (data->i_max_a + 1)])
		{
			printf("Order: NO!\n");
			return (0);
		}
		max_value_index++;
	}
	printf("Order: YES!\n");
	return (1);
}

void sort_two(t_list *data, char c)
{
	if (c == 'a' && data->i_max_a == 1 && data->stack_a[0] < data->stack_a[1])
		swap(data, 'a');
	if (c == 'b' && data->i_max_b == 1 && data->stack_b[0] > data->stack_b[1])
		swap(data, 'b');
}

void sort_three(t_list *data)
{
	if (order(data) && data->stack_a[data->i_max_a] == min_value(data))
		return;
	if (!order(data))
		swap(data, 'a');
	if (data->stack_a[0] == min_value(data))
		reverse(data, 'a');
	if (data->stack_a[data->i_max_a] == max_value(data))
		rotate(data, 'a');
}

void find_position_in_a(t_list *data)
{
	int min_a;
	int max_a;
	int pos_a;
	
	max_a = find_index_of_max_value(data);
	min_a = find_index_of_min_value(data);
	if (data->stack_b[data->i_max_b] > data->stack_a[max_a] || data->stack_b[data->i_max_b] < data->stack_a[min_a])
		pos_a = min_a;
	else
	{
		while (data->stack_b[data->i_max_b] < data->stack_a[max_a % (data->i_max_a + 1)])
			max_a = (max_a + 1) % (data->i_max_a + 1);
		if (max_a == 0)
			max_a = data->i_max_a;
		else
			max_a--;
		pos_a = max_a;
	}
	if (data->i_max_a - pos_a <= pos_a + 1)
	{
		while (pos_a++ < data->i_max_a)
			rotate(data, 'a');
	}
	else
	{
		while (pos_a-- >= 0)
			reverse(data, 'a');
	}
}

int find_position_in_b(t_list *data, int value)
{
	int i;

	i = data->i_max_b;
	if (data->stack_b[0] > data->stack_b[i])
		return (0);
	while (value < data->stack_b[i] && i > -1)
		i--;
	if (i == -1)
		i = data->i_max_b;
	return (i);
}

int count_steps(t_list *data, int index)
{
	int pos_b;
	int rot_a;
	int rot_b;
	int rev_a;
	int rev_b;
	int rot;
	int rev;
	int aubd;
	int adbu;
	int min;

	pos_b = find_position_in_b(data, data->stack_a[index]);

	rot_a = data->i_max_a - index;
	rot_b = data->i_max_b - pos_b;
	rev_a = index + 1;
	rev_b = pos_b + 1;

	rot = bigger(rot_a, rot_b);
	rev = bigger(rev_a, rev_b);
	aubd = rot_a + rev_b;
	adbu = rev_a + rot_b;
	
	min = smallest(4, rot, rev, aubd, adbu) + 1;
	return (min);
}

int index_to_push(t_list *data)
{
	int least_steps;
	int steps;
	int index;
	int i;

	least_steps = count_steps(data, data->i_max_a);
	index = data->i_max_a;
	i = index;
	while (--i > -1 && least_steps > 1)
	{
		steps = count_steps(data, i);
		if (least_steps > steps)
		{
			least_steps = steps;
			index = i;
		}
	}
	return (index);
}

void push_element(t_list *data, int index)
{
	int pos_b;
	int rot_a;
	int rot_b;
	int rev_a;
	int rev_b;
	int rot;
	int rev;
	int aubd;
	int adbu;

	pos_b = find_position_in_b(data, data->stack_a[index]);

	rot_a = data->i_max_a - index;
	rot_b = data->i_max_b - pos_b;
	rev_a = index + 1;
	rev_b = pos_b + 1;

	rot = bigger(rot_a, rot_b);
	rev = bigger(rev_a, rev_b);
	aubd = rot_a + rev_b;
	adbu = rev_a + rot_b;

	if (rot <= rev && rot <= smaller(aubd, adbu))
		A_up_B_up(data, index, pos_b);
	else if (rev <= smaller(aubd, adbu))
		A_down_B_down(data, index, pos_b);
	else if (aubd <= adbu)
		A_up_B_down(data, index, pos_b);
	else
		A_down_B_up(data, index, pos_b);
	
	push(data, 'b');
}

void shift_a(t_list *data, int index)
{
	if ((data->i_max_a - index) <= (index + 1))
	{
		while (index++ < data->i_max_a)
			rotate(data, 'a');
	}
	else
	{
		while (index-- >= 0)
			reverse(data, 'a');
	}
}

void turk_sort(t_list *data)
{
	int i;

	if (data->i_max_a == 1)
		sort_two(data, 'a');
	else if (data->i_max_a == 2)
		sort_three(data);
	else
	{
		while (data->i_max_a > 2 && data->i_max_b < 1 && !order(data))
		{
			push(data, 'b');
		}
		sort_two(data, 'b');
		while (data->i_max_a > 2 && !order(data))
		{
			i = index_to_push(data);
			push_element(data, i);
		}
		if (data->i_max_a == 2 && !order(data))
			sort_three(data);
		while (data->i_max_b >= 0)
		{
			find_position_in_a(data);
			push(data, 'a');
		}
		shift_a(data, find_index_of_min_value(data));
	}
}