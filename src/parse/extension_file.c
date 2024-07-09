
#include "cub3d.h"

/*Funcion que verifica la extension .cub*/
int	file_is_cub(char *av, t_game *game)
{
	int	len;

	(void)game;
	len = ft_strlen(av);
	if (ft_strncmp(&av[len - 4], ".cub", 4) == 0)
		return (0);
	else
	{
		write (2, "Error\n", 6);
		write (2, "The file does not have a .cub extension.\n", 41);
		exit(1);
	}
}
