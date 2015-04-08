/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:23:25 by wbeets            #+#    #+#             */
/*   Updated: 2015/03/19 16:23:27 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		calc_piv(t_stacks *stacks, int pivpos)
{
	int		higher;
	int		lower;
	int		i;

	higher = 0;
	lower = 0;
	i = 0;
	while (i < stacks->size)
	{
		if (i != pivpos)
		{
			if (stacks->a[i].val < stacks->a[pivpos].val)
				lower++;
			if (stacks->a[i].val > stacks->a[pivpos].val)
				higher++;
		}
		i++;
	}
	return (lower > higher ? lower - higher : higher - lower);
}

void	find_pivot(t_stacks *stacks)
{
	int		i;
	int		sc;

	i = 0;
	stacks->piv.score = INT_MAX;
	while (i < stacks->size)
	{
		sc = calc_piv(stacks, i);
		if (sc < stacks->piv.score)
		{
			stacks->piv.score = sc;
			stacks->piv.pos = i;
			stacks->piv.num = stacks->a[i].val;
		}
		i++;
	}
}

static int		get_op_piv(t_stacks *stacks)
{
	if (stacks->a[stacks->a_used].val > stacks->piv.num)
	{
		stacks->sness.num_big_piv--;
		return (PB);
	}
	else
		return (RA);
}


void	divide_by_pivot(t_stacks *stacks)
{
	int	i;

	i = 0;
	find_pivot(stacks);
	stacks->sness = sortedness(stacks);
	while (stacks->sness.num_big_piv && ++i)
		do_op(get_op_piv(stacks), stacks);
}
