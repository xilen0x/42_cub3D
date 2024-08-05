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

int	ft_strcmp(char c1, char c2)
{
	if (c1 > c2)
		return (1);
	else if (c1 == c2)
		return (0);
	else
		return (-1);
}

size_t	spaces_to_zeros(t_lmap *lmap)
{
	size_t	i;

	i = 0;
	while (lmap)
	{
		i = 0;
		while (lmap->content[i] == ' ' || lmap->content[i] == '\t')
			i++;
		while (lmap->content[i])
		{
			if (lmap->content[i] == ' ')
			{
				if (ft_strcmp(lmap->content[i], ' ') == 0)
					lmap->content[i] = '1';
			}
			i++;
		}
		lmap = lmap->next;
	}
	return (0);
}

/*busqueda de linea mas larga en el mapa(list)*/
size_t	search_longest_line(t_lmap *lmap)
{
	size_t	longest_line;
	size_t	len;

	longest_line = 0;
	while (lmap)
	{
		len = ft_strlen(lmap->content);
		if (len > 0 && lmap->content[len - 1] == '\n')
			len--;
		if (longest_line < len)
			longest_line = len;
		lmap = lmap->next;
	}
	return (longest_line + 1);
}

// /*Funcion que calcula long. de columnas(w) & filas(h)*/
// void width_height_map_file(t_map *map, char *av[])
// {
//     char *line;

//     map->w = search_longest_line(map);
//     open_map(av[1], map);
//     line = get_next_line(map->map_fd);
//     if (!line)
// 	{
//         write(2, "Invalid map!\n", 13);
//         return;
//     }
// 	map->h = 0;
//     while (line)
// 	{
//         map->h++;
//         free(line);
//         line = get_next_line(map->map_fd);
//     }
//     free(line);
//     close(map->map_fd);
// }

/*Funcion que calcula long. de lista*/
// void width_height_map_list(t_lmap *lmap, t_map *map)
// {
// 	t_lmap *tmp;
// 	unsigned int len;
// 	unsigned int i;

// 	i = 0;
// 	tmp = lmap;
// 	len = lst_size(tmp);
// 	while (lmap)
// 	{
// 		i++;
// 		lmap = lmap->next;
// 	}
// 	map->h = i;
// 	map->w = len / i;
// 	ft_printf("\nlen: %d\n", len);
// 	ft_printf("h: %d\n", map->h);
// 	ft_printf("w: %d\n", map->w);
// }