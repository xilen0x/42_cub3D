
#ifndef CUB3D_H
# define CUB3D_H

/* =============================== LIBRARIES =============================== */
# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <math.h>
# include <stdio.h>

/* ===============================   MACROS  =============================== */
# define MAX_COLOR_VALUE 255
# define MIN_COLOR_VALUE 0
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
#define WINX				1280//1920
#define WINY				1024//1080

// /* =============================== CARLOS STRUCTURES =============================== */
typedef struct s_map_parse
{
	int				map_fd;
	int				w;//ancho del mapa
	int				h;//alto del mapa
	int				x;//posicion x del jugador
	int				y;//posicion y del jugador
	char			**matrix;//matriz donde se guarda el mapa
	void			*mlx;
	void			*mlx_win;
	// t_img			imgs;
}	t_map_parse;

typedef struct s_list_x_map
{
	char				*cont;
	struct s_list_x_map	*next;
}	t_lmap;

typedef struct s_elem
{
	char	*no_path;//path que almacena la ruta de la textura NO
	char	*so_path;//path que almacena la ruta de la textura SO
	char	*ea_path;//path que almacena la ruta de la textura EA
	char	*we_path;//path que almacena la ruta de la textura WE
	char	**av;
	char	*line;
}	t_elem;

typedef struct s_colors
{
	int			f;//int para saber si se ha encontrado F (1)
	int			c;//int para saber si se ha encontrado C (2)
	uint32_t	f_color[3];//array para guardar los valores de F
	uint32_t	c_color[3];//array para guardar los valores de C
	uint32_t	f_color_hex;//color en hexadecimal de F
	uint32_t	c_color_hex;//color en hexadecimal de C
}	t_colors;

/* ===============================  SERGIO STRUCTURES  =============================== */
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
	t_img		img2;	// to be img2
	t_img		img3;
	t_map		map;
	t_player	player;
	t_ray		ray;
	void		*mlx;
	void		*win;
	int			h;		// game/window height in pixels
	int			w;		// game/window width in pixels
	float		si[628];
	float		co[628];
	float		ta[628];
}				t_game;

/* ===============================  GAME  =============================== */

/************************** trigo.c *******************************/
void	set_sine(float *sin_arr);
void	set_cosine(float *cos_arr);
void	set_tan(float *tan_arr);

/************************* setters.c ******************************/
void	set_pixel_to_image(t_img *img, int x, int y, uint32_t color);
void	set_player(t_map *map, t_player *player);
void	set_rays(t_game *g);
void	set_image(t_game *g, t_colors *colors);

void	calculate_ray_hlen(t_game *g);
void	calculate_ray_vlen(t_game *g);

void	check_horizon_lines(t_game *g);
void	check_vertical_lines(t_game *g);

/********************** game_utils.c *****************************/
int		exit_game(t_game *g);
int		press_key(int keycode, t_game *g, t_colors *colors);

/********************** game_moves.c ****************************/
// void	move_w(t_game *g);
// void	move_s(t_game *g);
// void	move_a(t_game *g);
// void	move_d(t_game *g);
// void	move_l(t_game *g);
// void	move_r(t_game *g);
void	move_w(t_game *g, t_colors *colors);
void	move_s(t_game *g, t_colors *colors);
void	move_a(t_game *g, t_colors *colors);
void	move_d(t_game *g, t_colors *colors);
void	move_l(t_game *g, t_colors *colors);
void	move_r(t_game *g, t_colors *colors);
/********************* put_to_image.c **************************/
void	bg_to_image(t_game *g, int color);
// void	floor_to_image(t_img *img, int color);
void	floor_to_image(t_img *img, t_colors *colors);
void	ceiling_to_image(t_img *img, t_colors *colors);
void	grid_to_image(t_img *img, int color);
void	box_to_image(t_img *img, int x, int y, int color);
void	player_to_image(t_img *img, t_player *player, int color);
void	direction_to_image(t_game *g, int color);//(t_img *img, t_player *player, int color);
void	ray_to_image(t_game *g, int color);//(t_img *img, t_ray *ray, t_player *player, int color);
void	map_to_image(t_img *img, t_map *map, int color);
void	slice_to_image(t_game *g, int col, int top_px, int bottom_px);//, int color);
void	wall_to_image(t_game *g, int col);
//int		get_color(t_game *g);

