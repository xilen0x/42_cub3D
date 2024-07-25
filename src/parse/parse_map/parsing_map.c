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

void	parsing_map(t_map *map)
{
	char	*line;
	t_map	*node;

	line = get_next_line(map->map_fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(map->map_fd);
			continue ;
		}
		if ((line[0] == '0') || (line[0] == '1'))
		{
			// printf("%s", line);
			node = ft_newnode(line);
			ft_add_back(&map, node);
			printf("%s", (char *)node->content);
		
			free(line);
			line = get_next_line(map->map_fd);
			continue ;
		}
		free(line);
		line = get_next_line(map->map_fd);
	}
	close(map->map_fd);
}

// void	save_map(char *av, t_map *map)//no utilizada aun y esta incompleta
// {
// 	char	*line;
	
// 	map->map_fd = open(av, O_RDONLY);
// 	if (map->map_fd == -1)
// 		ft_errors(2);	
// 	line = get_next_line(map->map_fd);
// 	while (line)
// 	{
// 		if (line[0] == '\n')
// 		{
// 			free(line);
// 			line = get_next_line(map->map_fd);
// 			continue ;
// 		}
// 		remove_tabs_and_spaces(line);
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(map->map_fd);
// 	}
// 	close(map->map_fd);
// }
