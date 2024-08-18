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

void	remove_external_tabs_spaces_elem(t_lmap *lmap)
{
	char	*line;

	while (lmap)
	{
		if (ft_strnstr(lmap->cont, "NO", ft_strlen(lmap->cont)) || 
			ft_strnstr(lmap->cont, "SO", ft_strlen(lmap->cont)) || 
			ft_strnstr(lmap->cont, "EA", ft_strlen(lmap->cont)) || 
			ft_strnstr(lmap->cont, "WE", ft_strlen(lmap->cont)) || 
			ft_strnstr(lmap->cont, "F", ft_strlen(lmap->cont)) || 
			ft_strnstr(lmap->cont, "C", ft_strlen(lmap->cont)))
		{
			line = ft_strtrim2(lmap->cont, " ", "\t");
			free(lmap->cont);
			lmap->cont = line;
			lmap = lmap->next;
		}
		else
			break ;
	}
}

int	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

// Función para verificar si una línea está vacía o solo contiene espacios/tabs
int	is_empty_or_whitespace(const char *str)
{
	while (*str)
	{
		if (!ft_is_space(*str))
			return (0);
		str++;
	}
	return (1);
}

void	remove_empty_lines(t_lmap *lmap)
{
	t_lmap	*current;
	t_lmap	*prev;
	t_lmap	*temp;

	current = lmap;
	prev = NULL;
	while (current)
	{
		if (is_empty_or_whitespace(current->cont))
		{
			temp = current;
			if (prev)
				prev->next = current->next;
			else
				lmap = current->next;
			current = current->next;
			free(temp->cont);
			free(temp);
		}
		else
		{
			prev = current;
			current = current->next;
		}
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
