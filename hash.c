#include "minishell.h"

t_hash	**init_zhash(int size)
{
	t_hash	**table;
	int		x;

	x = 0;
	table = (t_hash **)w_malloc(sizeof(t_hash *) * size + 1);
	while (x < size)
	{
		table[x] = 0;
		x++;
	}
	return (table);
}
int		ihash(char *str, int size)
{
	int	total;

	total = 0;
	if (str == 0)
		return (-1);
	while (*str != '\0')
	{
		total += (size * *str) + *str;
		str++;
	}
	return (total % size);
}
char	*fhash(t_hash **table, char *str, int size)
{
	t_hash	*h;

	h = table[ihash(str, size)];
	if (!str)
		return (0);
	while (h)
	{
		if (ft_strcmp(h->index, str) == 0)
			return (h->data);
		h = h->next;
	}
	return (0);
}
void	hash_push(t_hash **hash, char *index, char *str, int ihash)
{
	t_hash	*save;

	if (hash == 0)
		return ;
	if (ihash == -1)
		return ;
	if (hash[ihash] == 0)
	{
		hash[ihash] = w_malloc(sizeof(t_hash));
		hash[ihash]->next = 0;
		hash[ihash]->data = ft_strdup(str);
		hash[ihash]->index = ft_strdup(index);
	}
	else
	{
		save = hash[ihash];
		while (hash[ihash]->next)
			hash[ihash] = hash[ihash]->next; 
		hash[ihash]->next = w_malloc(sizeof(t_hash));
		hash[ihash]->next->next = 0;
		hash[ihash]->next->data = ft_strdup(str);
		hash[ihash]->next->index = ft_strdup(index);
		hash[ihash] = save;
	}	
}
t_hash	**create_hashtable(char **str, int *size)
{
	int		x;
	char	*tmp;
	t_hash	**hash;

	x = 0;
	while (str[x] != 0)
		x++;
	*size = x;
	hash = init_zhash(x);
	x = 0;
	while (str[x] != 0)
	{
		tmp = str[x];
		while (*str[x] != '=')
			str[x] += 1;
		*str[x]++ = '\0';
		hash_push(hash, tmp, str[x], ihash(tmp, *size));
		x++;
	}
	return (hash);
}
