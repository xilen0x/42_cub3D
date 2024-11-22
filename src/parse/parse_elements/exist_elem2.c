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

int	check_cardinal_direction(char **elements)
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

int	check_cardinal_in_line(t_lmap *lmap)
{
	char	**elements;
	int		temp;

	elements = ft_split2(lmap->cont);
	temp = check_cardinal_direction(elements);
	free_elements(elements);
	return (temp);
}

int	exist_elements2(t_lmap *lmap)
{
	int		temp;
	int		count;

	count = 0;
	while (lmap)
	{
		if ((ft_strnstr(lmap->cont, "NO", ft_strlen(lmap->cont)) != NULL) || \
			(ft_strnstr(lmap->cont, "SO", ft_strlen(lmap->cont)) != NULL) || \
			(ft_strnstr(lmap->cont, "EA", ft_strlen(lmap->cont)) != NULL) || \
			(ft_strnstr(lmap->cont, "WE", ft_strlen(lmap->cont)) != NULL))
		{
			temp = check_cardinal_in_line(lmap);
			count += temp;
			if (temp != 1)
				ft_errors("Invalid number of elements\n");
			if (count == 4)
				return (0);
		}
		lmap = lmap->next;
	}
	return (0);
}

int	exist_elements_or_colors_anywhere(t_lmap *lmap)
{
	int		count;

	count = 0;
	while (lmap)
	{
		if (ft_strnstr(lmap->cont, "NO", ft_strlen(lmap->cont)))
			count++;
		else if (ft_strnstr(lmap->cont, "SO", ft_strlen(lmap->cont)))
			count++;
		else if (ft_strnstr(lmap->cont, "EA", ft_strlen(lmap->cont)))
			count++;
		else if (ft_strnstr(lmap->cont, "WE", ft_strlen(lmap->cont)))
			count++;
		else if (ft_strnstr(lmap->cont, "F", ft_strlen(lmap->cont)))
			count++;
		else if (ft_strnstr(lmap->cont, "C", ft_strlen(lmap->cont)))
			count++;
		lmap = lmap->next;
	}
	if (count != 6)
		ft_errors("Invalid number of elements or colors\n");
	return (0);
}
