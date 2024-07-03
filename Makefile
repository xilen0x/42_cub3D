# Nombre del ejecutable
NAME = cub3d

# Directorios de bibliotecas
LIBFT_DIR = lib/libft/
MLX_DIR = lib/mlx/

# Archivos de bibliotecas
LIBFT_FILE = libft.a
MLX_FILE = libmlx.a

# Rutas completas de las bibliotecas
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
MLX = $(addprefix $(MLX_DIR), $(MLX_FILE))

# Archivos fuente
SRCS_DIR = src/
SRC_FILES = main.c window.c utils_1.c utils_2.c #parsing0.c load_map.c parsing1.c parsing2.c 
#parsing3.c utils_3.c

# Archivos objeto
OBJS_DIR = objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))

# Archivos de dependencias
DEPS := $(OBJS:.o=.d)

# Compilador y opciones
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g#-fsanitize=address

# Detección del sistema operativo
UNAME_S := $(shell uname -s)

# Opciones específicas para macOS
ifeq ($(UNAME_S), Darwin)
    MLXFLAGS = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
else
    # Opciones específicas para Linux
    MLXFLAGS = -I/usr/include -L/usr/lib -lXext -lX11 -lm -lbsd
endif

# Comando para eliminar archivos
RM = rm -rf

# Comando para crear archivos de biblioteca
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

# Regla para compilar las bibliotecas externas
subsystems:
	@echo "$(YELLOW)▶ Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(YELLOW)▶ Compiling MinilibX...$(RESET)"
	@make -C $(MLX_DIR)

# Regla para crear el ejecutable
$(NAME): subsystems $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLXFLAGS) -o $@
	@echo
	@echo "$(GREEN)▉▉▉▉▉▉▉▉▉▉ Cub3D successfully compiled! ▉▉▉▉▉▉▉▉▉▉ $(RESET)"
	@echo

# Regla para crear el directorio de los archivos objeto
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Regla para compilar archivos fuente en archivos objeto
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@echo "▶ Compiling... $<"
	@$(CC) $(CFLAGS) -MMD -c $< -o $@ $(INCLUDE)

# Regla para crear la biblioteca estática (si fuera necesario)
$(LIBFT): 
	@$(MAKE) -C  $(LIBFT) @$(AR) $(OBJS)
	@ranlib $(LIBFT)

# Regla de limpieza
clean:
	@echo "$(YELLOW)▶ Cleaning object files and dependencies...$(RESET)"
	make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS) $(DEPS)

# Regla de limpieza completa (incluye 'clean')
fclean: clean
	@echo "$(YELLOW)▶ Cleaning executable...$(RESET)"
	make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

# Regla para reconstruir todo
re: fclean all

# Incluye archivos de dependencias si existen
-include $(DEPS)

# Objetivos PHONY
.PHONY: all clean fclean re subsystems
