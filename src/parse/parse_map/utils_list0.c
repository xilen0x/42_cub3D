/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:05:51 by castorga          #+#    #+#             */
/*   Updated: 2024/07/25 19:05:53 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	lst_size(t_lmap *lmap)
{
	unsigned int	i;

	i = 0;
	while (lmap)
	{
		i++;
		lmap = lmap->next;
	}
	return (i);
}

t_lmap	*ft_lastnode(t_lmap *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	ft_add_back(t_lmap **lst, t_lmap *new)
{
	t_lmap	*lastnode;

	if (*lst != 0)
	{
		lastnode = ft_lastnode(*lst);
		if (!lastnode)
			*lst = new;
		else
			lastnode->next = new;
	}
	else
		*lst = new;
}

void	lst_clear(t_lmap **lmap, void (*del)(void*))
{
	t_lmap	*current;
	t_lmap	*next;

	current = *lmap;
	while (current != NULL)
	{
		next = current->next;
		del(current->cont);
		free(current);
		current = next;
	}
	*lmap = NULL;
}

t_lmap	*ft_newnode(char *str)
{
	t_lmap	*new_node;

	new_node = (t_lmap *)malloc(sizeof(t_lmap));
	if (new_node)
	{
		new_node->cont = str;
		new_node->next = NULL;
	}
	else
		return (NULL);
	return (new_node);
}
