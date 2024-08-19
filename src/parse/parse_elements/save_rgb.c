/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:33:54 by castorga          #+#    #+#             */
/*   Updated: 2024/08/19 10:33:56 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_rgb_values3(t_lmap *temp, t_colors *colors, int i, int count)
{
	int		j;

	j = 0;
	if (temp->cont[0] == 'F')
	{
		colors->f = 1;
		if (count == 0)
			colors->f_color[j++] = ft_atoi(&temp->cont[i]);
		else if (count == 1)
			colors->f_color[j++] = ft_atoi(&temp->cont[i]);
		else if (count == 2)
			colors->f_color[j++] = ft_atoi(&temp->cont[i]);
	}
	else if (temp->cont[0] == 'C')
	{
		colors->c = 2;
		if (count == 0)
			colors->c_color[j++] = ft_atoi(&temp->cont[i]);
		else if (count == 1)
			colors->c_color[j++] = ft_atoi(&temp->cont[i]);
		else if (count == 2)
			colors->c_color[j++] = ft_atoi(&temp->cont[i]);
	}
	while (temp->cont[i] >= '0' && temp->cont[i] <= '9')
		i++;
}

void	save_rgb_values2(t_lmap *temp, t_colors *colors)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (temp->cont[i])
	{
		if (temp->cont[i] == ' ' || temp->cont[i] == '\t')
			i++;
		if (temp->cont[i] >= '0' && temp->cont[i] <= '9')
		{
			save_rgb_values3(temp, colors, i, count);
			count++;
		}
		if (count == 3)
			return ;
		i++;
	}
}

void	save_rgb_values(t_lmap *lmap, t_colors *colors)
{
	t_lmap	*temp;

	temp = lmap;
	while (temp)
	{
		if (temp->cont[0] == 'F' || temp->cont[0] == 'C')
		{
			save_rgb_values2(temp, colors);
		}
		temp = temp->next;
	}
}
