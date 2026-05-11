#include "libft.h"

int	count_words(char const *s, char c)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			res++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (res);
}

char	*ft_strdup(const char *s, size_t len)
{
	char	*res;
	
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s, len + 1);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t		words;
	size_t		i;
	size_t		start;
	size_t		current_word;

	words = count_words(s, c);
	strs = malloc((words + 1) * sizeof(char *));
	i = 0;
	current_word = 0;
	while (current_word < words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		strs[current_word] = ft_strdup(&s[start], i - start);
		if (!start[current_word])
			return (NULL);
		current_word++;
	}
	start[current_word] = NULL;
	return (strs);
}
