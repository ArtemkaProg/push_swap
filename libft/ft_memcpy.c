#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d_ptr;
	unsigned char *s_ptr;
	
	if (!dest && !src)
		return (NULL);
	d_ptr = (void *)dest;
	s_ptr = (void *)src;
	while (n--)
		*d_ptr++ = (unsigned char)*s_ptr++;
	return (dest);
}
