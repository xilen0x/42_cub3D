/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:18:54 by castorga          #+#    #+#             */
/*   Updated: 2024/08/12 16:18:57 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_delimiters2(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == ',')
			count++;
		str++;
	}
	return (count);
}
void copy_substring2(char **result, const char *str, int start, int end, int *index)
{
    result[*index] = p_malloc((end - start + 1) * sizeof(char));
    ft_strncpy(result[*index], str + start, end - start);
    result[*index][end - start] = '\0';
    (*index)++;
}

void fill_substrings2(char **result, const char *str)
{
    int start = 0;
    int end = 0;
    int index = 0;
    int length = ft_strlen(str);

    while (end <= length)
    {
        if (str[end] == ' ' || str[end] == '\t' || str[end] == ',' || str[end] == '\0')
        {
            if (end > start)
                copy_substring2(result, str, start, end, &index);
            start = end + 1;
        }
        end++;
    }
    result[index] = NULL;
}
char **allocate_substrings2(const char *str, int *substr_count)
{
    int delimiter_count;

    delimiter_count = count_delimiters2(str);
    *substr_count = delimiter_count + 1;
    return p_malloc((*substr_count + 1) * sizeof(char *));
}

char **split_space_tab_comma(const char *str)
{
    char **result;
    int substr_count;

	str++;
    result = allocate_substrings2(str, &substr_count);
    fill_substrings2(result, str);
    return result;
}