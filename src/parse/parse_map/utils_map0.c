/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:36:43 by castorga          #+#    #+#             */
/*   Updated: 2024/08/19 10:36:45 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	spaces_to_ones(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->matrix[i][j] == ' ')
				map->matrix[i][j] = '1';
			j++;
		}
		i++;
	}
}

/*Check if there is any space around the 0*/
int	any_zero_or_space(t_map *map)
{
	while (map->matrix[map->y])
	{
		map->x = 0;
		while (map->matrix[map->y][map->x])
		{
			if ((map->matrix[map->y][map->x] == '0') &&
				((map->matrix[map->y - 1][map->x] == ' ') ||
				(map->matrix[map->y + 1][map->x] == ' ') ||
				(map->matrix[map->y][map->x - 1] == ' ') ||
				(map->matrix[map->y][map->x + 1] == ' ')))
				return (1);
			map->x++;
		}
		if ((map->y + 1) < map->h)
			map->y++;
		else
			break ;
	}
	return (0);
}