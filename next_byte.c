/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_byte.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:12:58 by zzin              #+#    #+#             */
/*   Updated: 2025/03/18 14:56:35 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	next_byte(int fd)
{
	char	byte;
	int		rb;

	rb = read(fd, &byte, 1);
	if (rb == 0)
		return ('\0');
	return (byte);
}
