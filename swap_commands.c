#include "push_swap.h"

void	sa(t_stack *a, int display)
{
	int	temp;

	if (!a)
		return ;
	temp = a->value;
	a->value = a->next->value;
	a->next->value = temp;
	if (display)
		write(1, "sa\n", 3);
}

void	pa(t_stack *a, t_stack *b, int display)
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
	temp = last_a->value;
	last_a->value = last_b->value;
	last_b->value = temp;
	if (display)
		write(1, "pa\n", 3);
}

void	ra(t_stack *a, int display)
{
	t_stack	*last;
	int		temp;

	if (!a)
		return ;
	last = ft_stacklast(a);
	if (!last)
		return ;
	temp = a->value;
	a->value = last->value;
	last->value = temp;
	if (display)
		write(1, "ra\n", 3);
}

void	rra(t_stack *a, int display)
{
	int	tmp;

	if (!a)
		return ;
	tmp = a->value;
	while (a->next)
	{
		a->value = a->next->value;
		a = a->next;
	}
	a->value = tmp;
	if (display)
		write(1, "rra\n", 4);
}

















