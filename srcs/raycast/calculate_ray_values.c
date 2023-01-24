/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:12:27 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/24 12:05:59 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_values_by_ray_dir(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - game->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1 - game->pos_y) * ray->delta_dist_y;
	}
}

void	calculate_ray_values(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double) WIN_WIDTH - 1;
	ray->ray_dir_x = game->dir_x + game->plane_x * ray->camera_x;
	ray->ray_dir_y = game->dir_y + game->plane_y * ray->camera_x;
	ray->map_x = (int)game->pos_x;
	ray->map_y = (int)game->pos_y;
	if (ray->ray_dir_x != 0)
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y != 0)
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
	set_values_by_ray_dir(game, ray);
}
