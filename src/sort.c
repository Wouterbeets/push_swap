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

int		obvious_moves(t_stacks *stacks, t_op op)
{
	if (stacks->sness.sorted && stacks->b_used == -1)
		return (INT_MIN);
	if (op == RRR && (stacks->a_used < 1 || stacks->b_used < 1))
		return (INT_MAX);
	if (op == RR && (stacks->a_used < 1 || stacks->b_used < 1))
		return (INT_MAX);
	if (op == SS && stacks->undo == SB)
		return (INT_MAX);
	if (op == SS && stacks->undo == SA)
		return (INT_MAX);
	if (op == SS && (stacks->a_used < 1 || stacks->b_used < 1))
		return (INT_MAX);
	if (op == RB && stacks->last_op == RB && stacks->b_used < 2)
		return (INT_MAX);
	if (op == RRB && stacks->last_op == RRB && stacks->b_used < 2)
		return (INT_MAX);
	return (0);
}

int		winning_move(t_stacks *stacks, t_op op)
{
	if (stacks->old_sness.sorted)
	{
		if (stacks->old_sness.highest <= stacks->old_sness.lowest)
		{
			if (stacks->old_sness.inv_sorted)
			{
				if (op == PA)
				{
					stacks->glob = 2;
					return (1);
				}
			}
		}
	}
	return (0);
}

int				get_sort_score(t_stacks *stacks, t_op op)
{
	int	scoreb;
	int	scorea;
	int	score;

	if ((score = obvious_moves(stacks, op)) != 0)
		return (score);
	scorea = 0;
	scoreb = 0;
	if (stacks->glob == 2 && op != PA)
	{
		return (INT_MAX);
	}
	if (winning_move(stacks, op))
		return (INT_MIN);
	if (stacks->glob == 1)
	{
		score = global_real_dist(stacks);
		return (score);
	}
	else if (stacks->piv.sorted)
	{

		//ft_putstr("-------------------------------------------------\n");
		//print_op(op);
		//ft_putstr("\n");
		score += global_dist(stacks);
		//print_stacks(stacks);
		//print_global(stacks);
//		ft_putstr("\n");
		//score += global_ins_index(stacks);
		score += stacks->sness.highest > stacks->sness.lowest ? stacks->size * 100: 0;
		//score += stacks->sness_a.highest_dis;
		//score += stacks->sness_b.lowest_dis;
		if (score == 0)
			stacks->glob = 1;
		if (op >= 5)
		{

		//	ft_putstr(" glob_dist = ");
		//	ft_putnbr(score);
		//	ft_putstr("dist_inv_a ");
		//	ft_putnbr(dist_inv_a(stacks));
		//	ft_putstr("\n");
		//	ft_putstr("dist_inv_b ");
		//	ft_putnbr(dist_inv_b(stacks));
		//	ft_putstr("\n");
			score += dist_inv_a(stacks);
			score += dist_inv_b(stacks);
		}
		//print_op(op);
		//ft_putstr(" = ");
		//ft_putnbr(score);
		//ft_putstr("\n");
	}
	else
	{
		//if (op >= 5)
		//{
		//	score += stacks->sness.highest_dis;
		//	score += stacks->sness.lowest_dis;
		//}
		//else
		{
			score += stacks->sness.num_big_piv * stacks->size;
			score += stacks->sness.num_small_piv * stacks->size;
			//score += (global_dist(stacks));
		}
	}
	return (score);
}


int				get_op_sness(int i, t_stacks *stacks)
{
	int		undo;
	int		ret;

	ret = 0;
	undo = -1;
	if (i != stacks->undo)
		undo = do_op(i, stacks);
	if (undo > -1)
	{
		stacks->sness = sortedness(stacks);
		ret = get_sort_score(stacks, i);
		do_op(undo, stacks);
		return (ret);
	}
	return (INT_MAX);

}

