#include "minishell.h"

int		is_builtins(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (0);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "setenv") == 0)
		return (2);
	if (ft_strcmp(cmd, "unsetenv") == 0)
		return (3);
	if (ft_strcmp(cmd, "env") == 0)
		return (4);
	if (ft_strcmp(cmd, "exit") == 0)
		return (5);
	return (-1);
}
