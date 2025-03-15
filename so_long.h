/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:16:33 by zzin              #+#    #+#             */
/*   Updated: 2025/03/15 06:01:36 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

typedef struct dem
{
	int h;
	int w;
} t_dem;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_player
{
	int		x;
	int 	y;
	void	*texture;
}	t_player;

typedef struct s_map
{
	int height;
	int width;
	char **map;
}	t_map;

typedef struct s_game
{
	t_player player_info;
	t_window window_info;
	t_map	 map_info;
}	t_game;
char	next_byte(int fd);
t_dem	is_valid(char *path);
void	werr(char *str);

#endif