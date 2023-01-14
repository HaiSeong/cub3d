#include "cub3d.h"

static void validate(t_game *game, int *arr)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (0 > arr[i] || arr[i] > 255)
			ft_error(game, "rgb value must be between 0 and 255");
	}
}

static int	arr_to_hex(int *arr)
{
	int	hex;

	hex = 256 * 256 * arr[0] + 256 * arr[1] + arr[2];
	return (hex);
}

void	validate_rgb_lines(t_game *game)
{
	validate(game, game->F);
	validate(game, game->C);
	game->F_hex = arr_to_hex(game->F);
	game->C_hex = arr_to_hex(game->C);
	free(game->F);
	free(game->C);
	game->F = NULL;
	game->C = NULL;
}