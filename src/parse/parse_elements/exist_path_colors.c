/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_path_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:18:56 by castorga          #+#    #+#             */
/*   Updated: 2024/08/12 11:18:58 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	ft_strcmp(char c1, char c2)
{
	if (c1 > c2)
		return (1);
	else if (c1 == c2)
		return (0);
	else
		return (-1);
}

int	value_isdigit(char *num)
{
	int		i;

	i = 0;
	while (num[i])
	{
		if (num[i] >= '0' && num[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_range_values(int i, char **line, t_colors *colors, t_lmap *lmap)
{
	int		color_value;

	i = 0;
	while (line[i])
	{
		if (i == 3)
			break ;		
		if (value_isdigit(line[i]))
			color_value = ft_atoi(line[i]);
		else
			return (1);
		if (color_value < MIN_COLOR_VALUE || color_value > MAX_COLOR_VALUE)
			return (1);
		save_rgb_values(lmap, colors);
		i++;
	}
	return (0);
}
void	remove_leading_spaces(char *line, int *i, int *j)
{
    // Eliminar espacios o tabulaciones antes de la coma
	if ((line[*i] == ' ' || line[*i] == '\t') && line[*i + 1] == ',')
	{
		(*i)++; // Saltar el espacio/tabulación
		return ;
	}
    // Eliminar espacios o tabulaciones después de la coma
	if (line[*i] == ',' && (line[*i + 1] == ' ' || line[*i + 1] == '\t'))
	{
		line[(*j)++] = line[(*i)++]; // Copiar la coma
		while (line[*i] == ' ' || line[*i] == '\t')
			(*i)++; // Saltar los espacios/tabulaciones
		return ;
	}
	// Eliminar espacios o tabulaciones antes de la coma
	if ((line[*i] == ' ' || line[*i] == '\t') && (line[*j - 1] != ','))
	{
		(*i)++; // Saltar el espacio/tabulación
		return ;
	}
	// Copiar el carácter normalmente
	line[(*j)++] = line[(*i)++];
}
void	process_line(char *line)
{
	int i = 0, j = 0;

	while (line[i])
		remove_leading_spaces(line, &i, &j);
	while ((j > 0) && (line[j - 1] == ' ' || line[j - 1] == '\t'))
		j--;
	line[j] = '\0';
}
void	remove_spaces_around_commas(t_lmap *lmap)
{
	int		count;

	count = 0;
	while (lmap)
	{
		process_line(lmap->content);
		count++;
		lmap = lmap->next;
		if (count == 2)
			break ;		
	}
}


int	exist_path_colors2(char **line, t_colors *colors, t_lmap *lmap)
{
	int		i;

	i = 0;
	while (line[i])
		i++;
	if (i == 3)
	{
		if (check_range_values(i, line, colors, lmap) == 1)
		{
			free_elements(line);
			ft_errors(3);
		}
	}
	else
	{
		free_elements(line);
		return (1);
	}
	return (0);
}


int	exist_path_colors(t_lmap *lmap, t_colors *colors)
{
	// char	*temp;
	char	**line;

	while (lmap)
	{
		// temp = lmap->content;
		line = NULL;
		line = split_space_tab_comma(lmap->content);
		if (ft_strncmp(line[0], "F", 1) == 0 || \
			ft_strncmp(line[0], "C", 1) == 0)
			if (exist_path_colors2(line, colors, lmap))
				ft_errors(3);
		free_elements(line);
		lmap = lmap->next;
	}
	return (0);
}
