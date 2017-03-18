#include "minishell.h"

void	my_setenv(char **av, t_env env)
{
	int		x;
	char	*eg;
	int		w;
	char	*t;
	char	*c;

	x = 1;
	while (av[x] != 0)
	{
		if ((eg = ft_strchr(av[x], '=')) == 0)
			return ;
		w = (int)(eg - av[x]);
		t = ft_strsub(av[x], 0 , w);
		c = ft_strsub(av[x], w + 1, ft_strlen(av[x]));
		hash_push(env.table, t, c, ihash(t, env.table_size));
		free(c);
		free(t);
		x++;
	}
}
void	my_unsetenv(char **av, t_env env)
{
	int		x;
	int		i;
	t_hash	*save;
	t_hash	*prev;

	i = 0;
	x = 1;
	prev = 0;
	while (av[x] != 0)
	{
		i = ihash(av[x], env.table_size);
		save = env.table[i];
		while (env.table[i])
		{
			if (ft_strcmp(env.table[i]->index, av[x]) == 0)
			{
				if (!prev && env.table[i]->next == 0)
				{
					free(env.table[i]->index);
					free(env.table[i]->data);
					free(env.table[i]);
					env.table[i] = 0;
				}
				else if (!prev)
				{
					prev = env.table[i];
					env.table[i] = env.table[i]->next;
					free(prev->index);
					free(prev->data);
					free(prev);
					prev = 0;
				}
				else
					ft_putendl("NULL");
				env.table[i] = save;
				return ;
			}
			prev = env.table[i];
			env.table[i] = env.table[i]->next;
		}
		env.table[i] = save;
		x++;
	}
}
