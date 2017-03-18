/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:50:11 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/16 18:32:37 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	echo(char **av)
{
	int		x;
	int		space;

	space = 0;
	x = 1;
	while (av[x] != 0)
	{
		if (space == 1)
		{
			ft_putchar(' ');
			space = 0;
		}
		ft_putstr(av[x++]);
		space = 1;
	}
	ft_putchar('\n');
}
void	cd(char **av, t_env env)
{
	int		x;
	int		err;

	err = 0;
	x = 1;
	while (av[x] != 0)
		x++;
	if (x > 2)
	{
		ft_putendl("cd: too many argument");
		return ;
	}
	if (!av[1])
	{
		chdirabs(*fhash(env.table, "HOME", env.table_size), env);
	}
	else
	{
		(av[1][0] == '/' ? chdirabs(av[1], env) : chdirrel(av[1], env));
	}
}
void	execute_builtins(char **av, int fn, t_env env)
{
	if (fn == 0)
		echo(av);
	if (fn == 1)
		cd(av, env);
	if (fn == 2)
		my_setenv(av, env);
	if (fn == 3)
		my_unsetenv(av, env);
	if (fn == 5)
	{
		free_split(av, 0);
		w_exit(42, env);
	}
	if (fn == 4)
		env_cmd(av, env);
	return ;
}
