# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:52:30 by jecolmou          #+#    #+#              #
#    Updated: 2022/12/06 15:59:21 by jecolmou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	cub3d

SRC					=		cub3d.c \
							utils/ft_strnstr.c \
							utils/ft_strcmp.c \
							utils/ft_bzero.c \
							utils/ft_split.c \
							get_next_line/get_next_line.c \
							get_next_line/get_next_line_utils.c \

NAME = cub3d

MLX = ./mlx/libmlx.a

CC = clang

LINK = clang

CFLAGS = -Wall -Wextra -Werror -Imlx -I. -c -g3

OBJ = $(SRC:.c=.o)

LFLAGS	=	-ldl -lmlx -Lmlx -lm -lXext -lX11 -Lmlx -lmlx

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(LINK) $(OBJ) $(LFLAGS) $(OUTPUT_OPTION)

$(MLX) :
	$(MAKE) -C ./mlx

%.o: %.c
	${CC} ${CFLAGS} $< $(OUTPUT_OPTION)

clean:
	$(MAKE) $@ -C ./mlx
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
