#include "window.h"
#include "cub3d.h"

// /*Funcion que setea la imagen en la ventana*/
void	set_images_to_win(t_map *g)
{
	int		y;
	int		x;

	y = 0;
	while (y < g->h)
	{
		x = 0;
		while (x < g->w)
		{
			//set_images_to_win_bonus(g);
			if (g->matrix[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.wall, x * 32, y * 32);
			else if (g->matrix[y][x] == '0')
				mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.floor, x * 32, y * 32);
			else if (g->matrix[y][x] == 'N' || g->matrix[y][x] == 'S' || g->matrix[y][x] == 'E' || g->matrix[y][x] == 'W')
				mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.player, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

// /*Funcion que asocia las imgs en la estructura*/
void	set_images(t_map *map)
{
	map->imgs.wall = mlx_xpm_file_to_image(map->mlx, "./textures/blue.xpm", &map->imgs.w, &map->imgs.h);
	map->imgs.floor = mlx_xpm_file_to_image(map->mlx, "./textures/yellow.xpm", &map->imgs.w, &map->imgs.h);
	map->imgs.player = mlx_xpm_file_to_image(map->mlx, "./textures/red.xpm", &map->imgs.w, &map->imgs.h);
	set_images_to_win(map);
}

// void	set_player(t_game *g, int y, int x, char dir)
// {
// 	if (dir == 'w')
// 		mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.player.player_up, y * 32, x * 32);
// 	if (dir == 'a')
// 		mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.player.player_left, y * 32, x * 32);
// 	if (dir == 's')
// 		mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.player.player_down, y * 32, x * 32);
// 	if (dir == 'd')
// 		mlx_put_image_to_window(g->mlx, g->mlx_win, g->imgs.player.player_right, y * 32, x * 32);
// }


void	move_up(t_map *map)
{
	(void)map;
	ft_printf("Move up\n");
}

void	move_down(t_map *map)
{
	(void)map;
	ft_printf("Move down\n");
}

void	move_left(t_map *map)
{
	(void)map;
	ft_printf("Move left\n");
}

void	move_right(t_map *map)
{
	(void)map;
	ft_printf("Move right\n");
}

int	press_key(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		exit_game(map);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(map);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(map);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(map);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(map);
	return (0);
}
