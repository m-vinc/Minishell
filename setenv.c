#include "minishell.h"

void	my_setenv(char **av, t_env env)
{
	int		x;
	char	*eg;
	char	*t;
	char	*c;
	char	**hash;

	x = 1;
	eg = 0;
	while (av[x] != 0)
	{
		if ((eg = ft_strchr(av[x], '=')) == 0)
			return ;
		t = ft_strsub(av[x], 0 , (int)(eg - av[x]));
		c = ft_strsub(av[x], (int)(eg - av[x]) + 1, ft_strlen(av[x]));
		hash = fhash(env.table, av[x], env.table_size);
		if (hash == 0)
			hash_push(env.table, t, c, ihash(t, env.table_size));
		else
		{
			free(*hash);
			*hash = ft_strdup(c);
		}
		free(c);
		free(t);
		x++;
	}
}
void	free_hashe(t_env env, int index)
{
	free(env.table[index]->index);
	free(env.table[index]->data);
	free(env.table[index]);
	env.table[index] = 0;
}
void	free_el(t_hash **node)
{
	free((*node)->index);
	free((*node)->data);
	node = 0;
}
t_hash	*remove_hash(t_hash *hash, char *index)
{
	t_hash	*cnext;

	if (hash == 0)
		return (0);

	if (ft_strcmp(hash->index, index) == 0)
	{
		cnext = hash->next;
		free(hash->index);
		free(hash->data);
		free(hash);
		return (cnext);
	}
	hash->next = remove_hash(hash->next, index);
	return (hash);
}
void	my_unsetenv(char **av, t_env env)
{
	int		x;
	t_hash	**ph;
	int		h;

	x = 1;
	ph = 0;
	while (av[x] != 0)
	{
		h = ihash(av[x], env.table_size);
		env.table[h] = remove_hash(env.table[h], av[x]);
		x++;
	}
}
