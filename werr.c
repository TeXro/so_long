/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   werr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:39:06 by zzin              #+#    #+#             */
/*   Updated: 2025/03/14 03:14:17 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	werr(char *str)
{
	write(2, "Error\n", 6);
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	exit (1);
}