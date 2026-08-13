# include "hit.h"

static double plane_hit_distance(
    t_ray ray,
    t_plane *pl)
{
    double  denom;
    double  t;

    denom = vec3_dot(pl->normal, ray.dir);

    if (fabs(denom) < EPSILON)
        return (-1.0);

    t = vec3_dot(
            vec3_sub(pl->point, ray.origin),
            pl->normal)
        / denom;

    if (t < EPSILON)
        return (-1.0);

    return (t);
}


int intersect_plane(
    t_ray ray,
    t_object *obj,
    t_hit *hit)
{
    t_plane *pl;

    pl = (t_plane *)obj->data;
    hit->t = plane_hit_distance(ray, pl);
    if (hit->t < EPSILON)
        return (0);
    hit_fill(
        hit,
        ray,
        hit->t,
        pl->normal,
        obj);
    return (1);
}
