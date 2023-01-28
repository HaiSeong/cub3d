/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:59:53 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/28 22:03:56 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_rgb_by_key(t_game *game, int *field, \
char *value)
{
	char	**strs;
	int		i;

	if (field[0] >= 0 || field[1] >= 0 || field[2] >= 0)
		ft_error(game, "rgb property is duplicated defined");
	i = -1;
	while (value[++i] != '\0')
		if (!ft_isdigit(value[i]) && value[i] != ',')
			ft_error(game, "rgb property contains strange characters");
	strs = ft_split(value, ',');
	if (strs == NULL)
		ft_error(game, "malloc error");
	if (strs[3] != NULL || !strs[0] || !strs[1] || !strs[2])
	{
		ft_free_strs(strs);
		ft_error(game, "rgb property must have 3 numbers");
	}
	i = -1;
	while (++i < 3)
		field[i] = ft_atoi(strs[i]);
	ft_free_strs(strs);
}

void	assign_rgb(t_game *game, char *key, char *value)
{
	if (ft_strcmp(key, "F") == 0)
		assign_rgb_by_key(game, game->f, value);
	else if (ft_strcmp(key, "C") == 0)
		assign_rgb_by_key(game, game->c, value);
	else
		ft_error(game, "rgb property contains strange characters");
}
