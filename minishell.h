#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# define BUFF_SIZE 8
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>

typedef struct	s_hash
{
	char			*index;
	char			*data;
	struct	s_hash	*next;
}				t_hash;
typedef struct	s_env
{
	char	**env;
	t_hash	**table;
	int		table_size;
}				t_env;
char		**gen_av(char *base, char *command);
t_hash		**create_hashtable(char **str, int *size);
void		*w_malloc(size_t size);
int			ihash(char *str, int size);
char		*fhash(t_hash **table, char *str, int size);
void		hash_free(t_hash **table, int size);
void		prompt(t_env env);
char		*ft_strjoinf(char *one, char *two);
void		handle_cmd(char *cmd, t_env env);
char		*read_cmd();
void		w_exit(int no, t_hash **table, int size);
void		w_error(char *file);
void		free_split(char **spt, int index);
void		exec_cmd(char *cmd, char **av, t_env env);
int			isbuiltins(char *cmd);
char		*search_exec(char *cmd, t_env env);
char		*get_path(char **path, char *file);
#endif
