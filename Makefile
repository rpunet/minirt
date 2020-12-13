# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/01 19:51:56 by rpunet            #+#    #+#              #
#    Updated: 2020/12/13 23:34:56 by rpunet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	miniRT

NAME_BONUS	:=	miniRT_bonus

OS			:= $(shell uname)

CC			= gcc -g -fsanitize=address

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -Iincludes/ -Ilibft/includes -I$(MINILIBX_DIR)


LIBFT_DIR	= libft/

LIBFT_A		= libft/libft.a

SRC_FILES	= main.c bmp.c scene.c check_args.c read_scene.c read_elements.c read_cameras.c read_lights.c read_sphere.c read_plane.c read_cyl.c read_square.c read_triangle.c load_utils.c vectors.c vectors_2.c vectors_3.c error.c render_scene.c render_sphere.c render_plane.c render_cyl.c render_square.c render_triangle.c surface_data.c shadows.c cast_shadows_2.c

SRC_FILES_BONUS	= move_elements.c main.c bmp.c scene.c check_args.c read_scene.c read_elements.c read_cameras.c read_lights.c read_sphere.c read_plane.c read_cyl.c read_square.c read_triangle.c load_utils.c vectors.c vectors_2.c vectors_3.c error.c render_scene.c render_sphere.c render_plane.c render_cyl.c render_square.c render_triangle.c surface_data.c shadows.c cast_shadows_2.c

SRC_DIR		= src/

SRC_BONUS_DIR	= src_bonus/

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))

SRC_BONUS	= $(addprefix $(SRC_BONUS_DIR), $(SRC_FILES_BONUS))

GREEN		= \033[1;32m

BLUE		= \033[0;34m

RED			= \033[1;31m

COLOR_OFF	= \033[0m

ifeq ($(OS), Linux)
	MINILIBX_DIR = lib/minilibx-linux
	MLXFLAG = -lm -lbsd -lX11 -lXext
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
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)
	@echo "\033[0;31m ---- all cleared! ---- \033[0m"

re: fclean all

bonus: libraries $(NAME_BONUS)

$(NAME_BONUS): $(OBJ)
	@echo "$(BLUE)Building miniRT$(COLOR_OFF)"
	$(CC) $(CFLAGS) $(SRC_BONUS) $(INCLUDES) $(LIBFT_A) $(MINILIBX_A) $(MLXFLAG) -o $(NAME_BONUS)
	@echo "$(GREEN)miniRT done!$(COLOR_OFF)"

.PHONY: all clean fclean re libraries bonus
