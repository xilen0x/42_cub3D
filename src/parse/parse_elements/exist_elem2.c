/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_elem2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:42:19 by castorga          #+#    #+#             */
/*   Updated: 2024/08/12 19:42:21 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exist_cardinals2(char **elements)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	while (elements[i] && temp < 4)
	{
		if (ft_strncmp(elements[i], "NO", 2) == 0)
			temp++;
		else if (ft_strncmp(elements[i], "SO", 2) == 0)
			temp++;
		else if (ft_strncmp(elements[i], "EA", 2) == 0)
			temp++;
		else if (ft_strncmp(elements[i], "WE", 2) == 0)
			temp++;
		i++;
	}
	return (temp);
}

int	exist_elements2(t_lmap *lmap)
{
	char	**elements;
	int		temp;
	int		count;

	count = 0;
	while (lmap)
	{
		if ((ft_strnstr(lmap->content, "NO", ft_strlen(lmap->content)) != NULL) || (ft_strnstr(lmap->content, "SO", ft_strlen(lmap->content)) != NULL) || (ft_strnstr(lmap->content, "EA", ft_strlen(lmap->content)) != NULL) || (ft_strnstr(lmap->content, "WE", ft_strlen(lmap->content)) != NULL))
		{
			elements = ft_split2(lmap->content);
			temp = exist_cardinals2(elements);
			count = count + temp;
			if (temp != 1)
				ft_errors(3);
			if (count == 4)
			{
				free_elements(elements);
				return (0);
			}
		}
		// free_elements(elements);
		lmap = lmap->next;
	}
	return (0);
}
