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

# include "cub3d.h"

/* Funcion que reserva memoria y rellena con ' ' */
void space_malloc(size_t rows, size_t cols, t_map *map)
{
	size_t i;

	i = 0;
	// matrix_temp = p_malloc(sizeof(char *) * (rows + 1));
	map->matrix = p_malloc(sizeof(char *) * rows);
	// map->matrix = matrix_temp;
	while (i < rows)
	{
		map->matrix[i] = p_malloc(sizeof(char) * (cols + 2));
		ft_memset(map->matrix[i], '*', cols);
		map->matrix[i][cols] = '\0';
		i++;
	}
	// 
// }
    // map->matrix = p_malloc(sizeof(char *) * size);
    // ft_memset(map->matrix, '*', size);
}

/* Funcion que crea la matriz a partir de la lista*/
void	create_matrix(t_map *map, t_lmap *lmap)
{
	int				i;
	t_lmap			*tmp;
	size_t			max_line;

	i = 0;
	tmp = lmap;
	map->h = lst_size(tmp);
	max_line = search_longest_line(tmp);
	space_malloc(map->h + 1, max_line, map);
	while (lmap)
	{
		map->w = ft_strlen(lmap->content);
		ft_printf("map->w: %d\n", map->w);
		ft_strncpy_2(map->matrix[i], lmap->content, map->w);
		map->matrix[i][max_line] = '\0';
		lmap = lmap->next;
		i++;
	}
	map->matrix[i] = NULL;
}
