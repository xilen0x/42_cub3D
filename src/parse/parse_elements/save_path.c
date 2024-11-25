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
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
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

void	save_colors_in_hx(t_lmap *lmap, t_colors *col)
{
	if (lmap->cont[0] == 'F')
		col->f_color_hex = (col->f_color[0] << 16) + (col->f_color[1] << 8) + \
		col->f_color[2];
	else if (lmap->cont[0] == 'C')
		col->c_color_hex = (col->c_color[0] << 16) + (col->c_color[1] << 8) + \
		col->c_color[2];
}

int	save_path_elem(t_lmap *lmap, t_elem *elem, t_colors *colors)
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
		if (colors->f == 1 && colors->c == 2)
			return (0);
		free_elements(elements);
		lmap = lmap->next;
	}
	return (0);
}
