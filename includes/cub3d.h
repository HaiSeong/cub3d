/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:59:49 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/13 18:33:23 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define KEY_RELEASE 	3
# define KEY_EXIT 		17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

struct s_game
{
	char	*line;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	int		*F;
	int		*C;
	int		F_hex;
	int		C_hex;
	int		height;
	int		width;
	char	**map;
};
typedef struct s_game t_game;

// parsing
void	parsing_cub_file(t_game *game, char *file);
int		read_file(char *file);
void	parsing_texture_lines(t_game *game, int fd);
void	parsing_rgb_lines(t_game *game, int fd);
void	parsing_map_lines(t_game *game, int fd);
void	validate_texture_lines(t_game *game);
void	validate_rgb_lines(t_game *game);
void	validate_map(t_game *game);


// util
void	init_game_struct(t_game *game);
char	**ft_split_isspace(char const *s);
void	ft_free_strs(char **strs);
void	ft_free_game(t_game *game);
void	ft_error(t_game *game, char *msg);
void	validate_arg(t_game *game, int argc, char *argv[]);

#endif