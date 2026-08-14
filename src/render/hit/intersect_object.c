#include "hit.h"

int intersect_object(
    t_ray ray,
    t_object *obj,
    t_hit *hit)
{
    if (!obj)
        return (0);

    if (obj->type == OBJ_SPHERE)
        return (intersect_sphere(ray, obj, hit));

    if (obj->type == OBJ_PLANE)
        return (intersect_plane(ray, obj, hit));

    if (obj->type == OBJ_CYLINDER)
        return (intersect_cylinder(ray, obj, hit));

    return (0);
}