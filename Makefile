# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tas <tas@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 15:33:43 by tmejri            #+#    #+#              #
#    Updated: 2022/08/23 16:40:47 by tas              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRCS	= bubble.c deplacement_push.c deplacement_swap.c deplacement_rotate.c /
		deplacement_revrotate.c fonctions_utiles.c ft_split.c gestion_listes.c /
		initialisation.c liste_chainees.c other_sort.c push_swap.c /
		radix.c trash.c	/

OBJS			= ${SRCS:.c=.o}

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			${NAME}

${NAME}:		${OBJS}
						ar rcs ${NAME} ${OBJS}

clean:
						${RM} ${OBJS}

fclean:			clean
						${RM} ${NAME}

re:				fclean ${NAME}

.PHONY:			all clean fclean re