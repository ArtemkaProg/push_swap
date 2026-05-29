/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium_rotate.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: madebros <madebros@learner.42.tech>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/28 14:09:50 by madebros         #+#    #+#              */
/*   Updated: 2026/05/28 14:09:50 by madebros        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name, t_counter *c)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, 1, c);
			else
				rra(stack, 1, c);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, 1, c);
			else
				rrb(stack, 1, c);
		}
	}
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node, t_counter *c)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rr(a, b, 1, c);
	set_current_position(*a);
	set_current_position(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node, t_counter *c)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rrr(a, b, 1, c);
	set_current_position(*a);
	set_current_position(*b);
}
