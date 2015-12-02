/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genetic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:43:59 by wbeets            #+#    #+#             */
/*   Updated: 2015/12/02 15:43:59 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

float	fitness(t_stacks *s, t_op *coms, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		do_print_op(coms[i], s);
		i++;
	}
	return (sortedness(s, it));
}
