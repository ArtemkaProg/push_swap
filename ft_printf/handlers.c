/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:11:25 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/02 14:30:21 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_int(va_list *ap)
{
	return (ft_putnbr(va_arg(*ap, int)));
}

int	handle_char(va_list *ap)
{
	return (ft_putchar(va_arg(*ap, int)));
}

int	handle_str(va_list *ap)
{
	char	*res;

	res = va_arg(*ap, char *);
	if (!res)
	{
		ft_putstr("(null)");
		return (6);
	}
	return (ft_putstr(res));
}
