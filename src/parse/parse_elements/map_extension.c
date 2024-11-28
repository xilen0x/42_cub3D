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

/*Funcion que verifica la extension .cub del fichero*/
int	file_is_cub(char *av)
{
	int		len;
	char	**tmp;

	tmp = ft_split(av, '/');
	len = ft_strlen(tmp[1]);
	if (len < 5)
	{
		ft_errors("The file does not have a name!\n");
		free_elements(tmp);
		return (1);
	}
	len = ft_strlen(av);
	if (ft_strncmp(&av[len - 4], ".cub", 4) == 0)
	{
		free_elements(tmp);
		return (0);
	}
	else
		ft_errors("The file is not a .cub file\n");
	free_elements(tmp);
	return (0);
}

/*Funcion que verifica la extension .xpm del texture path*/
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
