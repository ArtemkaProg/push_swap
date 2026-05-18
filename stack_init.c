#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	res;
	int	sign;
	int	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

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
	//int		i;

	//i = 0;
	while (*argv)
	{
		//if (error_syntax(argv[i])) // not done
		//	return ; //error_free
		nbr = ft_atol(*argv);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			ft_printf("Error\n");
			return ; //error_free
		}
		if (error_repetition(*a, (int)nbr))
		{
			ft_printf("Error\n");
			return ; //error_free
		}
		append_node(a, (int)nbr);
		argv++;
	}
}
