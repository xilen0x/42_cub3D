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
void	space_malloc(size_t rows, size_t cols, t_map *map)
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
		map->matrix[i] = p_malloc(sizeof(char) * (cols + 3));
		ft_memset(map->matrix[i], ' ', cols + 3);
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

// void	create_matrix(t_map *map, t_lmap *lmap)
// {
// 	int		i;
// 	size_t	max_line;

// 	i = 0;
// 	while (lmap)
// 	{
// 		if (lmap->content[0] == '1')
// 			break ;
// 		lmap = lmap->next;
// 	}
// 	map->w = ft_strlen(lmap->content);
// 	map->h = lst_size(lmap) + 2;
// 	max_line = search_longest_line(lmap);
// 	space_malloc(map->h, max_line + 1, map);
// 	i++;
// 	while (lmap && (lmap->content[0] != '1' || lmap->content[0] == '\0'))
// 		lmap = lmap->next;
	
// 	while (lmap)
// 	{
// 		map->w = ft_strlen(lmap->content);
// 		ft_strncpy2(map->matrix[i], lmap->content, max_line);
// 		map->matrix[i][max_line + 1] = '\0';
// 		lmap = lmap->next;
// 		i++;
// 	}
// }

/* Funcion que crea la matriz a partir de la lista*/
void	create_matrix(t_map *map, t_lmap *lmap)
{
	int		i;
	size_t	max_line;

	// Saltar todas las líneas que contienen identificadores o están vacías
	while (lmap && (
	(ft_strnstr2(lmap->content, "NO", ft_strlen(lmap->content)) != NULL) ||
	 (ft_strnstr2(lmap->content, "SO", ft_strlen(lmap->content)) != NULL) ||
	  (ft_strnstr2(lmap->content, "WE", ft_strlen(lmap->content)) != NULL) ||
	   (ft_strnstr2(lmap->content, "EA", ft_strlen(lmap->content)) != NULL) ||
	    (ft_strnstr2(lmap->content, "F", ft_strlen(lmap->content)) != NULL) ||
	     (ft_strnstr2(lmap->content, "C", ft_strlen(lmap->content)) != NULL) ||
	      (lmap->content[0] == '\0')))
	{
		lmap = lmap->next;
	}
	// Calcular el alto del mapa (número de líneas)
	map->h = lst_size(lmap);
	// Encontrar la línea más larga para establecer el ancho máximo
	max_line = search_longest_line(lmap);
	// Reservar memoria para la matriz
	space_malloc(map->h, max_line + 1, map);
	i = 0;
	// Construir la matriz respetando la forma irregular del mapa
	while (lmap)
	{
		// Copiar la línea del mapa en la matriz
		ft_strncpy2(map->matrix[i], lmap->content, max_line);
		// Asegurarse de que la línea termina con un carácter nulo
		map->matrix[i][max_line] = '\0';
		// Avanzar al siguiente elemento de la lista
		lmap = lmap->next;
		i++;
	}
}






