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

int	ft_is_space(char c)
{
	// Comprueba si el carácter es un espacio en blanco o una tabulación
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
		// Si la línea está vacía o contiene solo espacios/tabulaciones, eliminarla
		if (is_empty_or_whitespace(current->content))
		{
			temp = current;
			if (prev) // No es el primer nodo
				prev->next = current->next;
			else // Es el primer nodo
				lmap = current->next;
			current = current->next;
			free(temp->content);
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
