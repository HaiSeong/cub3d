/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:42:45 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/13 18:35:44 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_struct(t_game *game)
{
	int i;

	game->line = NULL;
	game->map = NULL;
	game->texture_no = NULL;
	game->texture_so = NULL;
	game->texture_we = NULL;
	game->texture_ea = NULL;
	game->F = (int *)malloc(sizeof(int) * 3);
	game->C = (int *)malloc(sizeof(int) * 3);
	if (game->F == NULL || game->C == NULL)
		ft_error(game, "malloc error");
	i = -1;
	while (++i < 3)
	{
		game->F[i] = -1;
		game->C[i] = -1;
	}
}