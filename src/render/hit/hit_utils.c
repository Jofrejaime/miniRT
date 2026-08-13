#include "hit.h"

void hit_fill(
    t_hit *hit,
    t_ray ray,
    double t,
    t_vec3 normal,
    t_object *obj)
{
    hit->t = t;

    hit->point = ray_at(ray, t);

    hit_set_face_normal(
        hit,
        ray,
        normal);

    hit->object = obj;
}

double smallest_positive_root(
    double t1,
    double t2)
{
    if (t1 > EPSILON && t2 > EPSILON)
        return (fmin(t1, t2));

    if (t1 > EPSILON)
        return (t1);

    if (t2 > EPSILON)
        return (t2);

    return (-1.0);
}

