#include "push_swap.h"

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