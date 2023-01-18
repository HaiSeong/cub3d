#include "cub3d.h"

void	ft_error(t_game *game, char *msg)
{
	ft_free_game(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_image(game->mlx, game->img->image);
	ft_printf("Error : %s\n", msg);
	// system("leaks cub3d");
	exit(0);
}