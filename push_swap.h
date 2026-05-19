/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:01:50 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/19 19:01:51 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// stack_initialisation

long				ft_atol(const char *nptr);
int					error_repetition(t_stack *a, int nbr);
void				stack_init(t_stack **a, char **argv);

// stack_utils

t_stack				*ft_stacklast(t_stack *a);
void				append_node(t_stack **stack, int nbr);
int					get_stack_len(t_stack *stack);

// swap_comands

void				sa(t_stack *a, int display);
void				pa(t_stack **a, t_stack **b, int display);
void				ra(t_stack *a, int display);
void				rra(t_stack *a, int display);

void				sb(t_stack *b, int display);
void				pb(t_stack **b, t_stack **a, int display);
void				rb(t_stack *b, int display);
void				rrb(t_stack *b, int display);

void				ss(t_stack *a, t_stack *b, int display);
void				rr(t_stack *a, t_stack *b, int display);
void				rrr(t_stack *a, t_stack *b, int display);

// split

char				**ft_split(char const *s, char c);

#endif
