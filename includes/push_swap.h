#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdlib.h>

typedef struct	s_stacks
{
	int		*a;
	int		*b;
	int		size;
}				t_stacks;

#endif 

int start(t_stacks *stacks);

