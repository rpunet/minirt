# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/01 19:51:56 by rpunet            #+#    #+#              #
#    Updated: 2020/12/11 21:06:29 by rpunet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	miniRT

OS			:= $(shell uname)

CC			= gcc -g -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -Iincludes/ -Ilibft/includes -I$(MINILIBX_DIR)

LIBFT_DIR	= libft/

LIBFT_A		= libft/libft.a

SRC_FILES	= main.c bmp.c scene.c check_args.c read_scene.c read_elements.c read_cameras.c read_lights.c read_sphere.c read_plane.c read_cyl.c read_square.c read_triangle.c load_utils.c vectors.c vectors_2.c vectors_3.c error.c render_scene.c render_sphere.c render_plane.c render_cyl.c render_square.c render_triangle.c surface_data.c shadows.c

SRC_DIR		= src/

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))

GREEN		= \033[1;32m

BLUE		= \033[0;34m

RED			= \033[1;31m

COLOR_OFF	= \033[0m
#OBJ			= $(addprefix $())

ifeq ($(OS), Linux)
	MINILIBX_DIR = lib/minilibx-linux
	MLXFLAG = -lm -lbsd -lX11 -lXext

# ver si hace falta el flag -lbsd
endif
ifeq ($(OS), Darwin)
	MINILIBX_DIR = lib/minilibx_opengl_20191021
	MLXFLAG = -lz -framework OpenGL -framework AppKit
endif

MINILIBX_A	= $(MINILIBX_DIR)/libmlx.a

all: libraries $(NAME)



$(NAME): $(OBJ)
	@echo "$(BLUE)Building miniRT$(COLOR_OFF)"
	$(CC) $(CFLAGS) $(SRC) $(INCLUDES) $(LIBFT_A) $(MINILIBX_A) $(MLXFLAG) -o $(NAME)
	@echo "$(GREEN)miniRT done!$(COLOR_OFF)"

libraries:
	@echo "$(BLUE)Building libraries...$(COLOR_OFF)"
	make plus -C $(LIBFT_DIR)
	make -C $(MINILIBX_DIR)
	@echo "$(GREEN)Libraries built$(COLOR_OFF)"

clean:
	@make clean -C $(LIBFT_DIR)

fclean:
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "\033[0;31m ---- all cleared! ---- \033[0m"


re: fclean all


.PHONY: all clean fclean re libraries
