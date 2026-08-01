#ifndef OBJECTS_H
# define OBJECTS_H

#include "vec3.h"

typedef struct s_sphere
{
    t_vec3  center;
    double  radius;
}   t_sphere;

typedef struct s_plane
{
    t_vec3  point;
    t_vec3  normal;
}   t_plane;

typedef struct s_cylinder
{
    t_vec3  center;
    t_vec3  axis;
    double  radius;
    double  height;
}   t_cylinder;

#endif