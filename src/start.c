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
//
//int		get_op(int *ra, int *rb)
//{
//	if ((*ra)-- > 0 && (*rb)-- > 0)
//		return (RR);
//	if ((*ra)++ < 0 && (*rb)++ < 0)
//		return (RRR); 
//	if ((*ra)++ < 0)
//		return (RRA);
//	if ((*ra)-- > 0)
//		return (RA);
//	if ((*rb)-- > 0)
//		return (RB);
//	if ((*rb)++ < 0)
//		return (RRB);
//	return (INT_MIN);
//}
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


void	print_stats(t_stacks *stacks)
{
	ft_putstr("\n---------------------------\n\t\tstats\n--------------------------------\n");
	ft_putstr("a_ins_dis = ");
	ft_putnbr(stacks->a_ins_dis);
	ft_putstr("\n");
	ft_putstr("b_ins_dis = ");
	ft_putnbr(stacks->b_ins_dis);
	ft_putstr("\n");
	ft_putstr("rinsa = ");
	ft_putnbr(stacks->rinsa);
	ft_putstr("\n");
	ft_putstr("rinsb = ");
	ft_putnbr(stacks->rinsb);
	ft_putstr("\n");
	ft_putstr("a_ins_dis2 = ");
	ft_putnbr(stacks->a_ins_dis2);
	ft_putstr("\n");
	ft_putstr("b_ins_dis2 = ");
	ft_putnbr(stacks->b_ins_dis2);
	ft_putstr("\n");
	ft_putstr("rinsa2 = ");
	ft_putnbr(stacks->rinsa2);
	ft_putstr("\n");
	ft_putstr("rinsb2 = ");
	ft_putnbr(stacks->rinsb2);
	ft_putstr("\n");
}

void	ins_prepare(t_stacks *stacks)
{
	
	stacks->rinsa = dist_closest_ins_num_a(stacks->a, stacks->a_used, stacks->a_start);
	stacks->rinsb = dist_closest_ins_num_b(stacks->b, stacks->b_used, stacks->a_used, stacks->b_start);
	print_stats(stacks);
	ft_putstr("\n------------double_move------------------------\n");
	while (stacks->rinsa != 0 || stacks->rinsb != 0)
		do_print_op(get_op(stacks->rinsa, stacks->rinsb), stacks);
	do_print_op(PB, stacks);
	do_print_op(SB, stacks);
	do_print_op(PA, stacks);
	stacks->a_ins_dis = stacks->b[stacks->b_used].dist;
	stacks->b_ins_dis = stacks->a[stacks->a_used].dist;
	print_stats(stacks);
	ft_putstr("\n------------move_to_next_ins_area--------------\n");
	while (stacks->a_ins_dis != 0 || stacks->b_ins_dis != 0)
		do_print_op(get_op(stacks->a_ins_dis, stacks->b_ins_dis), stacks);
	stacks->rinsa2 = dist_closest_ins_num_a(stacks->a, stacks->a_used, stacks->a_start);
	stacks->rinsb2 = dist_closest_ins_num_b(stacks->b, stacks->b_used, stacks->a_used, stacks->b_start);
	print_stats(stacks);
	ft_putstr("\n------------find_new_to_moves--------------\n");
	while (stacks->rinsa2 != 0 || stacks->rinsb2 != 0)
		do_print_op(get_op(stacks->rinsa2, stacks->rinsb2), stacks);
	do_print_op(PB, stacks);
	do_print_op(SB, stacks);
	do_print_op(PA, stacks);
	stacks->a_ins_dis2 = stacks->b[stacks->b_used].dist;
	stacks->b_ins_dis2 = stacks->a[stacks->a_used].dist;
	print_stats(stacks);
	ft_putstr("\n------------move_to_insest_into_a--------------\n");
	while (stacks->a_ins_dis != 0 || stacks->rinsb != 0)
		do_print_op(get_op(stacks->a_ins_dis, stacks->rinsb), stacks);
	do_print_op(PA, stacks);
	ft_putstr("\nsorted\n");
	print_stack_sorted(stacks->a, stacks->a_used);
	stacks->rinsa = dist_closest_ins_num_a(stacks->a, stacks->a_used, stacks->a_start);
	ft_putstr("\n------------move_to_get_new_a--------------\n");
	while (stacks->rinsa != 0)
		do_print_op(get_op(stacks->rinsa, 0), stacks);
	do_print_op(PB, stacks);
	stacks->a_ins_dis = stacks->b[stacks->b_used].dist;
}

int		do_ins(t_stacks *stacks)
{
	print_global(stacks);
	print_stats(stacks);
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
