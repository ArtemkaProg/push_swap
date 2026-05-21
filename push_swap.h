/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:01:50 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/20 15:45:10 by avalchuk         ###   ########.fr       */
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
	int				current_position;
	int				push_price;
	int				above_median;
	int				cheapest;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*target_node;
}					t_stack;

// stack_initialisation

long				ft_atol(const char *nptr);
int					error_repetition(t_stack *a, int nbr);
void				free_split(char **argv);
void				free_stack(t_stack **stack);
void				stack_init(t_stack **a, char **split);

// stack_utils

t_stack				*ft_stacklast(t_stack *a);
void				append_node(t_stack **stack, int nbr);
int					stack_len(t_stack *stack);

// swap_comands

void				sa(t_stack *a, int display);
void				pa(t_stack **a, t_stack **b, int display);
void				ra(t_stack **a, int display);
void				rra(t_stack **a, int display);

void				sb(t_stack *b, int display);
void				pb(t_stack **b, t_stack **a, int display);
void				rb(t_stack **b, int display);
void				rrb(t_stack **b, int display);

void				ss(t_stack *a, t_stack *b, int display);
void				rr(t_stack **a, t_stack **b, int display);
void				rrr(t_stack **a, t_stack **b, int display);

// split

char				**ft_split(char const *s, char c);

// sorting

void		push_swap(t_stack **a, t_stack **b);
int		check_sort(t_stack *a);
int		compute_disorder(t_stack *a);
void	tiny_sort(t_stack **a);

//// medium_sort

void	medium_sort(t_stack **a, t_stack **b, int len_a);
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
void	move_nodes(t_stack **a, t_stack **b);
t_stack	*find_smallest(t_stack *a);
t_stack	*find_highest(t_stack *a);
t_stack	*return_cheapest(t_stack *b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

// push_swap init

void	init_nodes(t_stack *a, t_stack *b);
void	set_current_position(t_stack *stack);
void	set_target_node(t_stack *a, t_stack *b);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);

#endif
