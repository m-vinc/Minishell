#include "minishell.h"

char		*ft_strappend(char *file, char *buf)
{
	char	*result;

	result = ft_strjoin(file, buf);
	ft_memdel((void *)&file);
	return (result);
}

int			end_line(char **line, char *file, char **save, int fd)
{
	char	*tmp;

	if (!file[0])
	{
		*line = NULL;
		return (0);
	}
	if ((tmp = ft_strchr(file, '\n')) != NULL)
		*tmp = 0;
	*line = ft_strdup(file);
	if (tmp)
		save[fd] = ft_strdup(tmp + 1);
	else
		save[fd] = NULL;
	ft_memdel((void *)&file);
	tmp = NULL;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*save[5000];
	char			buf[BUFF_SIZE + 1];
	char			*file;
	int				ret;

	if (fd < 0 || fd > 5000 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (save[fd] != NULL)
		file = save[fd];
	else
		file = ft_strnew(0);
	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		file = ft_strappend(file, buf);
		if (ft_strchr(file, '\n') != NULL)
			return (end_line(line, file, save, fd));
	}
	if (ret == -1)
		return (-1);
	return (end_line(line, file, save, fd));
}
