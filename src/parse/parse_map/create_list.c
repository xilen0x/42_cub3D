/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:01:18 by castorga          #+#    #+#             */
/*   Updated: 2024/07/24 17:01:20 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_list(t_map_parse *map, t_lmap **lmap)
{
	char	*line;
	t_lmap	*node;

	line = get_next_line(map->map_fd);
	while (line)
	{
		node = p_malloc(sizeof(t_lmap));
		node->cont = line;
		node->next = NULL;
		ft_add_back(lmap, node);
		line = get_next_line(map->map_fd);
	}
	close(map->map_fd);
}

void	jump_elements(t_lmap **lm)
{
	while (*lm && (
			(ft_strnstr2((*lm)->cont, "NO", ft_strlen((*lm)->cont)) != NULL) || \
			(ft_strnstr2((*lm)->cont, "SO", ft_strlen((*lm)->cont)) != NULL) || \
			(ft_strnstr2((*lm)->cont, "WE", ft_strlen((*lm)->cont)) != NULL) || \
			(ft_strnstr2((*lm)->cont, "EA", ft_strlen((*lm)->cont)) != NULL) || \
			(ft_strnstr2((*lm)->cont, "F", ft_strlen((*lm)->cont)) != NULL) || \
			(ft_strnstr2((*lm)->cont, "C", ft_strlen((*lm)->cont)) != NULL) || \
			((*lm)->cont[0] == '\0')))
		*lm = (*lm)->next;
}

/*f que analiza si el mapa es de forma cuadrada o irregular*/
int	is_square_map(t_lmap *lm)
{
	int		len;
	int		len2;

	len = 0;
	len2 = 0;
	jump_elements(&lm);
	while (lm)
	{
		len = ft_strlen(lm->cont);
		if (len2 == 0)
			len2 = len;
		if (len != len2)
			break ;
		lm = lm->next;
	}
	if (len == len2)
		return (1);
	return (0);
}

int	check_map_nl(t_lmap **lmap)
{
	t_lmap	*lm;

	lm = *lmap;
	while (lm && (
			(ft_strnstr2((lm)->cont, "NO", ft_strlen((lm)->cont)) != NULL) || \
			(ft_strnstr2((lm)->cont, "SO", ft_strlen((lm)->cont)) != NULL) || \
			(ft_strnstr2((lm)->cont, "WE", ft_strlen((lm)->cont)) != NULL) || \
			(ft_strnstr2((lm)->cont, "EA", ft_strlen((lm)->cont)) != NULL) || \
			(ft_strnstr2((lm)->cont, "F", ft_strlen((lm)->cont)) != NULL) || \
			(ft_strnstr2((lm)->cont, "C", ft_strlen((lm)->cont)) != NULL) || \
			((lm)->cont[0] == '\n')))
		lm = (lm)->next;
	while (lm)
	{
		if ((lm)->cont[0] == '\n')
			ft_errors("New line inside the map!");
		lm = (lm)->next;
	}
	return (0);
}
