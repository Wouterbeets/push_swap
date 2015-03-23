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
	int	i;

	i = 0;
	pb(stacks);
	find_pivot(stacks);
	printf("pivotscore  = %d, pos = %d num = %d\n", stacks->piv.score, stacks->piv.pos, stacks->piv.num);
	print_stacks(stacks);
	stacks->sness_a = sortedness(stacks->a, stacks->a_used);
	stacks->sness_b = sortedness(stacks->b, stacks->b_used);
	printf("sotred = %d, out_of_place = %d, adj_invs = %d, invs = %d lis = %d\n", stacks->sness_a.sorted,stacks->sness_a.out_of_place, stacks->sness_a.adj_invs, stacks->sness_a.invs, stacks->sness_a.ins_index);
	printf("sotred = %d, out_of_place = %d, adj_invs = %d, invs = %d ins_index = %d\n", stacks->sness_b.sorted,stacks->sness_b.out_of_place, stacks->sness_b.adj_invs, stacks->sness_b.invs, stacks->sness_b.ins_index);
	sort(stacks);
	return (0);
}

