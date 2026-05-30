/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:02:02 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/20 12:38:26 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf_error/ft_printf_error.h"

static int     error_syntax(char *str)
{
        // if (!str || *str == '\0')
        //         return (1);
        if ((*str == '-' || *str == '+') && !*(str + 1))
                return (1);
        if (*str == '-' || *str == '+')
                str++;
        while (*str)
        {
                if (!ft_isdigit(*str))
                        return (1);
                str++;
        }
        return (0);
}

int	error_repetition(t_stack *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	free_split(char **split)
{
	int		i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	stack_init(t_stack **a, char **split)
{
	long	nbr;

	while (*split)
	{
		
		if (error_syntax(*split))
        {
            ft_printf_error("Error: syntax\n");
        	free_stack(a);
            return ;
        }
		nbr = ft_atol(*split);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			ft_printf_error("Error: overflows int\n");
			free_stack(a);
			return ;
		}
		if (error_repetition(*a, (int)nbr))
		{
			ft_printf_error("Error: repetition\n");
			free_stack(a);
			return ;
		}
		if (!append_node(a, (int)nbr))
		{
			ft_printf_error("Error: allocation failure\n");
			free_stack(a);
			return ;
		}
		split++;
	}
}
