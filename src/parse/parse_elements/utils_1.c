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

# include "cub3d.h"

// Función para contar las ocurrencias de espacios o tabulaciones en una cadena
int count_delimiters(const char *str) {
    int count = 0;
    while (*str) {
        if (*str == ' ' || *str == '\t') {
            count++;
        }
        str++;
    }
    return count;
}

// Función para dividir una cadena en subcadenas basadas en espacios y tabulaciones
char **ft_split2(const char *str)
{
	int start;
    int end;
    int index;
    int length;
    int delimiter_count;
    int substr_count;

    delimiter_count = count_delimiters(str);
    substr_count = delimiter_count + 1;
    char **result = malloc((substr_count + 1) * sizeof(char *));
    if (result == NULL)
	{
        fprintf(stderr, "Error al asignar memoria\n");
        exit(1);
    }
    start = 0;
    end = 0;
    index = 0;
    length = strlen(str);
    while (end <= length)
	{
        if (str[end] == ' ' || str[end] == '\t' || str[end] == '\0')
		{
            if (end > start)
			{
                result[index] = malloc((end - start + 1) * sizeof(char));
                if (result[index] == NULL)
				{
                    fprintf(stderr, "Error al asignar memoria\n");
                    exit(1);
                }
                strncpy(result[index], str + start, end - start);
                result[index][end - start] = '\0';
                index++;
            }
            start = end + 1;
        }
        end++;
    }

    // Terminar el arreglo de subcadenas con un puntero NULL
    result[index] = NULL;

    return result;
}