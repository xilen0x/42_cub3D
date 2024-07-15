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

// void reserve_memory(size_t *longest_line, int *i, t_map *map, char *line)
// {
//     size_t len;
//     size_t old_size;
//     size_t new_size;

//     len = ft_strlen(line);
//     old_size = sizeof(char *) * (*i + 1);
//     new_size = sizeof(char *) * (*i + 2);
//     map->matrix = ft_realloc(map->matrix, old_size, new_size); // Ajusta el tamaño de matrix
//     if (!map->matrix)
//     {
//         write(2, "Memory allocation error!\n", 25);
//         free(line);
//         exit(1);
//     }
//     map->matrix[*i] = line;
//     map->matrix[*i + 1] = NULL;
//     printf("%s", map->matrix[*i]);
//     if (len > 0 && line[len - 1] == '\n')
//         len--;
//     if (*longest_line < len)
//         *longest_line = len;
//     (*i)++;
// }

static size_t search_longest_line(t_map *map)
{
    char *line;
    size_t longest_line;
    int i;
	size_t len;
	
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
        // reserve_memory(&longest_line, &i, map, line);
		//printf("%s", line);
		//if que salta los posibles espacios en blanco y saltos de linea
		if (line[0] == '\0')
		{
			free(line);
			line = get_next_line(map->map_fd);
			continue ;
		}
    	if (len > 0 && line[len - 1] == '\n')
	        len--;
	    if (longest_line < len)
			longest_line = len;
		free(line);
        line = get_next_line(map->map_fd);
    	i++;
    }
    close(map->map_fd);
    map->h = i; // Actualiza la altura de la matriz
    return (longest_line);
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
	map->h = 0;
    while (line)
	{
        map->h++;
        free(line);
        line = get_next_line(map->map_fd);
    }
    free(line);
    close(map->map_fd);
}
