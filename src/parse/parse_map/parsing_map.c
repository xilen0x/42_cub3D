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

void	create_list(t_map *map, t_lmap *lmap)
{
	char	*line;
	t_lmap	*node;
	int		i;

	line = get_next_line(map->map_fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(map->map_fd);
			continue ;
		}
		i = 0;
		while (line[i] == ' ')			
			i++;
		if ((line[i] == '0') || (line[i] == '1'))
		{
			// printf("%s", line);
			i = 0;
			while (line[i] && line[i] != '\n')//linea modificada
			{
				node = ft_newnode(line[i]);
				ft_add_back(&lmap, node);
				i++;
			}
			node = ft_newnode('\n');//linea agregada
			ft_add_back(&lmap, node);//linea agregada
		}
		free(line);
		line = get_next_line(map->map_fd);
	}
	close(map->map_fd);
//	printf("\n");
}

void print_list(t_lmap *lmap)
{
    while (lmap)
    {
		printf("%c ", lmap->content);
        lmap = lmap->next;
    }
    // printf("\n");
}

void	parsing_map(t_map *map, t_lmap *lmap)
{
	create_list(map, lmap);
	print_list(lmap);
	width_height_map_list(lmap, map);
	create_matrix(map, lmap);
	print_matrix(map);
	// parsing_map(map);	
}
