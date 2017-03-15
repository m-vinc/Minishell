/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:50:11 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/15 18:12:06 by vmorvan          ###   ########.fr       */
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
void	execute_builtins(char **av, int fn)
{
	if (fn == 0)
	{
		echo(av);
	}
	return ;
}
