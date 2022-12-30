#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

int check_if_int(char *s)
{
	int i;

	i = 0;
	if (s[i] == '-' && s[i + 1])
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int check_int_minmax(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		if (result * sign > 2147483647)
			return (0);
		if (result * sign < -2147483648)
			return (0);
		str++;
	}
	return (1);
}

int check_duplicate(int *aa, int num)
{
	int ia;

	ia = max_index(aa);
	while (ia > 0)
	{
		if (aa[ia] == num)
			return (0);
		ia--;
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
		if (!check_int_minmax(av[i]))
		{
			printf("Error! Over minmax.\n");
			return (0);
		}
		num = atoi(av[i]);
		aa = create_aa(aa, num, i);
		if (!check_duplicate(aa, num))
		{
			printf("Error! There are duplicates.\n");
			return (0);
		}
	}
	bb = init_bb(bb, i);

	printf("\n----------------------------------\n\nINITIAL STACKS!\n\n");
	display_stacks(aa, bb);
	//test_sort_max_3(aa, bb);
	//test_commands(aa, bb);
	printf("\n----------------------------------\n\nCOMMANDS!\n\n");
	turk_sort(aa, bb);
	printf("\n----------------------------------\n\nFINAL STACKS!\n\n");
	display_stacks(aa, bb);
	return (0);
}