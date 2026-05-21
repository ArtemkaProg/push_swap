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

static t_stack	*find_highest(t_stack *a)
{
	t_stack	*highest;

	highest = a;
	while (a)
	{
		if (a->value > highest->value)
			highest = a;
		a = a->next;
	}
	return (highest);
}

static t_stack	*find_smallest(t_stack *a)
{
	t_stack	*smallest;

	smallest = a;
	while (a)
	{
		if (a->value < smallest->value)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}

void	tiny_sort(t_stack *a) // <= 3 elements
{
	t_stack	*highest_node;

	highest_node = find_highest(a);
	if (a == highest_node)
		ra(a, 1);
	else if (a->next == highest_node)
		rra(a, 1);
	if (a->value > a->next->value)
		sa(a, 1);
}

void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_value;

	while (b)
	{
		best_match_value = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_value)
			{
				best_match_value = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_value == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/*void	medium_sort(t_stack **a, t_stack **b)
{
	set_target_node(*a, *b);
}*/
