#include "../includes/push_swap.h"

int		get_number(char *str, int *num)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
		{
			if (i == 0 && str[i] == '-')
				continue;
			else 
				return (-1);
		}
		i++;
	}
	*num = ft_atoi(str);
	return (1);
}

t_stacks		*check_args(int ac, char **av)
{
	int			i;
	t_stacks	*ret;

	i = 0;
	ret = (t_stacks *)malloc(sizeof(t_stacks));
	ret->a = (int *)malloc(sizeof(int) * (ac - 1));
	ret->b = (int *)malloc(sizeof(int) * (ac - 1));
	ret->size = ac -1;
	if (ac == 1)
		ft_putstr("usage: ./push_swap 5 3 2 54 65 ...\n");
	while (i < ret->size)
	{
		if (!get_number(av[i + 1], &(ret->a[i])))
		{
			ret->size = -1;
			return (ret);
		}
		ret->b[i] = 0;	
		i++;
	}
	return (ret);
}

int		main(int ac, char **av)
{
	t_stacks	*stacks;

	if ((stacks = check_args(ac, av)) && stacks->size > 0)
	{
		start(stacks);
	}
	else 
	{
		ft_putstr("unable to parse numbers\n");
	}
	free(stacks->b);
	free(stacks->a);
	free(stacks);
	return (0);
}
