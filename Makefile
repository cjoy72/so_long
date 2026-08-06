NAME = so_long

SRCS = $(addprefix srcs/, so_long.c check_args.c check_map.c check_map02.c check_map03.c game_init.c update_image.c handle_key.c ft_printf.c)

OBJS = $(SRCS:.c=.o) 

MLX_URL = "https://github.com/codam-coding-college/MLX42.git"
MLX_DIR = MLX42
MLX_BUILD = $(MLX_DIR)/build
MLX_LIB = $(MLX_BUILD)/libmlx42.a

CFLAGS = -Wall -Wextra -Werror -g -Iheaders -IMLX42/include
LIBS = $(MLX_LIB) -lglfw -ldl -lm -lpthread
VAL_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --show-reachable=yes -s

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then git clone $(MLX_URL) $(MLX_DIR); fi
	@cmake -B $(MLX_BUILD) -S $(MLX_DIR)
	@cmake --build $(MLX_BUILD) -j4

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_BUILD)
	rm -rf leaks.log

leaks: all
	valgrind $(VAL_FLAGS) ./$(NAME) maps/test.ber 2> leaks.log
	sed -i '7,8d' leaks.log && rm -rf leaks.log.bak

re: fclean all

.PHONY: all clean fclean re leaks
