/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:08:50 by jbagger           #+#    #+#             */
/*   Updated: 2023/01/05 15:23:41 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_position_in_a(t_list *data)
{
	int	min_a;
	int	max_a;
	int	pos_a;
	
	max_a = find_index_of_max_value(data);
	min_a = find_index_of_min_value(data);
	if (data->stack_b[data->i_max_b] > data->stack_a[max_a] || data->stack_b[data->i_max_b] < data->stack_a[min_a])
		pos_a = min_a;
	else
	{
		while (data->stack_b[data->i_max_b] < data->stack_a[max_a % (data->i_max_a + 1)])
			max_a = (max_a + 1) % (data->i_max_a + 1);
		if (max_a == 0)
			max_a = data->i_max_a;
		else
			max_a--;
		pos_a = max_a;
	}
	shift_a(data, pos_a);
}

int	find_position_in_b(t_list *data, int value)
{
	int	i;

	i = data->i_max_b;
	if (data->stack_b[0] > data->stack_b[i])
		return (0);
	while (value < data->stack_b[i] && i > -1)
		i--;
	if (i == -1)
		i = data->i_max_b;
	return (i);
}

int	count_steps(t_list *data, int index)
{
	t_steps	list;

	list.pos_b = find_position_in_b(data, data->stack_a[index]);
	list.rot_a = data->i_max_a - index;
	list.rot_b = data->i_max_b - list.pos_b;
	list.rev_a = index + 1;
	list.rev_b = list.pos_b + 1;
	list.rot = bigger(list.rot_a, list.rot_b);
	list.rev = bigger(list.rev_a, list.rev_b);
	list.aubd = list.rot_a + list.rev_b;
	list.adbu = list.rev_a + list.rot_b;
	return (smallest(4, list.rot, list.rev, list.aubd, list.adbu) + 1);
}

void	push_element(t_list *data, int index)
{
	t_steps	list;

	list.pos_b = find_position_in_b(data, data->stack_a[index]);
	list.rot_a = data->i_max_a - index;
	list.rot_b = data->i_max_b - list.pos_b;
	list.rev_a = index + 1;
	list.rev_b = list.pos_b + 1;
	list.rot = bigger(list.rot_a, list.rot_b);
	list.rev = bigger(list.rev_a, list.rev_b);
	list.aubd = list.rot_a + list.rev_b;
	list.adbu = list.rev_a + list.rot_b;
	if (list.rot <= list.rev && list.rot <= smaller(list.aubd, list.adbu))
		a_up_b_up(data, index, list.pos_b);
	else if (list.rev <= smaller(list.aubd, list.adbu))
		a_down_b_down(data, index, list.pos_b);
	else if (list.aubd <= list.adbu)
		a_up_b_down(data, index, list.pos_b);
	else
		a_down_b_up(data, index, list.pos_b);
	push(data, 'b');
}

void	turk_sort(t_list *data)
{
	int	i;

	if (data->i_max_a < 3)
		sort_manual(data);
	else
	{
		while (data->i_max_a > 2 && data->i_max_b < 1 && !order(data))
		{
			push(data, 'b');
		}
		sort_two(data, 'b');
		while (data->i_max_a > 2 && !order(data))
		{
			i = index_to_push(data);
			push_element(data, i);
		}
		if (data->i_max_a == 2 && !order(data))
			make_stack_descending(data);
		while (data->i_max_b >= 0)
		{
			find_position_in_a(data);
			push(data, 'a');
		}
		shift_a(data, find_index_of_min_value(data));
	}
}
