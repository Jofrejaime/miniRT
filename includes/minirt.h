
#ifndef MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include "vec3.h"
#include "libft.h"
#include "windows.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlx.h"
#include "objects.h"


typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;

typedef struct  s_ambient
{
    double  ratio;
    t_color color;
}   t_ambient;

typedef struct s_light
{
    t_vec3  pos;
    double  ratio;
    t_color color;
}   t_light;

typedef struct s_camera
{
    t_vec3  pos;
    t_vec3  dir;
    double  fov;
}   t_camera;

typedef struct s_scene
{
    t_ambient   *ambient;
    t_light     *light;
    t_camera    *camera;
    t_object    *objects;
}   t_scene;

typedef struct s_rt
{
    t_scene         scene;
    t_error_info    error;
    t_mlx           mlx;
}   t_rt;

#endif
