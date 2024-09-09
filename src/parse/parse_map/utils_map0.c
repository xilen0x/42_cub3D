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
	int		x;
	int		y;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if ((map->matrix[y][x] == '0') &&
				((map->matrix[y - 1][x] == ' ') ||
				(map->matrix[y + 1][x] == ' ') ||
				(map->matrix[y][x - 1] == ' ') ||
				(map->matrix[y][x + 1] == ' ')))
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

int	space_exist_next_to_0(t_map *m)
{
	int	x;
	int	y;

	y = 0;
	while (m->matrix[y])
	{
		x = 0;
		while (m->matrix[y][x])
		{
			if (m->matrix[y][x] == '0')
			{
				if (m->matrix[y][x + 1] == ' ' || m->matrix[y][x - 1] == ' ' || \
					m->matrix[y + 1][x] == ' ' || m->matrix[y - 1][x] == ' ')
					return (1);
			}
			x++;
		}
		if ((y + 1) < m->h)
			y++;
		else
			break ;
	}
	return (0);
}
