#include "../includes/push_swap.h"

int		pos_to_index(t_elem *s, int size, int pos)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (s[i].pos == pos)
			return (i);
		i++;
	}
	return (-1);
}
static int		l_pos_to_index(t_elem *s, int size, int pos)
{
	int index;

	while ((index = pos_to_index(s, size, pos)) == -1 && pos <= size)
		pos++;
	return (index);
}

int		index_to_rel_index(t_stacks *s, int index)
{
	int	rel_zero;

	rel_zero = l_pos_to_index(s->a, s->a_used, 0);
	return ((s->a_used + 1) - (rel_zero - index)) % (s->a_used + 1);
}

t_elem	*it(t_stacks *s, int num)
{
	if (num <= s->a_used)
		return (&s->a[num]);
	else
		num -= s->a_used + 1;
	return (&s->b[num]);
}

t_elem	*rel_it(t_stacks *s, int num)
{
	int rel_zero;

	rel_zero = l_pos_to_index(s->a, s->a_used, 0);
	if (rel_zero == -1)
		return (NULL);
	if (rel_zero + num <= s->a_used)
		return (&s->a[rel_zero + num]);
	else if (num <= s->a_used)
		return (&s->a[num - ((s->a_used + 1) - rel_zero)]);
	rel_zero = l_pos_to_index(s->b, s->b_used, s->size / 2);
	if (rel_zero == -1)
		return (NULL);
	num -= s->a_used + 1;
	if (rel_zero - num >= 0)
		return (&s->b[rel_zero - num]);
	else if (num <= s->b_used)
		return (&s->b[(s->size + 1) - abs(rel_zero - num)]);
	return (NULL);
}

int		abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

float		sortedness(t_stacks *s, iter f)
{
	int i;
	t_elem *e;
	float diff;

	i = 0;
	diff = 0.0;
	while (i < s->size)
	{
		if ((e = f(s, i)) != NULL)
		{
			diff += abs(i - e->pos);
		}
		else 
			return (-1);
		i++;
	}
	return (1.0 - (diff / (s->size * s->size)) * 2);
}
