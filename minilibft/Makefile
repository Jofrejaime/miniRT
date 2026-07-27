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

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = ${SRC:.c=.o}

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
ft_lstmap_bonus.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = cc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror


$(NAME): ${OBJ}
	${AR} ${NAME} ${OBJ}

all: ${NAME}

bonus: ${OBJ} ${BONUS_OBJ}
	${AR} ${NAME} ${BONUS_OBJ}

clean:
	${RM} ${OBJ} ${BONUS_OBJ}

fclean:
	${RM} ${OBJ} ${BONUS_OBJ} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
	


