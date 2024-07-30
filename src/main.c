/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:31:15 by castorga          #+#    #+#             */
/*   Updated: 2024/07/17 11:31:18 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "window.h"

int	main(int ac, char *av[])
{
	t_elem		elem;
	t_colors	colors;
	t_map		map;
	t_lmap		*lmap;

	lmap = NULL;
	if (ac == 2)
	{
		init_values(&elem, &colors, &map);
		parsing(&elem, &colors, &map, av, &lmap);
		//init_game(&game);
		// set_images(&game);
		// mlx_hook(game.mlx_win, X_EVENT_KEY_PRESS, 0, &press_key, &game);
		// mlx_hook(game.mlx_win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
		// mlx_loop(game.mlx);
	}
	else
		ft_errors(1);
	free_matrix(map.matrix);
	lst_clear(&lmap, &free);
	free_element_struct(&elem);
	// exit(0);
	return (0);
}
 