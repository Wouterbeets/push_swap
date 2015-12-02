#include "../includes/push_swap.h"

static void		print_arr(t_elem *arr, int used)
{
	int	i;
	i = 0;
	while (i <= used)
	{
		ft_putnbr(arr[i].val);
		ft_putstr("|");
		ft_putnbr(arr[i].pos);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
}

void	print_stacks(t_stacks *stacks)
{
	print_arr(stacks->a, stacks->a_used);
	print_arr(stacks->b, stacks->b_used);
}

void	print_op(t_op op)
{
	static char *str[NUM_OP] = {"sa\0", "sb\0", "ss\0", "pa\0",
		"pb\0", "ra\0", "rb\0", "rr\0", "rra\0", "rrb\0", "rrr\0"};

	ft_putstr(str[op]);
	ft_putstr(" ");
}


