#include "cub3d.h"

void	remove_extra_spaces_or_tabs(t_lmap *lm)
{
	char	*line;

	while (lm && (
			(ft_strnstr2(lm->cont, "NO", ft_strlen(lm->cont)) != NULL) || 
			(ft_strnstr2(lm->cont, "SO", ft_strlen(lm->cont)) != NULL) || 
			(ft_strnstr2(lm->cont, "WE", ft_strlen(lm->cont)) != NULL) || 
			(ft_strnstr2(lm->cont, "EA", ft_strlen(lm->cont)) != NULL) || 
			(ft_strnstr2(lm->cont, "F", ft_strlen(lm->cont)) != NULL) || 
			(ft_strnstr2(lm->cont, "C", ft_strlen(lm->cont)) != NULL)))
	{
		line = ft_strtrim2(lm->cont, " ", "\t");
		free(lm->cont);
		lm->cont = line;
		lm = lm->next;
	}
}

/*Inserta un espacio antes y despues de la coma.(de los val. nums.)*/
void	add_one_space_between_elements(t_lmap *lmap)
{
	int		i;
	int		j;
	int		additional_space_count;
	char	*line;
	char	*new_line;

	while (lmap)
	{
		i = 0;
		additional_space_count = 0;
		line = lmap->cont;
		while (line[i])
		{
			if (line[i] == ',' && line[i + 1] != ' ' && line[i + 1] != '\t' && 
				line[i + 1] != '\0')
				additional_space_count++;
			i++;
		}
		new_line = (char *)malloc(strlen(line) + additional_space_count + 1);
		if (!new_line)
			return ;
		i = 0;
		j = 0;
		while (line[i])
		{
			if (line[i] != '\t')
			{
				new_line[j++] = line[i];
				if (line[i] == ',' && line[i + 1] != ' ' && line[i + 1] != '\t' 
					&& line[i + 1] != '\0')
					new_line[j++] = ' ';
				else if (line[i] == ' ')
				{
					while (line[i + 1] == '\t')
						i++;
				}
			}
			i++;
		}
		new_line[j] = '\0';
		free(lmap->cont);
		lmap->cont = new_line;
		lmap = lmap->next;
	}
}

/*remueve los espacios y tabulaciones al final de la linea*/
void	remove_final_spaces_tabs(char *str)
{
	int	i;

	i = ft_strlen(str) - 2;
	while (str[i] == ' ' || str[i] == '\t')
	{
		str[i] = '\0';
		i--;
	}
}
