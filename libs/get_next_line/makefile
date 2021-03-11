# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artainmo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 21:50:42 by artainmo          #+#    #+#              #
#    Updated: 2020/02/26 19:19:19 by artainmo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSC	= get_next_line.c \
				get_next_line_utils.c
SRCSH	= get_next_line.h
OBJS	= $(SRCSC:%.c=%.o)
NAME	= get_next_line.a
CC	= gcc
AR	= ar rc
RM	= rm -f
CFLAGS = -Wall -Wextra -Werror

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS} ${SRCSH}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
			${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
