/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:48:55 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/06 17:33:58 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	check_map_error(int index)
{
	if (index == 0)
		ft_error("Error\nMap is not rectangular\n", 1);
	if (index == 1)
		ft_error("Error\nMap Creation Failed\n", 1);
	if (index == 2)
		ft_error("Error\nMap Copy Failed\n", 1);
	if (index == 3)
		ft_error("Error\nInvalid character in map\n", 1);
	if (index == 4)
		ft_error("Error\nMap is not surrounded by walls\n", 1);
	if (index == 5)
		ft_error("Error\nInvalid number of player, exit or collectables\n", 1);
	if (index == 6)
		ft_error("Error\nInvalid path\n", 1);
}

char	*cir_utils(int *fd, t_game *game, char **argv)
{
	char	*line;

	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
		ft_error("Error\n", 1);
	line = malloc(sizeof(char) * (game->map.width + 1));
	if (!line)
	{
		close(*fd);
		ft_error("Error\n", 1);
	}
	line[game->map.width] = '\0';
	return (line);
}

void	x_pressed(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	destroy_everything(game);
}

int	check_char(t_game *game, char **argv)
{
	int				i;
	int				j;
	int				k;
	static char		*valid_chars = "01CEP";

	(void)argv;
	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			k = -1;
			while (valid_chars[++k])
				if (game->map.map[i][j] == valid_chars[k])
					break ;
			if (valid_chars[k] == '\0')
				return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc, argv);
	check_map(argv, &game);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game.mlx = mlx_init(game.map.width * SIZE,
			game.map.height * SIZE, "so_long", false);
	if (game.mlx == NULL)
		ft_error("Error\nmlx_init failed\n", 1);
	init_images(&game);
	load_images(&game);
	mlx_key_hook(game.mlx, handle_key_mlx42, &game);
	mlx_close_hook(game.mlx, x_pressed, &game);
	mlx_loop(game.mlx);
	destroy_everything(&game);
}
