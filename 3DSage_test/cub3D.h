/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:06:17 by spereyra          #+#    #+#             */
/*   Updated: 2024/09/27 17:44:49 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//// only for strdup --> pending to delete
#include <math.h>
#include "mlx.h"

//#define	PI	3.1415f	// already defined in <math.h> as M_PI = 3.14159265358979323846
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_RELEASE	3
#define X_EVENT_KEY_EXIT	17
#define KEY_ESC				65307
#define KEY_W				119
#define KEY_A				97
#define KEY_S				115
#define KEY_D				100
#define	KEY_LEFT			65361
#define	KEY_RIGHT			65363
#define	PX2					64//32//64	// Side of 2D tiles in pixels
#define	PX3					64//32//64	// Side of 3D tiles in pixels
#define	PI					314	// int 314 / 100.0f returns a float !!!

typedef struct	s_player
{
	int		px;			// player x coordinate (body centre) in pixels, into the image
	int		py;			// player y coordinate (body centre) in pixels, into the image
//	float	pdx;
//	float	pdy;
//	float	pa;			// player angle in radians
	int		pa;			// player angle in radians (in integer form, then divided by 100.0f)
}				t_player;

typedef struct	s_ray
{
//	float	ra;			// ray angle
	int		ra;			// ray angle in radians (in integer form, then divided by 100.0f)
	int		hx;			// horizontal line intersection point
	int		hy;			// horizontal line intersection point
	int		vx;			// vertical line intersection point
	int		vy;			// vertical line intersection point
	int		x_step;		// x offset to next horizontal line
	int		y_step;		// y offset to next horizontal line
	int		hlen;		// length of the ray to horizontal hit
	int		vlen;		// length of the ray to vertical hit
	int		len;		// minimal of hlen and vlen
	int		hcolor;		// color based on orientation of the wall (N, S)
	int		vcolor;		// color based on orientation of the wall (E, W)
	int		color;		// definitive color
}				t_ray;

typedef struct	s_map
{
	char	*map;
	int		mapH;		// map height in boxes/tiles
	int		mapW;		// map width in boxes/tiles
	int		x;			// x coordinate of the map, in boxes/tiles
	int		y;			// y coordinate of the map, in boxes/tiles
	int		pos;		// position n the map = y * mapW + x
}
				t_map;

typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;		// array of pixels
	int		h;			// image height in pixels
	int		w;			// image width in pixels
	int		bpp;		// bytes per pixels (tipically 4)
	int		endian;		// order of bytes in memory
	int		line_len;	// line length in bytes of each line of the image
}				t_img;

typedef struct	s_game
{
	t_img	img2;// to be img2
	t_img	img3;
	t_map	map;
	t_player	player;
	t_ray	ray;
	void	*mlx;
	void	*win;
	int		h;			// game/window height in pixels
	int		w;			// game/window width in pixels
	float	si[628];
	float	co[628];
	float	ta[628];
}				t_game;

/************************** trigo.c *******************************/
void	set_sine(float *sin_arr);
void	set_cosine(float *cos_arr);
void	set_tan(float *tan_arr);

/************************* setters.c ******************************/
void	set_pixel_to_image(t_img *img, int x, int y, int color);
void	set_player(t_map *map, t_player *player);
void	set_rays(t_game *g);
void	set_image(t_game *g);

void	calculate_ray_hlen(t_game *g);
void	calculate_ray_vlen(t_game *g);

void	check_horizon_lines(t_game *g);
void	check_vertical_lines(t_game *g);

/********************** game_utils.c *****************************/
int		exit_game(t_game *g);
int		press_key(int keycode, t_game *g);

/********************** game_moves.c ****************************/
void	move_w(t_game *g);
void	move_s(t_game *g);
void	move_a(t_game *g);
void	move_d(t_game *g);
void	move_l(t_game *g);
void	move_r(t_game *g);

/********************* put_to_image.c **************************/
void	bg_to_image(t_img *img, int color);
void	floor_to_image(t_img *img, int color);
void	ceiling_to_image(t_img *img, int color);
void	grid_to_image(t_img *img, int color);
void	box_to_image(t_img *img, int x, int y, int color);
void	player_to_image(t_img *img, t_player *player, int color);
void	direction_to_image(t_game *g, int color);//(t_img *img, t_player *player, int color);
void	ray_to_image(t_game *g, int color);//(t_img *img, t_ray *ray, t_player *player, int color);
void	map_to_image(t_img *img, t_map *map, int color);
void	slice_to_image(t_game *g, int col, int top_px, int bottom_px);//, int color);
void	wall_to_image(t_game *g, int col);
//int		get_color(t_game *g);