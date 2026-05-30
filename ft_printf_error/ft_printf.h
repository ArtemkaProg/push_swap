/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:11:47 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/02 14:59:02 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...);
int		dispatch(char specifier, va_list *ap);
int		handle_unsigneddecimal(va_list *ap);
int		handle_pointer(va_list *ap);
int		handle_hex(va_list *ap, int uppercase);
int		handle_str(va_list *ap);
int		handle_char(va_list *ap);
int		handle_int(va_list *ap);
void	ft_strupper_hex(char *s);
int		ft_putstr(char *s);
int		ft_putnbr(long n);
int		ft_putchar(char c);
char	*convert_base_hex(unsigned long n);
char	get_hex(int i);
int		get_hex_len(unsigned long n);

#endif
