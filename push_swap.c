#include "push_swap.h"

void display_stacks(t_stack *a, t_stack *b)
{
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
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	is_sorted;
	int	len_a;
	
	(void)b;
	is_sorted = check_sort(*a);
	ft_printf(is_sorted ? "Sorted\n" : "Not sorted\n");
	ft_printf("Disorder: %d\n\n", compute_disorder(*a));
	len_a = stack_len(*a);
	if (is_sorted)
		return ;
	if (len_a <= 3)
		tiny_sort(a);
	else if (len_a > 3 && len_a <= 5)
		(void)b; // handle_five 
	else if (len_a > 5)
		medium_sort(a, b, len_a);
}

int	main(int args, char **argv)
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	char	**split;

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
	push_swap(&a, &b);
	display_stacks(a, b);
}
