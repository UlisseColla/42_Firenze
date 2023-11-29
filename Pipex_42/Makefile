FLAGS:= -Wall -Werror -Wextra

NAME:= pipex

PATH_LIBFT:= libft
LIBFT:= libft.a

FUNCTIONS:= pipex

all: $(NAME)
	
$(NAME):
	cd $(PATH_LIBFT) && make all
	gcc $(FLAGS) $(patsubst %, %.c, $(FUNCTIONS)) $(PATH_LIBFT)/$(LIBFT) -o $(NAME)

#bonus:
	
clean: 
	cd $(PATH_LIBFT) && make clean
	rm -f 

fclean: clean
	cd $(PATH_LIBFT) && make fclean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus