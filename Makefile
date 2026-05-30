NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF = ft_printf/libftprintf.a
PRINTF_ERR = ft_printf_error/libftprintf_error.a

SRCS = push_swap.c stack_init.c stack_utils.c swap_commands.c swap_commands2.c swap_commands3.c utils.c sort.c handle_five.c simple_sort.c medium_init.c medium_rotate.c medium_sort.c radix_sort.c args.c benchmarck.c
OBJS = $(SRCS:.c=.o)

all: $(PRINTF) $(PRINTF_ERR) $(NAME)

$(PRINTF):
	make -C ft_printf

$(PRINTF_ERR):
	make -C ft_printf_error

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(PRINTF_ERR) -o $(NAME)

clean:
	make -C ft_printf clean
	make -C ft_printf_error clean
	rm -f $(OBJS)

fclean: clean
	make -C ft_printf fclean
	make -C ft_printf_error fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
