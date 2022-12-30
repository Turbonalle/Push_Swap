#include "push_swap.h"

//----TESTS---------------------------------------------------------------

void test_commands(int *aa, int *bb)
{
	printf("\n----------------------------------\n\nTESTING COMMANDS!\n\n");
	rotate(aa, bb, 'a');
	push(aa, bb, 'b');
	push(aa, bb, 'b');
	swap(aa, bb, 'a');
	push(aa, bb, 'b');
	rotate(aa, bb, 'r');
}

void test_sort_max_3(int *aa, int *bb)
{
	int min_a;
	int max_a;
	int ia;
	int ib;

	ia = max_index(aa);
	ib = max_index(bb);
	min_a = min_value(aa, ia);
	max_a = max_value(aa, ia);
	printf("\n----------------------------------\n\nSORTING IF STACK IS MAX 3!\n\n");
	if (ia == 1)
		sort_two(aa, bb, ia);
	if (ia == 2)
		sort_three(aa, bb, ia);
}

void test_order(int *stack, char c)
{
	int max_i;

	if (c == 'a')
		c = 'A';
	if (c == 'b')
		c = 'B';
	printf("\n----------------------------------\n\nCHECKING IF STACK %c IS IN ORDER!\n\n", c);
	max_i = max_index(stack);
	if (order(stack, max_i))
		printf("IN ORDER!\n");
	if (!order(stack, max_i))
		printf("NOT IN ORDER!\n");
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