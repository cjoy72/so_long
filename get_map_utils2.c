/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calvinjoybaroi <calvinjoybaroi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:32:28 by calvinjoyba       #+#    #+#             */
/*   Updated: 2024/04/09 16:41:04 by calvinjoyba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(char **map, int height)
{
	int	i;
	int	length;

	length = 0;
	while (map[0][length] != '\0' && map[0][length] == '1')
		lenth++;
	if (length != ft_strlenh(map[0]))
		return (1);
	i = 1;
	while (i < height)
	{
		if (length != ft_strlenh(map[i])
			|| map[i][0] != '1' || map[i][length -1] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map[height - 1][i] != '\0' && map[height - 1][i] == '1')
		i++;
	if (i != ft_strlenh(map[height - 1]))
		return (1);
	if (length == height)
		return (1);
	return (0);
}

int check_entities(char **map)
{
	t_entities	e;

	e.i = -1;
	e.player = 0;
	e.exit = 0;
	e.collectible = 0;
	while (map[++e.i] != NULL)
	{
		e.j = -1;
		while (map[e.i][++e.j] != '\0' && map[e.i][e.j] != '\n')
		{
			if (map[e.i][e.j] == 'P')
				e.player++;
			else if (map[e.i][e.j] == 'E')
				e.exit++;
			else if (map[e.i][e.j] == 'C')
				e.collectible++;
			else if (map[e.i][e.j] != '0' && map[e.i][e.j] != '1')
				return (1);
		}
	}
	if (e.player != 1 || e.exit != 1 || e.collectible == 0)
		return (1);
	return (0);
}

char	**copy_matrix(char **map)
{
	char	**tmp_map;
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
		i++;
	tmp_map = (char **)ft_calloc(i + 1, sizeof(char *));
	j = 0;
	while (j < i)
	{
		tmp_map[j] = ft_strdup(map[j]);
		++j;
	}
	return (tmp_map);
}

int	get_player_coordinate(char **map, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == 'P')
			{
				if (flag == 0)
					return (i);
				else
					return (j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	get_player_coordinate(char **map, int flag)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	mapsize.y = i;
	mapsize.x = ft_strlenh(map[0]);
	i = mapsize.x * mapsize.y;
}
