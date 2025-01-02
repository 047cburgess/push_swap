/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:43:16 by caburges          #+#    #+#             */
/*   Updated: 2025/01/02 15:53:15 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

// Stacks shit
typedef struct t_stack
{
	int	nb;
	struct t_stack	*prev;
	struct t_stack	*next;
}	t_stack;

t_stack	*new_node(int nb);
void	add_front(t_stack **head, t_stack *new);
void	clear_stack(t_stack **stack);
t_stack *last_node(t_stack *stack);

// Error management
int	initial_errors_found(int ac, char **av);

// Sort Operations
void	swap_a(t_stack *node);
void	swap_b(t_stack *node);
void	swap_ab(t_stack *a, t_stack *b);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate_ab(t_stack **a, t_stack **b);
void	rev_rotate_a(t_stack **stack);
void	rev_rotate_b(t_stack **stack);
void	rev_rotate_ab(t_stack **a, t_stack **b);

// Algos
void	sort_three(t_stack **head);
void	big_sort(t_stack **a, t_stack **b);

// Helpers
int	is_sorted(t_stack *stack);
int	stack_size(t_stack *stack);
void	set_min_max(t_stack **min, t_stack **max, t_stack *head);
void	print_stacks(t_stack *a, t_stack *b);
#endif
