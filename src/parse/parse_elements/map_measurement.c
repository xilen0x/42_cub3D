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

/*busqueda de linea mas larga en el mapa(incluyendo elementos)*/
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
    map->h = i;
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
/*funcion que calcula altura y ancho de una lista(para luego poder reservar memoria con estos datos)*/

/*Funcion que calcula long. de lista*/
void width_height_map_list(t_lmap *lmap, t_map *map)
{
	t_lmap *tmp;
	unsigned int len;
	unsigned int i;

	i = 0;
	tmp = lmap;
	len = lst_size(tmp);
	while (lmap)
	{
		if (lmap->content == '\n')
			i++;
		lmap = lmap->next;
	}
	map->h = i;
	map->w = len / i;
	// printf("len: \n%d\n", len);
	// printf("h: %d\n", map->h);
	// printf("w: %d\n", map->w);
}