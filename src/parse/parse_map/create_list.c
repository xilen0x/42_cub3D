/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:01:18 by castorga          #+#    #+#             */
/*   Updated: 2024/07/24 17:01:20 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_list(t_map *map, t_lmap **lmap)
{
	char	*line;
	t_lmap	*node;

	line = get_next_line(map->map_fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(map->map_fd);
			continue ;
		}
		// ft_printf("%s", line);
		remove_newline(line);
		node = p_malloc(sizeof(t_lmap));
		node->content = line;
		node->next = NULL;
		ft_add_back(lmap, node);
		line = get_next_line(map->map_fd);
	}
	close(map->map_fd);
}

void	parsing_map(t_map *map, t_lmap **lmap)
{
	printf("\n--------------LISTA DESP. DE VERF EXIST Y AGREGAR 1 ESPACIO--------------n\n");
	print_list(*lmap);
	create_matrix(map, *lmap);
	printf("\n--------------MATRIX RESULTANTE--------------\n");
	print_matrix(map);
	valid_map(map);
// 	lst_clear(lmap, &free);
}
