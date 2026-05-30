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

#include "ft_printf_error.h"

int	error_ft_putchar(char c)
{
	write(2, &c, 1);
	return (1);
}

int	error_ft_putnbr(long n)
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
		total += error_ft_putnbr(n / 10);
	tmp = n % 10 + '0';
	write(2, &tmp, 1);
	total++;
	return (total);
}

int	error_ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	return (i);
}
