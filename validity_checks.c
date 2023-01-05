/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:09:13 by jbagger           #+#    #+#             */
/*   Updated: 2023/01/05 16:11:18 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order(t_list *data)
{
	int	under;
	int	above;
	int	max_value_index;
	int	i;

	max_value_index = find_index_of_max_value(data);
	i = data->i_max_a;
	while (i-- > 0)
	{
		under = data->stack_a[max_value_index % (data->i_max_a + 1)];
		above = data->stack_a[(max_value_index + 1) % (data->i_max_a + 1)];
		if (under < above)
			return (0);
		max_value_index++;
	}
	return (1);
}

int	check_if_int(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' && s[i + 1])
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_int_minmax(const char *str)
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
		if (result * sign > 2147483647 || result * sign < -2147483648)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		str++;
	}
	return (1);
}

int	check_duplicate(t_list *data, int i, int num)
{
	if (i < data->i_max_a)
	{
		while (++i <= data->i_max_a)
		{
			if (num == data->stack_a[i])
			{
				write(1, "Error\n", 6);
				return (0);
			}
		}		
	}
	return (1);
}
