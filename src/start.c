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

int		smaller_dist(int dist, int r)
{
	if (r < -4 && dist < -3)
	{
		if (dist > r)
			return (1);
	}
	else if (r > 4 && dist > 3)
	{
		if (dist < r)
			return (1);
	}
	return (0);
}

void	get_b(t_stacks *stacks)
{
	ft_putstr("\n");
	ft_putstr("num b = ");
	ft_putnbr(stacks->b[stacks->b_used].val);
	ft_putstr("\n");
	do_print_op(PA, stacks);
	stacks->ins_list_b = add_to_list_ins(stacks->ins_list_b, 0, calc_ins_dis_b(stacks->a[stacks->a_used], stacks, -1), stacks->a[stacks->a_used]);
}

void	get_a(t_stacks *stacks)
{
	ft_putstr("\n");
	ft_putstr("num a = ");
	ft_putnbr(stacks->a[stacks->a_used].val);
	ft_putstr("\n");
	do_print_op(PB, stacks);
	stacks->ins_list_a = add_to_list_ins(stacks->ins_list_a, 0, calc_ins_dis(stacks->b[stacks->b_used], stacks, -1), stacks->b[stacks->b_used]);
}

void	do_move(t_stacks *stacks, int *ra, int *rb)
{
	if (*ra == INT_MAX || *rb == INT_MAX)
		return;
	while (*ra != 0 || *rb != 0)
		do_print_op(get_op(*ra, *rb), stacks);
}

void	do_move_ins(t_stacks *stacks, int *ra, int *rb)
{
	int		dist_a;
	int		dist_b;

	if (*ra == INT_MAX || *rb == INT_MAX)
		return ;
	while (*ra != 0 || *rb != 0)
	{
		if (stacks->a[stacks->a_used].val <= stacks->piv.num && stacks->a[stacks->a_used].dist != 0)
		{
			dist_a = calc_ins_dis(stacks->a[stacks->a_used], stacks, -1);
			stacks->a[stacks->a_used].dist = dist_a;
			if (abs(dist_a) > INS_MIN_DIST && smaller_dist(dist_a, *ra))
			{
				get_a(stacks);
				ins_a(stacks);
				ft_putstr("\n");
			}
		}
		if (stacks->b[stacks->b_used].val > stacks->piv.num && stacks->b[stacks->b_used].dist != 0)
		{
			dist_b = calc_ins_dis_b(stacks->b[stacks->b_used], stacks, -1);
			stacks->b[stacks->b_used].dist = dist_b;
			if (abs(dist_b) > INS_MIN_DIST && smaller_dist(dist_b, *rb))
			{
				get_b(stacks);
				ins_b(stacks);
				ft_putstr("\n");
			}
		}
		do_print_op(get_op(*ra, *rb), stacks);
	}
}

int	ins_prepare(t_stacks *stacks)
{
	int		nil;

	nil = 0;
	stacks->rinsa = dist_closest_ins_num_a(stacks);
	stacks->rinsb = dist_closest_ins_num_b(stacks);
	if (stacks->rinsa == INT_MAX && stacks->rinsb == INT_MAX)
		return (-1);
	else if (stacks->rinsa == INT_MAX)
	{
		do_move(stacks, &nil, &stacks->rinsb);
		get_b(stacks);
		return (1);
	}
	else if (stacks->rinsb == INT_MAX)
	{
		do_move(stacks, &stacks->rinsa, &nil);
		get_a(stacks);
		return (2);
	}
	else 
	{
		do_move(stacks, &stacks->rinsa, &stacks->rinsb);
		get_a(stacks);
		do_print_op(SB, stacks);
		get_b(stacks);
		stacks->ins_list_a->rot = 0;
		return (3);
	}
}

void	ins_a(t_stacks *stacks)
{
	stacks->ins_list_a->ins_dist = calc_ins_dis(stacks->ins_list_a->val, stacks, -1);
	do_move_ins(stacks, &(stacks->ins_list_a->ins_dist), &(stacks->ins_list_a->rot));
	do_print_op(PA, stacks);
	ft_putstr("\n");
	stacks->a[stacks->a_used].dist = 0;
	stacks->ins_list_a = remove_first_ins(stacks->ins_list_a);
}

void	ins_b(t_stacks *stacks)
{
	stacks->ins_list_b->ins_dist = calc_ins_dis_b(stacks->ins_list_b->val, stacks, -1);
	do_move_ins(stacks, &(stacks->ins_list_b->rot), &(stacks->ins_list_b->ins_dist));
	do_print_op(PB, stacks);
	ft_putstr("\n");
	stacks->b[stacks->b_used].dist = 0;
	stacks->ins_list_b = remove_first_ins(stacks->ins_list_b);
}

int		do_ins(t_stacks *stacks)
{
	int i;
	while ((i = ins_prepare(stacks)) != -1)
	{
		if (i == 3)
		{
			ft_putstr("\n---------------------both-------------------\n");
			ins_a(stacks);
			ins_b(stacks);
		}
		if (i == 2)
		{
			ft_putstr("\n---------------------a-------------------\n");
			ins_a(stacks);
		}
		if (i == 1)
		{
			ft_putstr("\n---------------------b-------------------\n");
			ins_b(stacks);
		}
		ft_putstr("\n---------------------insprep-------------------\n");
		print_global(stacks);
		print_stack_sorted(stacks->a, stacks->a_used);
		print_stack_sorted(stacks->b, stacks->b_used);
	}
	return (0);
}

int		start(t_stacks *stacks)
{
	divide_by_pivot(stacks);
	stacks->a_start = find_lowest_sub_a(stacks->a, stacks->a_used);
	stacks->b_start = find_lowest_sub_b(stacks->b, stacks->b_used);
	final_posistions(stacks);
	final_posistions_rel(stacks);
	print_global(stacks);
	print_stack_sorted(stacks->a, stacks->a_used);
	print_stack_sorted(stacks->b, stacks->b_used);
	do_ins(stacks);
	final_posistions_rel(stacks);
	print_global(stacks);
	print_stack_sorted(stacks->a, stacks->a_used);
	print_stack_sorted(stacks->b, stacks->b_used);
	return (1);
}
