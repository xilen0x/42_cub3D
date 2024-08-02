/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:44:09 by castorga          #+#    #+#             */
/*   Updated: 2024/07/09 15:44:12 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Funcion que verifica la extension .cub*/
int	file_is_cub(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (ft_strncmp(&av[len - 4], ".cub", 4) == 0)
		return (0);
	else
	{
		write (2, "Error\n", 6);
		write (2, "The file does not have a .cub extension.\n", 41);
		exit(1);
	}
	return (0);
}

/*Funcion que verifica la extension .xpm del texture path*/
void	texture_path_extension_is_valid(char *elements)
{
	int	i;

	i = 0;
	while (elements[i])
		i++;
	if (elements[i - 1] != 'm' || elements[i - 2] != 'p' \
	|| elements[i - 3] != 'x' || elements[i - 4] != '.')
	{
		write (2, "Error\n", 6);
		write (2, "The texture path is not valid.\n", 31);
		exit(1);
	}
}
