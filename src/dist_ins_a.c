
#include "../includes/push_swap.h"


int	calc_dist_a(int i, int pos, int used, int doubles)
{
	int		dist_inner;
	int		dist_outer;
	int		dist;

	dist = 0;
	dist_inner = 0;
	dist_outer = 0;
	if (i < pos)
	{
		dist_inner = ((pos - i) * -1) + 1;
		dist_outer = ((used - pos) + i);
	}
	if (i > doubles + pos)
	{
		dist_inner = (i - (pos + doubles)) + 1;
		dist_outer = (((used - i) + pos) * -1) + 1;
	}
	dist = abs(dist_inner) < abs(dist_outer) ? dist_inner : dist_outer;
	return (dist);
}

int				find_lowest_sub_a(t_layer	*stack, int used)
{
	int	i;
	int	min;
	int	pos;

	i = -1;
	pos = -1;
	min = INT_MAX;
	while (++i <= used)
	{
		if (min > stack[i].val && stack[i].dist == INT_MAX)
		{
			min = stack[i].val;
			pos = i;
		}
	}
	if (used > -1 && pos == 0 && stack[used].val == min)
	{
		while(stack[--used].val == min)
			;
		return (used + 1);
	}
	return (pos > -1 ? pos : 0);
}

int				find_lowest_sub_b(t_layer	*stack, int used)
{
	int	i;
	int	min;
	int	pos;

	i = used + 1;
	pos = -1;
	min = INT_MAX;
	while (--i >= 0)
	{
		if (min > stack[i].val && stack[i].dist == INT_MAX)
		{
			min = stack[i].val;
			pos = i;
		}
	}
	if (used > -1 && pos == used && stack[0].val == min)
	{
		while(stack[++i].val == min)
			;
		return (i - 1);
	}
	return (pos > -1 ? pos : 0);
}

static int	dist_right_a(t_layer *stack, int used, int start_pos)
{
	int		i;
	int		pos;
	int		dist;

	i = -1;
	pos = INT_MAX;
	dist = 0;
	while (++i <= used / 2)
	{
		if (stack[i].pos > used)
			continue;
		pos = stack[i].pos + start_pos;
		pos = pos > used ? (pos - used) - 1 : pos;
		dist = calc_dist_a(i, pos, used, stack[i].doubles);	
		if (abs(dist) > 3)
		{
			stack[i].dist = dist;
			return (i + 1);
		}
	}
	return (INT_MAX);
}

static int	dist_left_a(t_layer *stack, int used, int start_pos)
{
	int		i;
	int		pos;
	int		dist;

	i = used + 1;
	pos = INT_MAX;
	dist = 0;
	while (--i > used / 2)
	{
		if (stack[i].pos > used)
			continue;
		pos = stack[i].pos + start_pos;
		pos = pos > used ? (pos - used) - 1 : pos;
		dist = calc_dist_a(i, pos, used, stack[i].doubles);	
		if (abs(dist) > 3)
		{
			stack[i].dist = dist;
			return (used - i);
		}
	}
	return (INT_MAX);
}

int		dist_closest_ins_num_a(t_layer *stack, int used, int start_pos)
{
	int		distleft;
	int		distright;

	distleft = dist_left_a(stack, used, start_pos);
	distright = dist_right_a(stack, used, start_pos);
	if (distleft == INT_MAX && distright == INT_MAX)
		return (0);
	return (distleft < distright ? distleft : -distright);
}


