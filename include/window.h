

#ifndef WINDOW_H
# define WINDOW_H

# include <unistd.h>
#include "mlx.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define TILE_PXL 				32

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

#endif
