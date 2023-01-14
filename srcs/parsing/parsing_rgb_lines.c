/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:59:53 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/13 18:37:58 by hajeong          ###   ########.fr       */
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
		assign_rgb_by_key(game, game->F, key, value);
	else if (ft_strcmp(key, "C") == 0)
		assign_rgb_by_key(game, game->C, key, value);
	else
		ft_error(game, "");//error
}

void	parsing_rgb_lines(t_game *game, int fd)
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
		if (strs[2] != NULL || !strs[0] || !strs[1])
		{
			ft_free_strs(strs);
			free(line);
			ft_error(game, "rgb property must have 2 fields");// error + free strs
		}
		assign_rgb(game, strs[0], strs[1]);
		ft_free_strs(strs);
		free(line);
		line = get_next_line(fd);
	}
	if (game->F[0] < 0 || game->F[1] < 0 || game->F[2] < 0 || \
		game->C[0] < 0 || game->C[1] < 0 || game->C[2] < 0)
		ft_error(game, "need more imformation about rgb property");// error
}
