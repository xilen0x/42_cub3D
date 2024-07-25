/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:24:45 by castorga          #+#    #+#             */
/*   Updated: 2024/07/24 15:24:48 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parsing_elements(t_elem *elem, t_map *map)
{
    char *line;
    char **elements;
    char *temp;
	char *line_trimed;
	int i;
	int j;

    line = get_next_line(map->map_fd);
    while (line)
	{
        if (line[0] == '\n')
		{
            free(line);
            line = get_next_line(map->map_fd);
            continue ;
        }
		line_trimed = ft_strtrim2(line, " ", "\t");
        elements = ft_split2(line_trimed);			
		texture_path_extension_is_valid(elements[1]);//SEGV*******************
		remove_tabs(elements);
		i = 0;
		while (elements[i])
			i++;
		j = 0;
		if (i == 2)
		{
			if (ft_strncmp(elements[0], "NO", 2) == 0)
			{
				j++;
				temp = ft_strtrim(elements[0], " ");
				elem->no = temp;
				temp = ft_strtrim(elements[1], " ");
				elem->no_path = temp;
			}
			else if (ft_strncmp(elements[0], "SO", 2) == 0)
			{
				j++;
				temp = ft_strtrim(elements[0], " ");
				elem->so = temp;
				temp = ft_strtrim(elements[1], " ");
				elem->so_path = temp;
			}
			else if (ft_strncmp(elements[0], "EA", 2) == 0)
			{
				j++;
				temp = ft_strtrim(elements[0], " ");
				elem->ea = temp;
				temp = ft_strtrim(elements[1], " ");
				elem->ea_path = temp;
			}
			else if (ft_strncmp(elements[0], "WE", 2) == 0)
			{
				j++;
				temp = ft_strtrim(elements[0], " ");
				elem->we = temp;
				temp = ft_strtrim(elements[1], " ");
				elem->we_path = temp;
			}
			if (elem->no && elem->so && elem->ea && elem->we)
			{
				free_elements(elements);
				free(line);
				close(map->map_fd);
				free(line_trimed);
				return ;
			}
		}
		else
		{
			printf("Error de sintaxis en elementos!\n");
			free_elements(elements);
			free(line);
			close(map->map_fd);
			free(line_trimed);
			return ;
		}
        free_elements(elements);
        free(line);
		free(line_trimed);
        line = get_next_line(map->map_fd);
    }
    close(map->map_fd);
}