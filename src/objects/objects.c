#include "minirt.h"

t_object *object_new(
    t_obj_type type,
    void *data,
    t_color color)
{
    t_object *obj;

    obj = malloc(sizeof(t_object));
    if (!obj)
        return (NULL);

    obj->type = type;
    obj->data = data;
    obj->color = color;
    obj->next = NULL;

    return (obj);
}

void object_add(
    t_scene *scene,
    t_object *new_object)
{
    if (!scene->objects)
    {
        scene->objects = new_object;
        scene->last_object = new_object;
        return ;
    }

    scene->last_object->next = new_object;
    scene->last_object = new_object;
}