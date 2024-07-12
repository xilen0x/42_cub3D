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

int	elements_colors_exist(char *av, t_map *map)
{
	char	*line;
	char	**elements;
	int		i;
	char	**colors;

	open_map(av, map);
	line = get_next_line(map->map_fd);
	while (line)
	{
		elements = ft_split(line, ' ');
		i = 0;
		while (elements[i])
			i++;
		if (i == 2)
		{
			if ((ft_strncmp(elements[0], "F", 1) == 0) || (ft_strncmp(elements[0], "C", 1) == 0))
			{
				if (ft_strncmp(elements[0], "F", 1) == 0)
				{
					colors = ft_split(elements[1], ',');
					map->f++;
				}
				else if (ft_strncmp(elements[0], "C", 1) == 0)
				{
					colors = ft_split(elements[1], ',');
					map->c++;
				}
				i = 0;
				while (colors[i])
					i++;
				if (i != 3)
				{
					printf("Error de sintaxis en colores!\n");
					return (1);
				}
			}
		}
		free(line);
		line = get_next_line(map->map_fd);
    }
	if (map->f && map->c)
	{
        close(map->map_fd);
		printf("All colors exist\n");
        return (0);
    }
	else
	{
		close(map->map_fd);
		printf("algo falla!\n");
		return (1);
	}
	return (0);
}

//Elements exist(in any order)
int	elements_exist(t_map *map)
{
	char	*line;
	char	**elements;
	int		i;

	line = get_next_line(map->map_fd);
	while (line)
	{
		elements = ft_split(line, ' ');
		i = 0;
		while (elements[i])
			i++;
		if (i == 2)
		{
			if (ft_strncmp(elements[0], "NO", 2) == 0)
				map->no++;
			else if (ft_strncmp(elements[0], "SO", 2) == 0)
				map->so++;
			else if (ft_strncmp(elements[0], "WE", 2) == 0)
				map->we++;
			else if (ft_strncmp(elements[0], "EA", 2) == 0)
				map->ea++;
		}
		free(line);
		line = get_next_line(map->map_fd);
    }
	if (map->no && map->so && map->we && map->ea)
	{
        close(map->map_fd);
		printf("All cardinal directions exist\n");
        return (0);
    }
	else
	{
        printf("elementos no son dos!\n");
        close(map->map_fd);
        return (1);
    }
	return (0);
}
