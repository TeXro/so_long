/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:24:36 by zzin              #+#    #+#             */
/*   Updated: 2025/03/18 20:30:03 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	width(int fd)
{
	int		w;
	int		i;
	char	c;

	c = 2;
	w = 0;
	i = 0;
	while (c)
	{
		c = next_byte(fd);
		if (c == '\n' || c == '\0')
		{
			if (w && w != i)
				werr("Invalid map");
			w = i;
			i = 0;
		}
		if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
			i++;
	}
	return (w);
}

void	spawn(t_game *g)
{
	mlx_put_image_to_window(g->window_info.mlx, g->window_info.win,
		g->o.s, g->player_info.x, g->player_info.y);
}

void	f_arr(char **arr)
{
	int	a;

	a = 0;
	while (arr[a])
	{
		free(arr[a]);
		a++;
	}
	free(arr);
}

int	out(t_game *g)
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
	mlx_destroy_window(g->window_info.mlx, g->window_info.win);
	mlx_destroy_display(g->window_info.mlx);
	f_arr(g->map_info.map);
	free(g->window_info.mlx);
	exit(0);
}
