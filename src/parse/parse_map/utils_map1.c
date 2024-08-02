/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:05:56 by castorga          #+#    #+#             */
/*   Updated: 2024/07/29 14:05:59 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

/* Allocates 'size' bytes of memory and returns a pointer to it.
Exits properly if memory allocation fails.*/
void	*p_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		write(2, "Error: memory allocation failure\n", 33);
		exit (EXIT_FAILURE);
	}
	return (ptr);
}
// char	*ft_strncpy2(char *dest, const char *src, unsigned int n)
// {
// 	unsigned int	i;
// 	unsigned int	j;

// 	i = 1;
// 	j = 0;
// 	while (src[i] != '\0' && i < n)
// 	{
// 		dest[j] = src[i];
// 		i++;
// 		j++;
// 	}
// 	while (i < n)
// 	{
// 		dest[j] = '.';
// 		j++;
// 	}
// 	return (dest);
// }
char	*ft_strncpy2(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	dest[0] = '.';
	i = 0;
	j = 1;
	while (src[i] != '\0' && j < n)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}
	return dest;
}
