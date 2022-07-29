# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 17:01:08 by jinypark          #+#    #+#              #
#    Updated: 2022/07/18 15:02:30 by jinypark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

MLX_DIR = minilibx_macos

SRCS = fdf.c parse_map.c assign_point.c event.c draw.c rotation.c bresenham.c

BONUS = fdf_bonus.c parse_map_bonus.c assign_point_bonus.c event_bonus.c draw_bonus.c rotation_bonus.c bresenham_bonus.c

OBJS_SRCS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

ifdef BONUS_FLAG
	OBJS = $(OBJS_BONUS)
else
	OBJS = $(OBJS_SRCS)
endif

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o fdf $(OBJS) libft/libft.a minilibx_macos/libmlx.a -framework openGL -framework AppKit

bonus:
	make BONUS_FLAG=1 all

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: bonus all clean fclean re
