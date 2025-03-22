/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:14:37 by zzin              #+#    #+#             */
/*   Updated: 2025/03/22 01:47:57 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right(t_game *g)
{
	if (g->map_info.map[g->map_info.a][g->map_info.i + 1] == 'C')
	{
		g->map_info.map[g->map_info.a][g->map_info.i + 1] = '0';
		g->coin--;
	}
	if (g->map_info.map[g->map_info.a][g->map_info.i + 1] == 'E')
	{
		if (g->coin < 1)
		{
			print_move(++g->move_count);
			out(g, 0);
		}
		else
			return ;
	}
	print_move(++g->move_count);
	spawn(g);
	g->player_info.x += 64;
	g->map_info.i += 1;
}

void	left(t_game *g)
{
	if (g->map_info.map[g->map_info.a][g->map_info.i - 1] == 'C')
	{
		g->map_info.map[g->map_info.a][g->map_info.i - 1] = '0';
		g->coin--;
	}
	if (g->map_info.map[g->map_info.a][g->map_info.i - 1] == 'E')
	{
		if (g->coin < 1)
		{
			print_move(++g->move_count);
			out(g, 0);
		}
		else
			return ;
	}
	print_move(++g->move_count);
	spawn(g);
	g->player_info.x -= 64;
	g->map_info.i -= 1;
}

void	up(t_game *g)
{
	if (g->map_info.map[g->map_info.a - 1][g->map_info.i] == 'C')
	{
		g->map_info.map[g->map_info.a - 1][g->map_info.i] = '0';
		g->coin--;
	}
	if (g->map_info.map[g->map_info.a - 1][g->map_info.i] == 'E')
	{
		if (g->coin < 1)
		{
			print_move(++g->move_count);
			out(g, 0);
		}
		else
			return ;
	}
	print_move(++g->move_count);
	spawn(g);
	g->player_info.y -= 64;
	g->map_info.a -= 1;
}

void	down(t_game *g)
{
	if (g->map_info.map[g->map_info.a + 1][g->map_info.i] == 'C')
	{
		g->map_info.map[g->map_info.a + 1][g->map_info.i] = '0';
		g->coin--;
	}
	if (g->map_info.map[g->map_info.a + 1][g->map_info.i] == 'E')
	{
		if (g->coin < 1)
		{
			print_move(++g->move_count);
			out(g, 0);
		}
		else
			return ;
	}
	print_move(++g->move_count);
	spawn(g);
	g->player_info.y += 64;
	g->map_info.a += 1;
}
