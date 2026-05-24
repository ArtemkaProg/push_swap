#include "push_swap.h"

void	handle_five(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	while (len-- > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, 1);
	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
}
