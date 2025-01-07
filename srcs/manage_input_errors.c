/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:48:50 by caburges          #+#    #+#             */
/*   Updated: 2024/12/30 14:37:41 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	real_zero(char *str);

static int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	not_valid(long nb, char *str)
{
	char	*temp;

	temp = str;
	while (*temp != '\0')
	{
		if (!ft_isdigit(*temp) && (temp != str))
			return (1);
		temp++;
	}
	if (nb < INT_MIN || nb > INT_MAX)
		return (1);
	if (nb == 0 && !real_zero(str))

		return (1);
	return (0);
}

static int	real_zero(char *str)
{
	int	len;

	len = ft_strlen(str);
	if ((len == 1) && (str[0] == '0'))
		return (1);
	else if ((len == 2) && (is_sign(str[0])) && (str[1] == '0'))
		return (1);
	else 
		return (0);
}	


int	duplicate_found(t_node *stack, int nb)
{
	while (stack != NULL)
	{
		if (stack->nb == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_exit(t_node **stack)
{
	clear_stack(stack);
	ft_putendl_fd("Error", 2);
	exit(1);
}
