#include "minirt.h"

t_object *create_sphere_object(
    t_vec3 center,
    double diameter,
    t_color color)
{
    t_sphere    *sphere;
    t_object    *object;

    sphere = malloc(sizeof(t_sphere));
    if (!sphere)
        return (NULL);

    object = malloc(sizeof(t_object));
    if (!object)
    {
        free(sphere);
        return (NULL);
    }

    sphere->center = center;
    sphere->radius = diameter / 2.0;

    object->type = OBJ_SPHERE;
    object->data = sphere;
    object->color = color;
    object->next = NULL;

    return (object);
}