#include "push_swap.h"

//----COUNTING STUFF------------------------------------------------------------ OK!

int max_index(int *stack)
{
	int i;

	i = 0;
	while (stack[i] != 0)
		i++;
	return (i - 1);
}

int max_value(int *stack, int max_index)
{
	int max;

	max = stack[max_index];
	while (--max_index >= 0)
	{
		if (max < stack[max_index])
			max = stack[max_index];
	}
	return (max);
}

int min_value(int *stack, int max_index)
{
	int min;

	min = stack[max_index];
	while (--max_index >= 0)
	{
		if (min > stack[max_index])
			min = stack[max_index];
	}
	return (min);
}


//----SORTING ALGORITHMS--------------------------------------------------------


int order(int *stack, int max_index)
{
	int min_value_index;
	int i;

	min_value_index = 0;
	i = -1;
	while (++i < (max_index + 1))
	{
		if (stack[min_value_index] > stack[i])
			min_value_index = i;
	}
	i = -1;
	while (++i < max_index)
	{
		printf("Compare: %d, %d\n", stack[(min_value_index + i) % (max_index + 1)], stack[(min_value_index + i + 1) % (max_index + 1)]);
		if (stack[(min_value_index + i) % (max_index + 1)] > stack[(min_value_index + i + 1) % (max_index + 1)])
		{
			printf("order: YES\n");
			return (1);
		}
	}
	printf("order: NO\n");
	return (0);
}

/*
Options for changing "order"-function:

	while (s[...] > s[...])
	{
		if (i == max_index - 1)
			return (1);
		i++;
	}
	return (0);

or:																				TRY THIS FIRST!

	while (max_index2 > -1)
	{
		if (s[mvi % maxi+1] > s[mvi+1 % maxi+1])
			return (0);
		max_index2--;
	}
	return (1);

*/

/*

order			sorted			half-sort		reverse			half-rev
s[i]			3	2	1		2	1	3		1	2	3		3	1	2

i				0	1	2		0	1	2		0	1	2		0	1	2
mvi				2	2	2		1	1	1		0	0	0		1	1	1

x=(mvi+i)%3		2	0	1		1	2	0		0	1	2		1	2	0
y=(mvi+i+1)%3	0	1	2		2	0	1		1	2	0		2	0	1

s[x]			1	3	2		1	3	2		1	2	3		1	2	3
s[y]			3	2	1		3	2	1		2	3	1		2	3	1

s[x] ? s[y]		<	>	>		<	>	>		<	<	>		<	<	>

*/

void sort_two(int *aa, int *bb, char c)
{
	if (c == 'a' && aa[0] < aa[1])
		swap(aa, bb, 'a');
	if (c == 'b' && bb[0] > bb[1])
		swap(aa, bb, 'b');
}

void sort_three(int *aa, int *bb, int ia)
{
	if (order(aa, ia) && aa[ia] == min_value(aa, ia))
		return;
	if (!order(aa, ia))
		swap(aa, bb, 'a');
	if (aa[0] == min_value(aa, ia))
		reverse(aa, bb, 'a');
	if (aa[ia] == max_value(aa, ia))
		rotate(aa, bb, 'a');
}

int rotations_to_top(int max_index, int index)
{
	int min_rotations;

	if (max_index - index < index + 1)
		min_rotations = max_index - index;
	else
		min_rotations = index + 1;
	return (min_rotations);
}

int find_position(int *stack, int max_index, int value)
{
	while (value > stack[max_index] && max_index > -1)
		max_index--;
	max_index++;
	return (max_index);
}

//------------------------------------------------------------------------------ YOU'RE WORKING HERE!!!!!

int count_steps(int *aa, int *bb, int index, int ib)
{
	int steps;
	int min;
	int max;
	int ia;
	int rot;

	min = min_value(bb, ib);
	max = max_value(bb, ib);
	ia = max_index(aa);
	if ((aa[index] > max || aa[index] < min) && bb[ib] == max)
		steps = 1;										// pb
	else
	{
		rot = rotations_to_top(ia, index);
		steps = rotations_to_top(find_position(bb, ib, aa[index]), index);
	}
	return (steps);
}

/*
0	4
1	2
2	7	
3	6	8	0
4	1	3	1
--------------
ia	A	B	ib

- count least rotate steps for A
- count least reverse steps for A
- count least rotate steps for B
- count least reverse steps for B
(- optimize by checking if swapping means less steps in the future)
- choose the smallest of the folowing:
	- biggest of rotate A and rotate B
	- biggest of reverse A and reverse B

			
*/


//------------------------------------------------------------------------------ YOU'RE WORKING HERE!!!!!

int index_to_push(int *aa, int *bb, int ia, int ib)
{
	int least_steps;
	int steps;
	int index;

	least_steps = count_steps(aa, bb, ia, ib);
	printf("ia = %d,\tleast_steps = %d\n", ia, least_steps);
	index = ia;
	while (--ia > -1 && least_steps > 1)
	{
		steps = count_steps(aa, bb, ia, ib);
		printf("ia = %d,\tsteps = %d\n", ia, steps);
		if (least_steps > steps)
		{
			least_steps = steps;
			index = ia;
		}
	}
	return (index);
}

void turk_sort(int *aa, int *bb)
{
	int ia;
	int ib;
	int i;

	ia = max_index(aa);
	ib = max_index(bb);
	if (ia == 1)
		sort_two(aa, bb, 'a');
	else if (ia == 2)
		sort_three(aa, bb, ia);
	else
	{
		while (ia > 2 && ib < 1 && !order(aa, ia))								// <- Move up to 2 elements to B.
		{
			push(aa, bb, 'b');
			ia--;
			ib++;
		}
		sort_two(aa, bb, 'b');													// <- Make sure B is in reversed order.
		while (ia > 2 && !order(aa, ia))										// <- Check best element to push, and push until A has 3 elements left. (OPTIMIZE!!! Stop if A is in order.)
		{																		// Should be "order(aa, ia)", not "!order(aa, ia)". Change it when order function is fixed!
			i = index_to_push(aa, bb, ia, ib);
			printf("ia = %d,\tindex to push = %d\n", ia, i);
			//push_element(aa, bb, i);
			ia--;
			ib++;
		}
		/*
		// Sort A
		sort_three(aa, bb, ia);
		// Push back to A. Arrange A if needed.
		while (ib >= 0)
		{
			find_position(aa, bb, ib);
			push(aa, bb, 'b');
			ib--;
		}
		*/
	}
}

/*

ALGORITHM

- Push 2 to stack B
- Count how many steps is needed to push to correct position in B (we want stack B in reverse order)
	- If element will be new MIN or MAX of B, push it above current MAX
	- Else, push it to the correct place
- Push the element that require the least steps


TO DO

- Fix an order function that works with any size of stack (3 and bigger)

*/