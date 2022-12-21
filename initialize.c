#include "push_swap.h"

//----CREATING STACKS----------------------------------------------------------- OK!

int *init_aa(int *aa)
{
	aa = malloc(sizeof(int));
	aa[0] = 0;
	return (aa);
}

int *init_bb(int *bb, int i)
{
	i++;
	bb = malloc(i * sizeof(int));
	while (i >= 0)
	{
		bb[i] = 0;
		i--;
	}
	return (bb);
}

int *create_aa(int *ptr, int n, int len)
{
	int *stack;
	int i;
	
	stack = malloc((len + 1) * sizeof(int));
	if (!stack)
	{
		printf("Malloc failed!\n");
		return (0);
	}
	stack[len] = 0;
	i = -1;
	while (ptr[++i])
		stack[i + 1] = ptr[i];
	stack[0] = n;
	free(ptr);
	return (stack);
}

void display_stack(int *stack)
{
	int i;

	i = max_index(stack);
	while (i > -1)
		printf("stack[%d] = %d\n", i, stack[i]);
	printf("\n");
}

void display_stacks(int *aa, int *bb)
{
	int i;
	int size;

	size = max_index(aa);
	i = size;
	size = max_index(bb);
	if (i < size)
		i = size;
	i++;
	while (--i > -1)
		printf("aa[%d] = %d\tbb[%d] = %d\n", i, aa[i], i, bb[i]);
	printf("\n");
}