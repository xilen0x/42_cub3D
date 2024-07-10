
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
	int		w;
	int		h;
	char	**matrix;
}	t_map;

int		file_is_cub(char *av);
int		open_map(char *av, t_map *map);
int		ft_errors(int n);
void	parsing(t_map *map, char *av[]);
int		elements_exist(t_map *map);
void	init_values(t_map *map);
void	width_height_map_file(int fd, t_map *map, char *av);
void	*spaced_malloc(size_t count, size_t size);
void	create_matrix(t_map *map, char *av);

#endif
