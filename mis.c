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
void	hash_free(t_hash **table)
{
	
}
