/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 NUM_OP:49:17 by wbeets            #+#    #+#             */
/*   Updated: 2015/03/19 NUM_OP:49:20 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void		print_arr(t_layer *arr, int used)
{
	int	i;
	i = 0;
	while (i <= used)
	{
		ft_putnbr(arr[i].val);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
}

void	print_stacks(t_stacks *stacks)
{
	print_arr(stacks->a, stacks->a_used);
	print_arr(stacks->b, stacks->b_used);
}

int		get_op_piv(t_stacks *stacks)
{
	if (stacks->a[stacks->a_used].val > stacks->piv.num)
	{
		stacks->sness.num_big_piv--;
		return (PB);
	}
	else
		return (RA);
}

int		get_op(t_stacks *stacks)
{
	
}

int		start(t_stacks *stacks)
{
	int	i;

	i = 0;
	find_pivot(stacks);
	stacks->sness = sortedness(stacks);
	while (stacks->sness.num_big_piv && ++i)
		do_op(get_op_piv(stacks), stacks);
	ft_putstr("sorted by piv in ");
	ft_putnbr(i);
	ft_putstr(" \n ---------------------------\n");
	while ((stacks->sness.global_dist = global_dist(stacks)) != 0)
	{
		do_op(get_op(stacks), stacks);
		stacks->old_sness = stacks->sness;
	}
	//sort(stacks);
	return (1);
}
