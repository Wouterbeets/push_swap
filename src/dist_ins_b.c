
#include "../includes/push_swap.h"

void	print_stack_sorted(t_layer *stack, int used)
{
	int		i;
	int		lowest;
	int		high_pos;

	i = -1;
	lowest = 0;
	high_pos = 0;
	while (++i <= used)
		high_pos = stack[i].pos > high_pos ? stack[i].pos : high_pos;
	i = -1;
	ft_putstr("\n");
	while (++i <= used)
	{
		if (stack[i].pos == lowest)
		{
			ft_putnbr(stack[i].val);
			ft_putstr("\n");
		}
		if (i == used && lowest != high_pos) 
		{
			i = -1;
			lowest++;
		}
	}
	ft_putstr("\n");

}

int	abs(int num)
{
	return (num > 0 ? num : num * -1);
}
//
//int	calc_dist_b(int i, int pos, int used, int doubles)
//{
//	int		dist_inner;
//	int		dist_outer;
//	int		dist;
//
//	dist = 0;
//	dist_inner = 0;
//	dist_outer = 0;
//	if (i < pos)
//	{
//		dist_inner = ((pos - i)) * -1;
//		dist_outer = ((used - pos) + i);
//	}
//	if (i > doubles + pos)
//	{
//		dist_inner = (i - (pos + doubles)) - 1;
//		dist_outer = ((((used - i) + pos)) * -1) - 1;
//	}
//	dist = abs(dist_inner) < abs(dist_outer) ? dist_inner : dist_outer;
//	return (dist);
//}

static int	dist_right_b(t_layer *stack, int b_used, int start_pos, t_stacks *stacks)
{
	int		i;
	int		dist;

	i = -1;
	dist = 0;
	(void)start_pos;
	while (++i <= b_used / 2)
	{
		if (stack[i].val <= stacks->piv.num || i == stacks->b_start || stack[i].dist == 0)
			continue;
		dist = calc_ins_dis_b(stack[i], stacks, i);
		if (abs(dist) > INS_MIN_DIST)
		{
			return (i + 1);
		}
	}
	return (INT_MAX);


}

static int	dist_left_b(t_layer *stack, int b_used, int start_pos, t_stacks *stacks)
{
	int		i;
	int		dist;

	i = b_used + 1;
	dist = 0;
	(void)start_pos;
	while (--i > b_used / 2)
	{
		if (stack[i].val <= stacks->piv.num || i == stacks->b_start || stack[i].dist == 0)
			continue;
		dist = calc_ins_dis_b(stack[i], stacks, i);
		if (abs(dist) > INS_MIN_DIST)
		{
			return (b_used - i);
		}
	}
	return (INT_MAX);
}

int		dist_closest_ins_num_b(t_stacks *stacks)
{
	int		distleft;
	int		distright;
	
	distleft = dist_left_b(stacks->b, stacks->b_used, stacks->b_start, stacks);
	distright = dist_right_b(stacks->b, stacks->b_used, stacks->b_start, stacks);
	if (distleft == INT_MAX && distright == INT_MAX)
		return (INT_MAX);
	return (distleft < distright ? distleft : -distright);
}

