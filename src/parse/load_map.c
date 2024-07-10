/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:44:21 by castorga          #+#    #+#             */
/*   Updated: 2024/07/09 15:44:23 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Funcion que crea y guarda la matriz*/
// void	create_matrix(t_game *game, char *av)
// {
// 	int	i;

// 	i = 0;
// 	open_map(av, game);
// 	game->matrix = malloc(sizeof(char *) * (game->h + 1));
// 	if (!game->matrix)
// 		return ;
// 	while (i < game->h)
// 	{
// 		game->matrix[i] = get_next_line(game->map_fd);
// 		i++;
// 	}
// 	game->matrix[game->h] = NULL;
// 	close(game->map_fd);
// }

/*Funcion que calcula long. de columnas & filas*/
void	width_height_map_file(int fd, t_map *map, char *av)
{
	char	*line;
(void)av;
	line = get_next_line(fd);
	if (!line)
		write (2, "Invalid map!\n", 13);
	map->w = search_longest_line(fd, map);
	while (line)
	{
		map->h++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	// create_matrix(map, av);
	printf("width: %d\n", map->w);
	printf("height: %d\n", map->h);
	printf("longest line: %d\n", map->w);
}

/*search(& save the n)the longest line of the map*/
size_t	search_longest_line(int fd, t_map *map)
{
	char	*line;
	size_t	longest_line;
(void)map;
	line = get_next_line(fd);
	if (!line)
		write (2, "Invalid map!\n", 13);
	longest_line = ft_strlen(line) - 1;
	while (line)
	{
		if (longest_line < ft_strlen(line) - 1)
			longest_line = ft_strlen(line) - 1;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	//create_matrix(game, av);
	// printf("longest line: %ld\n", game->longest_line);
	return (longest_line);
}
/*Funcion que abre el mapa en modo lectura y almacena su fd en map_fd*/
int	open_map(char *av, t_map *map)
{
	map->map_fd = open(av, O_RDONLY);
	if (map->map_fd == -1)
		ft_errors(2);
	return (0);
}
