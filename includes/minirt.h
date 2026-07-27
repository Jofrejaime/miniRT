
#ifndef MINIRT_H
# define MINIRT_H

#include "vec3.h"

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



#endif
