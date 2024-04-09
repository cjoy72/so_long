/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calvinjoybaroi <calvinjoybaroi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:34:38 by calvinjoyba       #+#    #+#             */
/*   Updated: 2024/04/09 16:40:19 by calvinjoyba      ###   ########.fr       */
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

typedef struct s_entities
{
	int	player;
	int	exit;
	int	collectible;
	int	i;
	int	j;
}	t_entities;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_game
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

// get_next_line.c

static char	*join_free(char *buffer, char *readbuf);
static char	*clean_buf(char *buffer);
static char	*extract_line(char *buffer);
static char	*read_line(char *buffer, char *readbuf, int fd);
char		*get_next_line(int fd);

// get_next_line_utils.c

int			ft_strlen(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t nmemb, size_t size);

// get_map.c

static int	flood_fill(char **tmp_map, t_coord player, t_coord mapsize);
static int	check_floodfill(char **tmp_map);
void		free_matrix(char **tmp_map);
static int	check_path(char **map);
char		**get_map(char *argv, t_game *game);

// get_map_utils.c

int			ft_strlenh(const char *s);
int			get_height(char *argv);
char		*ft_itoa(int num);
int			free_and_destroy(t_game *game);
void		free_map(chat **map, t_game *game);

// get_map_utils2.c

int			check_wall(char **map, int height);
int 		check_entities(char **map);
char		**copy_matrix(char **map);
int			get_player_coordinate(char **map, int flag);
int			get_player_coordinate(char **map, int flag);

#endif