NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF = ft_printf/libftprintf.a

SRCS = push_swap.c stack_init.c stack_utils.c split.c
OBJS = $(SRCS:.c=.o)

all: $(PRINTF) $(NAME)

$(PRINTF):
	make -C ft_printf

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	make -C ft_printf clean
	rm -f $(OBJS)

fclean: clean
	make -C ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
