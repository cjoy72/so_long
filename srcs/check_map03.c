/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:01:19 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/02 20:47:42 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	file_descriptor(int *fd, char **argv)
{
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
		ft_error("Error\n", 1);
}

int	find_char(t_game *game, char c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
			if (game->map.map[i][j] == c)
				return (0);
	}
	return (1);
}

void	flood_fill(t_game *game, int i, int j)
{
	if (game->map.map[i][j] != '1')
	{
		game->map.map[i][j] = '1';
		flood_fill(game, i - 1, j);
		flood_fill(game, i + 1, j);
		flood_fill(game, i, j - 1);
		flood_fill(game, i, j + 1);
	}
}

int	valid_path(t_game *game, char **argv)
{
	t_game	tmp_game;
	int		validity;

	tmp_game.map.height = game->map.height;
	tmp_game.map.width = game->map.width;
	if (create_map(&tmp_game, argv) != 0)
		return (1);
	if (copy_map(&tmp_game, argv) != 0)
	{
		destroy_map(&tmp_game);
		return (1);
	}
	tmp_game.player_pos.i = game->player_pos.i;
	tmp_game.player_pos.j = game->player_pos.j;
	flood_fill(&tmp_game, tmp_game.player_pos.i, tmp_game.player_pos.j);
	if (find_char(&tmp_game, 'P' == 1)
		&& find_char(&tmp_game, 'E' == 1)
		&& find_char(&tmp_game, 'C') == 1)
		validity = 0;
	else
		validity = 1;
	destroy_map(&tmp_game);
	return (validity);
}

void	find_player_and_exit_position(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.map[i][j] == 'P')
			{
				game->player_pos.i = i;
				game->player_pos.j = j;
			}
			if (game->map.map[i][j] == 'E')
			{
				game->exit_pos.i = i;
				game->exit_pos.j = j;
			}
		}
	}
}
