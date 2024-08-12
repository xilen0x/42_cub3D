/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_path_colors2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:16:54 by castorga          #+#    #+#             */
/*   Updated: 2024/08/12 19:16:56 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exist_path_colors_op2(t_lmap *lmap)
{
	int		count;
	char	**line;

	count = 0;
	while (lmap)
	{
		// temp = lmap->content;
		line = NULL;
		line = split_space_tab_comma(lmap->content);
		if (exist_path_colors2(line))
			ft_errors(3);
		free_elements(line);
		count++;
		lmap = lmap->next;
		if (count == 2)
			break ;
	}
	return (0);
}