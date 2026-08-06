/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:10:59 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/06 17:34:03 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	free_and_close(int *fd, char *line)
{
	free(line);
	close(*fd);
	return (1);
}

void	update_image_init(t_game *game)
{
	static char		*path[] = {
		"textures/character_up.png",
		"textures/character_left.png",
		"textures/character_down.png",
		"textures/character_right.png",
		"textures/exit_open.png"
	};
	int				i;
	mlx_texture_t	*texture;

	i = -1;
	while (++i < 5)
	{
		texture = mlx_load_png(path[i]);
		if (!texture)
			image_error(game, "Error\nmlx_load_png failed\n", i + 5);
		game->textures[i + 5] = mlx_texture_to_image(game->mlx, texture);
		mlx_delete_texture(texture);
		if (!game->textures[i + 5])
			image_error(game, "Error\nmlx_texture_to_image failed\n", i + 5);
	}
}

void	update_image(t_game *game, int key)
{
	size_t	k;
	int		active_idx;

	active_idx = 7;
	if (key == XK_W || key == XK_Up)
		active_idx = 5;
	else if (key == XK_A || key == XK_Left)
		active_idx = 6;
	else if (key == XK_S || key == XK_Down)
		active_idx = 7;
	else if (key == XK_D || key == XK_Right)
		active_idx = 8;
	k = 4;
	while (++k <= 8)
	{
		if (game->textures[k]->count > 0)
		{
			game->textures[k]->instances[0].x = game->player_pos.j * SIZE;
			game->textures[k]->instances[0].y = game->player_pos.i * SIZE;
			game->textures[k]->instances[0].enabled = ((int)k == active_idx);
		}
	}
	if (game->collectables == 0)
	{
		if (game->textures[4]->count > 0)
			game->textures[4]->instances[0].enabled = false;
		if (game->textures[9]->count > 0)
			game->textures[9]->instances[0].enabled = true;
		game->map.map[game->exit_pos.i][game->exit_pos.j] = 'E';
	}
}
