# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkehren <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 09:40:03 by gkehren           #+#    #+#              #
#    Updated: 2022/02/18 10:34:53 by gkehren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_nbr.c main.c 

OBJS = ${SRCS:.c=.o}

NAME = do-op

CC	= gcc
RM 	= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} -f ${OBJS}

fclean:	clean
		${RM} -f ${NAME}

re:	fclean all