/* =============================== PARSE =============================== */
void	init_values(t_elem *elem, t_colors *colors, t_map_parse *map, char *av[]);
void	parsing(t_elem *elem, t_colors *colors, t_map_parse *map, t_lmap **lmap);
int		file_is_cub(char *av);
int		open_map(char *av, t_map_parse *map);
int		ft_errors(char *msg);
void	free_element_struct(t_elem *elem);
void	free_elements(char **double_pointer);
void	free_data2(char **line, char **colors);
char	*ft_strnstr2(const char *haystack, const char *needle, size_t len);
void	parsing_map(t_map_parse *map, t_lmap **lmap);
char	**split_space_tab_comma(const char *str);
int		counter_of_char(const char *str);
void	remove_final_spaces_tabs(char *str);
int		check_range_values(int i, char **line, t_colors *colors, t_lmap *lmap);
char	*ft_strtrim2(char const *s1, char const *set, char const *tabs);
char	**ft_split2(const char *str);
char	*ft_strncpy2(char *dest, const char *src, unsigned int n);
int		looking_for_xpm(char **elements);
int		save_path_chain_to_elem_struct(t_lmap *lmap, t_elem *elem, t_colors *colors);
void	remove_extra_spaces_or_tabs(t_lmap *lm);
int		exist_elements_or_colors_anywhere(t_lmap *lmap);
int		is_square_map(t_lmap *lm);
void	add_one_space_between_elements(t_lmap *lmap);
void	remove_spaces_around_commas(t_lmap *lmap);
void	print_list(t_lmap *lmap);
t_lmap	*ft_newnode(char *c);
void	ft_add_back(t_lmap **lst, t_lmap *new);
t_lmap	*ft_lastnode(t_lmap *node);
int		lst_size(t_lmap *lmap);
void	lst_clear(t_lmap **lmap, void (*del)(void*));
size_t	search_longest_line(t_lmap *lmap);
void	create_list(t_map_parse *map, t_lmap **lmap);
int		exist_elements(t_lmap *lmap);
int		exist_elements2(t_lmap *lmap);
int		exist_path_elements(t_lmap *lmap);
int		exist_colors(t_lmap *lmap);
int		exist_path_colors(t_lmap *lmap, t_colors *colors);
int		exist_path_colors2(char **line, t_colors *colors, t_lmap *lmap);
int		exist_path_colors_op2(t_lmap *lmap, t_colors *colors);
void	remove_external_tabs_spaces_elem(t_lmap *lmap);
void	save_rgb_values(t_lmap *lmap, t_colors *colors);
void	remove_empty_lines(t_lmap *lmap);
void	remove_newline(char *line);
void	remove_newline_char(char *str);
int		free_data(char **line, char **colors);
int		first_row_is_all_ones(t_lmap *lm);
int		rows_are_all_ones(t_lmap *lm);
size_t	ft_strlen2(const char *s);
void	*p_malloc(size_t size);
void	jump_elements(t_lmap **lm);
void	valid_map(t_map_parse *map);
void	create_matrix(t_map_parse *map, t_lmap *lmap);
void	spaces_to_ones(t_map_parse *map);
void	create_matrix_irregular(t_map_parse *map, t_lmap *lm);
void	free_matrix(char **matrix, size_t rows);
void	print_matrix(t_map_parse *map);
void	print_width_height(t_map_parse *map);
int		space_exist_next_to_0(t_map_parse *m);
void	load_map(t_game *g, t_map_parse *map);
void	printMap(t_game *g);
#endif
