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

char	*ft_strncpy2(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	dest[0] = ' ';
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
		dest[j] = ' ';
		j++;
	}
	return dest;
}
// int	horizontal_check(t_lmap *lmap)
// {
// 	unsigned int	last;

// 	while (lmap)
// 	{
// 		while (*lmap->content == ' ')
// 			lmap->content++;
// 		// last = ft_strlen(lmap->content) - 2;
// 		last = ft_strlen(lmap->content) - 1;
// 		if (*lmap->content != '1' || lmap->content[last] != '1')
// 			return (1);
// 		lmap = lmap->next;
// 	}
// 	return (0);
// }

// int	parsing_not_square_map(t_lmap *lmap)
// {
// 	(void)lmap;
// 	return (0);
// }

// int	is_square_map(t_lmap *lmap)
// {
// 	unsigned int	next;
// 	unsigned int	current;

// 	while (lmap)
// 	{
// 		current = ft_strlen(lmap->content);
// 		if (lmap->next)
// 			next = ft_strlen(lmap->next->content);
// 		if (current != next)
// 			return (0);
// 		lmap = lmap->next;
// 	}
// 	return (1);
// }