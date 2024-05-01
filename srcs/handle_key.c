/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:19:01 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/01 16:59:58 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	move_left(t_game *game)
{
	game->moves++;
	if (game->map.map[game->player_pos.i][game->player_pos.j - 1] == '1')
		update_image(game, XK_A);
	if (game->map.map[game->player_pos.i][game->player_pos.j - 1] == 'E')
	{
		if (game->collectables == 0)
		{
			printf("You won!\nWith only %d moves\n", game->moves);
			destroy_everything(game);
		}
		else
			return ;
	}
	if (game->map.map[game->player_pos.i][game->player_pos.j - 1] == 'C' ||
		game->map.map[game->player_pos.i][game->player_pos.j - 1] == '0')
	{
		if (game->map.map[game->player_pos.i][game->player_pos.j - 1] == 'C')
			game->collectables--;
		game->map.map[game->player_pos.i][game->player_pos.j - 1] = 'P';
		game->map.map[game->player_pos.i][game->player_pos.j] = '0';
		game->player_pos.j--;
		load_images(game);
		update_image(game, XK_A);
	}
	printf("Game moves: %d\n", game->moves);
}

void	move_right(t_game *game)
{
	game->moves++;
	if (game->map.map[game->player_pos.i][game->player_pos.j + 1] == '1')
		update_image(game, XK_D);
	if (game->map.map[game->player_pos.i][game->player_pos.j + 1] == 'E')
	{
		if (game->collectables == 0)
		{
			printf("You won!\nWith only %d moves\n", game->moves);
			destroy_everything(game);
		}
		else
			return ;
	}
	if (game->map.map[game->player_pos.i][game->player_pos.j + 1] == 'C' ||
		game->map.map[game->player_pos.i][game->player_pos.j + 1] == '0')
	{
		if (game->map.map[game->player_pos.i][game->player_pos.j + 1] == 'C')
			game->collectables--;
		game->map.map[game->player_pos.i][game->player_pos.j + 1] = 'P';
		game->map.map[game->player_pos.i][game->player_pos.j] = '0';
		game->player_pos.j++;
		load_images(game);
		update_image(game, XK_D);
	}
	printf("Game moves: %d\n", game->moves);
}

void	move_up(t_game *game)
{
	game->moves++;
	if (game->map.map[game->player_pos.i - 1][game->player_pos.j] == '1')
		update_image(game, XK_W);
	if (game->map.map[game->player_pos.i - 1][game->player_pos.j] == 'E')
	{
		if (game->collectables == 0)
		{
			printf("You won!\nWith only %d moves\n", game->moves);
			destroy_everything(game);
		}
		else
			return ;
	}
	if (game->map.map[game->player_pos.i - 1][game->player_pos.j] == 'C' ||
		game->map.map[game->player_pos.i - 1][game->player_pos.j] == '0')
	{
		if (game->map.map[game->player_pos.i - 1][game->player_pos.j] == 'C')
			game->collectables--;
		game->map.map[game->player_pos.i - 1][game->player_pos.j] = 'P';
		game->map.map[game->player_pos.i][game->player_pos.j] = '0';
		game->player_pos.i--;
		load_images(game);
		update_image(game, XK_W);
	}
	printf("Game moves: %d\n", game->moves);
}

void	move_down(t_game *game)
{
	game->moves++;
	if (game->map.map[game->player_pos.i + 1][game->player_pos.j] == '1')
		update_image(game, XK_S);
	if (game->map.map[game->player_pos.i + 1][game->player_pos.j] == 'E')
	{
		if (game->collectables == 0)
		{
			printf("You won!\nWith only %d moves\n", game->moves);
			destroy_everything(game);
		}
		else
			return ;
	}
	if (game->map.map[game->player_pos.i + 1][game->player_pos.j] == 'C' ||
		game->map.map[game->player_pos.i + 1][game->player_pos.j] == '0')
	{
		if (game->map.map[game->player_pos.i + 1][game->player_pos.j] == 'C')
			game->collectables--;
		game->map.map[game->player_pos.i + 1][game->player_pos.j] = 'P';
		game->map.map[game->player_pos.i][game->player_pos.j] = '0';
		game->player_pos.i++;
		load_images(game);
		update_image(game, XK_S);
	}
	printf("Game moves: %d\n", game->moves);
}

int	handle_key(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		destroy_everything(game);
		exit(0);
	}
	if (key == XK_W || key == XK_w)
		move_up(game);
	if (key == XK_A || key == XK_a)
		move_left(game);
	if (key == XK_S || key == XK_s)
		move_down(game);
	if (key == XK_D || key == XK_d)
		move_right(game);
	return (0);
}
