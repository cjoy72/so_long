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