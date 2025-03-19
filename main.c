/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:14:39 by zzin              #+#    #+#             */
/*   Updated: 2025/03/18 20:31:14 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	g_game;

void	init_map(t_dem dem, char **smap)
{
	g_game.map_info.height = dem.h;
	g_game.map_info.width = dem.w;
	g_game.map_info.map = smap;
}

void	init_window(void)
{
	g_game.window_info.mlx = mlx_init();
	g_game.window_info.win = mlx_new_window(g_game.window_info.mlx,
			64 * g_game.map_info.width, 64 * g_game.map_info.height, "so_long");
	init_obj(&g_game);
	mlx_hook(g_game.window_info.win, 17, 1L << 17, out, &g_game);
	mlx_key_hook (g_game.window_info.win, key_press, &g_game);
}

void	init_game(t_dem dem, char *path)
{
	int		fd;
	char	**fmap;
	char	**pmap;

	fd = open(path, O_RDONLY);
	fmap = str_map(dem, fd);
	fd = open(path, O_RDONLY);
	pmap = str_map(dem, fd);
	init_map(dem, pmap);
	get_p(&g_game);
	flood_fill(&g_game, fmap, g_game.map_info.a, g_game.map_info.i);
	check_fmap(fmap, pmap);
	f_arr(fmap);
	init_window();
	g_game.coin = 0;
	draw(g_game.map_info.map, &g_game);
}

void	run_game(void)
{
	mlx_loop(g_game.window_info.mlx);
}

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		werr("./so_long <map_name.ber>");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		werr("can't find this map");
	init_game(is_valid(av[1]), av[1]);
	run_game();
}
