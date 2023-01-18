#include "cub3d.h"

void	set_floor(t_game *game)
{
	int	pixel;

	for(int y = 0; y < WIN_HEIGHT/ 2; ++y)
	{
		for(int x = 0; x < WIN_WIDTH; ++x)
		{
			pixel = (y * game->img->line_bytes) + (x * 4);

			game->img->buffer[pixel + 0] = (game->c_hex) & 0xFF;
			game->img->buffer[pixel + 1] = (game->c_hex >> 8) & 0xFF;
			game->img->buffer[pixel + 2] = (game->c_hex >> 16) & 0xFF;
			game->img->buffer[pixel + 3] = (game->c_hex >> 24);
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
			pixel = (y  * game->img->line_bytes) + (x * 4);

			game->img->buffer[pixel + 0] = (game->f_hex) & 0xFF;
			game->img->buffer[pixel + 1] = (game->f_hex >> 8) & 0xFF;
			game->img->buffer[pixel + 2] = (game->f_hex >> 16) & 0xFF;
			game->img->buffer[pixel + 3] = (game->f_hex >> 24);
		}
	}
}