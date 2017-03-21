#include "minishell.h"

char	**gen_av(char *base, char *command)
{
	char **spt;

	spt = ft_strsplit(base, ' ');
	free(spt[0]);
	spt[0] = ft_strdup(command);
	return (spt);
}
