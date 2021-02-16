SRCS		=	check_flags_page_1.c check_flags_page_2.c conversion_page_1.c flags_page_1.c flags_page_2.c \
			flags_page_3.c tools_page_1.c tools_page_2.c tools_page_3.c ft_printf.c flags_page_4.c \
			check_flags_page_3.c tools_page_4.c tools_page_5.c flags_page_4.c flags_page_5.c \
			conversion_page_2.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

LIBFT		= libft

CC		= cc

AR		= ar

ARFLAGS		= -r -c -s

RM		= rm -f

CFLAGS		= -Wall -Werror -Wextra 

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		@make -C ${LIBFT}
		@cp libft/libft.a ./${NAME}
		${AR} ${ARFLAGS} ${NAME} ${OBJS}


all:		${NAME}


clean:
		${RM} ${OBJS}
		@make clean -C ${LIBFT}

fclean:		clean
		${RM} ${NAME}
		@make fclean -C ${LIBFT}

re:		fclean all

.PHONY:		all fclean clean re
