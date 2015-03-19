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

void rrr(t_stacks *stacks)
{
	int	tmp;
	int	i;

	ft_putstr("rrr");
	if (stacks->b_used > 0)
	{
		tmp = stacks->b[0];
		i = -1;
		while (++i < stacks->b_used)
			stacks->b[i] = stacks->b[i + 1];
		stacks->b[stacks->b_used] = tmp;
	}
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

