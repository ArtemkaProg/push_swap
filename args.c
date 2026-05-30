/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madebros <madebros@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:08:44 by madebros          #+#    #+#             */
/*   Updated: 2026/05/30 16:00:27 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf_error/ft_printf_error.h"

void	init_config(t_config *config)
{
	config->split = 0;
	config->selection = 4;
	config->adaptive = 0;
	config->bench = 0;
	config->index = -1;
	config->disorder = -1;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *) s1;
	cs2 = (unsigned char *) s2;
	i = 0;
	if (n < 1)
		return (0);
	while (cs1[i] && i < n - 1)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (cs1[i] - cs2[i]);
}

size_t	ft_strlen(const char *s)
{
	int	res;

	res = 0;
	while (s[res] != '\0')
		res++;
	return (res);
}

int	is_valide(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != ' ' && *str != '-')
			return (0);
		str++;
	}
	return (1);
}

int	ft_strdigit(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	if (i != 1)
		return (0);
	if ((c[0] >= '0' && c[0] <= '9'))
		return (1);
	return (0);
}

int	error(int code, char *reason)
{
	ft_printf_error("Error : %s\n", reason);
	return (code);
}

int	minus_two_check(int code, int target, char **argv, char *reason)
{
	if (!argv[target][0])
		return (error(-2, reason));
	else
		return (code);
}

int	args_controller(int ac, char **av, t_config *config)
{
	// if (ac <= 1)
	// 	return (error(-1));
	int (i) = 1;
	while (i < ac)
	{
		if ((av[i][0] == '-' && av[i][1] == '-'))
		{
			if (!ft_strncmp("--bench", av[i], 99))
				config->bench = 1;
			else if (!ft_strncmp("--simple", av[i], 99))
				config->selection = 1;
			else if (!ft_strncmp("--medium", av[i], 99))
				config->selection = 2;
			else if (!ft_strncmp("--complex", av[i], 99))
				config->selection = 3;
			else if (!ft_strncmp("--adaptive", av[i], 99))
				config->selection = 4;
			else
				return (error(-2, "ce flag existe pas"));
		}
		else
			break ;
		i++;
	}
	if ((!av[i]))
		return (-4);
	if ((av[i] && !is_valide(av[i])))
		return (error(-2, "arguments"));
	config->index = i;
	int (j) = 0;
	if (av[i])
	{
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
				config->split = 1;
			j++;
		}
	}
	else
		return (error(-2, "la boucle check"));
	return (/*minus_two_check(1, i - 1, av)*/ 1);
}

/*
#include <stdio.h>

int	main(int ac, char **av)
{
	t_config config;

	config.bench = 0;
	config.selection = 4;
	config.split = 0;
	ft_printf("(%d)\n", args_controller(ac, av, &config));
	ft_printf("{%d}\n", config.bench);
	ft_printf("[%d]\n", config.selection);
	ft_printf("+%d+\n", config.split);
	return (0);
}
*/
