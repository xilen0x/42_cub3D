# Nombre del ejecutable
NAME = cub3D

# Detección del sistema operativo
UNAME_S := $(shell uname -s)

# Opciones específicas para macOS
ifeq ($(UNAME_S), Darwin)
    MLXFLAGS = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
else
    # Opciones específicas para Linux
    MLXFLAGS = -I/usr/include -L/usr/lib -lXext -lX11 -lm -lbsd
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
			parse/errors_and_free/free_functions.c

# Archivos objeto
OBJ_FILES = $(SRC_FILES:.c=.o)

# Archivos de dependencias
DEPS_FILES = $(SRC_FILES:.o=.d)

# Rutas completas de las bibliotecas
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
MLX = $(addprefix $(MLX_DIR), $(MLX_FILE))
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))
DEPS = $(addprefix $(DEP_DIR), $(DEPS_FILES))

# eliminar archivos
RM = rm -rf

# crear archivos de biblioteca
AR = ar rc

# Rutas de inclusión
INCLUDE = -I include/ -I $(LIBFT_DIR) -I $(MLX_DIR)

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

# Regla para crear el directorio de los archivos objeto
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Regla para crear el directorio de dependencias
$(DEP_DIR):
	@mkdir -p $(DEP_DIR)

# Regla para compilar archivos fuente en archivos objeto
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(MKF) | $(OBJS_DIR) $(DEP_DIR)
	@mkdir -p $(dir $@)
	@echo "▶ Compiling... $<"
	@$(CC) $(CFLAGS) -MMD -c $< -o $@ $(INCLUDE)
	@mv $(patsubst %.o,%.d,$@) $(DEP_DIR)/$(notdir $(@:.o=.d))

# Regla para crear la biblioteca estática solo si es necesario
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

# Regla para compilar las bibliotecas externas solo si no existen
subsystems: $(LIBFT) $(MLX)

# Regla para crear el ejecutable
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLXFLAGS) -o $@
	@echo " "
	@echo "$(GREEN)▉▉▉▉▉▉▉▉▉▉ Cub3D successfully compiled! ▉▉▉▉▉▉▉▉▉▉ $(RESET)"
	@echo " "

# Incluye archivos de dependencias si existen
-include $(DEPS)

# Objetivos PHONY
.PHONY: all clean fclean re subsystems
