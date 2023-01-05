/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:09:01 by jbagger           #+#    #+#             */
/*   Updated: 2023/01/05 13:12:13 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_up_b_up(t_list *data, int index_a, int index_b)
{
	while (index_a < data->i_max_a && index_b < data->i_max_b)
	{
		rotate(data, 'r');
		index_a++;
		index_b++;
	}
	while (index_a < data->i_max_a)
	{
		rotate(data, 'a');
		index_a++;
	}
	while (index_b < data->i_max_b)
	{
		rotate(data, 'b');
		index_b++;
	}
}

void	a_up_b_down(t_list *data, int index_a, int index_b)
{
	while (index_a < data->i_max_a)
	{
		rotate(data, 'a');
		index_a++;
	}
	while (index_b > -1)
	{
		reverse(data, 'b');
		index_b--;
	}
}

void	a_down_b_up(t_list *data, int index_a, int index_b)
{
	while (index_a > -1)
	{
		reverse(data, 'a');
		index_a--;
	}
	while (index_b < data->i_max_b)
	{
		rotate(data, 'b');
		index_b++;
	}
}

void	a_down_b_down(t_list *data, int index_a, int index_b)
{
	while (index_a > -1 && index_b > -1)
	{
		reverse(data, 'r');
		index_a--;
		index_b--;
	}
	while (index_a > -1)
	{
		reverse(data, 'a');
		index_a--;
	}
	while (index_b > -1)
	{
		reverse(data, 'b');
		index_b--;
	}
}
