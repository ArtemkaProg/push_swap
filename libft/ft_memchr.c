#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t	i;

	ptr = (void *)s;
	i = 0;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
			return ((char *)ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
