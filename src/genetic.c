#include "../includes/push_swap.h"

float	fitness(t_stacks *s, t_op *coms, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		do_print_op(coms[i], s);
		i++;
	}
	return (sortedness(s, it));
}
