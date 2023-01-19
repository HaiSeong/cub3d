#include "cub3d.h"

int main(int argc, char *argv[])
{
	t_game	game;
	t_img	img;

	init_game_struct(&game, &img);
	validate_arg(&game, argc, argv);
	game.mlx = mlx_init();
	parsing_cub_file(&game, argv[1]);
	game.img->image = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (game.img->image == NULL)
		ft_error(&game, "mlx error");
	game.window = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	raycasting(&game);
	mlx_hook(game.window, ON_CLICK, 0, press_key, &game);
	mlx_hook(game.window, ON_DESTROY, 0, click_destroy, &game);
	mlx_loop(game.mlx);

	// ft_free_game(&game);
}
