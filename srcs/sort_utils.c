#include "push_swap.h"

int	new_min_or_max(int nb, int min_nb, int max_nb)
{
	return (nb < min_nb || nb > max_nb);
}

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

void	assign_target_nodes(t_node *a, t_node *b, t_node **min, t_node **max)
{
	t_node	*b_trav;
	t_node	*current_target;

	while (a != NULL)
	{
		b_trav = b;
		if (new_min_or_max(a->nb, (*min)->nb, (*max)->nb))
			a->target = *max;
		else
		{
			current_target = *min;
			while (b_trav != NULL)
			{

				if (b_trav->nb < a->nb && b_trav->nb > current_target->nb)
					current_target = b_trav;
				b_trav = b_trav->next;
			}
			a->target = current_target;
		}
		a = a->next;
	}		
}

void	calculate_push_cost(t_node *node, int a_size, int b_size)
{
	if ((node->index < a_size / 2) && (node->target->index < b_size / 2))
	{
		if (node->index > node->target->index)
			node->push_cost = node->index;
		else
			node->push_cost = node->target->index;
	}
	else if ((node->index > a_size / 2) && (node->target->index > b_size / 2))
	{
		if (a_size - node->index > b_size - node->target->index)
			node->push_cost = (a_size - node->index);
		else
			node->push_cost = (b_size - node->target->index);
	}
	else if ((node->index < a_size / 2) && (node->target->index > b_size / 2))
		node->push_cost = (node->index) + (b_size - node->target->index);
	else
		node->push_cost = (a_size - node->index) + (node->target->index);
}

void	execute_push(t_node *node, t_node **a, t_node **b, int a_size, int b_size)
{
	int	i;

	i = 0;
	if ((node->index < a_size / 2) && (node->target->index < b_size / 2))
	{
		while (i < node->index && i < node->target->index)
		{
			rotate_ab(a, b);
			i++;
		}
		while (*a != node)
			rotate_a(a);
		while (*b != node->target)
			rotate_b(b);
	}
	else if ((node->index > a_size / 2) && (node->target->index > b_size / 2))
	{
		while ((i < a_size - node->index) && (i < b_size - node->target->index))
		{
			rev_rotate_ab(a, b);
			i++;
		}
		while (*a != node)
			rev_rotate_a(b);
		while (*b != node->target)
			rev_rotate_b(b);
	}
	else if ((node->index < a_size / 2) && (node->target->index > b_size / 2))
	{
		while (*a != node)
			rotate_a(a);
		while (*b != node->target)
			rev_rotate_b(b);
	}
	else
	{
		while (*a != node)
			rev_rotate_a(a);
		while (*b != node->target)
			rotate_b(b);
	}
}


