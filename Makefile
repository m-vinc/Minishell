CFILE= srcs/hash_2.c \
srcs/setenv.c \
srcs/env.c \
srcs/cd.c \
srcs/mis_2.c \
srcs/command.c \
srcs/read_path.c \
srcs/main.c srcs/hash.c \
srcs/mis.c \
srcs/prompt.c \
srcs/builtins.c

OFILE=$(CFILE:.c=.o)
FLAG=  -I includes -Wall -Werror #-Wextra -g -Wno-unused-but-set-parameter -Wno-unused-but-set-variable
NAME= minishell
LIB= libft/libft.a

all: $(NAME)


$(NAME): $(CFILE) $(OFILE)
	make -C libft/
	gcc -o $@ $(FLAG) $(OFILE) $(LIB)
.c.o:
	gcc -c $< -o $@ $(FLAG)
clean:
	rm -f $(OFILE)
	make -C libft/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
re: fclean all
