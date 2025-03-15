/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:14:39 by zzin              #+#    #+#             */
/*   Updated: 2025/03/15 10:47:01 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char *tmp_map[] =
// {
// 	"1111111111111",
// 	"1000000000001",
// 	"1E000000C0001",
// 	"1000000000001",
// 	"1000000P00001",
// 	"1111111111111"
// };

t_game game;

void	init_map(t_dem dem)
{
	// game.map_info = load_map(path);
	game.map_info.height = dem.h;
	game.map_info.width = dem.w;
	// game.map_info.map = tmp_map;
}

int test()
{
    // Clean up resources
    mlx_destroy_window(game.window_info.mlx, game.window_info.win);
    mlx_destroy_display(game.window_info.mlx);
    free(game.window_info.mlx);
    exit(0); // Exit the program
}

void	init_window()
{
	game.window_info.mlx = mlx_init();
	game.window_info.win = mlx_new_window(game.window_info.mlx, 64 * game.map_info.width, 64 * game.map_info.height, "zzin");
	mlx_hook(game.window_info.win, 17, 1L<<0, test, &game);
}

// typedef struct s_object
// {
// 	void *o;
// 	int z;
// 	int x;
// 	int y;

// 	o = mlx_xpm_file_to_image(game.window_info.mlx, "./asset/wall.xpm", &z, &z);
// 	// mlx_put_image_to_window(game.window_info.mlx, game.window_info.win, o, 0, 0);
// }	t_object;
void	init_game(t_dem dem)
{
	init_map(dem);
	init_window();
}

void	run_game()
{
	mlx_loop(game.window_info.mlx);
}

void obj(int x, int y, char c)
{
	int		i;
	void	*a;

	if (c == 'P')
		a = mlx_xpm_file_to_image(game.window_info.mlx, "asset/player.xpm", &i, &i);
	else if (c == 'E')
		a = mlx_xpm_file_to_image(game.window_info.mlx, "asset/exit.xpm", &i, &i);
	else if (c == '1')
		a = mlx_xpm_file_to_image(game.window_info.mlx, "asset/wall.xpm", &i, &i);
	else if (c == '0')
		a = mlx_xpm_file_to_image(game.window_info.mlx, "asset/space.xpm", &i, &i);
	else if (c == 'C')
		a = mlx_xpm_file_to_image(game.window_info.mlx, "asset/exit.xpm", &i, &i);
	mlx_put_image_to_window(game.window_info.mlx, game.window_info.win, a, x, y);
	
}

int	main(int ac, char **av)
{
	int fd;
	int x;
	int y;
	char res;

	if(ac != 2)
		werr("./so_long <map_name.ber>");
	fd = open(av[1], O_RDONLY);
	if (fd < 0 )
		werr("can't find this map");
	res = next_byte(fd);
	init_game(is_valid(av[1]));
	x = 0;
	y = 0;
	while (res)
	{
		// sleep(1);
		if (res == '\n')
		{
			y += 64;
			x = 0;
		}else
		{
			obj(x, y, res);
			x += 64;
		}
		res = next_byte(fd);
		
	}
	
	run_game();
}
