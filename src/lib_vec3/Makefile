NAME = libvec3.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

SRCS = vec3_add.c \
	vec3_sub.c \
	vec3_scale.c \
	vec3_dot.c \
	vec3_cross.c \
	vec3_length.c \
	vec3_normalize.c \
	vec3_rotate.c

OBJS = $(SRCS:.c=.o)
TEST_NAME = test_vec3
TEST_SRC = main_test.c

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c vec3.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TEST_NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) $(TEST_SRC) $(NAME) -lm -o $(TEST_NAME)
	./$(TEST_NAME)

.PHONY: all clean fclean re test
