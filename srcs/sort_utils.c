#include "push_swap.h"

void	map_current_index(t_node *a, t_node *b)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		a->index = i;
		i++;
		a = a->next;
	}
	i = 0;
	while (b != NULL)
	{
		b->index = i;
		i++;
		b = b->next;
	}
}
