
#ifndef MINIRT_H
# define MINIRT_H

#include <stdio.h>


#include "vec3.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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


#endif
