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

int	main(int args, char **argv)
{
	t_stack	*a;
	//t_stack	*b;

	if (args == 1 || (args == 2 && !argv[1][0]))
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (args == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1);
	ft_printf("\ncompiles\n");
	return (0);
}
