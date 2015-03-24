

#include "../includes/push_swap.h"

static int		sorted(int *stack, int used)
{
	int		i;

	i = 0;
	while (i < used)
	{
		if (stack[i] > stack[i + 1])
			break;
		i++;
	}
	if (i == used)
		return (1);
	else
		return (0);
}

static int		out_of_place(int *stack, int used)
{
	int	i;
	int	out_of_place;

	i = 0;
	out_of_place = 0;
	while (i < used)
	{
		if (stack[i] > stack[i + 1])
			out_of_place++;
		i++;
	}	
	return (out_of_place);
}

static int		adj_invs(int *stack, int used)
{
	int	i;
	int	adj_invs;

	i = 0;
	adj_invs = 0;
	while (i <= used)
	{
		if (stack[i] > stack[i + 1])
		{
			if (i + 1 <= used && stack[i] < stack[i + 2])
				adj_invs++;
		}
		i++;
	}	
	return (adj_invs);
	
}

static int		invs(int *stack, int used)
{
	int	i;
	int	j;
	int	invs;

	i = 0;
	j = 1;
	invs = 0;
	while (i < used)
	{
		j = i;
		while (j + 1 <= used && stack[i] > stack[j + 1])
			j++;
		if (j > i)
			invs += j - i;
		i++;
	}	
	return (invs);
}

static int	rec_lis(int *stack, int used,int pos)
{
	int	i;
	int	mlis;
	int	old_mlis;

	i = pos + 1;
	mlis = 0;
	old_mlis = -1;
	while (i <= used)
	{
		if (stack[pos] <= stack[i])
		{
			if ((mlis = rec_lis(stack, used, i)) > old_mlis)
					old_mlis = mlis;
		}
		i++;
	}
	return (old_mlis + 1);
}


t_sort	sortedness(int *stack, int used)
{
	t_sort	s;

	s.sorted = sorted(stack, used);
	s.out_of_place = out_of_place(stack, used);
	s.adj_invs = adj_invs(stack, used);
	s.invs = invs(stack, used);
	s.ins_index = (used) - rec_lis(stack, used, 0);
	return (s);
}
