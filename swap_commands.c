/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:02:13 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/19 19:02:15 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int display)
{
	int	temp;

	if (!a || !a->next)
		return ;
	temp = a->value;
	a->value = a->next->value;
	a->next->value = temp;
	if (display)
		write(1, "sa\n", 3);
}

void	pa(t_stack **a, t_stack **b, int display)
{
	t_stack	*temp;

	if (!b || !*b)
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
		write(1, "pa\n", 3);
}

void	ra(t_stack *a, int display)
{
	int	temp;

	if (!a)
		return ;
	temp = a->value;
	while (a->next)
	{
		a->value = a->next->value;
		a = a->next;
	}
	a->value = temp;
	if (display)
		write(1, "ra\n", 3);
}

void	rra(t_stack *a, int display)
{
	int	temp;

	if (!a)
		return ;
	a = ft_stacklast(a);
	if (!a)
		return ;
	temp = a->value;
	while (a->prev)
	{
		a->value = a->prev->value;
		a = a->prev;
	}
	a->value = temp;
	if (display)
		write(1, "rra\n", 4);
}
