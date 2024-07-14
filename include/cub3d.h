
#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "window.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#define CYAN "\033[0;36m"
#define RESET "\033[0m"
#define BONUS 0

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

typedef struct s_map
{
	int		map_fd;//almacena el fd del mapa original
	int		no;
	int		so;
	int		ea;
	int		we;
	int		f;
	int		c;
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	int		f_color[3];
	int		c_color[3];
	int		w;
	int		h;
	char	**matrix;
}	t_map;

int		file_is_cub(char *av);
int		open_map(char *av, t_map *map);
int		ft_errors(int n);
void	free_matrix(char **matrix);
void	free_xx_path(t_map *map);
void	parsing(t_map *map, char *av[]);
int		elements_exist(t_map *map);
void	init_values(t_map *map);
void	width_height_map_file(t_map *map, char *av[]);
void	spaced_malloc(t_map *map, size_t count, size_t size);
int		elements_colors_exist(char *av, t_map *map);

#endif
