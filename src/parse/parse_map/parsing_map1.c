/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:35:07 by castorga          #+#    #+#             */
/*   Updated: 2024/07/16 15:35:09 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	horizontal_check(t_lmap *lmap)
// {
// 	unsigned int	last;

// 	while (lmap)
// 	{
// 		while (*lmap->content == ' ')
// 			lmap->content++;
// 		// last = ft_strlen(lmap->content) - 2;
// 		last = ft_strlen(lmap->content) - 1;
// 		if (*lmap->content != '1' || lmap->content[last] != '1')
// 			return (1);
// 		lmap = lmap->next;
// 	}
// 	return (0);
// }

// int	parsing_not_square_map(t_lmap *lmap)
// {
// 	(void)lmap;
// 	return (0);
// }

// int	is_square_map(t_lmap *lmap)
// {
// 	unsigned int	next;
// 	unsigned int	current;

// 	while (lmap)
// 	{
// 		current = ft_strlen(lmap->content);
// 		if (lmap->next)
// 			next = ft_strlen(lmap->next->content);
// 		if (current != next)
// 			return (0);
// 		lmap = lmap->next;
// 	}
// 	return (1);
// }
// void	parsing_square_map(t_lmap *lmap)
// {
// 	(void)lmap;
// 	// if (is_surrounded_by_walls(game) != 0)
// 	// 	ft_errors(3);
// 	// if (is_initial_position(game) != 1)
// 	// 	ft_errors(3);
// 	// if (has_only_one_exit(game) != 1)
// 	// 	ft_errors(3);
// 	// if (valid_path_to_exit(game) == 0)
// 	// 	ft_errors(4);
// 	// if (valid_path_to_collectables(game) != 0)
// 	// 	ft_errors(4);
// 	// if (q_collectible(game) < 1)
// 	// 	ft_errors(3);
// }

int any_zero_or_space(t_map **map)
{
	char **tmp;

	tmp = (*map)->matrix;
    // while (tmp->matrix[tmp->y])
	while (tmp[tmp->y])
    {
        tmp->x = 0;
        while (tmp->matrix[tmp->y][tmp->x])
        {
            if ((tmp->matrix[tmp->y][tmp->x] == '0') && 
                ((tmp->matrix[tmp->y - 1][tmp->x] == ' ') || 
                 (tmp->matrix[tmp->y + 1][tmp->x] == ' ') || 
                 (tmp->matrix[tmp->y][tmp->x - 1] == ' ') || 
                 (tmp->matrix[tmp->y][tmp->x + 1] == ' ')))
            {
                return 1;
            }
            tmp->x++;
        }
        tmp->y++;
    }

    return 0;
}


void	valid_map(t_map *map)
{
	// if (is_square_map(lmap))
	// 	printf("Square map\n");
	// 	// parsing_square_map(lmap);
	// else
	// 	// parsing_not_square_map(lmap);
	// 	printf("Not square map\n");
	if (any_zero_or_space(&map) == 1)
	{
		ft_printf("Error\n");
		ft_errors(3);
	}
	else
	{
		ft_printf("Map is valid\n");
	}
}
