/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapfunc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:49:10 by wbeets            #+#    #+#             */
/*   Updated: 2015/03/19 11:49:20 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ra(t_stacks *stacks)
{
	t_layer	tmp;
	int	i;

	if ((i = stacks->a_used + 1) > 1)
	{
		tmp = stacks->a[stacks->a_used];
		while (--i > 0)
			stacks->a[i] = stacks->a[i - 1];	
		stacks->a[0] = tmp;
		stacks->rinsa--;
		stacks->a_start++;
		if (stacks->a_start > stacks->a_used)
			stacks->a_start = 0;
		return (RRA);
	}
	return (-1);
}

int rb(t_stacks *stacks)
{
	t_layer	tmp;
	int i;

	if ((i = stacks->b_used + 1) > 1)
	{
		tmp = stacks->b[stacks->b_used];
		while (--i > 0)
			stacks->b[i] = stacks->b[i - 1];	
		stacks->b[0] = tmp;
		stacks->rinsb--;
		stacks->b_start++;
		if (stacks->b_start > stacks->b_used)
			stacks->b_start = 0;
		return (RRB);
	}
	return (-1);
}

int rr(t_stacks *stacks)
{
	int	a;
	int	b;

	a = ra(stacks);
	b = rb(stacks);
	if (a > -1 && b > -1)
		return (RRR);
	if (a > -1)
		return (a);
	if (b > -1)
		return (b);
	return (-1);
}

int rra(t_stacks *stacks)
{
	t_layer	tmp;
	int	i;

	if (stacks->a_used > 0)
	{
		tmp = stacks->a[0];
		i = -1;
		while (++i < stacks->a_used)
			stacks->a[i] = stacks->a[i + 1];
		stacks->a[stacks->a_used] = tmp;
		stacks->rinsa++;
		stacks->a_start--;
		if (stacks->a_start < 0)
			stacks->a_start = stacks->a_used;
		return (RA);
	}
	return (-1);
}

int rrb(t_stacks *stacks)
{
	t_layer	tmp;
	int	i;

	if (stacks->b_used > 0)
	{
		tmp = stacks->b[0];
		i = -1;
		while (++i < stacks->b_used)
			stacks->b[i] = stacks->b[i + 1];
		stacks->b[stacks->b_used] = tmp;
		stacks->rinsb++;
		stacks->b_start--;
		if (stacks->b_start < 0)
			stacks->b_start = stacks->b_used;
		return (RA);
		return(RB);
	}
	return (-1);
}
