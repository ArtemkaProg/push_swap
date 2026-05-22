/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:01:50 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/22 15:42:53 by avalchuk         ###   ########.fr       */
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
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*target_node;
}					t_stack;

// utils.c

char				**ft_split(char const *s, char c);
long				ft_atol(const char *nptr);

// stack_init.c

int					error_repetition(t_stack *a, int nbr);
void				free_split(char **argv);
void				free_stack(t_stack **stack);
void				stack_init(t_stack **a, char **split);

// stack_utils.c

t_stack				*ft_stacklast(t_stack *a);
void				append_node(t_stack **stack, int nbr);
int					stack_len(t_stack *stack);
t_stack				*find_smallest(t_stack *a);
t_stack				*find_highest(t_stack *a);

// swap_commands*.c

void				sa(t_stack **a, int display);
void				pa(t_stack **a, t_stack **b, int display);
void				ra(t_stack **a, int display);
void				rra(t_stack **a, int display);

void				sb(t_stack **b, int display);
void				pb(t_stack **b, t_stack **a, int display);
void				rb(t_stack **b, int display);
void				rrb(t_stack **b, int display);

void				ss(t_stack **a, t_stack **b, int display);
void				rr(t_stack **a, t_stack **b, int display);
void				rrr(t_stack **a, t_stack **b, int display);

// sort.c

void		push_swap(t_stack **a, t_stack **b);
int		check_sort(t_stack *a);
int		compute_disorder(t_stack *a);
void	tiny_sort(t_stack **a);


////// MEDIUM SORTING //////


// medium_init.c

void	init_nodes(t_stack *a, t_stack *b);
void	set_current_position(t_stack *stack);
void	set_target_node(t_stack *a, t_stack *b);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);

// medium rotating.c

void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

// medium_sort.c

void	medium_sort(t_stack **a, t_stack **b, int len_a);
void	move_nodes(t_stack **a, t_stack **b);
t_stack	*return_cheapest(t_stack *b);


////// RADIX SORTING //////

void    radix_sort(t_stack **a, t_stack **b);
void    fill_array(t_stack *a, int *tab);
void	asign_indexes(t_stack *a, int *tab, int len);
void	sort_array(int *tab, int len);

#endif
