#include "minishell.h"

void	handle_cmd(char *cmd)
{
	ft_putendl(cmd);
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

void	prompt(char *user, char *host)
{
	char	*t;

	while (1)
	{
		t = ft_strdup("");
		t = ft_strjoinf(t, user);
		t = ft_strjoinf(t, " ~ ");
		t = ft_strjoinf(t, host);
		t = ft_strjoinf(t, " :");
		ft_putstr(t);
		free(t);
		handle_cmd(read_cmd());
	}
}
