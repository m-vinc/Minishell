CFILE= srcs/hash_2.c \
srcs/setenv.c \
srcs/env.c \
srcs/cd.c \
srcs/mis_2.c \
srcs/read_path.c \
srcs/main.c srcs/hash.c \
srcs/mis.c \
srcs/prompt.c \
srcs/builtins.c \
srcs/fork.c

NO_COLOR=\033[0m
OK_COLOR=\033[32;01m
ERROR_COLOR=\033[31;01m
WARN_COLOR=\033[33;01m

OFILE=$(CFILE:.c=.o)
FLAG= -I includes -Wall -Werror -Wextra -g #-Wno-unused-but-set-variable
NAME= minishell
LIB= libft/libft.a

all: $(NAME)


$(NAME): $(CFILE) $(OFILE)
	@make -C libft/
	@echo "${WARN_COLOR}minishell:${NO_COLOR} Generating minishell -> ${OK_COLOR}$(NAME)${NO_COLOR}"
	@gcc -o $@ $(FLAG) $(OFILE) $(LIB)
.c.o:
	@echo "${WARN_COLOR}minishell:${NO_COLOR} Compile -> ${WARN_COLOR}$<${NO_COLOR} => ${OK_COLOR}$@${NO_COLOR}"
	@gcc -c $< -o $@ $(FLAG)
clean:
	@echo "${WARN_COLOR}minishell: ${NO_COLOR}${ERROR_COLOR}delete objects files${NO_COLOR}"
	@rm -f $(OFILE)
	@make -C libft/ clean
fclean: clean
	@echo "${WARN_COLOR}minishell: ${NO_COLOR}delete $(NAME)"
	@rm -f $(NAME)
	@make -C libft/ fclean
re: fclean all
