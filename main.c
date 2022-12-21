#include "push_swap.h"
#include <stdio.h>

//----MAIN----------------------------------------------------------------------

int main(int ac, char *av[])
{
	static int *aa;
	static int *bb;
	int i;

	if (ac < 2)
		return (0);
	i = 0;
	aa = init_aa(aa);
	while (av[++i])
		aa = create_aa(aa, atoi(av[i]), i);
	bb = init_bb(bb, i);

	printf("\n----------------------------------\n\nINITIAL STACKS!\n\n");
	display_stacks(aa, bb);
	
	//test_sort_max_3(aa, bb);
	//test_commands(aa, bb);
	
	turk_sort(aa, bb);
	
	//display_stacks(aa, bb);
	return (0);
}