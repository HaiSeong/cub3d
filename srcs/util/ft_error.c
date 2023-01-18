#include "cub3d.h"

void	ft_error(t_game *game, char *msg)
{
	ft_free_game(game);
	if (game->mlx != NULL  && game->window != NULL)
		mlx_destroy_window(game->mlx, game->window);
	if (game->img->image != NULL)
		mlx_destroy_image(game->mlx, game->img->image);
	ft_printf("Error : %s\n", msg);
	// system("leaks cub3d");
	exit(0);
}