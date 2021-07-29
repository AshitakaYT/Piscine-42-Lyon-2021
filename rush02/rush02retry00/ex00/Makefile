# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aucousin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 14:33:21 by aucousin          #+#    #+#              #
#    Updated: 2021/07/25 20:29:44 by aucousin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


SRCS	= ft_atoi.c ft_putchar.c ft_putstr.c ft_strcmp.c main.c ft_strlen.c ft_putnbr.c ft_split.c ft_swap.c ft_str_is_printable.c ft_get_words.c ft_get_lines.c ft_tablen.c ft_is_double_point_ok.c ft_is_dic_ok.c ft_get_nums.c ft_check_duplicate_nums.c ft_get_keys.c ft_get_dict.c ft_swap_dict.c ft_sort_dict.c ft_strncmp.c ft_nbrlen.c ft_print_words.c ft_ischarprt.c ft_get_past_doublepoint.c ft_get_past_spaces.c
HEADERS	= ft_beautiful_header.h
OBJS	= ${SRCS:.c=.o}
NAME	= rush-02
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
