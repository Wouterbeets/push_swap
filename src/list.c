/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 14:05:22 by wbeets            #+#    #+#             */
/*   Updated: 2015/03/23 14:05:25 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

t_op_lst	*new_lst_item(int op, int score)
{
	t_op_lst	*ret;

	ret = (t_op_lst *)malloc(sizeof(t_op_lst));
	ret->next = NULL;
	ret->op = op;
	ret->score = score;
	return (ret);
}

void		add_to_end(t_op_lst *begin, t_op_lst *to_add)
{
	while(begin->next)
		begin = begin->next;
	begin->next = to_add;
}

t_op_lst	*remove_last(t_op_lst *begin)
{
	t_op_lst	*tmp;

	tmp = begin;
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	if (tmp && tmp->next)
	{
		free(tmp->next);
		tmp->next = NULL;
	}
	else
	{
		free(begin);
		begin = NULL;
	}
	return (begin);
}

t_op_lst	*add_to_list(t_op_lst *begin, int op, int score)
{
	if (begin == NULL)
		return (new_lst_item(op, score));
	add_to_end(begin, new_lst_item(op, score));
	return (begin);
}

void		free_list(t_op_lst *list)
{
	t_op_lst	*tmp;

	while(list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

t_op_lst	*copy_list(t_op_lst *begin)
{
	t_op_lst *tmp;
	t_op_lst *ret_it;
	t_op_lst *ret;

	tmp = begin;
	ret = NULL;
	if (tmp)
	{
		ret = new_lst_item(tmp->op, tmp->score);
		ret_it = ret;
		while (tmp->next)
		{
			ret_it->next = new_lst_item(tmp->next->op, tmp->next->score);
			tmp = tmp->next;
			ret_it = ret_it->next;
		}
	}
	return (ret);
}

void	print_list(t_op_lst *list)
{
	t_op_lst	*tmp;

	tmp = list;
	while (tmp)
	{
		print_op(tmp->op);
		if (tmp->next)
			ft_putstr(" ");
		else 
			ft_putstr("\n");
		tmp = tmp->next;
	}
}
