#include "cub3d.h"

static void	set_play_direction(t_game *game, char direction, int i, int j)
{
	game->pos_x = (double) j;
	game->pos_y = (double) i;
	if (direction == 'N')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->plane_x = 0.66;
		game->plane_y = 0.0;
	}
	else if (direction == 'S')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->plane_x = -0.66;
		game->plane_y = 0.0;
	}
	else if (direction == 'W')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->plane_x = 0.0;
		game->plane_y = -0.66;
	}
	else if (direction == 'E')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->plane_x = 0.0;
		game->plane_y = 0.66;
	}
}

static void	validate_map_char(t_game *game)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (game->map[i][++j] != '\0')
		{
			if (!ft_strchr(" 01NSEW", game->map[i][j]))
				ft_error(game, "strange characters in the map");
			else if (ft_strchr("NSEW", game->map[i][j]))
			{
				cnt++;
				set_play_direction(game, game->map[i][j], i, j);
				game->map[i][j] = '0';
			}
		}
	}
	if (cnt < 1)
		ft_error(game, "no start position");
	if (cnt > 1)
		ft_error(game, "too many start position");
}

static void	validate_row(t_game *game, int row)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		while (i < game->map_width && game->map[row][i] == ' ')
			i++;
		if (game->map[row][i] == '\0')
			break ;
		if (game->map[row][i] != '1')
			ft_error(game, "map is not walled around");
		while (i < game->map_width && game->map[row][i] != ' ')
			i++;
		if (game->map[row][i - 1] != '1')
			ft_error(game, "map is not walled around");
	}
}

static void	validate_column(t_game *game, int column)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		while (i < game->map_height && game->map[i][column] == ' ')
			i++;
		if (i >= game->map_height)
			break ;
		if (game->map[i][column] != '1')
			ft_error(game, "map is not walled around");
		while (i < game->map_height && game->map[i][column] != ' ')
			i++;
		if (game->map[i - 1][column] != '1')
			ft_error(game, "map is not walled around");
	}
}

static void	validate_map_wall(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map_height)
		validate_row(game, i);
		
	i = -1;
	while (++i < game->map_width)
		validate_column(game, i);
	
}

void	validate_map(t_game *game)
{
	validate_map_char(game);
	validate_map_wall(game);
}