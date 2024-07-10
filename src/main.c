
#include "cub3d.h"

int	main(int ac, char *av[])
{
	t_map	map;

	if (ac == 2)
	{
		init_values(&map);
		open_map(av[1], &map);
		parsing(&map, av);
		// init_game(&game);
		// //set_images(&game);
		// mlx_hook(game.mlx_win, X_EVENT_KEY_PRESS, 0, &press_key, &game);
		// mlx_hook(game.mlx_win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
		// mlx_loop(game.mlx);
	}
	else
		ft_errors(1);
	return (0);
}
