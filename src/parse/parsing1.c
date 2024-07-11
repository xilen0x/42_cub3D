/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:44:40 by castorga          #+#    #+#             */
/*   Updated: 2024/07/09 15:44:43 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Elements exist(in any order)
int	elements_exist(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	while (line && i != 4)
	{
		line = get_next_line(map->map_fd);
		if (ft_strncmp(line, "NO", 2) == 0)
		{
			map->no++;
			i++;
		}
		else if (ft_strncmp(line, "SO", 2) == 0)
		{
			map->so++;
			i++;
		}
		else if (ft_strncmp(line, "WE", 2) == 0)
		{
			map->we++;
			i++;
		}
		else if (ft_strncmp(line, "EA", 2) == 0)
		{
			map->ea++;
			i++;
		}
	}	
	if (map->no && map->so && map->we && map->ea && i == 4)
	{
		printf("All cardinal directions exist\n");
		return (0);
	}
	else
	{
		printf("Some elements are missing\n");
		printf("NO: %d\n", map->no);
		printf("SO: %d\n", map->so);
		printf("WE: %d\n", map->we);
		printf("EA: %d\n", map->ea);
		printf("F: %d\n", map->f);
		printf("C: %d\n", map->c);
		return (1);
	}
	return (1);
}