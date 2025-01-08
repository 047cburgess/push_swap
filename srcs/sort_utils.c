#include "push_swap.h"

//OK
int	new_min_or_max(int nb, int min_nb, int max_nb)
{
	return (nb < min_nb || nb > max_nb);
}

//OK
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

//OK ?
void	assign_target_nodes(t_node *a, t_node *b)
{
	t_node	*b_trav;
	t_node	*current_target;
	t_node	*min;
	t_node	*max;

	set_min_max(&min, &max, b);
	while (a != NULL)
	{
		current_target = min;
		b_trav = b;
		while (b_trav != NULL)
		{
			if (b_trav->nb < a->nb && b_trav->nb > current_target->nb)
				current_target = b_trav;
			b_trav = b_trav->next;
		}
		if (current_target == min && current_target->nb > a->nb)
			a->target = max;
		else
			a->target = current_target;
		a = a->next;
	}	
}

void	assign_target_nodes_end(t_node *a, t_node *b)
{
	t_node	*a_trav;
	t_node	*current_target;
	t_node	*min;
	t_node	*max;

	set_min_max(&min, &max, a);	
	while (b != NULL)
	{
		current_target = max;
		a_trav = a;
		while (a_trav != NULL)
		{
			if (a_trav->nb > b->nb && a_trav->nb < current_target->nb)
				current_target = a_trav;
			a_trav = a_trav->next;
		}
		if (current_target == max && current_target->nb < b->nb)
			b->target = min;
		else
			b->target = current_target;
		b = b->next;
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

void	bring_right_nodes_to_top(t_node *node, t_node **a, t_node **b, int a_size, int b_size)
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
			rev_rotate_a(a);
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

void	bring_min_to_top(t_node **head, int size)
{
	t_node	*min;
	t_node	*trav;

	min = *head;
	trav = *head;
	while (trav != NULL)
	{
		if (trav->nb < min->nb)
			min = trav;
		trav = trav->next;
	}
	if (min->index < size / 2)
	{
		while (*head != min)
			rotate_a(head);
	}
	else
	{
		while (*head != min)
			rev_rotate_a(head);
	}
}

