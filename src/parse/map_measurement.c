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

/*search(& save the n)the longest line of the map*/
static size_t	search_longest_line(int fd)
{
	char	*line;
	size_t	longest_line;

	longest_line = 0;
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
	return (longest_line);
}
/*Funcion que calcula long. de columnas & filas*/
void	width_height_map_file(int fd, t_map *map, char *av)
{
	char	*line;

	map->w = search_longest_line(fd);
	open_map(av, map);
	line = get_next_line(fd);
	if (!line)
		write (2, "Invalid map!\n", 13);
	while (line)
	{
		map->h++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	printf("height: %d\n", map->h);
	printf("longest line: %d\n", map->w);
}

/*Funcion que abre el mapa en modo lectura y almacena su fd en map_fd*/
int	open_map(char *av, t_map *map)
{
	map->map_fd = open(av, O_RDONLY);
	if (map->map_fd == -1)
		ft_errors(2);
	return (0);
}
