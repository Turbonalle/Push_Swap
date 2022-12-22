#include "push_swap.h"

int order(int *stack, int max_index)
{
	int min_value_index;
	int max_value_index;
	int i;

	min_value_index = find_index_of_min_value(stack, max_index);
	max_value_index = find_index_of_max_value(stack, max_index);
	i = max_index;
	while (i-- > 0)
	{
		if (stack[max_value_index % (max_index + 1)] < stack[(max_value_index + 1) % (max_index + 1)])
		{
			printf("order: NO\n");
			return (0);
		}
		max_value_index++;
	}
	printf("order: YES\n");
	return (1);
}

void sort_two(int *aa, int *bb, char c)
{
	if (c == 'a' && aa[1] && aa[0] < aa[1])
		swap(aa, bb, 'a');
	if (c == 'b' && bb[1] && bb[0] > bb[1])
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

int find_position_in_b(int *stack, int max_index, int value)
{
	int i;

	i = max_index;
	while (value < stack[i] && i > -1)
		i--;
	if (i == -1)
		i = max_index;
	return (i);
}

int count_steps(int *aa, int *bb, int index, int ib)							// Still have to check if rotating one stack and reversing the other is a better option!!!
{
	int pos_b;
	int max_rot;
	int max_rev;
	int ia;
	
	pos_b = find_position_in_b(bb, ib, aa[index]);
	printf("CS:\tpos_b = %d\n", pos_b);
	ia = max_index(aa);
	// Calculate how many rots are needed
	max_rot = ia - index;
	if (max_rot < ib - pos_b)
		max_rot = ib - pos_b;
	// Calculate how many revs are needed
	max_rev = index + 1;
	if (max_rev < pos_b + 1)
		max_rev = pos_b + 1;
	// Return smaller one of max_rot and max_rev
	if (max_rot > max_rev)
		max_rot = max_rev;
	return (max_rot + 1);
}

//------------------------------------------------------------------------------ YOU'RE WORKING HERE!!!!! v

int index_to_push(int *aa, int *bb, int ia, int ib)
{
	int least_steps;
	int steps;
	int index;

	least_steps = count_steps(aa, bb, ia, ib);
	printf("IP:\ti = %d,\tleast_steps = %d\n", ia, least_steps);
	index = ia;
	while (--ia > -1 && least_steps > 1)
	{
		steps = count_steps(aa, bb, ia, ib);
		printf("IP:\ti = %d,\tsteps = %d\n", ia, steps);
		if (least_steps > steps)
		{
			least_steps = steps;
			index = ia;
		}
	}
	return (index);
}

void push_element(int *aa, int *bb, int index)
{
	int i;
	int ia;
	int ib;
	int pos_b;

	i = index;
	ia = max_index(aa);
	ib = max_index(bb);
	pos_b = find_position_in_b(bb, ib, aa[index]);
	// This is not considering different stack size of A and B
	if ((ia - index) <= (index + 1) && (ib - pos_b) <= (pos_b + 1))
		A_up_B_up(aa, bb, i, pos_b);
	else if ((ia - index) <= (index + 1) && (ib - pos_b) > (pos_b + 1))
		A_up_B_down(aa, bb, i, pos_b);
	else if ((ia - index) > (index + 1) && (ib - pos_b) <= (pos_b + 1))
		A_down_B_up(aa, bb, i, pos_b);
	else if ((ia - index) > (index + 1) && (ib - pos_b) > (pos_b + 1))
		A_down_B_down(aa, bb, i, pos_b);
	else if ((ia - index) == (index + 1) && (ib - pos_b) > (pos_b + 1))
		A_mid_B_down();
	else if ((ia - index) > (index + 1) && (ib - pos_b) == (pos_b + 1))
		A_down_B_mid();
	
	push(aa, bb, 'b');
}

/*

count_steps():

	rot_a = ia - index;
	rot_b = ib - find_position(bb, ib, aa[index]);
	rev_a = index + 1;
	rev_b = find_position(bb, ib, aa[index]) + 1;

*/

//------------------------------------------------------------------------------ YOU'RE WORKING HERE!!!!! ^

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
		{
			i = index_to_push(aa, bb, ia, ib);
			printf("TS:\ti = %d,\tindex to push = %d\n", ia, i);
			push_element(aa, bb, i);
			ia--;
			ib++;
		}
		
		// Sort A
		sort_three(aa, bb, ia);
		/*
		// Push back to A. Arrange A if needed.
		while (ib >= 0)
		{
			find_position_in_a(aa, bb, ib);
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

*/

/*

count_steps():

	rot_a = ia - index;
	rot_b = ib - find_position(bb, ib, aa[index]);
	rev_a = index + 1;
	rev_b = find_position(bb, ib, aa[index]) + 1;

*/