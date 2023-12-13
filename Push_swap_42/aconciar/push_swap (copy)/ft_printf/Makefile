NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs

SRCS = ft_printf.c \
	ft_printf_utils.c \
	ft_dec.c \
	ft_ptr_void.c \
	ft_string.c \
	ft_unsigned.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re