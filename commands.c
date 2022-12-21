#include "push_swap.h"

void swap(int *aa, int *bb, char c)
{
	int ia;
	int ib;

	ia = max_index(aa);
	ib = max_index(bb);
	if (ia > 0 && (c == 'a' || c == 's'))
	{
		aa[ia] = aa[ia] + aa[ia - 1];
		aa[ia - 1] = aa[ia] - aa[ia - 1];
		aa[ia] = aa[ia] - aa[ia - 1];
	}
	if (ib > 0 && (c == 'b' || c == 's'))
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