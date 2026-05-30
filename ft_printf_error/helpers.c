/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:11:31 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/02 14:11:32 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_error.h"

int	error_get_hex_len(unsigned long n)
{
	int	len;

	len = 0;
	if (!n)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

char	error_get_hex(int i)
{
	char	*base;

	if (i > 15)
		return ('x');
	base = "0123456789abcdef";
	return (base[i]);
}

char	*error_convert_base_hex(unsigned long n)
{
	char	*res;
	int		len;

	len = error_get_hex_len(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = error_get_hex(n % 16);
		if (res[len] == 'x')
		{
			free(res);
			return (NULL);
		}
		n /= 16;
		len--;
	}
	return (res);
}

void	error_ft_strupper_hex(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'f')
			*s -= 32;
		s++;
	}
}
