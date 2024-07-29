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
			//printf("%s", line);
			i = 0;
			while (line[i])
			{
				node = ft_newnode(line[i]);
				ft_add_back(&lmap, node);
				i++;
			}
		}
		free(line);
		line = get_next_line(map->map_fd);
	}
	close(map->map_fd);
	printf("\n");
}

// void print_list(t_lmap *lmap)
// {
//     while (lmap)
//     {
//         printf("%c ", lmap->content);
//         lmap = lmap->next;
//     }
//     printf("\n");
// }
void print_list(t_lmap *lmap)
{
    while (lmap)
    {
        printf("%c ", lmap->content);
        lmap = lmap->next;
    }
    printf("\n");
}

void	parsing_map(t_map *map, t_lmap *lmap)
{
	create_list(map, lmap);
	print_list(lmap);
	// create_matrix(map);
	// parsing_map(map);	
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
