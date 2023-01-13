/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:56:58 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/13 16:59:48 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_file(char *file)
{
int fd;

	fd = open("1.cub", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("System error, reboot game");
		return (-1);
	}
	return (fd);
}
