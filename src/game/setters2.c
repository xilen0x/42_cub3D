#include "cub3d.h"

/* Set the colour of a given pixel in an array of pixels (i.e. the image) */
void	set_pixel_to_image(t_img *img, int x, int y, unsigned int color)
{
	void	*offset;

	if (x < 0 || x >= WX || y < 0 || y >= WY)
		return ;
	offset = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)offset = color;
}

void	set_rays(t_game *g)
{
	float	angle_step;
	int		rays;

	g->ray.ra = g->player.pa - (g->player.fov / 2);
	angle_step = g->player.fov / g->img3.w;
	rays = 0;
	while (rays < g->img3.w)
	{
		g->ray.ra = norm_angle(g->ray.ra);
		check_horizon_lines(g);
		check_vertical_lines(g);
		if (g->ray.hlen <= 0 || (g->ray.vlen > 0 && g->ray.vlen < g->ray.hlen))
		{
            g->ray.len = sqrtf(g->ray.vlen); // Usar la distancia vertical
            g->ray.color = g->ray.vcolor;
			g->ray.path = g->ray.vpath;///////////////
		}
		else
		{
            g->ray.len = sqrtf(g->ray.hlen); // Usar la distancia horizontal
            g->ray.color = g->ray.hcolor;
			g->ray.path = g->ray.hpath;///////////////
		}
		//ray_to_image(g, g->ray.color);
		render_wall(g, rays);
		g->ray.ra += angle_step;
		rays++;
	}
}

void	set_hcolor(t_game *g)
{
	if (g->ray.ra > PI && g->ray.ra < (2 * PI))	// looking up
	{
		g->ray.hcolor = 0x00C0C0C0;//0x00FFFFFF;// color of north wall
		g->ray.hpath = 0;//"./textures/north.xpm";/////////////
	}
	else if (g->ray.ra <= PI && g->ray.ra >= 0)	// looking down
	{
		g->ray.hcolor = 0x00FF00FF;// color of south wall
		g->ray.hpath = 1;//"./textures/south.xpm";//////////////
	}
}

void	set_vcolor(t_game *g)// to be set_path
{
	if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2)) // looking left
	{
		g->ray.vcolor = 0x00FFFF00;// color of east wall
		g->ray.vpath = 2;//"./textures/east.xpm";
	}
	else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2)) // looking right
	{
		g->ray.vcolor = 0x0000FFFF;// color of west wall
		g->ray.vpath = 3;//"./textures/west.xpm";
	}
}

float	squared_hlen(t_game *g)
{
	float	dx;
	float	dy;

	dx = g->player.px - g->ray.hx;
	dy = g->player.py - g->ray.hy;
	return (dx * dx + dy * dy);
}

