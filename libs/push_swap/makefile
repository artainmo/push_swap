SRCSC	= handle_struct.c \
				handle_struct2.c \
	      operations.c \
				utils.c \
				shortest_algo.c \
				handle_struct3.c
SRCSH	= push_swap.h
OBJS	= $(SRCSC:%.c=%.o)
NAME	= push_swap_lib.a
CC	= gcc
AR	= ar rc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS} ${SRCSH}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
