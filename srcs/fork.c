/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:05:56 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/23 16:12:47 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_envp(char **envp, int size)
{
	int		x;

	x = 0;
	while (x < size)
	{
		free(envp[x]);
		x++;
	}
	free(envp);
}

void	fork_and_exec(char *rcmd, char **av, t_env env)
{
	pid_t		pid;
	char		**envp;
	int			x;
	struct stat	s;

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
		free_envp(envp, total_element(env));
	}
	if (pid == 0)
		execve(rcmd, av, envp);
}
