
#ifndef MINIRT_H
# define MINIRT_H

typedef struct s_vct3
{
    double  x;
    double  y;
    double  z;
}   t_vct3;

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
