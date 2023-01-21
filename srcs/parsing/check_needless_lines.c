/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_needless_lines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:05:58 by jungchoi          #+#    #+#             */
/*   Updated: 2023/01/21 12:05:59 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_needless_lines(t_game *game, int fd)
{
	int	i;

	while (game->line != NULL)
	{
		i = -1;
		while (game->line[++i] != '\0')
		{
			if (!ft_isspace(game->line[i]))
				ft_error(game, "needless lines after map lines");
		}
		free(game->line);
		game->line = get_next_line(fd);
	}
}
