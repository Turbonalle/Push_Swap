/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:52:38 by jbagger           #+#    #+#             */
/*   Updated: 2023/01/06 11:19:25 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list *data, char c)
{
	if (c == 'a' && data->i_max_a == 1 && data->stack_a[0] < data->stack_a[1])
		swap(data, 'a');
	if (c == 'b' && data->i_max_b == 1 && data->stack_b[0] > data->stack_b[1])
		swap(data, 'b');
}

void	sort_three(t_list *data)
{
	if (order(data) && data->stack_a[data->i_max_a] == min_value(data))
		return ;
	if (!order(data))
		swap(data, 'a');
	if (data->stack_a[0] == min_value(data))
		reverse(data, 'a');
	if (data->stack_a[data->i_max_a] == max_value(data, 'a'))
		rotate(data, 'a');
}

void	sort_manual(t_list *data)
{
	if (data->i_max_a == 1)
		sort_two(data, 'a');
	else if (data->i_max_a == 2)
		sort_three(data);
}

void	make_stack_descending(t_list *data)
{
	if (order(data) && data->stack_a[data->i_max_a] == min_value(data))
		return ;
	if (!order(data))
		swap(data, 'a');
	if (order(data))
		return ;
	if (data->stack_a[0] == min_value(data))
		reverse(data, 'a');
	if (data->stack_a[data->i_max_a] == max_value(data, 'a'))
		rotate(data, 'a');
}

void	shift_a(t_list *data, int index)
{
	if ((data->i_max_a - index) <= (index + 1))
	{
		while (index++ < data->i_max_a)
			rotate(data, 'a');
	}
	else
	{
		while (index-- >= 0)
			reverse(data, 'a');
	}
}
