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

static void		print_arr(int *arr, int used)
{
	int	i;
	i = 0;
	while (i <= used)
	{
		ft_putnbr(arr[i]);
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

int		start(t_stacks *stacks)
{
	int	i;

	i = 0;
	find_pivot(stacks);
	stacks->sness_a = sortedness(stacks->a, stacks->a_used, stacks->piv.num);
	stacks->sness_b = sortedness(stacks->b, stacks->b_used, stacks->piv.num);
	sort(stacks);
	return (1);
}
