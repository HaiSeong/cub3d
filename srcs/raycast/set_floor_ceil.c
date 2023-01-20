#include "cub3d.h"

void	set_floor(t_game *game)
{
	int	pixel;

	for(int y = 0; y < WIN_HEIGHT/ 2; ++y)
	{
		for(int x = 0; x < WIN_WIDTH; ++x)
		{
			pixel = (y * game->img->line_bytes / 4) + (x);

			game->img->buffer[pixel] = (game->c_hex);
		}
	}
}

void	set_ceil(t_game *game)
{
	int	pixel;
	
	for(int y = WIN_HEIGHT/ 2; y < WIN_HEIGHT; ++y)
	{
		for(int x = 0; x < WIN_WIDTH; ++x)
		{
			pixel = (y  * game->img->line_bytes / 4) + (x);

			game->img->buffer[pixel] = (game->f_hex);
		}
	}
}