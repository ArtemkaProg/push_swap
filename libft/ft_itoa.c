#include "libft.h"

int	get_len(long n)
{
	int	res;

	if (n == 0)
		return (1);
	res = 0;
	while (n > 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n) // -324
{
	char	*res;
	long	nb;
	int	len;
	int	is_negative;
	int	i;

	nb = n;
	is_negative = 0;
	if (nb < 0)
	{
		is_negative = 1;
		nb = -nb;
	}
	len = get_len(nb);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = len - 1;
	if (is_negative)
		res[i--] = '-';
	while (nb > 0)
	{
		res[i--] = nb % 10 + '0';
		nb /= 10;
	}
	res[i] = '\0';
	return (res);
}
