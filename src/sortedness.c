
#include "../includes/push_swap.h"
#include <stdio.h>

int				find_lowest_sub(int	*stack, int used, int a)
{
	int	i;
	int	min;
	int	pos;

	i = -1;
	min = INT_MAX;
	pos = 0;
	while (++i <= used)
	{
		if (min > stack[i])
		{
			min = stack[i];
			pos = i;
		}
	}
	if (pos == 0 && stack[used] == min && a)
		return (used);
	return (pos);
}

int				rel_iterator_pos(t_stacks *stacks, int i)
{	
	int		pos;
	int		posa;
	int		posb;
	int		*stack;

	posa = find_lowest_sub(stacks->a, stacks->a_used, 1);
	posb = find_lowest_sub(stacks->b, stacks->b_used, 0);
	if (i < stacks->size)
	{
		if (i <= stacks->a_used)
		{
			if (posa + i > stacks->a_used)
				pos = posa + (i - (stacks->a_used + 1));
			else 
				pos = posa + i;
			stack = stacks->a;
			return (pos);
		}
		else
		{
			if (posb - (i - (stacks->a_used + 1)) > -1) 
				pos = posb - (i - (stacks->a_used + 1));
			else
				pos = (posb + stacks->b_used + 1) - (i - (stacks->a_used + 1));
			stack = stacks->b;
			return (pos + stacks->a_used + 1);
		}
	}
	return (INT_MIN);
}


int				*rel_iterator(t_stacks *stacks, int i)
{	
	int		pos;
	int		posa;
	int		posb;
	int		*stack;

	posa = find_lowest_sub(stacks->a, stacks->a_used, 1);
	posb = find_lowest_sub(stacks->b, stacks->b_used, 0);
	if (i < stacks->size)
	{
		if (i <= stacks->a_used)
		{
			if (posa + i > stacks->a_used)
				pos = posa + (i - (stacks->a_used + 1));
			else 
				pos = posa + i;
			stack = stacks->a;
		}
		else
		{
			if (posb - (i - (stacks->a_used + 1)) > -1) 
				pos = posb - (i - (stacks->a_used + 1));
			else
				pos = (posb + stacks->b_used + 1) - (i - (stacks->a_used + 1));
			stack = stacks->b;
		}
		return (&stack[pos]);
	}
	return (NULL);
}

int				global_number_dist(t_stacks *stacks, int val, int i)
{
	int		j;
	int		pos;
	int		doubles;
	int		distleft;
	int		distright;

	j = -1;
	pos = 0;
	doubles = 0;
	while (++j < stacks->size)
	{
		if (val > *rel_iterator(stacks, j))
			pos++;
		if (i != j && val == *rel_iterator(stacks, j))
			doubles++;
	}
	distleft = i > pos ? i - pos : pos - i;
	distright = i > pos ? stacks->size - i + pos : (stacks->size - pos) + i;
	if (i >= pos && i <= pos + doubles)
	{
		distleft = 0;
		distright = 0;
	}
	return (distleft < distright ? distleft : distright );
}

int				dist_inv_b(t_stacks *stacks)
{
	int		i;
	int		*val1;
	int		*val2;
	int		tmp;
	int		score;
	int		newscore;
	int		pos;
	int		posb;

	i = -1;
	while (++i < stacks->b_used)
	{
		val1 = rel_iterator(stacks, i + stacks->a_used + 1);
		val2 = rel_iterator(stacks, i + stacks->a_used + 2);
		if (*val1 > *val2)
		{
			score = global_number_dist(stacks, *val1, i + stacks->a_used + 1); 
			score += global_number_dist(stacks, *val2, i + stacks->a_used + 2);
			tmp = *val1;
			*val1 = *val2;
			*val2 = tmp;
			newscore = global_number_dist(stacks, *val1, i + stacks->a_used + 1);
			newscore += global_number_dist(stacks, *val2, i + stacks->a_used + 2);
			tmp = *val1;
			*val1 = *val2;
			*val2 = tmp;
			if (newscore < score)
				pos = rel_iterator_pos(stacks, i + stacks->a_used + 1);
		}
	}
	posb = pos - (stacks->a_used + 1);
	posb = posb < (stacks->b_used + 1) / 2 ? stacks->b_used - (posb + 1) : posb + 1;
	if (posb < 0)
		posb *= -1;
	ft_putstr("\nposb = ");
	ft_putnbr(posb);
	ft_putstr("\n");
	return(posb);
}

