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

// /*Funcion que verifica la extension .xpm del texture path*/
// void	texture_path_extension_is_valid(char *elements)
// {
// 	int	i;

// 	i = 0;
// 	while (elements[i])
// 		i++;
// 	if (elements[i - 1] != 'm' || elements[i - 2] != 'p' 
// 	|| elements[i - 3] != 'x' || elements[i - 4] != '.')
// 	{
// 		write (2, "Error\n", 6);
// 		write (2, "The texture path is not valid.\n", 31);
// 		exit(1);
// 	}
// }


/* Funcion que verifica la extension .xpm del texture path */
// void	texture_path_extension_is_valid(t_lmap *lmap)
// {
// 	char	*line;
// 	int		len;
// 	int		temp;

// 	temp = 0;
// 	while (lmap)
// 	{
// 		line = lmap->content;
//         len = ft_strlen(line);
// 		if (line[0] == '\n')
//         {
//             lmap = lmap->next;
//             continue;
//         }
// 		if ((ft_strncmp(lmap->content, "SO", 2) == 0) || (ft_strncmp(lmap->content, "NO", 2) == 0) ||
// 			(ft_strncmp(lmap->content, "WE", 2) == 0) || (ft_strncmp(lmap->content, "EA", 2) == 0))
// 			temp++;
//         if (len < 4 || line[len - 1] != 'm' || line[len - 2] != 'p' ||
//             line[len - 3] != 'x' || line[len - 4] != '.')
// 			ft_errors2(7);
//         lmap = lmap->next;
// 		if (temp == 4)
// 			break ;
//     }
// }

void	texture_path_extension_is_valid(t_elem *elem)
{
	// while (lmap)
	// {
	// 	line = lmap->content;
    //     len = ft_strlen(line);
	// 	if (line[0] == '\n')
    //     {
    //         lmap = lmap->next;
    //         continue;
    //     }
	if ((ft_strncmp(elem->so_path, ".xpm", 4) != 0) || (ft_strncmp(elem->no_path, ".xpm", 4) != 0) ||
		(ft_strncmp(elem->we_path, ".xpm", 4) != 0) || (ft_strncmp(elem->ea_path, ".xpm", 4) != 0))
	// 		temp++;
    // if (len < 4 || line[len - 1] != 'm' || line[len - 2] != 'p' ||
    //         line[len - 3] != 'x' || line[len - 4] != '.')
			ft_errors2(7);
        // lmap = lmap->next;
		// if (temp == 4)
		// 	break ;
}
