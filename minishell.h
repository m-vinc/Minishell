#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# define BUFF_SIZE 8
typedef struct	s_hash
{
	char			*index;
	char			*data;
	struct	s_hash	*next;
}				t_hash;

t_hash	**create_hashtable(char **str, int *size);
void	*w_malloc(size_t size);
int		ihash(char *str, int size);
char	*fhash(t_hash **table, char *str, int size);
void	hash_free(t_hash **table, int size);
void	prompt(char *user, char *host);
char	*ft_strjoinf(char *one, char *two);
void	handle_cmd(char *cmd);
char	*read_cmd();
#endif
