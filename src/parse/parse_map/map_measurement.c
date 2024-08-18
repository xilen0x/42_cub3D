/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:44:21 by castorga          #+#    #+#             */
/*   Updated: 2024/07/09 15:44:23 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*busqueda de linea mas larga en el mapa(list)*/
size_t	search_longest_line(t_lmap *lmap)
{
	size_t	longest_line;
	size_t	len;

	longest_line = 0;
	while (lmap)
	{
		len = ft_strlen(lmap->cont);
		if (len > 0 && lmap->cont[len - 1] == '\n')
			len--;
		if (longest_line < len)
			longest_line = len;
		lmap = lmap->next;
	}
	return (longest_line + 1);
}
