/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:34:22 by castorga          #+#    #+#             */
/*   Updated: 2024/07/16 15:34:23 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Inicializacion de valores estructura t_elem*/
void	init_elem_values(t_elem *elem)
{
	elem->no = 0;
	elem->so = 0;
	elem->ea = 0;
	elem->we = 0;
	elem->no_path = NULL;
	elem->so_path = NULL;
	elem->we_path = NULL;
	elem->ea_path = NULL;
}

/*Inicializacion de valores structura t_colors*/
void	init_colors_values(t_colors *colors)
{
	colors->f = 0;
	colors->c = 0;
	colors->f_color[0] = -1;
	colors->f_color[1] = -1;
	colors->f_color[2] = -1;
	colors->c_color[0] = -1;
	colors->c_color[1] = -1;
	colors->c_color[2] = -1;
}

/*Inicialización de valores estructura t_map*/
void	init_map_values(t_map *map)
{
	map->map_fd = 0;
	map->w = 0;
	map->h = 0;
	map->matrix = NULL;
}

/*Inicializacion de valores*/
void	init_values(t_elem *elem, t_colors *colors, t_map *map)
{
	init_elem_values(elem);
	init_colors_values(colors);
	init_map_values(map);
}
