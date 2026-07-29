
#ifndef MINIRT_H
# define MINIRT_H

# define BUFFER_SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "../minilibft/libft.h"
#include "../src/lib_vec3/vec3.h"

typedef enum e_obj_type
{
    OBJ_SPHERE,
    OBJ_PLANE,
    OBJ_CYLINDER
}   t_obj_type;

typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;

typedef struct s_object
{
    t_obj_type  type;
    void        *data;
    t_color     color;
    struct s_object *next;
}   t_object;

typedef struct  s_ambient
{
    double  ratio;
    t_color color;
}   t_ambient;

typedef struct s_light
{
    t_vec3  *pos;
    double  ratio;
    t_color color;
}   t_light;

typedef struct s_scene
{
    t_ambient   *ambient;
    t_light     *light;
    t_object    *objects;
}   t_scene;

char *get_next_line(int fd);

#endif
