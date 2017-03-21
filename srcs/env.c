#include "minishell.h"

void	showallhash(t_hash **table, int size)
{
	int		x;
	char	*str;
	t_hash	*save;

	str = ft_strdup("\0");
	x = 0;
	while (x < size)
	{
		save = table[x];
		while (table[x])
		{
			if (table[x]->index != 0)
			{
				str = ft_strjoinf(str, table[x]->index);
				str = ft_strjoinf(str, "=");
				str = ft_strjoinf(str, table[x]->data);
				str = ft_strjoinf(str, "\n");
			}
			table[x] = table[x]->next;
		}
		table[x] = save;
		x++;
	}
	ft_putstr(str);
	free(str);
}

void	env_cmd(char **av, t_env env)
{
	int		x;

	x = 0;
	if (!av[1])
	{
		showallhash(env.table, env.table_size);
	}
}
