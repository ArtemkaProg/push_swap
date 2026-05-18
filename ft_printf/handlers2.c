/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:11:53 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/02 15:06:43 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hex(va_list *ap, int uppercase)
{
	char	*res;
	int		len;

	res = convert_base_hex(va_arg(*ap, unsigned int));
	if (!res)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (uppercase)
		ft_strupper_hex(res);
	len = ft_putstr(res);
	free(res);
	return (len);
}

int	handle_pointer(va_list *ap)
{
	char			*res;
	int				len;
	unsigned long	n;

	n = (unsigned long)va_arg(*ap, void *);
	if (!n)
	{
		ft_putstr("(nil)");
		return (5);
	}
	res = convert_base_hex(n);
	if (!res)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_putstr("0x") + ft_putstr(res);
	free(res);
	return (len);
}

int	handle_unsigneddecimal(va_list *ap)
{
	unsigned int	res;

	res = (unsigned int)va_arg(*ap, unsigned int);
	return (ft_putnbr(res));
}
