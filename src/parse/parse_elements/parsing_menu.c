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

/*funcion que guarda en */
void	parsing_components(t_elem *elem, t_colors *colors, t_map *map, char *av[])
{
	parsing_elements(elem, map);
	//print_elements(elem);
	open_map(av[1], map);
	parsing_colors(colors, map);
	//print_colors(colors);
	open_map(av[1], map);
	parsing_map(map);
	// save_map(av[1], map);
}

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
