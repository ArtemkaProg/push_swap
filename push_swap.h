/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalchuk <avalchuk@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:01:50 by avalchuk          #+#    #+#             */
/*   Updated: 2026/05/30 15:59:20 by avalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_config
{
	int	bench;
	int	selection;
	int	adaptive;
	int	split;
	int	index;
	int	disorder;
}		t_config;

typedef struct s_counter
{
	int	bench;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_counter;

typedef struct s_stack
{
	int		value;
	int		current_position;
	int		push_price;
	int		above_median;
	int		cheapest;
	int		index;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*target_node;
}			t_stack;

// partie de mattiu tkt bg

int     args_controller(int ac, char **av, t_config *config);
void    init_config(t_config *config);
void    init_counter(t_counter *counter, t_config *config);
void    write_benchmarck(t_config *config, t_counter *c, t_stack *a);

// utils.c

int	ft_isdigit(char c);
char	**ft_split(char const *s, char c);
long	ft_atol(const char *nptr);

// stack_init.c

int		error_repetition(t_stack *a, int nbr);
void	free_split(char **argv);
void	free_stack(t_stack **stack);
void	stack_init(t_stack **a, char **split);

// stack_utils.c

t_stack	*ft_stacklast(t_stack *a);
void	append_node(t_stack **stack, int nbr);
int		stack_len(t_stack *stack);
t_stack	*find_smallest(t_stack *a);
t_stack	*find_highest(t_stack *a);

// swap_commands*.c

void	sa(t_stack **a, int display, t_counter *c);
void	pa(t_stack **a, t_stack **b, int display, t_counter *c);
void	ra(t_stack **a, int display, t_counter *c);
void	rra(t_stack **a, int display, t_counter *c);

void    sb(t_stack **b, int display, t_counter *counter);
void	pb(t_stack **b, t_stack **a, int display, t_counter *c);
void	rb(t_stack **b, int display, t_counter *c);
void	rrb(t_stack **b, int display, t_counter *c);

void	ss(t_stack **a, t_stack **b, int display, t_counter *c);
void	rr(t_stack **a, t_stack **b, int display, t_counter *c);
void	rrr(t_stack **a, t_stack **b, int display, t_counter *c);

// sort.c

void	push_swap(t_stack **a, t_stack **b, t_config *config, t_counter *c);
int		check_sort(t_stack *a);
int		compute_disorder(t_stack *a);
void	tiny_sort(t_stack **a, t_counter *c);

// handle_five.c

void	handle_five(t_stack **a, t_stack **b, t_counter *c);

// simple_sort.c

void	simple_sort(t_stack **a, t_stack **b, t_counter *c);

////// MEDIUM SORTING //////

// medium_init.c

void	init_nodes(t_stack *a, t_stack *b);
void	set_current_position(t_stack *stack);

// medium rotating.c

void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name, t_counter *c);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node, t_counter *c);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node, t_counter *c);

// medium_sort.c

void	medium_sort(t_stack **a, t_stack **b, int len_a, t_counter *c);
void	move_nodes(t_stack **a, t_stack **b, t_counter *c);

////// RADIX SORTING //////

void	radix_sort(t_stack **a, t_stack **b, t_counter *c);

#endif
