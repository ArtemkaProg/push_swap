#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int		value;
	int		index;
	struct s_stack *prev;
	struct s_stack *next;
}		t_stack;

// stack_initialisation

long	ft_atol(const char *nptr);
void	stack_init(t_stack **a, char **argv);
int	error_repetition(t_stack *a, int nbr);

// stack_utils

t_stack	*ft_stacklast(t_stack *a);
void	append_node(t_stack **stack, int nbr);
int	get_stack_len(t_stack *stack);

// swap_comands

void	sa(t_stack *a, int display);
void	pa(t_stack *a, t_stack *b, int display);
void	ra(t_stack *a, int display);
void	rra(t_stack *a, int display);

void	sb(t_stack *b, int display);
void	pb(t_stack *b, t_stack *a, int display);
void	rb(t_stack *b, int display);
void	rrb(t_stack *b, int display);

void	ss(t_stack *a, t_stack *b, int display);
void	rr(t_stack *a, t_stack *b, int display);
void	rrr(t_stack *a, t_stack *b, int display);

// split

char	**ft_split(char	const *s, char c);

#endif
