/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:36:32 by jungchoi          #+#    #+#             */
/*   Updated: 2023/01/21 14:09:35 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	t_img	img;

	if (argc != 2)
	{
		ft_printf("check arguments number");
		return (0);
	}
	init_game_struct(&game, &img);
	validate_arg(&game, argc, argv);
	game.mlx = mlx_init();
	game.img->image = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (game.img->image == NULL)
		ft_error(&game, "mlx error");
	parsing_cub_file(&game, argv[1]);
	game.window = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	raycasting(&game);
	mlx_hook(game.window, ON_CLICK, 0, press_key, &game);
	mlx_hook(game.window, ON_DESTROY, 0, click_destroy, &game);
	mlx_loop(game.mlx);
}
