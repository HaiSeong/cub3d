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

	t_img texture_img;

	if (ray->side == 1 && ray->step_y < 0)
		texture_img = game->img_no;
	else if (ray->side == 1)
		texture_img = game->img_so;
	else if (ray->step_x > 0)
		texture_img = game->img_ea;
	else
		texture_img = game->img_we;

		
	ray->texture_x = (int)(ray->wall_x * (double) TEXTURE_WIDTH);

	if (ray->side == 0 && ray->ray_dir_x > 0)
    	ray->texture_x = TEXTURE_WIDTH - ray->texture_x - 1;

	if (ray->side == 1 && ray->ray_dir_y < 0)
    	ray->texture_x = TEXTURE_WIDTH - ray->texture_x - 1;
	
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = - ray->line_height / 2 + WIN_HEIGHT / 2;
	if(ray->draw_start < 0)
		ray->draw_start = 0;
	ray->drawEnd =  ray->line_height / 2 + WIN_HEIGHT / 2;
	if(ray->drawEnd >= WIN_HEIGHT)
		ray->drawEnd = WIN_HEIGHT;

	if (ray->line_height <= 0)
		return ;

	ray->step = (double) TEXTURE_WIDTH / ray->line_height;
	ray->texture_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * ray->step;

	for(int y = ray->draw_start; y < ray->drawEnd; y += 1)
	{
		pixel = (y * game->img->line_bytes / 4) + (x);
		ray->texture_y = (int)ray->texture_pos & (TEXTURE_WIDTH - 1);

		game->img->buffer[pixel] = texture_img.buffer[ray->texture_y * texture_img.line_bytes/4 + ray->texture_x];
		ray->texture_pos += ray->step;
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

