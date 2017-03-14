#include "minishell.h"

void	execute_cmd(char *url, char **en)
{
	
}
int		searchexec(char *path, char *cmd, t_hash **table)
{
	DIR 			*folder;
	struct dirent 	*file;
	char			*url;

	url = ft_strdup("");
	if ((folder = opendir(path))== 0)
		return (0);
	while ((file = readdir(folder)))
	{
		if (ft_strcmp(cmd, file->d_name) == 0)
		{
			url = ft_strjoinf(url, path);
			url = ft_strjoinf(url, "/");
			url = ft_strjoinf(url, file->d_name);
			execute_cmd(url, hashtochar(table));
			return (1);
		}
	}
	(void)closedir(folder);
	return (0);
}

void	handle_cmd(char *cmd, t_hash **table, int size)
{
	char *path;
	char *s;
	char tmp;
	
	path = fhash(table, "PATH", size);
	while (*path)
	{
		s = path;
		while (*path && *path != ':')
			path++;
		tmp = *path;
		*path = 0;
		if (searchexec(s, cmd, table))
			return ;
		*path++ = tmp;
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": commmand not found", 2);
	free(cmd);
}

char	*read_cmd()
{
	char	 *cmd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*ptr;

	cmd = ft_strdup("");
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
		t = ft_strjoinf(t, fhash(table, "LOGNAME", size));
		t = ft_strjoinf(t, " ~ ");
		t = ft_strjoinf(t, fhash(table, "HOSTNAME", size));
		t = ft_strjoinf(t, " :");
		ft_putstr(t);
		free(t);
		handle_cmd(read_cmd(), table, size);
	}
}
