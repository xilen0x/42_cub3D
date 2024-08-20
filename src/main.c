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

// void	init_game(t_game *game)
// {
// 	game->mlx = mlx_init();
// 	game->mlx_win = mlx_new_window(game->mlx, 1200, 600, "cub3D");
// }

// int	press_key(int keycode, t_game *game)
// {
// 	(void)game;
// 	(void)keycode;
// 	return (0);
// }
// int	exit_game(t_game *game)
// {
// 	mlx_destroy_window(game->mlx, game->mlx_win);
// 	exit(0);
// 	return (0);
// }

int	main(int ac, char *av[])
{
	t_elem		elem;
	t_colors	colors;
	t_map		map;
	t_lmap		*lmap;
	//t_game		game;

	lmap = NULL;
	if (ac == 2)
	{
		elem.av = av;
		init_values(&elem, &colors, &map, av);
		parsing(&elem, &colors, &map, &lmap);
		// init_game(&game);
		// //set_images(&game);
		// mlx_hook(game.mlx_win, X_EVENT_KEY_PRESS, 0, &press_key, &game);
		// mlx_hook(game.mlx_win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
		// mlx_loop(game.mlx);
	}
	else
		ft_errors("Invalid number of arguments\n");
	lst_clear(&lmap, &free);
	free_element_struct(&elem);
	free_matrix(map.matrix, map.h);
	return (0);
}
