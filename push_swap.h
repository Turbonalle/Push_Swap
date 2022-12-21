#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>

int max_index(int *stack);
int max_value(int *stack, int max_index);
int min_value(int *stack, int max_index);

int *init_aa(int *aa);
int *init_bb(int *bb, int i);
int *create_aa(int *ptr, int n, int len);
void display_stack(int *stack);
void display_stacks(int *aa, int *bb);

void swap(int *aa, int *bb, char c);
void push(int *aa, int *bb, char c);
void rotate(int *aa, int *bb, char c);
void reverse(int *aa, int *bb, char c);

int order(int *stack, int max_index);
void sort_two(int *aa, int *bb, char c);
void sort_three(int *aa, int *bb, int ia);
int rotations_to_top(int max_index, int index);
int find_position(int *stack, int max_index, int value);
int count_steps(int *aa, int *bb, int index, int ib);
int index_to_push(int *aa, int *bb, int ia, int ib);

void turk_sort(int *aa, int *bb);

void test_commands(int *aa, int *bb);
void test_sort_max_3(int *aa, int *bb);
void test_order(int *stack, char c);

#endif