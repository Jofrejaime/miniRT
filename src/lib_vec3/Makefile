# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/04 16:08:03 by lvitorin          #+#    #+#              #
#    Updated: 2026/09/04 16:08:06 by lvitorin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvec3.a

SRC = vec3_add.c vec3_sub.c vec3_scale.c vec3_dot.c vec3_cross.c \
	vec3_length.c vec3_normalize.c vec3_rotate.c

OBJ = $(SRC:.c=.o)

CC = cc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
