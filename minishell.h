#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# define BUFF_SIZE 8
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <limits.h>
# include <sys/wait.h>
# include <signal.h>

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
char		**fhash(t_hash **table, char *str, int size);
void		hash_free(t_hash **table, int size);
void		hash_push(t_hash **hash, char *index, char *str, int ihash);
void		prompt(t_env env);
char		*ft_strjoinf(char *one, char *two);
void		handle_cmd(char *cmd, t_env env);
char		*read_cmd();
void		w_exit(int no, t_env env);
void		w_error(char *file, char *fcmd);
void		free_split(char **spt, int index);
void		exec_cmd(char *cmd, char **av, t_env env, char *save);
int			is_builtins(char *cmd);
void		execute_builtins(char **av, int fn, t_env env);
char		*search_exec(char *cmd, t_env env);
char		*get_path(char **path, char *file);
void		chdirrel(char *str, t_env env);
void		chdirabs(char *str, t_env env);
void		env_cmd(char **av, t_env env);
void		my_setenv(char **av, t_env env);
void		my_unsetenv(char **av, t_env env);
t_hash		**get_ptr_hash(t_env env, char *index);
int			total_element(t_env env);
char		**tabletostr(t_env env);
void		fork_and_exec(char *rcmd, char **av, t_env env);
#endif
