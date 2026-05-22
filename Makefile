NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF = ft_printf/libftprintf.a

SRCS = push_swap.c stack_init.c stack_utils.c swap_commands.c swap_commands2.c swap_commands3.c utils.c sort.c medium_init.c medium_rotate.c medium_sort.c
OBJS = $(SRCS:.c=.o)

all: $(PRINTF) $(NAME)

$(PRINTF):
	make -C ft_printf

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

clean:
	make -C ft_printf clean
	rm -f $(OBJS)

fclean: clean
	make -C ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
