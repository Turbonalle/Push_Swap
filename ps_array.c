#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct	s_data
{
	int		a_max;
	int		a_min;
	int		b_max;
	int		b_min;
}			t_data;


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


//----CREATING STACKS----------------------------------------------------------- OK!

int *init_aa(int *aa)
{
	aa = malloc(sizeof(int));
	aa[0] = 0;
	return (aa);
}

int *init_bb(int *bb, int i)
{
	i++;
	bb = malloc(i * sizeof(int));
	while (i >= 0)
	{
		bb[i] = 0;
		i--;
	}
	return (bb);
}

int *create_aa(int *ptr, int n, int len)
{
	int *stack;
	int i;
	
	stack = malloc((len + 1) * sizeof(int));
	if (!stack)
	{
		printf("Malloc failed!\n");
		return (0);
	}
	stack[len] = 0;
	i = -1;
	while (ptr[++i])
		stack[i + 1] = ptr[i];
	stack[0] = n;
	free(ptr);
	return (stack);
}

void display_stack(int *stack)
{
	int i;

	i = max_index(stack);
	while (i > -1)
		printf("stack[%d] = %d\n", i, stack[i]);
	printf("\n");
}

void display_stacks(int *aa, int *bb)
{
	int i;
	int size;

	size = max_index(aa);
	i = size;
	size = max_index(bb);
	if (i < size)
		i = size;
	i++;
	while (--i > -1)
		printf("aa[%d] = %d\tbb[%d] = %d\n", i, aa[i], i, bb[i]);
	printf("\n");
}


//----SORTING COMMANDS---------------------------------------------------------- OK!

void swap(int *aa, int *bb, char c)
{
	int ia;
	int ib;

	ia = max_index(aa);
	ib = max_index(bb);
	if ((c == 'a' || c == 's') && aa[ia] && aa[ia - 1])
	{
		aa[ia] = aa[ia] + aa[ia - 1];
		aa[ia - 1] = aa[ia] - aa[ia - 1];
		aa[ia] = aa[ia] - aa[ia - 1];
	}
	if ((c == 'b' || c == 's') && bb[ib] && bb[ib - 1])
	{
		bb[ib] = bb[ib] + bb[ib - 1];
		bb[ib - 1] = bb[ib] - bb[ib - 1];
		bb[ib] = bb[ib] - bb[ib - 1];
	}
	printf("s%c\n", c);
	display_stacks(aa, bb);
}

void push(int *aa, int *bb, char c)
{
	int ia;
	int ib;

	ia = max_index(aa);
	ib = max_index(bb);
	if (c == 'a' && bb[0])
	{
		aa[ia + 1] = bb[ib];
		bb[ib] = 0;
	}
	if (c == 'b' && aa[0])
	{
		bb[ib + 1] = aa[ia];
		aa[ia] = 0;
	}
	printf("p%c\n", c);
	display_stacks(aa, bb);
}

void rotate(int *aa, int *bb, char c)
{
	int temp;
	int ia;
	int ib;

	ia = max_index(aa);
	ib = max_index(bb);
	if (ia > 0 && (c == 'a' || c == 'r'))
	{
		temp = aa[ia];
		while (--ia >= 0)
			aa[ia + 1] = aa[ia];
		aa[0] = temp;
	}
	if (ib > 0 && (c == 'b' || c == 'r'))
	{
		temp = bb[ib];
		while (--ib >= 0)
			bb[ib + 1] = bb[ib];
		bb[0] = temp;
	}
	printf("r%c\n", c);
	display_stacks(aa, bb);
}

void reverse(int *aa, int *bb, char c)
{
	int temp;
	int ia;
	int ib;
	int i;

	ia = max_index(aa);
	ib = max_index(bb);
	if (ia > 0 && (c == 'a' || c == 'r'))
	{
		i = -1;
		temp = aa[0];
		while (++i < ia)
			aa[i] = aa[i + 1];
		aa[ia] = temp;
	}
	if (ib > 0 && (c == 'b' || c == 'r'))
	{
		i = -1;
		temp = bb[0];
		while (++i < ib)
			bb[i] = bb[i + 1];
		bb[ib] = temp;
	}
	printf("rr%c\n", c);
	display_stacks(aa, bb);
}


