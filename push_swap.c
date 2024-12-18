#include "push_swap.h"

int	initial_errors_found(int ac);

void	print_stack(t_list *stack)
{
	while (stack != NULL)
	{
		printf("%i\n", stack->content);
		stack = stack->next;
	}
}

void	build_stack(t_list **head, char **nums, int num_args)
{
	t_list	*new_list;
	t_list	*trav;
	int	*new_content;
	int	i;

	new_list = NULL;
	i = 0;
	while (i < num_args)
	{
		new_content = malloc(sizeof(int));
		*new_content = ft_atoi(nums[i]);
		if (new_list == NULL)
		{

			new_list = ft_lstnew(new_content);
			trav = new_list->next;
		}
		else
		{
			trav = ft_lstnew(new_content);
			trav = trav->next;
		}
		i++;
	}
	*head = new_list;
}		

int	main(int ac, char **av)
{
	char **nums;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (initial_errors_found(ac))
	{
		printf("Error\n");
		return (1);
	}
	nums = &av[1];	
	build_stack(&stack_a, nums, ac - 1);

	print_stack(stack_a);	

}

int	initial_errors_found(int ac)
{
	if (ac == 1)
		return (1);
	return (0);
}
