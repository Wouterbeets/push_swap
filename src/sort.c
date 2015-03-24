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

static t_sort	get_op_sness(int i, t_stacks *stacks, int a)
{
	int		undo;
	t_sort	s;

	undo = do_op(i, stacks);
	if (a)
		s = sortedness(stacks->a, stacks->a_used);
	else
		s = sortedness(stacks->b, stacks->b_used);
	if (undo != -1)
		do_op(undo, stacks);
	return (s);
	
}

int				get_sort_score(t_sort s)
{
	return (s.ins_index);
}

t_op_lst	*get_list(int *sarra, int *sarrb)
{
	t_op_lst	*ret;
	int			i;
	int			j;
	int			best_op;
	int			best_score;

	(void)sarrb;
	i = -1;
	best_score = INT_MAX;
	ret = NULL;
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
			ret = add_to_list(ret, best_op);
		sarra[best_op] = INT_MAX;
	}
	return (ret);
}

static		t_op_lst	*best_ops(t_stacks *stacks)
{
	int		sarra[NUM_OP];
	int		sarrb[NUM_OP];
	int		i;
	int		score;

	i = -1;
	score = 0;
	while (++i < NUM_OP)
	{
		sarra[i] = get_sort_score(get_op_sness(i ,stacks, 1));
		sarrb[i] = get_sort_score(get_op_sness(i ,stacks, 0));
	}
	i = -1;
	return (get_list(sarra, sarrb));
}

static int	rec_sort(t_stacks *stacks, t_op_lst *begin, int counter, int *best)
{
	int		ret;
	int		undo;
	t_op_lst	*start;
	t_op_lst	*ops;

	ret = -1;
	undo = -1;
	stacks->sness_a = sortedness(stacks->a, stacks->a_used);
	if (stacks->v)
		print_list(begin);
	if (stacks->sness_a.sorted == 1 && stacks->b_used == -1)
		return (counter);
	if  (counter >= *best || counter >= MAX_DEPTH)
		return (-1);
	else
	{
		ops = best_ops(stacks);
		start = ops;
		while (ops)
		{
			undo = do_op(ops->op, stacks);
			begin = add_to_list(begin, ops->op);
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
				do_op(ops->op, stacks);
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
	best = 2000;	
	if (rec_sort(stacks, list, 0, &best))
	{
		print_list(stacks->best_lst);
		ft_putstr("\n");
		return (stacks->best_lst);
	}
	return (NULL);
}

