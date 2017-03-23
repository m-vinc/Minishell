/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:02:46 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/23 16:03:23 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		free_split(char **spt, int index)
{
	while (spt[index])
		free(spt[index++]);
	free(spt);
}

static char	*makeurl(char *file, char *path)
{
	char *tmp;

	tmp = ft_strdup("\0");
	tmp = ft_strjoinf(tmp, path);
	tmp = ft_strjoinf(tmp, "/");
	tmp = ft_strjoinf(tmp, file);
	return (tmp);
}

char		*get_path(char **path, char *file)
{
	DIR				*folder;
	struct dirent	*dfile;
	int				x;
	char			*url;

	x = 0;
	while (path[x] != 0)
	{
		if ((folder = opendir(path[x])) != 0)
		{
			while ((dfile = readdir(folder)))
				if (ft_strcmp(dfile->d_name, file) == 0)
				{
					url = makeurl(dfile->d_name, path[x]);
					free_split(path, x);
					(void)closedir(folder);
					return (url);
				}
			(void)closedir(folder);
		}
		free(path[x]);
		x++;
	}
	free(path);
	return (0);
}
