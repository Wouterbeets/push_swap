#include "../includes/push_swap.h"

int		pa(t_stacks *s)
{
	if (s->b_used >= 0)
	{
		s->a[s->a_used + 1] = s->b[s->b_used];
		s->b_used--;
		s->a_used++;
	}
	return (PB);
}

int		pb(t_stacks *s)
{
	if (s->a_used >= 0)
	{
		s->b[s->b_used + 1] = s->a[s->a_used];
		s->a_used--;
		s->b_used++;
	}
	return (PB);
}

int		rrr(t_stacks *s)
{
	rra(s);
	rrb(s);
	return (RR);
}
