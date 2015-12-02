#include "../includes/push_swap.h"

int		ra(t_stacks *s)
{
	t_elem tmp;
	int i;

	tmp  = s->a[s->a_used];
	i = s->a_used;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = tmp;
	return (RRA);
}

int		rb(t_stacks *s)
{
	t_elem tmp;
	int i;

	tmp  = s->b[s->b_used];
	i = s->b_used;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = tmp;
	return (RRB);

}

int		rr(t_stacks *s)
{
	ra(s);
	rb(s);
	return (RRR);
}

int		rra(t_stacks *s)
{
	t_elem tmp;
	int i;

	tmp = s->a[0];
	i = 0;
	while (i < s->a_used)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[s->a_used] = tmp;
	return (RA);
}

int		rrb(t_stacks *s)
{
	t_elem tmp;
	int i;

	tmp = s->b[0];
	i = 0;
	while (i < s->b_used)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[s->b_used] = tmp;
	return (RB);
}
