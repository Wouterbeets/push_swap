/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapfunc1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:55:55 by wbeets            #+#    #+#             */
/*   Updated: 2015/03/19 11:55:57 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int sa(t_stacks *stacks)
{
	t_layer		tmp;

	if (stacks->a_used > 0 && stacks->a[stacks->a_used].val != stacks->a[stacks->a_used -1].val)
	{
		tmp = stacks->a[stacks->a_used];
		stacks->a[stacks->a_used] = stacks->a[stacks->a_used - 1];
		stacks->a[stacks->a_used - 1] = tmp;
		return (SA);
	}
	return (-1);
}

int sb(t_stacks *stacks)
{
	t_layer		tmp;

	if (stacks->b_used > 0 && stacks->b[stacks->b_used].val != stacks->b[stacks->b_used -1].val)
	{
		tmp = stacks->b[stacks->b_used];
		stacks->b[stacks->b_used] = stacks->b[stacks->b_used - 1];
		stacks->b[stacks->b_used - 1] = tmp;
		return (SB);
	}
	return (-1);
}

int ss(t_stacks *stacks)
{
	int		a;
	int		b;

	a = sa(stacks);	
	b = sb(stacks);	
	if (a > -1 && b > -1)
		return (SS);
	if (a > -1)
		return (a);
	if (b > -1)
		return (b);
	return (-1);
}

int pa(t_stacks *stacks)
{
	if (stacks->b_used > -1)
	{
		stacks->a[stacks->a_used + 1] = stacks->b[stacks->b_used];
		stacks->a_used++;
		stacks->b_used--;
		if (stacks->a[stacks->a_used].val > stacks->piv.num)
			stacks->sness.num_big_piv++;
		else
			stacks->sness.num_small_piv--;
		stacks->rinsa += stacks->rinsa < 0 ? 0 : 1;
		stacks->rinsa2 += stacks->rinsa2 < 0 ? 0 : 1;
		stacks->a_ins_dis += stacks->a_ins_dis < 0 ? 0 : 1;
		stacks->a_ins_dis2 += stacks->a_ins_dis2 < 0 ? 0 : 1;
		stacks->rinsb -= stacks->rinsb < 0 ? 0 : 1;
		stacks->rinsb2 -= stacks->rinsb2 < 0 ? 0 : 1;
		stacks->b_ins_dis -= stacks->b_ins_dis < 0 ? 0 : 1;
		stacks->b_ins_dis2 -= stacks->b_ins_dis2 < 0 ? 0 : 1;
		return (PB);
	}
	return (-1);
}

int pb(t_stacks *stacks)
{
	if (stacks->a_used > -1)
	{
		stacks->b[stacks->b_used + 1] = stacks->a[stacks->a_used];
		stacks->b_used++;
		stacks->a_used--;
		if (stacks->b[stacks->b_used].val <= stacks->piv.num)
			stacks->sness.num_small_piv++;
		else
			stacks->sness.num_big_piv--;
		stacks->rinsa -= stacks->rinsa < 0 ? 0 : 1;
		stacks->rinsa2 -= stacks->rinsa2 < 0 ? 0 : 1;
		stacks->a_ins_dis -= stacks->a_ins_dis < 0 ? 0 : 1;
		stacks->a_ins_dis2 -= stacks->a_ins_dis2 < 0 ? 0 : 1;
		stacks->rinsb += stacks->rinsb < 0 ? 0 : 1;
		stacks->rinsb2 += stacks->rinsb2 < 0 ? 0 : 1;
		stacks->b_ins_dis += stacks->b_ins_dis < 0 ? 0 : 1;
		stacks->b_ins_dis2 += stacks->b_ins_dis2 < 0 ? 0 : 1;
		return (PA);
	}
	return (-1);
}
