/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:19:33 by castorga          #+#    #+#             */
/*   Updated: 2024/08/12 11:19:35 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	exist_cardinals(char **elements)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	while (elements[i] && temp < 4)
	{
		if (ft_strlen(elements[i]) == 2)
		{
			if (ft_strncmp(elements[i], "NO", 2) == 0)
				temp++;
			else if (ft_strncmp(elements[i], "SO", 2) == 0)
				temp++;
			else if (ft_strncmp(elements[i], "EA", 2) == 0)
				temp++;
			else if (ft_strncmp(elements[i], "WE", 2) == 0)
				temp++;
		}
		i++;
	}
	return (temp);
}

int	exist_elements(t_lmap *lmap)
{
	char	**elements;
	int		temp;

	elements = ft_split2(lmap->content);
	temp = exist_cardinals(elements);
	if (temp != 1)
		ft_errors("Invalid number of elements\n");
	free_elements(elements);
	return (0);
}

int	looking_for_xpm(char **elements)
{
	int		i;
	int		temp;

	temp = 0;
	i = 0;
	while (elements[i] && temp < 4)
	{
		if (ft_strlen(elements[i]) > 3)
		{
			if (ft_strnstr(elements[i], ".xpm", ft_strlen(elements[i])) != NULL)
				temp++;
		}
		i++;
	}
	if (temp == 1)
		return (0);
	return (1);
}

void	remove_newline_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}

int	path_is_valid(char **elements)
{
	int		i;
	int		temp;

	temp = 0;
	i = 0;
	while (elements[i] && temp < 4)
	{
		if (ft_strlen(elements[i]) > 3)
		{
			remove_newline_char(elements[i]);
			if (access(elements[i], R_OK) != 0)
				ft_errors("Invalid path 01\n");
			temp++;
		}
		i++;
	}
	if (temp == 1)
		return (0);
	return (1);
}

int	exist_path_elements(t_lmap *lmap)
{
	char	**elements;

	elements = ft_split2(lmap->content);
	if (looking_for_xpm(elements) == 1)
		ft_errors("Invalid path 02\n");
	if (path_is_valid(elements) == 1)
		ft_errors("Invalid path 03\n");	
	free_elements(elements);
	return (0);
}
