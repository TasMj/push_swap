# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tas <tas@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 15:33:43 by tmejri            #+#    #+#              #
#    Updated: 2022/08/22 02:27:42 by tas              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= bubble.c deplacement_push.c deplacement_swap.c deplacement_rotate.c /
		deplacement_revrotate.c fonctions_utiles.c ft_split gestion_listes.c /
		initialisation.c liste_chainees.c other_sort.c push_swap.c /
		radix.c (trash.c et liste_chainees2.c)	

OBJS			= ${SRCS:.c=.o}

BONUS			=

BONUS_OBJS		= $(BONUS:.c=.o)

NAME			= libft.a

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			${NAME}

${NAME}:		${OBJS}
						ar rcs ${NAME} ${OBJS}

clean:
						${RM} ${OBJS} ${BONUS_OBJS}

fclean:			clean
						${RM} ${NAME}

re:				fclean ${NAME}

bonus:			$(OBJS) $(BONUS_OBJS)
						ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus