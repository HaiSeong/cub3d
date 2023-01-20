/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:42:45 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/19 19:41:02 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_struct(t_game *game, t_img *img)
{
	int i;

	game->img = img;
	game->line = NULL;
	game->map = NULL;
	game->texture_no = NULL;
	game->texture_so = NULL;
	game->texture_we = NULL;
	game->texture_ea = NULL;
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

	//init temp
	game->temp = (int **)malloc(sizeof(int *) * WIN_HEIGHT);
	if (game->temp == NULL)
		ft_error(game, "malloc error");
	i = -1;
	while (++i < WIN_HEIGHT)
	{
		game->temp[i] = (int *)malloc(sizeof(int) * WIN_WIDTH);
		if (game->temp[i] == NULL)
			ft_error(game, "malloc error");
		ft_bzero(game->temp[i], WIN_WIDTH);
	}
	//init temp

	//init texture
	i = -1;
	while (++i < 4)
	{
		game->texture[i] = (int *)malloc(sizeof(int) * PIXEL * PIXEL);
		if (game->texture[i] == NULL)
			ft_error(game, "malloc error");
		ft_bzero(game->texture[i], sizeof(int) * PIXEL * PIXEL);
	}
	//init texture

	game->mlx = NULL;
	game->window = NULL;
	img->image = NULL;
}
