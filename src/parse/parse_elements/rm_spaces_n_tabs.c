/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_spaces_n_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:33:27 by castorga          #+#    #+#             */
/*   Updated: 2024/07/16 15:33:29 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	remove_tabs_and_spaces(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ' ' && (j == 0 || line[i + 1] == ' '))
		{
			i++;
			continue ;
		}
		if (line[i] == '\t')
		{
			line[j++] = ' ';
			i++;
			while (line[i] == '\t')
				i++;
		}
		else
			line[j++] = line[i++];
	}
	while ((j > 0) && ((line[j - 1] == ' ') || (line[j - 1] == '\t')))
		j--;
	line[j] = '\0';
}

// void remove_tabs_and_spaces(char **lines)
// {
//     int i, j, k;

//     i = 0;
//     while (lines[i])
//     {
//         j = 0;
//         k = 0;
//         while (lines[i][j])
//         {
//             if (lines[i][j] != '\t' && lines[i][j] != ' ')
//             {
//                 lines[i][k] = lines[i][j];
//                 k++;
//             }
//             j++;
//         }
//         while (k > 0 && (lines[i][k - 1] == ' ' || lines[i][k - 1] == '\t'))
//             k--;
//         lines[i][k] = '\0';
//         i++;
//     }
// }

void	remove_tabs(char **line)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (line[i])
	{
		j = 0;
		k = 0;
		while (line[i][j])
		{
			if ((line[i][j] != '\t'))
			{
				line[i][k] = line[i][j];
				k++;
			}
			j++;
		}
		line[i][k] = '\0';
		i++;
	}
}

//elimina espacios antes y después de las comas
void	remove_spaces_around_commas(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ' ' && (j == 0 || line[i + 1] == ' ' \
		|| line[i + 1] == ',' || line[j - 1] == ','))
		{
			i++;
			continue ;
		}
		if (line[i] == ' ' && line[i + 1] == ',')
		{
			i++;
			continue ;
		}
		if (line[i] == ',' && line[i + 1] == ' ')
		{
			line[j++] = line[i++];
			while (line[i] == ' ')
				i++;
		}
		else
			line[j++] = line[i++];
	}
	while ((j > 0) && ((line[j - 2] == ' ') || (line[j - 2] == '\t')))
		j--;
	line[j] = '\0';
}
