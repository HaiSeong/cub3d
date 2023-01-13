/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:59:53 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/13 18:34:14 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	t_game game;

	init_game_struct(&game);
	parsing_cub_file(&game);
	ft_printf("texture_no : %s\n", game.texture_no);
	ft_printf("texture_so : %s\n", game.texture_so);
	ft_printf("texture_we : %s\n", game.texture_we);
	ft_printf("texture_ea : %s\n", game.texture_ea);
	ft_printf("F :");
	for (int i = 0 ; i< 3; i++)
		ft_printf(" %d,", game.F[i]);
	ft_printf("C :");
	for (int i = 0 ; i< 3; i++)
		ft_printf(" %d,", game.C[i]);
	
}
