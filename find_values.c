/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:08:32 by jbagger           #+#    #+#             */
/*   Updated: 2023/01/06 13:12:38 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value(t_list *data, char c)
{
	int	i;
	int	max;
	int *stack;

	if (c == 'a')
	{
		stack = data->stack_a;
		i = data->i_max_a;
	}
	else
	{
		stack = data->stack_b;
		i = data->i_max_b;
	}
	max = stack[i];
	while (--i >= 0)
	{
		if (max < stack[i])
			max = stack[i];
	}


	// if (c == 'a')
	// {
	// 	i = data->i_max_a;
	// 	max = data->stack_a[i];
	// 	while (--i >= 0)
	// 	{
	// 		if (max < data->stack_a[i])
	// 			max = data->stack_a[i];
	// 	}
	// }
	// if (c == 'b')
	// {
	// 	i = data->i_max_b;
	// 	max = data->stack_b[i];
	// 	while (--i >= 0)
	// 	{
	// 		if (max < data->stack_b[i])
	// 			max = data->stack_b[i];
	// 	}
	// }
	return (max);
}

int	min_value(t_list *data)
{
	int	i;
	int	min;

	i = data->i_max_a;
	min = data->stack_a[i];
	while (--i >= 0)
	{
		if (min > data->stack_a[i])
			min = data->stack_a[i];
	}
	return (min);
}

int	find_index_of_max_value(t_list *data)
{
	int	max_value_index;
	int	i;

	max_value_index = 0;
	i = -1;
	while (++i < (data->i_max_a + 1))
	{
		if (data->stack_a[max_value_index] < data->stack_a[i])
			max_value_index = i;
	}
	return (max_value_index);
}

int	find_index_of_min_value(t_list *data, char c)
{
	int	min_value_index;
	int *stack;
	int	i;

	if (c == 'a')
	{
		stack = data->stack_a;
	}
	else
	{
		stack = data->stack_b;
		
	}
	min_value_index = 0;
	i = -1;
	while (++i < (data->i_max_a + 1))
	{
		if (stack[min_value_index] > stack[i])
			min_value_index = i;
	}
	return (min_value_index);
}

int	index_to_push(t_list *data)
{
	int	least_steps;
	int	steps;
	int	index;
	int	i;

	least_steps = count_steps(data, data->i_max_a);
	index = data->i_max_a;
	i = index;
	while (--i > -1 && least_steps > 1)
	{
		steps = count_steps(data, i);
		if (least_steps > steps)
		{
			least_steps = steps;
			index = i;
		}
	}
	return (index);
}
