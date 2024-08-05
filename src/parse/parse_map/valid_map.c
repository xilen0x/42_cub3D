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

int	is_one_player(t_map *map)
{
	int	count;

	count = 0;
	map->y = 0;
	while (map->matrix[map->y])
	{
		map->x = 0;
		while (map->matrix[map->y][map->x])
		{
			if (map->matrix[map->y][map->x] == 'N' ||
				map->matrix[map->y][map->x] == 'S' ||
				map->matrix[map->y][map->x] == 'E' ||
				map->matrix[map->y][map->x] == 'W')
				count++;
			map->x++;
		}
		if ((map->y + 1) < map->h)
			map->y++;
		else
			break ;
	}
	if (count != 1)
	{
		return (1);
	}
	printf("count: %d\n", count);
	return (0);
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

void	valid_map(t_map *map)
{
	if (any_zero_or_space(map) == 1)
		ft_errors(3);
	else
		ft_printf("Map is valid\n");
	if (is_one_player(map) == 1)
		ft_printf("Player is not valid!\n");
	else
		ft_printf("Player is valid\n");
}
