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

static void		print_arr(t_layer *arr, int used)
{
	int	i;
	i = 0;
	while (i <= used)
	{
		ft_putnbr(arr[i].val);
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
int		get_op(int ra, int rb)
{
	if (ra > 0 && rb > 0)
		return (RR);
	if (ra < 0 && rb < 0)
		return (RRR); 
	if (ra < 0)
		return (RRA);
	if (ra > 0)
		return (RA);
	if (rb > 0)
		return (RB);
	if (rb < 0)
		return (RRB);
	return (INT_MIN);
}

void	ins_prepare(t_stacks *stacks)
{
	stacks->rinsa = dist_closest_ins_num_a(stacks->a, stacks->a_used, stacks->a_start);
	stacks->rinsb = dist_closest_ins_num_b(stacks->b, stacks->b_used, stacks->a_used, stacks->b_start);
	while (stacks->rinsa != 0 || stacks->rinsb != 0)
	{
		do_print_op(get_op(stacks->rinsa, stacks->rinsb), stacks);
		ft_putstr("\n");
		ft_putstr("startpos a = ");
		ft_putnbr(stacks->a_start);
		ft_putstr("\n");
		ft_putstr("startpos b = ");
		ft_putnbr(stacks->b_start);
		ft_putstr("\n");
	}
	do_print_op(PB, stacks);
	do_print_op(SB, stacks);
	do_print_op(PA, stacks);
}

int		do_ins(t_stacks *stacks)
{
	int		op;
	int		ra;

	ra = stacks->b[stacks->b_used].dist;
	stacks->rinsb = stacks->a[stacks->a_used].dist;
	ft_putstr("rinsa = ");
	ft_putnbr(stacks->rinsa);
	ft_putstr("\nrinsb = ");
	ft_putnbr(stacks->rinsb);
	ft_putstr("\ndo_ins ___________________ \n");
	while ((op = get_op(0, stacks->rinsb)) != INT_MIN)
	{
		do_print_op(op, stacks);
	}
	do_print_op(PB, stacks);
	stacks->rinsb = dist_closest_ins_num_b(stacks->b, stacks->b_used, stacks->a_used, stacks->b_start);
	ft_putstr("moving b for pa ---------\n");
	while ((op = get_op(0, stacks->rinsb)) != INT_MIN)
	{
		do_print_op(op, stacks);
	}
	do_print_op(PA, stacks);
	stacks->rinsa = dist_closest_ins_num_a(stacks->a, stacks->a_used, stacks->a_start);
	ft_putstr("moving a for pb ---------\n");
	while ((op = get_op(stacks->rinsa, 0)) != INT_MIN)
	{
		do_print_op(op, stacks);
	}
	do_print_op(PB, stacks);
	ft_putstr(" \n");
	print_stack_sorted(stacks->a, stacks->a_used);
	print_stack_sorted(stacks->b, stacks->b_used);
	ft_putstr(" \n");
	print_global(stacks);


	return (0);
}

int		start(t_stacks *stacks)
{
	print_stacks(stacks);
	final_posistions(stacks);
	divide_by_pivot(stacks);
	stacks->a_start = find_lowest_sub_a(stacks->a, stacks->a_used);
	stacks->b_start = find_lowest_sub_b(stacks->b, stacks->b_used);
	print_stacks(stacks);
	ins_prepare(stacks);
	do_ins(stacks);
	//sort(stacks);
	return (1);
}
