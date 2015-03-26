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
	int		tmp;

	if (stacks->a_used > 0 && stacks->a[stacks->a_used] != stacks->a[stacks->a_used -1])
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
	int		tmp;

	if (stacks->b_used > 0 && stacks->b[stacks->b_used] != stacks->b[stacks->b_used -1])
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
		return (PA);
	}
	return (-1);
}
