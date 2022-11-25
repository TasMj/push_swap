# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tas <tas@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 15:33:43 by tmejri            #+#    #+#              #
#    Updated: 2022/11/25 14:00:02 by tas              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRCS	= big_sort_tools.c big_sort.c big_sort2.c big_sort3.c \
		deplacement_push.c deplacement_revrotate.c deplacement_rotate.c \
		deplacement_swap.c fonctions_utiles.c ft_split.c gestion_listes.c \
		initialisation.c initialisation2.c liste_chainees.c push_swap.c \
		small_sort.c small_sort2.c big_sort5.c sort_from_start.c \
		aaaaaa.c \

OBJS			= ${SRCS:.c=.o}

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

all:			${NAME}

${NAME}:		${OBJS}
						${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
						${RM} ${OBJS}

fclean:			clean
						${RM} ${NAME}

re:				fclean ${NAME}

.PHONY:			all clean fclean re