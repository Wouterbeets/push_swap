
#include "../includes/push_swap.h"

int		check_otherway(int dist, int used)
{
	if (dist < 0)
	{
		if (abs(dist) > (used + 1) / 2)
			dist += used + 1;
	}
	else
	{
		if (dist > (used + 1) / 2)
			dist -= used + 1;
	}
	return (dist);
}

int		nums_smaller_piv_range(t_stacks *stacks, int i, int end)
{
	int	smalls;
	t_layer		*val;

	smalls = 0;
	while (i <= end)
	{
		val = rel_iterator_t(stacks, i);
		if (val->val <= stacks->piv.num)
			smalls++;
		i++;
	}
	return (smalls);
}

int		nums_bigger_piv_range(t_stacks *stacks, int i, int end)
{
	int	bigs;
	t_layer		*val;

	bigs = 0;
	while (i <= end)
	{
		val = rel_iterator_t(stacks, i);
		if (val->val > stacks->piv.num)
			bigs++;
		i++;
	}
	return (bigs);
}

int		check_higer(t_stacks *stacks,int i, int rel_pos, int rel_pos2)
{
	t_layer	*val;
	int		low_pos;

	low_pos = i;
	while (i < stacks->size)
	{
		val = rel_iterator_t(stacks, ++i);
		if (val->dist == 0)
		{
			if (val->rel_pos > rel_pos)
				return (low_pos + 1);
			else
				low_pos = i;
				
		}
	}
	return (rel_pos2);
}

int		check_for_dist_zero_b(t_stacks *stacks, int rel_pos)
{
	int		i;
	int		rel_pos2;
	t_layer	*val;

	i = rel_pos + 1 + stacks->sness.num_big_piv;
	while (i > 0)
	{
		val = rel_iterator_t(stacks, --i);
		if (val->dist == 0)
		{
			if (val->rel_pos <= rel_pos)
			{
				i -= stacks->sness.num_big_piv;
				rel_pos2 = i + (rel_pos - val->rel_pos);
				rel_pos2 += nums_smaller_piv_range(stacks, i , rel_pos);
				return (check_higer(stacks, i, rel_pos, rel_pos2));
			}
		}
	}
	return (rel_pos);
}

int		check_for_dist_zero_a(t_stacks *stacks, int rel_pos)
{
	int		i;
	t_layer	*val;
	int		rel_pos2;

	i = rel_pos + 1;
	while (i > 0)
	{
		val = rel_iterator_t(stacks, --i);
		if (val->dist == 0)
		{
			if (val->rel_pos <= rel_pos)
			{
				rel_pos2 = i + (rel_pos - val->rel_pos);
				rel_pos2 += nums_bigger_piv_range(stacks, i ,rel_pos);
				return (check_higer(stacks, i, rel_pos, rel_pos2));
			}
		}
	}
	return (rel_pos);
}

int		calc_ins_dis(t_layer val, t_stacks *stacks, int i)
{
	int	dist_inner;
	int	rel_pos_in;
	int	rel_pos_out;

	rel_pos_in = val.rel_pos;
	rel_pos_in = check_for_dist_zero_a(stacks, rel_pos_in);
	if (rel_pos_in > stacks->a_used)
		rel_pos_in = stacks->a_used + 1;
	rel_pos_out = rel_pos_in + val.doubles;
	if (i != -1)
	{
		if (i < stacks->a_start)
			i += stacks->a_used - stacks->a_start;
		else
			i -= stacks->a_start;
		if (i > rel_pos_in && i < rel_pos_out)
			return (0);
		rel_pos_out = i - rel_pos_out;
		rel_pos_out = check_otherway(rel_pos_out, stacks->a_used);
		rel_pos_in = i - rel_pos_in;
		rel_pos_in = check_otherway(rel_pos_in, stacks->a_used);
		return (abs(rel_pos_in) > abs(rel_pos_out) ? rel_pos_out : rel_pos_in);
	}
	dist_inner = stacks->a_used - (stacks->a_start + rel_pos_in);
	dist_inner++;
	dist_inner = check_otherway(dist_inner, stacks->a_used);
	return ( dist_inner);
}

int		calc_ins_dis_b(t_layer val, t_stacks *stacks, int i)
{
	int	start_pos;
	int	rel_pos_in;
	int	rel_pos_out;
	int	dist_inner;

	rel_pos_in = val.rel_pos;
	rel_pos_in = check_for_dist_zero_b(stacks, rel_pos_in);
	rel_pos_in -= stacks->a_used + 1;
	if (rel_pos_in > stacks->b_used)
		rel_pos_in = stacks->b_used + 1;
	rel_pos_out = rel_pos_in + val.doubles;
	start_pos = stacks->b_start + 1;
	if (i != -1)
	{
		if (i < stacks->b_start)
			i = stacks->b_start - i;
		else
			i = (stacks->b_used - i) + stacks->b_start;
		if (i > rel_pos_in && i < rel_pos_out)
			return (0);
		rel_pos_out = i - rel_pos_out;
		rel_pos_in = i - rel_pos_in;
		return (abs(rel_pos_in) > abs(rel_pos_out) ? rel_pos_out : rel_pos_in);
	}
	dist_inner = (start_pos - rel_pos_in) * -1;
	dist_inner = check_otherway(dist_inner, stacks->b_used);
	return (dist_inner);
}
