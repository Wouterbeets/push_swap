
#include "../includes/push_swap.h"

void	divide_by_pivot(t_stacks *stacks)
{
	int	i;

	i = stacks->a_used;
	while (i >= 0)
	{
		if (stacks->a[stacks->a_used] <= stacks->piv.num)
			pb(stacks);
		else
			ra(stacks);
		i--;
	}
	print_stacks(stacks);
}
