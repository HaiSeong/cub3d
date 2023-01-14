#include "cub3d.h"

static void validate(t_game *game, char *texture_file)
{
	int fd;

	fd = read_file(texture_file);
	if (fd < 0)
		ft_error(game, "cannot open texture_file");
	// png or xpm ?
}

void	validate_texture_lines(t_game *game)
{
	validate(game, game->texture_no);
	validate(game, game->texture_so);
	validate(game, game->texture_we);
	validate(game, game->texture_ea);
}