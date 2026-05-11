#include "ft_printf.h"

int	dispatch(char specifier, va_list *ap)
{
	switch (specifier)
	{
		case 'd': return (handle_int(ap));
		case 'i': return (handle_int(ap));
		case 'c': return (handle_char(ap));
		case 's': return (handle_str(ap));
		case 'x': return (handle_hex(ap, 0));
		case 'X': return (handle_hex(ap, 1));
		case 'p': return (handle_pointer(ap));
		case 'u': return (handle_unsigneddecimal(ap));
		case '%': write(1, "%", 1); return (1);
	}
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		total;
	
	total = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
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
	return (total);
}
