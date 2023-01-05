#include "push_swap.h"

void test_commands(t_list *data)
{
	rotate(data, 'a');
	push(data, 'b');
	push(data, 'b');
	push(data, 'b');
	push(data, 'b');
	push(data, 'b');
	swap(data, 's');
	reverse(data, 'r');
	push(data, 'a');
	swap(data, 'a');
	rotate(data, 'r');
}

void test_sort_max_3(t_list *data)
{
	if (data->i_max_a == 1)
		sort_two(data, 'a');
	if (data->i_max_a == 2)
		sort_three(data);
}

// void test_order(int *stack, char c)
// {
// 	int max_i;

// 	if (c == 'a')
// 		c = 'A';
// 	if (c == 'b')
// 		c = 'B';
// 	printf("\n----------------------------------\n\nCHECKING IF STACK %c IS IN ORDER!\n\n", c);
// 	max_i = max_index(stack);
// 	if (order(stack, max_i))
// 		printf("IN ORDER!\n");
// 	if (!order(stack, max_i))
// 		printf("NOT IN ORDER!\n");
// }

// void display_stacks(t_list *data)
// {
// 	int ia;
// 	int ib;

// 	ia = data->i_max_a;
// 	ib = data->i_max_b;
// 	printf("\n");
// 	while (ia > ib)
// 	{
// 		printf("%d\n",data->stack_a[ia]);
// 		ia--;
// 	}
// 	while (ia < ib)
// 	{
// 		printf("\t%d\n",data->stack_b[ib]);
// 		ib--;
// 	}
// 	while (ia > -1)
// 	{
// 		printf("%d\t%d\n",data->stack_a[ia], data->stack_b[ia]);
// 		ia--;
// 	}
// 	printf("----------------\n");
// 	printf("A\tB\n");
// 	printf("\n");
// }

void display_stacks(t_list *data)
{
	int ia;
	int ib;

	ia = data->i_max_a;
	ib = data->i_max_b;
	if (ia < ib)
		ia = ib;
	while (ia > -1)
	{
		printf("aa[%d] = %d\tbb[%d] = %d\n", ia, data->stack_a[ia], ia, data->stack_b[ia]);
		ia--;
	}
	printf("\n");
}