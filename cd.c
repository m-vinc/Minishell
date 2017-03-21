/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:44:23 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/16 19:22:47 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(char *str, t_env env, int mode)
{
	char 	**oldpwd;
	
	if (mode == 1)
		oldpwd = fhash(env.table, "OLDPWD", env.table_size);
	else
		oldpwd = fhash(env.table, "PWD", env.table_size);
	if (oldpwd != 0)
	{
		free(*oldpwd);
		*oldpwd = ft_strdup(str);
	}
}

void	chdirrel(char *path, t_env env)
{
	char 	str[PATH_MAX];
	char	*abspath;
	char	**opwd;

	opwd = fhash(env.table, "OLDPWD", env.table_size);
	if (getcwd(str, PATH_MAX) == 0)
	{
		ft_putendl("cd: Error");
		return ;
	}
	if (path[0] == '-' && path[1] == '\0')
	{
		if (opwd == 0)
		{
			ft_putendl("cd: OLDPWD not set");
			return ;
		}
		else
			abspath = ft_strdup(*opwd);
	}
	else
	{
		abspath = ft_strjoin(str, "/");
		abspath = ft_strjoinf(abspath, path);
	}
	update_pwd(str, env, 1);
	chdirabs(abspath, env);
	free(abspath);
}
void	chdirabs(char *path, t_env env)
{
	char	str[UCHAR_MAX];

	if (getcwd(str, UCHAR_MAX) == 0)
	{
		ft_putendl("cd: Error");
	}
	else
		update_pwd(str, env, 1);
	if (chdir(path) == -1)
		ft_putendl("cd: no such file or directory");
	else
		update_pwd(path, env, 0);
}
