/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:44:40 by castorga          #+#    #+#             */
/*   Updated: 2024/07/09 15:44:43 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_elements(char **elements)
{
	int i;

	i = 0;
	while (elements[i])
	{
		free(elements[i]);
		i++;
	}
	free(elements);
}

//elimina espacios antes y después de las comas
void remove_spaces_around_commas(char *line)
{
    int i;
	int j;
	
	i = 0;
	j = 0;
    while (line[i] != '\0')
	{
        // Eliminar espacios adicionales
        if (line[i] == ' ' && (j == 0 || line[i + 1] == ' ' || line[i + 1] == ','))
		{
            i++;
            continue;
        }
        // Eliminar espacio antes de la coma
        if (line[i] == ' ' && line[i + 1] == ',')
		{
            i++;
        }
        // Eliminar espacio después de la coma
        if (line[i] == ',' && line[i + 1] == ' ')
		{
            line[j++] = line[i++];
            while (line[i] == ' ')
			{
                i++;
            }
        }
		else
		{
            line[j++] = line[i++];
        }
    }
    line[j] = '\0';
}

int elements_colors_exist(char *av, t_map *map)
{
    char *line;
    char **elements;
    char **colors;
    int i;

    open_map(av, map);  // Abre el archivo del mapa
    line = get_next_line(map->map_fd);  // Lee la primera línea del archivo
    
    while (line)
    {
        elements = ft_split(line, ' ');  // Divide la línea en elementos usando espacios como delimitadores
        if (!elements)
        {
            free(line);
            printf("Error al dividir la línea en elementos!\n");
            return (1);
        }
        
        i = 0;
        while (elements[i])
            i++;
        
        if (i == 2)
        {
            if (ft_strncmp(elements[0], "F", 1) == 0 || ft_strncmp(elements[0], "C", 1) == 0)
            {
                colors = ft_split(elements[1], ',');  // Divide el segundo elemento por comas
                if (!colors)
                {
                    free_elements(elements);  // Libera `elements` antes de salir
                    free(line);
                    printf("Error al dividir los colores!\n");
                    return (1);
                }

                if (ft_strncmp(elements[0], "F", 1) == 0)
                    map->f++;
                else if (ft_strncmp(elements[0], "C", 1) == 0)
                    map->c++;

                i = 0;
                while (colors[i])
                    i++;
                
                if (i != 3)
                {
                    printf("Error de sintaxis en colores!\n");
                    free_elements(colors);  // Libera `colors` antes de salir
                    free_elements(elements);
                    free(line);
                    return (1);
                }
                free_elements(colors);  // Libera `colors` después de usarlo
            }
        }
        free_elements(elements);  // Libera `elements` después de usarlo
        free(line);  // Libera `line` después de usarlo
        line = get_next_line(map->map_fd);  // Lee la siguiente línea del archivo
    }

    close(map->map_fd);  // Cierra el archivo del mapa
    
    if (map->f && map->c)
    {
        printf("All colors exist\n");
        return (0);
    }
    else
    {
        printf("Error: Faltan colores!\n");
        return (1);
    }
}

//Check if elements exist(in any order)
int	elements_exist(t_map *map)
{
	char	*line;
	char	**elements;
	int		i;

	line = get_next_line(map->map_fd);
	while (line)
	{
		elements = ft_split(line, ' ');
		i = 0;
		while (elements[i])
			i++;
		if (i == 2)
		{
			if (ft_strncmp(elements[0], "NO", 2) == 0)
			{
				map->no++;
				map->no_path = ft_strdup(elements[1]);
			}
			else if (ft_strncmp(elements[0], "SO", 2) == 0)
			{
				map->so++;
				map->so_path = ft_strdup(elements[1]);
			}
			else if (ft_strncmp(elements[0], "WE", 2) == 0)
			{
				map->we++;
				map->we_path = ft_strdup(elements[1]);
			}
			else if (ft_strncmp(elements[0], "EA", 2) == 0)
			{
				map->ea++;
				map->ea_path = ft_strdup(elements[1]);
			}
		}
		else
		{
			printf("Error de sintaxis en elementos!\n");//la linea vacia al inicio la da como error aparentemente
			close(map->map_fd);
			free(line);
			free_elements(elements);
			free_xx_path(map);
			return (1);
		}
        free(line);
		free_elements(elements);
		if (map->no && map->so && map->we && map->ea)
		{
        	close(map->map_fd);
			printf("All cardinal directions exist\n");
			free_xx_path(map);
        	return (0);
    	}
		line = get_next_line(map->map_fd);
    }

	printf("algun otro Error\n");
	close(map->map_fd);
	free_xx_path(map);
	return (1);
}
