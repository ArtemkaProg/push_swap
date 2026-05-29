/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:02:17 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/26 14:48:05 by madebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b, int display, t_counter *counter)
{
	t_stack	*first;
	t_stack	*second;

	if (!b || !(*b) || !(*b)->next)
		return ;
	first = (*b);
	second = first->next;
	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	*b = second;
	if (display && counter && !counter->bench)
		write(1, "sb\n", 3);
	else if (counter)
		counter->sb++;
}

void	pb(t_stack **b, t_stack **a, int display, t_counter *c)
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
	if (display && c && !c->bench)
		write(1, "pb\n", 3);
	else if (c)
		c->pb++;
}

void	rb(t_stack **b, int display, t_counter *c)
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
	if (display && c && !c->bench)
		write(1, "rb\n", 3);
	else if (c)
		c->rb++;
}

void	rrb(t_stack **b, int display, t_counter *c)
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
	if (display && c && !c->bench)
		write(1, "rrb\n", 4);
	else if (c)
		c->rrb++;
}
