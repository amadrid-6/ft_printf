SRCS		=	ft_bzero.c ft_calloc.c ft_isdigit.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isprint.c ft_memcmp.c ft_memcpy.c ft_memccpy.c \
			ft_memmove.c ft_strchr.c ft_memchr.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strdup.c \
			ft_strjoin.c ft_strlcat.c ft_strlcpy.c  ft_strmapi.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJS		= ${SRCS:.c=.o}

BONUS		=	ft_lstadd_back.c ft_lstnew.c ft_lstlast.c ft_lstsize.c ft_lstadd_front.c

BONUS_OBJS	= ${BONUS:.c=.o}

NAME		= libft.a

DINLIB		= libft.so

CC		= cc

AR		= ar

ARFLAGS		= -r -c -s

RM		= rm -f

CFLAGS		= -Wall -Werror -Wextra -std=c99

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


${NAME}:	${OBJS}
		${AR} ${ARFLAGS} ${NAME} ${OBJS}


all:		${NAME}


clean:
		${RM} ${OBJS} ${BONUS_OBJS}

so:
		gcc ${OBJS} ${BONUS_OBJS} -shared -o ${DINLIB}


bonus:		${OBJS} ${BONUS_OBJS}
		${AR} ${ARFLAGS} ${NAME} ${BONUS_OBJS} ${OBJS}


fclean:		clean
		${RM} ${NAME}
		${RM} ${DINLIB}

re:		fclean all

.PHONY:		all fclean clean re so bonus
