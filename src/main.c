
#include "cub3d.h"
#include "window.h"

int	main(int ac, char *av[])
{
	t_map	map;
	//t_game	game;

	if (ac == 2)
	{
		init_values(&map);
		parsing(&map, av);
		//init_game(&game);
		// set_images(&game);
		// mlx_hook(game.mlx_win, X_EVENT_KEY_PRESS, 0, &press_key, &game);
		// mlx_hook(game.mlx_win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
		// mlx_loop(game.mlx);
		free_matrix(map.matrix);
		//free_xx_path(&map);
	}
	else
		ft_errors(1);
	return (0);
}
