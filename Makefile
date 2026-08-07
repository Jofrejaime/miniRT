NAME = miniRT

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

# ── Directories ───────────────────────────────────────────────────────────────
LIBFT_DIR   = minilibft
VEC3_DIR    = src/lib_vec3
MLX_DIR     = minilibx-linux
WINDOWS_DIR = src/window

# ── Libraries ─────────────────────────────────────────────────────────────────
LIBFT       = $(LIBFT_DIR)/libft.a
LIBVEC3     = $(VEC3_DIR)/libvec3.a
LIBMLX      = $(MLX_DIR)/libmlx_Linux.a
LIBWINDOW   = $(WINDOWS_DIR)/libwindow.a

# ── Includes ──────────────────────────────────────────────────────────────────
INCLUDES = \
	-Iincludes \
	-I$(LIBFT_DIR) \
	-I$(VEC3_DIR) \
	-Isrc/lexer \
	-Isrc/parser \
	-I$(MLX_DIR) \
	-I$(WINDOWS_DIR)

# ── Linker flags ──────────────────────────────────────────────────────────────
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ── Sources ───────────────────────────────────────────────────────────────────
SRCS = \
	src/main.c \
	\
	src/errors/error_msg.c \
	src/errors/print_error.c \
	src/errors/set_error.c \
	\
	src/cleanup/cleanup_rt.c \
	src/cleanup/scene_destoy.c \
	\
	\
	src/lexer/tokenize.c \
	src/lexer/token_utils.c \
	\
	src/parser/parse_args.c \
	src/parser/parse_element.c \
	src/parser/parse_scene.c \
	src/parser/get_next_line.c \
	\
	src/parser/converters/parse_color.c \
	src/parser/converters/parse_double.c \
	src/parser/converters/parse_int.c \
	src/parser/converters/parse_vec3.c \
	\
	src/parser/parsers/parse_ambient.c \
	src/parser/parsers/parse_camera.c \
	src/parser/parsers/parse_light.c \
	src/parser/parsers/parse_sphere.c \
	src/parser/parsers/parse_plane.c \
	src/parser/parsers/parse_cylinder.c \
	\
	src/parser/utils/create_sphere_object.c \
	src/parser/utils/object_utils.c \
	src/parser/utils/parser_utils.c \
	src/parser/utils/parser_validation.c \
	\
	src/debug/debug_vec3.c \
	src/debug/debug_color.c \
	src/debug/debug_tokens.c \
	src/debug/debug_objects.c \
	src/debug/debug_errors.c \
	src/debug/debug_rt.c

OBJS = $(SRCS:.c=.o)

# ── Rules ─────────────────────────────────────────────────────────────────────
all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBVEC3):
	$(MAKE) -C $(VEC3_DIR)

$(LIBMLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBWINDOW):
	$(MAKE) -C $(WINDOWS_DIR)

$(NAME): $(LIBFT) $(LIBVEC3) $(LIBWINDOW) $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBVEC3) $(LIBWINDOW) $(LIBMLX) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ── Debug build ───────────────────────────────────────────────────────────────
debug: CFLAGS += -DDEBUG -g
debug: all

# ── Cleanup ───────────────────────────────────────────────────────────────────
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(VEC3_DIR) clean
	$(MAKE) -C $(WINDOWS_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(VEC3_DIR) fclean
	$(MAKE) -C $(WINDOWS_DIR) fclean

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus debug
