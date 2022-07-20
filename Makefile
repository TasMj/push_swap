# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 15:33:43 by tmejri            #+#    #+#              #
#    Updated: 2022/06/28 15:34:23 by tmejri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 

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