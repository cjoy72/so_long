/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calvinjoybaroi <calvinjoybaroi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:24:41 by cbaroi            #+#    #+#             */
/*   Updated: 2024/04/09 10:41:55 by calvinjoyba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_basics(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[1], j * SIZE, i * SIZE);
		game->player.x = j;
		game->player.y = i;
	}
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->wind,
			game->textures[1], j * SIZE, i * SIZE);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[2], j * SIZE, i * SIZE);
	else if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			fame->textures[3], j * SIZE, i *SIZE);
		game->collectible++;
	}
}

static void	load_images(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			load_basics(game, i, j);
			if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures[4], j * SIZE, i * SIZE);
				game->exit.x = j;
				game->exit.y = i;
			}
		}
	}
}

static void	init_images2(t_game *game, int size)
{
	game->texture[3] = mlx_xpm_file_to_image(game->mlx, "./textures/sup.xpm",
			&size, &size);
	if (game->textures[3] == NULL)
		img_error (game, 3, "Error: invalid texture\n", 6);
	game->textures[4] = mlx_xpm_file_to image(game->mlx, "./textures/e_clo.xpm",
			&size, &size);
	if (game->textures[4] == NULL)
		img_error(game, 4, "Error: invalid texture\n", 6);
	game->textures[5] = mlx_xpm_file_to_image(game->mlx, "./textures/e_op.xpm",
			&size, &size);
	if (game->textures[5] == NULL)
		img_error(game, 5, "Error: invalid texture\n", 6);
}

static void	init_images(t_game *game)
{
	int	size;

	size = SIZE;
	game->textures[0] = mlx_xpm_file_to_image(game->mlx, "./textures/p1.xpm",
			&size, &size);
	if (game->textures[0] == NULL)
		img_error(game, 0, "Error: Invalid Texture\n", 7);
	game->textures[1] = mlx_xpm_file_to_image(game->mlx, "-/textures/tree.xpm",
			&size, &size);
	if (game->textures[1] == NULL)
		img_error(game, 1, "Error: Invalid Texture\n", 7);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx, "./textures/grass.xpm",
			&size, &size);
	if (game->textures[2] == NULL)
		img_error(game, 2, "Error:invalid texture\n", 7);
	init_images2(game, size);
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
	game->win = mlx_new_window(game->mlx, ft_strlenh(game->map[0] * SIZE,
		get_height(argv[1] * SIZE, "so_long");
	init_images(game);
	load_images(game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, get_inputs, game);
	mlx_hook(game->win, 17, 1L << 17, free_and_destroy, game);
	mlx_loop(game->mlx);
	free_and_destroy(game);		
}