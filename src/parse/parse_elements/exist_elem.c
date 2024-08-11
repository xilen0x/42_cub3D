
#include "cub3d.h"

int	exist_cardinals(char **elements)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	while (elements[i] && temp < 4)
	{
		if (ft_strlen(elements[i]) == 2)
		{
			if (ft_strncmp(elements[i], "NO", 2) == 0)
				temp++;
			else if (ft_strncmp(elements[i], "SO", 2) == 0)
				temp++;
			else if (ft_strncmp(elements[i], "EA", 2) == 0)
				temp++;
			else if (ft_strncmp(elements[i], "WE", 2) == 0)
				temp++;
		}
		i++;
	}
	return (temp);
}

int	exist_elements(t_lmap *lmap)
{
	char	**elements;
	int		temp;
	int		count;

	count = 0;
	while (lmap)
	{
		elements = ft_split2(lmap->content);
		temp = exist_cardinals(elements);
		count = count + temp;
		if (temp != 1)
			ft_errors(3);
		if (count == 4)
		{
			free_elements(elements);
			return (0);
		}
		free_elements(elements);
		lmap = lmap->next;
	}
	return (0);
}

int	looking_for_xpm(char **elements)
{
	int		i;
	int		temp;

	temp = 0;
	i = 0;
	while (elements[i] && temp < 4)
	{
		if (ft_strlen(elements[i]) > 3)
		{
			if (ft_strnstr(elements[i], ".xpm", ft_strlen(elements[i])) != NULL)
				temp++;
			if (temp == 4)
			{
				free_elements(elements);
				return (temp);
			}
		}
		i++;
	}
	return (temp);
}

int	exist_path_elements(t_lmap *lmap)
{
	char	**elements;
	int		temp;
	int		count;

	temp = 0;
	while (lmap)
	{
		elements = ft_split2(lmap->content);
		count = looking_for_xpm(elements);
		temp = temp + count;
		free_elements(elements);
		lmap = lmap->next;
	}
	if (temp != 4)
		ft_errors(3);
	return (0);
}
