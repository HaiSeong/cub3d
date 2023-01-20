#include "cub3d.h"

static void	xpm_file_to_image(t_game *game, int dir, char *file)
{
	t_img	img;
	int		w;
	int		h;
	int		x;
	int		y;

	game->img->image = mlx_xpm_file_to_image(game->mlx, file, &w, &h);
	if (game->img->image == NULL)
		ft_error(game, "mlx error");
	game->img->buffer = mlx_get_data_addr(game->img->image, \
		&game->img->pixel_bits, &game->img->line_bytes, &game->img->endian);
	
	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
			game->texture[dir][w * y + x] = game->img->buffer[w * y + x];
	}
	mlx_destroy_image(game->mlx, game->img->image);
}

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

	xpm_file_to_image(&game, 0, game.texture_we);
	xpm_file_to_image(&game, 1, game.texture_ea);
	xpm_file_to_image(&game, 2, game.texture_no);
	xpm_file_to_image(&game, 3, game.texture_so);

	game.img->image = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	game.img->buffer = mlx_get_data_addr(game.img->image, \
		&game.img->pixel_bits, &game.img->line_bytes, &game.img->endian);

	raycasting(&game);
	mlx_hook(game.window, ON_CLICK, 0, press_key, &game);
	mlx_hook(game.window, ON_DESTROY, 0, click_destroy, &game);
	mlx_loop(game.mlx);

	// ft_free_game(&game);
}
