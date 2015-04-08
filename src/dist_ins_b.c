
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
	while (++i <= used)
	{
		if (stack[i].pos == lowest)
		{
			ft_putnbr(stack[i].val);
			ft_putstr(" ");
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

int	calc_dist_b(int i, int pos, int used, int doubles)
{
	int		dist_inner;
	int		dist_outer;
	int		dist;

	dist = 0;
	dist_inner = 0;
	dist_outer = 0;
	if (i < pos)
	{
		dist_inner = ((pos - i)) * -1;
		dist_outer = ((used - pos) + i);
	}
	if (i > doubles + pos)
	{
		dist_inner = (i - (pos + doubles));
		dist_outer = ((((used - i) + pos)) * -1) - 1;//good for sure
	}
	dist = abs(dist_inner) < abs(dist_outer) ? dist_inner : dist_outer;
	return (dist);
}

static int	dist_right_b(t_layer *stack, int b_used, int a_used, int start_pos)
{
	int		i;
	int		pos;
	int		dist;

	i = -1;
	pos = INT_MAX;
	dist = 0;
	while (++i <= b_used / 2)
	{
		if (stack[i].pos <= a_used)
			continue;
		pos = (((stack[i].pos - (a_used + 1)) * -1) + b_used) - (b_used - start_pos);
		pos = pos < 0 ? pos + b_used : pos;
		dist = calc_dist_b(i, pos, b_used, stack[i].doubles);	
		if (abs(dist) > 3)
		{
			stack[i].dist = dist;
			return (i + 1);
		}
	}
	return (INT_MAX);


}

static int	dist_left_b(t_layer *stack, int b_used, int a_used, int start_pos)
{
	int		i;
	int		pos;
	int		dist;

	i = b_used + 1;
	pos = INT_MAX;
	dist = 0;
	while (--i > b_used / 2)
	{
		if (stack[i].pos <= a_used)
			continue;
		pos = (((stack[i].pos - (a_used + 1)) * -1) + b_used) - (b_used - start_pos);
		pos = pos < 0 ? pos + b_used : pos;
		dist = calc_dist_b(i, pos, b_used, stack[i].doubles);	
		if (abs(dist) > 3)
		{
			stack[i].dist = dist;
			return (b_used - i);
		}
		i--;
	}
	return (INT_MAX);
}

int		dist_closest_ins_num_b(t_layer *stack, int b_used, int a_used, int start_pos)
{
	int		distleft;
	int		distright;
	
	distleft = dist_left_b(stack, b_used, a_used, start_pos);
	distright = dist_right_b(stack, b_used, a_used, start_pos);
	if (distleft == INT_MAX && distright == INT_MAX)
		return (0);
	return (distleft < distright ? distleft : -distright);
}

