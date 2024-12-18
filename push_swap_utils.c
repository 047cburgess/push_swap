#include "push_swap.h"

int	*alloc_num(char *num)
{
	int	value;
	int	*result;

	value = ft_atoi(num);
	result = malloc(sizeof(int));
	if (!result)
		return (NULL);
	ft_memcpy(result, value, sizeof(int));
	return (result);
}

