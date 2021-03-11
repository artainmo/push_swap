SRCC	= checker.c
OBJSC	= $(SRCC:%.c=%.o)
NAMEC	= checker

SRCP	= push_swap.c
OBJSP	= $(SRCP:%.c=%.o)
NAMEP	= push_swap

SRCT = libs/push_swap/shortest_algo.c
OBJST	= $(SRCT:%.c=%.o)
NAMET	= test

all: libft_all push_swap_all get_next_line_all $(NAMEC) $(NAMEP) #$(NAMET)
	clear

CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror

$(NAMEC): ${OBJSC}
			${CC} ${CFLAGS} -o ${NAMEC} ${OBJSC} ./libs/libft_plus/libft.a ./libs/push_swap/push_swap_lib.a ./libs/get_next_line/get_next_line.a

$(NAMEP): ${OBJSP}
			${CC} ${CFLAGS} -o ${NAMEP}  ${OBJSP} ./libs/libft_plus/libft.a ./libs/push_swap/push_swap_lib.a ./libs/get_next_line/get_next_line.a

$(NAMET): ${OBJST}
			${CC} ${CFLAGS} -o ${NAMET} ${OBJST} ./libs/libft_plus/libft.a ./libs/push_swap/push_swap_lib.a ./libs/get_next_line/get_next_line.a


clean: libft_clean push_swap_clean get_next_line_clean
		${RM} ${OBJSC} ${OBJSP}

fclean:	clean libft_fclean push_swap_fclean get_next_line_fclean
		${RM} ${NAMEC} ${NAMEP}

re:	fclean all


libft_all:
		make -C ./libs/libft_plus all
libft_clean:
		make -C ./libs/libft_plus clean
libft_fclean:
		make -C ./libs/libft_plus fclean

push_swap_all:
			make -C ./libs/push_swap all
push_swap_clean:
			make -C ./libs/push_swap clean
push_swap_fclean:
			make -C ./libs/push_swap fclean

get_next_line_all:
			make -C ./libs/get_next_line all
get_next_line_clean:
			make -C ./libs/get_next_line clean
get_next_line_fclean:
			make -C ./libs/get_next_line fclean


.PHONY:	all clean fclean re
