
#include "../includes/push_swap.h"

t_ins_list	*new_lst_item_ins(int rot, int ins_dist, t_layer val)
{
	t_ins_list	*ret;

	ret = (t_ins_list *)malloc(sizeof(t_ins_list));
	ret->next = NULL;
	ret->rot = rot;
	ret->ins_dist = ins_dist;
	ret->val = val;
	return (ret);
}

void		add_to_end_ins(t_ins_list *begin, t_ins_list *to_add)
{
	while(begin->next)
		begin = begin->next;
	begin->next = to_add;
}

t_ins_list		*add_to_begin_ins(t_ins_list *begin, t_ins_list *to_add)
{
	to_add->next = begin;
	return (to_add);
}

t_ins_list	*remove_first_ins(t_ins_list *begin)
{
	t_ins_list *tmp;

	tmp = begin->next;
	free(begin);
	return (tmp);
}

t_ins_list	*remove_last_ins(t_ins_list *begin)
{
	t_ins_list	*tmp;

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

t_ins_list	*add_to_list_ins(t_ins_list *begin, int rot, int ins_dist, t_layer val)
{
	if (begin == NULL)
		return (new_lst_item_ins(rot, ins_dist, val));
	begin = add_to_begin_ins(begin, new_lst_item_ins(rot, ins_dist, val));
	return (begin);
}

void		free_list_ins(t_ins_list *list)
{
	t_ins_list	*tmp;

	while(list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

void		dec_list_ins_p(t_ins_list *lst)
{
	t_ins_list *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->ins_dist -= tmp->ins_dist < 0 ? 0 : 1;
		tmp = tmp->next;
	}
}

void		inc_list_ins_p(t_ins_list *lst)
{
	t_ins_list *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->ins_dist += tmp->ins_dist < 0 ? 0 : 1;
		tmp = tmp->next;
	}
}

void		dec_list_rot_p(t_ins_list *lst)
{
	t_ins_list *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->rot -= tmp->rot < 0 ? 0 : 1;
		tmp = tmp->next;
	}
}

void		inc_list_rot_p(t_ins_list *lst)
{
	t_ins_list *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->rot += tmp->rot < 0 ? 0 : 1;
		tmp = tmp->next;
	}
}

void		dec_list_ins(t_ins_list *lst)
{
	t_ins_list *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->ins_dist -= 1;
		tmp = tmp->next;
	}
}

void		inc_list_ins(t_ins_list *lst)
{
	t_ins_list *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->ins_dist += 1;
		tmp = tmp->next;
	}
}
void		dec_list_rot(t_ins_list *lst)
{
	t_ins_list *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->rot -= 1;
		tmp = tmp->next;
	}
}

void		inc_list_rot(t_ins_list *lst)
{
	t_ins_list *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->rot += 1;
		tmp = tmp->next;
	}
}
