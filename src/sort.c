/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 13:52:47 by wbeets            #+#    #+#             */
/*   Updated: 2015/03/23 13:52:49 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//static int	comp_stacks(int *old, int *new, int used)
//{
//	int	i;
//
//	i = 0;
//	while (i <= used)
//	{
//		if (old[i] != new[i])
//			return (-1);
//		i++;
//	}
//	return (0);
//}
//
//static int	*copy_stack(int *stack, int used)
//{
//	int		i;
//	int		*ret;
//
//	i = 0;
//	ret = malloc(sizeof(int) * (used + 1));
//	while (i <= used)
//	{
//		ret[i] = stack[i];
//		i++;
//	}
//	return(ret);
//}

int				get_sort_score(t_stacks *stacks, t_op op)
{
	int	score;
	int	scorea;

	scorea = (stacks->sness_a.ins_index)+ stacks->sness_a.out_of_place;
	//scorea = (stacks->sness_a.ins_index);
	score = scorea + 100;
	score += stacks->sness_b.inv_ins_index + stacks->sness_b.inv_out_of_place;
	if (stacks->sness_a.sorted && stacks->b_used == -1)
		return (INT_MIN);
	if (op == RRR && (stacks->a_used < 1 || stacks->b_used < 1))
		return (INT_MAX);
	if (op == RR && (stacks->a_used < 1 || stacks->b_used < 1))
		return (INT_MAX);
	if (op == SS && (stacks->a_used < 1 || stacks->b_used < 1))
		return (INT_MAX);
	if (op == RB && stacks->last_op == RB && stacks->b_used < 2)
		return (INT_MAX);
	if (op == RRB && stacks->last_op == RRB && stacks->b_used < 2)
		return (INT_MAX);
	if (op == PB && stacks->sness_b.lowest < stacks->sness_a.highest)
		score *= 2;
	if (op == PB && stacks->sness_b.inv_sorted && stacks->sness_b.lowest >= stacks->sness_a.highest)
		score /= 2;
	if (op == PA && stacks->sness_a.sorted && stacks->sness_b.lowest >= stacks->sness_a.highest)
		score /= 3;
	if (stacks->sness_a.highest == stacks->a[stacks->a_used])
		score /= 2;
	if (stacks->sness_a.sorted && stacks->a_used > 1)
		score /= 2;
//	if (stacks->sness_a.sorted && stacks->sness_a.num_big_piv == 0)
//		score /= 2;
//	if (op == PB && stacks->b[stacks->b_used] > stacks->piv.num)
//		score /= 2;
//	if (op == PB && stacks->b[stacks->b_used] <= stacks->piv.num)
//		score *= 2;
//	//if (op == RA && stacks->a[stacks->a_used] <= stacks->piv.num)
//		//score = score - (score / 3);
	if (op == PA && scorea > 0)
		score *= 2;
//	if (op == RA && stacks->sness_a.highest < stacks->piv.num && stacks->sness_a.highest == stacks->a[stacks->a_used])
//		score /= 2;
//	if (op == RRA && stacks->sness_a.highest < stacks->piv.num && stacks->sness_a.highest == stacks->a[stacks->a_used])
//		score /= 2;
	//if (stacks->last_score < score)
		//return (INT_MAX);
	return (score);
}


int				get_op_sness(int i, t_stacks *stacks)
{
	int		undo;
	int		ret;

	ret = 0;
	undo = -1;
	if (i != stacks->last_op)
		undo = do_op(i, stacks);
	if (undo > -1)
	{
		stacks->sness_a = sortedness(stacks->a, stacks->a_used, stacks->piv.num);
		stacks->sness_b = sortedness(stacks->b, stacks->b_used, stacks->piv.num);
		ret = get_sort_score(stacks, i);
		do_op(undo, stacks);
		return (ret);
	}
	return (INT_MAX);

}

t_op_lst	*get_list(int *sarra)
{
	t_op_lst	*ret;
	int			i;
	int			j;
	int			best_op;
	int			best_score;

	i = -1;
	best_score = INT_MAX;
	ret = NULL;
	ft_putstr("options are:\n");
	j = -1;
	while (++j < NUM_OP)
	{
		print_op(j);
		ft_putstr(" ");
		ft_putnbr(sarra[j]);
		ft_putstr("\n");
	}
	ft_putstr("\n");
	while (++i < MAX_TESTS)
	{
		j = -1;
		while (++j < NUM_OP)
		{
			if (sarra[j] <= best_score)
			{
				best_score = sarra[j];
				best_op = j;
			}
		}
		if (sarra[best_op] != INT_MAX)
		{
			ret = add_to_list(ret, best_op);
			best_score = INT_MAX;
			print_op(best_op);
			ft_putstr(" ");
			ft_putnbr(sarra[best_op]);
			ft_putstr("\n");
		}
		sarra[best_op] = INT_MAX;
	}
	//ft_putstr("\n");
	return (ret);
}

static		t_op_lst	*best_ops(t_stacks *stacks)
{
	int		sarra[NUM_OP];
	int		i;
	int		score;

	i = -1;
	score = 0;
	while (++i < NUM_OP)
		sarra[i] = get_op_sness(i ,stacks);
	return (get_list(sarra));
}

static int	rec_sort(t_stacks *stacks, t_op_lst *begin, int counter, int *best)
{
	int		ret;
	int		undo;
	t_op_lst	*start;
	t_op_lst	*ops;

	ret = -1;
	undo = -1;
	stacks->sness_a = sortedness(stacks->a, stacks->a_used, stacks->piv.num);
	stacks->sness_b = sortedness(stacks->b, stacks->b_used, stacks->piv.num);
	if (stacks->v)
	{
		print_list(begin);
		print_stacks(stacks);
	}
	if (stacks->sness_a.sorted == 1 && stacks->b_used == -1)
	{
		ft_putstr("awesome");
		return (counter);
	}
	if  (counter >= *best || counter >= stacks->size * 100)
		return (-1);
	else
	{
		ops = best_ops(stacks);
		start = ops;
		while (ops)
		{
			undo = do_op(ops->op, stacks);
			begin = add_to_list(begin, ops->op);
			stacks->last_op = undo;
			stacks->last_score = get_sort_score(stacks, ops->op);
			if( (ret = rec_sort(stacks, begin, counter + 1, best)) > -1)
			{	
				if (ret < *best)
				{
					*best = ret;
					if (stacks->best_lst)
						free(stacks->best_lst);
					stacks->best_lst = copy_list(begin);
				}
			} 
			begin = remove_last(begin);
			if (undo != -1)
				do_op(undo, stacks);
			ops = ops->next;
		}
		free_list(start);
		return (ret);
	}
}

t_op_lst	*sort(t_stacks *stacks)
{
	t_op_lst	*list;
	int			best;

	list = NULL;
	best = INT_MAX;	
	stacks->last_op = -1;
	stacks->last_score = INT_MAX;
	if (rec_sort(stacks, list, 0, &best))
	{
		print_list(stacks->best_lst);
		//ft_putstr("\n---------------------------------------\n");
		return (stacks->best_lst);
	}
	return (NULL);
}

