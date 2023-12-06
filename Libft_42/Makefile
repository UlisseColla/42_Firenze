FLAGS:= -Wall -Werror -Wextra
NAME:= libft.a
LST_PATH:= ft_lst/

FILES:= ./ft_is/ft_isalpha.c \
		./ft_is/ft_isdigit.c \
		./ft_is/ft_isalnum.c \
		./ft_is/ft_isascii.c \
		./ft_is/ft_isprint.c \
		./ft_mem/ft_memset.c \
		./ft_mem/ft_bzero.c \
		./ft_mem/ft_memcpy.c \
		./ft_mem/ft_memmove.c \
		./ft_mem/ft_memchr.c \
		./ft_mem/ft_memcmp.c \
		./ft_str/ft_strlen.c \
		./ft_str/ft_strlcpy.c \
		./ft_str/ft_strlcat.c \
		./ft_str/ft_strchr.c \
		./ft_str/ft_strrchr.c \
		./ft_str/ft_strncmp.c \
		./ft_str/ft_strnstr.c \
		./ft_str/ft_substr.c \
		./ft_str/ft_strjoin.c \
		./ft_str/ft_strtrim.c \
		./ft_str/ft_split.c \
		./ft_str/ft_calloc.c \
		./ft_str/ft_strdup.c \
		./ft_convert/ft_toupper.c \
		./ft_convert/ft_tolower.c \
		./ft_convert/ft_atoi.c \
		./ft_convert/ft_itoa.c \
		./ft_convert/ft_strmapi.c \
		./ft_convert/ft_striteri.c \
		./ft_fd/ft_putchar_fd.c \
		./ft_fd/ft_putstr_fd.c \
		./ft_fd/ft_putendl_fd.c \
		./ft_fd/ft_putnbr_fd.c \
		./ft_lst/ft_lstnew.c \
		./ft_lst/ft_lstadd_front.c \
		./ft_lst/ft_lstsize.c \
		./ft_lst/ft_lstlast.c \
		./ft_lst/ft_lstadd_back.c \
		./ft_lst/ft_lstdelone.c \
		./ft_lst/ft_lstclear.c \
		./ft_lst/ft_lstiter.c \
		./ft_lst/ft_lstmap.c \
		./ft_printf/
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \

OBJECTS:= ${FILES:.c=.o}

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ -Iheaders
	
$(NAME): $(OBJECTS)
	@echo Creazione della libreria
	@ar -rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean: 
	@rm -f $(OBJECTS)
	@echo Eliminati i file oggetto

fclean: clean
	@rm -f $(NAME)
	@echo Eliminata libreria

re: fclean all

.PHONY: all clean fclean re bonus