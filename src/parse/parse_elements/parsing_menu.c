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
	  	ft_errors(3);//corregir(si procede) luego los mensajes de error
	// //F: cant. de elementos o formato debe ser == (X XXX,XXX,XXX)
	// //F 220,100,0
	// if (elements_colors_range(map) != 0)
	// 	ft_errors(3);	
	return (0);
}

void	parsing(t_map *map, char *av[])
{
	file_is_cub(av[1]);
	open_map(av[1], map);
	width_height_map_file(map, av);
	open_map(av[1], map);
	parsing_elements(av[1], map);
	//parsing_map(&map);
	//print_width_height(map);
}