t_op_lst	*get_list(int *sarra, int max_op)
{
	t_op_lst	*ret;
	int			i;
	int			j;
	int			best_op;
	int			best_score;

	i = -1;
	best_score = INT_MAX;
	ret = NULL;
	//	ft_putstr("options are:\n");
	//	j = -1;
	//	while (++j < NUM_OP)
	//	{
	//		print_op(j);
	//		ft_putstr(" ");
	//		ft_putnbr(sarra[j]);
	//		ft_putstr("\n");
	//	}
	//	ft_putstr("\n");
	while (++i < max_op)
	{
		j = NUM_OP;
		while (--j >= 0)
		{
			if (sarra[j] <= best_score)
			{
				best_score = sarra[j];
				best_op = j;
			}
		}
		if (sarra[best_op] != INT_MAX)
		{
			ret = add_to_list(ret, best_op, sarra[best_op]);
			best_score = INT_MAX;
			//			print_op(best_op);
			//			ft_putstr(" ");
			//			ft_putnbr(sarra[best_op]);
			//			ft_putstr("\n");
		}
		sarra[best_op] = INT_MAX;
	}
	//	ft_putstr("\n");
	return (ret);
}

static		t_op_lst	*best_ops(t_stacks *stacks)
{
	int		sarra[NUM_OP];
	int		i;
	int		score;

	i = -1;
	score = 0;
	//if (stacks->piv.sorted != 1)
	//{
		while (++i < NUM_OP)
			sarra[i] = INT_MAX;
		i = -1;
		while (++i < 5)
			sarra[i] = get_op_sness(i ,stacks);
		i = -1;
		while (++i < 5)
		{
			if (sarra[i] < stacks->last_score || stacks->last_score == INT_MIN)
				return (get_list(sarra, stacks->max_op));
		}
		i = -1;
		while (++i < 5)
			sarra[i] = INT_MAX;
		i = 4;
		while (++i < NUM_OP)
			sarra[i] = get_op_sness(i ,stacks);
		return (get_list(sarra, stacks->max_op));
	//}
}

static int	rec_sort(t_stacks *stacks, t_op_lst *begin, int counter, int *best)
{
	int		ret;
	int		undo;
	t_op_lst	*start;
	t_op_lst	*ops;

	ret = -1;
	undo = -1;
	stacks->max_depth--;
	stacks->max_op--;
	if (stacks->max_op == 0 || stacks->max_op > 3)
		stacks->max_op = 1;
	stacks->old_sness = sortedness(stacks);
	if (stacks->v)
	{
		ft_putstr("\n");
		ft_putstr("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		ft_putstr("xx              rec_sort                      xx\n");
		ft_putstr("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		print_list(begin);
		print_stacks(stacks);
		print_global(stacks);
	}
	if (stacks->old_sness.sorted == 1 && stacks->b_used == -1)
		return (counter);
	if (stacks->piv.sorted == 0 && stacks->old_sness.num_big_piv == 0 && stacks->old_sness.num_small_piv == 0)
	{
		ft_putstr("||||||||||||||||||||||||||||||||||||||||||||||||\n");
		ft_putstr("||              piv sorted                    ||\n");
		ft_putstr("||||||||||||||||||||||||||||||||||||||||||||||||\n");
		stacks->piv.sorted = 1;
		stacks->last_score = get_sort_score(stacks, stacks->last_op);
		ft_putstr("dist = ");
		ft_putnbr(global_dist(stacks));
	}
	if  (counter >= *best || stacks->max_depth == 0)
		return (-1);
	else
	{
		ops = best_ops(stacks);
		start = ops;
		while (ops)
		{
			undo = do_op(ops->op, stacks);
			begin = add_to_list(begin, ops->op, ops->score);
			stacks->last_op = ops->op;
			stacks->undo = undo;
			if (ops->score < stacks->last_score && ops->op < 5)
			{
				stacks->last_score = ops->score;
				stacks->max_depth = 100;
				stacks->max_op = 5;
			}
			if((ret = rec_sort(stacks, begin, counter + 1, best)) > -1)
			{	
				if (ret < *best && ret != -1)
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
			if (ops->next && ops->next->score == ops->score)
				ops = ops->next;
			else
				ops = NULL;
			stacks->max_depth++;
			stacks->max_op++;
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
	stacks->undo = -1;
	stacks->last_score = INT_MAX;
	stacks->max_depth = 5;
	stacks->max_op = 1;
	final_posistions(stacks);
	//ft_putstr("global_dist = ");
	//ft_putnbr(global_dist(stacks));
	//ft_putstr("\n");
	if (rec_sort(stacks, list, 0, &best))
	{
		print_list(stacks->best_lst);
		//ft_putstr("\n---------------------------------------\n");
		return (stacks->best_lst);
	}
	return (NULL);
}

