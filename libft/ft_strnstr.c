#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	needle_len = 0;
	while (needle[needle_len])
		needle_len++;
	if (!needle_len)
		return ((char *)haystack);
	i = 0;
	while (i < n && haystack[i])
	{
		j = 0;
		while (i + j < n && haystack[i + j] == needle[j] && needle[j])
			j++;
		if (j == needle_len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
