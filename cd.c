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

char	*modify_oldpwd(t_env env, char *str)
{
	char	*abs;
	char	*oldpwd;

	oldpwd = ft_strdup(str);
	abs = ft_strdup(oldpwd);
	return (abs);
}

void	chdirrel(char *path, t_env env)
{
	char 	str[UCHAR_MAX];
	char	*abspath;

	if (getcwd(str, UCHAR_MAX) == 0)
	{
		ft_putendl("cd: Error");
		return ;
	}
	if (path[0] == '~' && path[1] == '/')
	{
		abspath = ft_strdup(fhash(env.table, "HOME", env.table_size));
		abspath = ft_strjoinf(abspath, "/");
		abspath = ft_strjoinf(abspath, path + 2);
	}
	else
		if (path[0] == '-' && path[1] == '\0')
			abspath = modify_oldpwd(env, str);
		else
		{
			abspath = ft_strjoin(str, "/");
			abspath = ft_strjoinf(abspath, path);
		}
	chdirabs(abspath, ft_strdup(str), env);
	free(abspath);
}

void	chdirabs(char *path, char *prev, t_env env)
{
	if (chdir(path) == -1)
		ft_putendl("cd: no such file or directory");
}
