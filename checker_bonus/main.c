/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:32:47 by caburges          #+#    #+#             */
/*   Updated: 2025/01/12 15:30:30 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include "checker.h"

void	ft_exit_checker(t_node **a, t_node **b)
{
	clear_stack(a);
	clear_stack(b);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	execute_instruction(char *instruction, t_node **a, t_node **b)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		sa(*a);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		sb(*b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ss(*a, *b);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rrr(a, b);
	else
		ft_exit_checker(a, b);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	*instruction;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	build_stack(&a, av, ac);
	instruction = get_next_line(0);
	while (instruction != NULL)
	{
		execute_instruction(instruction, &a, &b);
		free(instruction);
		instruction = get_next_line(0);
	}
	if (is_sorted(a) && (stack_size(b) == 0))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	clear_stack(&a);
	clear_stack(&b);
}
