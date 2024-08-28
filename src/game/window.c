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


void	move_up(t_map *map, char op)
{
	int	y;
	int	x;

	y = map->y;
	x = map->x;
	if (map->matrix[y - 1][x] >= 0 && map->matrix[y - 1][x] != '1')
	{
		if (map->matrix[y - 1][x] != '1')
		{
			map->matrix[y][x] = '0';
			map->y--;
			y = map->y;
			if (op == 'N')
				map->matrix[y][x] = 'N';
			else if (op == 'S')
				map->matrix[y][x] = 'S';
			else if (op == 'E')
				map->matrix[y][x] = 'E';
			else if (op == 'W')
				map->matrix[y][x] = 'W';
			set_images_to_win(map);
		}
	}
}

void	move_down(t_map *map, char op)
{
	int	y;
	int	x;

	y = map->y;
	x = map->x;
	if (map->matrix[y + 1][x] >= 0 && map->matrix[y + 1][x] != '1')
	{
		if (map->matrix[y + 1][x] != '1')
		{
			map->matrix[y][x] = '0';
			map->y++;
			y = map->y;
			if (op == 'N')
				map->matrix[y][x] = 'N';
			else if (op == 'S')
				map->matrix[y][x] = 'S';
			else if (op == 'E')
				map->matrix[y][x] = 'E';
			else if (op == 'W')
				map->matrix[y][x] = 'W';
			set_images_to_win(map);
		}
	}
}

void	move_left(t_map *map, char op)
{
	int	y;
	int	x;

	y = map->y;
	x = map->x;
	if (map->matrix[y][x - 1] >= 0 && map->matrix[y][x - 1] != '1')
	{
		if (map->matrix[y][x - 1] != '1')
		{
			map->matrix[y][x] = '0';
			map->x--;
			x = map->x;
			if (op == 'N')
				map->matrix[y][x] = 'N';
			else if (op == 'S')
				map->matrix[y][x] = 'S';
			else if (op == 'E')
				map->matrix[y][x] = 'E';
			else if (op == 'W')
				map->matrix[y][x] = 'W';
			set_images_to_win(map);
		}
	}
}

void	move_right(t_map *map, char op)
{
	int	y;
	int	x;

	y = map->y;
	x = map->x;
	if (map->matrix[y][x + 1] >= 0 && map->matrix[y][x + 1] != '1')
	{
		if (map->matrix[y][x + 1] != '1')
		{
			map->matrix[y][x] = '0';
			map->x++;
			x = map->x;
			if (op == 'N')
				map->matrix[y][x] = 'N';
			else if (op == 'S')
				map->matrix[y][x] = 'S';
			else if (op == 'E')
				map->matrix[y][x] = 'E';
			else if (op == 'W')
				map->matrix[y][x] = 'W';
			set_images_to_win(map);
		}
	}
}

int	press_key(int keycode, t_map *map)
{
	char	op;

	op = map->matrix[map->y][map->x];
	if (keycode == KEY_ESC)
		exit_game(map);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(map, op);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(map, op);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(map, op);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(map, op);
	return (0);
}
