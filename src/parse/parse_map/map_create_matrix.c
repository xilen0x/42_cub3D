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

    map->matrix = p_malloc(sizeof(char *) * rows);
    i = 0;
	map->matrix[i] = p_malloc(sizeof(char) * (cols + 2));
	ft_memset(map->matrix[i], '8', cols + 1);
	map->matrix[i][cols + 1] = '\0';
	i++;
    while (i < rows)
    {
        map->matrix[i] = p_malloc(sizeof(char) * (cols + 2));
        ft_memset(map->matrix[i], '+', cols + 1);
        map->matrix[i][cols] = '\0';
        i++;
    }
}

/* Funcion que crea la matriz a partir de la lista*/
void create_matrix(t_map *map, t_lmap *lmap)
{
    int     i;
    t_lmap  *tmp;
    size_t  max_line;

    i = 0;
    tmp = lmap;
    map->h = lst_size(tmp) + 2;
    max_line = search_longest_line(tmp);
    space_malloc(map->h, max_line, map);
	map->w = ft_strlen(lmap->content);
    // ft_strncpy(map->matrix[i], "*", map->w);
    // map->matrix[i][max_line] = '\0';
	i++;
    while (lmap)
    {
        map->w = ft_strlen(lmap->content);
        ft_strncpy2(map->matrix[i], lmap->content, max_line);
        map->matrix[i][max_line + 1] = '\0';
        lmap = lmap->next;
        i++;
    }
}
