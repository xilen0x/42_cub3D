/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:37:58 by castorga          #+#    #+#             */
/*   Updated: 2024/08/19 10:38:01 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define MAX_COLOR_VALUE 255
# define MIN_COLOR_VALUE 0

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
	char				*cont;
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

/* ====================== PARSING ====================== */
void	init_values(t_elem *elem, t_colors *colors, t_map *map, char *av[]);
void	parsing(t_elem *elem, t_colors *colors, t_map *map, t_lmap **lmap);
int		file_is_cub(char *av);
int		open_map(char *av, t_map *map);
int		ft_errors(char *msg);
void	free_element_struct(t_elem *elem);
void	free_elements(char **double_pointer);
void	free_data2(char **line, char **colors);
char	*ft_strnstr2(const char *haystack, const char *needle, size_t len);
void	parsing_map(t_map *map, t_lmap **lmap);
char	**split_space_tab_comma(const char *str);
int		counter_of_char(const char *str);
void	remove_final_spaces_tabs(char *str);
int		check_range_values(int i, char **line, t_colors *colors, t_lmap *lmap);
char	*ft_strtrim2(char const *s1, char const *set, char const *tabs);
char	**ft_split2(const char *str);
char	*ft_strncpy2(char *dest, const char *src, unsigned int n);
int		looking_for_xpm(char **elements);
int		save_path_chain_to_elem_struct(t_lmap *lmap, t_elem *elem);
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
void	create_list(t_map *map, t_lmap **lmap);
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
/* ------------- MATRIX ------------- */
void	valid_map(t_map *map);
void	create_matrix(t_map *map, t_lmap *lmap);
void	spaces_to_ones(t_map *map);
void	create_matrix_irregular(t_map *map, t_lmap *lm);
void	free_matrix(char **matrix, size_t rows);
void	print_matrix(t_map *map);
void	print_width_height(t_map *map);

/* ====================== GAME ====================== */

#endif
