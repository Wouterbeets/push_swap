#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <limits.h>
# define MAX_TESTS 1
# define NUM_OP 11
# define INS_MIN_DIST 3

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

typedef struct s_elem
{
	int val;
	int pos;
	int dub;
	int ins;
}				t_elem;

typedef struct	s_stacks
{
	t_elem *a;
	int a_used;
	t_elem *b;
	int b_used;
	int size;
	char  v;
}				t_stacks;

typedef t_elem *(*iter)(t_stacks *s, int num);
/*
 * swpfunc1.c 
 */
int				sa(t_stacks *s);
int				sb(t_stacks *s);
int				ss(t_stacks *s);

/*
 * swpfunc2.c 
 */
int				ra(t_stacks *s);
int				rb(t_stacks *s);
int				rr(t_stacks *s);
int				rra(t_stacks *s);
int				rrb(t_stacks *s);

/*
 * swpfunc3.c 
 */
int				rrr(t_stacks *s);
int				pa(t_stacks *s);
int				pb(t_stacks *s);

/*
 * print.c
 */
void	print_stacks(t_stacks *stacks);
void	print_op(t_op op);

/*
 * do_op.c
 */
int		do_op(t_op op, t_stacks *stacks);
int		do_print_op(t_op op, t_stacks *stacks);

/*
 * start.c
 */
void	prepare(t_stacks *s);
void start(t_stacks *s);

/*
 * sortedness.c
 */
float	sortedness(t_stacks *s, iter f);
t_elem	*rel_it(t_stacks *s, int num);
t_elem	*it(t_stacks *s, int num);
int		abs(int n);
int		index_to_rel_index(t_stacks *s, int index);
int		pos_to_index(t_elem *s, int size, int pos);

/*
 * genetic.c
 */
float fitness(t_stacks *s, t_op *coms, int size);
#endif 
