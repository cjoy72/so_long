NAME = so_long

SRCS = $(addprefix srcs/, so_long.c check_args.c check_map.c check_map02.c check_map03.c game_init.c update_image.c handle_key.c ft_printf.c)

OBJS = $(SRCS:.c=.o) 

MLX_URL = "https://github.com/codam-coding-college/MLX42.git"
MLX_DIR = MLX42
MLX_BUILD = $(MLX_DIR)/build
MLX_LIB = $(MLX_BUILD)/libmlx42.a

UNAME_S := $(shell uname -s)

CFLAGS = -Wall -Wextra -Werror -g -Iheaders -IMLX42/include

ifeq ($(UNAME_S), Linux)
	LIBS = $(MLX_LIB) -lglfw -ldl -lm -lpthread
endif

ifeq ($(UNAME_S), Darwin)
	GLFW_DIR := $(shell brew --prefix glfw 2>/dev/null || echo /opt/homebrew)
	ifneq ($(wildcard $(GLFW_DIR)/include),)
		CFLAGS += -I$(GLFW_DIR)/include
		GLFW_LIB := -L$(GLFW_DIR)/lib -lglfw
	else ifneq ($(wildcard $(MLX_BUILD)/_deps/glfw-build/src/libglfw3.a),)
		GLFW_LIB := $(MLX_BUILD)/_deps/glfw-build/src/libglfw3.a
	else
		GLFW_LIB := -lglfw
	endif
	LIBS = $(MLX_LIB) $(GLFW_LIB) -framework Cocoa -framework OpenGL -framework IOKit
endif
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
ifeq ($(UNAME_S), Darwin)
	leaks --atExit -- ./$(NAME) maps/test.ber
else
	valgrind $(VAL_FLAGS) ./$(NAME) maps/test.ber 2> leaks.log
	sed '7,8d' leaks.log > leaks.tmp && mv leaks.tmp leaks.log
endif

re: fclean all

.PHONY: all clean fclean re leaks
