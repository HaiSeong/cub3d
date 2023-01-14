#include "cub3d.h"

void	ft_free_game(t_game *game)
{
	if (game->line != NULL)
		free(game->line);
	if (game->texture_no != NULL)
		free(game->texture_no);
	if (game->texture_so != NULL)
		free(game->texture_so);
	if (game->texture_we != NULL)
		free(game->texture_we);
	if (game->texture_ea != NULL)
		free(game->texture_ea);
	if (game->F != NULL)
		free(game->F);
	if (game->C != NULL)
		free(game->C);
	if (game->map != NULL)
		ft_free_strs(game->map);
	
}