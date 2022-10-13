# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 15:33:43 by tmejri            #+#    #+#              #
#    Updated: 2022/10/13 16:31:20 by tmejri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRCS	= deplacement_push.c deplacement_revrotate.c  deplacement_rotate.c \
		deplacement_swap.c fonctions_utiles.c ft_split.c gestion_listes.c \
		initialisation.c initialisation_2.c liste_chainees.c other_sort.c \
		other_sort_2.c push_swap.c sort_for_hundread.c sort_for_hundread_2.c \
		sort_for_hundread_3.c \

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