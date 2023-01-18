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
		ft_free_game(&game);
		exit(EXIT_SUCCESS);
	}
	raycasting(game);
	return (0);
}

static int	click_destroy(t_game *game)
{
	printf("click destroy\n");
	mlx_destroy_window(game->mlx, game->window);
	ft_free_game(&game);
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
	game.window = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	raycasting(&game);
	mlx_hook(game.window, ON_CLICK, 0, press_key, &game);
	mlx_hook(game.window, ON_DESTROY, 0, click_destroy, &game);
	mlx_loop(game.mlx);

	// ft_free_game(&game);
}
