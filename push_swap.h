#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int		value;
	//int		index;
	struct s_stack *prev;
	struct s_stack *next;
}		t_stack;

long	ft_atol(const char *nptr);
void	stack_init(t_stack **a, char **argv);
t_stack	*ft_stacklast(t_stack *a);
void	append_node(t_stack **stack, int nbr);
char	**ft_split(char	const *s, char c);
int	error_repetition(t_stack *a, int nbr);

#endif
