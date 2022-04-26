# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 22:09:58 by iamongeo          #+#    #+#              #
#    Updated: 2022/03/16 23:04:13 by iamongeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = srcs/

SRC_FILES = main.c map_validator.c error_handling.c find_bsq.c str_utils.c

SRCS = ${addprefix ${SRC_DIR}, ${SRC_FILES}}

INCLS = includes/

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

NAME = bsq

.c.o:
	${CC} ${CFLAGS} -I${INCLS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -I${INCLS} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
