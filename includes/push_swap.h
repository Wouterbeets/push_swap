#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct	s_pivot
{
	int	score;
	int	pos;
	int	num;
}				t_pivot;

typedef struct	s_sort
{	
	int	sorted;
	int out_of_place;
	int	invs;
	int	adj_invs;
	int	ins_index;
}				t_sort;

typedef struct	s_stacks
{
	int		*a;
	int		*b;
	int		a_used;
	int		b_used;
	int		size;	
	int		v;
	t_pivot	piv;
	t_sort	sness_a;
	t_sort	sness_b;
}				t_stacks;

int		start(t_stacks *stacks);
void	print_stacks(t_stacks *stacks);
void	find_pivot(t_stacks *stacks);
t_sort	sortedness(int *stack, int used);
void	divide_by_pivot(t_stacks *stacks);

void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
#endif 

