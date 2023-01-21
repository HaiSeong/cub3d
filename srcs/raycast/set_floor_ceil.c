/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_floor_ceil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:28:12 by jungchoi          #+#    #+#             */
/*   Updated: 2023/01/21 16:31:18 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_floor(t_game *game)
{
	int	x;
	int	y;
	int	pixel;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			pixel = (y * game->img->line_bytes / 4) + x;
			game->img->buffer[pixel] = game->c_hex;
		}
		y++;
	}
}

void	set_ceil(t_game *game)
{
	int	x;
	int	y;
	int	pixel;

	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel = (y * game->img->line_bytes / 4) + x;
			game->img->buffer[pixel] = game->f_hex;
			x++;
		}
		y++;
	}
}
