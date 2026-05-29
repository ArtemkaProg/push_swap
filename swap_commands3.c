/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:02:20 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/27 12:17:02 by madebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b, int display, t_counter *c)
{
	sa(a, 0, NULL);
	sb(b, 0, NULL);
	if (display && c && !c->bench)
		write(1, "ss\n", 3);
	else if (c)
		c->ss++;
}

void	rr(t_stack **a, t_stack **b, int display, t_counter *c)
{
	ra(a, 0, NULL);
	rb(b, 0, NULL);
	if (display && c && !c->bench)
		write(1, "rr\n", 3);
	else if (c)
		c->rr++;
}

void	rrr(t_stack **a, t_stack **b, int display, t_counter *c)
{
	rra(a, 0, NULL);
	rrb(b, 0, NULL);
	if (display && c && !c->bench)
		write(1, "rrr\n", 4);
	else if (c)
		c->rrr++;
}
