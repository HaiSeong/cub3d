/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:56:58 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/24 13:25:28 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_cub_file(t_game *game, char *file)
{
	int		fd;

	fd = read_file(file);
	if (fd < 0)
		ft_error(game, "failed to open .cub file");
	parsing_texture_lines(game, fd);
	validate_texture_lines(game);
	parsing_rgb_lines(game, fd);
	validate_rgb_lines(game);
	parsing_map_lines(game, fd);
	check_needless_lines(game, fd);
	validate_map(game);
	close(fd);
}
