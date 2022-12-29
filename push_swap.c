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

void find_position_in_a(int *aa, int *bb, int ia, int ib)
{
	int min_a;
	int max_a;
	int pos_a;
	
	max_a = find_index_of_max_value(aa, ia);
	min_a = find_index_of_min_value(aa, ia);
	if (bb[ib] > aa[max_a] || bb[ib] < aa[min_a])
		pos_a = min_a;
	else
	{
		printf("TEST!\nmax_a = %d\n", max_a);
		while (bb[ib] < aa[max_a % ia])											// FIX THIS! IT LOOPS FOREVER!
			max_a = (max_a + 1) % ia;
		if (max_a == 0)
			max_a = ia;
		else
			max_a--;
		pos_a = max_a;
	}
	printf("FPA:\tpos_a = %d\tia = %d\n", pos_a, ia);
	if (ia - pos_a <= pos_a + 1)
	{
		while (pos_a++ < ia)
			rotate(aa, bb, 'a');
	}
	else
	{
		while (pos_a-- >= 0)
			reverse(aa, bb, 'a');
	}
}

int find_position_in_b(int *stack, int max_index, int value)
{
	int i;

	i = max_index;
	if (stack[0] > stack[i])
		return (0);
	while (value < stack[i] && i > -1)
		i--;
	if (i == -1)
		i = max_index;
	printf("FPB:\tvalue = %d\tpos_b = %d\n", value, i);
	return (i);
}

int count_steps(int *aa, int *bb, int index, int ib)
{
	int ia;
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

	ia = max_index(aa);
	pos_b = find_position_in_b(bb, ib, aa[index]);

	rot_a = ia - index;
	rot_b = ib - pos_b;
	rev_a = index + 1;
	rev_b = pos_b + 1;

	rot = bigger(rot_a, rot_b);
	rev = bigger(rev_a, rev_b);
	aubd = rot_a + rev_b;
	adbu = rev_a + rot_b;
	
	min = smallest(4, rot, rev, aubd, adbu) + 1;

	//printf("CS:\trot = %d, rev = %d, aubd = %d, adbu = %d\n", rot, rev, aubd, adbu);
	//printf("CS:\tmin = %d\n", min);
	
	return (min);
}

int index_to_push(int *aa, int *bb, int ia, int ib)
{
	int least_steps;
	int steps;
	int index;

	least_steps = count_steps(aa, bb, ia, ib);
	//printf("IP:\ti = %d,\tleast_steps = %d\n", ia, least_steps);
	index = ia;
	while (--ia > -1 && least_steps > 1)
	{
		steps = count_steps(aa, bb, ia, ib);
		//printf("IP:\ti = %d,\tsteps = %d\n", ia, steps);
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
	int ia;
	int ib;
	int pos_b;
	int rot_a;
	int rot_b;
	int rev_a;
	int rev_b;
	int rot;
	int rev;
	int aubd;
	int adbu;

	ia = max_index(aa);
	ib = max_index(bb);
	pos_b = find_position_in_b(bb, ib, aa[index]);

	rot_a = ia - index;
	rot_b = ib - pos_b;
	rev_a = index + 1;
	rev_b = pos_b + 1;

	rot = bigger(rot_a, rot_b);
	rev = bigger(rev_a, rev_b);
	aubd = rot_a + rev_b;
	adbu = rev_a + rot_b;

	//printf("PE:\tindex = %d\tpos_b = %d\n", index, pos_b);

	if (rot <= rev && rot <= smaller(aubd, adbu))
		A_up_B_up(aa, bb, index, pos_b);
	else if (rev <= smaller(aubd, adbu))
		A_down_B_down(aa, bb, index, pos_b);
	else if (aubd <= adbu)
		A_up_B_down(aa, bb, index, pos_b);
	else
		A_down_B_up(aa, bb, index, pos_b);
	
	push(aa, bb, 'b');
}

void shift_a(int *aa, int *bb, int ia, int index)
{
	printf("SA:\tindex = %d\n", index);
	if ((ia - index) <= (index + 1))
	{
		while (index++ < ia)
			rotate(aa, bb, 'a');
	}
	else
	{
		while (index-- >= 0)
			reverse(aa, bb, 'a');
	}
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
		while (ia > 2 && ib < 1 && !order(aa, ia))
		{
			push(aa, bb, 'b');
			ia--;
			ib++;
		}
		sort_two(aa, bb, 'b');
		while (ia > 2 && !order(aa, ia))
		{
			i = index_to_push(aa, bb, ia, ib);
			//printf("TS:\ti = %d,\tindex to push = %d\n", ia, i);
			push_element(aa, bb, i);
			ia--;
			ib++;
		}
		sort_three(aa, bb, ia);
		printf("I THINK IT BREAKS AFTER THIS ONE!\nia = %d, ib = %d\n", ia, ib);
		while (ib >= 0)
		{
			find_position_in_a(aa, bb, ia, ib);
			push(aa, bb, 'a');
			ia++;
			ib--;
		}
		shift_a(aa, bb, ia, find_index_of_min_value(aa, ia));
	}
}