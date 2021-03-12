SRCSC	= algo/shortest_algo.c \
					algo/shortest_algo2.c \
					algo/shortest_algo3.c \
					algo/shortest_algo4.c \
					operations/find_operation.c \
					operations/operations.c \
					utils/bonus_and_verifs.c \
					utils/free.c \
					utils/handle_stack.c \
					utils/handle_stack2.c \
					utils/handle_struct.c \
					utils/show.c \
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
