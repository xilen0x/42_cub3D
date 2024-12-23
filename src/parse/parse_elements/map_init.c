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
static void	init_elem_values(t_elem *elem, char *av[])
{
	elem->no_path = NULL;
	elem->so_path = NULL;
	elem->ea_path = NULL;
	elem->we_path = NULL;
	elem->av = av;
	elem->line = NULL;
}

/*Inicializacion de valores structura t_colors*/
static void	init_colors_values(t_colors *colors)
{
	colors->f = 0;
	colors->c = 0;
	colors->f_color[0] = 255;
	colors->f_color[1] = 255;
	colors->f_color[2] = 255;
	colors->c_color[0] = 255;
	colors->c_color[1] = 255;
	colors->c_color[2] = 255;
	colors->f_color_hex = 0x0000FF00;
	colors->c_color_hex = 0x0000FF00;
}

/*Inicialización de valores estructura t_map*/
static void	init_map_values(t_map_parse *map)
{
	map->map_fd = 0;
	map->w = 0;
	map->h = 0;
	map->x = 0;
	map->y = 0;
	map->matrix = NULL;
}

/*Inicializacion de valores*/
void	init_values(t_elem *elem, t_colors *col, t_map_parse *m, char *av[])
{
	init_elem_values(elem, av);
	init_colors_values(col);
	init_map_values(m);
}
