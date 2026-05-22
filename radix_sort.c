#include "push_swap.h"

void    fill_array(t_stack *a, int *tab)
{
	int	i;

	i = 0;
	while (a)
	{
		tab[i++] = a->value;
		a = a->next;
	}
}

void	assign_indexes(t_stack *a, int *tab, int len)
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
				break;
			}
			i++;
		}
		a = a->next;
	}
}

void	sort_array(int *tab, int len)
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

void    radix_sort(t_stack **a, t_stack **b)
{
    int len_tab;
    int *tab;
    int bit;
    int i;
    int len;

    len_tab = stack_len(*a);
    tab = malloc(len_tab * sizeof(int));
    if (!tab)
        return ;
    fill_array(*a, tab);
    sort_array(tab, len_tab);
    assign_indexes(*a, tab, len_tab);
    free(tab);
    len = len_tab;
    bit = 0;
    while (bit < 32)
    {
        i = 0;
        while (i++ < len)
        {
            if (((*a)->index >> bit & 1) == 0)
                pb(b, a, 1);
            else
                ra(a, 1);
        }
        while (*b)
            pa(a, b, 1);
        bit++;
    }
}
