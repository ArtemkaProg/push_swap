#include "push_swap.h"

int compute_disorder(t_stack *a)
{
	t_stack	*current_i;
	t_stack	*current_j;
	int	mistakes;
	int	total_pairs;

	current_i = a;
	mistakes = 0;
	total_pairs = 0;
	while (current_i->next)
	{
		current_j = current_i->next;
		while (current_j)
		{
			total_pairs++;
			if (current_i->value > current_j->value)
				mistakes++;
			current_j = current_j->next;
		}
		current_i = current_i->next;
	}
	return (mistakes);
}

int	check_sort(t_stack *a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	simple_sort(t_stack *a) // <= 3 elements
{
	if (a->value > a->next->value && a->value > a->next->next->value)
		ra(a, 1);
	else if (a->next->value > a->value && a->next->value > a->next->next->value)
		rra(a, 1);
	if (a->value > a->next->value)
		sa(a, 1);
}
