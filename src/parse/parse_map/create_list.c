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

#include "cub3d.h"

void	create_list(t_map *map, t_lmap **lmap)
{
	char	*line;
	t_lmap	*node;

	line = get_next_line(map->map_fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(map->map_fd);
			continue ;
		}
		ft_printf("%s", line);//quitar luego***************
		// remove_newline(line);
		node = p_malloc(sizeof(t_lmap));
		node->content = line;
		node->next = NULL;
		ft_add_back(lmap, node);
		line = get_next_line(map->map_fd);
	}
	close(map->map_fd);
}

/*funcion que primero se salta las lineas(NO,SO,WE,EA,F,C) que no corresponden
 al mapa(0,1) y luego, una vez que ha llegado al mapa, lo analiza para detectar
  si es de forma cuadrada (o rectangular tambien) o es un mapa irregular*/
int	is_square_map(t_lmap *lm)
{
	int		len;
	int		len2;

	len = 0;
	len2 = 0;
	while (lm && (
			(ft_strnstr2(lm->content, "NO", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "SO", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "WE", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "EA", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "F", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "C", ft_strlen(lm->content)) != NULL) || 
			(lm->content[0] == '\0')))
		lm = lm->next;
	while (lm)
	{
		len = ft_strlen(lm->content);
		if (len2 == 0)
			len2 = len;
		if (len != len2)
			break ;

		lm = lm->next;
	}
	if (len == len2)
		return (1);
	return (0);
}

void	parsing_map(t_map *map, t_lmap **lmap)
{
	if (is_square_map(*lmap) == 1)
	{
		ft_printf("\nMapa cuadrado\n");
		create_matrix(map, *lmap);
	}
	else
	{
		ft_printf("Mapa irregular\n");
		create_matrix_irregular(map, *lmap);
	}
	//create_matrix(map, *lmap);
	valid_map(map);
// 	lst_clear(lmap, &free);
}
