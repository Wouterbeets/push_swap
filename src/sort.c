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

static int	comp_stacks(int *old, int *new, int used)
{
	int	i;

	i = 0;
	while (i <= used)
	{
		if (old[i] != new[i])
			return (-1);
		i++;
	}
	return (0);
}

static int	*copy_stack(int *stack, int used)
{
	int		i;
	int		*ret;

	i = 0;
	ret = malloc(sizeof(int) * (used + 1));
	while (i <= used)
	{
		ret[i] = stack[i];
		i++;
	}
	return(ret);
}


static int	rec_sort(t_stacks *stacks, t_op_lst *begin, int counter, int *best)
{
	int		i;
	int		ret;
	static int (*fptr_arr[11])(t_stacks *) = {
		sa, sb, ss, pa, pb, ra, rb ,rr, rra, rrb, rrr};
	int		undo;

	i = 0;
	ret = -1;
	undo = -1;
	stacks->sness_a = sortedness(stacks->a, stacks->a_used);
	if (stacks->sness_a.sorted == 1 && stacks->b_used == -1)
		return (counter);
	if  (counter >= *best || counter >= MAX_DEPTH)
		return (-1);
	else
	{
		while (i < 11)
		{
			undo = fptr_arr[i](stacks);
			begin = add_to_list(begin, i);
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
				fptr_arr[undo](stacks);
			i++;
		}
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

