#ifndef HIT_H
#define HIT_H

#include "minirt.h"
#include "vec3.h"

#define EPSILON 1e-6

typedef struct s_hit
{
    double t;

    t_vec3 point;
    t_vec3 normal;

    t_object *object;

    int front_face;
} t_hit;

typedef struct s_quadratic
{
    double a;
    double b;
    double c;
    double delta;
} t_quadratic;

/*
** hit.c
*/
t_vec3 ray_at(t_ray ray, double t);

void hit_set_face_normal(
    t_hit *hit,
    t_ray ray,
    t_vec3 outward_normal);
void hit_fill(
    t_hit *hit,
    t_ray ray,
    double t,
    t_vec3 normal,
    t_object *obj);
/*
** hit_scene.c
*/
int hit_scene(
    t_scene *scene,
    t_ray ray,
    t_hit *hit);

/*
** intersect_object.c
*/
int intersect_object(
    t_ray ray,
    t_object *obj,
    t_hit *hit);

/*
** primitives
*/
int intersect_sphere(
    t_ray ray,
    t_object *obj,
    t_hit *hit);

int intersect_plane(
    t_ray ray,
    t_object *obj,
    t_hit *hit);

int intersect_cylinder(
    t_ray ray,
    t_object *obj,
    t_hit *hit);

double smallest_positive_root(double t1, double t2);

#endif