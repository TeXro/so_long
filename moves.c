/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:14:37 by zzin              #+#    #+#             */
/*   Updated: 2025/03/18 03:46:44 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void spawn(t_game *g)
{
	mlx_put_image_to_window(g->window_info.mlx, g->window_info.win, g->o.s , g->player_info.x, g->player_info.y);
}

void right(t_game *g)
{
	spawn(g);
	g->player_info.x += 64;
	g->map_info.i += 1;
}

void left(t_game *g)
{
	printf("%d\n", g->coin);
	if (g->map_info.map[g->map_info.a][g->map_info.i - 1] == 'E')
	{
		if (g->coin < 1)
			exit(0);
		else
			return ;
	}
	spawn(g);
	g->player_info.x -= 64;
	g->map_info.i -= 1;
}

void up(t_game *g)
{
	spawn(g);
	g->player_info.y -= 64;
	g->map_info.a -= 1;
}

void down(t_game *g)
{
	spawn(g);
	g->player_info.y += 64;
	g->map_info.a += 1;
}
