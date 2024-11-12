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

int	value_isdigit(char *num)
{
	int		i;

	i = 0;
	while (num[i] && num[i] != '\n')
	{
		if (num[i] >= '0' && num[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_range_values(int i, char **line, t_colors *colors, t_lmap *lmap)
{
	int		color_value;
	(void)colors;
	(void)lmap;
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
		// save_rgb_values(lmap, colors);
		i++;
	}
	return (0);
}

void	remove_leading_spaces(char *line, int *i, int *j)
{
	if ((line[*i] == ' ' || line[*i] == '\t') && line[*i + 1] == ',')
	{
		(*i)++;
		return ;
	}
	if (line[*i] == ',' && (line[*i + 1] == ' ' || line[*i + 1] == '\t'))
	{
		line[(*j)++] = line[(*i)++];
		while (line[*i] == ' ' || line[*i] == '\t')
			(*i)++;
		return ;
	}
	if ((line[*i] == ' ' || line[*i] == '\t') && (line[*j - 1] != ','))
	{
		(*i)++;
		return ;
	}
	line[(*j)++] = line[(*i)++];
}

void	process_line(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
		process_line(lmap->cont);
		count++;
		lmap = lmap->next;
		if (count == 2)
			break ;
	}
}
