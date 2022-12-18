#include "../libft/libft.h"
#include <stdio.h>



void display(t_list *stack)
{
	t_list	*current;
	int		*data;

	current = stack;
	if (stack == NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	while (current != NULL)
	{
		data = current->content;
		printf("%d ", *data);
		current = current->next;
	}
	printf("\n");
}

int main(int ac, char *av[])
{
	t_list *a_stack;
	int *ptr_data;
	int i;

	ptr_data = NULL;
	if (ac > 1)
	{
		i = 0;
		while (av[++i])
		{
			*ptr_data = ft_atoi(av[i]);
			ft_lstadd_back(&a_stack, ft_lstnew(ptr_data));
		}
		display(a_stack);
	}
	return (0);
}