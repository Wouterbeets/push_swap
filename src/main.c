#include "../includes/push_swap.h"

static int		get_number(char *str, int *num)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = -1;
	while (i < len)
	{
		i++;
		if (str[i] && !ft_isdigit(str[i]))
		{
			if (str[0] == '-')
				continue;
			else
				return (-1);
		}
	}
	*num = ft_atoi(str);
	return (1);
}

static char **remove_element_from_array(int ac, char **av, int index)
{
	char **ret;
	int i;

	ret = (char **)malloc((ac - 1) * sizeof(char *));
	i = 0;
	while (i < index)
	{
		ret[i] = av[i];
		i++;
	}
	while (i < ac - 1)
	{
		ret[i] = av[i + 1];
		i++;
	}
	return ret;
}

static void		set_verbose(t_stacks *s, int ac, char ***av)
{
	int i;
	char **tmp;

	i = 0;
	while (++i < ac) 
	{
		if (ft_strcmp((*av)[i], "-v") == 0 )
		{
			tmp = remove_element_from_array(ac, *av, i);
			*av = remove_element_from_array(ac - 1, tmp, 0);
			free(tmp);
			s->v = 1;
			s->size = ac - 2;
			return;
		}
	}
	*av = remove_element_from_array(ac, *av, 0);
	s->size = ac - 1;
	s->v = -1;
}

static t_stacks *check_args(int ac, char ***av)
{
	int			i;
	t_stacks	*s;

	if (ac > 1)
	{
		s = (t_stacks *)malloc(sizeof(t_stacks));
		set_verbose(s, ac, av);
		s->a_used = s->size - 1;
		s->b_used = -1;
		s->a = (t_elem *)malloc(s->size * sizeof(*s->a));
		s->b = (t_elem *)malloc(s->size * sizeof(*s->a));
		if (s->a == NULL || s->b == NULL)
		{
			ft_putendl("malloc error");
			return (NULL);
		}
		i = -1;
		while (++i < s->size)
			get_number((*av)[i], &s->a[i].val);
		return s;
	}
	return NULL;
}

int main(int ac, char **av)
{
	t_stacks *s;

	s = check_args(ac, &av);
	if (s == NULL)
	{
		ft_putendl("No numbers to sort in program arguments");
		return (1);
	}
	prepare(s);
	start(s);
	free(av);
	return (1);
}

