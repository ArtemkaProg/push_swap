#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	fd_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
