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

#include "ft_printf_error.h"

int	error_handle_hex(va_list *ap, int uppercase)
{
	char	*res;
	int		len;

	res = error_convert_base_hex(va_arg(*ap, unsigned int));
	if (!res)
	{
		error_ft_putstr("(null)");
		return (6);
	}
	if (uppercase)
		error_ft_strupper_hex(res);
	len = error_ft_putstr(res);
	free(res);
	return (len);
}

int	error_handle_pointer(va_list *ap)
{
	char			*res;
	int				len;
	unsigned long	n;

	n = (unsigned long)va_arg(*ap, void *);
	if (!n)
	{
		error_ft_putstr("(nil)");
		return (5);
	}
	res = error_convert_base_hex(n);
	if (!res)
	{
		error_ft_putstr("(null)");
		return (6);
	}
	len = error_ft_putstr("0x") + error_ft_putstr(res);
	free(res);
	return (len);
}

int	error_handle_unsigneddecimal(va_list *ap)
{
	unsigned int	res;

	res = (unsigned int)va_arg(*ap, unsigned int);
	return (error_ft_putnbr(res));
}
