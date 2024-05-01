/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:42:21 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/01 23:12:21 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_exit_player_collectables(t_game *game, char **argv)
{
	int		i;
	int		j;

	printf("%s\n", argv[1]);
	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.map[i][j] == 'E')
				game->exit_pos.num++;
			if (game->map.map[i][j] == 'C')
				game->collectables++;
			if (game->map.map[i][j] == 'P')
				game->player_pos.num++;
		}
	}
	if (game->exit_pos.num != 1 || game->player_pos.num != 1
		|| game->collectables == 0)
		return (1);
	find_player_and_exit_position(game);
	return (0);
}

int	ft_check_wall(t_game *game, char **argv)
{
	int	i;

	printf("%s\n ", argv[0]);
	if (game->map.map == NULL)
		return (1);
	i = -1;
	while (++i < game->map.width)
		if (game->map.map[0][i] != '1' ||
			game->map.map[game->map.height - 1][i] != '1')
			return (1);
	i = -1;
	while (++i < game->map.height)
		if (game->map.map[i][0] != '1' ||
			game->map.map[i][game->map.width - 1] != '1')
			return (1);
	return (0);
}

int	copy_map(t_game *game, char **argv)
{
	int		fd;
	int		i;
	int		j;
	char	ch;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (read(fd, &ch, 1) == -1)
				return (!close(fd));
			game->map.map[i][j] = ch;
			if (j == game->map.width - 1)
				game->map.map[i][j + 1] = '\0';
		}
		read(fd, &game->map.map[i][j], 1);
	}
	close(fd);
	return (0);
}

void	destroy_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
		free(game->map.map[i++]);
	free(game->map.map);
}

int	create_map(t_game *game, char **argv)
{
	int		i;

	game->map.height = map_height(argv);
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.height + 1));
	if (game->map.map == NULL)
		return (1);
	i = 0;
	while (i < game->map.height)
	{
		game->map.map[i] = (char *)malloc(sizeof(char) * (game->map.width + 1));
		if (game->map.map[i] == NULL)
		{
			while (i >= 0)
				free(game->map.map[i--]);
			free(game->map.map);
			return (1);
		}
		i++;
	}
	game->map.map[i] = '\0';
	return (0);
}
