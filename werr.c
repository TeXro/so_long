/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   werr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:39:06 by zzin              #+#    #+#             */
/*   Updated: 2025/03/25 14:28:52 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	werr(char *str)
{
	if (str == NULL)
		exit(0);
	write(2, "Error\n", 6);
	while (*str)
		write(2, str++, 1);
	exit (1);
}

int	xout(t_game *g)
{
	if (g->o.p)
		mlx_destroy_image(g->window_info.mlx, g->o.p);
	if (g->o.e)
		mlx_destroy_image(g->window_info.mlx, g->o.e);
	if (g->o.w)
		mlx_destroy_image(g->window_info.mlx, g->o.w);
	if (g->o.s)
		mlx_destroy_image(g->window_info.mlx, g->o.s);
	if (g->o.c)
		mlx_destroy_image(g->window_info.mlx, g->o.c);
	if (g->window_info.win)
		mlx_destroy_window(g->window_info.mlx, g->window_info.win);
	if (g->window_info.mlx)
		mlx_destroy_display(g->window_info.mlx);
	if (g->window_info.mlx)
		free(g->window_info.mlx);
	if (g->map_info.map)
		f_arr(g->map_info.map);
	exit(0);
}

void	get_p(t_game *g)
{
	int		a;
	int		i;
	char	**map;

	map = g->map_info.map;
	a = 0;
	while (map[a])
	{
		i = 0;
		while (map[a][i])
		{
			if (map[a][i] == 'P')
			{
				g->map_info.a = a;
				g->map_info.i = i;
				return ;
			}
			i++;
		}
		a++;
	}
}

void	flood_fill(t_game *g, char **str, int y, int x)
{
	if (y < 0 || x < 0 || y > g->map_info.height || x > g->map_info.width)
		return ;
	if (str[y][x] == 'E')
		str[y][x] = '1';
	if (str[y][x] == '0' || str[y][x] == 'P' || str[y][x] == 'C')
	{
		str[y][x] = 'F';
		flood_fill(g, str, y + 1, x);
		flood_fill(g, str, y - 1, x);
		flood_fill(g, str, y, x + 1);
		flood_fill(g, str, y, x - 1);
	}
}

void	check_fmap(char **fmap, char **pmap, t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (fmap[i])
	{
		j = 0;
		while (fmap[i][j])
		{
			if (fmap[i][j] == 'C' || fmap[i][j] == 'E')
			{
				mlx_destroy_display(g->window_info.mlx);
				free(g->window_info.mlx);
				f_arr(pmap);
				f_arr(fmap);
				werr("You can't win in this map");
			}
			j++;
		}
		i++;
	}
}
