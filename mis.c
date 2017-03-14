#include "minishell.h"

void	*w_malloc(size_t	size)
{
	void	*m;

	if ((m = malloc(size)) == 0)
	{
		exit(1);
	}
	return (m);
}
void	hash_free(t_hash **table, int size)
{
	int 	x;
	t_hash	*tmp;

	x = 0;
	while (x < size)
	{
		while (table[x])
		{
			if (table[x]->data)
				free(table[x]->data);
			if (table[x]->index)
				free(table[x]->index);
			tmp = table[x];
			table[x] = table[x]->next;
			free(tmp);
		}
		free(table[x]);
		table[x] = 0;
		x++;
	}
	free(table);
}
