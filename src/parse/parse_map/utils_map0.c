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

t_map	*ft_lastnode(t_map *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)//Exception has occurred: Signal SIGSEGV: address not mapped to object (fault address: 0x10007fff8003)
		node = node->next;
	return (node);
}

void	ft_add_back(t_map **lst, t_map *new)
{
	t_map	*lastnode;

	if (lst != 0)
	{
		lastnode = ft_lastnode(*lst);
		if (!lastnode)
			*lst = new;
		else
			lastnode->next = new;
	}
}

t_map	*ft_newnode(void *content)
{
	t_map	*new_node;

	new_node = (t_map *)malloc(sizeof(t_map));
	if (new_node)
	{
		new_node->content = content;
		new_node->next = NULL;
	}
	else
		return (NULL);
	return (new_node);
}
