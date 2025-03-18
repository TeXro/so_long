/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:14:39 by zzin              #+#    #+#             */
/*   Updated: 2025/03/18 03:49:46 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *tmp_map[] =
{
	"1111111111111",
	"1000000000001",
	"1E000000C0001",
	"1000000000001",
	"1000000P00001",
	"1111111111111"
};

t_game		game;


void	init_map(t_dem dem, char **smap)
{
	game.map_info.height = dem.h;
	game.map_info.width = dem.w;
	game.map_info.map = smap;
}

void init_obj(t_obj *o)
{
	int i;
	o->w = mlx_xpm_file_to_image(game.window_info.mlx, "asset/wall.xpm", &i, &i);
	o->s = mlx_xpm_file_to_image(game.window_info.mlx, "asset/space.xpm", &i, &i);
	o->p = mlx_xpm_file_to_image(game.window_info.mlx, "asset/player.xpm", &i, &i);
	o->e = mlx_xpm_file_to_image(game.window_info.mlx, "asset/exit.xpm", &i, &i);
	o->c = mlx_xpm_file_to_image(game.window_info.mlx, "asset/coin.xpm", &i, &i);
}

int test()
{
    // Clean up resources
    mlx_destroy_window(game.window_info.mlx, game.window_info.win);
    mlx_destroy_display(game.window_info.mlx);
    free(game.window_info.mlx);
    exit(0); // Exit the program
}



// void move(char k, t_game *p)
// {
// 	char **map = game.map_info.map;
// 	mlx_put_image_to_window(game.window_info.mlx, game.window_info.win, obj.s , game.player_info.x, game.player_info.y);
// 	if (k == 'd')
// 		plus(&game.player_info.x, &game.map_info.i);
// 	else if (k == 'a')
// 	{
// 		p->player_info.x -= 64;
// 		p->map_info.i--;
// 	}
// 	else if (k == 'w')
// 	{
// 		p->player_info.y -= 64;
// 		p->map_info.a--;
// 	}
// 	else if (k = 's')
// 	{
// 		plus(&game.player_info.y, &game.map_info.a);
// 	}
// }

// void is_exit(int a, int i)
// {
// 	char **map = game.map_info.map;
// 	if(map[a][i] == 'C')
// 	{
// 		game.coin--;
// 		printf("%d", game.coin);
// 		p->player_info.x += 64;
// 		p->map_info.i++;
// 	}
// 	if(map[a][i] == 'E' && game.coin < 1);
// 	{
// 		exit(0);
// 	}
// }


int key_press(int key, t_game *p)
{
	int i;
	int a;
	char **map;

	map = game.map_info.map;
	a = game.map_info.a;
	i = game.map_info.i;
	if (key == XK_d && map[a][i + 1] != '1')
		right(p);
	else if (key == XK_a && map[a][i - 1] != '1')
		left(p);
	else if (key == XK_w && map[a - 1][i] != '1')
		up(p);
	else if (key == XK_s && map[a + 1][i] != '1')
		down(p);
	if (map[a][i] == 'C')
		p->coin--;
	mlx_put_image_to_window(game.window_info.mlx, game.window_info.win, p->o.p , p->player_info.x, p->player_info.y);
	return 0;
}

void	init_window()
{
	game.window_info.mlx = mlx_init();
	game.window_info.win = mlx_new_window(game.window_info.mlx, 64 * game.map_info.width, 64 * game.map_info.height, "zzin");
	init_obj(&game.o);
	mlx_hook(game.window_info.win, 17, 1L<<17, test, &game);
	mlx_key_hook(game.window_info.win, key_press, &game);
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

char **str_map(t_dem dem, int fd)
{
	int a;
	int i;
	char res;
	char **smap;

	smap = malloc(sizeof(char *) * (dem.h + 1));
	a = 0;
	res = next_byte(fd);
	while (res)
	{
		i = 0;
		smap[a] = malloc(dem.w + 1);
		while (res != '\n')
		{
			if (!res)
				break;
			smap[a][i] = res;
			res = next_byte(fd);
			i++;
		}
		smap[a][i] = '\0';
		res = next_byte(fd);
		a++;
	}
	smap[a] = NULL;
	return smap;
}

void po(char c, int x, int y, t_game *p, int a, int i)
{

	if(c == '1')
		mlx_put_image_to_window(game.window_info.mlx, game.window_info.win, p->o.w , x, y);
	else if(c == '0')
		mlx_put_image_to_window(game.window_info.mlx, game.window_info.win, p->o.s , x, y);
	else if(c == 'E')
		mlx_put_image_to_window(game.window_info.mlx, game.window_info.win, p->o.e , x, y);
	else if(c == 'C')
	{
		p->coin++;
		mlx_put_image_to_window(game.window_info.mlx, game.window_info.win, p->o.c , x, y);
	}
	else if(c == 'P')
	{
		p->player_info.x = x;
		p->player_info.y = y;
		p->map_info.a = a;
		p->map_info.i = i;
		mlx_put_image_to_window(game.window_info.mlx, game.window_info.win, p->o.p , x, y);
	}
	return;
}

void draw(char **smap, t_game *game)
{
	int a;
	int i;
	static int x;
	static int y;

	a = 0;
	while (smap[a])
	{
		i = 0;
		x = 0;
		while (smap[a][i])
		{
			po(smap[a][i], x, y, game, a, i);
			x += 64;
			i++;
		}
		y += 64;
		a++;
	}
	
}

void	init_game(t_dem dem, int fd)
{
	init_map(dem, str_map(dem, fd));
	init_window();
	game.coin = 0;
	draw(game.map_info.map, &game);
	printf("coin>%d\n", game.coin);
}

void	run_game()
{
	mlx_loop(game.window_info.mlx);
}

int	main(int ac, char **av)
{
	int fd;
	int x;
	int y;

	if(ac != 2)
		werr("./so_long <map_name.ber>");
	fd = open(av[1], O_RDONLY);
	if (fd < 0 )
		werr("can't find this map");
	init_game(is_valid(av[1]), fd);
	run_game();
}
