#include "push_swap.h"

int	main(int args, char **argv)
{
	t_stack *a = NULL;
	t_stack *b = NULL;

	if (args == 1 || (args == 2 && !argv[1][0]))
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (args == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1);

	sa(a, 1);
	pb(&b, &a, 1);

	while (a)
	{
		ft_printf("%d\n", a->value);
		a = a->next;
	}
	// ft_printf("\nstack: b : %d\n", b->value);
	return (0);
}
