/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:10:57 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/06 17:34:20 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define SIZE			64

# define XK_W			MLX_KEY_W
# define XK_w			MLX_KEY_W
# define XK_A			MLX_KEY_A
# define XK_a			MLX_KEY_A
# define XK_S			MLX_KEY_S
# define XK_s			MLX_KEY_S
# define XK_D			MLX_KEY_D
# define XK_d			MLX_KEY_D
# define XK_Up			MLX_KEY_UP
# define XK_Left		MLX_KEY_LEFT
# define XK_Down		MLX_KEY_DOWN
# define XK_Right		MLX_KEY_RIGHT
# define XK_Escape		MLX_KEY_ESCAPE

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}			t_map;

typedef struct s_coord
{
	int	num;
	int	i;
	int	j;
}				t_coord;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*textures[10];
	t_map		map;
	t_coord		exit_pos;
	t_coord		player_pos;
	int			collectables;
	int			moves;
}				t_game;

// so_long.c

void		check_map_error(int index);
char		*cir_utils(int *fd, t_game *game, char **argv);
void		x_pressed(void *param);
int			check_char(t_game *game, char **argv);

// handle_key.c

void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
int			handle_key(int key, t_game *game);
void		handle_key_mlx42(mlx_key_data_t keydata, void *param);

// update_image.c

int			free_and_close(int *fd, char *line);
void		update_image_init(t_game *game);
void		update_image(t_game *game, int key);

// game_init.c

void		image_error(t_game *game, char *message, int index);
void		init_images(t_game *game);
void		destroy_everything(t_game *game);
void		load_updated_images(t_game *game);
void		load_images(t_game *game);

// check_map03.c

void		file_descriptor(int *fd, char **argv);
int			find_char(t_game *game, char c);
void		flood_fill(t_game *game, int i, int j);
int			valid_path(t_game *game, char **argv);
void		find_player_and_exit_position(t_game *game);

// check_map02.c

int			check_exit_player_collectables(t_game *game, char **argv);
int			ft_check_wall(t_game *game, char **argv);
int			copy_map(t_game *game, char **argv);
void		destroy_map(t_game *game);
int			create_map(t_game *game, char **argv);

// check_map.c

int			check_if_rectangular(t_game *game, char **argv);
int			map_height(char **argv);
int			map_width(char **argv);
void		init_map(t_game *game, char **argv);
void		check_map(char **argv, t_game *game);

// check_args.c

void		ft_error(char *str, int status);
void		ft_file_check(char *file);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(const char *s);
void		check_args(int argc, char **argv);

// ft_printf.c

void		pf_putnbr(int nbr, size_t *count);
void		pf_putstr(char *str, size_t *count);
void		pf_putchar(char c, size_t *count);
void		pf_flags(va_list args, char *str, size_t *count);
int			ft_printf(char const *str, ...);

#endif
