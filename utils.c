/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:37:19 by zzin              #+#    #+#             */
/*   Updated: 2025/03/22 01:06:13 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**str_map(t_dem dem, int fd)
{
	int			a;
	int			i;
	char		res;
	char		**smap;

	smap = malloc(sizeof(char *) * (dem.h + 1));
	res = next_byte(fd);
	a = 0;
	while (res)
	{
		i = 0;
		smap[a] = malloc(dem.w + 1);
		while (res != '\n')
		{
			if (!res)
				break ;
			smap[a][i++] = res;
			res = next_byte(fd);
		}
		smap[a][i] = '\0';
		res = next_byte(fd);
		a++;
	}
	smap[a] = NULL;
	return (smap);
}

int	key_press(int key, t_game *g)
{
	int		i;
	int		a;
	char	**map;

	map = g->map_info.map;
	a = g->map_info.a;
	i = g->map_info.i;
	if (key == XK_d && map[a][i + 1] != '1')
		right(g);
	else if (key == XK_a && map[a][i - 1] != '1')
		left(g);
	else if (key == XK_w && map[a - 1][i] != '1')
		up(g);
	else if (key == XK_s && map[a + 1][i] != '1')
		down(g);
	else if (key == XK_Escape)
		out(g, 0);
	mlx_put_image_to_window(g->window_info.mlx,
		g->window_info.win, g->o.p, g->player_info.x, g->player_info.y);
	return (0);
}

void	po(char c, int x, int y, t_game *g)
{
	if (c == '1')
		mlx_put_image_to_window(g->window_info.mlx,
			g->window_info.win, g->o.w, x, y);
	else if (c == '0')
		mlx_put_image_to_window(g->window_info.mlx,
			g->window_info.win, g->o.s, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(g->window_info.mlx,
			g->window_info.win, g->o.e, x, y);
	else if (c == 'C')
	{
		g->coin++;
		mlx_put_image_to_window(g->window_info.mlx,
			g->window_info.win, g->o.c, x, y);
	}
	else if (c == 'P')
	{
		g->player_info.x = x;
		g->player_info.y = y;
		mlx_put_image_to_window(g->window_info.mlx,
			g->window_info.win, g->o.p, x, y);
	}
}

void	draw(char **smap, t_game *g)
{
	int	x;
	int	y;
	int	a;
	int	i;

	y = 0;
	a = 0;
	while (smap[a])
	{
		i = 0;
		x = 0;
		while (smap[a][i])
		{
			po (smap[a][i], x, y, g);
			x += 64;
			i++;
		}
		y += 64;
		a++;
	}
}

void	init_obj(t_game *g)
{
	int	i;

	g->o.w = mlx_xpm_file_to_image(g->window_info.mlx,
			"asset/wall.xpm", &i, &i);
	g->o.s = mlx_xpm_file_to_image(g->window_info.mlx,
			"asset/space.xpm", &i, &i);
	g->o.p = mlx_xpm_file_to_image(g->window_info.mlx,
			"asset/player.xpm", &i, &i);
	g->o.e = mlx_xpm_file_to_image(g->window_info.mlx,
			"asset/exit.xpm", &i, &i);
	g->o.c = mlx_xpm_file_to_image(g->window_info.mlx,
			"asset/coin.xpm", &i, &i);
	if (!g->o.w || !g->o.s || !g->o.p || !g->o.e || !g->o.c)
		out(g, 1);
}
