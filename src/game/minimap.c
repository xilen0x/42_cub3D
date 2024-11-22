/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:25:17 by castorga          #+#    #+#             */
/*   Updated: 2024/11/22 14:25:19 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void Minimap_Init(Minimap* minimap, int x, int y, int width, int height) {
//     // Configurar el área de renderizado (viewport)
//     minimap->viewport.x = x;
//     minimap->viewport.y = y;
//     minimap->viewport.w = width;
//     minimap->viewport.h = height;

//     // Inicializar el área de recorte como igual al viewport
//     minimap->clipArea = minimap->viewport;

//     // Inicializar la textura
//     minimap->texture = NULL; // Se asignará después si es necesario
// }

// int minimap_Init(t_game *g, int x, int y, int width, int height) {
//     g->minimap.x = x;
//     g->minimap.y = y;
//     g->minimap.width = width;
//     g->minimap.height = height;

//     // Utilizar img2 como base para el minimapa
//     g->minimap.img_ptr = g->img2.img_ptr;  // Usamos la misma imagen que img2
//     g->minimap.addr = g->img2.addr;        // Usamos los mismos datos de la imagen que img2
//     g->minimap.bpp = g->img2.bpp;          // Bits por píxel de img2
//     g->minimap.line_len = g->img2.line_len; // Longitud de línea de img2
//     g->minimap.endian = g->img2.endian;    // Endian de img2

//     return 0;
// }


// void minimap_Render(t_game *g)
// {
//     // Aquí puedes agregar procesamiento para pintar solo el área relevante del mapa, si es necesario.
//     mlx_put_image_to_window(g->mlx, g->win, g->minimap.img_ptr, g->minimap.x, g->minimap.y);
// }

// void Minimap_Render(Minimap* minimap, SDL_Renderer* renderer, SDL_Texture* mapTexture) {
//     // Establecer la región de recorte
//     SDL_RenderSetClipRect(renderer, &(minimap->clipArea));

//     // Dibujar la textura del mapa dentro del área de recorte
//     SDL_RenderCopy(renderer, mapTexture, NULL, &(minimap->viewport));

//     // Restaurar el recorte a su estado predeterminado
//     SDL_RenderSetClipRect(renderer, NULL);
// }

// /*Walls minimap(part2)*/
// void	box_to_image(t_img *img, int x, int y, int color)
// {
// 	int	x0;
// 	int	y0;

// 	x0 = x;
// 	y0 = y;
// 	while (y < y0 + 32)
// 	{
// 		x = x0;
// 		while (x < x0 + 32)
// 		{
// 			set_pixel_to_image(img, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }
// /*Walls minimap*/
// void	map_to_image(t_img *img, t_map *map, int color)
// {
// 	int	x;
// 	int	y;

//     y = 0;
// 	while (y < map->mapH)
// 	{
// 		x = 0;
// 		while (x < map->mapW)
// 		{
// 			if (map->map[y * map->mapW + x] == '1')
// 				box_to_image(img, x * 32, y * 32, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }
