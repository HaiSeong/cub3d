#include "cub3d.h"

void	set_wall(t_game *game, t_ray *ray, int x)
{
	int	pixel;
	int	pixel2;

	if (ray->side == 0)
	{
		ray->wall_x = game->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
		ray->wall_x -= floor(ray->wall_x);
	}
	else
	{
		ray->wall_x = game->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
		ray->wall_x -= floor(ray->wall_x);
	}

	ray->texture_x = (int)(ray->wall_x * 1920.0);

	if (ray->side == 1 && ray->ray_dir_x < 0)
    	ray->texture_x = 1920 - ray->texture_x - 1;

	if (ray->side == 0 && ray->ray_dir_y < 0)
    	ray->texture_x = 1920 - ray->texture_x - 1;
	
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = - ray->line_height / 2 + WIN_HEIGHT / 2;
	if(ray->draw_start < 0)
		ray->draw_start = 0;
	ray->drawEnd =  ray->line_height / 2 + WIN_HEIGHT / 2;
	if(ray->drawEnd >= WIN_HEIGHT)
		ray->drawEnd = WIN_HEIGHT - 1;

// 		while (벽의 시작지점부터 끝지점까지)
// {
//     textureY = (int)texture_pos & (TEXTURE_HEIGHT - 1);
//     texture_pos += step;
//     픽셀 가져와서 색칠하는 함수;
//     벽의 세로 좌표++;
// }
	t_img texture_img;

	if (ray->side == 1 && ray->step_y < 0)
		texture_img = game->img_no;
	else if (ray->side == 1)
		texture_img = game->img_so;
	else if (ray->step_x > 0)
		texture_img = game->img_ea;
	else
		texture_img = game->img_we;

	if (ray->line_height <= 0)
		return ;

	int step = 1920 / ray->line_height;

	pixel2 = (int)(ray->texture_x);
	for(int y = ray->draw_start; y < ray->drawEnd; ++y)
	{
		pixel = (y * game->img->line_bytes) + (x * 4);

		game->img->buffer[pixel + 0] = texture_img.buffer[1280] & 0xFF;
		game->img->buffer[pixel + 1] = (texture_img.buffer[1281] >> 8) & 0xFF;
		game->img->buffer[pixel + 2] = (texture_img.buffer[1282] >> 16) & 0xFF;
		game->img->buffer[pixel + 3] = (texture_img.buffer[1283] >> 24);
		pixel2 += step;
	}
}

void	raycasting(t_game *game)
{
	t_ray ray;
	int x;

	game->img->buffer = mlx_get_data_addr(game->img->image, &(game->img->pixel_bits), &(game->img->line_bytes), &(game->img->endian));
	set_floor(game);
	set_ceil(game);
	x = 0;
	while (x < WIN_WIDTH)
	{
		calculate_ray_values(game, &ray, x);
		dda(game, &ray);
		calculate_perp_wall_dist(game, &ray);
		set_wall(game, &ray, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img->image, 0, 0);
}

