#include "push_swap.h"



int	main(int args, char **argv)
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	char	**split;
	int	is_sorted;

	split = NULL;
	if (args == 1 || (args == 2 && !argv[1][0]))
	{
		ft_printf("Error: invalid input\n");
		return (0);
	}
	else if (args == 2)
	{
		split = ft_split(argv[1], ' ');
		stack_init(&a, split);
		free_split(split);
	}
	else
		stack_init(&a, argv + 1);
	if (a == NULL)
		return (0);

	is_sorted = check_sort(a);
	ft_printf(is_sorted ? "Sorted\n" : "Not sorted\n");
	ft_printf("Disorder: %d\n\n", compute_disorder(a));
	if (!is_sorted && stack_len(a) <= 3)
	{
		tiny_sort(a);
		ft_printf("\n");
	}
	ft_printf("stack a:\n");
	while (a)
	{
		ft_printf("%d ", a->value);
		a = a->next;
	}
	ft_printf("\nstack b:\n");
	while (b)
	{
		ft_printf("%d ", b->value);
		b = b->next;
	}
	ft_printf("\n");
	return (0);
}
