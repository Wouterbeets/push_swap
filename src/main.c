/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:48:57 by wbeets            #+#    #+#             */
/*   Updated: 2015/03/19 11:49:02 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		get_number(char *str, int *num)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = -1;
	while (i < len)
	{
		i++;
		if (str[i] && !ft_isdigit(str[i]))
		{
			if (str[0] == '-')
				continue;
			else
				return (-1);
		}
	}
	*num = ft_atoi(str);
	return (1);
}

static int		set_verbose(char *arg, int *i, int *ac)
{
	if (ft_strcmp(arg, "-v") == 0 )
	{
		*i += 1;
		*ac -= 1;
		return (1);
	}
	return (0);
}

static t_stacks	*check_args(int ac, char **av)
{
	int			i;
	int			j;
	t_stacks	*ret;

	i = 1;
	j = 0;
	ret = (t_stacks *)malloc(sizeof(t_stacks));
	ret->size = ac - 1;
	ret->v = set_verbose(av[1], &i, &ret->size); 
	ret->a = (t_layer *)malloc(sizeof(t_layer) * (ret->size));
	ret->b = (t_layer *)malloc(sizeof(t_layer) * (ret->size));
	ret->a_used = ret->size -1;
	ret->b_used = -1;
	ret->a_ins_dis = 0;
	ret->a_ins_dis2 = 0;
	ret->b_ins_dis = 0;
	ret->b_ins_dis2 = 0;
	ret->rinsa = 0;
	ret->rinsb = 0;
	ret->rinsa2 = 0;
	ret->rinsb2 = 0;
	ret->ins_list_a = NULL;
	ret->ins_list_b = NULL;
	while (i < ac)
	{
		if (!get_number(av[i], &(ret->a[j].val)))
		{
			ret->size = -1;
			return (ret);
		}
		ret->a[j].pos = -1;
		ret->a[j].rel_pos = -1;
		ret->b[j].val = 0;
		ret->a[i].dist = INT_MAX;
		i++;
		j++;
	}
	ret->best_lst = NULL;
	return (ret);
}

int				main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac <= 1)
	{
		ft_putstr("usage: ./push_swap 5 3 2 54 65 ...\n");
		return (0);
	}
	if ((stacks = check_args(ac, av)) && stacks->size > 0)
	{
		start(stacks);
	}
	else 
	{
		ft_putstr("usage: ./push_swap 5 3 2 54 65 ...\n");
		ft_putstr("unable to parse numbers\n");
	}
	free(stacks->b);
	free(stacks->a);
	free_list(stacks->best_lst);
	free(stacks);
	return (0);
}
