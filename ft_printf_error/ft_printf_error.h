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

#ifndef FT_PRINTF_ERROR_H
# define FT_PRINTF_ERROR_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf_error(const char *fmt, ...);
int	error_dispatch(char specifier, va_list *ap);
int	error_handle_unsigneddecimal(va_list *ap);
int	error_handle_pointer(va_list *ap);
int	error_handle_hex(va_list *ap, int uppercase);
int	error_handle_str(va_list *ap);
int	error_handle_char(va_list *ap);
int	error_handle_int(va_list *ap);
void	error_ft_strupper_hex(char *s);
int	error_ft_putstr(char *s);
int	error_ft_putnbr(long n);
int	error_ft_putchar(char c);
char	*error_convert_base_hex(unsigned long n);
char	error_get_hex(int i);
int	error_get_hex_len(unsigned long n);

#endif
