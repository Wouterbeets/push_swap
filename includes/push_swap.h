#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <limits.h>
# define MAX_DEPTH 8
# define MAX_TESTS 1
# define NUM_OP 11
typedef	enum
{
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}		t_op;


typedef struct	s_op_lst
{
	struct s_op_lst	*next;
	int					op;
}				t_op_lst;

typedef struct	s_pivot
{
	int	score;
	int	pos;
	int	num;
	int	sorted;
}				t_pivot;

typedef struct	s_sort
{	
	int	sorted;
	int	inv_sorted;
	int out_of_place;
	int inv_out_of_place;
	int	invs;
	int	rev_invs;
	int	adj_invs;
	int	ins_index;
	int inv_ins_index;
	int	highest;
	int	lowest;
	int	num_big_piv;
	int num_small_piv;
	int	highest_dis;
	int	lowest_dis;
	int	high_dis;
	int	low_dis;
	int	used;
}				t_sort;

typedef struct	s_stacks
{
	int		*a;
	int		*b;
	int		a_used;
	int		b_used;
	int		size;	
	int		v;
	t_pivot		piv;
	t_sort		sness_a;
	t_sort		sness_b;
	t_sort		old_sness_a;
	t_sort		old_sness_b;
	t_op_lst	*best_lst;
	t_op	last_op;
	t_op	undo;
	int		bsort;
	int		asort;
	int		last_score;
}				t_stacks;

int				global_dist(t_stacks *stacks);
int		start(t_stacks *stacks);
void	print_stacks(t_stacks *stacks);
void	find_pivot(t_stacks *stacks);
t_sort	sortedness(int *stack, int used, int piv);
t_op_lst		*sort(t_stacks *stacks);

int			*copy_arr(int stack_b, t_stacks *stacks);
t_stacks	*copy_stacks(t_stacks *stacks);
int		do_op(t_op op, t_stacks *stacks);
int		do_print_op(t_op op, t_stacks *stacks);
void	print_list(t_op_lst *list);
void	print_op(t_op op);
int		sa(t_stacks *stacks);
int		sb(t_stacks *stacks);
int		ss(t_stacks *stacks);
int		pa(t_stacks *stacks);
int		pb(t_stacks *stacks);
int		rrr(t_stacks *stacks);
int		ra(t_stacks *stacks);
int		rb(t_stacks *stacks);
int		rr(t_stacks *stacks);
int		rra(t_stacks *stacks);
int		rrb(t_stacks *stacks);


t_op_lst	*new_lst_item(int op);
void		add_to_end(t_op_lst *begin, t_op_lst *to_add);
t_op_lst	*add_to_list(t_op_lst *begin, int op);
void		free_list(t_op_lst *list);
t_op_lst	*remove_last(t_op_lst *begin);
t_op_lst	*copy_list(t_op_lst *begin);

t_op_lst	*sort(t_stacks *stacks);
#endif 

