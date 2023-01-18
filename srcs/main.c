#include "cub3d.h"

static int	press_key(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		printf("press w\n");
	else if (keycode == KEY_A)
		printf("press a\n");
	else if (keycode == KEY_S)
		printf("press s\n");
	else if (keycode == KEY_D)
		printf("press d\n");
	else if (keycode == KEY_ESC)
	{
		printf("press esc\n");
		mlx_destroy_window(game->mlx, game->window);
		exit(EXIT_SUCCESS);
	}
	raycasting(game);
	// draw_screen(&game, &(game->ray));
	return (0);
}

static int	click_destroy(t_game *game)
{
	printf("click destroy\n");
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	t_game	game;
	t_img	img;

	init_game_struct(&game, &img);
	validate_arg(&game, argc, argv);
	parsing_cub_file(&game, argv[1]);


	game.mlx = mlx_init();
	game.img->image = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (game.img->image == NULL)
		ft_error(&game, "mlx error");
	game.window = mlx_new_window(game.mlx, \
		WIN_WIDTH, WIN_HEIGHT, "cub3d");
	
	// game.img->buffer = mlx_get_data_addr(game.img->image, &(game.img->pixel_bits), &(game.img->line_bytes), &(game.img->endian));
	// for(int y = 0; y < WIN_HEIGHT/ 2; ++y)
	// {
	// 	for(int x = 0; x < WIN_WIDTH; ++x)
	// 	{
	// 		int pixel = (y * game.img->line_bytes) + (x * 4);

	// 		game.img->buffer[pixel + 0] = (game.c_hex) & 0xFF;
	// 		game.img->buffer[pixel + 1] = (game.c_hex >> 8) & 0xFF;
	// 		game.img->buffer[pixel + 2] = (game.c_hex >> 16) & 0xFF;
	// 		game.img->buffer[pixel + 3] = (game.c_hex >> 24);

	// 		pixel = ((y + WIN_HEIGHT/ 2) * game.img->line_bytes) + (x * 4);

	// 		game.img->buffer[pixel + 0] = (game.f_hex) & 0xFF;
	// 		game.img->buffer[pixel + 1] = (game.f_hex >> 8) & 0xFF;
	// 		game.img->buffer[pixel + 2] = (game.f_hex >> 16) & 0xFF;
	// 		game.img->buffer[pixel + 3] = (game.f_hex >> 24);
	// 	}
	// }
	// mlx_put_image_to_window(game.mlx, game.window, game.img->image, 0, 0);
	
	mlx_hook(game.window, ON_CLICK, 0, press_key, &game);
	mlx_hook(game.window, ON_DESTROY, 0, click_destroy, &game);
	mlx_loop(game.mlx);

	// ft_free_game(&game);s
}
