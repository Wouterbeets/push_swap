/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swpfunc1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:44:03 by wbeets            #+#    #+#             */
/*   Updated: 2015/12/02 15:44:03 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sa(t_stacks *s)
{
	t_elem tmp;

	if (s->a_used >= 0)
	{
		tmp = s->a[s->a_used];
		s->a[s->a_used] = s->a[s->a_used - 1];
		s->a[s->a_used - 1] = tmp;
		return (SA);
	}
	return (-1);
}

int		sb(t_stacks *s)
{
	t_elem tmp;

	if (s->b_used >= 0)
	{
		tmp = s->b[s->b_used];
		s->b[s->b_used] = s->b[s->b_used - 1];
		s->b[s->b_used - 1] = tmp;
		return (SB);
	}
	return (-1);
}

int		ss(t_stacks *s)
{
	int a;
	int b;

	a = sa(s);
	b = sb(s);
	if (a > -1 && b > -1)
		return (SS);
	if (a > -1)
		return (a);
	if (b > -1)
		return (b);
	return (SS);
}
