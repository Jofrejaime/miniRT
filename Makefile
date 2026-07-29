NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = minilibft
VEC3_DIR = src/lib_vec3

LIBFT = $(LIBFT_DIR)/libft.a
LIBVEC3 = $(VEC3_DIR)/libvec3.a

INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(VEC3_DIR) -Isrc/parse -Isrc/Lexer

SRCS = src/main.c \
	src/parse/parse_extent.c \
	src/parse/parse_ambient.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBVEC3):
	$(MAKE) -C $(VEC3_DIR)

$(NAME): $(LIBFT) $(LIBVEC3) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBVEC3) -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

parse:
	$(MAKE) -C src/parse

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(VEC3_DIR) clean
	$(MAKE) -C src/parse clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(VEC3_DIR) fclean
	$(MAKE) -C src/parse fclean

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus parse
