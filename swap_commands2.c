/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:02:17 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/19 19:02:18 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *b, int display)
{
	int	temp;

	if (!b || !b->next)
		return ;
	temp = b->value;
	b->value = b->next->value;
	b->next->value = temp;
	if (display)
		write(1, "sb\n", 3);
}

void	pb(t_stack **b, t_stack **a, int display)
{
	t_stack	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	temp->next = *b;
	temp->prev = NULL;
	if (*b)
		(*b)->prev = temp;
	*b = temp;
	if (display)
		write(1, "pb\n", 3);
}

void	rb(t_stack **b, int display)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	last = ft_stacklast(*b);
	*b = first->next;
	(*b)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	if (display)
		write(1, "rb\n", 3);
}

void	rrb(t_stack **b, int display)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	last = ft_stacklast(*b);
	first = *b;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*b = last;
	if (display)
		write(1, "rrb\n", 4);
}
