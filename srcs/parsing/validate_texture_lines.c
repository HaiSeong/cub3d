#include "cub3d.h"

static void validate(t_game *game, char *texture_file)
{
	int fd;

	fd = read_file(texture_file);
	if (fd < 0)
		ft_error(game, "cannot open texture file");
	close(fd);
	if (ft_strlen(texture_file) < ft_strlen(".xpm"))
		ft_error(game, "texture file name is too short");
	if (ft_strncmp(texture_file + ft_strlen(texture_file) - 4 , ".xpm" , 4))
		ft_error(game, "texture file name must end with \'.xpm\'");
}

void	validate_texture_lines(t_game *game)
{
	validate(game, game->texture_no);
	validate(game, game->texture_so);
	validate(game, game->texture_we);
	validate(game, game->texture_ea);
}