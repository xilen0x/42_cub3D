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

void remove_tabs_and_spaces(char **lines)
{
    int i, j, k;

    i = 0;
    while (lines[i])
    {
        j = 0;
        k = 0;
        while (lines[i][j])
        {
            if (lines[i][j] != '\t' && lines[i][j] != ' ')
            {
                lines[i][k] = lines[i][j];
                k++;
            }
            j++;
        }
        while (k > 0 && (lines[i][k - 1] == ' ' || lines[i][k - 1] == '\t'))
            k--;
        lines[i][k] = '\0';
        i++;
    }
}


// void remove_tabs(char **line)
// {
//     int i, j, k;

//     i = 0;
//     while (line[i])
//     {
//         j = 0;
//         k = 0;
//         while (line[i][j])
//         {
//             if ((line[i][j] != '\t'))
//             {
//                 line[i][k] = line[i][j];
//                 k++;
//             }
//             j++;
//         }
//         line[i][k] = '\0';
//         i++;
//     }
// }

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
   while ((j > 0) && ((line[j - 2] == ' ') || (line[j - 2] == '\t')))
        j--;
    line[j] = '\0';
}
