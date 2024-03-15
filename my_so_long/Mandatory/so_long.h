/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:09:27 by cbaroi            #+#    #+#             */
/*   Updated: 2024/03/15 10:48:31 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# define SIZE 64
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_entities
{
	int	player;
	int	exit;
	int	collectable;
	int	i;
	int	j;
}				t_entities;

typedef struct	s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	void	*textures[6];
	char	**map;
	t_coord	player;
	t_coord	exit;
	int		collectable;
	int		moves;
}	t_game;

// so_long_utils

int		ft_check_file(char *file);
int		ft_error(char *str, int exit_code);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strrchr(const char *s, int c);

// so_long

static void	load_basics(t_game *game, int i, int j);
static void load_images(t_game *game);
static void init_images2(t_game *game, int size);
static void	init_images(t_game *game);

#endif