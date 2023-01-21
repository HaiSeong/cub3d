/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture_lines.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:16:30 by jungchoi          #+#    #+#             */
/*   Updated: 2023/01/21 12:24:16 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate(t_game *game, char *texture_file)
{
	int	fd;

	fd = read_file(texture_file);
	if (fd < 0)
		ft_error(game, "cannot open texture file");
	close(fd);
	if (ft_strlen(texture_file) < ft_strlen(".xpm"))
		ft_error(game, "texture file name is too short");
	if (ft_strncmp(texture_file + ft_strlen(texture_file) - 4, ".xpm", 4))
		ft_error(game, "texture file name must end with \'.xpm\'");
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

void	validate_texture_lines(t_game *game)
{
	validate(game, game->texture_no);
	validate(game, game->texture_so);
	validate(game, game->texture_we);
	validate(game, game->texture_ea);
	xpm_file_to_image_texture(game);
	get_data_addr_texture(game);
	if (!game->img_no.image || !game->img_so.image || \
		!game->img_we.image || !game->img_ea.image)
		ft_error(game, "mlx malloc error");
}
