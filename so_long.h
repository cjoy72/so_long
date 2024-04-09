/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calvinjoybaroi <calvinjoybaroi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:34:38 by calvinjoyba       #+#    #+#             */
/*   Updated: 2024/04/09 11:58:50 by calvinjoyba      ###   ########.fr       */
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
# include "minilibx-linux/mlx.h"

# define SIZE 64
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef	struct	s_entities
{
	int	player;
	int	exit;
	int	collectible;
	int	i;
	int	j;
}	t_entities;

typedef struct	s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef	struct s_game
{
	void	*mlx;
	void	*win;
	void	*textures[6];
	char	**map;
	t_coord	player;
	t_coord	exit;
	int		collectible;
	int		moves;
}	t_game;

// so_long.c

static void	load_basics(t_game *game, int i, int j);
static void	load_images(t_game *game);
static void	init_images2(t_game *game, int size);
static void	init_images(t_game *game);

// so_long_utils.c

char		*ft_strdup(const char *s);
char		*ft_strrchr(const char *s, int c);
int			ft_check_file(char *file);
int			ft_error(char *str, int exit_code);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif