# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 17:01:08 by jinypark          #+#    #+#              #
#    Updated: 2022/06/17 21:19:02 by jinypark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

SRCS = client.c server.c

BONUS = client_bonus.c server_bonus.c

OBJS_SRCS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

ifdef BONUS_FLAG
	OBJS = $(OBJS_BONUS)
	SERVER = server_bonus.o
	CLIENT = client_bonus.o
else
	OBJS = $(OBJS_SRCS)
	SERVER = server.o
	CLIENT = client.o
endif

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o server $(SERVER) -L libft -lft
	$(CC) $(CFLAGS) -o client $(CLIENT) -L libft -lft

bonus:
	make BONUS_FLAG=1 all

clean:
	make -C libft clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: bonus all clean fclean re
