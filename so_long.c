/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:24:41 by cbaroi            #+#    #+#             */
/*   Updated: 2024/04/08 12:13:32 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_images(t_game *game)
{
	int	size;

	size = SIZE;
	game->textures[0] = mlx_xpm_file_to_image(game->mlx, "./textures/p1.xpm",
		&size, &size);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_error("Error: Invalid Number of Arguments", 1);
	if (ft_check_file(argv[1] == 0))
		ft_error("Error: invalid file", 2);
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
		ft_error("Error: invalid file extension", 3);
	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("Error: malloc failed", 4);
	game->collectible = 0;
	game->moves = 0;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_error("Error: mlx failed", 5);
	game->map = get_map(argv[1], game);
	game->win = mlx_new_window(game-mlx, gt_strlenh(game->map[0] * SIZE,
		get_height(argv[1] * SIZE, "so_long")));
	init_images(game);
	load_images(game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, get_inputs, game);
	mlx_hook(game->win, 17, 1L << 17, free_and_destroy, game);
	mlx_loop(game->mlx);
	free_and_destroy(game);		
}

