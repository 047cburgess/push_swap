/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:18:24 by caburges          #+#    #+#             */
/*   Updated: 2025/01/10 16:39:31 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_buffers(char *vault, char *buffer)
{
	char	*joined_buffers;
	size_t	vault_len;

	if (!vault)
		return (NULL);
	vault_len = my_strlen(vault);
	joined_buffers = malloc((vault_len + my_strlen(buffer) + 1) * sizeof(char));
	if (!joined_buffers)
	{
		free(vault);
		return (NULL);
	}
	my_strcpy(joined_buffers, vault);
	my_strcpy(&joined_buffers[vault_len], buffer);
	free(vault);
	return (joined_buffers);
}

size_t	my_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*my_strchr(char *s, int c)
{
	size_t	i;
	size_t	last_index;

	if (!s)
		return (NULL);
	last_index = my_strlen(s);
	i = 0;
	while (i <= last_index)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*my_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*my_calloc(size_t nmemb, size_t size)
{
	char	*memory;
	size_t	total_memory;
	size_t	i;

	total_memory = nmemb * size;
	memory = malloc(nmemb * size);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < total_memory)
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
}
