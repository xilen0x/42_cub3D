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

# include "cub3d.h"

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
		node = malloc(sizeof(t_lmap));
		node->content = line;
		node->next = NULL;
		ft_add_back(lmap, node);
		line = get_next_line(map->map_fd);
	}
	close(map->map_fd);
	ft_printf("\n");
}

void print_list(t_lmap *lmap)
{
	int i;

	i = 0;
    while (lmap)
    {
		ft_printf("%s", lmap->content);
        lmap = lmap->next;
		i++;
    }
	ft_printf("\n\n");
	ft_printf("Longitud de la lista: %d\n", i);
}

void	parsing_map(t_map *map, t_lmap **lmap)
{
	create_list(map, lmap);
	// print_list(*lmap);
	// width_height_map_list(*lmap, map);
	create_matrix(map, *lmap);
	print_matrix(map);
	// parsing_map(map);
// 	lst_clear(lmap, &free);
}
