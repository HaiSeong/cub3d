#include "cub3d.h"

void validate_arg(t_game *game, int argc, char *argv[])
{
	if (argc != 2)
		ft_error(game, "check arguments number");
	if (ft_strlen(argv[1]) < ft_strlen(".cub"))
		ft_error(game, "file name is too short");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4 , ".cub" , 4))
		ft_error(game, "file name must end with \'.cub\'");
}