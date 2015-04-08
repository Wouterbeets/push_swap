
#include "../includes/push_swap.h"
#include <stdio.h>

t_layer				*iterator(t_stacks *stacks, int i)
{	
	int		pos;
	t_layer		*stack;

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
int				func_fib(int loops)
{
	int		i;
	int		fib;
	int		ret;

	i = -1;
	fib = 1;
	ret = 0;
	while (++i < loops)
	{
		ret = ret + fib;
		fib += 1;	
	}	
	return (ret);
}
int				rel_iterator_pos(t_stacks *stacks, int i)
{	
	int		pos;
	int		posa;
	int		posb;
	t_layer		*stack;

	posa = stacks->a_start;
	posb = stacks->b_start;
	stack = stacks->a;
	if (i < stacks->size)
	{
		if (i <= stacks->a_used)
		{
			pos = posa + i;
			if (pos > stacks->a_used)
				pos -= stacks->a_used + 1;
			return (pos);
		}
		else
		{
			i -= stacks->a_used + 1;
			pos = posb - i;
			if (pos < 0)
				pos += stacks->b_used + 1;
			return (pos + stacks->a_used + 1);
		}
	}
	return (INT_MIN);
}

t_layer				*rel_iterator_t(t_stacks *stacks, int i)
{	
	int		pos;
	int		posa;
	int		posb;
	t_layer		*stack;

	posa = stacks->a_start;
	posb = stacks->b_start;
	stack = stacks->a;
	if (i < stacks->size)
	{
		if (i <= stacks->a_used)
		{
			pos = posa + i;
			if (pos > stacks->a_used)
				pos -= stacks->a_used + 1;
			stack = stacks->a;
		}
		else
		{
			i -= stacks->a_used + 1;
			pos = posb - i;
			if (pos < 0)
				pos += stacks->b_used + 1;
			stack = stacks->b;
		}
		return (&stack[pos]);
	}
	return (&stack[0]);
}

void			numb_final_pos(t_stacks *stacks, int i)
{
	int			j;
	t_layer		*val;
	t_layer		*val2;

	j = -1;
	val = iterator(stacks, i);
	val->pos = 0;
	val->doubles = 0;
	val->dist = INT_MAX;
	while (++j < stacks->size)
	{
		if (i != j)
		{
			val2 = iterator(stacks, j);
			if (val->val > val2->val)
				val->pos++;
			if (val->val == val2->val)
				val->doubles++;
		}
		
	}
}

void			final_posistions(t_stacks *stacks)
{
	int		i;

	i = -1;
	while (++i < stacks->size)
		numb_final_pos(stacks, i);
}


int				global_num_inv(t_stacks	*stacks)
{
	int		i;
	int		invs;
	t_layer *val1;
	t_layer *val2;

	i = -1;
	invs = 0;
	while (++i < stacks->size - 1)
	{
		val1 = rel_iterator_t(stacks, i);
		val2 = rel_iterator_t(stacks, i + 1);
		if (val1->val > val2->val)
			invs++;
	}
	return (invs);
}

int				global_number_dist(t_stacks *stacks, int i)
{
	int		dist_inner;
	int		dist_out;
	t_layer	*num;

	num = rel_iterator_t(stacks, i);
	if (i >= num->pos && i <= num->pos + num->doubles)
		return (0);
	else
	{
		dist_inner = i - num->pos;
		dist_inner *= dist_inner < 0 ? -1 : 1;
		dist_out = (stacks->size - 1) - dist_inner;
	}
	if (dist_inner > dist_out)
		return (func_fib(dist_out));
	else
		return (func_fib(dist_inner));
}

int				dist_inv_b(t_stacks *stacks)
{
	int		i;
	int		j;
	t_layer	*val1;
	t_layer	*val2;
	t_layer	tmp;
	int		score;
	int		newscore;
	int		pos;
	int		dist;
	int		closest;


	i = -1;
	pos = -1;
	closest = stacks->b_used + 1;
	while (++i < stacks->b_used)
	{
		j = i + stacks->a_used + 1;
		val1 = rel_iterator_t(stacks, j);
		val2 = rel_iterator_t(stacks, j + 1);
		if (val1->val > val2->val)
		{
			//ft_putstr("val1 ");
			//ft_putnbr(val1->val);
			//ft_putstr("\n");
			//ft_putstr("val2 ");
			//ft_putnbr(val2->val);
			//ft_putstr("\n");
			score = global_number_dist(stacks, j); 
			score += global_number_dist(stacks,j + 1); 
			//score += global_num_inv(stacks);
			//ft_putstr("score ");
			//ft_putnbr(score);
			//ft_putstr("\n");
			tmp = *val1;
			*val1 = *val2;
			*val2 = tmp;
			newscore = global_number_dist(stacks, j); 
			newscore += global_number_dist(stacks,j + 1); 
			//newscore += global_num_inv(stacks);
			//ft_putstr("ns ");
			//ft_putnbr(newscore);
			//ft_putstr("\n");
			tmp = *val1;
			*val1 = *val2;
			*val2 = tmp;
			if (newscore < score)
			{
				pos = rel_iterator_pos(stacks, j + 1);
				pos = pos - (stacks->a_used + 1);
				dist = (stacks->b_used - 1) - pos;
				dist *= dist < 0 ? -1 : 1;
				dist = pos + 2 < dist ? pos + 2 : dist;
				dist *= dist < 0 ? -1 : 1;
				closest = dist < closest ? dist : closest;
			}
		}
	}
	return(closest);
}

int				dist_inv_a(t_stacks *stacks)
{ 
	int		i;
	t_layer	*val1;
	t_layer	*val2;
	t_layer	tmp;
	int		score;
	int		newscore;
	int		pos;
	int		dist;
	int		closest;

	closest = stacks->a_used + 1;
	i = -1;
	pos = -1;
	while (++i < stacks->a_used)
	{
		val1 = rel_iterator_t(stacks, i);
		val2 = rel_iterator_t(stacks, i + 1);
		if (val1->val > val2->val)
		{
			//ft_putstr("val1 ");
			//ft_putnbr(val1->val);
			//ft_putstr("\n");
			//ft_putstr("val2 ");
			//ft_putnbr(val2->val);
			//ft_putstr("\n");
	
			score = global_number_dist(stacks, i); 
			score += global_number_dist(stacks, i + 1); 
			tmp = *val1;
			*val1 = *val2;
			*val2 = tmp;
			newscore = global_number_dist(stacks, i); 
			newscore += global_number_dist(stacks, i + 1); 
			tmp = *val1;
			*val1 = *val2;
			*val2 = tmp;
			if (newscore < score)
			{
				pos = rel_iterator_pos(stacks, i);
				dist = (stacks->a_used - 1) - pos;
				dist *= dist < 0 ? -1 : 1;
				dist = pos + 2 < dist ? pos + 2 : dist;
				dist *= dist < 0 ? -1 : 1;
				closest = dist < closest ? dist : closest;
			}
		}
	}
	return (dist);
}

//
//int				dist_to_closest_inv(t_stacks *stacks)
//{
//	int		i;
//	int		pos;
//	int		closest;
//	int		dist;
//	int		val1;
//	int		val2;
//	int		val3;
//	int		val4;
//
//	i = -1;
//	closest = INT_MAX;
//	while (++i < stacks->size - 3)
//	{
//		val1 = *rel_iterator(stacks, i);
//		val2 = *rel_iterator(stacks, i + 1);
//		val3 = *rel_iterator(stacks, i + 2);
//		val4 = *rel_iterator(stacks, i + 3);
//		if (val2 > val3 && val2 <= val4 && val1 <= val3)
//		{
//			pos = rel_iterator_pos(stacks, i + 2);
//			dist = stacks->a_used >= pos ? stacks->a_used - pos : (stacks->b_used -1) - ((pos - stacks->a_used) - 1) ;
//			if (dist < 0)
//				dist *= -1;
//			if (closest > dist)
//			{
//				closest = dist;
//				//ft_putnbr(val2);
//				//ft_putstr(" ");
//				//ft_putnbr(val3);
//				//ft_putstr("\n");
//			}
//		}
//	}
//	return (closest);
//}


void			print_global(t_stacks *stacks)
{
	int i;
	t_layer	*tmp;

	i = 0;
	while (i < stacks->size)
	{
		tmp = rel_iterator_t(stacks, i);
		ft_putnbr(tmp->val);
		if (i == stacks->a_used)
			ft_putstr(" | ");
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
	i = -1;
	while (++i < stacks->size)
	{
		tmp = rel_iterator_t(stacks, i);
		ft_putnbr(tmp->pos);
		if (i == stacks->a_used)
			ft_putstr(" | ");
		ft_putstr(" ");
	}
	ft_putstr("\n");

}

t_layer				*circle_iterator(t_stacks *stacks, int i, int start_pos)
{
	t_layer		*val;
	while ((val = iterator(stacks, start_pos + i)) == NULL)
		i -= stacks->size;
	return (val);
}

int				find_lowest(t_stacks *stacks)
{
	int		i;
	t_layer		*val;
	int		pos;
	int		smallest;

	i = -1;
	smallest = INT_MAX;
	while ((val = iterator(stacks, ++i)) != NULL)
	{
		if (smallest > val->val)
		{
			smallest = val->val;
			pos = i;
		}
	}
	return (pos);
}
//
//int				global_rel_ins_index(t_stacks *stacks)
//{
//	int		i;
//	int		j;
//	int		*val;
//	int		old_lis;
//	int		lis;
//
//	old_lis = INT_MIN;
//	lis = 0;
//	i = -1;
//	while ((++i < stacks->size && (val = rel_iterator(stacks, i))))
//	{
//		j = i;
//		while (++j < stacks->size -1)
//		{
//			if (*val < *rel_iterator(stacks, j))
//				lis++;
//		}
//		if (lis > old_lis)
//			old_lis = lis;
//		lis = 0;
//	}
//	return (stacks->size - 1 - old_lis);
//}
//
//int				global_ins_index(t_stacks *stacks)
//{	int		i;
//	int		j;
//	t_layer		*val;
//	t_layer		*val2;
//	int		old_lis;
//	int		lis;
//
//	lis = 0;
//	i = -1;
//	while ((val = iterator(stacks, ++i)))
//	{
//		j = i;
//		while (++j < stacks->size -1)
//		{
//			val2 = iterator(stacks, j);
//			if (val->val < val2->val)
//				lis++;
//		}
//		if (lis > old_lis)
//			old_lis = lis;
//		lis = 0;
//	}
//	return (stacks->size - 1 - old_lis);
//}
//
int				real_dist_number(t_stacks *stacks, int i)
{
	int		dist_inner;
	int		dist_out;
	t_layer	*num;

	num = iterator(stacks, i);
	if (i >= num->pos && i <= num->pos + num->doubles)
	{
		return (0);
	}
	else
	{
		dist_inner = i - num->pos;
		dist_inner *= dist_inner < 0 ? -1 : 1;
		dist_out = (stacks->size - 1) - dist_inner;
	}
	if (dist_inner > dist_out)
		return (func_fib(dist_out));
	else
		return (func_fib(dist_inner));
}

int				global_real_dist(t_stacks *stacks)
{
	int		i;
	int		dist;

	i = -1;
	dist = 0;
	while (++i < stacks->size)
	{
		dist += real_dist_number(stacks, i);
	}
	return (dist);

}


int				global_dist(t_stacks *stacks)
{
	int		i;
	int		dist;

	dist = 0;
	i = -1;
	while(++i < stacks->size)
		dist += global_number_dist(stacks, i);
	return (dist + (global_num_inv(stacks) * 2));
}

//static int		invs(t_layer *stack, int used)
//{
//	int	i;
//	int	j;
//	int	invs;
//
//	i = 0;
//	j = 1;
//	invs = 0;
//	while (i < used)
//	{
//		j = i;
//		while (j + 1 <= used && stack[i] > stack[j + 1])
//			j++;
//		if (j > i)
//			invs += j - i;
//		i++;
//	}	
//	return (invs);
//}

static int		sorted(t_layer *stack, int used)
{
	int		i;

	i = 0;
	while (i < used)
	{
		if (stack[i].val > stack[i + 1].val)
			break;
		i++;
	}
	if (i == used)
		return (1);
	else
		return (0);
}

static int		inv_sorted(t_layer *stack, int used)
{
	int i;

	i = 0;
	while (i < used)
	{
		if (stack[i].val < stack[i + 1].val)
			break;
		i++;
	}
	if (i == used)
		return (1);
	else
		return (0);
}

//static int		inv_out_of_place(t_layer *stack, int used)
//{
//	int	i;
//	int	out_of_place;
//
//	i = 0;
//	out_of_place = 0;
//	while (i < used)
//	{
//		if (stack[i] < stack[i + 1])
//			out_of_place++;
//		i++;
//	}	
//	return (out_of_place);
//}
//
//static int		out_of_place(t_layer *stack, int used)
//{
//	int	i;
//	int	out_of_place;
//
//	i = 0;
//	out_of_place = 0;
//	while (i < used)
//	{
//		if (stack[i] > stack[i + 1])
//			out_of_place++;
//		i++;
//	}	
//	return (out_of_place);
//}
//
//static int		adj_invs(t_layer *stack, int used)
//{
//	int	i;
//	int	adj_invs;
//
//	i = 0;
//	adj_invs = 0;
//	while (i <= used)
//	{
//		if (stack[i] > stack[i + 1])
//		{
//			if (i + 1 <= used && stack[i] < stack[i + 2])
//				adj_invs++;
//		}
//		i++;
//	}	
//	return (adj_invs);
//
//}
//
//static int		rev_invs(t_layer *stack, int used)
//{
//	int	i;
//	int	j;
//	int	invs;
//
//	i = 0;
//	j = 1;
//	invs = 0;
//	while (i < used)
//	{
//		j = i;
//		while (j + 1 <= used && stack[i] < stack[j + 1])
//			j++;
//		if (j > i)
//			invs += j - i;
//		i++;
//	}	
//	return (invs);
//}
//
//static int	inv_rec_helper(t_layer *stack, int used, int pos, int start)
//{
//	int	i;
//	int	max_for_number;
//	int	old_max_for_number;
//
//	if (pos < start)
//		used = start;
//	i = pos + 1;
//	max_for_number = 0;
//	old_max_for_number = -1;
//	while (i <= used)
//	{
//		if (stack[pos] >= stack[i])
//		{
//			if ((max_for_number = inv_rec_helper(stack, used, i, start)) > old_max_for_number)
//				old_max_for_number = max_for_number;
//		}
//		i++;
//		if (used != start && i == used)
//		{
//			i = 0;
//			used = start;
//		}
//	}
//	return (old_max_for_number + 1);
//}

//static int	inv_rec_lis(t_layer *stack, int used)
//{
//	int	max_for_number;
//	int	old_max_for_number;
//	int	pos;
//
//	pos = 0;
//	max_for_number = 0;
//	old_max_for_number = -1;
//	while(pos < used)
//	{
//		max_for_number = inv_rec_helper(stack, used, pos, pos);
//		if (max_for_number > old_max_for_number)
//			old_max_for_number = max_for_number;
//		pos++;
//	}
//	return (old_max_for_number);
//}

//static int	rec_helper(t_layer *stack, int used, int pos, int start)
//{
//	int	i;
//	int	max_for_number;
//	int	old_max_for_number;
//
//	if (pos < start)
//		used = start;
//	i = pos + 1;
//	max_for_number = 0;
//	old_max_for_number = -1;
//	while (i <= used)
//	{
//		if (stack[pos] <= stack[i])
//		{
//			if ((max_for_number = rec_helper(stack, used, i, start)) > old_max_for_number)
//				old_max_for_number = max_for_number;
//		}
//		i++;
//		if (used != start && i == used)
//		{
//			i = 0;
//			used = start;
//		}
//	}
//	return (old_max_for_number + 1);
//}
//
//static int	rec_lis(t_layer *stack, int used)
//{
//	int	max_for_number;
//	int	old_max_for_number;
//	int	pos;
//
//	pos = 0;
//	max_for_number = 0;
//	old_max_for_number = -1;
//	while(pos < used)
//	{
//		max_for_number = rec_helper(stack, used, pos, pos);
//		if (max_for_number > old_max_for_number)
//			old_max_for_number = max_for_number;
//		pos++;
//	}
//	return (old_max_for_number);
//}

int		lowest(t_layer *stack, int used)
{
	int		i;
	int		lowest;

	lowest = INT_MAX;
	i = -1;
	while (++i <= used)
	{
		if (lowest > stack[i].val)
			lowest = stack[i].val;	
	}
	return (lowest);
}

int		highest(t_layer *stack, int used)
{
	int		i;
	int		highest;

	highest = INT_MIN;
	i = -1;
	while (++i <= used)
	{
		if (highest < stack[i].val)
			highest = stack[i].val;	
	}
	return (highest);
}

int		num_big_piv(t_layer *stack, int used, int piv)
{
	int score;
	int	i;

	i = -1;
	score = 0;
	while (++i <= used)
	{
		if (stack[i].val > piv)
			score++;	
	}
	return (score);
}

int		num_small_piv(t_layer *stack, int used, int piv)
{
	int score;
	int	i;

	i = -1;
	score = 0;
	while (++i <= used)
	{
		if (stack[i].val <= piv)
			score++;	
	}
	return (score);
}

int		low_dist_to_used(t_layer *stack, int used, int piv)
{
	int		score;
	int		i;
	int		pos;

	score = 0;
	pos = -1;
	i = used / 2;
	while (++i <= used)
	{
		if (stack[i].val < piv)
			pos = i;
	}
	score = used - pos;
	i = used / 2 + 1;
	while (--i >= 0)
	{
		if (stack[i].val > piv)
			pos = i;
	}
	return (pos < score ? pos : score);

}

int		high_dist_to_used(t_layer *stack, int used, int piv)
{
	int		score;
	int	i;
	int		pos;

	score = 0;
	pos = -1;
	i = used / 2;
	while (++i <= used)
	{
		if (stack[i].val > piv)
			pos = i;
	}
	score = used - pos;
	i = used / 2 + 1;
	while (--i >= 0)
	{
		if (stack[i].val > piv)
			pos = i;
	}
	return (pos < score ? pos : score);
}

int		highest_dist_to_used(t_layer *stack, int used,int highest)
{
	int		score;
	int	i;
	int		pos;

	score = 0;
	pos = -1;
	i = used / 2;
	while (++i <= used)
	{
		if (stack[i].val == highest)
			pos = i;
	}
	score = used - pos;
	i = used / 2 + 1;
	while (--i >= 0)
	{
		if (stack[i].val == highest)
			pos = i + 1;
	}
	return (pos < score ? pos : score);
}

t_sort	sortedness(t_stacks *stacks)
{
	t_sort	s;

	s.sorted = sorted(stacks->a, stacks->a_used);
	s.inv_sorted = inv_sorted(stacks->b, stacks->b_used);
	s.highest = highest(stacks->a, stacks->a_used); 
	s.lowest = lowest(stacks->b, stacks->b_used);
	s.num_big_piv = num_big_piv(stacks->a, stacks->a_used, stacks->piv.num);
	s.num_small_piv = num_small_piv(stacks->b, stacks->b_used, stacks->piv.num);
	s.highest_dis = highest_dist_to_used(stacks->a, stacks->a_used, s.highest);
	s.high_dis = high_dist_to_used(stacks->a, stacks->a_used, stacks->piv.num);
	s.low_dis = low_dist_to_used(stacks->b, stacks->b_used, s.lowest);
	s.lowest_dis = highest_dist_to_used(stacks->b, stacks->b_used, s.lowest);
	return (s);
}
