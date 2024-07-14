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

// static int	parsing_elements(char *av, t_map *map)
// {
// 	if (elements_exist(map) != 0)
// 		ft_errors(3);

// 	if (elements_colors_exist(av, map) != 0)
// 	 	ft_errors(3);
	
// 	// if (expected_syntax_textures(game) != 0)
// 	// 	ft_errors(3);

// 	// //F: cant. de elementos o formato debe ser == (X XXX,XXX,XXX)
// 	// //F 220,100,0
// 	// if (expected_syntax_colors(game) != 0)
// 	// 	ft_errors(3);
	
// 	// //Information from elements separated by 1 or + spaces
// 	// if (spaces_handler(game) != 0)
// 	// 	ft_errors(3);
	
// 	// //Elements separated by 1 or + empty lines
// 	// if (empty_lines_handler(game) != 0)
// 	// 	ft_errors(3);

// 	return (0);
// }

// static int	parsing_map(t_game *game)
// {
// 	if (is_rectangular(game) != 0)
// 		ft_errors(3);
// 	if (is_surrounded_by_walls(game) != 0)
// 		ft_errors(3);
// 	if (is_initial_position(game) != 1)
// 		ft_errors(3);
// 	if (has_only_one_exit(game) != 1)
// 		ft_errors(3);
// 	if (valid_path_to_exit(game) == 0)
// 		ft_errors(4);
// 	if (valid_path_to_collectables(game) != 0)
// 		ft_errors(4);
// 	if (q_collectible(game) < 1)
// 		ft_errors(3);
// 	return (0);
// }

void	parsing(t_map *map, char *av[])
{
	// int	i;

	file_is_cub(av[1]);
	open_map(av[1], map);
	width_height_map_file(map, av);
	// open_map(av[1], map);
	// parsing_elements(av[1], map);
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
}

//search_longest_line(map.map_fd, &map, av[1]);
