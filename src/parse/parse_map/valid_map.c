/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:35:07 by castorga          #+#    #+#             */
/*   Updated: 2024/07/16 15:35:09 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//*Descripción: Funcion que compueba si el mapa es jugable
int	its_playable(t_map_parse	*map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] == '1')
				count++;
			x++;
		}
		if ((y + 1) < map->h)
			y++;
		else
			break ;
	}
	if (count < 4)
		return (1);
	return (0);
}

/*Verifica si solo existen caracteres permitidos*/
int	only_characters_allowed(t_map_parse	*map)
{
	int	x;
	int	y;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] != '0' && \
				map->matrix[y][x] != '1' &&
				map->matrix[y][x] != 'N' &&
				map->matrix[y][x] != 'S' &&
				map->matrix[y][x] != 'E' &&
				map->matrix[y][x] != 'W' &&
				map->matrix[y][x] != '\t')
				return (1);
			x++;
		}
		if ((y + 1) < map->h)
			y++;
		else
			break ;
	}
	return (0);
}

void	save_player_position(t_map_parse *map, int *count, int *x, int *y)
{
	if (map->matrix[*y][*x] == 'N' || map->matrix[*y][*x] == 'S' || \
			map->matrix[*y][*x] == 'E' || map->matrix[*y][*x] == 'W')
	{
		(*count)++;
		map->y = *y;
		map->x = *x;
	}
}

int	is_one_player(t_map_parse *map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (map->matrix[map->y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			save_player_position(map, &count, &x, &y);
			x++;
		}
		if ((y + 1) < map->h)
			y++;
		else
			break ;
	}
	if (count != 1)
		return (1);
	return (0);
}

void	valid_map(t_map_parse *map)
{
	print_matrix(map);
	if (space_exist_next_to_0(map) == 1)
		ft_errors("Invalid map, there are spaces next to 0\n");
	spaces_to_ones(map);
	if (only_characters_allowed(map) == 1)
		ft_errors("Invalid map, characters not allowed were found\n");
	if (is_one_player(map) == 1)
		ft_errors("Invalid map, there must be only one player\n");
	if (its_playable(map) == 1)
		ft_errors("Invalid map. The map is not playable\n");
}
