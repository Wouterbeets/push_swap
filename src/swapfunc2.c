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

void ra(t_stacks *stacks)
{
	int	tmp;
	int	i;

	ft_putstr("ra");
	if ((i = stacks->a_used + 1) > 1)
	{
		tmp = stacks->a[stacks->a_used];
		while (--i > 0)
			stacks->a[i] = stacks->a[i - 1];	
		stacks->a[0] = tmp;
	}
	if(stacks->v)
		print_stacks(stacks);
}

void rb(t_stacks *stacks)
{
	int	tmp;
	int i;

	ft_putstr("rb");
	if ((i = stacks->b_used + 1) > 1)
	{
		tmp = stacks->b[stacks->b_used];
		while (--i > 0)
			stacks->b[i] = stacks->b[i - 1];	
		stacks->b[0] = tmp;
	}
	if(stacks->v)
		print_stacks(stacks);
}

void rr(t_stacks *stacks)
{
	int	tmp;
	int	i;

	ft_putstr("rr");
	if ((i = stacks->b_used + 1) > 1)
	{
		tmp = stacks->b[stacks->b_used];
		while (--i > 0)
			stacks->b[i] = stacks->b[i - 1];	
		stacks->b[0] = tmp;
	}
	if ((i = stacks->a_used + 1) > 1)
	{
		tmp = stacks->a[stacks->a_used];
		while (--i > 0)
			stacks->a[i] = stacks->a[i - 1];	
		stacks->a[0] = tmp;
	}
	if(stacks->v)
		print_stacks(stacks);
}

void rra(t_stacks *stacks)
{
	int	tmp;
	int	i;

	ft_putstr("rra");
	if (stacks->a_used > 0)
	{
		tmp = stacks->a[0];
		i = -1;
		while (++i < stacks->a_used)
			stacks->a[i] = stacks->a[i + 1];
		stacks->a[stacks->a_used] = tmp;
	}
	if(stacks->v)
		print_stacks(stacks);
}

void rrb(t_stacks *stacks)
{
	int	tmp;
	int	i;

	ft_putstr("rrb");
	if (stacks->b_used > 0)
	{
		tmp = stacks->b[0];
		i = -1;
		while (++i < stacks->b_used)
			stacks->b[i] = stacks->b[i + 1];
		stacks->b[stacks->b_used] = tmp;
	}
	if(stacks->v)
		print_stacks(stacks);
}
