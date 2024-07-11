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

/*
	Search(& save)the longest(num) line of the map.
	Reserve memory and store the map in the matrix.
*/
static size_t	search_longest_line(t_map *map)
{
	char	*line;
	size_t	longest_line;
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	longest_line = 0;
	line = get_next_line(map->map_fd);
	if (!line)
		write (2, "Invalid map!\n", 13);
	while (line)
	{
		len = ft_strlen(line);
		map->matrix = spaced_malloc(map->h + 1, sizeof(char *));
		map->matrix[i] = line;
		printf("%s", map->matrix[i]);
        // printf("Length of line: %zu\n", len);
		if (len > 0 && line[len - 1] == '\n')
			len--;
		if (longest_line < len)
			longest_line = len;
		free(line);
		line = get_next_line(map->map_fd);
	}
	close(map->map_fd);
	return (longest_line);
}

/*Funcion que calcula long. de columnas(w) & filas(h)*/
void	width_height_map_file(t_map *map, char *av[])
{
	char	*line;

	map->w = search_longest_line(map);
	open_map(av[1], map);
	line = get_next_line(map->map_fd);
	if (!line)
		write (2, "Invalid map!\n", 13);
	while (line)
	{
		map->h++;
		free(line);
		line = get_next_line(map->map_fd);
	}
	free(line);
	close(map->map_fd);
	// printf("height: %d\n", map->h);
	// printf("longest line: %d\n", map->w);
}

/*Funcion que abre el mapa en modo lectura y almacena su fd en map_fd*/
int	open_map(char *av, t_map *map)
{
	map->map_fd = open(av, O_RDONLY);
	if (map->map_fd == -1)
		ft_errors(2);
	return (0);
}
