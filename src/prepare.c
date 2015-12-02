/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:44:01 by wbeets            #+#    #+#             */
/*   Updated: 2015/12/02 15:44:01 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		index_next_low_val(t_stacks *s)
{
	int		i;
	int		l_index;
	int		low;

	i = 0;
	low = INT_MAX;
	while (i <= s->a_used)
	{
		if (s->a[i].pos == -1 && low > s->a[i].val)
		{
			low = s->a[i].val;
			l_index = i;
		}
		i++;
	}
	return (l_index);
}

static int		find_doubles(t_stacks *s, int val)
{
	int i;
	int dub;

	i = 0;
	dub = 0;
	while (i <= s->a_used)
	{
		if (val == s->a[i].val)
			dub++;
		i++;
	}
	return (dub - 1);
}

static void		init_pos_dub(t_stacks *s)
{
	int		i;
	int		index;

	i = 0;
	index = 0;
	while (i <= s->a_used)
	{
		s->a[i].pos = -1;
		s->a[i].dub = find_doubles(s, s->a[i].val);
		i++;
	}
	i = 0;
	while (i <= s->a_used)
	{
		index = index_next_low_val(s);
		s->a[index].pos = i;
		i++;
	}
}

void			prepare(t_stacks *s)
{
	init_pos_dub(s);
	print_stacks(s);
}
