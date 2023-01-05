#include "push_swap.h"

void swap(t_list *data, char c)
{
	if (data->i_max_a > 0 && (c == 'a' || c == 's'))
	{
		data->stack_a[data->i_max_a] = data->stack_a[data->i_max_a] + data->stack_a[data->i_max_a - 1];
		data->stack_a[data->i_max_a - 1] = data->stack_a[data->i_max_a] - data->stack_a[data->i_max_a - 1];
		data->stack_a[data->i_max_a] = data->stack_a[data->i_max_a] - data->stack_a[data->i_max_a - 1];
	}
	if (data->i_max_b > 0 && (c == 'b' || c == 's'))
	{
		data->stack_b[data->i_max_b] = data->stack_b[data->i_max_b] + data->stack_b[data->i_max_b - 1];
		data->stack_b[data->i_max_b - 1] = data->stack_b[data->i_max_b] - data->stack_b[data->i_max_b - 1];
		data->stack_b[data->i_max_b] = data->stack_b[data->i_max_b] - data->stack_b[data->i_max_b - 1];
	}
	printf("s%c\n", c);
	display_stacks(data);
}

void push(t_list *data, char c)
{
	if (c == 'a' && data->i_max_b >= 0)
	{
		data->i_max_a++;
		data->stack_a[data->i_max_a] = data->stack_b[data->i_max_b];
		data->stack_b[data->i_max_b] = 0;
		data->i_max_b--;
	}
	if (c == 'b' && data->i_max_a >= 0)
	{
		data->i_max_b++;
		data->stack_b[data->i_max_b] = data->stack_a[data->i_max_a];
		data->stack_a[data->i_max_a] = 0;
		data->i_max_a--;
	}
	printf("p%c\n", c);
	display_stacks(data);
}

void rotate(t_list *data, char c)
{
	int temp;
	int i;

	if (data->i_max_a > 0 && (c == 'a' || c == 'r'))
	{
		temp = data->stack_a[data->i_max_a];
		i = data->i_max_a;
		while (--i >= 0)
			data->stack_a[i + 1] = data->stack_a[i];
		data->stack_a[0] = temp;
	}
	if (data->i_max_b > 0 && (c == 'b' || c == 'r'))
	{
		temp = data->stack_b[data->i_max_b];
		i = data->i_max_b;
		while (--i >= 0)
			data->stack_b[i + 1] = data->stack_b[i];
		data->stack_b[0] = temp;
	}
	printf("r%c\n", c);
	display_stacks(data);
}

void reverse(t_list *data, char c)
{
	int temp;
	int i;

	if (data->i_max_a > 0 && (c == 'a' || c == 'r'))
	{
		i = -1;
		temp = data->stack_a[0];
		while (++i < data->i_max_a)
			data->stack_a[i] = data->stack_a[i + 1];
		data->stack_a[data->i_max_a] = temp;
	}
	if (data->i_max_b > 0 && (c == 'b' || c == 'r'))
	{
		i = -1;
		temp = data->stack_b[0];
		while (++i < data->i_max_b)
			data->stack_b[i] = data->stack_b[i + 1];
		data->stack_b[data->i_max_b] = temp;
	}
	printf("rr%c\n", c);
	display_stacks(data);
}