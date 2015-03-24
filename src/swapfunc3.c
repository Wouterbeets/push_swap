/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapfunc3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:59:29 by wbeets            #+#    #+#             */
/*   Updated: 2015/03/19 11:59:31 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		rrr(t_stacks *stacks)
{
	int	a;
	int	b;

	a = rra(stacks);
	b = rrb(stacks);
	if (a > -1 && b > -1)
		return (RR);
	if (a > -1)
		return (a);
	if (b > -1)
		return (b);
	return (-1);
}

void	do_print_op(t_op op, t_stacks *stacks)
{
	static int (*fptr_arr[11])(t_stacks *) = {
		sa, sb, ss, pa, pb, ra, rb ,rr, rra, rrb, rrr};
	static char *str[11] = {"sa\0", "sb\0", "ss\0", "pa\0",
		"pb\0", "ra\0", "rb\0", "rr\0", "rra\0", "rrb\0", "rrr\0"};

	ft_putstr(str[op]);
	fptr_arr[op](stacks);
	if (!stacks->sness_a.sorted)
		ft_putstr(" ");
	if(stacks->v)
	{
		ft_putstr("\n");
		print_stacks(stacks);
	}
}

void	print_op(t_op op)
{
	static char *str[11] = {"sa\0", "sb\0", "ss\0", "pa\0",
		"pb\0", "ra\0", "rb\0", "rr\0", "rra\0", "rrb\0", "rrr\0"};

	ft_putstr(str[op]);
}
