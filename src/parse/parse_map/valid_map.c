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

// void	parsing_square_map(t_lmap *lmap)
// {
// 	(void)lmap;
// 	// if (is_surrounded_by_walls(game) != 0)
// 	// 	ft_errors(3);
// 	// if (is_initial_position(game) != 1)
// 	// 	ft_errors(3);
// 	// if (has_only_one_exit(game) != 1)
// 	// 	ft_errors(3);
// 	// if (valid_path_to_exit(game) == 0)
// 	// 	ft_errors(4);
// 	// if (valid_path_to_collectables(game) != 0)
// 	// 	ft_errors(4);
// 	// if (q_collectible(game) < 1)
// 	// 	ft_errors(3);
// }

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
	{
		ft_printf("Error\n");
		ft_errors(3);
	}
	else
		ft_printf("Map is valid\n");
}
