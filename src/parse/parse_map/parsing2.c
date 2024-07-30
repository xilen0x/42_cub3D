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

int	starts_and_ends_with_1(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->w)
	{
		if (map->matrix[0][i] != '1')
			return (1);
		i++;
	}
	while (j < map->h)
	{
		if (map->matrix[j][0] != '1')
			return (1);
		j++;
	}
	i = 0;
	j = 0;
	while (i < map->w)
	{
		if (map->matrix[map->h - 1][i] != '1')
			return (1);
		i++;
	}
	while (j < map->h)
	{
		if (map->matrix[j][map->w - 1] != '1')
			return (1);
		j++;
	}
	return (0);
}


int	valid_map(t_map *map)
{
	if (starts_and_ends_with_1(map) != 0)
		ft_errors(3);
	// if (is_surrounded_by_walls(game) != 0)
	// 	ft_errors(3);
	// if (is_initial_position(game) != 1)
	// 	ft_errors(3);
	// if (has_only_one_exit(game) != 1)
	// 	ft_errors(3);
	// if (valid_path_to_exit(game) == 0)
	// 	ft_errors(4);
	// if (valid_path_to_collectables(game) != 0)
	// 	ft_errors(4);
	// if (q_collectible(game) < 1)
	// 	ft_errors(3);
	return (0);
}
