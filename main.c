/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:14:39 by zzin              #+#    #+#             */
/*   Updated: 2025/03/22 23:18:56 by zzin             ###   ########.fr       */
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

void	init_window(int fd, t_dem dem, char **pmap)
{
	char	**fmap;
	int		x;
	int		y;

	g_game.window_info.mlx = mlx_init();
	mlx_get_screen_size(g_game.window_info.mlx, &x, &y);
	if ((dem.w * 64) > x || (dem.h * 64) > y)
	{
		mlx_destroy_display(g_game.window_info.mlx);
		free(g_game.window_info.mlx);
		f_arr(pmap);
		werr("map bigger than screen size");
	}
	fmap = str_map(dem, fd);
	flood_fill(&g_game, fmap, g_game.map_info.a, g_game.map_info.i);
	check_fmap(fmap, pmap, &g_game);
	f_arr(fmap);
	g_game.window_info.win = mlx_new_window(g_game.window_info.mlx,
			64 * g_game.map_info.width, 64 * g_game.map_info.height, "so_long");
	init_obj(&g_game);
	mlx_hook(g_game.window_info.win, 17, 1L << 17, out, &g_game);
	mlx_key_hook (g_game.window_info.win, key_press, &g_game);
}

void	init_game(t_dem dem, char *path)
{
	int		fd;
	char	**pmap;

	fd = open(path, O_RDONLY);
	pmap = str_map(dem, fd);
	init_map(dem, pmap);
	get_p(&g_game);
	fd = open(path, O_RDONLY);
	init_window(fd, dem, pmap);
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
	int	i;

	if (ac != 2)
		werr("./so_long <map_name.ber>");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		werr("can't find this map");
	i = 0;
	while (av[1][i] != '.')
		i++;
	if (av[1][i++] == '.')
		if (av[1][i++] == 'b')
			if (av[1][i++] == 'e')
				if (av[1][i++] == 'r')
					if (av[1][i++] == '\0')
						i = 0;
	if (i)
		werr("game accept only (.ber) maps");
	g_game.move_count = 0;
	init_game(is_valid(av[1]), av[1]);
	run_game();
}
