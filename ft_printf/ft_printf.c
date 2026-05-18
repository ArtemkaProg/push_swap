/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:11:14 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/02 15:17:47 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dispatch(char specifier, va_list *ap)
{
	if (specifier == 'd')
		return (handle_int(ap));
	if (specifier == 'i')
		return (handle_int(ap));
	if (specifier == 'c')
		return (handle_char(ap));
	if (specifier == 's')
		return (handle_str(ap));
	if (specifier == 'x')
		return (handle_hex(ap, 0));
	if (specifier == 'X')
		return (handle_hex(ap, 1));
	if (specifier == 'p')
		return (handle_pointer(ap));
	if (specifier == 'u')
		return (handle_unsigneddecimal(ap));
	if (specifier == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	is_format(char c)
{
	char	*s;

	s = "cspdiuxX%";
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		total;

	total = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && is_format(*(fmt + 1)))
		{
			fmt++;
			total += dispatch(*fmt, &ap);
		}
		else
		{
			write(1, fmt, 1);
			total++;
		}
		fmt++;
	}
	va_end(ap);
	return (total);
}
