/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_play_direction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:34:31 by jungchoi          #+#    #+#             */
/*   Updated: 2023/01/21 16:42:10 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_play_direction(t_game *game, char direction, int i, int j)
{
	game->pos_x = (double) j + 0.5;
	game->pos_y = (double) i + 0.5;
	if (direction == 'N')
	{
		game->dir_y = -1;
		game->plane_x = 0.66;
	}
	else if (direction == 'S')
	{
		game->dir_y = 1;
		game->plane_x = -0.66;
	}
	else if (direction == 'W')
	{
		game->dir_x = -1;
		game->plane_y = -0.66;
	}
	else if (direction == 'E')
	{
		game->dir_x = 1;
		game->plane_y = 0.66;
	}
}
