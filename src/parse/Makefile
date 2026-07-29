NAME = parse_test

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

ROOT = ../..
LIBFT_DIR = $(ROOT)/minilibft
VEC3_DIR = $(ROOT)/src/lib_vec3

INCLUDES = -I$(ROOT)/includes -I$(LIBFT_DIR) -I$(VEC3_DIR) -I.

LIBFT = $(LIBFT_DIR)/libft.a
LIBVEC3 = $(VEC3_DIR)/libvec3.a

SRCS = main_parse.c parse_extent.c parse_ambient.c parse.c get_next_line.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBVEC3):
	$(MAKE) -C $(VEC3_DIR)

$(NAME): $(LIBFT) $(LIBVEC3) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBVEC3) -lm -o $(NAME)

%.o: %.c parse.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
