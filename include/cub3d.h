
#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "window.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_point
{
	// int			x;
	// int			y;
}	t_point;

typedef struct s_player
{
	// void	*player_n;
	// void	*player_s;
	// void	*player_e;
	// void	*player_w;
}	t_player;

typedef struct s_img
{
	// void		*wall;
	// void		*floor;
	// void		*ceiling;
	// void		*exit;
	// void		*open_door;
	// void		*closed_door;
	// int			w;
	// int			h;
	t_player	player;
}	t_img;

typedef struct s_game
{
	// void	*mlx;
	// void	*mlx_win;
	// char	**matrix;
	// int		w;
	// int		h;
	// t_img	imgs;
	t_point	position;
	t_point exit;
}	t_game;

typedef struct s_map
{
	int		map_fd;//almacena el fd del mapa original
	size_t	longest_line;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
}	t_map;

int		file_is_cub(char *av);
int		open_map(char *av, t_map *map);
int		ft_errors(int n);
void	search_longest_line(int fd, t_map *map);
void	parsing(t_map *map);
int		elements_exist(t_map *map);
void	init_values(t_map *map);
// void	create_map(int fd, t_game *game, char *av);
// void	print_matrix(t_game *game);
// void	set_values(t_game *g);
// int		parsing_map(t_game *game);
// int		is_rectangular(t_game *game);
// int		is_initial_position(t_game *game);
// int		is_surrounded_by_walls(t_game *game);
// int		has_only_one_exit(t_game *game);
// int		valid_path_to_exit(t_game *game);
// int		valid_path_to_collectables(t_game *game);
// int		q_collectible(t_game *game);
// t_point	find_p(t_game *copy_map, t_game *game);
// void	set_images(t_game *game);
// void	set_images_to_win(t_game *game, char dir);
// void	init_game(t_game *game);
// void	set_player(t_game *g, int y, int x, char dir);
// int		press_key(int keycode, t_game *game);
// void	move_up(t_game *g);
// void	move_right(t_game *g);
// void	move_left(t_game *g);
// void	move_down(t_game *g);
// int		exit_game(t_game *g);
// void	free_map(t_game *game);
#endif
