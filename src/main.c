#include "cub3d.h"

		// ft_printf("\nAnchura mapa(w): %d\n", map.w);
		// ft_printf("Altura mapa(h): %d\n\n", map.h);
		// ft_printf("Valor x: %d\n", map.x);
		// ft_printf("Valor y: %d\n\n", map.y);
		// ft_printf("NO: %s\n", elem.no_path);
		// ft_printf("SO: %s\n", elem.so_path);
		// ft_printf("EA: %s\n", elem.ea_path);
		// ft_printf("WE: %s\n", elem.we_path);
		// ft_printf("F: %d\n", colors.f);
		// ft_printf("C: %d\n\n", colors.c);
		// ft_printf("Posición del jugador(y, x): %d,%d\n\n", map.y, map.x);
		// ft_printf("Orientación del jugador: %c\n\n", map.matrix[map.y][map.x]);
int img2_init(t_game *g)
{
	g->img2.w = PX2 * g->map.mapW;
	g->img2.h = PX2 * g->map.mapH;
	// g->img2.w = WINX / 5;
	// g->img2.h = WINY / 5;
	g->img2.img_ptr = mlx_new_image(g->mlx, WINX / 5, WINY / 5);
	if (!g->img2.img_ptr)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		return (1);
	}
	g->img2.addr = mlx_get_data_addr(g->img2.img_ptr, &(g->img2.bpp), &(g->img2.line_len), &(g->img2.endian));
	if (!g->img2.addr)
	{
		mlx_destroy_image(g->mlx, g->img2.img_ptr);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		return (1);
	}
	return (0);
}
int img_init(t_game *g)
{
	g->img3.w = WINX;
	g->img3.h = WINY;
	g->img3.img_ptr = mlx_new_image(g->mlx, WINX, WINY);
	if (!g->img3.img_ptr)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		return (1);
	}
	g->img3.addr = mlx_get_data_addr(g->img3.img_ptr, &(g->img3.bpp), &(g->img3.line_len), &(g->img3.endian));
	if (!g->img3.addr)
	{
		mlx_destroy_image(g->mlx, g->img3.img_ptr);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		return (1);
	}
	return (0);
}
// int minimap_init(t_game *g)
// {
// 	g->img3.w = WINX;
// 	g->img3.h = WINY;
// 	g->img_mini.img_ptr = mlx_new_image(g->mlx, WINX / 5, WINY / 5);
// 	if (!g->img_mini.img_ptr)
// 	{
// 		mlx_destroy_display(g->mlx);
// 		free(g->mlx);
// 		return (1);
// 	}
// 	g->img_mini.addr = mlx_get_data_addr(g->img_mini.img_ptr, &(g->img_mini.bpp), &(g->img_mini.line_len), &(g->img_mini.endian));
// 	if (!g->img_mini.addr)
// 	{
// 		mlx_destroy_image(g->mlx, g->img_mini.img_ptr);
// 		mlx_destroy_display(g->mlx);
// 		free(g->mlx);
// 		return (1);
// 	}
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	t_elem		elem;
	t_map_parse	map_parse;
	t_lmap		*lmap;
	t_game		g;


	lmap = NULL;
	if (argc == 2)
	{
		set_sine(g.si);
		set_cosine(g.co);
		set_tan(g.ta);

		elem.av = argv;
		init_values(&elem, &g.cols, &map_parse, elem.av);
		parsing(&elem, &g.cols, &map_parse, &lmap);
		load_map(&g, &map_parse);
		g.mlx = mlx_init();
		if (!g.mlx)
			ft_errors("Error initializing mlx\n");
		g.win = mlx_new_window(g.mlx, WINX, WINY, "Cub3D");
		img2_init(&g);
		img_init(&g);
		// minimap_init(&g);
		set_player(&g.map, &g.player);
		set_image(&g, g.cols);
		set_rays(&g);
		// mlx_clear_window(g.mlx, g.win);
		mlx_put_image_to_window(g.mlx, g.win, g.img3.img_ptr, 0, 0);
		mlx_put_image_to_window(g.mlx, g.win, g.img2.img_ptr, 0, 0);
		// mlx_put_image_to_window(g.mlx, g.win, g.img_mini.img_ptr, 0, 0);
		mlx_hook(g.win, X_EVENT_KEY_PRESS, 0, &press_key, &g);
		mlx_hook(g.win, X_EVENT_KEY_EXIT, 1, &exit_game, &g);
		mlx_loop(g.mlx);
	}
	else
		ft_errors("Invalid number of arguments\n");
	lst_clear(&lmap, &free);
	free_element_struct(&elem);
	free_matrix(map_parse.matrix, map_parse.h);
	return (0);
}
