/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:55:08 by cbaroi            #+#    #+#             */
/*   Updated: 2024/03/15 11:13:36 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int flood_fill(char **tmp_map, t_coord player, t_coord mapsize)
{
	if (tmp_map[player.y][player.x] == '1'
		|| tmp_map[player.y][player.x] = 'X')
		return (0);
	tmp.map[player.y][player.x] = 'X';
	flood_fill(tmp_map, (t_coord){player.x + 1, player.y}, mapsize);
	flood_fill(tmp_map, (t_coord){player.x, player.y + 1}, mapsize);
	flood_fill(tmp_map, (t_coord){player.x - 1, player.y}, mapsize);
	flood_fill(tmp_map, (t_coord){player.x, player.y - 1}, mapsize);
	return (0);
}

static int	check_floodfill(char *tmp_map)
{
	int	i;
	int	j;

	i = 0;
	while (tmp_map[i][j] != NULL)
	{
		j = 0;
		while (tmp_map[i][j] != '\0')
		{
			if (tmp_map[i][j] == 'C' || tmp_map[i][j] == "c"
				|| tmp_map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_matrix(char **tmp_map)
{
	int	i;

	i = 0;
	while (tmp_map[i] != NULL)
		free(tmp_map[i++]);
	free(tmp_map);
}

static int	check_path(char *map)
{
	char	**tmp_map;
	t_coord	player;
	t_coord	mapsize;

	mapsize.x = 0;
	mapsize.y = 0;
	player.x = get_player_coordinate(map, 1);
	player.y = get_player_coordinate(map, 0);
	tmp_map = copy_matrix(map);
	get_map_size(map, mapsize);
	flood_fill(tmp_map, player, mapsize);
	if (check_floodfill(tmp_map) == 0)
		return (1);
	free_matrix(tmp_map);
	return (0);
}

char	**get_map(char *argv, t_game *game)
{
	char	**map;
	char	*line;
	int		fd;
	line = get_next_line(fd);
	while (line != 0)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	if (check_wall(map, height) || check_entities(map) || check_path(map))
		free_map(map, game);
	return (map);
}