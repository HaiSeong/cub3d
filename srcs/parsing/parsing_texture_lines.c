/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_lines.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:59:53 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/13 17:25:40 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assign_texture(t_game *game, char *key, char *value)
{
	if (ft_strcmp(key, "NO") == 0)
	{
		if (game->texture_no != NULL)
			; // error
		game->texture_no = value;
	}
	else if (ft_strcmp(key, "SO") == 0)
	{
		if (game->texture_no != NULL)
			; // error
		game->texture_so = value;
	}
	else if (ft_strcmp(key, "WE") == 0)
	{
		if (game->texture_no != NULL)
			; // error
		game->texture_we = value;
	}
	else if (ft_strcmp(key, "EA") == 0)
	{
		if (game->texture_no != NULL)
			; // error
		game->texture_ea = value;
	}
}

void	parsing_texture_lines(t_game *game, int fd)
{
	char	*line;
	char	**strs;

	line = "\n";
	while (ft_strcmp(line, "\n") == 0)
		line = get_next_line(fd);
	while (ft_strcmp(line, "\n") != 0)
	{
		strs = ft_split_isspace(line);
		if (strs == NULL)
			;// error
		assign_texture(game, strs[0], strs[1]);
		free(strs[0]);
		free(strs);
		free(line);
		line = get_next_line(fd);
	}
	if (game->texture_no == NULL || game->texture_so == NULL \
		|| game->texture_we == NULL || game->texture_ea == NULL)
		;// error
}