//----SORTING ALGORITHMS--------------------------------------------------------


void sort(int *aa, int *bb)
{
	push(aa, bb, 'b');
	// push(aa, bb, 'b');
	swap(aa, bb, 'a');
	// rotate(aa, bb, 'a');
	// push(aa, bb, 'b');
	// push(aa, bb, 'b');
	// rotate(aa, bb, 'r');
	// reverse(aa, bb, 'r');
	// push(aa, bb, 'a');
	// reverse(aa, bb, 'a');
}

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
		if (stack[(min_value_index + i) % 3] > stack[(min_value_index + i + 1) % 3])
			return (1);
	}
	return (0);
}

void sort_two(int *aa, int *bb, char c)
{
	if (c = 'a' && aa[0] < aa[1])
		swap(aa, bb, 'a');
	if (c = 'b' && bb[0] < bb[1])
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

//------------------------------------------------------------------------------ YOU'RE WORKING HERE!!!!!

int rotations_to_top(int max_index, int index)
{
	int min_rotations;

	if (max_index - index < index + 1)
		min_rotations = max_index - index;
	else
		min_rotations = index + 1;
	return (min_rotations);
}

int find_position(int *stack, int max_index, int index)
{
	
}

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
		steps = rotations_to_top(find_position(bb, ib, index), index);
	}
	return (steps);
}

/*
0	4
1	2
2	7	
3	6	8
4	1	3
---------
i	A	B

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
	while (--ia > -1 && least_steps > 1)
	{
		steps = count_steps(aa, bb, ia, ib);
		if (least_steps > steps)
			least_steps = steps;
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
		// Move up to 2 elements to B.
		while (--ia > 2 && ++ib < 2)
			push(aa, bb, 'b');
		// Make sure B is in reversed order;
		sort_two(aa, bb, 'b');
		// Check best element to push, and push until A has 3 elements left.
		while (ia > 2)
		{
			i = index_to_push(aa, bb, ia, ib);
			push_element(aa, bb, i);
			ia--;
			ib++;
		}
		// Sort A
		sort_three(aa, bb, ia);
		// Push back to A. Arrange A if needed.
		while (ib >= 0)
		{
			find_position(aa, bb, ib);
			push(aa, bb, 'b');
			ib--;
		}
	}
}

//----MAIN----------------------------------------------------------------------

void test(int *aa, int *bb)
{
	int min_a;
	int max_a;
	int max_i;

	max_i = max_index(aa);
	min_a = min_value(aa, max_i);
	max_a = max_value(aa, max_i);
	if (max_i == 1)
		sort_three(aa, bb, max_i);
	if (max_i == 2)
		sort_three(aa, bb, max_i);
}

int main(int ac, char *av[])
{
	static int *aa;
	static int *bb;
	int i;

	if (ac < 2)
		return (0);
	i = 0;
	aa = init_aa(aa);
	while (av[++i])
		aa = create_aa(aa, atoi(av[i]), i);
	bb = init_bb(bb, i);

	display_stacks(aa, bb);
	
	test(aa, bb);
	//sort(aa, bb);
	//turk_sort(aa, bb);
	//display_stacks(aa, bb);
	return (0);
}

/*

ALGORITHM

- Push 2 to stack B
- Count how many steps is needed to push to correct position in B (we want stack B in reverse order)
	- If element will be new MIN or MAX of B, push it above current MAX
	- Else, push it to the correct place
- Push the element that require the least steps


(x)	sa
(x)	sb
(x)	ss
(x)	pa
(x)	pb
(x)	ra
(x)	rb
(x)	rr
(x)	rra
(x)	rrb
(x)	rrr


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