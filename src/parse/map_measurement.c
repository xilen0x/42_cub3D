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
static size_t search_longest_line(t_map *map)
{
	char	*line;
    size_t	longest_line;
    size_t	len;
    int		i;

	longest_line = 0;
	i = 0;
    line = get_next_line(map->map_fd);
    if (!line)
	{
        write(2, "Invalid map!\n", 13);
        return 0;
    }
    while (line)
	{
        len = ft_strlen(line);
        map->matrix = realloc(map->matrix, sizeof(char *) * (i + 2)); // Ajusta el tamaño de matrix
        map->matrix[i] = line; // Guarda la línea en matrix
        map->matrix[i + 1] = NULL; // Asegúrate de que el próximo elemento es NULL
        printf("%s", map->matrix[i]);
        if (len > 0 && line[len - 1] == '\n')
		{
            len--;
        }
        if (longest_line < len)
		{
            longest_line = len;
        }
        i++;
        line = get_next_line(map->map_fd);
    }
    close(map->map_fd);
    map->h = i; // Actualiza la altura de la matriz
    return longest_line;
}

/*Funcion que calcula long. de columnas(w) & filas(h)*/
void width_height_map_file(t_map *map, char *av[])
{
    char *line;

    map->w = search_longest_line(map);
    open_map(av[1], map);
    line = get_next_line(map->map_fd);
    if (!line)
	{
        write(2, "Invalid map!\n", 13);
        return;
    }
    while (line)
	{
        map->h++;
        free(line);
        line = get_next_line(map->map_fd);
    }
    free(line);
    close(map->map_fd);
}

/*Funcion que abre el mapa en modo lectura y almacena su fd en map_fd*/
int	open_map(char *av, t_map *map)
{
	map->map_fd = open(av, O_RDONLY);
	if (map->map_fd == -1)
		ft_errors(2);
	return (0);
}
// int	open_matrix(t_map *map)
// {
// 	map->map_fd = open(map->matrix, O_RDONLY);
// 	if (map->map_fd == -1)
// 		ft_errors(2);
// 	return (0);
// }