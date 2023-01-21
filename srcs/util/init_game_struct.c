/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:42:45 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/21 13:59:45 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_struct(t_game *game, t_img *img)
{
	int	i;

	ft_memset(game, 0, sizeof(t_game));
	game->img = img;
	game->f = (int *)malloc(sizeof(int) * 3);
	game->c = (int *)malloc(sizeof(int) * 3);
	if (game->f == NULL || game->c == NULL)
		ft_error(game, "malloc error");
	i = -1;
	while (++i < 3)
	{
		game->f[i] = -1;
		game->c[i] = -1;
	}
}
