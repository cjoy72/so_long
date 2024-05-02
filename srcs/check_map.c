/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:11:05 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/02 20:47:28 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_if_rectangular(t_game *game, char **argv)
{
	int			fd;
	int			i;
	int			len;
	char		*line;

	line = cir_utils(&fd, game, argv);
	i = 0;
	while (i < game->map.height)
	{
		if (read(fd, line, game->map.width + 1) == -1)
		{
			free(line);
			close(fd);
			ft_error("Error\n", 1);
		}
		len = ft_strlen(line);
		if (len != game->map.width)
			return (1);
		i++;
	}
	free(line);
	close(fd);
	return (0);
}

int	map_height(char **argv)
{
	int			height;
	int			fd;
	static char	buf[1];
	int			bytes_read;
	int			total_bytes;

	file_descriptor(&fd, argv);
	height = 0;
	total_bytes = 0;
	bytes_read = read(fd, buf, 1);
	while (bytes_read != 0)
	{
		if (buf[0] == '\n')
			height++;
		else
			total_bytes++;
		bytes_read = read(fd, buf, 1);
	}
	if (total_bytes % height != 0)
		height = height - 1;
	close(fd);
	return (height);
}

int	map_width(char **argv)
{
	int			fd;
	int			width;
	int			bytes_read;
	static char	line[100];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error\n", 1);
	bytes_read = read(fd, line, 100);
	if (bytes_read == -1)
		ft_error("Error\n", 1);
	width = ft_strlen(line);
	close (fd);
	return (width);
}

void	init_map(t_game *game, char **argv)
{
	game->collectables = 0;
	game->moves = 0;
	game->exit_pos.num = 0;
	game->player_pos.num = 0;
	game->map.height = map_height(argv);
	game->map.width = map_width(argv);
}

void	check_map(char **argv, t_game *game)
{
	int			i;
	static int	(*check_functions[7])(t_game *game, char **argv) = {
		&check_if_rectangular, &create_map,
		&copy_map, &check_char, &ft_check_wall,
		&check_exit_player_collectables, &valid_path};

	init_map(game, argv);
	i = -1;
	while (++i < 7)
	{
		if (check_functions[i](game, argv) == 1)
		{
			if (i > 2)
				destroy_map(game);
			check_map_error(i);
		}
	}
}
