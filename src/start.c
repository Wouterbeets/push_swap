/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:49:17 by wbeets            #+#    #+#             */
/*   Updated: 2015/03/19 11:49:20 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	print_stacks(t_stacks *stacks)
{
	int		i;

	i = 0;
	ft_putstr("\na = ");
	while (i <= stacks->a_used)
	{
		ft_putnbr(stacks->a[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\nb = ");
	i = 0;
	while (i <= stacks->b_used)
	{
		ft_putnbr(stacks->b[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
}

int		start(t_stacks *stacks)
{
	find_pivot(stacks);
	printf("pivotscore  = %d, pos = %d num = %d\n", stacks->piv.score, stacks->piv.pos, stacks->a[stacks->piv.pos]);
	return (0);
}
