#include "cub3d.h"

void	ft_error(t_game *game, char *msg)
{
	ft_free_game(game);
	ft_printf("Error : %s\n", msg);
	exit(0);
}