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

void	parsing_components(t_elem *elem, t_colors *colors, t_map *map, char *av[])
{
	char *line;
    char **elements;
    char *line_trimed;

	line = get_next_line(map->map_fd);
	while (line)
	{
		if (line[0] == '\n')
		{
            free(line);
            line = get_next_line(map->map_fd);
            continue ;
        }
		line_trimed = ft_strtrim2(line, " ", "\t");
        elements = ft_split2(line_trimed);
		if ((ft_strncmp(elements[0], "F", 1) == 0) || (ft_strncmp(elements[0], "C", 1) == 0))
		{
			parsing_colors(colors, map, line);
			open_map(av[1], map);
			parsing_elements(elem, map);
		}
		else
		{
			parsing_elements(elem, map);
			open_map(av[1], map);
			parsing_colors(colors, map, line);
		}
		//free(line);
		line = get_next_line(map->map_fd);
	}
}

/*funcion que guarda en */
// void	parsing_components(t_elem *elem, t_colors *colors, t_map *map, char *av[])
// {
// 	parsing_elements(elem, map);
// 	//print_elements(elem);
// 	open_map(av[1], map);
// 	parsing_colors(colors, map);
// 	//print_colors(colors);
// 	// open_map(av[1], map);
// 	// parsing_map(map);
// 	// save_map(av[1], map);
// }

void	parsing(t_elem *elem, t_colors *colors, t_map *map, char *av[])
{
	file_is_cub(av[1]);
	open_map(av[1], map);
	width_height_map_file(map, av);
	open_map(av[1], map);
	parsing_components(elem, colors, map, av);
	
	//open_map(av[1], map);
	//parsing_elements(av[1], map);
	//parsing_map(&map);
	//print_width_height(map);
}
