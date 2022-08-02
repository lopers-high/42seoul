NAME	      = push_swap

CC		= cc
CFLAG	= -Wall -Wextra -Werror

RM		= rm -f

AR		= ar
ARFLAGS       = crs

SRCS = push_swap.c \
	   command.c \


SRCS	= $(SRCS_1)			\
	  $(SRCS_2)			\

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BN:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(RMFLAG) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

bonus : $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $^

 .PHONY : all clean fclean re
