/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:48:24 by jungchoi          #+#    #+#             */
/*   Updated: 2023/01/25 12:06:24 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture_image(t_game *game)
{
	xpm_file_to_image_texture(game);
	get_data_addr_texture(game);
	if (!game->img_no.image || !game->img_so.image || \
		!game->img_we.image || !game->img_ea.image)
		ft_error(game, "mlx malloc error");
}

void	xpm_file_to_image_texture(t_game *game)
{
	int	w;
	int	h;

	game->img_no.image = mlx_xpm_file_to_image(game->mlx, \
		game->texture_no, &w, &h);
	game->img_so.image = mlx_xpm_file_to_image(game->mlx, \
		game->texture_so, &w, &h);
	game->img_we.image = mlx_xpm_file_to_image(game->mlx, \
		game->texture_we, &w, &h);
	game->img_ea.image = mlx_xpm_file_to_image(game->mlx, \
		game->texture_ea, &w, &h);
	if (game->img_no.image == NULL || game->img_so.image == NULL \
		|| game->img_ea.image == NULL || game->img_we.image == NULL)
		ft_error(game, "texture image has no value");
}

void	get_data_addr_texture(t_game *game)
{
	game->img_no.buffer = (int *)mlx_get_data_addr(game->img_no.image, \
		&(game->img_no.pixel_bits), \
		&(game->img_no.line_bytes), &(game->img_no.endian));
	game->img_so.buffer = (int *)mlx_get_data_addr(game->img_so.image, \
		&(game->img_so.pixel_bits), \
		&(game->img_so.line_bytes), &(game->img_so.endian));
	game->img_we.buffer = (int *)mlx_get_data_addr(game->img_we.image, \
		&(game->img_we.pixel_bits), \
		&(game->img_we.line_bytes), &(game->img_we.endian));
	game->img_ea.buffer = (int *)mlx_get_data_addr(game->img_ea.image, \
		&(game->img_ea.pixel_bits), \
		&(game->img_ea.line_bytes), &(game->img_ea.endian));
}
