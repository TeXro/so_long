/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:21:10 by zzin              #+#    #+#             */
/*   Updated: 2025/03/25 15:04:11 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line(int fd, int w)
{
	char	c;
	int		i;
	int		h;

	h = 1;
	c = next_byte(fd);
	i = 0;
	while (c)
	{
		if (c == '\n')
		{
			h += 1;
			i = 0;
		}
		if (c == '1')
			i++;
		c = next_byte(fd);
	}
	if (i != w)
		werr("Invalid map");
	return (h);
}

void	is_extra(int fd)
{
	char		c;
	int			pe[2];
	int			coin;

	c = '1';
	pe[0] = 0;
	pe[1] = 0;
	coin = 0;
	while (c)
	{
		if (!(c == '0' || c == '1' || c == 'C'
				|| c == 'P' || c == 'E' || c == '\n'))
			werr("Invalid map");
		if (c == 'P')
			pe[0]++;
		else if (c == 'E')
			pe[1]++;
		else if (c == 'C')
			coin++;
		c = next_byte(fd);
	}
	if (pe[0] != 1 || pe[1] != 1 || coin == 0)
		werr("Invalid map");
}

int	first(int fd)
{
	char	c;
	int		i;

	c = next_byte(fd);
	i = 0;
	while (c && c != '\n')
	{
		i++;
		if (c != '1')
			werr("Invalid map");
		c = next_byte(fd);
	}
	return (i);
}

void	corner(int fd)
{
	char	s;
	char	c;
	int		i;

	c = next_byte(fd);
	i = 0;
	while (c)
	{
		if (i == 0 && c != '1')
			werr("Invalid map");
		s = c;
		c = next_byte(fd);
		if (c == '\n')
		{
			i = 0;
			if (s != '1')
				werr("Invalid map");
			c = next_byte(fd);
		}
		else
			i++;
	}
}

t_dem	is_valid(char *path)
{
	int		fd;
	t_dem	dem;

	fd = open(path, O_RDONLY);
	dem.w = first(fd);
	corner(fd);
	if (dem.w < 3)
		werr("Invalid map");
	fd = open(path, O_RDONLY);
	is_extra(fd);
	fd = open(path, O_RDONLY);
	dem.h = line(fd, dem.w);
	fd = open(path, O_RDONLY);
	dem.w = width(fd);
	if (dem.w < 3)
		exit(0);
	return (dem);
}
