
#include "cub3d.h"

/*Funcion que inicializa valores*/
// void	set_values(t_game *g)
// {
// 	g->collected = 0;
// 	g->walk_cnt = 0;
// 	g->h = 0;
// 	g->w = 0;
// }

/*Funcion que verifica la extension .cub*/
int	file_is_cub(char *av, t_game *game)
{
	int	len;

	(void)game;
	len = ft_strlen(av);
	if (ft_strncmp(&av[len - 4], ".cub", 4) == 0)
	{
		// set_values(game);
		printf("todo ok!\n");
		return (0);
	}
	else
	{
		write (2, "Error\n", 6);
		write (2, "The file does not have a .cub extension.\n", 41);
		exit(1);
	}
}

// int	parsing_map(t_game *game)
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

