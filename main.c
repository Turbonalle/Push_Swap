/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:08:44 by jbagger           #+#    #+#             */
/*   Updated: 2023/01/11 16:02:57 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

int	main(int ac, char *av[])
{
	int		i;
	int		num;
	t_list	data;

	if (ac < 2)
		return (0);
	i = 0;
	init_list(&data, ac - 1);
	while (i + 1 < ac)
	{
		if (!check_if_int(av[i + 1]) || !check_int_minmax(av[i + 1]))
			return (0);
		num = atoi(av[i + 1]);
		data.stack_a[data.i_max_a - i] = num;
		if (!check_duplicate(&data, data.i_max_a - i, num))
			return (0);
		i++;
	}
	display_stacks(&data);
	//sort_merge(&data);
	sort_merge2(&data);
	//sort_turk(&data);
	//sort_two_halves(&data);
	//sort_only_a(&data);
	//test_order(&data);
	display_stacks(&data);
	free(data.stack_a);
	free(data.stack_b);
	return (0);
}
