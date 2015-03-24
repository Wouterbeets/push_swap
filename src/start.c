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
	t_op_lst *lst;

	i = 0;
	find_pivot(stacks);
	stacks->sness_a = sortedness(stacks->a, stacks->a_used);
	stacks->sness_b = sortedness(stacks->b, stacks->b_used);
	lst = sort(stacks);
	if (stacks->v)
	{
		while (lst)
		{
			do_print_op(lst->op, stacks);
			stacks->sness_a = sortedness(stacks->a, stacks->a_used);
			stacks->sness_b = sortedness(stacks->b, stacks->b_used);
			lst = lst->next;
				printf("a = sotred = %d, out_of_place = %d, adj_invs = %d, invs = %d lis = %d\n", stacks->sness_a.sorted,stacks->sness_a.out_of_place, stacks->sness_a.adj_invs, stacks->sness_a.invs, stacks->sness_a.ins_index);
			printf("b = sotred = %d, out_of_place = %d, adj_invs = %d, invs = %d lis = %d\n\n", stacks->sness_b.sorted,stacks->sness_b.out_of_place, stacks->sness_b.adj_invs, stacks->sness_b.invs, stacks->sness_b.ins_index);
		}
	}
