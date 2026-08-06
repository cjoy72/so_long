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
	(void)index;
	if (game->mlx)
		mlx_terminate(game->mlx);
	destroy_map(game);
	ft_error(message, 1);
}

void	init_images(t_game *game)
{
	int				i;
	mlx_texture_t	*texture;
	static char		*path[] = {
		"textures/wall.png",
		"textures/grass.png",
		"textures/collectable.png",
		"textures/character_down.png",
		"textures/exit_close.png",
	};

	game->map.map[game->exit_pos.i][game->exit_pos.j] = '0';
	i = -1;
	while (++i < 5)
	{
		texture = mlx_load_png(path[i]);
		if (!texture)
			image_error(game, "Error\nmlx_load_png failed\n", i);
		game->textures[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_delete_texture(texture);
		if (!game->textures[i])
			image_error(game, "Error\nmlx_texture_to_image failed\n", i);
	}
	update_image_init(game);
}

void	destroy_everything(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	destroy_map(game);
	exit(0);
}

void	load_updated_images(t_game *game)
{
	(void)game;
}

void	load_images(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
			mlx_image_to_window(game->mlx, game->textures[1], j * SIZE, i * SIZE);
	}
	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->textures[0], j * SIZE, i * SIZE);
			else if (game->map.map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->textures[2], j * SIZE, i * SIZE);
		}
	}
	mlx_image_to_window(game->mlx, game->textures[4], game->exit_pos.j * SIZE, game->exit_pos.i * SIZE);
	mlx_image_to_window(game->mlx, game->textures[9], game->exit_pos.j * SIZE, game->exit_pos.i * SIZE);
	if (game->textures[9]->count > 0)
		game->textures[9]->instances[0].enabled = false;

	mlx_image_to_window(game->mlx, game->textures[5], game->player_pos.j * SIZE, game->player_pos.i * SIZE);
	mlx_image_to_window(game->mlx, game->textures[6], game->player_pos.j * SIZE, game->player_pos.i * SIZE);
	mlx_image_to_window(game->mlx, game->textures[7], game->player_pos.j * SIZE, game->player_pos.i * SIZE);
	mlx_image_to_window(game->mlx, game->textures[8], game->player_pos.j * SIZE, game->player_pos.i * SIZE);

	if (game->textures[5]->count > 0)
		game->textures[5]->instances[0].enabled = false;
	if (game->textures[6]->count > 0)
		game->textures[6]->instances[0].enabled = false;
	if (game->textures[7]->count > 0)
		game->textures[7]->instances[0].enabled = true;
	if (game->textures[8]->count > 0)
		game->textures[8]->instances[0].enabled = false;
}
