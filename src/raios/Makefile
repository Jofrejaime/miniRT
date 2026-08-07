# Makefile for raios module compilation - Audited and complete
# This Makefile compiles all necessary resources for the raios (ray tracing) phase

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O0
INCLUDES = -I../../includes \
           -I../../src/lib_vec3 \
           -I../../src/window \
           -I../../src/raios \
           -I../../src/parser \
           -I../../src/lexer \
           -I../../src/errors \
           -I../../src/debug \
           -I../../src/cleanup \
           -I../../minilibx-linux \
           -I../../minilibft

LDFLAGS = -L../../minilibx-linux -lmlx \
          -L/usr/lib -lXext -lX11 -lm

# Output
TARGET = raios
OBJS_DIR = objs
$(shell mkdir -p $(OBJS_DIR))

# Source files from raios module (simplified for raios phase only)
RAIOS_SRCS = main_raios.c \
             camera_build_basis.c

# Source files from lexer
LEXER_SRCS = ../../src/lexer/tokenize.c \
             ../../src/lexer/token_utils.c

# Source files from parser
PARSER_SRCS = ../../src/parser/parse_scene.c \
              ../../src/parser/parse_element.c \
              ../../src/parser/parse_args.c \
              ../../src/parser/get_next_line.c

# Parser converters
PARSER_CONV_SRCS = ../../src/parser/converters/parse_int.c \
                   ../../src/parser/converters/parse_double.c \
                   ../../src/parser/converters/parse_vec3.c \
                   ../../src/parser/converters/parse_color.c

# Parser element parsers
PARSER_ELEM_SRCS = ../../src/parser/parsers/parse_ambient.c \
                   ../../src/parser/parsers/parse_camera.c \
                   ../../src/parser/parsers/parse_light.c \
                   ../../src/parser/parsers/parse_sphere.c \
                   ../../src/parser/parsers/parse_plane.c \
                   ../../src/parser/parsers/parse_cylinder.c

# Parser utils
PARSER_UTIL_SRCS = ../../src/parser/utils/parser_utils.c \
                   ../../src/parser/utils/parser_validation.c \
                   ../../src/parser/utils/create_sphere_object.c

# Source files from other modules (only what's needed)
WINDOW_SRCS = ../../src/window/initialize.c

VEC3_SRCS = ../../src/lib_vec3/vec3_add.c \
            ../../src/lib_vec3/vec3_sub.c \
            ../../src/lib_vec3/vec3_scale.c \
            ../../src/lib_vec3/vec3_dot.c \
            ../../src/lib_vec3/vec3_cross.c \
            ../../src/lib_vec3/vec3_length.c \
            ../../src/lib_vec3/vec3_normalize.c \
            ../../src/lib_vec3/vec3_rotate.c

OBJECTS_SRCS = ../../src/objects/objects.c

# Error handling
ERROR_SRCS = ../../src/errors/error_msg.c \
             ../../src/errors/print_error.c \
             ../../src/errors/set_error.c

# Cleanup
CLEANUP_SRCS = ../../src/cleanup/cleanup_rt.c \
               ../../src/cleanup/scene_destoy.c

# Combine all sources needed for raios phase
ALL_SRCS = $(RAIOS_SRCS) $(LEXER_SRCS) $(PARSER_SRCS) $(PARSER_CONV_SRCS) \
           $(PARSER_ELEM_SRCS) $(PARSER_UTIL_SRCS) $(WINDOW_SRCS) $(VEC3_SRCS) \
           $(OBJECTS_SRCS) $(ERROR_SRCS) $(CLEANUP_SRCS)

# Object files
OBJS = $(addprefix $(OBJS_DIR)/,$(notdir $(ALL_SRCS:.c=.o)))

# Libraries
MINILIBX = ../../minilibx-linux/libmlx.a
MINILIBFT = ../../minilibft/libft.a

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS) $(MINILIBX) $(MINILIBFT)
	@echo "[Linking] $(TARGET)"
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(MINILIBFT) $(LDFLAGS)
	@echo "[✓] Build complete: $(TARGET)"

$(OBJS_DIR)/%.o: %.c
	@echo "[Compiling] $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: ../../src/window/%.c
	@echo "[Compiling] $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: ../../src/lib_vec3/%.c
	@echo "[Compiling] $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: ../../src/objects/%.c
	@echo "[Compiling] $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: ../../src/lexer/%.c
	@echo "[Compiling] $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: ../../src/parser/%.c
	@echo "[Compiling] $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: ../../src/parser/converters/%.c
	@echo "[Compiling] $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: ../../src/parser/parsers/%.c
	@echo "[Compiling] $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: ../../src/parser/utils/%.c
	@echo "[Compiling] $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: ../../src/errors/%.c
	@echo "[Compiling] $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o: ../../src/cleanup/%.c
	@echo "[Compiling] $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MINILIBX):
	@echo "[Building] minilibx"
	@make -C ../../minilibx-linux

$(MINILIBFT):
	@echo "[Building] minilibft"
	@make -C ../../minilibft

clean:
	@echo "[Cleaning] Object files"
	rm -rf $(OBJS_DIR)

fclean: clean
	@echo "[Cleaning] Executable"
	rm -f $(TARGET)

re: fclean all

info:
	@echo "=== Raios Phase Build Audit ==="
	@echo "Target: $(TARGET)"
	@echo ""
	@echo "RAIOS MODULE SOURCE FILES (2 files):"
	@echo "  $(RAIOS_SRCS)"
	@echo ""
	@echo "WINDOW MODULE (1 file):"
	@echo "  $(WINDOW_SRCS)"
	@echo ""
	@echo "VEC3 LIBRARY (8 files):"
	@echo "  $(VEC3_SRCS)"
	@echo ""
	@echo "OBJECTS MODULE (1 file):"
	@echo "  $(OBJECTS_SRCS)"
	@echo ""
	@echo "TOTAL: 12 source files"
	@echo "TOTAL OBJECTS: $$(echo $(OBJS) | wc -w) object files"

.PHONY: all clean fclean re info
