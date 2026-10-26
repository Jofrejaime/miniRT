NAME    = miniRT

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -fPIE
AR      = ar rcs
RM      = rm -f

# ── Directories ───────────────────────────────────────────────────────────────
MLX_DIR = minilibx-linux
LIBMLX  = $(MLX_DIR)/libmlx_Linux.a

# ── Includes ──────────────────────────────────────────────────────────────────
INCLUDES = \
	-Iincludes \
	-Iminilibft \
	-Isrc/lib_vec3 \
	-Isrc/lexer \
	-Isrc/parser \
	-Isrc/raios \
	-Isrc/render \
	-Isrc/render/hit \
	-Isrc/render/light \
	-Isrc/window \
	-I$(MLX_DIR)

# ── Linker flags ──────────────────────────────────────────────────────────────
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ── Sources ───────────────────────────────────────────────────────────────────
SRCS = \
	src/main.c \
	\
	minilibft/ft_atoi.c \
	minilibft/ft_bzero.c \
	minilibft/ft_isdigit.c \
	minilibft/ft_isfloat.c \
	minilibft/ft_matrizlen.c \
	minilibft/ft_memcpy.c \
	minilibft/ft_memset.c \
	minilibft/ft_putchar_fd.c \
	minilibft/ft_putendl_fd.c \
	minilibft/ft_putstr_fd.c \
	minilibft/ft_split.c \
	minilibft/ft_strdup.c \
	minilibft/ft_strlen.c \
	minilibft/ft_strncmp.c \
	\
	src/lib_vec3/vec3_add.c \
	src/lib_vec3/vec3_sub.c \
	src/lib_vec3/vec3_scale.c \
	src/lib_vec3/vec3_dot.c \
	src/lib_vec3/vec3_cross.c \
	src/lib_vec3/vec3_length.c \
	src/lib_vec3/vec3_normalize.c \
	src/lib_vec3/vec3_rotate.c \
	\
	src/window/initialize.c \
	\
	src/errors/error_msg.c \
	src/errors/print_error.c \
	src/errors/set_error.c \
	\
	src/cleanup/cleanup_rt.c \
	src/cleanup/scene_destoy.c \
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
	src/raios/camera_build_basis.c \
	\
	src/render/render.c \
	src/render/hit/hit.c \
	src/render/hit/hit_scene.c \
	src/render/hit/hit_utils.c \
	src/render/hit/intersect_sphere.c \
	src/render/hit/intersect_plane.c \
	src/render/hit/intersect_cylinder.c \
	src/render/hit/cylinder_helpers.c \
	src/render/hit/intersect_object.c \
	src/render/light/ambiente.c \
	src/render/light/light_utils.c \
	src/render/light/shadow.c

OBJS = $(SRCS:.c=.o)

# ── Rules ─────────────────────────────────────────────────────────────────────
all: $(LIBMLX) $(NAME)

$(LIBMLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

src/window/initialize.o: src/window/initialize.c
	$(CC) $(CFLAGS) -Wno-incompatible-pointer-types $(INCLUDES) -c $< -o $@

# ── Cleanup ───────────────────────────────────────────────────────────────────
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