int				dist_inv_a(t_stacks *stacks)
{ 
	int		i;
	int		*val1;
	int		*val2;
	int		tmp;
	int		score;
	int		newscore;
	int		pos;

	i = -1;
	while (++i < stacks->a_used)
	{
		val1 = rel_iterator(stacks, i);
		val2 = rel_iterator(stacks, i + 1);
		if (*val1 > *val2)
		{
			score = global_number_dist(stacks, *val1, i); 
			score += global_number_dist(stacks, *val2, i + 1);
			tmp = *val1;
			*val1 = *val2;
			*val2 = tmp;
			newscore = global_number_dist(stacks, *val1, i);
			newscore += global_number_dist(stacks, *val2, i + 1);
			tmp = *val1;
			*val1 = *val2;
			*val2 = tmp;
			if (newscore < score)
				pos = rel_iterator_pos(stacks, i);
		}
	}
	ft_putstr("\npos = ");
	ft_putnbr(pos);
	ft_putstr("\n");
	pos = pos < (stacks->a_used + 1) / 2 ? pos + 2 : stacks->a_used - (pos + 1);
	return (pos < 0 ? pos * -1 : pos);
}

int				dist_to_closest_inv(t_stacks *stacks)
{
	int		i;
	int		pos;
	int		closest;
	int		dist;
	int		val1;
	int		val2;
	int		val3;
	int		val4;

	i = -1;
	closest = INT_MAX;
	while (++i < stacks->size - 3)
	{
		val1 = *rel_iterator(stacks, i);
		val2 = *rel_iterator(stacks, i + 1);
		val3 = *rel_iterator(stacks, i + 2);
		val4 = *rel_iterator(stacks, i + 3);
		if (val2 > val3 && val2 <= val4 && val1 <= val3)
		{
			pos = rel_iterator_pos(stacks, i + 2);
			dist = stacks->a_used >= pos ? stacks->a_used - pos : (stacks->b_used -1) - ((pos - stacks->a_used) - 1) ;
			if (dist < 0)
				dist *= -1;
			if (closest > dist)
			{
				closest = dist;
				ft_putnbr(val2);
				ft_putstr(" ");
				ft_putnbr(val3);
				ft_putstr("\n");
			}
		}
	}
	return (closest);
}


