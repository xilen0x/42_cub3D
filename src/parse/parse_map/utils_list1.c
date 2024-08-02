/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:05:03 by castorga          #+#    #+#             */
/*   Updated: 2024/08/02 15:05:05 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_list(t_lmap *lmap)
{
	int	i;

	i = 0;
	while (lmap)
	{
		ft_printf("%s", lmap->content);
		lmap = lmap->next;
		i++;
	}
	ft_printf("\n\n");
	ft_printf("Longitud de la lista: %d\n", i);
}

// void ft_del_one(t_lmap *lst, void (*del)(void*))
// {
//     if (lst)
//     {
//         del((void *)(uintptr_t)lst->content);
//         free(lst);
//     }
// }
