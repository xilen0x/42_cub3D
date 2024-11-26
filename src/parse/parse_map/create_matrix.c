/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:04:02 by castorga          #+#    #+#             */
/*   Updated: 2024/07/10 19:04:05 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Funcion que reserva memoria y rellena con ' ' */
void	space_malloc(size_t rows, size_t cols, t_map_parse *map)
{
	size_t	i;

	map->matrix = p_malloc(sizeof(char *) * rows);
	i = 0;
	map->matrix[i] = p_malloc(sizeof(char) * (cols + 2));
	ft_memset(map->matrix[i], ' ', cols + 2);
	map->matrix[i][cols + 1] = '\0';
	i++;
	while (i < rows)
	{
		map->matrix[i] = p_malloc(sizeof(char) * (cols + 2));
		ft_memset(map->matrix[i], ' ', cols + 2);
		map->matrix[i][cols] = '\0';
		i++;
	}
}

char	*ft_strnstr2(const char *haystack, const char *needle, size_t len)
{
	size_t	k;
	size_t	i;
	size_t	j;

	k = 0;
	i = 0;
	j = 0;
	while (needle[k] != '\0')
		k++;
	while ((haystack[i] != '\0') && (i + k <= len))
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0')
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	create_matrix_irregular(t_map_parse *map, t_lmap *lm)
{
	int		i;
	size_t	max_line;

	while (lm && (
			(ft_strnstr2(lm->cont, "NO", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "SO", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "WE", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "EA", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "F", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "C", ft_strlen(lm->cont)) != NULL) || \
			(lm->cont[0] == '\0')))
		lm = lm->next;
	map->h = lst_size(lm);
	max_line = search_longest_line(lm);
	map->w = max_line;
	space_malloc(map->h, max_line + 1, map);
	i = 0;
	while (lm)
	{
		remove_newline_char(lm->cont);
		ft_strncpy2(map->matrix[i], lm->cont, max_line);
		map->matrix[i][max_line] = '\0';
		lm = lm->next;
		i++;
	}
}

/* Funcion que crea la matriz a partir de la lista*/
void	create_matrix(t_map_parse *map, t_lmap *lm)
{
	int		i;
	size_t	max_line;

	while (lm && (
			(ft_strnstr2(lm->cont, "NO", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "SO", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "WE", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "EA", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "F", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "C", ft_strlen(lm->cont)) != NULL) || \
			(lm->cont[0] == '\0')))
		lm = lm->next;
	map->h = lst_size(lm);
	max_line = search_longest_line(lm);
	map->w = max_line;
	space_malloc(map->h, max_line + 1, map);
	i = 0;
	while (lm)
	{
		ft_strncpy2(map->matrix[i], lm->cont, max_line);
		map->matrix[i][max_line] = '\0';
		lm = lm->next;
		i++;
	}
}
