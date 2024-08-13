/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:44:32 by castorga          #+#    #+#             */
/*   Updated: 2024/07/09 15:44:35 by castorga         ###   ########.fr       */
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

	while (elements[i])
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
		if (temp == 4)
			break ;
		i++;
	}
}

int	save_path_chain_to_elem_struct(t_lmap *lmap, t_elem *elem)
{
	char	**elements;
	int		i;
	int		temp;

	temp = 0;
	while (lmap)
	{
		if (lmap->content[0] == '\n')
		{
			lmap = lmap->next;
			continue ;
		}
		elements = ft_split2(lmap->content);
		i = 0;
		save_path2(elem, elements, i, temp);
		free_elements(elements);
		lmap = lmap->next;
	}
	return (0);
}

int	duplicate_lines(t_lmap *lmap)
{
	t_lmap	*temp;
	t_lmap	*temp2;

	temp = lmap;
	while (temp)
	{
		temp2 = temp->next;
		if (temp->content[0] == 'S' || temp->content[0] == 'N' || \
		temp->content[0] == 'E' || temp->content[0] == 'W' || \
		temp->content[0] == 'F' || temp->content[0] == 'C')
		{
			while (temp2)
			{
				if (ft_strncmp(temp->content, temp2->content, ft_strlen(temp->content)) == 0)
					return (1);
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
		temp = temp->next;
	}
	return (0);
}
int	exist_elements_or_colors_anywhere(t_lmap *lmap)
{
	t_lmap	*temp;
	int		count;

	temp = lmap;
	while (temp)
	{
		if (temp->content[0] == 'S' || temp->content[0] == 'N' || \
		temp->content[0] == 'E' || temp->content[0] == 'W' || \
		temp->content[0] == 'F' || temp->content[0] == 'C')
			count++;
		temp = temp->next;
	}
	if (count != 6)
	{
		ft_printf("count: %d\n", count);
		ft_errors(3);
	}
	
	return (0);
}
/*Deja un(y solo un) espacio despues de la F o C y un espacio antes y despues de la coma.(de los numeros)*/
void	add_one_space_between_elements(t_lmap *lmap)
{
	int		i;
	int		j;
	int		additional_space_count;
	char	*line;
	char	*new_line;

	while (lmap)
	{
		i = 0;
		additional_space_count = 0;
		line = lmap->content;

		// Contar cuántos espacios adicionales serán necesarios
		while (line[i])
		{
			if (line[i] == ',' && line[i + 1] != ' ' && line[i + 1] != '\t' && line[i + 1] != '\0')
				additional_space_count++;
			i++;
		}
		// Asignar memoria suficiente para la nueva cadena
		new_line = (char *)malloc(strlen(line) + additional_space_count + 1);
		if (!new_line)
			return;
		// Reiniciar índices y construir la nueva cadena sin copiar tabulaciones
		i = 0;
		j = 0;
		while (line[i])
		{
			// Copiar comas y cualquier carácter no tabulación
			if (line[i] != '\t')
			{
				new_line[j++] = line[i];
				// Si es una coma, verificar el siguiente carácter
				if (line[i] == ',' && line[i + 1] != ' ' && line[i + 1] != '\t' && line[i + 1] != '\0')
					new_line[j++] = ' ';
				// Si es un espacio, saltar todas las tabulaciones consecutivas
				else if (line[i] == ' ')
				{
					while (line[i + 1] == '\t')
						i++;
				}
			}
			i++;
		}
		new_line[j] = '\0';  // Finalizar la nueva cadena con el terminador nulo
		free(lmap->content);   // Liberar la antigua cadena
		lmap->content = new_line;  // Asignar la nueva cadena
		lmap = lmap->next;
	}
}

static void	hub_elements(t_lmap *lmap)
{
	while (lmap)
	{
		if ((lmap->content[0] == 'N') || (lmap->content[0] == 'S') || \
		(lmap->content[0] == 'W') || (lmap->content[0] == 'E'))
		{
		if (exist_elements(lmap))
			ft_errors(3);
		if (exist_path_elements(lmap))
			ft_errors(3);		
		// if (exist_colors(lmap))
		// 	ft_errors(3);
		// if (exist_path_colors(lmap))
		// 	ft_errors(3);
		// remove_spaces_around_commas(lmap);
		}
		else if ((lmap->content[0] == 'F') || (lmap->content[0] == 'C'))
		{
		add_one_space_between_elements(lmap);
		if (exist_colors(lmap))//aki voy  - revisar 2da iteracion (lmap.content: C255,255,255)
			ft_errors(3);
		// remove_spaces_around_commas(lmap);
		if (exist_path_colors_op2(lmap))
			ft_errors(3);
		// if (exist_elements2(lmap))
		// 	ft_errors(3);
		// if (exist_path_elements(lmap))
		// 	ft_errors(3);		
		}
		lmap = lmap->next;
	}
	
}




void	parse_elems(t_elem *elem, t_lmap *lmap)
{
	(void)elem;
	remove_empty_lines(lmap);
	remove_external_tabs_spaces_elem(lmap);
	// remove_internal_tabs_spaces_elem(lmap);
	// add_one_space_between_elements(lmap);

	if(exist_elements_or_colors_anywhere(lmap))
		ft_errors(3);
	
	hub_elements(lmap);
	// if (duplicate_lines(lmap))
	// 	ft_errors(3);

	// save_path_chain_to_elem_struct(lmap, elem);
}

/*Menu parsing*/
void	parsing(t_elem *elem, t_colors *colors, t_map *map, t_lmap **lmap)
{
	// (void)lmap;
	(void)colors;
	file_is_cub(elem->av[1]);
	open_map(elem->av[1], map);
	create_list(map, lmap);
	parse_elems(elem, *lmap);

	// parsing_map(map, lmap);
	print_list(*lmap);
	ft_printf("\n");
	
	// print_elements(elem);
	// print_colors(colors);
	// print_width_height(map);
}
