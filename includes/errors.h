#ifndef ERRORS_H
# define ERRORS_H

# define RETURN_ERROR(ctx, code, id, val, msg) \
do { \
    set_error( \
        &((ctx)->error), \
        code, \
        (ctx)->current_line, \
        id, \
        val, \
        msg  \
    ) \
    return (code); \
} while (0);

typedef enum e_error
{
    ERR_NONE,
    /* Memory */
    ERR_MALLOC,
    /* File */
    ERR_FILE_OPEN,
    ERR_EMPTY_FILE,
    ERR_INVALID_EXTENSION,
    ERR_INVALID_FILE_FORMAT,
    /* Scene */
    ERR_DUPLICATE_AMBIENT,
    ERR_DUPLICATE_CAMERA,
    ERR_DUPLICATE_LIGHT,
    ERR_MISSING_AMBIENT,
    ERR_MISSING_CAMERA,
    ERR_MISSING_LIGHT,
    ERR_MISSING_OBJECTS,
    ERR_INVALID_SCENE,
    /* Parsing */
    ERR_UNKNOWN_IDENTIFIER,
    ERR_INVALID_RATIO,
    ERR_INVALID_FOV,
    ERR_INVALID_VECTOR,
    ERR_INVALID_COLOR,
    ERR_INVALID_ARGUMENT_COUNT,
    ERR_INVALID_ORIENTATION,
    /* Objects */
    ERR_INVALID_SPHERE,
    ERR_INVALID_PLANE,
    ERR_INVALID_CYLINDER,
    ERR_UNKNOWN,
    ERR_INVALID_DIAMETER,
    ERR_INVALID_HEIGHT,
    /*TOKEN*/
    ERR_INVALID_TOKEN,
    ERR_INVALID_TOKEN_COUNT
}   t_error;

typedef struct s_error_info
{
    t_error code;

    int     line;

    char    *identifier;
    char    *value;

    char    *message;
}   t_error_info;

const   char *error_msg(t_error code);
void    set_error(t_error_info *err,
                t_error code,
                int line,
                char *identifier, 
                char *value,
                char *message);
void    print_error(t_error_info *err);

#endif