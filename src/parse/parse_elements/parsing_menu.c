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

static int	parsing_elements(char *av, t_map *map)
{
	if (elements_exist(map) != 0)
		ft_errors(3);
	if (elements_colors_exist(av, map) != 0)
	  	ft_errors(3);
	//texture_path_extension_is_valid(map);//corregir luego los mensajes de error

	// //F: cant. de elementos o formato debe ser == (X XXX,XXX,XXX)
	// //F 220,100,0
	// if (expected_syntax_colors(game) != 0)
	// 	ft_errors(3);
	return (0);
}

void	parsing(t_map *map, char *av[])
{
	// int	i;

	file_is_cub(av[1]);
	open_map(av[1], map);
	width_height_map_file(map, av);
	open_map(av[1], map);
	parsing_elements(av[1], map);
	// open_map(av[1], map);
	// i = 0;
	// while (map->matrix[i] != NULL)
	// {
	// 	printf("line %d: %s\n", i, map->matrix[i]);
	// 	i++;
	// }
	//printf("firt line: %s\n", map->matrix[0]);
	// parsing_elements(map);
	//parsing_map(&map);
	//print_width_height(map);
}
