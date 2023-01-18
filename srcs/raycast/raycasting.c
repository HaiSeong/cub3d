#include "cub3d.h"

void	raycasting(t_game *game)
{
	t_ray ray;
	int x;
	int line_height;
	int draw_start;
	int drawEnd;
	int	pixel;

	game->img->buffer = mlx_get_data_addr(game->img->image, &(game->img->pixel_bits), &(game->img->line_bytes), &(game->img->endian));
	set_floor(game);
	set_ceil(game);
	x = 0;
	while (x < WIN_WIDTH)
	{
		calculate_ray_values(game, &ray, x);
		dda(game, &ray);
		calculate_perp_wall_dist(game, &ray);

		line_height = (int)(WIN_HEIGHT / ray.perp_wall_dist);

		draw_start = -line_height / 2 + WIN_HEIGHT / 2;
		if(draw_start < 0)
			draw_start = 0;
		drawEnd = line_height / 2 + WIN_HEIGHT / 2;
		if(drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;

		for(int y = draw_start; y < drawEnd; ++y)
		{
			pixel = (y * game->img->line_bytes) + (x * 4);

			game->img->buffer[pixel + 0] = (0x00345678) & 0xFF;
			game->img->buffer[pixel + 1] = (0x00345678 >> 8) & 0xFF;
			game->img->buffer[pixel + 2] = (0x00345678 >> 16) & 0xFF;
			game->img->buffer[pixel + 3] = (0x00345678 >> 24);
		}
		// mlx_pixel_put(game->mlx, game->window, x, y, 0x12345678);

		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img->image, 0, 0);
}