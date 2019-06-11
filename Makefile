# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 17:47:25 by bwynton-          #+#    #+#              #
#    Updated: 2019/05/12 13:52:48 by bwynton-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
FILES = main.c \
		add_funck.c \
		cas.c \
		checker.c \
		control.c \
		culcmap.c \
		draw_walls.c \
		draw_walls2.c \
		key_control.c \
		libe_trace.c \
		line_copy.c \
		map_block_setter.c \
		map_drawer.c \
		map_reader.c \
		mouse_control.c

OBJ = $(FILES:%.c=%.o)

CFLAGS = -I./minilibx_macos -I./libft -I.\
	-L./minilibx_macos -lmlx -L./libft -lft -framework OpenGL -framework AppKit -framework OpenCL

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx_macos
	make -C libft
	cc $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): %.o:%.c
	gcc -Wall -Wextra -Werror -I. -I./libft -I./minilibx_macos  -c $(FILES)

clean: 
	rm -f $(OBJ)
	make -C libft clean
	make -C minilibx_macos clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	
re: fclean all
