/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:56:58 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/28 22:17:29 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	pass_new_line(t_game *game, int fd)
{
	while (game->line != NULL && ft_strcmp(game->line, "\n") == 0)
	{
		free(game->line);
		game->line = get_next_line(fd);
	}
}

static void	check_strs_value(t_game *game, char **strs)
{
	if (strs == NULL)
		ft_error(game, "malloc error");
	if (strs[2] != NULL || !strs[0] || !strs[1])
	{
		ft_free_strs(strs);
		ft_error(game, "property must have 2 fields");
	}
}

static void	free_useless_value(t_game *game, char **strs)
{
	free(strs[0]);
	free(strs);
	free(game->line);
}

static void	parsing_elements(t_game *game, int fd)
{
	static int	count = 0;
	char		**strs;

	game->line = ft_strdup("\n");
	while (count < 6)
	{
		pass_new_line(game, fd);
		if (game->line == NULL)
			break ;
		strs = ft_split_isspace(game->line);
		check_strs_value(game, strs);
		if (ft_strcmp("F", strs[0]) == 0 || ft_strcmp("C", strs[0]) == 0)
		{
			assign_rgb(game, strs[0], strs[1]);
			free(strs[1]);
		}
		else if (ft_strcmp("NO", strs[0]) == 0 || ft_strcmp("SO", strs[0]) == 0 \
			|| ft_strcmp("WE", strs[0]) == 0 || ft_strcmp("EA", strs[0]) == 0)
			assign_texture(game, strs[0], strs[1]);
		else
			ft_error(game, "contains strange characters");
		free_useless_value(game, strs);
		game->line = get_next_line(fd);
		count++;
	}
}

void	parsing_cub_file(t_game *game, char *file)
{
	int		fd;

	fd = read_file(file);
	if (fd < 0)
		ft_error(game, "failed to open .cub file");
	parsing_elements(game, fd);
	if (game->texture_no == NULL || game->texture_so == NULL \
		|| game->texture_we == NULL || game->texture_ea == NULL)
		ft_error(game, "need more imformation");
	if (game->f[0] < 0 || game->f[1] < 0 || game->f[2] < 0 || \
		game->c[0] < 0 || game->c[1] < 0 || game->c[2] < 0)
		ft_error(game, "need more imformation");
	validate_texture_lines(game);
	validate_rgb_lines(game);
	parsing_map_lines(game, fd);
	validate_map(game);
	check_needless_lines(game, fd);
	close(fd);
}
