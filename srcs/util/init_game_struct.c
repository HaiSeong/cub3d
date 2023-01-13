/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:42:45 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/13 17:47:19 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_struct(t_game *game)
{
	game->texture_no = NULL;
	game->texture_so = NULL;
	game->texture_we = NULL;
	game->texture_ea = NULL;
}