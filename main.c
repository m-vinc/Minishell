#include "minishell.h"

void	noflag(int argc, char **argv)
{
	argc++;
	argv += 1;
}
int 	main(int argc, char **argv, char **en)
{
	t_hash 	**table;
	int 	size;

	noflag(argc, argv);
	table = create_hashtable(en, &size);
	prompt(fhash(table, "LOGNAME", size), fhash(table, "HOSTNAME", size));
	hash_free(table, size);
	return (0);
}
