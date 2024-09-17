# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: castorga <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 16:34:23 by castorga          #+#    #+#              #
#    Updated: 2024/09/17 16:34:25 by castorga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Nombre del ejecutable
NAME = cub3D

# Detección del sistema operativo
UNAME_S := $(shell uname -s)

# Opciones específicas para macOS
ifeq ($(UNAME_S), Darwin)
    MLXFLAGS = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
else
    # Opciones específicas para Linux
    MLXFLAGS = -I/usr/include -L/usr/lib -lXext -lX11 -lm -lbsd -lmlx
endif

# Compilador y FLAGS
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

# Makefile
MKF := Makefile

# Directorios base
LIBFT_DIR = lib/libft/
MLX_DIR = lib/mlx/
SRCS_DIR = src/
OBJS_DIR = .objs/
DEP_DIR = .dep/
INCLUDE_DIR = include/

# Archivos de bibliotecas
LIBFT_FILE = libft.a
MLX_FILE = libmlx.a

# Archivos fuente
SRC_FILES = main.c \
            parse/parse_elements/map_init.c \
            parse/parse_elements/parsing_menu.c \
            parse/parse_elements/map_extension.c \
            parse/parse_elements/utils_0.c \
            parse/parse_elements/utils_1.c \
            parse/parse_elements/utils_2.c \
            parse/parse_elements/exist_elem.c \
            parse/parse_elements/exist_elem2.c \
            parse/parse_elements/exist_colors.c \
            parse/parse_elements/exist_path_colors.c \
            parse/parse_elements/exist_path_colors2.c \
            parse/parse_elements/remove_spaces_tabs.c \
            parse/parse_elements/remove_spaces_tabs2.c \
            parse/parse_elements/remove_spaces_tabs3.c \
            parse/parse_elements/save_path.c \
            parse/parse_elements/save_rgb.c \
            parse/parse_map/create_list.c \
            parse/parse_map/create_matrix.c \
            parse/parse_map/map_measurement.c \
            parse/parse_map/utils_list0.c \
            parse/parse_map/utils_list1.c \
            parse/parse_map/utils_map0.c \
            parse/parse_map/utils_map1.c \
            parse/parse_map/valid_map.c \
            parse/parse_map/valid_map2.c \
            parse/errors_and_free/errors_msgs.c \
            parse/errors_and_free/free_functions.c \
            game/window.c \
            game/utils_windows.c

# Archivos objeto
OBJ_FILES = $(SRC_FILES:.c=.o)

# Archivos de dependencias
DEP_FILES = $(SRC_FILES:.c=.d)

# Rutas completas de las bibliotecas
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
MLX = $(addprefix $(MLX_DIR), $(MLX_FILE))
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))
DEPS = $(addprefix $(DEP_DIR), $(DEP_FILES))

# eliminar archivos
RM = rm -rf

# crear archivos de biblioteca
AR = ar rc

# Rutas de inclusión
INCLUDE = -I $(INCLUDE_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)

# Colores
YELLOW = \033[1;33m
GREEN = \033[1;32m
CYAN = \033[1;36m
RESET = \033[0m

# Regla por defecto (primera regla)
all: $(NAME)

# Regla de limpieza
clean:
	@echo "$(YELLOW)▶ Cleaning object files and dependencies...$(RESET)"
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS_DIR) $(DEP_DIR)

# Regla de limpieza completa (incluye 'clean')
fclean: clean
	@echo "$(YELLOW)▶ Cleaning executable...$(RESET)"
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

# Regla para reconstruir todo
re: fclean all

# Regla para crear los directorios necesarios
make_dirs:
	@mkdir -p $(OBJS_DIR) $(DEP_DIR)
	@mkdir -p $(dir $(OBJS))
	@mkdir -p $(dir $(DEPS))

# Regla para compilar archivos fuente en archivos objeto
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDE_DIR)*.h | make_dirs
	@echo "▶ Compiling... $<"
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@
	@mv $(basename $@).d $(DEP_DIR)$(notdir $(basename $@)).d

# Regla para crear la biblioteca estática solo si es necesario
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

# Regla para compilar las bibliotecas externas solo si no existen
subsystems: $(LIBFT) $(MLX)

# Regla para crear el ejecutable
$(NAME): subsystems $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLXFLAGS) -o $@
	@echo " "
	@echo "$(GREEN)▉▉▉▉▉▉▉▉▉▉ Cub3D successfully compiled! ▉▉▉▉▉▉▉▉▉▉ $(RESET)"
	@echo " "

# Incluye archivos de dependencias si existen
-include $(DEPS)

# Objetivos PHONY
.PHONY: all clean fclean re subsystems make_dirs
