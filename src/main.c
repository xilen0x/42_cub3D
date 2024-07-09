
#include "cub3d.h"

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac == 2)
	{
		file_is_cub(av[1]);
		open_map(av[1], &game);
		parsing(&game);
		//search_longest_line(game.map_fd, &game, av[1]);
		//create_map(game.map_fd, &game, av[1]);
		// //parsing_map(&game);
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
