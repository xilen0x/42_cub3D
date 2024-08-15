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

//spaces_to_ones(lmap);

void	remove_external_tabs_spaces_elem(t_lmap *lmap)
{
	char	*line;

	while (lmap)
	{
		if (ft_strnstr(lmap->content, "NO", ft_strlen(lmap->content)) || 
			ft_strnstr(lmap->content, "SO", ft_strlen(lmap->content)) || 
			ft_strnstr(lmap->content, "EA", ft_strlen(lmap->content)) || 
			ft_strnstr(lmap->content, "WE", ft_strlen(lmap->content)) || 
			ft_strnstr(lmap->content, "F", ft_strlen(lmap->content)) || 
			ft_strnstr(lmap->content, "C", ft_strlen(lmap->content)))
		{
			line = ft_strtrim2(lmap->content, " ", "\t");
			free(lmap->content);
			lmap->content = line;
			lmap = lmap->next;
		}
		else
			break ;
	}
}

// void	remove_external_tabs_spaces_elem(t_lmap *lmap)
// {
// 	char	*line;

// 	while (lmap && (lmap->content[0] == ' ' || lmap->content[0] == '\t' || 
// 			lmap->content[0] != '1'))
// 	{
// 		line = ft_strtrim2(lmap->content, " ", "\t");
// 		printf("%s\n", line);
// 		free(lmap->content);
// 		lmap->content = line;
// 		lmap = lmap->next;
// 	}
// }


// void	remove_internal_tabs_spaces_elem(t_lmap *lmap)
// {
// 	int		i;

// 	while (lmap)
// 	{
// 		i = 0;
// 		while (lmap->content[i])
// 		{
// 			if (lmap->content[i] == '\t' || lmap->content[i] == ' ')
// 				lmap->content[i] = ' ';
// 			i++;
// 		}
					// 		lmap = lmap->next;
// 	}
// }
void	remove_empty_lines(t_lmap *lmap)
{
	t_lmap	*prev;

	prev = NULL;
	while (lmap)
	{
		if (lmap->content[0] == '\0')
		{
			if (prev)
				prev->next = lmap->next;
			free(lmap->content);
			free(lmap);
			lmap = prev;
		}
		lmap = lmap->next;
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
