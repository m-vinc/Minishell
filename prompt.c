#include "minishell.h"
#include <limits.h>

void	execute_cmd(char *cmd, char *rcmd, t_env env)
{
	char **av;

	av = ft_strsplit(cmd, ' ');
	free(av[0]);
	av[0] = ft_strdup(rcmd);
	ft_putendl(av[0]);
	ft_putstr("rcmd -> ");
	ft_putendl(rcmd);
	ft_putendl_fd(fhash(env.table, "PATH", env.table_size), 2);
}

char	*search_exec(char *cmd, t_env env)
{
	struct stat		info;
	char			**path;
	int				x;
	char			*url;

	x = 0;
	if (cmd == 0)
		return (0);
	if ((stat(cmd, &info)) == -1)
	{
		path = ft_strsplit(fhash(env.table, "PATH", env.table_size), ':');
		url = get_path(path, cmd);
		free(cmd);
		return ((url == 0 ? 0 : url));
	}
	else
	{
		return (cmd);
	}
}
void	handle_cmd(char *cmd, t_env env)
{
	int		x;
	char	*rcmd;
	char	*save;
	int		y;

	y = 0;
	x = 0;
	while (cmd[x] != '\0' && (cmd[x] == ' ' || cmd[x] == '\t'))
		x++;
	while (cmd[x + y] != '\0' &&  (cmd[x + y] != ' ' && cmd[x + y] != '\t'))
		y++;
	if ((x == 0 && y == 0) || (cmd[x] == '\0'))
	{
		free(cmd);
		return ;
	}
	rcmd = ft_strsub(cmd, x, y);
	save = ft_strdup(rcmd);
	rcmd = search_exec(rcmd, env);
	(rcmd == 0 ? w_error(save) : execute_cmd(cmd, rcmd, env));
	free(cmd);
	free(rcmd);
	free(save);
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

void	prompt(t_env env)
{
	char	*t;
	char	*tmp;

	while (1)
	{
		tmp = fhash(env.table, "USER", env.table_size);
		t = ft_strdup("");
		t = ft_strjoinf(t, (tmp == 0 ? "" : tmp));
		t = ft_strjoinf(t, "@");
		tmp = fhash(env.table, "HOSTNAME", env.table_size);
		t = ft_strjoinf(t, (tmp == 0 ? "" : tmp));
		t = ft_strjoinf(t, " => ");
		ft_putstr(t);
		free(t);
		handle_cmd(read_cmd(), env);
	}
}
