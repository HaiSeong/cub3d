/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:59:49 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/28 11:52:54 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define KEY_RELEASE 	3
# define KEY_EXIT 		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124

# define ON_CLICK		2
# define ON_DESTROY		17

# define SPEED			0.05

# define WIN_WIDTH		1920
# define WIN_HEIGHT		1080

typedef struct s_img
{
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		*buffer;
}	t_img;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	int		hit;
	int		side;
	int		step_x;
	int		step_y;
	double	camera_x;
	double	camera_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	int		texture_x;
	int		texture_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	step;
	double	texture_pos;
}	t_ray;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_img	*img;
	t_ray	*ray;
	char	*line;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	t_img	img_no;
	t_img	img_so;
	t_img	img_we;
	t_img	img_ea;
	int		*f;
	int		*c;
	int		f_hex;
	int		c_hex;
	int		map_height;
	int		map_width;
	char	**map;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_game;

// parsing
void	parsing_cub_file(t_game *game, char *file);
int		read_file(char *file);
void	parsing_texture_lines(t_game *game, int fd);
void	parsing_rgb_lines(t_game *game, int fd);
void	parsing_map_lines(t_game *game, int fd);
void	validate_texture_lines(t_game *game);
void	validate_rgb_lines(t_game *game);
void	validate_map(t_game *game);
void	check_needless_lines(t_game *game, int fd);
void	set_play_direction(t_game *game, char direction, int i, int j);

// util
void	init_game_struct(t_game *game, t_img *img);
int		ft_isspace(char c);
char	**ft_split_isspace(char const *s);
void	ft_free_strs(char **strs);
void	ft_free_game(t_game *game);
void	ft_error(t_game *game, char *msg);
void	ft_destroy_images(t_game *game);
void	validate_arg(t_game *game, char *argv[]);
void	set_texture_image(t_game *game);
void	xpm_file_to_image_texture(t_game *game);
void	get_data_addr_texture(t_game *game);

// raycast
void	raycasting(t_game *game);
void	calculate_ray_values(t_game *game, t_ray *ray, int x);
void	dda(t_game *game, t_ray *ray);
void	calculate_perp_wall_dist(t_game *game, t_ray *ray);
void	set_floor(t_game *game);
void	set_ceil(t_game *game);

// event
int		press_key(int keycode, t_game *game);
void	press_ws(t_game *game, int flag);
void	press_ad(t_game *game, int flag);
void	press_lr(t_game *game, int flag);
int		click_destroy(t_game *game);

#endif
