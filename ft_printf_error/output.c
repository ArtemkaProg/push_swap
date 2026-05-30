/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:12:03 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/02 14:14:05 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 2);
	return (1);
}

int	ft_putnbr(long n)
{
	char	tmp;
	int		total;

	total = 0;
	if (n < 0)
	{
		n = -n;
		total++;
		write(1, "-", 2);
	}
	if (n >= 10)
		total += ft_putnbr(n / 10);
	tmp = n % 10 + '0';
	write(1, &tmp, 2);
	total++;
	return (total);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 2);
		i++;
	}
	return (i);
}
