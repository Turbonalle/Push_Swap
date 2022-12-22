#include "push_swap.h"

void A_up_B_up(int *aa, int *bb, int index_a, int index_b)
{
	int max_index_a;
	int max_index_b;

	max_index_a = max_index(aa);
	max_index_b = max_index(bb);
	while (index_a < max_index_a && index_b < max_index_b)
	{
		rotate(aa, bb, 'r');
		index_a++;
		index_b++;
	}
	while (index_a < max_index_a)
	{
		rotate(aa, bb, 'a');
		index_a++;
	}
	while (index_b < max_index_b)
	{
		rotate(aa, bb, 'b');
		index_b++;
	}
}

void A_up_B_down(int *aa, int *bb, int index_a, int index_b)
{
	int max_index_a;

	max_index_a = max_index(aa);
	while (index_a < max_index_a)
	{
		rotate(aa, bb, 'a');
		index_a++;
	}
	while (index_b > -1)
	{
		reverse(aa, bb, 'b');
		index_b--;
	}
}

void A_down_B_up(int *aa, int *bb, int index_a, int index_b)
{
	int max_index_b;

	while (index_a > -1)
	{
		reverse(aa, bb, 'a');
		index_a--;
	}
	max_index_b = max_index(bb);
	while (index_b < max_index_b)
	{
		rotate(aa, bb, 'b');
		index_b++;
	}
}

void A_down_B_down(int *aa, int *bb, int index_a, int index_b)
{
	while (index_a > -1 && index_b > -1)
	{
		reverse(aa, bb, 'r');
		index_a--;
		index_b--;
	}
	while (index_a > -1)
	{
		reverse(aa, bb, 'a');
		index_a--;
	}
	while (index_b > -1)
	{
		reverse(aa, bb, 'b');
		index_b--;
	}
}