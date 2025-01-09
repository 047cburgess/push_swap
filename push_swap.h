/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:43:16 by caburges          #+#    #+#             */
/*   Updated: 2025/01/09 19:24:10 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

// Stacks shit
typedef struct s_node
{
	int	nb;
	int	index;
	struct s_node	*target;
	int	push_cost;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

t_node	*new_node(int nb);
void	add_front(t_node **head, t_node *new);
void	clear_stack(t_node **stack);
t_node *last_node(t_node *stack);
void	build_stack(t_node **stack, char **av, int ac);

// Error management
int	initial_errors_found(int ac, char **av);
int	not_valid(long nb, char *str);
int	duplicate_found(t_node *stack, int nb);
void	ft_exit(t_node **stack);

// Sort Operations
void	swap_a(t_node *node);
void	swap_b(t_node *node);
void	swap_ab(t_node *a, t_node *b);
void	push_a(t_node **a, t_node **b);
void	push_b(t_node **a, t_node **b);
void	rotate_a(t_node **stack);
void	rotate_b(t_node **stack);
void	rotate_ab(t_node **a, t_node **b);
void	rev_rotate_a(t_node **stack);
void	rev_rotate_b(t_node **stack);
void	rev_rotate_ab(t_node **a, t_node **b);

// Algos
void	sort_three(t_node **head);
void	big_sort(t_node **a, t_node **b, int a_size);

// Helpers
int	is_sorted(t_node *stack);
int	stack_size(t_node *stack);
void	set_min_max(t_node **min, t_node **max, t_node *head);
void	print_stacks(t_node *a, t_node *b);
void	map_current_index(t_node *a, t_node *b);
void	assign_target_nodes(t_node *a, t_node *b);
void	assign_target_nodes_end(t_node *a, t_node *b);
void	calculate_push_cost(t_node *node, int a_size, int b_size);
void	bring_right_nodes_to_top(t_node *node, t_node **a, t_node **b);
void	bring_right_nodes_to_top_end(t_node *node, t_node **a, t_node **b);
void	bring_min_to_top(t_node **head, int size);
int	above_med(int index, int stack_size);
#endif
