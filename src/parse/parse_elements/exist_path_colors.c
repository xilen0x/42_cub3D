
#include "cub3d.h"

int	ft_strcmp(char c1, char c2)
{
	if (c1 > c2)
		return (1);
	else if (c1 == c2)
		return (0);
	else
		return (-1);
}

int	value_isdigit(char *num)
{
	int		i;

	i = 0;
	while (num[i])
	{
		if (num[i] >= '0' && num[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_range_values(char **colors, int i, char **line)
{
	int		color_value;

	i = 0;
	while (colors[i])
	{
		if (value_isdigit(colors[i]))
			color_value = ft_atoi(colors[i]);
		else
			return (free_data(line, colors));
		if (color_value < MIN_COLOR_VALUE || color_value > MAX_COLOR_VALUE)
			return (free_data(line, colors));
		i++;
	}
	return (0);
}

int	exist_path_colors2(t_lmap *lmap, char **line)
{
	char	**colors;
	int		i;

	if ((ft_strcmp(lmap->content[0], 'F') == 0) || 
		(ft_strcmp(lmap->content[0], 'C') == 0))
	{
		colors = ft_split(line[1], ',');
		i = 0;
		while (colors[i])
			i++;
		if (i == 3)
		{
			if (check_range_values(colors, i, line) == 1)
				return (1);
		}
		else
			free_data2(line, colors);
	}
	else
		free_elements(line);
	return (0);
}

int	exist_path_colors(t_lmap *lmap)
{
	char	**line;
	char	*temp;

	while (lmap)
	{
		temp = lmap->content;
		line = ft_split(temp, ' ');
		exist_path_colors2(lmap, line);
		lmap = lmap->next;
	}
	return (0);
}
