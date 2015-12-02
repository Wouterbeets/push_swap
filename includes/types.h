/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:11:00 by wbeets            #+#    #+#             */
/*   Updated: 2015/12/02 16:54:06 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef	enum
{
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_op;

typedef struct			s_op_lst
{
	struct s_op_lst		*next;
	int					op;
	int					score;
}						t_op_lst;

typedef struct			s_pivot
{
	int	score;
	int	pos;
	int	num;
	int	sorted;
}						t_pivot;

typedef struct			s_elem
{
	int val;
	int pos;
	int dub;
	int ins;
}						t_elem;

typedef struct			s_stacks
{
	t_elem	*a;
	int		a_used;
	t_elem	*b;
	int		b_used;
	int		size;
	char	v;
}						t_stacks;

typedef t_elem			*(*t_iter)(t_stacks *s, int num);
#endif
