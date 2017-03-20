#include "minishell.h"
#include <limits.h>

void	execute_cmd(char *cmd, char *rcmd, t_env env, char *save)
{
	char 	**av;
	int		fn;

	av = ft_strsplit(cmd, ' ');
	free(av[0]);
	av[0] = ft_strdup(rcmd);
	if ((fn = is_builtins(rcmd)) != -1)
	{
		free(cmd);
		free(rcmd);
		free(save);
		execute_builtins(av, fn, env);
	}
	else
	{
		fork_and_exec(rcmd, av, env);
		(cmd ? free(cmd) : 0);
		(rcmd ? free(rcmd) : 0);
		(save ? free(save) : 0);
	}
	free(av[0]);
	free_split(av, 1);
}
char	*search_exec(char *cmd, t_env env)
{
	struct stat		info;
	char			**path;
	int				x;
	char			*url;
	char			**tmp;

	tmp  = fhash(env.table, "PATH", env.table_size);
	x = 0;
	url = 0;
	if (cmd == 0)
		return (0);
	if ((is_builtins(cmd) != -1))
		return (cmd);
	if ((stat(cmd, &info)) == -1)
	{
		if (tmp != 0)
		{
			path = ft_strsplit(*tmp, ':');
			url = get_path(path, cmd);
		}
		free(cmd);
		return ((url == 0 ? 0 : url));
	}
	else
		return (cmd);
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
	(rcmd == 0 ? w_error(save, cmd) : execute_cmd(cmd, rcmd, env, save));
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
	char	str[UCHAR_MAX];

	while (1)
	{
		getcwd(str, UCHAR_MAX);
		tmp = *fhash(env.table, "USER", env.table_size);
		t = ft_strdup("");
		t = ft_strjoinf(t, (tmp == 0 ? "" : tmp));
		t = ft_strjoinf(t, "@");
		t = ft_strjoinf(t, str);
		t = ft_strjoinf(t, " => ");
		ft_putstr(t);
		free(t);
		handle_cmd(read_cmd(), env);
	}
}
