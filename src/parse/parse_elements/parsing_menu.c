/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:44:32 by castorga          #+#    #+#             */
/*   Updated: 2024/07/09 15:44:35 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	parsing_comp2(t_elem *elem, t_colors *colors, t_map *map, char *line)
{
	char	*line_trimed;
	char	**elements;

	line_trimed = ft_strtrim2(line, " ", "\t");
	elements = ft_split2(line_trimed);
	if ((ft_strncmp(elements[0], "F", 1) == 0) || (ft_strncmp(elements[0], "C", 1) == 0))
	{
		parsing_colors2(colors, map, line);
		open_map(elem->av[1], map);
		parsing_elements(elem, map);
		free_elements(elements);
		free(line_trimed);
		return ;
	}
	else
	{
		parsing_elements2(elem, map, line);
		open_map(elem->av[1], map);
		parsing_colors(colors, map);
		free_elements(elements);
		free(line_trimed);
		return ;
	}
	free_elements(elements);
	free(line_trimed);
}

void	parsing_components(t_elem *elem, t_colors *colors, t_map *map)
{
	char	*line;

	line = get_next_line(map->map_fd);
	while (1)
	{
		if (line[0] == '\n')//SEGFAULT HERE*****************************************
		{
			free(line);
			line = get_next_line(map->map_fd);
			continue ;
		}
		parsing_comp2(elem, colors, map, line);
	}
	free(line);
	return ;
}

void	parsing(t_elem *elem, t_colors *colors, t_map *map, t_lmap **lmap)
{
	(void)lmap;
	file_is_cub(elem->av[1]);
	open_map(elem->av[1], map);
	parsing_components(elem, colors, map);
	//parsing_map(map, lmap);
	// print_elements(elem);
	// print_colors(colors);
	// print_width_height(map);
}
