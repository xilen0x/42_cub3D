#include "cub3d.h"

int	check_start_and_end_ones(char *line)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	i = 0;
	start = 0;
	end = 0;
	remove_final_spaces_tabs(line);
	remove_newline_char(line);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1')
		start = 1;
	while (line[i] != '\0')
		i++;
	if (line[i - 1] == '1')
		end = 1;
	return (start && end);
}

int	last_row_is_all_ones(char *line)
{
	unsigned int	length_line;
	unsigned int	q_of_ones;

	remove_newline_char(line);
	length_line = ft_strlen2(line);
	q_of_ones = counter_of_char(line);
	return (length_line != q_of_ones);
}

int	rows_are_all_ones(t_lmap *lm)
{
	unsigned int	size;

	jump_elements(&lm);
	lm = lm->next;
	size = lst_size(lm);
	while (lm && size > 1)
	{
		if (!check_start_and_end_ones(lm->cont))
			return (1);
		lm = lm->next;
		size--;
	}
	if (last_row_is_all_ones(lm->cont))
		return (1);
	return (0);
}

int	first_row_is_all_ones(t_lmap *lm)
{
	unsigned int	length_line;
	unsigned int	q_of_ones;
	char			*line;

	while (lm && (
			(ft_strnstr2(lm->cont, "NO", ft_strlen(lm->cont)) != NULL) || 
			(ft_strnstr2(lm->cont, "SO", ft_strlen(lm->cont)) != NULL) || 
			(ft_strnstr2(lm->cont, "WE", ft_strlen(lm->cont)) != NULL) || 
			(ft_strnstr2(lm->cont, "EA", ft_strlen(lm->cont)) != NULL) || 
			(ft_strnstr2(lm->cont, "F", ft_strlen(lm->cont)) != NULL) || 
			(ft_strnstr2(lm->cont, "C", ft_strlen(lm->cont)) != NULL) || 
			(lm->cont[0] == '\0')))
		lm = lm->next;
	remove_newline_char(lm->cont);
	line = ft_strtrim2(lm->cont, " ", "\t");
	length_line = ft_strlen2(line);
	q_of_ones = counter_of_char(line);
	if (length_line != q_of_ones)
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

int	counter_of_char(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!str)
		ft_errors("Error, the string is empty\n");
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			count++;
		i++;
	}
	return (count);
}
