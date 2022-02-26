# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkehren <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 12:00:58 by gkehren           #+#    #+#              #
#    Updated: 2022/02/20 20:21:42 by gkehren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/dico_reader.c srcs/dico_reader2.c srcs/formatage.c srcs/ft_atoi.c srcs/ft_print_my_number.c srcs/ft_print_my_number2.c srcs/ft_print_my_number3.c srcs/ft_putstr.c srcs/ft_split.c

OBJS = ${SRCS:.c=.o}

NAME = rush-02 

.c.o:
			gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all :	${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

.PHONY : re clean fclean all
