# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 12:59:36 by lvitorin          #+#    #+#              #
#    Updated: 2025/06/12 16:18:06 by lvitorin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isdigit.c ft_isfloat.c ft_split.c ft_strlen.c ft_strdup.c ft_memcpy.c ft_atoi.c ft_matrizlen.c

OBJ = ${SRC:.c=.o}

CC = cc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror


$(NAME): ${OBJ}
	${AR} ${NAME} ${OBJ}

all: ${NAME}

bonus: all

clean:
	${RM} ${OBJ}

fclean:
	${RM} ${OBJ} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
	

