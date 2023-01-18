#include "cub3d.h"

static int	press_key(int keycode, t_info *info)
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
		mlx_destroy_window(info->mlx, info->window);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int	click_destroy(t_info *info)
{
	printf("click destroy\n");
	mlx_destroy_window(info->mlx, info->window);
	exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	t_game game;
	t_info	info;

	init_game_struct(&game);
	validate_arg(&game, argc, argv);
	parsing_cub_file(&game, argv[1]);
	ft_printf("texture_no : %s\n", game.texture_no);
	ft_printf("texture_so : %s\n", game.texture_so);
	ft_printf("texture_we : %s\n", game.texture_we);
	ft_printf("texture_ea : %s\n", game.texture_ea);

	ft_printf("width : %d, height : %d\n", game.width, game.height);
	for (int i = 0 ; i< game.height; i++)
		ft_printf("[%s]\n", game.map[i]);

	info.mlx = mlx_init();
	info.window = mlx_new_window(info.mlx, \
		game.width * 64, game.height * 64, "cub3d");
	mlx_hook(info.window, ON_CLICK, 0, press_key, &info);
	mlx_hook(info.window, ON_DESTROY, 0, click_destroy, &info);
	mlx_loop(info.mlx);

	ft_free_game(&game);
}
