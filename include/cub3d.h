
#ifndef CUB3D_H
# define CUB3D_H

/* ====================== LIBRARIES ====================== */
# include "mlx.h"
# include "window.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>

/* ====================== MACROS ====================== */
// #define CYAN "\033[0;36m"
// #define RESET "\033[0m"
// #define BONUS 0

// #define NORTH 0
// #define SOUTH 1
// #define EAST 2
// #define WEST 3

#define MAX_COLOR_VALUE 255
#define MIN_COLOR_VALUE 0

/* ====================== STRUCTURES ====================== */
typedef struct s_map
{
	int				map_fd;
	int				w;
	int				h;
	int				x;
	int				y;
	char			**matrix;
}	t_map;

typedef struct s_list_x_map
{
	char				*content;
	struct s_list_x_map	*next;
}	t_lmap;

typedef struct s_elem
{
	char	all_elem_found;
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	char	**av;
	char	*line;
}	t_elem;

typedef struct s_colors
{
	int		f;
	int		c;
	int		f_color[3];
	int		c_color[3];
}	t_colors;

// typedef struct s_params
// {
//     t_elem *elem;
//     t_colors *colors;
//     t_map *map;
//     char *av;
// } t_params;

/* ====================== PARSING ====================== */
void	init_values(t_elem *elem, t_colors *colors, t_map *map, char *av[]);
void	parsing(t_elem *elem, t_colors *colors, t_map *map, t_lmap **lmap);
int		file_is_cub(char *av);
int		open_map(char *av, t_map *map);
int		ft_errors(char *msg);
void	free_element_struct(t_elem *elem);
void	free_elements(char **double_pointer);
void	free_data2(char **line, char **colors);
// void	parsing_colors(t_colors *colors, t_map *map);
// void	parsing_colors2(t_colors *colors, t_map *map, char *line);
// void	parsing_elements(t_elem *elem, t_map *map);
// void 	parsing_elements2(t_elem *elem, t_map *map, char *line);
char	*ft_strnstr2(const char *haystack, const char *needle, size_t len);
void	parsing_map(t_map *map, t_lmap **lmap);
void	valid_map(t_map *map);
void	remove_spaces_around_commas(t_lmap *lmap);
char	**split_space_tab_comma(const char *str);
// void	remove_tabs(char **elements);
// void	remove_tabs_and_spaces(char *lines);
char	*ft_strtrim2(char const *s1, char const *set, char const *tabs);
char	**ft_split2(const char *str);
void	print_width_height(t_map *map);
void	print_elements(t_elem *elem);
void	print_colors(t_colors *colors);
char	*ft_strncpy2(char *dest, const char *src, unsigned int n);
int		exist_elements_or_colors_anywhere(t_lmap *lmap);

/* ------------- LIST ------------- */
void	print_list(t_lmap *lmap);
t_lmap	*ft_newnode(char *c);
void	ft_add_back(t_lmap **lst, t_lmap *new);
t_lmap	*ft_lastnode(t_lmap *node);
// void 		ft_del_one(t_lmap *lst, void (*del)(void*));
int		lst_size(t_lmap *lmap);
void	lst_clear(t_lmap **lmap, void (*del)(void*));
size_t	search_longest_line(t_lmap *lmap);
// size_t	spaces_to_ones(t_lmap *lmap);
void	spaces_to_ones(t_map *map);
void	create_list(t_map *map, t_lmap **lmap);
// void			remove_newline(char *line);
int		exist_elements(t_lmap *lmap);
int		exist_elements2(t_lmap *lmap);
int		exist_path_elements(t_lmap *lmap);
int		exist_colors(t_lmap *lmap);
int		exist_path_colors(t_lmap *lmap, t_colors *colors);
int		exist_path_colors2(char **line, t_colors *colors, t_lmap *lmap);
int		exist_path_colors_op2(t_lmap *lmap, t_colors *colors);
void	remove_external_tabs_spaces_elem(t_lmap *lmap);
// void	remove_internal_tabs_spaces_elem(t_lmap *lmap);
void	save_rgb_values(t_lmap *lmap, t_colors *colors);
void	remove_empty_lines(t_lmap *lmap);
void	remove_newline(char *line);
void	remove_newline_char(char *str);
int		free_data(char **line, char **colors);
int 	first_row_is_all_ones(t_lmap *lm);
int		rows_are_all_ones(t_lmap *lm);
size_t	ft_strlen2(const char *s);

/* ------------- MATRIX ------------- */
void	create_matrix(t_map *map, t_lmap *lmap);
void	create_matrix_irregular(t_map *map, t_lmap *lm);
void	print_matrix(t_map *map);
// void	free_matrix(char **matrix);
void	free_matrix(char **matrix, size_t rows);
void	*p_malloc(size_t size);
// int		horizontal_check(t_lmap *lmap);

/* ====================== GAME ====================== */

#endif
