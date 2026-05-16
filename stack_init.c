#include "push_swap.h"

/*int	error_syntax(char *nbr)
{
	return (1);
}*/

int	error_repetition(t_stack *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	stack_init(t_stack **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (*argv)
	{
		//if (error_syntax(argv[i])) // not done
		//	return ; //error_free
		nbr = ft_atol(*argv);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return ; //error_free
		if (error_repetition(*a, (int)nbr))
			return ; //error_free
		append_node(a, (int)nbr);
		i++;
	}
}
