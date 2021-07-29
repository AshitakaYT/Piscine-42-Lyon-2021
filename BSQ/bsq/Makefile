# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aucousin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 14:33:21 by aucousin          #+#    #+#              #
#    Updated: 2021/07/28 13:22:40 by aucousin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


SRCS	= ft_int_tabs.c ft_parsing.c ft_putnbr.c ft_split.c  ft_swap.c scanf.c ft_atoi.c ft_make_int_tab.c ft_putchar.c ft_putstr.c ft_strlen.c ft_tablen.c verif_line.c ft_norminette.c
HEADERS	= header.h
OBJS	= ${SRCS:.c=.o}
NAME	= bsq
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I includes

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
