# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spereyra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 16:33:40 by spereyra          #+#    #+#              #
#    Updated: 2024/09/27 17:42:16 by spereyra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	cub3D	
SRC		:=	cub3D.c setters.c game_utils.c game_moves.c \
			put_to_image.c trigo.c
OBJ		:=	$(SRC:%.c=%.o)
HEADER	:=	./cub3D.h
#LIBFT	:=	./libft/libft.a
MLX		:=	./mlx_linux/libmlx.a
CC		:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra
LFLAGS	:=	-Lmlx_linux -lmlx -lX11 -lXext -lm
IFLAGS	:=	-Imlx_linux -Iinc

.PHONY	:	all clean fclean re

all	:
#	make --no-print-directory -C ./libft
	make --no-print-directory -C ./mlx_linux
	make --no-print-directory $(NAME)

$(NAME)	:	$(MLX) $(OBJ) #$(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(IFLAGS) $(LFLAGS) -g

%.o		:	%.c Makefile $(HEADER)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

#$(LIBFT):
#	make -C ./libft

$(MLX)	:
	make -C ./mlx_linux

clean	:
#	rm -f ./libft/*.o
	rm -f ./mlx_linux/*.o
	rm -f ./*.o

fclean	:	clean
#	rm -f ./libft/libft.a
	rm -f ./mlx_linux/libmlx.a
	rm -f ./cub3D

re		:	fclean all
