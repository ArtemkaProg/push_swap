#include "push_swap.h"

t_stack *ft_stacklast(t_stack *a)
{
	if (!a)
		return (NULL);
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
		if (!last_node)
			return ;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

int	get_stack_len(t_stack *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
