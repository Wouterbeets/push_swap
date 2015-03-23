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

static int	rec_sort(t_stacks *stacks, t_op_lst *begin, int counter, int *best)
{
	int		i;
	int		ret;
	static void (*undo[11])(t_stacks *) = {
		sa, sb, ss, pb, pa, rra, rrb ,rrr, ra, rb, rr};
	static void (*fptr_arr[11])(t_stacks *) = {
		sa, sb, ss, pa, pb, ra, rb ,rr, rra, rrb, rrr};

	i = 0;
	ret = -1;
	stacks->sness_a = sortedness(stacks->a, stacks->a_used);
	if (stacks->sness_a.sorted == 1)
		return (counter);
	if  (counter >= *best || counter >= MAX_DEPTH)
		return (-1);
	else
		//arr_sortedness  = get_array_of_sortedness_per_op
		//order_arr
		//for arr_sortedness 
	{
		while (i < 11)
		{
			fptr_arr[i](stacks);
			add_to_list(begin, i);
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
			remove_last(begin);
			undo[i](stacks);
			i++;
		}
		print_stacks(stacks);
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
		print_stacks(stacks);
	return list;
}

