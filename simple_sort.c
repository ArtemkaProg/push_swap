/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple_sort.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: madebros <madebros@learner.42.tech>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/28 11:42:28 by madebros         #+#    #+#              */
/*   Updated: 2026/05/28 11:42:28 by madebros        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack **a, t_stack **b, t_counter *c)
{
	while (stack_len(*a) > 3)
	{
		finish_rotation(a, find_smallest(*a), 'a', c);
		pb(b, a, 1, c);
	}
	tiny_sort(a, c);
	while (*b)
		pa(a, b, 1, c);
	while (!check_sort(*a))
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, 1, c);
		ra(a, 1, c);
	}
}
