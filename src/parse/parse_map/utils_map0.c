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