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

// // Divide una cadena en subcadenas basadas en espacios y tabulaciones
// char	**ft_split2(const char *str)
// {
// 	int		start;
// 	int		end;
// 	int		index;
// 	int		length;
// 	int		delimiter_count;
// 	int		substr_count;
// 	char	**result;

// 	delimiter_count = count_delimiters(str);
// 	substr_count = delimiter_count + 1;
// 	result = p_malloc((substr_count + 1) * sizeof(char *));
// 	start = 0;
// 	end = 0;
// 	index = 0;
// 	length = ft_strlen(str);
// 	while (end <= length)
// 	{
// 		if (str[end] == ' ' || str[end] == '\t' || str[end] == '\0')
// 		{
// 			if (end > start)
// 			{
// 				result[index] = p_malloc((end - start + 1) * sizeof(char));
// 				ft_strncpy(result[index], str + start, end - start);
// 				result[index][end - start] = '\0';
// 				index++;
// 			}
// 			start = end + 1;
// 		}
// 		end++;
// 	}
// 	result[index] = NULL;
// 	return (result);
// }

char **allocate_substrings(const char *str, int *substr_count)
{
    int delimiter_count;

    delimiter_count = count_delimiters(str);
    *substr_count = delimiter_count + 1;
    return p_malloc((*substr_count + 1) * sizeof(char *));
}

void copy_substring(char **result, const char *str, int start, int end, int *index)
{
    result[*index] = p_malloc((end - start + 1) * sizeof(char));
    ft_strncpy(result[*index], str + start, end - start);
    result[*index][end - start] = '\0';
    (*index)++;
}

void fill_substrings(char **result, const char *str)
{
    int start = 0;
    int end = 0;
    int index = 0;
    int length = ft_strlen(str);

    while (end <= length)
    {
        if (str[end] == ' ' || str[end] == '\t' || str[end] == '\0')
        {
            if (end > start)
                copy_substring(result, str, start, end, &index);
            start = end + 1;
        }
        end++;
    }
    result[index] = NULL;
}

char **ft_split2(const char *str)
{
    char **result;
    int substr_count;

    result = allocate_substrings(str, &substr_count);
    fill_substrings(result, str);
    return result;
}

void	print_elements(t_elem *elem)
{
	ft_printf("NO_PATH: %s\n", elem->no_path);
	ft_printf("SO_PATH: %s\n", elem->so_path);
	ft_printf("EA_PATH: %s\n", elem->ea_path);
	ft_printf("WE_PATH: %s\n", elem->we_path);
}

void	print_colors(t_colors *colors)
{
	ft_printf("\nF      : %d\n", colors->f);
	ft_printf("F_COLOR: %d, %d, %d\n", colors->f_color[0], colors->f_color[1], \
	colors->f_color[2]);
	ft_printf("\nC      : %d\n", colors->c);
	ft_printf("C_COLOR: %d, %d, %d\n", colors->c_color[0], colors->c_color[1], \
	colors->c_color[2]);
}

void	free_data2(char **line, char **colors)
{
	free_elements(line);
	free_elements(colors);
}
