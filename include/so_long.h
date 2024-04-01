/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:47:14 by castorga          #+#    #+#             */
/*   Updated: 2023/11/27 13:47:17 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include "../mlx/mlx.h"

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

typedef struct s_player
{
	void	*player_up;
	void	*player_right;
	void	*player_down;
	void	*player_left;
	void	*barrer_a;
}	t_player;

typedef struct s_text
{
	void	*s;
	void	*t;
	void	*e;
	void	*p;
	void	*o;
}	t_text;

typedef struct s_img
{
	void		*wall;
	void		*floor;
	void		*coll;
	void		*exit;
	void		*open;
	void		*black;
	t_text		text;		
	t_player	player;
	int			w;
	int			h;
	void		*img_ptr;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**matrix;
	int		map_fd;
	int		w;
	int		h;
	int		q_collec;
	int		collected;
	int		walk_cnt;
	t_img	imgs;
	t_point	position;
	t_point exit;
}	t_game;

int		file_is_ber(char *av, t_game *game);
int		open_map(char *av, t_game *game);
int		ft_errors(int n);
int		ft_errors2(int n);
void	create_map(int fd, t_game *game, char *av);
void	print_matrix(t_game *game);
void	set_values(t_game *g);
int		parsing_map(t_game *game);
int		is_rectangular(t_game *game);
int		is_initial_position(t_game *game);
int		is_surrounded_by_walls(t_game *game);
int		has_only_one_exit(t_game *game);
int		valid_path_to_exit(t_game *game);
int		valid_path_to_collectables(t_game *game);
int		q_collectible(t_game *game);
t_point	find_p(t_game *copy_map, t_game *game);
void	set_images(t_game *game);
void	set_images_to_win(t_game *game, char dir);
void	init_game(t_game *game);
void	set_player(t_game *g, int y, int x, char dir);
int		press_key(int keycode, t_game *game);
void	move_up(t_game *g);
void	move_right(t_game *g);
void	move_left(t_game *g);
void	move_down(t_game *g);
int		exit_game(t_game *g);
void	free_map(t_game *game);

#endif
