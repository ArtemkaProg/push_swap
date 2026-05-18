#include "push_swap.h"

void	sb(t_stack *b, int display)
{
	int	temp;

	if (!b)
		return ;
	temp = b->value;
	b->value = b->next->value;
	b->next->value = temp;
	if (display)
		write(1, "sb\n", 3);
}

void	pb(t_stack *b, t_stack *a, int display)
{
	t_stack	*last_a;
	t_stack	*last_b;
	int		temp;

	if (!a || !b)
		return ;
	last_a = ft_stacklast(a);
	last_b = ft_stacklast(b);
	if (!last_a || !last_b)
		return ;
	temp = last_b->value;
	last_b->value = last_a->value;
	last_a->value = temp;
	if (display)
		write(1, "pb\n", 3);
}

void	rb(t_stack *b, int display)
{
	t_stack	*last;
	int		temp;

	if (!b)
		return ;
	last = ft_stacklast(b);
	if (!last)
		return ;
	temp = b->value;
	b->value = last->value;
	last->value = temp;
	if (display)
		write(1, "rb\n", 3);
}

void	rrb(t_stack *b, int display)
{
	int	tmp;

	if (!b)
		return ;
	tmp = b->value;
	while (b->next)
	{
		b->value = b->next->value;
		b = b->next;
	}
	b->value = tmp;
	if (display)
		write(1, "rrb\n", 4);
}

















