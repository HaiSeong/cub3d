#include "cub3d.h"

static int	get_width(t_list *map_ll)
{
	int		max_width;
	t_list	*node;

	max_width = 0;
	node = map_ll;
	while (node != NULL)
	{
		if (!ft_strchr(node->content, '\n'))
		{
			if (max_width < ft_strlen(node->content))
				max_width = ft_strlen(node->content);
		}
		else if (max_width < ft_strlen(node->content) - 1)
			max_width = ft_strlen(node->content) - 1;
		node = node->next;
	}
	return (max_width);
}

static char	**init_2d_arr(int height, int width)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(char *) * (height + 1));
	if (arr == NULL)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		arr[i] = (char *)malloc(sizeof(char) * (width + 1));
		if (arr[i] == NULL)
		{
			while (--i >= 0)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		ft_memset(arr[i], ' ', width);
		arr[i][width] = '\0';
	}
	arr[height] = NULL;
	return (arr);
}

static void	linkedlist_to_arr(t_game *game, t_list **map_ll)
{
	char	**map_arr;
	t_list	*node;
	int		i;
	int		j;

	game->map_height = ft_lstsize(*map_ll);
	game->map_width = get_width(*map_ll);
	game->map = init_2d_arr(game->map_height, game->map_width);
	if (game->map == NULL)
	{
		ft_lstclear(map_ll, free);
		ft_error(game, "malloc error");
	}
	i = 0;
	node = *map_ll;
	while (node != NULL)
	{
		j = -1;
		while (node->content[++j] != '\n' && node->content[j] != '\0')
			game->map[i][j] = node->content[j];
		i++;
		node = node->next;
	}
	ft_lstclear(map_ll, free);
} 

void	parsing_map_lines(t_game *game, int fd)
{
	t_list	*map_ll;
	t_list	*node;

	map_ll = NULL;
	while (game->line != NULL && ft_strcmp(game->line, "\n") == 0)
	{
		free(game->line);
		game->line = get_next_line(fd);
	}
	while (game->line != NULL && ft_strcmp(game->line, "\n") != 0)
	{
		node = ft_lstnew(game->line);
		if (node == NULL)
		{
			ft_lstclear(&map_ll, free);
			ft_error(game, "malloc error");
		}
		ft_lstadd_back(&map_ll, node);
		game->line = get_next_line(fd);
	}
	if (map_ll == NULL)
		ft_error(game, "empty map lines");
	linkedlist_to_arr(game, &map_ll);
}
