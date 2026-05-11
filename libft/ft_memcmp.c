#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t	i;

	p1 = (void *)s1;
	p2 = (void *)s2;
	i = 0;
	while (i < n && *p1 == *p2)
	{
		p1++;
		p2++;
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)*p1 - (unsigned char)*p2);
}
