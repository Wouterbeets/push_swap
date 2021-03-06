/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:43:41 by wbeets            #+#    #+#             */
/*   Updated: 2015/12/02 15:43:52 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		do_op(t_op op, t_stacks *stacks)
{
	static int (*fptr_arr[NUM_OP])(t_stacks *) = {
		sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
	};

	return (fptr_arr[op](stacks));
}

int		do_print_op(t_op op, t_stacks *s)
{
	int		ret;

	print_op(op);
	ret = do_op(op, s);
	if (s->v == 1)
	{
		ft_putstr("\n");
		print_stacks(s);
	}
	return (ret);
}
