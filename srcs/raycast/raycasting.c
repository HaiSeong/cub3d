#include "cub3d.h"

void	set_wall(t_game *game, t_ray *ray, int x)
{
	int		step;
	double	texture_pos;
	int		i;
	int		texture_y;
	int		color;

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

	ray->texture_x = (int)(ray->wall_x * (double)PIXEL); //

	if (ray->side == 1 && ray->ray_dir_x < 0)
    	ray->texture_x = PIXEL - ray->texture_x - 1; //

	if (ray->side == 0 && ray->ray_dir_y < 0)
    	ray->texture_x = PIXEL - ray->texture_x - 1; //
	
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = - ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->drawEnd =  ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->drawEnd >= WIN_HEIGHT)
		ray->drawEnd = WIN_HEIGHT - 1;

	int	tex_num = game->map[ray->map_y][ray->map_x] - 1;
	// start
	step = 1.0 * PIXEL / ray->line_height;
	texture_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	i = ray->draw_start;
	while (i <= ray->drawEnd)
	{
		texture_y = (int)texture_pos & (PIXEL - 1);
		texture_pos += step;
		color = game->texture[tex_num][PIXEL * texture_y + ray->texture_x];
		game->temp[i][x] = color;
		i++;
	}
}

static void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			game->img->buffer[y * WIN_WIDTH + x] = game->temp[y][x];
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img->image, 0, 0);
}

void	raycasting(t_game *game)
{
	t_ray ray;
	int x;

	game->img->buffer = mlx_get_data_addr(game->img->image, &(game->img->pixel_bits), &(game->img->line_bytes), &(game->img->endian));
	// set_floor(game);
	// set_ceil(game);
	x = 0;
	while (x < WIN_WIDTH)
	{
		calculate_ray_values(game, &ray, x);
		dda(game, &ray);
		calculate_perp_wall_dist(game, &ray);
		set_wall(game, &ray, x);
		x++;
	}
	draw_map(game);
}

