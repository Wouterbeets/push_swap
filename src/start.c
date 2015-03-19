#include "../includes/push_swap.h"
#include <stdio.h>

void	print_stacks(t_stacks *stacks)
{
	int		i;

	i = 0;
	while (i < stacks->size)
	{
		printf("a[%d] = %d \t b[%d] = %d\n", i, stacks->a[i],i, stacks->b[i]);
		i++;
	}
}

int		start(t_stacks *stacks)
{
	(void)stacks;
	print_stacks(stacks);
	return (0);
}


