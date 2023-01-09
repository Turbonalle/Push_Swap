/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:08:56 by jbagger           #+#    #+#             */
/*   Updated: 2023/01/09 10:02:49 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <stdarg.h>
# include <limits.h>

# include <stdio.h>

typedef struct s_list
{
	int	*stack_a;
	int	*stack_b;
	int	i_max_a;
	int	i_max_b;
}		t_list;
typedef struct s_steps
{
	int	pos_b;
	int	rot_a;
	int	rot_b;
	int	rev_a;
	int	rev_b;
	int	rot;
	int	rev;
	int	aubd;
	int	adbu;
}		t_steps;
int		smallest(int n, ...);
int		smaller(int a, int b);
int		bigger(int a, int b);
int		max_index(t_list *data, char c);
int		max_value(t_list *data, char c);
int		min_value(t_list *data);
int		find_index_of_max_value(t_list *data, char c);
int		find_index_of_min_value(t_list *data, char c);
int		check_if_int(char *s);
int		check_int_minmax(const char *str);
int		check_duplicate(t_list *data, int i, int num);
int		init_list(t_list *data, int size);
void	swap(t_list *data, char c);
void	push(t_list *data, char c);
void	rotate(t_list *data, char c);
void	reverse(t_list *data, char c);
void	a_up_b_up(t_list *data, int index_a, int index_b);
void	a_up_b_down(t_list *data, int index_a, int index_b);
void	a_down_b_up(t_list *data, int index_a, int index_b);
void	a_down_b_down(t_list *data, int index_a, int index_b);
int		order(t_list *data);
int		rev_order(t_list *data);
void	sort_two(t_list *data, char c);
void	sort_three(t_list *data);
void	sort_manual(t_list *data);
void	find_position_in_a(t_list *data);
int		find_position_in_b(t_list *data, int value);
int		count_steps(t_list *data, int index);
int		index_to_push(t_list *data);
void	push_element(t_list *data, int index);
void	shift_a(t_list *data, int index);
void	make_stack_descending(t_list *data);
void	sort_merge(t_list *data);
void	sort_only_a(t_list *data);
void	sort_turk(t_list *data);
void	sort_two_halves(t_list *data);
void	test_commands(t_list *data);
void	test_sort_max_3(t_list *data);
void	test_order(int *stack, char c);
void	test_order_both(t_list *data);
void	display_stacks(t_list *data);

#endif
