NAME = libwindow.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS_WINDOW = -Wall -Wextra -Werror -Wno-incompatible-pointer-types
AR = ar rcs
RM = rm -f

INCLUDES = -I. -I../../includes -I../../minilibx-linux -I../../src/lib_vec3 -I../../minilibft

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS_WINDOW) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re