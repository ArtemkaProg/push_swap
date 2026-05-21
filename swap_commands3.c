/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:02:20 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/19 19:02:21 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b, int display)
{
	sa(a, 0);
	sb(b, 0);
	if (display)
		write(1, "ss\n", 3);
}

void	rr(t_stack **a, t_stack **b, int display)
{
	ra(a, 0);
	rb(b, 0);
	if (display)
		write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b, int display)
{
	rra(a, 0);
	rrb(b, 0);
	if (display)
		write(1, "rrr\n", 4);
}
