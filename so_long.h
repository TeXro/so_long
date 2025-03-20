/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:16:33 by zzin              #+#    #+#             */
/*   Updated: 2025/03/20 03:47:58 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct obj
{
	void	*p;
	void	*w;
	void	*s;
	void	*e;
	void	*c;
}	t_obj;

typedef struct dem
{
	int	h;
	int	w;
}	t_dem;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	int		height;
	int		width;
	int		a;
	int		i;
	char	**map;
}	t_map;

typedef struct s_game
{
	int			coin;
	t_player	player_info;
	t_obj		o;
	t_window	window_info;
	t_map		map_info;
}	t_game;
void	flood_fill(t_game *g, char **str, int y, int x);
void	get_p(t_game *g);
void	check_fmap(char **fmap, char **pmap, t_game *g);
int		width(int fd);
char	next_byte(int fd);
t_dem	is_valid(char *path);
void	werr(char *str);
void	init_obj(t_game *g);
void	spawn(t_game *g);
void	right(t_game *g);
void	left(t_game *g);
void	up(t_game *g);
void	down(t_game *g);
void	f_arr(char **arr);
int		out(t_game *g, int ex);
void	spawn(t_game *g);
char	**str_map(t_dem dem, int fd);
int		key_press(int key, t_game *g);
void	po(char c, int x, int y, t_game *p);
void	draw(char **smap, t_game *g);

#endif