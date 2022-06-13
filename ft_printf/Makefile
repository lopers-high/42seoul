# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinypark <jinypark@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 17:01:08 by jinypark          #+#    #+#              #
#    Updated: 2022/03/31 18:17:44 by jinypark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

SRCS = ft_printf.c ft_c_s_utils.c ft_d_i_utils.c ft_u_x_p_utils.c ft_print_c_s.c ft_print_d_i.c ft_print_u_x_p.c ft_set_flag.c ft_uitoa.c

BONUS = ft_printf_bonus.c c_s_utils_bonus.c d_i_utils_bonus.c u_x_p_utils_bonus.c ft_print_char_bonus.c

OBJS_SRCS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

ifdef BONUS_FLAG
	OBJS = $(OBJS_SRCS:.c=.o) $(BONUS:.c=.o)
else
	OBJS = $(OBJS_SRCS:.c=.o)
endif

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)/libft.a libftprintf.a
	make fclean -C $(LIBFT_DIR)
	ar rcs $@ $^

bonus:
	make BONUS_FLAG=1 all

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all
	
.PHONY: bonus all clean fclean re
