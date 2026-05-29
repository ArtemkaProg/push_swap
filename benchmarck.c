/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   benchmarck.c                                       :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: madebros <madebros@learner.42.tech>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/24 11:17:30 by madebros         #+#    #+#              */
/*   Updated: 2026/05/27 17:12:15 by madebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_counter(t_counter *counter, t_config *config)
{
	counter->bench = config->bench;
	counter->sa = 0;
	counter->sb = 0;
	counter->ss = 0;
	counter->pa = 0;
	counter->pb = 0;
	counter->ra = 0;
	counter->rb = 0;
	counter->rr = 0;
	counter->rra = 0;
	counter->rrb = 0;
	counter->rrr = 0;
}

int	total_counter(t_counter *counter)
{
	int	res;

	res = 0;
	res += counter->sa;
	res += counter->sb;
	res += counter->ss;
	res += counter->pa;
	res += counter->pb;
	res += counter->ra;
	res += counter->rb;
	res += counter->rr;
	res += counter->rra;
	res += counter->rrb;
	res += counter->rrr;
	return (res);
}

void	print_float(t_config *config, t_stack *a)
{
	int	huge;
	int	modulo;
	int	len;

	len = stack_len(a);
	if (len < 2)
	{
		ft_printf("0.00%\n");
		return ;
	}
	huge = (config->disorder * 100 * 100) / (len * (len - 1) / 2);
	modulo = huge % 100;
	if (modulo < 10)
		ft_printf("%d.0%d%\n", huge / 100, modulo);
	else
		ft_printf("%d.%d%\n", huge / 100, modulo);
}

void	print_methode(t_config *config)
{
	if (config->adaptive == 1 || !config->adaptive)
		ft_printf("O(n2)\n");
	if (config->adaptive == 2)
		ft_printf("O(n√n)\n");
	if (config->adaptive == 3)
		ft_printf("O(n log n)\n");
}

void	write_benchmarck(t_config *config, t_counter *c, t_stack *a)
{
	ft_printf("[bench] disorder: ");
	print_float(config, a);
	ft_printf("[bench] strategy: ");
	if (config->selection == 1)
		ft_printf("Simple / O(n2)\n");
	if (config->selection == 2)
		ft_printf("Medium / O(n√n)\n");
	if (config->selection == 3)
		ft_printf("Complex / O(n log n)\n");
	if (config->selection == 4)
	{
		ft_printf("Adaptive / ");
		print_methode(config);
	}
	ft_printf("[bench] total_ops: %d\n", total_counter(c));
	ft_printf("[bench] sa: %d sb: %d ss: %d", c->sa, c->sb, c->ss);
	ft_printf(" pa: %d, pb: %d\n[bench] ", c->pa, c->pb);
	ft_printf("ra: %d rb: %d rr: %d rra: %d", c->ra, c->rb, c->rr, c->rra);
	ft_printf(" rrb: %d rrr: %d", c->rrb, c->rrr);
}

/*
int	main()
{
	t_config config;
	t_counter counter;

	config.bench = 1;
	config.selection = 2;
	init_counter(&counter);
	write_benchmarck(23, &config, &counter);
	return (0);
}
*/
