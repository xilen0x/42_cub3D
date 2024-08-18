/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:55:32 by castorga          #+#    #+#             */
/*   Updated: 2024/07/22 18:55:35 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Función para contar las ocurrencias de espacios o tabulaciones en una cadena
int	count_delimiters(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			count++;
		str++;
	}
	return (count);
}

void	copy_substr(char **res, const char *str, int start, int end, int *index)
{
	res[*index] = p_malloc((end - start + 1) * sizeof(char));
	ft_strncpy(res[*index], str + start, end - start);
	res[*index][end - start] = '\0';
	(*index)++;
}

void	fill_substrings(char **result, const char *str)
{
	int	start;
	int	end;
	int	index;
	int	length;

	start = 0;
	end = 0;
	index = 0;
	length = ft_strlen(str);
	while (end <= length)
	{
		if (str[end] == ' ' || str[end] == '\t' || str[end] == '\0')
		{
			if (end > start)
				copy_substr(result, str, start, end, &index);
			start = end + 1;
		}
		end++;
	}
	result[index] = NULL;
}

char	**allocate_substrings(const char *str, int *substr_count)
{
	int	delimiter_count;

	delimiter_count = count_delimiters(str);
	*substr_count = delimiter_count + 1;
	return (p_malloc((*substr_count + 1) * sizeof(char *)));
}

char	**ft_split2(const char *str)
{
	char	**result;
	int		substr_count;

	result = allocate_substrings(str, &substr_count);
	fill_substrings(result, str);
	return (result);
}
