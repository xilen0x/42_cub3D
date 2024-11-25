#include "cub3d.h"

/*white direction in minimap*/
void	direction_to_image(t_game *g, int color)
{
	int		x;
	int		y;
	int		hyp;
	float	px;
	float	py;

	hyp = 1;
	px = g->player.px / 2;
	py = g->player.py / 2;
	while (hyp <= 15)
	{
		x = (int)(px + (cosf(g->player.pa) * hyp));
		y = (int)(py + (sinf(g->player.pa) * hyp));
		set_pixel_to_image(&g->img2, x, y, color);
		hyp++;
	}
}

void	ray_to_image(t_game *g, int color)
{
	int		x;
	int		y;
	int		hyp;
	float	px;
	float	py;

	hyp = 1;
	x = 0;
	y = 0;
	px = g->player.px / 2;
	py = g->player.py / 2;
	while (hyp <= g->ray.len / 2)
	{
		x = (int)(px + (cosf(g->ray.ra) * hyp));
		y = (int)(py + (sinf(g->ray.ra) * hyp));
		set_pixel_to_image(&g->img2, x, y, color);
		hyp++;
	}
}
