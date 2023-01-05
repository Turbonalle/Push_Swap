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

int check_duplicate(t_list *data, int i, int num)
{
	if (i < data->i_max_a)
	{
		while (++i <= data->i_max_a)
		{
			if (num == data->stack_a[i])
				return (0);
		}		
	}
	return (1);
}

int main(int ac, char *av[])
{
	int i;
	int num;
	t_list data;

	if (ac < 2)
		return (0);
	i = 0;
	init_list(&data, ac - 1);
	while (i + 1 < ac)
	{
		if (!check_if_int(av[i + 1]))
		{
			printf("Error! Not an int.\n");
			return (0);
		}
		if (!check_int_minmax(av[i + 1]))
		{
			printf("Error! Over minmax.\n");
			return (0);
		}
		num = atoi(av[i + 1]);
		data.stack_a[data.i_max_a - i] = num;
		if (!check_duplicate(&data, data.i_max_a - i, num))
		{
			printf("Error! There are duplicates.\n");
			return (0);
		}
		i++;
	}
	display_stacks(&data);
	turk_sort(&data);
	//display_stacks(&data);
	return (0);
}