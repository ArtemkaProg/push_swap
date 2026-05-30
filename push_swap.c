/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madebros <madebros@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:43:50 by madebros          #+#    #+#             */
/*   Updated: 2026/05/27 17:03:43 by madebros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_auto(t_stack **a, t_stack **b, t_config *config, t_counter *c)
{
	int	ratio;
	int	len_a;

	len_a = stack_len(*a);
	ratio = ((config->disorder * 100 * 100) / (len_a * (len_a - 1) / 2) / 100);
	if (ratio < 20)
	{
		config->adaptive = 1;
		simple_sort(a, b, c);
	}
	else if (ratio >= 20 && ratio < 50)
	{
		config->adaptive = 2;
		medium_sort(a, b, len_a, c);
	}
	else
	{
		config->adaptive = 3;
		radix_sort(a, b, c);
	}
}

void	push_swap(t_stack **a, t_stack **b, t_config *config, t_counter *c)
{
	int	is_sorted;
	int	len_a;

	is_sorted = check_sort(*a);
	len_a = stack_len(*a);
	if (is_sorted)
		return ;
	if (config->selection == 1)
		simple_sort(a, b, c);
	if (config->selection == 2)
		medium_sort(a, b, len_a, c);
	if (config->selection == 3)
		radix_sort(a, b, c);
	if (config->selection == 4)
		adaptive_auto(a, b, config, c);
}

static void	zero_no_quote(t_config *config, t_counter *c, t_stack *a)
{
	config->disorder = 0;
	if (config->bench)
		write_benchmarck(config, c, a);
	exit(0);
}

int	main(int args, char **argv)
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	char	**split;
	t_config config;
	t_counter counter;

	init_config(&config);
	int (arg_res) = args_controller(args, argv, &config);
	if (arg_res == -2)
		return (0);
	init_counter(&counter, &config);
	if (arg_res == -4)
		zero_no_quote(&config, &counter, a);
	if (config.split)
	{
		split = ft_split(argv[config.index], ' ');
		if (!split)
			return (0);
		stack_init(&a, split);
		free_split(split);
	}
	else
		stack_init(&a, argv + config.index);
	if (a == NULL)
		return (0);
	config.disorder = compute_disorder(a);
	push_swap(&a, &b, &config, &counter);
	if (config.bench)
		write_benchmarck(&config, &counter, a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
