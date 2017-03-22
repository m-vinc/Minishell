#include "minishell.h"

void	fork_and_exec(char *rcmd, char **av, t_env env)
{
	pid_t	pid;
	char	**envp;
	int		x;
	struct	stat	s;

	x = 0;
	if (stat(rcmd, &s) == 0 && s.st_mode & S_IXUSR)
	{
		envp = tabletostr(env);
		pid = fork();
	}
	else
	{
		w_errornf(rcmd);
		return ;
	}
	if (pid > 0)
	{
		wait(0);
		while (x < total_element(env))
		{
			free(envp[x]);
			x++;
		}
		free(envp);
	}
	if (pid == 0)
		execve(rcmd, av, envp);
}
int		total_element(t_env env)
{
	int		x;
	int		total;
	t_hash	*save;

	total = 0;
	x = 0;
	while (x < env.table_size)
	{
		save = env.table[x];
		while (env.table[x])
		{
			total++;
			env.table[x] = env.table[x]->next;
		}
		env.table[x] = save;
		x++;
	}
	return (total);
}

char	**tabletostr(t_env env)
{
	int		element;
	char	**envstr;
	int		x;
	t_hash	*save;
	int		xstr;

	xstr = 0;
	x = 0;
	element = total_element(env);
	envstr = (char **)malloc(sizeof(char *) * (element + 1));
	envstr[element] = 0;
	while (x < env.table_size)
	{
		save = env.table[x];
		while (env.table[x])
		{
			envstr[xstr] = ft_strjoin(env.table[x]->index, "=");
			envstr[xstr] = ft_strjoinf(envstr[xstr], env.table[x]->data);
			xstr++;
			env.table[x] = env.table[x]->next;
		}
		env.table[x] = save;
		x++;
	}
	return (envstr);
}
