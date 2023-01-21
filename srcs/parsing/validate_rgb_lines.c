/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rgb_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:24:25 by jungchoi          #+#    #+#             */
/*   Updated: 2023/01/21 12:24:43 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate(t_game *game, int *arr)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (0 > arr[i] || arr[i] > 255)
			ft_error(game, "rgb value must be between 0 and 255");
	}
}

static int	arr_to_hex(int *arr)
{
	int	hex;

	hex = 256 * 256 * arr[0] + 256 * arr[1] + arr[2];
	return (hex);
}

void	validate_rgb_lines(t_game *game)
{
	validate(game, game->f);
	validate(game, game->c);
	game->f_hex = arr_to_hex(game->f);
	game->c_hex = arr_to_hex(game->c);
	free(game->f);
	free(game->c);
	game->f = NULL;
	game->c = NULL;
}
