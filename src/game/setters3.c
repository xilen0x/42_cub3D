#include "cub3d.h"

float	squared_vlen(t_game *g)
{
	float	dx;
	float	dy;

	dx = g->player.px - g->ray.vx;
	dy = g->player.py - g->ray.vy;
	return (dx * dx + dy * dy);
}

void	calculate_ray_hlen(t_game *g)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if ((g->ray.hx < TL) || (g->ray.hx > (g->map.mapW - 1) * TL))
		{
			g->ray.hlen = 0;
			return ;
		}
		g->map.x = ((int)(g->ray.hx)) >> 6;
		if (g->ray.ra > PI && g->ray.ra < 2 * PI)
			g->map.y = ((int)(g->ray.hy - 1)) >> 6;
		else if (g->ray.ra < PI && g->ray.ra > 0)
			g->map.y = ((int)(g->ray.hy)) >> 6;
		g->map.pos = g->map.y * g->map.mapW + g->map.x;
		if (g->map.pos >= 0 && g->map.pos < g->map.mapW * g->map.mapH && g->map.map[g->map.pos] == '1')
				hit = 1;
		else
		{
			g->ray.hx += g->ray.x_step;
			g->ray.hy += g->ray.y_step;
		}
	}
	set_hcolor(g);
	g->ray.hlen = squared_hlen(g);
}

void	check_horizon_lines(t_game *g)
{
	float	tan_ra;

	tan_ra = tanf(g->ray.ra);
	if (g->ray.ra > PI && g->ray.ra < (2 * PI))
	{
		g->ray.hy = ((int)(g->player.py) >> 6) << 6;
		g->ray.hx = (g->player.px - ((g->player.py - g->ray.hy) / tan_ra));
		g->ray.y_step = -TL;
		g->ray.x_step = (g->ray.y_step / tan_ra);
		calculate_ray_hlen(g);
	}
	else if (g->ray.ra < PI && g->ray.ra > 0)
	{
		g->ray.hy = (((int)(g->player.py) >> 6) << 6) + TL;
		g->ray.hx = (g->player.px - ((g->player.py - g->ray.hy) / tan_ra));
		g->ray.y_step = TL;
		g->ray.x_step = (g->ray.y_step / tan_ra);
		calculate_ray_hlen(g);
	}
	else if (g->ray.ra == 0 || g->ray.ra == PI)
		g->ray.hlen = 0;
}


void	calculate_ray_vlen(t_game *g)
{
	int	hit = 0;

	while (hit == 0)
	{
		if ((g->ray.vy < TL) || (g->ray.vy > (g->map.mapH - 1) * TL))
		{
			g->ray.vlen = 0;
			return ;
		}
		if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2))
			g->map.x = ((int)(g->ray.vx - 1)) >> 6;
		else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2))
			g->map.x = ((int)(g->ray.vx)) >> 6;
		g->map.y = ((int)g->ray.vy) >> 6;
		g->map.pos = g->map.y * g->map.mapW + g->map.x;
		if (g->map.pos >= 0 && g->map.pos < g->map.mapW * g->map.mapH && g->map.map[g->map.pos] == '1')
			hit = 1;
		else
		{
			g->ray.vx += g->ray.x_step;
			g->ray.vy += g->ray.y_step;
		}
	}
	set_vcolor(g);
	g->ray.vlen = squared_vlen(g);
}

void	check_vertical_lines(t_game *g)
{
	float	tan_ra;

	tan_ra = tanf(g->ray.ra);
	if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2))
	{
		g->ray.vx = (((int)g->player.px >> 6) << 6);
		g->ray.vy = (g->player.py - (g->player.px - g->ray.vx) * tan_ra);
		g->ray.x_step = -TL;
		g->ray.y_step = (g->ray.x_step * tan_ra);
		calculate_ray_vlen(g);
	}
	else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2))
	{
		g->ray.vx = (((int)g->player.px >> 6) << 6) + TL;
		g->ray.vy = (g->player.py - (g->player.px - g->ray.vx) * tan_ra);
		g->ray.x_step = TL;
		g->ray.y_step = (g->ray.x_step * tan_ra);
		calculate_ray_vlen(g);
	}
	else if (g->ray.ra == (PI / 2) || g->ray.ra == (3 * PI / 2))
		g->ray.vlen = 0;
}
