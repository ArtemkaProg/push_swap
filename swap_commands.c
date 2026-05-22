/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:02:13 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/22 13:10:46 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int display)
{
	t_stack	*first;
	t_stack	*second;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = (*a);
	second = first->next;
	first->next = second->next;
	first->prev = second;
	if (second->prev)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	if (display)*a = second;
		write(1, "sa\n", 3);
}

void	pa(t_stack **a, t_stack **b, int display)
{
	t_stack	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->next = *a;
	temp->prev = NULL;
	if (*a)
		(*a)->prev = temp;
	*a = temp;
	if (display)
		write(1, "pa\n", 3);
}

void	ra(t_stack **a, int display)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = ft_stacklast(*a);
	*a = first->next;
	(*a)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	if (display)
		write(1, "ra\n", 3);
}

void	rra(t_stack **a, int display)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = ft_stacklast(*a);
	first = *a;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*a = last;
	if (display)
		write(1, "rra\n", 4);
}
