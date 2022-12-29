#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

//----MAIN----------------------------------------------------------------------

int check_if_int(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int check_int_minmax(long long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int check_duplicate(int *aa, int num)
{
	int i;
	int ia;

	i = 0;
	ia = max_index(aa);
	while (i < ia)
	{
		if (num == aa[i])
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char *av[])
{
	static int *aa;
	static int *bb;
	int i;
	int num;

	if (ac < 2)
		return (0);
	i = 0;
	aa = init_aa(aa);
	while (av[++i])
	{
		if (!check_if_int(av[i]))
		{
			printf("Error! Not an int.\n");
			return (0);
		}
		num = atoi(av[i]);
		if (!check_int_minmax(num))
		{
			printf("Error! Over minmax.\n");
			return (0);
		}
		aa = create_aa(aa, num, i);
		// if (!check_duplicate(aa, num))
		// {
		// 	printf("Error! There are duplicates.\n");
		// 	return (0);
		// }
	}
	bb = init_bb(bb, i);

	printf("\n----------------------------------\n\nINITIAL STACKS!\n\n");
	display_stacks(aa, bb);
	
	//test_sort_max_3(aa, bb);
	//test_commands(aa, bb);
	
	turk_sort(aa, bb);
	
	//display_stacks(aa, bb);
	return (0);
}