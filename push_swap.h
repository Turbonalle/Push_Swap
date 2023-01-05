#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	int		*stack_a;
	int		*stack_b;
	int		i_max_a;
	int		i_max_b;
}			t_list;

int		smallest(int n, ...);
int		smaller(int a, int b);
int		bigger(int a, int b);
int		max_index(t_list *data, char c);
int		max_value(t_list *data);
int		min_value(t_list *data);
int		find_index_of_max_value(t_list *data);
int		find_index_of_min_value(t_list *data);

int		check_if_int(char *s);
int		check_int_minmax(const char *str);
int		check_duplicate(t_list *data, int i, int num);

int		init_list(t_list *data, int size);

void	swap(t_list *data, char c);
void	push(t_list *data, char c);
void	rotate(t_list *data, char c);
void	reverse(t_list *data, char c);

void	A_up_B_up(t_list *data, int index_a, int index_b);
void	A_up_B_down(t_list *data, int index_a, int index_b);
void	A_down_B_up(t_list *data, int index_a, int index_b);
void	A_down_B_down(t_list *data, int index_a, int index_b);

int		order(t_list *data);
void	sort_two(t_list *data, char c);
void	sort_three(t_list *data);
void	find_position_in_a(t_list *data);
int		find_position_in_b(t_list *data, int value);
int		count_steps(t_list *data, int index);
int		index_to_push(t_list *data);
void	push_element(t_list *data, int index);

void	turk_sort(t_list *data);

void	test_commands(t_list *data);
void	test_sort_max_3(t_list *data);
void	test_order(int *stack, char c);
void	display_stacks(t_list *data);

#endif