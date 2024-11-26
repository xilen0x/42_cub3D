/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces_tabs2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:26:28 by castorga          #+#    #+#             */
/*   Updated: 2024/08/19 10:26:30 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_additional_space(t_lmap *lmap, int *additional_space_count)
{
	int		i;
	char	*line;

	i = 0;
	line = lmap->cont;
	while (line[i])
	{
		if (line[i] == ',' && line[i + 1] != ' ' && line[i + 1] != '\t' && \
		line[i + 1] != '\0')
			(*additional_space_count)++;
		i++;
	}
}

void	copy_and_adjust_line_content(char *line, char *new_line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != '\t')
		{
			new_line[j++] = line[i];
			if (line[i] == ',' && line[i + 1] != ' ' && line[i + 1] != '\t' \
			&& line[i + 1] != '\0')
				new_line[j++] = ' ';
			else if (line[i] == ' ')
				while (line[i + 1] == '\t')
					i++;
		}
		i++;
	}
	new_line[j] = '\0';
}

void	create_new_line_and_free_old(t_lmap *lmap, int additional_space_count)
{
	char	*line;
	char	*new_line;

	line = lmap->cont;
	new_line = (char *)malloc(strlen(line) + additional_space_count + 1);
	if (!new_line)
		return ;
	copy_and_adjust_line_content(line, new_line);
	free(lmap->cont);
	lmap->cont = new_line;
}

void	add_one_space_between_elements(t_lmap *lmap)
{
	int	additional_space_count;

	while (lmap)
	{
		additional_space_count = 0;
		calculate_additional_space(lmap, &additional_space_count);
		create_new_line_and_free_old(lmap, additional_space_count);
		lmap = lmap->next;
	}
}
