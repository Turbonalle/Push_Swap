/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:08:34 by jbagger           #+#    #+#             */
/*   Updated: 2023/01/12 15:56:36 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_list(t_list *data, int size)
{
	data->stack_a = malloc(sizeof(int) * (size));
	if (!(data->stack_a))
	{
		write(1, "Malloc failed!\n", 15);
		return (0);
	}
	data->stack_b = malloc(sizeof(int) * (size));
	if (!data->stack_b)
	{
		write(1, "Malloc failed!\n", 15);
		return (0);
	}
	data->i_max_a = size - 1;
	while (size >= 0)
	{
		data->stack_b[size] = 0;
		size--;
	}
	data->i_max_b = -1;
	data->moves = 0;
	return (1);
}
