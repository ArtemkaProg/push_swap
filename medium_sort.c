#include "push_swap.h"

static t_stack	*return_cheapest(t_stack *b)
{
	int	cheapest_value;
	t_stack	*cheapest;

	if (b == NULL)
		return (NULL);
	cheapest_value = INT_MAX;
	cheapest = b;
	while (b)
	{
		if (b->push_price < cheapest_value)
		{
			cheapest_value = b->push_price;
			cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}

void	move_nodes(t_stack **a, t_stack **b, t_counter *c)
{
	t_stack	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node, c);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node, c);
	finish_rotation(b, cheapest_node, 'b', c);
	finish_rotation(a, cheapest_node->target_node, 'a', c);
	pa(a, b, 1, c);
}

void	medium_sort(t_stack **a, t_stack **b, int len_a, t_counter *c)
{
	t_stack	*smallest;

	while (len_a-- > 5)
		pb(b, a, 1, c);
	handle_five(a, b, c);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b, c);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, 1, c);
	else
		while (*a != smallest)
			rra(a, 1, c);
}
