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

void sa(t_stacks *stacks)
{
	int		tmp;

	if (stacks->a_used > 1)
	{
		tmp = stacks->a[stacks->a_used];
		stacks->a[stacks->a_used] = stacks->a[stacks->a_used - 1];
		stacks->a[stacks->a_used - 1] = tmp;
	}
}

void sb(t_stacks *stacks)
{
	int		tmp;

	if (stacks->b_used > 1)
	{
		tmp = stacks->b[stacks->b_used];
		stacks->b[stacks->b_used] = stacks->b[stacks->b_used - 1];
		stacks->b[stacks->b_used - 1] = tmp;
	}
}

void ss(t_stacks *stacks)
{
	int		tmp;

	if (stacks->a_used > 1)
	{
		tmp = stacks->a[stacks->a_used];
		stacks->a[stacks->a_used] = stacks->a[stacks->a_used - 1];
		stacks->a[stacks->a_used - 1] = tmp;
	}
	if (stacks->b_used > 1)
	{
		tmp = stacks->b[stacks->b_used];
		stacks->b[stacks->b_used] = stacks->b[stacks->b_used - 1];
		stacks->b[stacks->b_used - 1] = tmp;
	}
}

void pa(t_stacks *stacks)
{
	if (stacks->b_used > -1)
	{
		stacks->a[stacks->a_used + 1] = stacks->b[stacks->b_used];
		stacks->a_used++;
		stacks->b_used--;
	}
}

void pb(t_stacks *stacks)
{
	if (stacks->a_used > -1)
	{
		stacks->b[stacks->b_used + 1] = stacks->a[stacks->a_used];
		stacks->b_used++;
		stacks->a_used--;
	}
}
