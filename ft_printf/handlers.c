#include "ft_printf.h"

int handle_int(va_list *ap)
{
    return(ft_putnbr(va_arg(*ap, int)));
}

int handle_char(va_list *ap)
{
    ft_putchar(va_arg(*ap, int));
    return (1);
}

int handle_str(va_list *ap)
{
    char *res;

    res = va_arg(*ap, char *);
    if (!res)
    {
        ft_putstr("(null)");
        return (6);
    }
    return(ft_putstr(res));
}

int handle_hex(va_list *ap, int uppercase)
{
    char *res;
    int len;

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

int handle_pointer(va_list *ap)
{
    char *res;
    int len;
    unsigned long n = (unsigned long)va_arg(*ap, void *);

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
    return (len);
}

int handle_unsigneddecimal(va_list *ap)
{
    unsigned int res;
    
    res = (unsigned int)va_arg(*ap, unsigned int);
    return(ft_putnbr(res));
}
