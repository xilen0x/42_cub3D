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

/*Crea y guarda el mapa en una matriz*/
void	create_matrix(t_map *map, char *av)
{
	int	i;

	i = 0;
	open_map(av, map);
	map->matrix = spaced_malloc((map->h + 1) * sizeof(char *));
	while (i < map->h)
	{
		map->matrix[i] = get_next_line(map->map_fd);
		i++;
	}
	map->matrix[map->h] = NULL;
	close(map->map_fd);
}
