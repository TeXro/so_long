/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:21:10 by zzin              #+#    #+#             */
/*   Updated: 2025/03/14 13:55:56 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int corner(char *path)
// {
// 	int fd;
// 	int i;
// 	int c;

// 	fd = open(path, O_RDONLY);
// 	i = 0;
// 	c = 2;
// 	while (c)
// 	{
// 		if(i == 0)
// 		{
// 			while (c == '1')
// 				c = next_byte(fd);
// 		}
		
		
// 	}
	
// }

int width(int fd)
{
	int h;
	int i;
	char c;

	c = 2;
	h = 0;
	i = 0;
	while (c)
	{
		c = next_byte(fd);
		if (c == '\n' || c == '\0')
		{
			if (h && h != i)
				werr("Invalid map");
			h = i;
			i = 0;
		}
		if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
			i++;
	}
	return (h);
}

void line(int fd, int w)
{
	char c;
	int i;

	c = next_byte(fd);
	i = 0;
	while(c)
	{
		if (c == '\n')
			i = 0;
		if (c == '1')
			i++;
		c = next_byte(fd);
	}
	if (i != w)
		werr("!");
}
void is_extra(int fd)
{
	char	c;
	int		total;

	c = '1';
	total = 0;
	while (c)
	{
		if (!(c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'E' || c == '\n'))
			exit(0);
		else if(c == 'C' || c == 'P' || c == 'E')
			total++;
		c = next_byte(fd);
	}
	if (total != 3)
		exit(0);
}

int first(int fd)
{
	char c;
	int i;

	c = next_byte(fd);
	i = 0;
	while (c && c != '\n')
	{
		i++;
		if(c == '0')
			werr("C");
		c = next_byte(fd);
	}
	return i;
}

void corner(int fd)
{
	char s;
	char c;
	int i;

	c = next_byte(fd);
	i = 0;
	while (c)
	{
		if(i == 0 && c != '1')
			werr("cor!!");
		s = c;
		c = next_byte(fd);
		if (c == '\n')
		{
			i = 0;
			if (s != '1')
				werr("corner!!");
			c = next_byte(fd);
		}
		else
			i++;
	}
}

int is_valid(char *path)
{
	int fd;
	int w;

	fd = open(path, O_RDONLY);
	w = first(fd);
	corner(fd);
	if(w < 3)
		werr("3");
	fd = open(path, O_RDONLY);
	is_extra(fd);
	fd = open(path, O_RDONLY);
	line(fd, w);
	fd = open(path, O_RDONLY);
	w = width(fd);
	if (w < 3)
		exit(0);
	return w;
}
