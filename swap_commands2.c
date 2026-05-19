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

void	rb(t_stack *b, int display)
{
	int	temp;

	if (!b)
		return ;
	temp = b->value;
	while (b->next)
	{
		b->value = b->next->value;
		b = b->next;
	}
	b->value = temp;
	if (display)
		write(1, "rb\n", 3);
}

void	rrb(t_stack *b, int display)
{
	int	temp;

	if (!b)
		return ;
	b = ft_stacklast(b);
	if (!b)
		return ;
	temp = b->value;
	while (b->prev)
	{
		b->value = b->prev->value;
		b = b->prev;
	}
	b->value = temp;
	if (display)
		write(1, "rrb\n", 4);
}
