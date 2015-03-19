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

	ft_putstr("sa");
	if (stacks->a_used > 1)
	{
		tmp = stacks->a[stacks->a_used];
		stacks->a[stacks->a_used] = stacks->a[stacks->a_used - 1];
		stacks->a[stacks->a_used - 1] = tmp;
	}
	if(stacks->v)
		print_stacks(stacks);
}

void sb(t_stacks *stacks)
{
	int		tmp;

	ft_putstr("sb");
	if (stacks->b_used > 1)
	{
		tmp = stacks->b[stacks->b_used];
		stacks->b[stacks->b_used] = stacks->b[stacks->b_used - 1];
		stacks->b[stacks->b_used - 1] = tmp;
	}
	if(stacks->v)
		print_stacks(stacks);
}

void ss(t_stacks *stacks)
{
	int		tmp;

	ft_putstr("ss");
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
	if(stacks->v)
		print_stacks(stacks);
}

void pa(t_stacks *stacks)
{
	ft_putstr("pa");
	if (stacks->b_used > -1)
	{
		stacks->a[stacks->a_used + 1] = stacks->b[stacks->b_used];
		stacks->a_used++;
		stacks->b_used--;
	}
	if(stacks->v)
		print_stacks(stacks);
}

void pb(t_stacks *stacks)
{
	ft_putstr("pb");
	if (stacks->a_used > -1)
	{
		stacks->b[stacks->b_used + 1] = stacks->a[stacks->a_used];
		stacks->b_used++;
		stacks->a_used--;
	}
	if(stacks->v)
		print_stacks(stacks);
}
