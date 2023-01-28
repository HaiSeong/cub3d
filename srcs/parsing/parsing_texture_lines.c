/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_lines.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:59:53 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/28 22:04:06 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_wrong_field_number(t_game *game, char **strs)
{
	ft_free_strs(strs);
	ft_error(game, "texture property must have 2 fields");
}

void	assign_texture_by_key(t_game *game, char **field, \
char *value)
{
	if (*field != NULL)
		ft_error(game, "texture property is duplicated defined");
	*field = value;
}

void	assign_texture(t_game *game, char *key, char *value)
{
	if (ft_strcmp(key, "NO") == 0)
		assign_texture_by_key(game, &(game->texture_no), value);
	else if (ft_strcmp(key, "SO") == 0)
		assign_texture_by_key(game, &(game->texture_so), value);
	else if (ft_strcmp(key, "WE") == 0)
		assign_texture_by_key(game, &(game->texture_we), value);
	else if (ft_strcmp(key, "EA") == 0)
		assign_texture_by_key(game, &(game->texture_ea), value);
	else
		ft_error(game, "strange identifier in texture lines");
}
