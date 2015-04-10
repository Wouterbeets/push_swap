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
	int					score;
}				t_op_lst;

typedef struct	s_pivot
{
	int	score;
	int	pos;
	int	num;
	int	sorted;
}				t_pivot;

typedef struct	s_layer
{
	int	val;
	int	pos;
	int	rel_pos;
	int	doubles;
	int	dist;
}				t_layer;

typedef struct	s_sort
{	
	int	global_dist;
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
	t_layer		*a;
	t_layer		*b;
	int			a_used;
	int			b_used;
	int			a_start;
	int			b_start;
	int			rinsa;
	int			rinsb;
	int			rinsa2;
	int			rinsb2;
	int			a_ins_dis2;
	int			b_ins_dis2;
	int			a_ins_dis;
	int			b_ins_dis;
	int			size;	
	int			v;
	t_pivot		piv;
	t_sort		sness;
	t_sort		old_sness;
	t_op_lst	*best_lst;
	t_op		last_op;
	t_op		undo;
	int			last_score;
	int			max_depth;
	int			max_op;
	int			glob;
}				t_stacks;


int		abs(int num);
int		calc_dist_a(int i, int pos, int used, int doubles);
int		calc_dist_b(int i, int pos, int used, int doubles);
t_layer				*rel_iterator_t(t_stacks *stacks, int i);
void	print_stack_sorted(t_layer *stack, int used);
void	divide_by_pivot(t_stacks *stacks);
int		dist_closest_ins_num_b(t_layer *stack, int b_used, int a_used, int start_pos);
int		dist_closest_ins_num_a(t_layer *stack, int used, int start_pos);
int				find_lowest_sub_a(t_layer	*stack, int used);
int				find_lowest_sub_b(t_layer	*stack, int used);
int		num_big_piv(t_layer *stack, int used, int piv);
void			final_posistions_rel(t_stacks *stacks);
void			final_posistions(t_stacks *stacks);
int				global_num_inv(t_stacks	*stacks);
int				*rel_iterator(t_stacks *stacks, int i);
void			print_global(t_stacks *stacks);
int				fib(int loops);
int				dist_inv_b(t_stacks *stacks);
int				dist_inv_a(t_stacks *stacks);
int				dist_to_closest_inv(t_stacks *stacks);
int				global_ins_index(t_stacks *stacks);
int				global_rel_ins_index(t_stacks *stacks);
int				global_dist(t_stacks *stacks);
int				global_real_dist(t_stacks *stacks);
int				start(t_stacks *stacks);
void			print_stacks(t_stacks *stacks);
void			find_pivot(t_stacks *stacks);
t_sort			sortedness(t_stacks *stacks);
t_op_lst		*sort(t_stacks *stacks);

int				*copy_arr(int stack_b, t_stacks *stacks);
t_stacks		*copy_stacks(t_stacks *stacks);
int				do_op(t_op op, t_stacks *stacks);
int				do_print_op(t_op op, t_stacks *stacks);
void			print_list(t_op_lst *list);
void			print_op(t_op op);
int				sa(t_stacks *stacks);
int				sb(t_stacks *stacks);
int				ss(t_stacks *stacks);
int				pa(t_stacks *stacks);
int				pb(t_stacks *stacks);
int				rrr(t_stacks *stacks);
int				ra(t_stacks *stacks);
int				rb(t_stacks *stacks);
int				rr(t_stacks *stacks);
int				rra(t_stacks *stacks);
int				rrb(t_stacks *stacks);


t_op_lst		*new_lst_item(int op, int score);
void			add_to_end(t_op_lst *begin, t_op_lst *to_add);
t_op_lst		*add_to_list(t_op_lst *begin, int op, int score);
void			free_list(t_op_lst *list);
t_op_lst		*remove_last(t_op_lst *begin);
t_op_lst		*copy_list(t_op_lst *begin);
t_op_lst		*sort(t_stacks *stacks);
#endif 

