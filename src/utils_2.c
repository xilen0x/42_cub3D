#include "cub3d.h"

int	exit_game(t_game *g)
{
	write (1, "####################\n", 21);
	write (1, "     End Game!\n", 15);
	write (1, "####################\n", 21);
	mlx_destroy_window(g->mlx, g->mlx_win);
	free(g->mlx);
	exit(0);
}

int	press_key(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	printf("test\n");
	// if (keycode == KEY_ESC)
	// 	exit_game(game);
	// else if (keycode == KEY_W || keycode == KEY_UP)
	// 	move_up(game);
	// else if (keycode == KEY_A || keycode == KEY_LEFT)
	// 	move_left(game);
	// else if (keycode == KEY_S || keycode == KEY_DOWN)
	// 	move_down(game);
	// else if (keycode == KEY_D || keycode == KEY_RIGHT)
	// 	move_right(game);
	return (0);
}
