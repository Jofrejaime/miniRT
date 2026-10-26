# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/04 16:57:22 by lvitorin          #+#    #+#              #
#    Updated: 2026/09/04 16:57:24 by lvitorin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libwindow.a

SRC = initialize.c

OBJ = $(SRC:.c=.o)

CC = cc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -Wno-incompatible-pointer-types
INCLUDES = -I. -I../../includes -I../../minilibx-linux -I../../src/lib_vec3 -I../../minilibft

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
