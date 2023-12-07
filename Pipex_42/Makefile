FLAGS:= -Wall -Werror -Wextra

NAME:= pipex

PATH_LIBFT:= libft
LIBFT:= libft.a

FUNCTIONS:= pipex_bonus pipex_bonus_utils

all: $(NAME)
	
$(NAME):
	gcc $(FLAGS) $(patsubst %, %.c, $(FUNCTIONS)) $(PATH_LIBFT)/$(LIBFT) -o $(NAME)

libft: $(LIBFT)

$(LIBFT):
	cd $(PATH_LIBFT) && make all

#bonus:
	
clean: 
	rm -f $(NAME)

fclean: clean
	cd $(PATH_LIBFT) && make fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus