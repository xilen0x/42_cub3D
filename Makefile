NAME = so_long

LIBFT_DIR = libft/
MLX_DIR = mlx/

LIBFT_FILE = libft.a
MLX_FILE = libmlx.a

LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
MLX = $(addprefix $(MLX_DIR), $(MLX_FILE))

SRCS_DIR = src/
SRC_FILES =	 main.c parsing0.c load_map.c utils_1.c parsing1.c parsing2.c \
			parsing3.c window.c utils_2.c utils_3.c

OBJS_DIR =	objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))
DEPS        := $(OBJS:.o=.d)
CC = clang -g
CFLAGS = -Wall -Wextra -Werror #-fsanitize='address'
MLXFLAGS = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
AR = ar rc
INCLUDE = -I include/ -I $(LIBFT_DIR) -I $(MLX_DIR)

all: 		$(NAME)

subsystems:
			@make -C $(LIBFT_DIR)
			@make -C $(MLX_DIR)

$(NAME):	subsystems $(OBJS_DIR) $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx $(MLXFLAGS) -o $@

$(OBJS_DIR):
			@mkdir $@

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
			@$(CC) $(CFLAGS) -MMD -c $< -o $@ $(INCLUDE)

clean: 		
			make -C $(LIBFT_DIR) clean
			@$(RM) $(OBJS) $(DEPS)


fclean: 	clean
			make -C $(LIBFT_DIR) fclean
			@$(RM) $(NAME)

re:			fclean all
-include $(DEPS)			

.PHONY: all clean fclean re subsystems
