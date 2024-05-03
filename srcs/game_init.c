/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:30:03 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/03 11:26:01 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	image_error(t_game *game, char *message, int index)
{
	int	i;

	destroy_map(game);
	i = -1;
	while (++i < index)
		if (game->textures[i] != NULL)
			mlx_destroy_image(game->mlx, game->textures[i]);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_error(message, 1);
}

void	init_images(t_game *game)
{
	int			i;
	int			size;
	static char	*path[] = {
		"textures/wall.xpm",
		"textures/grass.xpm",
		"textures/collectable.xpm",
		"textures/character_down.xpm",
		"textures/exit_close.xpm",
	};

	game->map.map[game->exit_pos.i][game->exit_pos.j] = '0';
	size = SIZE;
	i = -1;
	while (++i < 5)
	{
		game->textures[i] = mlx_xpm_file_to_image(game->mlx, path[i],
				&size, &size);
		if (game->textures[i] == NULL)
			image_error(game, "Error\nmlx_xpm_file_to_image failed\n", i);
	}
	update_image_init(game);
}

void	destroy_everything(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 10)
		if (game->textures[i] != NULL)
			mlx_destroy_image(game->mlx, game->textures[i]);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	destroy_map(game);
	exit(0);
}

void	load_updated_images(t_game *game)
{
	int		i;
	int		j;
	int		k;
	char	*sign;

	sign = "10CPE";
	i = game->player_pos.i - 2;
	while (++i < game->player_pos.i + 2)
	{
		j = game->player_pos.j - 2;
		while (++j < game->player_pos.j + 2)
		{
			k = -1;
			while (++k < 5)
			{
				if (game->map.map[i][j] == sign[k])
				{
					mlx_put_image_to_window(game->mlx, game->window,
						game->textures[k], j * SIZE, i * SIZE);
					break ;
				}
			}
		}
	}
}

void	load_images(t_game *game)
{
	int		i;
	int		j;
	int		k;
	char	*sign;

	sign = "10CPE";
	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			k = -1;
			while (++k < 5)
			{
				if (game->map.map[i][j] == sign[k])
				{
					mlx_put_image_to_window(game->mlx, game->window,
						game->textures[k], j * SIZE, i * SIZE);
					break ;
				}
			}
		}
	}
}
