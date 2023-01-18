#include "cub3d.h"

void	dda(t_game *game, t_ray *ray)
{
	int	map_x;
	int	map_y;

	map_x = game->pos_x;
	map_y = game->pos_y;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[map_y][map_x] > 0)
			ray->hit = 1;
	}
}