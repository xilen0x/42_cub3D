/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces_tabs3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:52:34 by castorga          #+#    #+#             */
/*   Updated: 2024/08/19 11:52:36 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	remove_extra_spaces_or_tabs(t_lmap *lm)
{
	char	*line;

	while (lm && (
			(ft_strnstr2(lm->cont, "NO", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "SO", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "WE", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "EA", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "F", ft_strlen(lm->cont)) != NULL) || \
			(ft_strnstr2(lm->cont, "C", ft_strlen(lm->cont)) != NULL)))
	{
		line = ft_strtrim2(lm->cont, " ", "\t");
		free(lm->cont);
		lm->cont = line;
		lm = lm->next;
	}
}

/*remueve los espacios y tabulaciones al final de la linea*/
void	remove_final_spaces_tabs(char *str)
{
	int	i;

	i = ft_strlen(str) - 2;
	while (str[i] == ' ' || str[i] == '\t')
	{
		str[i] = '\0';
		i--;
	}
}
