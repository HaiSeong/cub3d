#include "cub3d.h"

static int	get_width(t_list *map_ll)
{
	int		max_width;
	t_list	*node;

	max_width = 0;
	node = map_ll;
	while (node != NULL)
	{
		if (max_width < ft_strlen(node->content))
			max_width = ft_strlen(node->content);
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
		ft_memset(arr[i], ' ', width - 1);
		arr[i][width - 1] = '\0';
	}
	return (arr);
}

static void	linkedlist_to_arr(t_game *game, t_list **map_ll)
{
	char	**map_arr;
	t_list	*node;
	int		i;
	int		j;

	game->height = ft_lstsize(*map_ll);
	game->width = get_width(*map_ll);
	game->map = init_2d_arr(game->height, game->width);
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
		while (((char *)node->content)[++j] != '\n' && ((char *)node->content)[j] != '\0')
			game->map[i][j] = ((char *)node->content)[j];
		i++;
		node = node->next;
	}
	ft_lstclear(map_ll, free);
} 

void	parsing_map_lines(t_game *game, int fd)
{
	char	*line;
	t_list	*map_ll;
	t_list	*node;

	map_ll = NULL;
	line = "\n";
	while (line != NULL && ft_strcmp(line, "\n") == 0)
		line = get_next_line(fd);
	while (line != NULL && ft_strcmp(line, "\n") != 0)
	{
		node = ft_lstnew(line);
		if (node == NULL)
		{
			free(line);
			ft_lstclear(&map_ll, free);
			ft_error(game, "malloc error");
		}
		ft_lstadd_back(&map_ll, node);
		line = get_next_line(fd);
	}
	if (map_ll == NULL)
		ft_error(game, "empty map lines");
	linkedlist_to_arr(game, &map_ll);
}
