
#include "../includes/push_swap.h"

static void		print_arr(t_layer *arr, int used)
{
	int	i;
	i = 0;
	while (i <= used)
	{
		ft_putnbr(arr[i].val);
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

void	print_stats(t_stacks *stacks)
{
		ft_putstr("\n---------------------------\n\t\tstats\n--------------------------------\n");
	if (stacks->ins_list_a != NULL)
	{
		ft_putstr("a_ins_dis = ");
		ft_putnbr(stacks->ins_list_a->ins_dist);
		ft_putstr("\n");
		ft_putstr("rot  = ");
		ft_putnbr(stacks->ins_list_a->rot);
		ft_putstr("\n");
	}
	if (stacks->ins_list_b != NULL)
	{
		ft_putstr("b_ins_dis = ");
		ft_putnbr(stacks->ins_list_b->ins_dist);
		ft_putstr("\n");
		ft_putstr("rot = ");
		ft_putnbr(stacks->ins_list_b->rot);
		ft_putstr("\n");
	}
}
