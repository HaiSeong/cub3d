#include "cub3d.h"

static void	ft_destroy_images(t_game *game)
{
	if (game->img->image != NULL)
		mlx_destroy_image(game->mlx, game->img->image);
	// if (game->img_no.image != NULL)
	// 	mlx_destroy_image(game->mlx, game->img_no.image);
	// if (game->img_so.image != NULL)
	// 	mlx_destroy_image(game->mlx, game->img_so.image);
	// if (game->img_we.image != NULL)
	// 	mlx_destroy_image(game->mlx, game->img_we.image);
	// if (game->img_ea.image != NULL)
	// 	mlx_destroy_image(game->mlx, game->img_ea.image);
}

void	ft_error(t_game *game, char *msg)
{
	ft_free_game(game);
	ft_destroy_images(game);
	if (game->window != NULL)
		mlx_destroy_window(game->mlx, game->window);
	ft_printf("Error : %s\n", msg);
	// system("leaks cub3d");
	exit(0);
}