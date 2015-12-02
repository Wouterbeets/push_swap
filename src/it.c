/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:43:17 by wbeets            #+#    #+#             */
/*   Updated: 2015/12/02 16:45:05 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pos_to_index(t_elem *s, int size, int pos)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (s[i].pos == pos)
			return (i);
		i++;
	}
	return (-1);
}

int		l_pos_to_index(t_elem *s, int size, int pos)
{
	int index;

	while ((index = pos_to_index(s, size, pos)) == -1 && pos <= size)
		pos++;
	return (index);
}

int		index_to_rel_index(t_stacks *s, int index)
{
	int	rel_zero;

	rel_zero = l_pos_to_index(s->a, s->a_used, 0);
	return ((s->a_used + 1) - (rel_zero - index)) % (s->a_used + 1);
}
