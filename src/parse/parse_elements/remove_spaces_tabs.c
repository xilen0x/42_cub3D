/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces_tabs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:19:15 by castorga          #+#    #+#             */
/*   Updated: 2024/08/12 11:19:17 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	remove_tabs_spaces_elem(t_lmap *lmap)
{
	char	*line;

	while (lmap)
	{
		line = ft_strtrim2(lmap->content, " ", "\t");
		free(lmap->content);
		lmap->content = line;
		lmap = lmap->next;
	}
}

void	remove_empty_lines(t_lmap *lmap)
{
	t_lmap	*temp;
	t_lmap	*prev;

	temp = lmap;
	prev = NULL;
	while (temp)
	{
		if (temp->content[0] == '\0')
		{
			if (prev)
				prev->next = temp->next;
			free(temp->content);
			free(temp);
			temp = prev;
		}
		prev = temp;
		temp = temp->next;
	}
}

void	remove_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break ;
		}
		i++;
	}
}
