#ifndef OBJECTS_H
# define OBJECTS_H

# include "vec3.h"

typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;

typedef struct s_scene t_scene;


typedef enum e_obj_type
{
    OBJ_SPHERE,
    OBJ_PLANE,
    OBJ_CYLINDER
}   t_obj_type;

typedef struct s_object
{
    t_obj_type  type;
    void        *data;
    t_color         color;
    struct s_object *next;
}   t_object;


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
    double  diameter;
    double  height;
}   t_cylinder;

t_object *object_new(
    t_obj_type type,
    void *data,
    t_color color);
    
t_object *create_sphere_object(
    t_vec3 center,
    double diameter,
    t_color color);

void object_add(
    t_object **objects,
    t_object *new_object);

#endif