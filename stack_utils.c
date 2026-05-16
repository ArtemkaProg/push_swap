#include "push_swap.h"

t_stack *ft_stacklast(t_stack *a)
{
	while (a->next)
		a = a->next;
	return (a);
}

void	append_node(t_stack **stack, int nbr)
{
	t_stack	*last_node;
	t_stack	*new_node;

	if (stack == NULL)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = nbr;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_stacklast(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
