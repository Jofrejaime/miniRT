#include "hit.h"

t_vec3 ray_at(t_ray ray, double t)
{
    return (
        vec3_add(
            ray.origin,
            vec3_scale(ray.dir, t)
        )
    );
}

void hit_set_face_normal(
    t_hit *hit,
    t_ray ray,
    t_vec3 outward_normal)
{
    hit->front_face =
        (vec3_dot(ray.dir, outward_normal) < 0);

    if (hit->front_face)
        hit->normal = outward_normal;
    else
        hit->normal =
            vec3_scale(outward_normal, -1.0);
}