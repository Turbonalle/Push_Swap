/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:08:25 by jbagger           #+#    #+#             */
/*   Updated: 2023/01/11 16:05:21 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *data, char c)
{
	int	i;

	if (data->i_max_a > 0 && (c == 'a' || c == 's'))
	{
		i = data->i_max_a;
		data->stack_a[i] = data->stack_a[i] + data->stack_a[i - 1];
		data->stack_a[i - 1] = data->stack_a[i] - data->stack_a[i - 1];
		data->stack_a[i] = data->stack_a[i] - data->stack_a[i - 1];
	}
	if (data->i_max_b > 0 && (c == 'b' || c == 's'))
	{
		i = data->i_max_b;
		data->stack_b[i] = data->stack_b[i] + data->stack_b[i - 1];
		data->stack_b[i - 1] = data->stack_b[i] - data->stack_b[i - 1];
		data->stack_b[i] = data->stack_b[i] - data->stack_b[i - 1];
	}
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	display_stacks(data);
}

void	push(t_list *data, char c)
{
	if (c == 'a' && data->i_max_b >= 0)
	{
		data->i_max_a++;
		data->stack_a[data->i_max_a] = data->stack_b[data->i_max_b];
		data->stack_b[data->i_max_b] = 0;
		data->i_max_b--;
	}
	if (c == 'b' && data->i_max_a >= 0)
	{
		data->i_max_b++;
		data->stack_b[data->i_max_b] = data->stack_a[data->i_max_a];
		data->stack_a[data->i_max_a] = 0;
		data->i_max_a--;
	}
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	display_stacks(data);
}

void	rotate(t_list *data, char c)
{
	int	temp;
	int	i;

	if (data->i_max_a > 0 && (c == 'a' || c == 'r'))
	{
		temp = data->stack_a[data->i_max_a];
		i = data->i_max_a;
		while (--i >= 0)
			data->stack_a[i + 1] = data->stack_a[i];
		data->stack_a[0] = temp;
	}
	if (data->i_max_b > 0 && (c == 'b' || c == 'r'))
	{
		temp = data->stack_b[data->i_max_b];
		i = data->i_max_b;
		while (--i >= 0)
			data->stack_b[i + 1] = data->stack_b[i];
		data->stack_b[0] = temp;
	}
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	display_stacks(data);
}

void	reverse(t_list *data, char c)
{
	int	temp;
	int	i;

	if (data->i_max_a > 0 && (c == 'a' || c == 'r'))
	{
		i = -1;
		temp = data->stack_a[0];
		while (++i < data->i_max_a)
			data->stack_a[i] = data->stack_a[i + 1];
		data->stack_a[data->i_max_a] = temp;
	}
	if (data->i_max_b > 0 && (c == 'b' || c == 'r'))
	{
		i = -1;
		temp = data->stack_b[0];
		while (++i < data->i_max_b)
			data->stack_b[i] = data->stack_b[i + 1];
		data->stack_b[data->i_max_b] = temp;
	}
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
	display_stacks(data);
}
