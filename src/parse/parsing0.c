
#include "cub3d.h"

int	parsing_elements(t_game *game)
{
	//Elements exist(in any order)
	if (elements_exist(game) != 0)
		ft_errors(3);

	//cant. de elementos o formato debe ser == (XX ./XXXXXXXXXX.xpm)
	/*
		NO ./textures/blue.xpm
		WE ./textures/green.xpm
		SO ./textures/red.xpm
		EA ./textures/yellow.xpm
	*/
	if (expected_syntax_textures(game) != 0)
		ft_errors(3);

	//F: cant. de elementos o formato debe ser == (X XXX,XXX,XXX)
	//F 220,100,0
	if (expected_syntax_colors(game) != 0)
		ft_errors(3);
	
	//Information from elements separated by 1 or + spaces
	if (spaces_handler(game) != 0)
		ft_errors(3);
	
	//Elements separated by 1 or + empty lines
	if (empty_lines_handler(game) != 0)
		ft_errors(3);

	return (0);
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

