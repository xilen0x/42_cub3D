/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:46:30 by castorga          #+#    #+#             */
/*   Updated: 2023/11/26 15:46:32 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"
#include "../include/window.h"

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac == 2)
	{
		file_is_ber(av[1], &game);
		open_map(av[1], &game);
		create_map(game.map_fd, &game, av[1]);
		parsing_map(&game);
		init_game(&game);
		set_images(&game);
		mlx_hook(game.mlx_win, X_EVENT_KEY_PRESS, 0, &press_key, &game);
		mlx_hook(game.mlx_win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_errors(1);
	return (0);
}
