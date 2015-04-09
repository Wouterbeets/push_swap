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
void	do_move(t_stacks *stacks, int *ra, int *rb)
{
	while (*ra != 0 || *rb != 0)
		do_print_op(get_op(*ra, *rb), stacks);
}
void	ins_prepare(t_stacks *stacks)
{
	int	nil;

	nil = 0;
	stacks->rinsa = dist_closest_ins_num_a(stacks->a, stacks->a_used, stacks->a_start);
	stacks->rinsb = dist_closest_ins_num_b(stacks->b, stacks->b_used, stacks->a_used, stacks->a_start);
	do_move(stacks, &stacks->rinsa, &stacks->rinsb);
	final_posistions_rel(stacks);
	stacks->a_ins_dis = stacks->a[stacks->a_used].dist;
	stacks->b_ins_dis = stacks->b[stacks->b_used].dist;
	do_print_op(PB, stacks);
	do_print_op(SB, stacks);
	do_print_op(PA, stacks);
	do_move(stacks, &stacks->a_ins_dis, &nil);
	do_print_op(PA, stacks);
	do_move(stacks, &stacks->rinsa, &stacks->b_ins_dis);
	do_print_op(PB, stacks);
	final_posistions_rel(stacks);
}

int		do_ins(t_stacks *stacks)
{
	ft_putstr("\n------------check-------------\n");
	print_global(stacks);
	ft_putstr("\n------------sorted-------------\n");
	print_stack_sorted(stacks->a, stacks->a_used);
	print_stack_sorted(stacks->b, stacks->b_used);
	//while (stacks->a_ins_dis2 != INT_MAX && stacks->a_ins_dis != INT_MAX)
	//{
	//	do_move(stacks, &stacks->a_ins_dis, &stacks->rinsb);	
	//	do_print_op(PA, stacks);
	//}
	//stacks->a[stacks->a_used].dist = check_if_in_block();
	return (0);
}

int		start(t_stacks *stacks)
{
	print_stacks(stacks);
	divide_by_pivot(stacks);
	print_stacks(stacks);
	stacks->a_start = find_lowest_sub_a(stacks->a, stacks->a_used);
	stacks->b_start = find_lowest_sub_b(stacks->b, stacks->b_used);
	final_posistions(stacks);
	final_posistions_rel(stacks);
	do_ins(stacks);
	ins_prepare(stacks);
	do_ins(stacks);
	//sort(stacks);
	return (1);
}
