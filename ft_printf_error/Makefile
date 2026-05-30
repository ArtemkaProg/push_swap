NAME = libftprintf_error.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS = ft_printf_error.c handlers.c handlers2.c helpers.c output.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
