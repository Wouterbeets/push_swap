#include "../includes/push_swap.h"

static int ins_index(t_stacks *s, int index)
{
	int f_pos;
	int c_pos;
	int ins;

	f_pos = s->a[index].pos;
	c_pos = index_to_rel_index(s, index);
	ins = c_pos - f_pos;
	if (abs(ins) > (s->a_used + 1) / 2)
	{
		if (ins < 0)
			ins = ((s->a_used + 1) + ins);
		else 
			ins = (((s->a_used + 1) - ins) * -1);
	}
	return (ins);
}

static void		algo(t_stacks *s)
{
	int ins;	
	int i;

	while (sortedness(s, rel_it) != 1.0)
	{
		i = 0;
		ins = ins_index(s, s->a_used);
		s->a[s->a_used].ins = ins;
		do_print_op(PB, s);
		if (ins < 0)
		{
			while (i < abs(ins))
			{
				do_print_op(RRA, s);
				i++;
			}
		}
		else 
		{
			while (i < abs(ins))
			{
				do_print_op(RA, s);
				i++;
			}
		}
		do_print_op(PA, s);
		do_print_op(RA, s);
	}
}

void	start(t_stacks *s)
{
	int rotate;
	int i;

	algo(s);
	rotate = pos_to_index(s->a, s->a_used, 0);
	i = 0;
	while (i < rotate)
	{
		do_print_op(RRA, s);
		i++;
	}
}
