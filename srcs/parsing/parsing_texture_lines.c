/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_lines.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:59:53 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/13 18:38:24 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assign_texture_by_key(t_game *game, char **field, \
char *key, char *value)
{
	if (*field != NULL)
		ft_error(game, "texture property is duplicated defined"); // error
	*field = value;
}

static void	assign_texture(t_game *game, char *key, char *value)
{
	if (ft_strcmp(key, "NO") == 0)
		assign_texture_by_key(game, &(game->texture_no), key, value);
	else if (ft_strcmp(key, "SO") == 0)
		assign_texture_by_key(game, &(game->texture_so), key, value);
	else if (ft_strcmp(key, "WE") == 0)
		assign_texture_by_key(game, &(game->texture_we), key, value);
	else if (ft_strcmp(key, "EA") == 0)
		assign_texture_by_key(game, &(game->texture_ea), key, value);
	else
		ft_error(game, "strange identifier in texture lines");//error
} 

void	parsing_texture_lines(t_game *game, int fd)
{
	char	*line;
	char	**strs;

	line = "\n";
	while (line != NULL && ft_strcmp(line, "\n") == 0)
		line = get_next_line(fd);
	while (line != NULL && ft_strcmp(line, "\n") != 0)
	{
		strs = ft_split_isspace(line);
		if (strs == NULL)
			ft_error(game, "malloc error");// error
		if (strs[2] != NULL || !strs[0]|| !strs[1])
		{
			free(strs);
			free(line);
			ft_error(game, "texture property must have 2 fields");// error + free strs
		}
		assign_texture(game, strs[0], strs[1]);
		free(strs[0]);
		free(strs);
		free(line);
		line = get_next_line(fd);
	}
	if (game->texture_no == NULL || game->texture_so == NULL \
		|| game->texture_we == NULL || game->texture_ea == NULL)
		ft_error(game, "need more imformation about texture property");// error
}
