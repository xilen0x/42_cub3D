
#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "window.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// #define CYAN "\033[0;36m"
// #define RESET "\033[0m"
// #define BONUS 0

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

#define MAX_COLOR_VALUE 255
#define MIN_COLOR_VALUE 0

typedef struct s_map
{
	int		map_fd;//almacena el fd del mapa original
	int		w;
	int		h;
	char	**matrix;
}	t_map;

typedef struct s_elem
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
}	t_elem;


typedef struct s_colors
{
	int		f;
	int		c;
	int		f_color[3];
	int		c_color[3];
}	t_colors;

/* ---------------------------- PARSING ----------------------------*/
int		file_is_cub(char *av);
int		open_map(char *av, t_map *map);
int		ft_errors(int n);
void	free_matrix(char **matrix);
void	free_xx_element(t_elem *elem);
void	free_elements(char **elements);
void	parsing(t_elem *elem, t_colors *colors, t_map *map, char *av[]);
// int		elements_exist(t_map *map);
void	init_values(t_elem *elem, t_colors *colors, t_map *map);
void	width_height_map_file(t_map *map, char *av[]);
int		elements_colors_exist(char *av, t_map *map);
void 	print_width_height(t_map *map);
void	remove_spaces_around_commas(char *line);
//void	remove_tabs(char **elements);
void	remove_tabs_and_spaces(char **lines);
void	texture_path_extension_is_valid(char	*elements);
int		elements_colors_range(t_map *map, char *element);

/* ---------------------------- GAME ----------------------------*/


#endif
