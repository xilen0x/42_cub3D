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

int	exist_elements_or_colors_anywhere(t_lmap *lmap)
{
	int		count;

	count = 0;
	while (lmap)
	{
		if (ft_strnstr(lmap->cont, "NO", ft_strlen(lmap->cont)))
			count++;
		else if (ft_strnstr(lmap->cont, "SO", ft_strlen(lmap->cont)))
			count++;
		else if (ft_strnstr(lmap->cont, "EA", ft_strlen(lmap->cont)))
			count++;
		else if (ft_strnstr(lmap->cont, "WE", ft_strlen(lmap->cont)))
			count++;
		else if (ft_strnstr(lmap->cont, "F", ft_strlen(lmap->cont)))
			count++;
		else if (ft_strnstr(lmap->cont, "C", ft_strlen(lmap->cont)))
			count++;
		lmap = lmap->next;
	}
	if (count != 6)
		ft_errors("Invalid number of elements or colors\n");
	return (0);
}

/*Descripción:Encamina el parsing segun sea el caso. 
  Objetivo: Manejar lineas en cualquier orden estas vengan.*/
static void	hub_elements(t_lmap *lmap, t_colors *colors)
{
	while (lmap)
	{
		if ((lmap->cont[0] == 'N') || (lmap->cont[0] == 'S') || 
			(lmap->cont[0] == 'W') || (lmap->cont[0] == 'E'))
		{
			if (exist_elements(lmap))
				ft_errors("Invalid elements\n");
			if (exist_path_elements(lmap))
				ft_errors("Invalid path 04\n");
		}
		else if ((lmap->cont[0] == 'F') || (lmap->cont[0] == 'C'))
		{
			add_one_space_between_elements(lmap);
			if (exist_colors(lmap))
				ft_errors("Invalid colors\n");
			if (exist_path_colors_op2(lmap, colors))
				ft_errors("Invalid path or color\n");
		}
		lmap = lmap->next;
	}
}

void	parsing_map(t_map *map, t_lmap **lmap)
{
	if (first_row_is_all_ones(*lmap) == 1)
		ft_errors("Invalid map. The row 1 is not all 1\n");
	if (rows_are_all_ones(*lmap) == 1)
		ft_errors("Invalid map. One or more rows are open\n");
	if (is_square_map(*lmap) == 1)
		create_matrix(map, *lmap);
	else
		create_matrix_irregular(map, *lmap);
	valid_map(map);
	ft_printf("\n\n-------07 MATRIX DESP. DE VALID_MAP----\n\n");
	print_matrix(map);
}

void	parse_elems(t_elem *elem, t_lmap *lmap, t_colors *colors)
{
	remove_extra_spaces_or_tabs(lmap);
	remove_external_tabs_spaces_elem(lmap);
	if (exist_elements_or_colors_anywhere(lmap))
		ft_errors("Invalid number of elements or colors\n");
	hub_elements(lmap, colors);
	save_path_chain_to_elem_struct(lmap, elem);
}

/******************************Menu parsing*******************************/
void	parsing(t_elem *elem, t_colors *colors, t_map *map, t_lmap **lmap)
{
	file_is_cub(elem->av[1]);
	open_map(elem->av[1], map);
	create_list(map, lmap);
	remove_empty_lines(*lmap);
	parse_elems(elem, *lmap, colors);
	parsing_map(map, lmap);
}