void			print_global(t_stacks *stacks)
{
	int i;

	i = 0;
	ft_putstr("\t");
	while (i < stacks->size)
	{
		ft_putnbr(*rel_iterator(stacks, i));
		if (i == stacks->a_used)
		{
			ft_putstr(" | ");
		}
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");

}

int				*iterator(t_stacks *stacks, int i)
{	
	int		pos;
	int		*stack;

	if (i < stacks->size)
	{
		if (i <= stacks->a_used)
		{
			pos	= i;
			stack = stacks->a;
		}
		else
		{
			pos = stacks->b_used - (i - stacks->a_used);
			stack = stacks->b;
		}
		return (&stack[pos]);
	}
	return (NULL);
}

int				*circle_iterator(t_stacks *stacks, int i, int start_pos)
{
	int		*val;
	while ((val = iterator(stacks, start_pos + i)) == NULL)
		i -= stacks->size;
	return (val);
}

int				find_lowest(t_stacks *stacks)
{
	int		i;
	int		*val;
	int		pos;
	int		smallest;

	i = -1;
	smallest = INT_MAX;
	while ((val = iterator(stacks, ++i)) != NULL)
	{
		if (smallest > *val)
		{
			smallest = *val;
			pos = i;
		}
	}
	return (pos);
}

int				global_rel_ins_index(t_stacks *stacks)
{
	int		i;
	int		j;
	int		*val;
	int		old_lis;
	int		lis;

	old_lis = INT_MIN;
	lis = 0;
	i = -1;
	while ((++i < stacks->size && (val = rel_iterator(stacks, i))))
	{
		j = i;
		while (++j < stacks->size -1)
		{
			if (*val < *rel_iterator(stacks, j))
				lis++;
		}
		if (lis > old_lis)
			old_lis = lis;
		lis = 0;
	}
	return (stacks->size - 1 - old_lis);
}

int				global_ins_index(t_stacks *stacks)
{	int		i;
	int		j;
	int		*val;
	int		old_lis;
	int		lis;

	lis = 0;
	i = -1;
	while ((val = iterator(stacks, ++i)))
	{
		j = i;
		while (++j < stacks->size -1)
		{
			if (*val < *iterator(stacks, j))
				lis++;
		}
		if (lis > old_lis)
			old_lis = lis;
		lis = 0;
	}
	return (stacks->size - 1 - old_lis);



}

int				global_real_dist(t_stacks *stacks)
{
	int		i;
	int		j;
	int		*val;
	int		pos;
	int		distleft;
	int		distright;
	int		dist;

	pos = 0;
	dist = 0;
	i = -1;
	while ((val = iterator(stacks, ++i)))
	{
		j = -1;
		while (++j < stacks->size -1)
		{
			if (*val > *iterator(stacks, j))
				pos++;
		}
		distleft = i > pos ? i - pos : pos - i;
		distright = i > pos ? stacks->size - i + pos : (stacks->size - pos) + i;
		dist += distleft < distright ? distleft : distright;
		pos = 0;
	}
	return (dist);

}


int				global_dist(t_stacks *stacks)
{
	int		i;
	int		*val;
	int		dist;

	dist = 0;
	i = -1;
	while(++i < stacks->size - 1 && (val = rel_iterator(stacks, i)))
		dist += global_number_dist(stacks, *val, i);
	print_global(stacks);
	return (dist);
}

static int		invs(int *stack, int used)
{
	int	i;
	int	j;
	int	invs;

	i = 0;
	j = 1;
	invs = 0;
	while (i < used)
	{
		j = i;
		while (j + 1 <= used && stack[i] > stack[j + 1])
			j++;
		if (j > i)
			invs += j - i;
		i++;
	}	
	return (invs);
}

static int		sorted(int *stack, int used)
{
	int		i;

	i = 0;
	while (i < used)
	{
		if (stack[i] > stack[i + 1])
			break;
		i++;
	}
	if (i == used)
		return (1);
	else
		return (0);
}

static int		inv_sorted(int *stack, int used)
{
	int i;

	i = 0;
	while (i < used)
	{
		if (stack[i] < stack[i + 1])
			break;
		i++;
	}
	if (i == used)
		return (1);
	else
		return (0);
}

static int		inv_out_of_place(int *stack, int used)
{
	int	i;
	int	out_of_place;

	i = 0;
	out_of_place = 0;
	while (i < used)
	{
		if (stack[i] < stack[i + 1])
			out_of_place++;
		i++;
	}	
	return (out_of_place);
}

static int		out_of_place(int *stack, int used)
{
	int	i;
	int	out_of_place;

	i = 0;
	out_of_place = 0;
	while (i < used)
	{
		if (stack[i] > stack[i + 1])
			out_of_place++;
		i++;
	}	
	return (out_of_place);
}

static int		adj_invs(int *stack, int used)
{
	int	i;
	int	adj_invs;

	i = 0;
	adj_invs = 0;
	while (i <= used)
	{
		if (stack[i] > stack[i + 1])
		{
			if (i + 1 <= used && stack[i] < stack[i + 2])
				adj_invs++;
		}
		i++;
	}	
	return (adj_invs);

}

static int		rev_invs(int *stack, int used)
{
	int	i;
	int	j;
	int	invs;

	i = 0;
	j = 1;
	invs = 0;
	while (i < used)
	{
		j = i;
		while (j + 1 <= used && stack[i] < stack[j + 1])
			j++;
		if (j > i)
			invs += j - i;
		i++;
	}	
	return (invs);
}

static int	inv_rec_helper(int *stack, int used, int pos, int start)
{
	int	i;
	int	max_for_number;
	int	old_max_for_number;

	if (pos < start)
		used = start;
	i = pos + 1;
	max_for_number = 0;
	old_max_for_number = -1;
	while (i <= used)
	{
		if (stack[pos] >= stack[i])
		{
			if ((max_for_number = inv_rec_helper(stack, used, i, start)) > old_max_for_number)
				old_max_for_number = max_for_number;
		}
		i++;
		if (used != start && i == used)
		{
			i = 0;
			used = start;
		}
	}
	return (old_max_for_number + 1);
}

static int	inv_rec_lis(int *stack, int used)
{
	int	max_for_number;
	int	old_max_for_number;
	int	pos;

	pos = 0;
	max_for_number = 0;
	old_max_for_number = -1;
	while(pos < used)
	{
		max_for_number = inv_rec_helper(stack, used, pos, pos);
		if (max_for_number > old_max_for_number)
			old_max_for_number = max_for_number;
		pos++;
	}
	return (old_max_for_number);
}

static int	rec_helper(int *stack, int used, int pos, int start)
{
	int	i;
	int	max_for_number;
	int	old_max_for_number;

	if (pos < start)
		used = start;
	i = pos + 1;
	max_for_number = 0;
	old_max_for_number = -1;
	while (i <= used)
	{
		if (stack[pos] <= stack[i])
		{
			if ((max_for_number = rec_helper(stack, used, i, start)) > old_max_for_number)
				old_max_for_number = max_for_number;
		}
		i++;
		if (used != start && i == used)
		{
			i = 0;
			used = start;
		}
	}
	return (old_max_for_number + 1);
}

static int	rec_lis(int *stack, int used)
{
	int	max_for_number;
	int	old_max_for_number;
	int	pos;

	pos = 0;
	max_for_number = 0;
	old_max_for_number = -1;
	while(pos < used)
	{
		max_for_number = rec_helper(stack, used, pos, pos);
		if (max_for_number > old_max_for_number)
			old_max_for_number = max_for_number;
		pos++;
	}
	return (old_max_for_number);
}

int		lowest(int *stack, int used)
{
	int		i;
	int		lowest;

	lowest = INT_MAX;
	i = -1;
	while (++i <= used)
	{
		if (lowest > stack[i])
			lowest = stack[i];	
	}
	return (lowest);
}

int		highest(int *stack, int used)
{
	int		i;
	int		highest;

	highest = INT_MIN;
	i = -1;
	while (++i <= used)
	{
		if (highest < stack[i])
			highest = stack[i];	
	}
	return (highest);
}

int		num_big_piv(int *stack, int used, int piv)
{
	int score;
	int	i;

	i = -1;
	score = 0;
	while (++i <= used)
	{
		if (stack[i] > piv)
			score++;	
	}
	return (score);
}

int		num_small_piv(int *stack, int used, int piv)
{
	int score;
	int	i;

	i = -1;
	score = 0;
	while (++i <= used)
	{
		if (stack[i] <= piv)
			score++;	
	}
	return (score);
}

int		low_dist_to_used(int *stack, int used, int piv)
{
	int		score;
	int		i;
	int		pos;

	score = 0;
	pos = -1;
	i = used / 2;
	while (++i <= used)
	{
		if (stack[i] < piv)
			pos = i;
	}
	score = used - pos;
	i = used / 2 + 1;
	while (--i >= 0)
	{
		if (stack[i] > piv)
			pos = i;
	}
	return (pos < score ? pos : score);

}

int		high_dist_to_used(int *stack, int used, int piv)
{
	int		score;
	int	i;
	int		pos;

	score = 0;
	pos = -1;
	i = used / 2;
	while (++i <= used)
	{
		if (stack[i] > piv)
			pos = i;
	}
	score = used - pos;
	i = used / 2 + 1;
	while (--i >= 0)
	{
		if (stack[i] > piv)
			pos = i;
	}
	return (pos < score ? pos : score);
}

int		highest_dist_to_used(int *stack, int used,int highest)
{
	int		score;
	int	i;
	int		pos;

	score = 0;
	pos = -1;
	i = used / 2;
	while (++i <= used)
	{
		if (stack[i] == highest)
			pos = i;
	}
	score = used - pos;
	i = used / 2 + 1;
	while (--i >= 0)
	{
		if (stack[i] == highest)
			pos = i;
	}
	return (pos < score ? pos : score);
}

t_sort	sortedness(int *stack, int used, int piv)
{
	t_sort	s;

	s.sorted = sorted(stack, used);
	s.inv_sorted = inv_sorted(stack, used);
	s.out_of_place = out_of_place(stack, used);
	s.inv_out_of_place = inv_out_of_place(stack, used);
	s.adj_invs = adj_invs(stack, used);
	s.invs = invs(stack, used);
	s.rev_invs = rev_invs(stack, used);
	s.ins_index = (used) - rec_lis(stack, used);
	s.inv_ins_index = (used) - inv_rec_lis(stack, used);
	if (s.ins_index == -1)
		s.ins_index = 0;
	s.highest = highest(stack, used); 
	s.lowest = lowest(stack, used);
	s.num_big_piv = num_big_piv(stack, used, piv);
	s.num_small_piv = num_small_piv(stack, used, piv);
	s.highest_dis = highest_dist_to_used(stack, used, s.highest);
	s.low_dis = low_dist_to_used(stack, used, s.lowest);
	s.lowest_dis = highest_dist_to_used(stack, used, s.lowest);
	s.high_dis = high_dist_to_used(stack, used, piv);
	s.used = used;
	return (s);
}
