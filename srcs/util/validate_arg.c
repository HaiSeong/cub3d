/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:15:40 by jungchoi          #+#    #+#             */
/*   Updated: 2023/01/21 13:44:11 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_arg(t_game *game, int argc, char *argv[])
{
	if (ft_strlen(argv[1]) < ft_strlen(".cub"))
		ft_error(game, "file name is too short");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
		ft_error(game, "file name must end with \'.cub\'");
}
