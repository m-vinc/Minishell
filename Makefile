CFILE= main.c hash.c mis.c

OFILE=$(CFILE:.c=.o)
FLAG= -Wall -Werror -Wextra -Wno-unused-but-set-variable
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
