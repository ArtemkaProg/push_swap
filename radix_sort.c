#include "push_swap.h"

static void	fill_array(t_stack *a, int *tab)
{
	int	i;

	i = 0;
	while (a)
	{
		tab[i++] = a->value;
		a = a->next;
	}
}

static void	assign_indexes(t_stack *a, int *tab, int len)
{
	int	i;

	i = 0;
	while (a)
	{
		i = 0;
		while (i < len)
		{
			if (a->value == tab[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

static void	sort_array(int *tab, int len)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	get_max_bits(int len_tab)
{
	int	max_bits;

	max_bits = 0;
	len_tab--;
	while (len_tab > 0)
	{
		max_bits++;
		len_tab >>= 1;
	}
	return (max_bits);
}

void	radix_sort(t_stack **a, t_stack **b, t_counter *c)
{
	int	len_tab;
	int	*tab;
	int	bit;
	int	i;
	int	len;
	int	max_bits;

	len_tab = stack_len(*a);
	tab = malloc(len_tab * sizeof(int));
	if (!tab)
		return ;
	fill_array(*a, tab);
	sort_array(tab, len_tab);
	assign_indexes(*a, tab, len_tab);
	free(tab);
	len = len_tab;
	max_bits = get_max_bits(len_tab);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i++ < len)
		{
			if (((*a)->index >> bit & 1) == 0)
				pb(b, a, 1, c);
			else
				ra(a, 1, c);
		}
		while (*b)
			pa(a, b, 1, c);
		bit++;
	}
}
