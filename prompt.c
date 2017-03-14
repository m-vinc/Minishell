#include "minishell.h"

void	exec_cmd(char *path, t_hash **table, int size)
{
	char *s;

	s = fhash(table, "TERM", size);
	free(path);
}

int		searchexec(char *path, char *cmd, t_hash **table)
{
	DIR 			*folder;
	struct dirent 	*file;
	char			*url;

	url = ft_strdup("");
	folder = 0;
	if ((folder = opendir(path)) == 0)
		return (0);
	while ((file = readdir(folder)))
	{
		if (ft_strcmp(cmd, file->d_name) == 0)
		{
			url = ft_strjoinf(url, path);
			url = ft_strjoinf(url, "/");
			url = ft_strjoinf(url, file->d_name);
			exec_cmd(url, table, size);
			free(cmd);
			(void)closedir(folder);
			return (1);
		}
	}
	free(url);
	(void)closedir(folder);
	return (0);
}

void	handle_cmd(char *cmd, t_hash **table, int size)
{
	char 	*path;
	char	**pp;
	int		x;

	x = 0;
	if (ft_strcmp(cmd, "exit") == 0)
		w_exit(0, table, size);
	path = fhash(table, "PATH", size);
	pp = ft_strsplit(path, ':');
	while (pp[x] != 0)
	{
		if (searchexec(pp[x], cmd, table, size))
		{
			while (pp[x] != 0)
				free(pp[x++]);
			free(pp);
			return ;
		}
		free(pp[x]);
		x++;
	}
	free(pp);
	w_error(cmd);
	free(cmd);
}

char	*read_cmd()
{
	char	 *cmd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*ptr;

	cmd = ft_strdup("\0");
	while ((ret = read(0, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if ((ptr = ft_strchr(buf, '\n')) == 0)
			cmd = ft_strjoinf(cmd, buf);
		else
		{
			*ptr = '\0';
			cmd = ft_strjoinf(cmd, buf);
			return (cmd);
		}
	}
	return (cmd);
}

void	prompt(t_hash **table, int size)
{
	char	*t;

	while (1)
	{
		t = ft_strdup("");
		t = ft_strjoinf(t, fhash(table, "USER", size));
		t = ft_strjoinf(t, "@");
		t = ft_strjoinf(t, fhash(table, "LOGNAME", size));
		t = ft_strjoinf(t, " => ");
		ft_putstr(t);
		free(t);
		handle_cmd(read_cmd(), table, size);
	}
}
