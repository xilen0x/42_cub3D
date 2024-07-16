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

/*
Descr.: verifica si el mapa es rectangular*/
// int	is_rectangular(t_game *game)
// {
// 	int		i;
// 	int		curr_row_len;
// 	int		first_row_len;

// 	i = 0;
// 	if (game->w <= 4 || game->w > 34)
// 		ft_errors(3);
// 	first_row_len = ft_strlen(game->matrix[i]);
// 	while (i < game->h)
// 	{
// 		curr_row_len = ft_strlen(game->matrix[i]);
// 		if (first_row_len != curr_row_len)
// 			ft_errors(3);
// 		i++;
// 	}
// 	return (0);
// }

// static int	parsing_map(t_game *game)
// {
// 	if (is_rectangular(game) != 0)
// 		ft_errors(3);
// 	if (is_surrounded_by_walls(game) != 0)
// 		ft_errors(3);
// 	if (is_initial_position(game) != 1)
// 		ft_errors(3);
// 	if (has_only_one_exit(game) != 1)
// 		ft_errors(3);
// 	if (valid_path_to_exit(game) == 0)
// 		ft_errors(4);
// 	if (valid_path_to_collectables(game) != 0)
// 		ft_errors(4);
// 	if (q_collectible(game) < 1)
// 		ft_errors(3);
// 	return (0);
// }
