/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:05:07 by jungchoi          #+#    #+#             */
/*   Updated: 2023/01/21 14:18:25 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	press_key(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		press_ws(game, 1);
	else if (keycode == KEY_A)
		press_ad(game, -1);
	else if (keycode == KEY_S)
		press_ws(game, -1);
	else if (keycode == KEY_D)
		press_ad(game, 1);
	else if (keycode == KEY_LEFT)
		press_lr(game, -1);
	else if (keycode == KEY_RIGHT)
		press_lr(game, 1);
	else if (keycode == KEY_ESC)
		click_destroy(game);
	raycasting(game);
	return (0);
}

void	press_ws(t_game *game, int flag)
{
	double	move_x;
	double	move_y;

	move_x = game->pos_x + game->dir_x * (double)SPEED * flag;
	move_y = game->pos_y + game->dir_y * (double)SPEED * flag;
	if (game->map[(int)move_y][(int)move_x] == '1')
		return ;
	game->pos_x = move_x;
	game->pos_y = move_y;
}

void	press_ad(t_game *game, int flag)
{
	double	move_x;
	double	move_y;

	move_x = game->pos_x + game->plane_x * (double)SPEED * flag;
	move_y = game->pos_y + game->plane_y * (double)SPEED * flag;
	if (game->map[(int)move_y][(int)move_x] == '1')
		return ;
	game->pos_x = move_x;
	game->pos_y = move_y;
}

void	press_lr(t_game *game, int flag)
{
	double	cp_dir_x;
	double	cp_plane_x;
	double	theta;

	cp_dir_x = game->dir_x;
	cp_plane_x = game->plane_x;
	theta = (double)SPEED * flag;
	game->dir_x = game->dir_x * cos(theta) - game->dir_y * sin(theta);
	game->dir_y = cp_dir_x * sin(theta) + game->dir_y * cos(theta);
	game->plane_x = game->plane_x * cos(theta) - game->plane_y * sin(theta);
	game->plane_y = cp_plane_x * sin(theta) + game->plane_y * cos(theta);
}

int	click_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	ft_free_game(game);
	ft_destroy_images(game);
	exit(EXIT_SUCCESS);
}
