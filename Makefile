# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 17:37:18 by mtani             #+#    #+#              #
#    Updated: 2024/05/01 17:25:57 by cbaroi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = $(addprefix srcs/, so_long.c check_args.c check_map.c check_map02.c check_map03.c game_init.c update_image.c handle_key.c)

OBJS = $(SRCS:.c=.o) 

MLX = "https://github.com/42Paris/minilibx-linux.git"
MLX_DIR = mlx
FLAGS = -Lmlx -lmlx -lX11 -lXext
VAL_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --show-reachable=yes

%.o: %.c
	gcc -Wall -Wextra -Werror -g $(FLAGS) -c $< -o $@

all: $(MLX_DIR) $(NAME)

$(MLX_DIR):
	@git clone $(MLX) mlx
	@cd $(MLX_DIR) && ./configure

$(NAME): $(OBJS)
	gcc -o $(NAME) -Wall -Wextra -Werror -g $(OBJS) $(FLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_DIR)

leaks: all
	valgrind $(VAL_FLAGS) ./$(NAME) maps/test.ber 2> leaks.log
	
re: fclean all
