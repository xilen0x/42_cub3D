/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:33:36 by castorga          #+#    #+#             */
/*   Updated: 2024/08/19 10:33:38 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	save_path3(t_elem *elem, char *line, char *option)
{
	if (ft_strncmp(option, "NO", 2) == 0)
		elem->no_path = ft_strdup(line);
	else if (ft_strncmp(option, "SO", 2) == 0)
		elem->so_path = ft_strdup(line);
	else if (ft_strncmp(option, "EA", 2) == 0)
		elem->ea_path = ft_strdup(line);
	else if (ft_strncmp(option, "WE", 2) == 0)
		elem->we_path = ft_strdup(line);
	free(line);
}

static void	save_path2(t_elem *elem, char **elements, int i, int temp)
{
	char	*line;
	char	*option;

	while (elements[i] && ((ft_strncmp(elements[i], "NO", 2) == 0) || \
			(ft_strncmp(elements[i], "SO", 2) == 0) || \
			(ft_strncmp(elements[i], "EA", 2) == 0) || \
			(ft_strncmp(elements[i], "WE", 2) == 0)))
	{
		if (ft_strlen(elements[i]) == 2)
		{
			option = elements[i];
			if (ft_strncmp(elements[i], option, 2) == 0)
			{
				line = ft_strdup(elements[i + 1]);
				save_path3(elem, line, option);
				temp++;
			}
		}
		if (temp == 1)
			break ;
		i++;
	}
}

void	save_colors(t_colors *colors, char **elements, int i)
{
	while (elements[i] && ((ft_strncmp(elements[i], "F", 1) == 0) || (ft_strncmp(elements[i], "C", 1) == 0)))
	{
		if (ft_strlen(elements[i]) == 1)
		{
			if (ft_strncmp(elements[i], "F", 1) == 0)
			{
				colors->f = 1;
				colors->f_color[0] = ft_atoi(elements[i + 1]); // Rojo
				colors->f_color[1] = ft_atoi(elements[i + 2]); // Verde
				colors->f_color[2] = ft_atoi(elements[i + 3]); // Azul
				colors->f_color_hex = (colors->f_color[0] << 16) | (colors->f_color[1] << 8) | colors->f_color[2];
			}
			else if (ft_strncmp(elements[i], "C", 1) == 0)
			{
				colors->c = 2;
				colors->c_color[0] = ft_atoi(elements[i + 1]); // Rojo
				colors->c_color[1] = ft_atoi(elements[i + 2]); // Verde
				colors->c_color[2] = ft_atoi(elements[i + 3]); // Azul
				colors->c_color_hex = (colors->c_color[0] << 16) | (colors->c_color[1] << 8) | colors->c_color[2];
			}
			i += 4; // Salta F/C y sus tres valores RGB
		}
		else
            i++; // Solo avanza si no se encontró un elemento válido
	}
}


int	save_path_chain_to_elem_struct(t_lmap *lmap, t_elem *elem, t_colors *colors)
{
	char	**elements;
	int		i;
	int		temp;

	temp = 0;
	while (lmap)
	{
		if (lmap->cont[0] == '\n')
		{
			lmap = lmap->next;
			continue ;
		}
		elements = ft_split2(lmap->cont);
		i = 0;
		save_path2(elem, elements, i, temp);
		save_colors(colors, elements, i);
		free_elements(elements);
		lmap = lmap->next;
	}
	return (0);
}
