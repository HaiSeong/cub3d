/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:59:53 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/18 15:03:01 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assign_rgb_by_key(t_game *game, int *field, \
char *key, char *value)
{
	char	**strs;
	int		i;
	
	if (field[0] >= 0 || field[1] >= 0 || field[2] >= 0)
		ft_error(game, "rgb property is duplicated defined"); // error
	i = -1;
	while (value[++i] != '\0')
		if (!ft_isdigit(value[i]) && value[i] != ',')
			ft_error(game, "rgb property contains strange characters"); //error
	strs = ft_split(value, ',');
	if (strs == NULL)
		ft_error(game, "malloc error");// error
	if (strs[3] != NULL || !strs[0] || !strs[1] || !strs[2]) 
	{
		ft_free_strs(strs);
		ft_error(game, "rgb property must have 3 numbers");// error + ~~~~
	}
	i = -1;
	while (++i < 3)
		field[i] = atoi(strs[i]);
	ft_free_strs(strs);
}

static void	assign_rgb(t_game *game, char *key, char *value)
{
	if (ft_strcmp(key, "F") == 0)
		assign_rgb_by_key(game, game->f, key, value);
	else if (ft_strcmp(key, "C") == 0)
		assign_rgb_by_key(game, game->c, key, value);
	else
		ft_error(game, "");//error
}

void	parsing_rgb_lines(t_game *game, int fd)
{
	char	**strs;

	while (game->line != NULL && ft_strcmp(game->line, "\n") == 0)
	{
		free(game->line);
		game->line = get_next_line(fd);
	}
	while (game->line != NULL && ft_strcmp(game->line, "\n") != 0)
	{
		strs = ft_split_isspace(game->line);
		if (strs == NULL)
			ft_error(game, "malloc error");// error
		if (strs[2] != NULL || !strs[0] || !strs[1])
		{
			ft_free_strs(strs);
			ft_error(game, "rgb property must have 2 fields");// error + free strs
		}
		assign_rgb(game, strs[0], strs[1]);
		ft_free_strs(strs);
		free(game->line);
		game->line = get_next_line(fd);
	}
	if (game->f[0] < 0 || game->f[1] < 0 || game->f[2] < 0 || \
		game->c[0] < 0 || game->c[1] < 0 || game->c[2] < 0)
		ft_error(game, "need more imformation about rgb property");// error
}
