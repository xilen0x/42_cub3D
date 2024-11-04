/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_path_colors2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:16:54 by castorga          #+#    #+#             */
/*   Updated: 2024/08/12 19:16:56 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exist_path_colors2(char **line, t_colors *colors, t_lmap *lmap)
{
	int		i;

	i = 0;
	while (line[i] && *line[i] != '\n')
		i++;
	if (i == 3)
	{
		if (check_range_values(i, line, colors, lmap) == 1)
		{
			free_elements(line);
			ft_errors("Invalid color value 2\n");
		}
	}
	else
	{
		free_elements(line);
		return (1);
	}
	return (0);
}

int	exist_path_colors_op2(t_lmap *lmap, t_colors *colors)
{
	char	**line;

	line = NULL;
	line = split_space_tab_comma(lmap->cont);
	if (exist_path_colors2(line, colors, lmap))
		ft_errors("Invalid path or color\n");
	free_elements(line);
	return (0);
}


int	exist_path_colors(t_lmap *lmap, t_colors *colors)
{
	char	**line;

	while (lmap)
	{
		line = NULL;
		line = split_space_tab_comma(lmap->cont);
		if (ft_strncmp(line[0], "F", 1) == 0 || \
			ft_strncmp(line[0], "C", 1) == 0)
			if (exist_path_colors2(line, colors, lmap))
				ft_errors("Invalid color value 1\n");
		free_elements(line);
		lmap = lmap->next;
	}
	return (0);
}
