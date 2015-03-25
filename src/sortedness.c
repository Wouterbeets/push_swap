

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

static int		inv_sorted(int *stack, int used)
{
	int i;

	i = 0;
	while (i < used)
	{
		if (stack[i] < stack[i + 1])
			break;
		i++;
	}
	if (i == used)
		return (1);
	else
		return (0);
}

static int		inv_out_of_place(int *stack, int used)
{
	int	i;
	int	out_of_place;

	i = 0;
	out_of_place = 0;
	while (i < used)
	{
		if (stack[i] < stack[i + 1])
			out_of_place++;
		i++;
	}	
	return (out_of_place);
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

static int	inv_rec_helper(int *stack, int used, int pos, int start)
{
	int	i;
	int	max_for_number;
	int	old_max_for_number;

	if (pos < start)
		used = start;
	i = pos + 1;
	max_for_number = 0;
	old_max_for_number = -1;
	while (i <= used)
	{
		if (stack[pos] >= stack[i])
		{
			if ((max_for_number = inv_rec_helper(stack, used, i, start)) > old_max_for_number)
				old_max_for_number = max_for_number;
		}
		i++;
		if (used != start && i == used)
		{
			i = 0;
			used = start;
		}
	}
	return (old_max_for_number + 1);
}

static int	inv_rec_lis(int *stack, int used)
{
	int	max_for_number;
	int	old_max_for_number;
	int	pos;

	pos = 0;
	max_for_number = 0;
	old_max_for_number = -1;
	while(pos < used)
	{
		max_for_number = inv_rec_helper(stack, used, pos, pos);
		if (max_for_number > old_max_for_number)
			old_max_for_number = max_for_number;
		pos++;
	}
	return (old_max_for_number);
}

static int	rec_helper(int *stack, int used, int pos, int start)
{
	int	i;
	int	max_for_number;
	int	old_max_for_number;

	if (pos < start)
		used = start;
	i = pos + 1;
	max_for_number = 0;
	old_max_for_number = -1;
	while (i <= used)
	{
		if (stack[pos] <= stack[i])
		{
			if ((max_for_number = rec_helper(stack, used, i, start)) > old_max_for_number)
				old_max_for_number = max_for_number;
		}
		i++;
		if (used != start && i == used)
		{
			i = 0;
			used = start;
		}
	}
	return (old_max_for_number + 1);
}

static int	rec_lis(int *stack, int used)
{
	int	max_for_number;
	int	old_max_for_number;
	int	pos;

	pos = 0;
	max_for_number = 0;
	old_max_for_number = -1;
	while(pos < used)
	{
		max_for_number = rec_helper(stack, used, pos, pos);
		if (max_for_number > old_max_for_number)
			old_max_for_number = max_for_number;
		pos++;
	}
	return (old_max_for_number);
}

int		lowest(int *stack, int used)
{
	int		i;
	int		lowest;

	lowest = INT_MAX;
	i = -1;
	while (++i <= used)
	{
		if (lowest > stack[i])
			lowest = stack[i];	
	}
	return (lowest);
}

int		highest(int *stack, int used)
{
	int		i;
	int		highest;

	highest = INT_MIN;
	i = -1;
	while (++i <= used)
	{
		if (highest < stack[i])
			highest = stack[i];	
	}
	return (highest);
}

int		num_big_piv(int *stack, int used, int piv)
{
	int score;
	int	i;

	i = -1;
	score = 0;
	while (++i <= used)
	{
		if (stack[i] > piv)
			score++;	
	}
	return (score);
}

int		num_small_piv(int *stack, int used, int piv)
{
	int score;
	int	i;

	i = -1;
	score = 0;
	while (++i <= used)
	{
		if (stack[i] <= piv)
			score++;	
	}
	return (score);
}

t_sort	sortedness(int *stack, int used, int piv)
{
	t_sort	s;

	s.sorted = sorted(stack, used);
	s.inv_sorted = inv_sorted(stack, used);
	s.out_of_place = out_of_place(stack, used);
	s.inv_out_of_place = inv_out_of_place(stack, used);
	s.adj_invs = adj_invs(stack, used);
	s.invs = invs(stack, used);
	s.ins_index = (used) - rec_lis(stack, used);
	s.inv_ins_index = (used) - inv_rec_lis(stack, used);
	if (s.ins_index == -1)
		s.ins_index = 0;
	s.highest = highest(stack, used); 
	s.lowest = lowest(stack, used);
	s.num_big_piv = num_big_piv(stack, used, piv);
	s.num_small_piv = num_small_piv(stack, used, piv);
	return (s);
}
