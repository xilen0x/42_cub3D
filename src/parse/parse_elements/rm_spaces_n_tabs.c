/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_spaces_n_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:33:27 by castorga          #+#    #+#             */
/*   Updated: 2024/07/16 15:33:29 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void remove_tabs(char **elements)
{
    int i, j, k;

    i = 0;
    while (elements[i])
    {
        j = 0;
        k = 0;
        while (elements[i][j])
        {
            if (elements[i][j] != '\t')
            {
                elements[i][k] = elements[i][j];
                k++;
            }
            j++;
        }
        elements[i][k] = '\0'; // Terminar la cadena
        i++;
    }
}

//elimina espacios antes y después de las comas
void remove_spaces_around_commas(char *line)
{
    int i = 0;
    int j = 0;

    while (line[i])
    {
        // Eliminar espacios adicionales
        if (line[i] == ' ' && (j == 0 || line[i + 1] == ' ' || line[i + 1] == ',' || line[j - 1] == ','))
        {
            i++;
            continue;
        }
        // Eliminar espacio antes de la coma
        if (line[i] == ' ' && line[i + 1] == ',')
        {
            i++;
            continue;
        }
        // Eliminar espacio después de la coma
        if (line[i] == ',' && line[i + 1] == ' ')
        {
            line[j++] = line[i++];
            while (line[i] == ' ')
                i++;
        }
        else
        {
            line[j++] = line[i++];
        }
    }
    // Eliminar espacios al final de la línea
    while (j > 0 && line[j - 2] == ' ')
        j--;

    line[j] = '\0';
}
