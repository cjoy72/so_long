/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:10:59 by cbaroi            #+#    #+#             */
/*   Updated: 2024/04/30 13:22:05 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	update_image_init(t_game *game)
{
	static char	*path[] = {
		"textures/character_up.xpm",
		"textures/character_left.xpm",
		"textures/character_down.xpm",
		"textures/character_right.xpm",
		"textures/exit_open.xpm"
	};
	int			i;
	int			size;

	size = SIZE;
	i = -1;
	while (++i < 5)
	{
		game->textures[i + 5] = mlx_xpm_file_to_image(game->mlx, path[i],
				&size, &size);
		if (game->textures[i + 5] == NULL)
		{
			printf("%d\n", i);
			image_error(game, "Error\nmlx_xpm_file_to_image failed\n", i);
		}
	}
}

void	update_image(t_game *game, int key)
{
	if (key == XK_W)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[5], game->player_pos.j * SIZE,
			game->player_pos.i * SIZE);
	if (key == XK_A)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[6], game->player_pos.j * SIZE,
			game->player_pos.i * SIZE);
	if (key == XK_S)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[7], game->player_pos.j * SIZE,
			game->player_pos.i * SIZE);
	if (key == XK_D)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[8], game->player_pos.j * SIZE,
			game->player_pos.i * SIZE);
	if (game->collectables == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[9], game->exit_pos.j * SIZE,
			game->exit_pos.i * SIZE);
}
