#include "push_swap.h"

int o(t_list *data, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (data->stack_a[data->i_max_a - i] > data->stack_a[data->i_max_a - i - 1])
		{
			//printf("Order: NO! (%d)\n", size);
			return (0);
		}
		i++;
	}
	//printf("Order: YES! (%d)\n", size);
	return (1);
}

int o2(t_list *data, int size)
{
	int i;

	i = data->i_max_a - size;
	while (i > 0)
	{
		if (data->stack_a[i] > data->stack_a[i - 1])
		{
			//printf("Order: NO! (%d)\n", size);
			return (0);
		}
		i--;
	}
	//printf("Order: YES! (%d)\n", size);
	return (1);
}

void r(t_list *data, int size)
{
	//printf("Entered r()!\n");

	while (size-- > 0)
		rotate(data, 'a');
}

void rr(t_list *data, int size)
{
	//printf("Entered rr()!\n");

	while (size-- > 0)
		reverse(data, 'a');
}

void push_half(t_list *data, int size)
{
	//printf("Entered push_half()!\n");
	while (size-- > 0)
		push(data, 'b');
}

void sm_2(t_list *data)
{
	//printf("Entered sm_2()!\n");
	int rotations;

	rotations = 0;
	if (data->stack_a[data->i_max_a] > data->stack_a[data->i_max_a - 1])
		swap(data, 'a');
	if (o(data, 4))
		return;
	push(data, 'b');
	push(data, 'b');
	if (data->stack_a[data->i_max_a] > data->stack_a[data->i_max_a - 1])
		swap(data, 'a');
	if (data->stack_a[data->i_max_a] < data->stack_b[data->i_max_b])
	{
		rotate(data, 'a');
		rotations++;
	}
	if (data->stack_a[data->i_max_a] < data->stack_b[data->i_max_b])
	{
		rotate(data, 'a');
		rotations++;
	}
	push(data, 'a');
	while (rotations-- > 0)
	{
		if (data->i_max_b >= 0 && data->stack_b[0] > data->stack_a[0])
			push(data, 'a');
		reverse(data, 'a');
	}
	if (data->i_max_b >= 0)
		push(data, 'a');
}

int top_min(t_list *data, int size)
{
	int min;

	min = data->stack_a[data->i_max_a];
	while (size-- > 0)
	{
		if (min > data->stack_a[data->i_max_a - size])
			min = data->stack_a[data->i_max_a - size];
	}
	//printf("top_min = %d\n", min);
	return (min);
}

int bottom_max(t_list *data, int size)
{
	int max;

	max = data->stack_a[0];
	while (size-- > 0)
	{
		if (max < data->stack_a[size])
			max = data->stack_a[size];
	}
	//printf("bottom_max = %d\n", max);
	return (max);
}

void org(t_list *data, int size2)
{
	int rotations;

	rotations = 0;
	while (data->i_max_b >= 0)
	{
		while (rotations < size2 && data->stack_a[data->i_max_a] < data->stack_b[data->i_max_b])
		{
			rotate(data, 'a');
			rotations++;
		}
		push(data, 'a');
		while (rotations > 0 && data->stack_a[0] > data->stack_b[data->i_max_b])
		{
			reverse(data, 'a');
			rotations--;
		}
	}
	while (rotations > 0)
	{
		reverse(data, 'a');
		rotations--;
	}
}

void sm_small(t_list *data, int size)
{
	int top;

	top = data->i_max_a;
	if (size == 2)
	{
		if (data->stack_a[top] > data->stack_a[top - 1])
			swap(data, 'a');
	}
	if (size == 3)
	{
		if (data->stack_a[top] > data->stack_a[top - 1])
			swap(data, 'a');
		if (data->stack_a[top - 1] > data->stack_a[top - 2])
		{
			rotate(data, 'a');
			swap(data, 'a');
			reverse(data, 'a');
		}
		if (data->stack_a[top] > data->stack_a[top - 1])
			swap(data, 'a');
	}
	if (size == 4)
		sm_2(data);
}

void sm(t_list *data, int size, int lap)
{
	int size1;
	int size2;
	
	size1 = size / 2;
	size2 = size / 2;
	if (size % 2 != 0)
		size1++;
	//printf("SM: size = %d, lap = %d\n",size, lap);
	if (o(data, size))
		return;
	if (size <= 4)
	{
		sm_small(data, size);
		return;
	}
	if (!o(data, size1))
	{
		sm(data, size1, lap + 1);
	}
	if (!o2(data, size2))
	{
		r(data, size1);
		sm(data, size2, lap + 1);
	}
	/*
	if (top_min(data, size2) > bottom_max(data, size1))
	{
		r(data, size1);
		return;
	}
	*/
	rr(data, size1);
	push_half(data, size1);
	//printf("TEST!------------------------------------------------------\n");
	org(data, size2);
}

void sort_merge2(t_list *data)
{
	if (!o(data, data->i_max_a + 1))
		sm(data, data->i_max_a + 1, 1);
}


/*

FAIL!

3 1 2 4 6 7 5

1 5 6 9 8 7 2 4 3

8 1 2 9 10 11 6 7 5 4 3 

1 4 8 3 10 11 9 5 13 12 7 6 2 

4 9 6 5 13 15 14 11 1 2 7 3 12 10 8 


 5 16  8 13  6  1 15 18  3  4  7  9 12 17 14 10 11  2
15 11 14  4  3  7  5 17  6  8 12  1 16 18  2 10 13  9
13  7 15  4  8 10  1 16  5  2  3  9 18 11 17 14 12  6


SUCCESS!

 1  8 17 14  7 10 11 16  9  5  6  3  2 12 15 18 13  4
14 17 10  2  5  3  4  1  6 16  9 11 18 12  8 15  7 13
 7 17  9 18 11  4  1  3 13  2 15 16  8 12 10 14  5  6
 7 16 11  5 18 14  6 10  9  1 12 17 15  2  3  8 13  4
 9  7  4 15  3  1  6 13 11 12  8 18 16 10 17  5  2 14
 5 16  8  2  6 13 18 11 12 14  4 10  9 15  7  1  3 17
 4 10  7  8 12 16  1  5  2 18 15 11 13  6 17  9  3 14


*/